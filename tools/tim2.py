"""Minimal TIM2 reader -> PIL images (first picture only)."""
import struct
from PIL import Image

def read(b, swizzle_pal=False):
    assert b[:4]==b'TIM2'
    count=struct.unpack_from('<H',b,6)[0]
    off=16
    total,clutsize,imgsize,hdr,ncol,fmt,mip,clutType,imgType,w,h=struct.unpack_from('<IIIHHBBBBHH',b,off)
    data=b[off+hdr:off+hdr+imgsize]
    clut=b[off+hdr+imgsize:off+hdr+imgsize+clutsize]
    def pal(n):
        out=[]
        csm2=bool(clutType&0x80)
        t=clutType&0x3f
        for i in range(n):
            if t==3:
                r,g,bb,a=clut[i*4:i*4+4];a=min(255,a*2) if a<=128 else 255
            elif t==2:
                r,g,bb=clut[i*3:i*3+3];a=255
            elif t==1:
                v=struct.unpack_from('<H',clut,i*2)[0]
                r=(v&31)*255//31;g=((v>>5)&31)*255//31;bb=((v>>10)&31)*255//31;a=255 if v&0x8000 else 0
            out.append((r,g,bb,a))
        if swizzle_pal and n==256:
            o=list(out)
            for i in range(256):
                j=(i&0xe7)|((i&0x08)<<1)|((i&0x10)>>1)
                o[i]=out[j]
            out=o
        return out
    im=Image.new('RGBA',(w,h))
    px=im.load()
    if imgType==5:
        p=pal(256)
        for y in range(h):
            for x in range(w):
                px[x,y]=p[data[y*w+x]]
    elif imgType==4:
        p=pal(16)
        for y in range(h):
            for x in range(w):
                v=data[(y*w+x)//2]
                px[x,y]=p[(v>>4)&15 if (x&1) else v&15]
    elif imgType==3:
        for y in range(h):
            for x in range(w):
                r,g,bb,a=data[(y*w+x)*4:(y*w+x)*4+4];px[x,y]=(r,g,bb,min(255,a*2))
    elif imgType==2:
        for y in range(h):
            for x in range(w):
                r,g,bb=data[(y*w+x)*3:(y*w+x)*3+3];px[x,y]=(r,g,bb,255)
    elif imgType==1:
        for y in range(h):
            for x in range(w):
                v=struct.unpack_from('<H',data,(y*w+x)*2)[0]
                px[x,y]=((v&31)*255//31,((v>>5)&31)*255//31,((v>>10)&31)*255//31,255 if v&0x8000 else 0)
    else:
        raise ValueError(imgType)
    return im,dict(w=w,h=h,imgType=imgType,clutType=clutType,count=count)
