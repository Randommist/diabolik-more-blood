"""Russian name-entry keyboard: patch the character grid table in the (decrypted) EBOOT ELF and, optionally, build a test ISO.
Table (file offsets of analysis/EBOOT.decrypted.bin):
  0x31f840  60 bytes  cell -> variant-entry id (12 rows x 5, ff = empty cell)
  0x31f87c  12 rows x 11 bytes  cp932 grid labels (5 chars + NUL)
  0x31f904  49 entries x 0x64: variant string (cycled with the key), +0x54 variant count, +0x58 kanji start code, +0x5c kanji count
usage: patch_keyboard.py out_elf [base_iso out_iso]"""
import struct,sys,shutil
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
ROOT=Path(__file__).resolve().parents[1]
MAP,GRID,ENT,STRIDE=0x31f840,0x31f87c,0x31f904,0x64
ALPHA='АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'
from glyphs import encode as enc
def patch(b):
    """Letters fill the 10x5 grid contiguously in reading order (the kana layout's gaps are not kept)."""
    b=bytearray(b);letters=list(ALPHA)
    for r in range(10):b[GRID+r*11:GRID+r*11+10]=b'\x81\x40'*5   # clear labels
    for r in range(10):
        for c in range(5):
            k=r*5+c;i=MAP+r*5+c
            if k>=len(letters):b[i]=0xff;continue          # unused cell stays empty
            b[i]=k;eid=k;L=letters[k];var=enc(L+L.lower(),True)  # entry ids 0..45 are kana entries we may reuse
            b[GRID+r*11+c*2:GRID+r*11+c*2+2]=enc(L,True)
            a=ENT+STRIDE*eid;b[a:a+0x54]=var+b'\0'*(0x54-len(var))
            struct.pack_into('<III',b,a+0x54,2,0,0)
    # mode keys (英 数 記 = Latin / digits / symbols): language-neutral labels
    r=10;b[GRID+r*11:GRID+r*11+10]='Ａ１＠　　'.encode('cp932')
    return bytes(b)
def iso(base,out,elf):
    from patch_iso import find_record
    shutil.copy2(base,out);data=Path(elf).read_bytes()
    with open(out,'r+b') as f:
        pos,rec=find_record(f,'/PSP_GAME/SYSDIR/EBOOT.BIN');sec=struct.unpack_from('<I',rec,2)[0];size=struct.unpack_from('<I',rec,10)[0]
        assert len(data)<=size,(len(data),size)
        f.seek(sec*2048);f.write(data);f.write(b'\0'*(size-len(data)))
        f.seek(pos+10);f.write(struct.pack('<I',len(data))+struct.pack('>I',len(data)))
    print('ISO',out)
if __name__=='__main__':
    src=(ROOT/'analysis/EBOOT.decrypted.bin').read_bytes();out=Path(sys.argv[1]);out.parent.mkdir(parents=True,exist_ok=True)
    out.write_bytes(patch(src));print('ELF',out,len(src))
    if len(sys.argv)>3:iso(sys.argv[2],sys.argv[3],out)

# ---- footer button labels (strings are referenced from code by lui/addiu pairs; every unique label is re-packed into the old block)
FOOT0,FOOT1=0x158218,0x15831c
LABELS={'決定':'Ввод','進む':'Далее','戻る':'Назад','選択':'Выбор','切り替え':'Смена','初期化':'Сброс','結果確認':'Итоги','終了':'Выход',
 '再生':'Пуск','シーンバック':'Сцена','ゲームに戻る':'Назад','キャラクター切替':'Смена','操作説明ＯＮ／ＯＦＦ':'Помощь','次へ':'Далее',
 '差分表示':'Вид','停止':'Стоп','確定':'ОК','ページ切り替え':'Смена','メールを閉じる':'Выход','削除':'Удал.','スクロール':'Скролл'}
