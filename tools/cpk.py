import struct, json, sys
from pathlib import Path

def decompress(b):
    if not b.startswith(b'CRILAYLA'):return b
    size,off=struct.unpack_from('<II',b,8)
    out=bytearray(size+256);out[:256]=b[off+16:off+272]
    p=off+15;pool=0;left=0;pos=len(out)-1
    def bits(n):
        nonlocal p,pool,left
        result=0
        for _ in range(n):
            if not left:pool=b[p];p-=1;left=8
            result=(result<<1)|((pool>>(left-1))&1);left-=1
        return result
    while pos>=256:
        if bits(1):
            source=pos+bits(13)+3;length=3
            for n in (2,3,5,8):
                v=bits(n);length+=v
                if v!=(1<<n)-1:break
            else:
                while True:
                    v=bits(8);length+=v
                    if v!=255:break
            for _ in range(length):out[pos]=out[source];pos-=1;source-=1
        else:out[pos]=bits(8);pos-=1
    return bytes(out)

def utf(b, start=0):
    if b[start:start+4]!=b'@UTF':
        b=bytearray(b);key=0x655f
        for i in range(start,len(b)):
            b[i]^=key&255;key=(key*0x4115)&0xffffffff
    assert b[start:start+4]==b'@UTF'
    base=start+8
    rows=struct.unpack_from('>H',b,base+2)[0]
    strings,data=struct.unpack_from('>II',b,base+4)
    name,ncols,rowlen,nrows=struct.unpack_from('>IHHI',b,base+12)
    def string(i):
        s=base+strings+i
        return b[s:b.index(b'\0',s)].decode('utf-8')
    def value(p,t):
        fmt={0:'B',1:'b',2:'H',3:'h',4:'I',5:'i',6:'Q',7:'q',8:'f',10:'I',11:'II'}[t]
        v=struct.unpack_from('>'+fmt,b,p); size=struct.calcsize('>'+fmt)
        return (string(v[0]) if t==10 else v if t==11 else v[0]),p+size
    cols=[];p=base+24
    for _ in range(ncols):
        flags=b[p];i=struct.unpack_from('>I',b,p+1)[0];p+=5
        const=None
        if flags&0xf0==0x30:const,p=value(p,flags&15)
        cols.append((string(i),flags,const))
    result=[]
    for row in range(nrows):
        p=base+rows+row*rowlen; d={}
        for name,flags,const in cols:
            if flags&0xf0==0x50:v,p=value(p,flags&15)
            else:v=const or 0
            d[name]=v
        result.append(d)
    return result

def index(path):
    with open(path,'rb') as f:
        header=utf(f.read(4096),16)[0]
        f.seek(header['TocOffset']);toc=f.read(header['TocSize'])
    entries=utf(toc,16)
    base=min(header['TocOffset'],header['ContentOffset'])
    for e in entries:e['absolute']=base+e['FileOffset']
    return header,entries

def read_entry(path,entries,dirname,filename):
    """Decompressed bytes of one CPK entry (entries = index(path)[1])."""
    e=next(x for x in entries if str(x['DirName'])==dirname and str(x['FileName'])==filename)
    with open(path,'rb') as f:f.seek(e['absolute']);b=decompress(f.read(e['FileSize']))
    assert len(b)==e['ExtractSize'];return b

if __name__=='__main__':
    path=Path(sys.argv[1]);h,entries=index(path)
    print(json.dumps(h,indent=2)); print('Entries:',len(entries))
    Path(str(path)+'.index.json').write_text(json.dumps(entries,ensure_ascii=False,indent=2))
    if len(sys.argv)>2:
        dest=Path(sys.argv[2])
        with path.open('rb') as f:
            for e in entries:
                if e['DirName'] not in ('script','font','xls'):continue
                target=dest/str(e['DirName'])/str(e['FileName'])
                assert target.resolve().is_relative_to(dest.resolve())
                target.parent.mkdir(parents=True,exist_ok=True)
                f.seek(e['absolute']);b=f.read(e['FileSize'])
                b=decompress(b);assert len(b)==e['ExtractSize']
                target.write_bytes(b)
        print('Extracted to',dest)
