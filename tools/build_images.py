"""Build a test ISO with the Russian images (and the Russian name-entry keyboard) on top of build/patched-crisp.
Images: translation/images/jobs.json + translation/images/ru/<id>.png; originals are read from build/extracted/INSTALL.CPK.
usage: build_images.py [out_iso]"""
import struct,sys,json,subprocess
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
from cpk import index,read_entry
import png_to_tim2,patch_keyboard,patch_default_name
ROOT=Path(__file__).resolve().parents[1]
IMAGES=ROOT/'translation/images'
OUT=ROOT/'build/images';OUT.mkdir(parents=True,exist_ok=True)
def patch_cpk(src,replacements,dest):
    h,es=index(src);b=bytearray(src.read_bytes())
    tocstart=h['TocOffset'];toc=bytearray(b[tocstart:tocstart+h['TocSize']]);packet=bytearray(toc[16:]);encrypted=packet[:4]!=b'@UTF'
    def xor(v):
        key=0x655f
        for i in range(len(v)):v[i]^=key&255;key=(key*0x4115)&0xffffffff
    if encrypted:xor(packet)
    base=8;rowstart=base+struct.unpack_from('>H',packet,10)[0];rowlen=struct.unpack_from('>H',packet,26)[0]
    assert list(es[0].keys())[:8]==['DirName','FileName','FileSize','ExtractSize','FileOffset','ID','UserString','CRC']
    done=set()
    for i,e in enumerate(es):
        key=(e['DirName'],e['FileName'])
        if key not in replacements:continue
        data=replacements[key];offset=(len(b)+2047)//2048*2048;b.extend(b'\0'*(offset-len(b)));b.extend(data)
        row=rowstart+i*rowlen
        assert struct.unpack_from('>I',packet,row+8)[0]==e['FileSize']
        struct.pack_into('>IIQ',packet,row+8,len(data),len(data),offset-min(h['TocOffset'],h['ContentOffset']));done.add(key)
    assert done==set(replacements),set(replacements)-done
    if encrypted:xor(packet)
    b[tocstart+16:tocstart+16+len(packet)]=packet
    dest.write_bytes(b)
    nh,nes=index(dest)
    for e in nes:
        key=(e['DirName'],e['FileName'])
        if key in replacements:assert b[e['absolute']:e['absolute']+e['FileSize']]==replacements[key]
def collect():
    jobs=json.load(open(IMAGES/'jobs.json'));rep={}
    cpk=ROOT/'build/extracted/INSTALL.CPK';entries=index(cpk)[1]
    for j in jobs:
        d,n=j['src'].split('/');orig=read_entry(cpk,entries,d,n)
        rep[(d,n)]=png_to_tim2.encode(orig,IMAGES/'ru'/f"{j['id']}.png")
    return rep
if __name__=='__main__':
    rep=collect()
    rep[('script','0')]=patch_default_name.resize((ROOT/'build/extracted/resources/script/0').read_bytes(),patch_default_name.EDITS)
    print(len(rep),'images converted')
    cpk=OUT/'INSTALL.CPK';patch_cpk(ROOT/'build/patched-crisp/INSTALL.CPK',rep,cpk)
    dns=OUT/'INSTALL.DNS'
    subprocess.run([str(ROOT/'vendor/pgd_tool'),'encrypt',str(ROOT/'build/extracted/PSP_GAME/INSDIR/INSTALL.DNS'),str(cpk),str(dns)],check=True)
    rt=OUT/'roundtrip.CPK';subprocess.run([str(ROOT/'vendor/pgd_tool'),'decrypt',str(dns),str(rt)],check=True)
    assert rt.read_bytes()==cpk.read_bytes();rt.unlink()
    mid=OUT/'mid.iso';subprocess.run([sys.executable,str(ROOT/'tools/patch_iso.py'),str(ROOT/'source/Diabolik-MoreBlood-JPN.iso'),str(dns),str(mid)],check=True)
    elf=OUT/'EBOOT.ru.elf';elf.write_bytes(patch_keyboard.patch_footer(patch_keyboard.patch((ROOT/'analysis/EBOOT.decrypted.bin').read_bytes())))
    final=Path(sys.argv[1]) if len(sys.argv)>1 else ROOT/'outputs/Diabolik-MoreBlood-RU-images-test.iso'
    patch_keyboard.iso(mid,final,elf);mid.unlink();print('Built',final)
