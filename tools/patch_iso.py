import struct,sys,shutil
from pathlib import Path
def find_record(f,wanted):
 f.seek(16*2048);root=f.read(2048)[156:190]
 def walk(rec,prefix=''):
  sector=struct.unpack_from('<I',rec,2)[0];size=struct.unpack_from('<I',rec,10)[0]
  f.seek(sector*2048);data=f.read(size);i=0
  while i<len(data):
   n=data[i]
   if not n:i=(i//2048+1)*2048;continue
   recordpos=sector*2048+i;r=data[i:i+n];i+=n
   name=r[33:33+r[32]].decode('ascii').split(';')[0]
   if name in ('\x00','\x01'):continue
   path=prefix+'/'+name
   if path==wanted:return recordpos,r
   if r[25]&2:
    v=walk(r,path)
    if v:return v
  return None
 return walk(root)
if __name__=='__main__':
 original,replacement,out=map(Path,sys.argv[1:4])
 with original.open('rb') as f:position,record=find_record(f,'/PSP_GAME/INSDIR/INSTALL.DNS')
 if original.resolve()==out.resolve():raise ValueError('Output must differ from the original ISO')
 shutil.copy2(original,out)
 data=replacement.read_bytes()
 with out.open('r+b') as f:
  f.seek(0,2);start=(f.tell()+2047)//2048*2048;f.seek(start);f.write(data);f.write(b'\0'*((-len(data))%2048));size=f.tell()
  f.seek(position+2);f.write(struct.pack('<I',start//2048)+struct.pack('>I',start//2048))
  f.seek(position+10);f.write(struct.pack('<I',len(data))+struct.pack('>I',len(data)))
  f.seek(16*2048+80);f.write(struct.pack('<I',size//2048)+struct.pack('>I',size//2048))
 with out.open('rb') as f:
  _,r=find_record(f,'/PSP_GAME/INSDIR/INSTALL.DNS');sector=struct.unpack_from('<I',r,2)[0]
  assert sector==start//2048 and struct.unpack_from('<I',r,10)[0]==len(data)
  f.seek(sector*2048);assert f.read(len(data))==data
 print('Created',out,'bytes',size)
