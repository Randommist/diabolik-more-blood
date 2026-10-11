"""Export the original game graphics (needed only for re-drawing images, not for the build).
usage: extract_images.py     -> build/assets/<dir>/<name> (raw TIM2/data) and build/png/<dir>/<name>.png
Dirs: system, aex, back, sub from build/extracted/INSTALL.CPK (see docs/SETUP.md)."""
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
import cpk,tim2
ROOT=Path(__file__).resolve().parents[1]
src=ROOT/'build/extracted/INSTALL.CPK';entries=cpk.index(src)[1];n=0
for e in entries:
    d=str(e['DirName'])
    if d not in ('system','aex','back','sub'):continue
    name=str(e['FileName']);b=cpk.read_entry(src,entries,d,name)
    raw=ROOT/'build/assets'/d/name;raw.parent.mkdir(parents=True,exist_ok=True);raw.write_bytes(b)
    if b[:4]==b'TIM2':
        png=ROOT/'build/png'/d/(name+'.png');png.parent.mkdir(parents=True,exist_ok=True);tim2.read(b,True)[0].save(png)
    n+=1
print(n,'files exported to build/assets and build/png')
