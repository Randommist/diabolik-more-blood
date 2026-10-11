"""Replace string payloads inside an STCM2L script and relocate everything after them.
resize(b, edits): edits = {action_address: (text_offset, old_capacity, new_bytes)}; same algorithm as build_scene.patch_script."""
import struct
def resize(b,edits):
    p=b.index(b'CODE_START_')+12;start=p;end=struct.unpack_from('<I',b,32)[0]-12;actions=[];newpos=start;addresses={};internal={}
    while p<end:
        local,op,count,length=struct.unpack_from('<IIII',b,p);raw=bytearray(b[p:p+length]);oldlen=length
        if p in edits and isinstance(edits[p],dict):
            raw=bytearray(edits[p]['raw']);internal[p]=edits[p]['internal']
        elif p in edits:
            off_abs,oldcap,rawtext=edits[p];off=off_abs-p;newcap=(len(rawtext)//4+1)*4
            raw[off:off+oldcap]=rawtext+b'\0'*(newcap-len(rawtext))
            struct.pack_into('<I',raw,off-12,newcap//4);struct.pack_into('<I',raw,off-4,newcap)
            struct.pack_into('<I',raw,12,len(raw))
        addresses[p]=newpos;actions.append((p,newpos,oldlen,raw));newpos+=len(raw);p+=oldlen
    shift=newpos-end
    for old,new,oldlen,raw in actions:
        local,op,count,_=struct.unpack_from('<IIII',raw)
        if local and op in addresses:struct.pack_into('<I',raw,4,addresses[op])
        for i in range(count):
            q=16+i*12;v1,v2,v3=struct.unpack_from('<III',raw,q)
            if (i in internal[old]) if old in internal else (old<v1<old+oldlen):struct.pack_into('<I',raw,q,new+v1-old)
            if v1==0xffffff41 and v2 in addresses:struct.pack_into('<I',raw,q+4,addresses[v2])
    tail=bytearray(b[end:]);exports=struct.unpack_from('<I',b,32)[0];link=struct.unpack_from('<I',b,44)[0]
    for p in range(exports,link-16,40):
        old=struct.unpack_from('<I',b,p+36)[0]
        assert old in addresses,(p,old)
        struct.pack_into('<I',tail,p+36-end,addresses[old])
    ptr=struct.unpack_from('<I',b,link+4)[0];struct.pack_into('<I',tail,link+4-end,ptr+shift)
    header=bytearray(b[:start]);struct.pack_into('<I',header,32,exports+shift);struct.pack_into('<I',header,44,link+shift)
    return bytes(header)+b''.join(bytes(a[3]) for a in actions)+bytes(tail)


def edit_strings(b,mapping,encode):
    """Replace string objects (cap/4, cap, text) whose Shift-JIS text is a key of mapping, in every action; returns the patched script."""
    p=b.index(b'CODE_START_')+12;end=struct.unpack_from('<I',b,32)[0]-12;edits={}
    while p<end:
        local,op,count,length=struct.unpack_from('<IIII',b,p);objs=[]
        for i in range(count):
            v1=struct.unpack_from('<I',b,p+16+i*12)[0]
            if p<v1<p+length and v1+16<=p+length:
                cap=struct.unpack_from('<I',b,v1+12)[0]
                if cap and cap%4==0 and struct.unpack_from('<I',b,v1+4)[0]==cap//4 and v1+16+cap<=p+length:
                    try:t=b[v1+16:v1+16+cap].split(b'\0')[0].decode('cp932')
                    except UnicodeDecodeError:continue
                    if t in mapping and v1 not in [o[0] for o in objs]:objs.append((v1,cap,t))
        if objs:
            objs.sort();raw=bytearray(b[p:p+length]);out=bytearray();pos=0;shifts=[]
            for v1,cap,t in objs:
                rel=v1-p;new=encode(mapping[t]);newcap=(len(new)//4+1)*4
                out+=raw[pos:rel+16];hdr=len(out)-16
                struct.pack_into('<I',out,hdr+4,newcap//4);struct.pack_into('<I',out,hdr+12,newcap)
                out+=new+b'\0'*(newcap-len(new));pos=rel+16+cap;shifts.append((rel,newcap-cap))
            out+=raw[pos:]
            def mp(rel):return rel+sum(d for r,d in shifts if r<rel)
            internal=set()
            for i in range(count):
                v1=struct.unpack_from('<I',out,16+i*12)[0]
                if p<v1<p+length:struct.pack_into('<I',out,16+i*12,p+mp(v1-p));internal.add(i)
            struct.pack_into('<I',out,12,len(out));edits[p]={'raw':bytes(out),'internal':internal}
        p+=length
    return resize(b,edits)
