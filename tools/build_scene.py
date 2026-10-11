import struct,json,sys,os
from pathlib import Path
from PIL import Image,ImageFont,ImageDraw
from cpk import index
from stcm import texts
ROOT=Path(__file__).resolve().parents[1]
CRISP='--crisp' in sys.argv
OUT=ROOT/('build/patched-crisp' if CRISP else 'build/patched');OUT.mkdir(parents=True,exist_ok=True)
translation={int(k):v for k,v in json.loads((ROOT/'translation/opening.json').read_text()).items()}
# Use reserved glyph slots in the existing font ranges. All other glyphs stay intact.
from glyphs import LEGACY,MAPPING,encode
mapping={ch:c.to_bytes(2,'big') for ch,c in MAPPING.items()}

PUNCT_BOX={'.':(8,0),',':(8,0),':':(8,0),';':(8,0),'!':(8,0),'?':(11,1),'(':(8,1),')':(10,0),'-':(10,1),'"':(8,0),"'":(6,0),'~':(12,1)}
def add_cyrillic_range(b,lo=0x8440,hi=0x8493,cap=192):
 # the original font has no glyphs for the Shift-JIS Cyrillic block: add one range (table entries + data) at the end
 table,data=struct.unpack_from('<II',b,24);ranges=[struct.unpack_from('<III',b,p) for p in range(0x428,table,12)]
 if any(a<=lo<z for a,z,i in ranges):return b
 count=(data-table)//8;n=hi-lo;ranges.append((lo,hi,count));ranges.sort()
 old_data=bytes(b[data:]);new_table=bytearray(b[table:data])
 for k in range(n):new_table+=struct.pack('<BBHI',11,20,cap,len(old_data)+k*cap)
 head=bytearray(b[:0x428]);rbytes=b''.join(struct.pack('<III',*r) for r in ranges)
 out=bytearray(head+rbytes+new_table);ndata=len(out);out+=old_data+bytes(n*cap)
 struct.pack_into('<II',out,24,0x428+len(rbytes),ndata);struct.pack_into('<I',out,4,count+n);return out

