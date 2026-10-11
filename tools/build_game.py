"""Apply the whole Russian translation to the game scripts and build a test ISO.
Sources: translation/scenes/*.json, corpus/records.json and corpus/fixed.json (fixed lines such as speaker names).
Lines that are not translated (manual / original retained) stay Japanese.
usage: build_game.py [out_iso]  |  --scenes 101 300 (only these scripts, for quick tests)"""
import json,sys,subprocess,collections
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
from stcm import texts
from script_patch import resize
import patch_keyboard,patch_default_name,build_images,patch_places,patch_strings
from glyphs import encode as enc

ROOT=Path(__file__).resolve().parents[1];W=ROOT/'translation'
def load():
    records=json.loads((W/'corpus/records.json').read_text());by_key={(r['scene'],r['index']):r for r in records};by_id={r['id']:r for r in records}
    fixed=json.loads((W/'corpus/fixed.json').read_text())
    ru={}
    for path in sorted((W/'scenes').glob('*.json'),key=lambda p:(p.stem.startswith('scene-'),p.stem)):
        name=path.name
        for e in json.loads(path.read_text()):
            r=by_id[e['id']]
            assert r['ja']==e['ja'] and r['index']==e['index'] and e.get('scene',r['scene'])==r['scene'] and e.get('action',r['action'])==r['action'],(name,e['id'])
            ru[r['id']]=e['ru']
    for k,v in fixed.items():ru.setdefault(int(k),v)
    import reflow
    ru,_=reflow.apply(by_key,ru)
    return by_key,ru
def build_scripts(only=None):
    by_key,ru=load();out={};stats=collections.Counter();bad=[]
    for f in sorted((ROOT/'build/extracted/resources/script').iterdir(),key=lambda p:int(p.name) if p.name.isdigit() else 10**9):
        if not f.name.isdigit() or (only and f.name not in only):continue
        b=f.read_bytes();ts=texts(b);edits={};want={}
        for i,t in enumerate(ts):
            r=by_key.get((f.name,i))
            if not r:continue
            s=ru.get(r['id'])
            if s is None or s==t['text']:continue
            assert r['action']==t['action'] and r['ja']==t['text'],(f.name,i)
            try:raw=enc(s)
            except UnicodeEncodeError as e:bad.append((f.name,i,s,str(e)));stats['unencodable']+=1;continue
            edits[t['action']]=(t['offset'],t['capacity'],raw);want[i]=raw
        if not edits:continue
        new=resize(b,edits);nt=texts(new);assert len(nt)==len(ts),f.name
        for i,raw in want.items():assert new[nt[i]['offset']:nt[i]['offset']+len(raw)]==raw,(f.name,i)
        out[('script',f.name)]=new;stats['scripts']+=1;stats['lines']+=len(edits)
    print(dict(stats))
    if bad:
        for x in bad[:20]:print('UNENCODABLE',x)
    return out,bad
if __name__=='__main__':
    only=None;args=sys.argv[1:]
    if args[:1]==['--scenes']:only=set(args[1:]);args=[]
    scripts,bad=build_scripts(only)
    rep=build_images.collect();rep.update(scripts)
    rep[('script','0')]=patch_default_name.resize((ROOT/'build/extracted/resources/script/0').read_bytes(),patch_default_name.EDITS)
    rep[('script','1')]=patch_places.patch((ROOT/'build/extracted/resources/script/1').read_bytes())
    out=build_images.OUT;cpk=out/'INSTALL.CPK'
    build_images.patch_cpk(ROOT/'build/patched-crisp/INSTALL.CPK',rep,cpk)
    dns=out/'INSTALL.DNS'
    subprocess.run([str(ROOT/'vendor/pgd_tool'),'encrypt',str(ROOT/'build/extracted/PSP_GAME/INSDIR/INSTALL.DNS'),str(cpk),str(dns)],check=True)
    rt=out/'roundtrip.CPK';subprocess.run([str(ROOT/'vendor/pgd_tool'),'decrypt',str(dns),str(rt)],check=True)
    assert rt.read_bytes()==cpk.read_bytes();rt.unlink()
    mid=out/'mid.iso';subprocess.run([sys.executable,str(ROOT/'tools/patch_iso.py'),str(ROOT/'source/Diabolik-MoreBlood-JPN.iso'),str(dns),str(mid)],check=True)
    elf=out/'EBOOT.ru.elf';elf.write_bytes(patch_strings.patch(patch_keyboard.patch_system(patch_keyboard.patch_quick(patch_keyboard.patch_footer(patch_keyboard.patch((ROOT/'analysis/EBOOT.decrypted.bin').read_bytes()))))))
    final=Path(args[0]) if args else ROOT/'outputs/Diabolik-MoreBlood-RU-full-test.iso'
    patch_keyboard.iso(mid,final,elf);mid.unlink();print('Built',final)