def patch_footer(b):
    b=bytearray(b);block=bytes(b[FOOT0:FOOT1]);old={};p=0
    for s in block.split(b'\0'):
        if s:
            jp=s.decode('cp932')
            assert jp.endswith('%s')
            old[jp[:-2]]=FOOT0+p
        p+=len(s)+1
    code=bytes(b[0xc0:0xc0+0x329824]);new={};pos=FOOT0;pool=b''
    def refs(off):
        va=off-0xc0;lo=va&0xffff;hi=(va>>16)+(1 if lo&0x8000 else 0);out=[]
        for i in range(0,len(code)-4,4):
            w=struct.unpack_from('<I',code,i)[0]
            if (w>>26)==9 and (w&0xffff)==lo:
                rs=(w>>21)&31
                for k in range(1,12):
                    if i-4*k<0:break
                    q=struct.unpack_from('<I',code,i-4*k)[0]
                    if (q>>26)==15 and (q&0xffff)==hi and ((q>>16)&31)==rs:out.append(i+0xc0);break
        return out
    plan=[];strings={}
    for jp,ru in LABELS.items():
        if jp not in old:continue
        r=refs(old[jp])
        if not r:print('no code reference, label left as is:',jp);continue
        plan.append((jp,ru,r))
    for jp,ru,r in plan:
        if ru not in strings:
            s=enc(ru)+b'%s\0';s+=b'\0'*(-len(s)%4);strings[ru]=(FOOT0+len(pool),s);pool+=s
    assert len(pool)<=FOOT1-FOOT0,(len(pool),FOOT1-FOOT0)
    # keep the 4-byte-aligned original tail (e.g. '%s' entries at 0x15820c/0x158214 are before FOOT0)
    b[FOOT0:FOOT1]=pool+b'\0'*(FOOT1-FOOT0-len(pool))
    for jp,ru,r in plan:
        va=strings[ru][0]-0xc0
        for i in r:
            w=struct.unpack_from('<I',b,i)[0];assert ((va>>16)+(1 if va&0x8000 else 0))==((struct.unpack_from('<I',b,i-4)[0] if False else (va>>16)+(1 if va&0x8000 else 0)))
            struct.pack_into('<I',b,i,(w&0xffff0000)|(va&0xffff))
    print('footer labels:',len(strings),'strings,',len(pool),'of',FOOT1-FOOT0,'bytes')
    return bytes(b)

QUICK={0x14d000:('クイックセーブしました。','Сохранено.'),
       0x14d01c:('クイックロードします。#nよろしいですか？','Быстрая загрузка?'),
       0x14d048:('クイックロードできるデータがありません。','Нет сохранения.'),
       0x14d074:('#nクイックロード','#nЗагруз.')}

def patch_quick(b):
    b=bytearray(b)
    for off,(jp,ru) in QUICK.items():
        old=jp.encode('cp932');assert b[off:off+len(old)]==old,hex(off)
        cap=(len(old)//4+1)*4;new=enc(ru);assert len(new)<cap,(ru,len(new),cap)
        b[off:off+cap]=new+b'\0'*(cap-len(new))
    return bytes(b)

SYS0,SYS1=0x149158,0x14938c
SYSTEM=[(0x149158,'#Scale[%f]Загружено'),
(0x149184,'#Scale[%f]Поддерживается автосохранение.#n　#nПри сохранении мигает#nиндикатор Memory Stick#Scale[%f]TM#Scale[%f]#n　#nНе вынимайте носитель и не выключайте PSP#n　#nПеревод: Randommist'),
(0x149270,'#Scale[%f]Ошибка чтения'),
(0x1492a0,'#Scale[%f]Данные не найдены'),
(0x1492d0,'#Scale[%f]#nДанные повреждены'),
(0x149324,'#Scale[%f]Проверка данных.#nНе вынимайте носитель')]

def patch_system(b):
    """Start-up system-data messages: rebuild the string pool and repoint the lui/addiu references."""
    b=bytearray(b);code=bytes(b[0xc0:0xc0+0x329824])
    def refs(off):
        va=off-0xc0;lo=va&0xffff;hi=(va>>16)+(1 if lo&0x8000 else 0);out=[]
        for i in range(0,len(code)-4,4):
            w=struct.unpack_from('<I',code,i)[0]
            if (w>>26)==9 and (w&0xffff)==lo:
                rs=(w>>21)&31
                for k in range(1,12):
                    if i-4*k<0:break
                    q=struct.unpack_from('<I',code,i-4*k)[0]
                    if (q>>26)==15 and (q&0xffff)==hi and ((q>>16)&31)==rs:out.append(i+0xc0);break
        return out
    pool=b'';plan=[]
    for off,ru in SYSTEM:
        r=refs(off);assert len(r)==1,hex(off)
        s=enc(ru)+b'\0';s+=b'\0'*(-len(s)%4);plan.append((SYS0+len(pool),r[0]));pool+=s
    assert len(pool)<=SYS1-SYS0,(len(pool),SYS1-SYS0)
    b[SYS0:SYS1]=pool+b'\0'*(SYS1-SYS0-len(pool))
    for new,i in plan:
        va=new-0xc0;assert (va>>16)+(1 if va&0x8000 else 0)==(va>>16)+(1 if va&0x8000 else 0)
        w=struct.unpack_from('<I',b,i)[0];struct.pack_into('<I',b,i,(w&0xffff0000)|(va&0xffff))
    print('system messages:',len(pool),'of',SYS1-SYS0,'bytes')
    return bytes(b)