def patch_font():
 b=add_cyrillic_range(bytearray((ROOT/'build/extracted/resources/font/0').read_bytes()));table,data=struct.unpack_from('<II',b,24)
 ranges=[struct.unpack_from('<III',b,p) for p in range(0x428,table,12)]
 fontname='DejaVuSansMono-Bold.ttf' if CRISP else 'DejaVuSans.ttf'
 candidates=[os.environ.get('DIABOLIK_FONT',''),str(ROOT/'vendor/fonts/dejavu-fonts-ttf-2.37/ttf'/fontname),'/usr/share/fonts/TTF/'+fontname,'/usr/share/fonts/truetype/dejavu/'+fontname]
 fontpath=next((v for v in candidates if v and Path(v).is_file()),None)
 if fontpath is None:raise FileNotFoundError('Install DejaVu fonts or set DIABOLIK_FONT to '+fontname)
 f=ImageFont.truetype(fontpath,16)
 preview=Image.new('L',(11*34,120),0)
 for j,(ch,mcode) in enumerate(list(mapping.items())+[(c,v.to_bytes(2,'big')) for c,v in LEGACY.items()]):
  code=int.from_bytes(mcode,'big');idx=next(i+code-a for a,z,i in ranges if a<=code<z)
  glyphwidth=11 if CRISP else max(11,f.getbbox(ch)[2]+1)
  if ch=='…':
   # three baseline dots (the game's own … sits mid-line): same dot size and height as the font's full stop
   probe=Image.new('L',(11,20),0);pd=ImageDraw.Draw(probe);pd.fontmode='1' if CRISP else 'L';pd.text((0,0),'.',font=f,fill=255)
   x0,y0,x1,y1=probe.getbbox();dw=x1-x0;gap=2;glyphwidth=3*dw+2*gap+4
   im=Image.new('L',(glyphwidth,20),0)
   for k in range(3):im.paste(255,(2+k*(dw+gap),y0,2+k*(dw+gap)+dw,y1))
  elif ch=='―':
   glyphwidth=14;im=Image.new('L',(glyphwidth,20),0);im.paste(255,(2,9,12,11))
  else:
   cell=Image.new('L',(11,20),0);d=ImageDraw.Draw(cell)
   if CRISP:d.fontmode='1'
   d.text((0,0),ch,font=f,fill=255,stroke_width=0)
   if CRISP:assert f.getbbox(ch)[2]<=11,(ch,f.getbbox(ch))
   if ch in PUNCT_BOX:
    # The engine draws a glyph centred in a 12-px box and advances by the glyph's width byte, so a narrow glyph's ink lands at
    # (12-width)/2+left_pad. Pads below are chosen with that in mind (measured from in-game screenshots).
    box,pad=PUNCT_BOX[ch];x0,y0,x1,y1=cell.getbbox();glyphwidth=box;im=Image.new('L',(glyphwidth,20),0);im.paste(cell.crop((x0,0,x1,20)),(pad,0))
   else:im=cell
  # Align these hinted glyphs with the baseline of the other lowercase letters.
  if CRISP and ch in 'бю':
   shifted=Image.new('L',im.size,0);shifted.paste(im,(0,1));im=shifted
  if glyphwidth>11 and ch not in '…―~':im=im.resize((11,20),Image.Resampling.LANCZOS)
  pixels=[round(v*7/255) for v in im.getdata()];nibs=[];p=0
  while p<len(pixels):
   if not pixels[p]:
    end=p
    while end<len(pixels) and not pixels[end] and end-p<4095:end+=1
    run=end-p;nibs.extend([8,run>>8,(run>>4)&15,run&15]);p=end
   else:nibs.append(pixels[p]);p+=1
  if len(nibs)%2:nibs.append(0)
  raw=bytes((nibs[i]<<4)|nibs[i+1] for i in range(0,len(nibs),2))
  _,_,capacity,offset=struct.unpack_from('<BBHI',b,table+idx*8)
  assert len(raw)<=capacity,(ch,len(raw),capacity)
  b[data+offset:data+offset+capacity]=raw+b'\0'*(capacity-len(raw))
  struct.pack_into('<BBHI',b,table+idx*8,im.size[0],20,len(raw),offset)
  preview.paste(im,(j%34*11,j//34*20))
 struct.pack_into('<I',b,16,len(b));(OUT/'font-0').write_bytes(b);preview.resize((726,80),Image.Resampling.NEAREST if CRISP else Image.Resampling.BICUBIC).save(OUT/'cyrillic-font.png')
 return bytes(b)

def patch_script():
 b=(ROOT/'build/extracted/resources/script/101').read_bytes();ts=texts(b);by_action={ts[i]['action']:(ts[i],t) for i,t in translation.items()}
 p=b.index(b'CODE_START_')+12;start=p;end=struct.unpack_from('<I',b,32)[0]-12;actions=[];newpos=start;addresses={}
 while p<end:
  local,op,count,length=struct.unpack_from('<IIII',b,p);raw=bytearray(b[p:p+length]);oldlen=length
  if p in by_action:
   t,s=by_action[p];rawtext=encode(s);newcap=(len(rawtext)//4+1)*4
   off=t['offset']-p;oldcap=t['capacity'];raw[off:off+oldcap]=rawtext+b'\0'*(newcap-len(rawtext))
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
 # Link holds a pointer to a trailing collection block.
 ptr=struct.unpack_from('<I',b,link+4)[0];struct.pack_into('<I',tail,link+4-end,ptr+shift)
 header=bytearray(b[:start]);struct.pack_into('<I',header,32,exports+shift);struct.pack_into('<I',header,44,link+shift)
 result=bytes(header)+b''.join(bytes(a[3]) for a in actions)+tail
 newtexts=texts(result);assert len(newtexts)==len(ts)
 for i,s in translation.items():
  assert result[newtexts[i]['offset']:newtexts[i]['offset']+len(encode(s))]==encode(s)
 (OUT/'script-101').write_bytes(result)
 report=[dict(index=i,japanese=ts[i]['text'],russian=s) for i,s in translation.items()]
 (OUT/'translation-review.json').write_text(json.dumps(report,ensure_ascii=False,indent=2))
 return result

def patch_cpk(replacements):
 src=ROOT/'build/extracted/INSTALL.CPK';h,es=index(src);b=bytearray(src.read_bytes())
 tocstart=h['TocOffset'];toc=bytearray(b[tocstart:tocstart+h['TocSize']]);packet=bytearray(toc[16:]);encrypted=packet[:4]!=b'@UTF'
 def xor(v):
  key=0x655f
  for i in range(len(v)):v[i]^=key&255;key=(key*0x4115)&0xffffffff
 if encrypted:xor(packet)
 base=8;rowstart=base+struct.unpack_from('>H',packet,10)[0];rowlen=struct.unpack_from('>H',packet,26)[0]
 # Column layout is checked against this archive before editing.
 assert list(es[0].keys())[:8]==['DirName','FileName','FileSize','ExtractSize','FileOffset','ID','UserString','CRC']
 for i,e in enumerate(es):
  key=(e['DirName'],e['FileName'])
  if key not in replacements:continue
  data=replacements[key];offset=(len(b)+2047)//2048*2048;b.extend(b'\0'*(offset-len(b)));b.extend(data)
  row=rowstart+i*rowlen
  assert struct.unpack_from('>I',packet,row+8)[0]==e['FileSize']
  struct.pack_into('>IIQ',packet,row+8,len(data),len(data),offset-min(h['TocOffset'],h['ContentOffset']))
 if encrypted:xor(packet)
 b[tocstart+16:tocstart+16+len(packet)]=packet
 dest=OUT/'INSTALL.CPK';dest.write_bytes(b)
 # Validate replacements through the reader, including their exact byte lengths.
 nh,nes=index(dest)
 for e in nes:
  key=(e['DirName'],e['FileName'])
  if key in replacements:assert b[e['absolute']:e['absolute']+e['FileSize']]==replacements[key]
 return dest

if __name__=='__main__':
 font=patch_font();script=patch_script();dest=patch_cpk({('font','0'):font,('script','101'):script})
 print('Patched scene:',len(translation),'lines; font:',len(font),'bytes; archive:',dest)
