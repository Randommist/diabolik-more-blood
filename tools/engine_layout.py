"""Pixel geometry recovered from EBOOT; accepts explicit runtime configuration.

Only horizontal, left-aligned runs are certified. Unknown tags/configurations raise
instead of silently approving text. Coordinates describe glyph quads (transparent
padding included), then the same integer truncation used by the GPU submission.
"""
import math, struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]


def f32(v):return struct.unpack('<f',struct.pack('<f',v))[0]
def signed(v):return v-0x100000000 if v>=0x80000000 else v
def word_float(v):return struct.unpack('<f',struct.pack('<I',v))[0]
def metrics(path=None):
    path=Path(path) if path else ROOT/'build/patched-crisp/font-0'
    b=path.read_bytes();table=struct.unpack_from('<I',b,24)[0];result={}
    for p in range(0x428,table,12):
        a,z,i=struct.unpack_from('<III',b,p)
        for c in range(a,z):result[c]=struct.unpack_from('<BB',b,table+(i+c-a)*8)
    return result

def encoded_code(ch):
    from glyphs import code_of
    return code_of(ch)
def configuration(words,base_width=20,base_height=20,baseline_offset=0):
    if len(words)!=13:raise ValueError('Expected 13 configuration words')
    flags,font,variant,mode,gapx,gapy,mx,my,unknown,align,cx,cy,height=words
    if align!=0:raise ValueError('Only horizontal left-aligned mode 0 is certified')
    if font!=0:raise ValueError('Font 0 only; provide a recovered font-specific model')
    if flags!=0:raise ValueError('Only flags=0 has been validated against runtime records')
    if unknown!=0:raise ValueError('Unsupported configuration word 8')
    scale=f32(1 if flags&4 else f32(height)/f32(base_height))
    return dict(flags=flags,mode=signed(mode),gapx=signed(gapx),gapy=signed(gapy),
                mx=f32(1 if flags&4 else word_float(mx)),my=f32(1 if flags&4 else word_float(my)),
                cx=word_float(cx),cy=word_float(cy),scale=scale,
                base_width=base_width,base_height=base_height,baseline_offset=baseline_offset)

def glyph_layout(text,words,origin=(0,0),font=None,base_width=20,base_height=20,baseline_offset=0):
    c=configuration(words,base_width,base_height,baseline_offset);font=font or metrics()
    # #n completes a line; the next glyph advances it. Consecutive empty #n's
    # do not advance the renderer until a glyph is emitted. Blank d2 uses U+3000.
    parts=text.replace('#n','\n').replace('\r\n','\n').split('\n')
    if any('#' in p or '\r' in p for p in parts):raise ValueError('Unresolved control tag / carriage return')
    x=y=f32(0);line=-1;out=[];stepx=f32(c['mx']*c['scale']);stepy=f32(c['my']*c['scale'])
    dx=c['gapx'] if c['mode']==1 else c['base_width']+c['gapx']
    dy=c['gapy'] if c['mode']==1 else c['base_height']+c['gapy']
    for part in parts:
        if not part:continue
        line+=1;x=f32(0)
        if line:y=f32(y+f32(dy*stepy))
        if c['flags']&2:y=f32(y+f32(f32(f32(c['cy']*c['my'])*c['scale'])*base_height))
        for ch in part:
            code=encoded_code(ch)
            if code not in font:raise ValueError(f'Missing glyph {ch!r} {code:#x}')
            w,h=font[code]
            centerx=f32(x+f32(f32(f32(base_width*c['cx'])*c['scale'])*c['mx']))
            centery=f32(f32(y-baseline_offset)+f32(f32(f32(base_height*c['cy'])*c['scale'])*c['my']))
            halfw=f32(f32(w*-0.5)*stepx);halfh=f32(f32(h*-0.5)*stepy)
            local=(f32(centerx+halfw),f32(centery+halfh),f32(centerx-halfw),f32(centery-halfh))
            gpu=[math.trunc(f32(v+origin[i%2])) for i,v in enumerate(local)]
            out.append(dict(code=code,width=w,height=h,x=centerx,y=centery,sx=stepx,sy=stepy,
                            line=line,local_quad=local,gpu_quad=gpu))
            advance=c['gapx'] if c['mode']==1 else ((base_width if c['mode']==0 else w)+c['gapx'])
            x=f32(x+f32(advance*stepx))
    return out

def fit(text,words,origin,clip=(0,0,480,272),font=None):
    glyphs=glyph_layout(text,words,origin,font);bad=[]
    for i,g in enumerate(glyphs):
        l,t,r,b=g['gpu_quad']
        if l<clip[0] or t<clip[1] or r>clip[2] or b>clip[3]:bad.append(i)
    bounds=[min(g['gpu_quad'][0] for g in glyphs),min(g['gpu_quad'][1] for g in glyphs),max(g['gpu_quad'][2] for g in glyphs),max(g['gpu_quad'][3] for g in glyphs)] if glyphs else None
    return dict(fits=not bad,bounds=bounds,overflow_glyph_indices=bad,rendered_lines=len({g['line'] for g in glyphs}),clip=list(clip),origin=list(origin))

CONFIG_ROWS={'main_win':0x8,'name_win':0x22,'novel':0x3c,'choice':0x58,'auxiliary':0x72,'ruby':0x90,'chapter':0xc2,'auxiliary_2':0xdc}
def resource_configuration(name,path=None):
    """0x58004 loads font/100; 0x57f78 converts signed shorts to 13 words."""
    b=Path(path or ROOT/'build/extracted/resources/font/100').read_bytes();p=CONFIG_ROWS[name]
    a=struct.unpack_from('<13h',b,p)
    def u32(v):return v&0xffffffff
    def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
    # a[4:6] are separate auxiliary parameters, not renderer configuration.
    return [u32(a[1]),u32(a[2]),u32(a[3]),u32(a[6]),u32(a[7]),u32(a[8]),bits(1),bits(1),u32(a[11]),u32(a[0]),bits(f32(a[12]/100)),bits(f32(a[10]/100)),u32(a[9])]
