"""Custom glyph slots in font-0 (rare, unused Shift-JIS codes) and the text encoder used by every tool.
Cyrillic + « » … use EA40..; punctuation, digits and Latin get their own white (outline-free) glyphs in unused E980.. slots.
Control tags (#Name[2], #n, #Color[0] ...) are kept as plain ASCII."""
import re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
CYR='АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя«»'
EXTRA_PUNCT='….,-?!():;"\'―~'
DIGITS='0123456789'
LATIN='ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
ALPHABET=CYR+EXTRA_PUNCT+DIGITS+LATIN
EA=list(range(0xea40,0xea7f))+list(range(0xea80,0xeaa5))
E9=[c for c in list(range(0xe940,0xe97f))+list(range(0xe980,0xe9fd))]
def _codes():
    # Cyrillic and the first custom glyphs fill EA40..EAA4 in order; the rest continue in E9 slots that no script/EBOOT string uses
    slots=EA+E9;return slots
_slots=_codes()
# The PSP save-data menu converts the game's Shift-JIS to UTF-8 itself, so every glyph that has a real
# Shift-JIS counterpart (Cyrillic, full-width digits/Latin/punctuation) sits on that code: the menu then shows real text.
REAL={'…':'…','.':'．',',':'，','-':'－','?':'？','!':'！','(':'（',')':'）',':':'：',';':'；','"':'”',"'":'’','~':'～'}
def _real(ch):
    if ch in REAL:u=REAL[ch]
    elif ch in DIGITS or ch in LATIN:u=chr(ord(ch)+0xfee0)
    elif ch in '«»―':return None
    else:u=ch
    try:b=u.encode('cp932')
    except UnicodeEncodeError:return None
    return int.from_bytes(b,'big') if len(b)==2 else None
# Name entry (keyboard grid, default name) keeps the original rare-slot codes: the engine's name handling only copes with those
LEGACY=dict(zip(CYR[:66],_slots[:66]))
_spare=iter(_slots[66:]);CODES=[]
for _ch in ALPHABET:
    _c=_real(_ch);CODES.append(_c if _c is not None else next(_spare))
MAPPING=dict(zip(ALPHABET,CODES))
NORMALISE=str.maketrans({'？':'?','！':'!','。':'.','、':',','～':'~','“':'"','”':'"','’':"'",'‘':"'",'─':'―','—':'―','–':'-'})
TAG=re.compile(r'#[A-Za-z0-9_]+(?:\[[^\]]*\])?|%[sdf]')
def encode_char(ch,legacy=False):
    c=(LEGACY if legacy else MAPPING).get(ch)
    if c is None:c=MAPPING.get(ch)
    return c.to_bytes(2,'big') if c is not None else ch.encode('cp932')
def encode(s,legacy=False):
    out=b'';pos=0
    for m in TAG.finditer(s):
        out+=b''.join(encode_char(ch,legacy) for ch in s[pos:m.start()].translate(NORMALISE));out+=m.group().encode('ascii');pos=m.end()
    return out+b''.join(encode_char(ch,legacy) for ch in s[pos:].translate(NORMALISE))
def code_of(ch):
    ch=ch.translate(NORMALISE)
    if ch in MAPPING:return MAPPING[ch]
    return int.from_bytes(ch.encode('cp932'),'big')
