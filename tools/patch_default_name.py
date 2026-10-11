"""Default heroine name (script/0, opcode 471 string actions): 小森 ユイ -> Комори Юи.
Resizes the string payloads and relocates the rest of the script exactly like build_scene.patch_script does for script/101.
usage: patch_default_name.py [out_file]   (selftest: identical edits must reproduce the original bytes)"""
import struct,sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
from patch_keyboard import enc
ROOT=Path(__file__).resolve().parents[1]
EDITS={0xb0a8:('小森','Комор'),0xb0fc:('ユイ','Юи')}   # action address -> (original, russian)
def resize(b,edits):
    p=b.index(b'CODE_START_')+12;start=p;end=struct.unpack_from('<I',b,32)[0]-12;actions=[];newpos=start;addresses={}
    while p<end:
        local,op,count,length=struct.unpack_from('<IIII',b,p);raw=bytearray(b[p:p+length]);oldlen=length
        if p in edits:
            assert op==471
            ptr=struct.unpack_from('<I',b,p+16)[0] if False else None
            # string object pointer is the second 12-byte slot of the action (see dump): find the pointer that lies inside the action
            for q in range(16,length-12,12):
                v=struct.unpack_from('<I',b,p+q)[0]
                if p<v<p+length and b[v+16:v+16+len(edits[p][0].encode('cp932'))]==edits[p][0].encode('cp932'):ptr=v;break
            cap=struct.unpack_from('<I',b,ptr+12)[0];off=ptr+16-p
            orig,ru=edits[p];assert b[ptr+16:ptr+16+len(orig.encode('cp932'))]==orig.encode('cp932'),(hex(p),b[ptr+16:ptr+24])
            rawtext=enc(ru,True) if ru!=orig else orig.encode('cp932');newcap=(len(rawtext)//4+1)*4
            raw[off:off+cap]=rawtext+b'\0'*(newcap-len(rawtext))
            struct.pack_into('<I',raw,off-12,newcap//4);struct.pack_into('<I',raw,off-4,newcap)
            struct.pack_into('<I',raw,12,len(raw))
        addresses[p]=newpos;actions.append((p,newpos,oldlen,raw));newpos+=len(raw);p+=oldlen
    shift=newpos-end
    for old,new,oldlen,raw in actions:
        local,op,count,_=struct.unpack_from('<IIII',raw)
        if local and op in addresses:struct.pack_into('<I',raw,4,addresses[op])
        for i in range(count):
            q=16+i*12;v1,v2,v3=struct.unpack_from('<III',raw,q)
            if old<v1<old+oldlen:struct.pack_into('<I',raw,q,new+v1-old)
            if v1==0xffffff41 and v2 in addresses:struct.pack_into('<I',raw,q+4,addresses[v2])
    tail=bytearray(b[end:]);exports=struct.unpack_from('<I',b,32)[0];link=struct.unpack_from('<I',b,44)[0]
    for p in range(exports,link-16,40):
        old=struct.unpack_from('<I',b,p+36)[0]
        assert old in addresses,(p,old)
        struct.pack_into('<I',tail,p+36-end,addresses[old])
    ptr=struct.unpack_from('<I',b,link+4)[0];struct.pack_into('<I',tail,link+4-end,ptr+shift)
    header=bytearray(b[:start]);struct.pack_into('<I',header,32,exports+shift);struct.pack_into('<I',header,44,link+shift)
    return bytes(header)+b''.join(bytes(a[3]) for a in actions)+bytes(tail)
if __name__=='__main__':
    b=(ROOT/'build/extracted/resources/script/0').read_bytes()
    same=resize(b,{k:(v[0],v[0]) for k,v in EDITS.items()});print('identity edit reproduces original:',same==b)
    assert same==b
    out=resize(b,EDITS);print('patched',len(b),'->',len(out))
    if len(sys.argv)>1:Path(sys.argv[1]).write_bytes(out)
