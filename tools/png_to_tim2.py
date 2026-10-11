"""PNG -> TIM2 in the exact layout of an original game TIM2 (single picture, 8/4-bit indexed, RGBA32 CLUT).
Palette of 256 entries is stored in PS2 'swizzled' order; CLUT alpha is stored as half range (255 -> 128).
usage: png_to_tim2.py original.tim2 picture.png out.tim2 | selftest original.tim2 (round-trip through the reader)"""
import struct,sys
from pathlib import Path
from PIL import Image
def swz(i):return (i&0xe7)|((i&0x08)<<1)|((i&0x10)>>1)
def header(b):
    assert b[:4]==b'TIM2' and struct.unpack_from('<H',b,6)[0]==1
    total,clutsize,imgsize,hdr,ncol,fmt,mip,ct,it,w,h=struct.unpack_from('<IIIHHBBBBHH',b,16)
    assert hdr==48 and ct==3 and it in (4,5) and len(b)==16+total
    return dict(clutsize=clutsize,imgsize=imgsize,hdr=hdr,ncol=ncol,ct=ct,it=it,w=w,h=h)
def encode(orig,png):
    H=header(orig);w,h,n=H['w'],H['h'],16 if H['it']==4 else 256
    im=Image.open(png).convert('RGBA')
    if im.size!=(w,h):raise ValueError(f'size {im.size} != {(w,h)}')
    # quantise with alpha (fast octree keeps an alpha channel); no dithering for UI art
    q=im.quantize(colors=n,method=Image.Quantize.FASTOCTREE,dither=Image.Dither.NONE)
    pal=q.getpalette(rawmode='RGBA') if q.palette.mode=='RGBA' else None
    if pal is None:raise RuntimeError('palette without alpha')
    cols=[tuple(pal[i*4:i*4+4]) for i in range(n)]
    idx=list(q.tobytes())
    # normalise transparent entries so identical invisible pixels share one colour
    clut=bytearray(n*4)
    for i in range(n):
        r,g,b,a=cols[i]
        if a==0:r=g=b=0
        s=min(128,(a+1)//2) if a<255 else 128
        j=swz(i) if n==256 else i
        clut[j*4:j*4+4]=bytes((r,g,b,s))
    if H['it']==5:data=bytes(idx)
    else:
        data=bytearray(w*h//2)
        for k,v in enumerate(idx):data[k//2]|=(v&15)<<(4 if k&1 else 0)
        data=bytes(data)
    assert len(data)==H['imgsize'] and len(clut)<=H['clutsize'],(len(data),H['imgsize'],len(clut),H['clutsize'])
    clut=bytes(clut)+b'\0'*(H['clutsize']-len(clut))
    return orig[:16+H['hdr']]+data+clut
if __name__=='__main__':
    if sys.argv[1]=='selftest':
        sys.path.insert(0,str(Path(__file__).parent))
        from tim2 import read
        b=Path(sys.argv[2]).read_bytes();im,_=read(b,swizzle_pal=True)
        tmp=Path('/tmp/_rt.png');im.save(tmp);nb=encode(b,tmp);im2,_=read(nb,swizzle_pal=True)
        bg=Image.new('RGBA',im.size,(128,128,128,255));a=bg.copy();a.alpha_composite(im);c=bg.copy();c.alpha_composite(im2)
        from PIL import ImageChops
        d=ImageChops.difference(a.convert('RGB'),c.convert('RGB'));hist=d.convert('L').histogram()
        n=im.size[0]*im.size[1];mean=sum(i*v for i,v in enumerate(hist))/n
        print(sys.argv[2],'size',len(b),len(nb),'mean abs diff on grey %.2f'%mean,'max',max(i for i,v in enumerate(hist) if v))
    else:
        Path(sys.argv[3]).write_bytes(encode(Path(sys.argv[1]).read_bytes(),sys.argv[2]))
