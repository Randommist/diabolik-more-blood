import struct,json,sys
from pathlib import Path
def texts(b):
 p=b.index(b'CODE_START_')+12;end=struct.unpack_from('<I',b,32)[0]-12
 result=[]
 while p<end:
  local,op,count,length=struct.unpack_from('<IIII',b,p)
  assert length>=16 and p+length<=end,(p,op,count,length,end)
  if not local and op in (0xd2,0xd4,0xe7,0x79d0) and count:
   ptr=struct.unpack_from('<I',b,p+16+(3 if op==0x79d0 else 0)*12)[0]
   if p<ptr<p+length:
    size=struct.unpack_from('<I',b,ptr+12)[0];raw=b[ptr+16:ptr+16+size]
    result.append(dict(action=p,opcode=hex(op),offset=ptr+16,capacity=size,text=raw.rstrip(b'\0').decode('cp932')))
  p+=length
 return result
if __name__=='__main__':
 for name in sys.argv[1:]:
  p=Path(name);ts=texts(p.read_bytes());print(name,len(ts))
  Path(str(p)+'.texts.json').write_text(json.dumps(ts,ensure_ascii=False,indent=2))
  for t in ts[:35]:print(t['opcode'],t['capacity'],t['text'])
