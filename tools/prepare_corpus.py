# Extracts the Japanese text corpus from the game scripts: translation/corpus/records.json (all lines) and fixed.json (lines that need no translation: names, opening, non-Japanese).
import json,math,re,struct
from pathlib import Path
from stcm import texts
ROOT=Path(__file__).resolve().parents[1];OUT=ROOT/'translation/corpus';
if (OUT/'records.json').exists():
 raise SystemExit('Corpus already exists; refusing to overwrite working records.')
OUT.mkdir(parents=True,exist_ok=True)
NAMES={'アヤト':'Аято','カナト':'Канато','ライト':'Райто','シュウ':'Шу','レイジ':'Рейджи','スバル':'Субару','ルキ':'Руки','コウ':'Коу','ユーマ':'Юма','アズサ':'Азуса','カールハインツ':'Карлхайнц','リヒター':'Рихтер','コーデリア':'Корделия','ベアトリクス':'Беатрикс','クリスタ':'Криста','エドガー':'Эдгар','ジャスティン':'Джастин','ヒルデ':'Хильда','ベーア':'Беа','ラインハルト':'Райнхард','ラインハルト？':'Райнхард?','ルクス':'Люкс','クリスティーナ':'Кристина','メリッサ':'Мелисса','セイジ':'Сейджи','テディ':'Тедди','みんな':'Все','ギャングのボス':'Главарь','ナンパ男':'Ловелас','メイド':'Горничная','世界史教師':'Учитель истории','伯爵':'Граф','先生':'Учитель','司会':'Ведущий','司教':'Епископ','商人の男':'Торговец','執事':'Дворецкий','女の子':'Девочка','女性の声':'Женский голос','子ども':'Ребёнок','将校':'Офицер','少年':'Мальчик','店主':'Хозяин магазина','教師':'Учитель','数学教師':'Учитель математики','施設長':'Директор приюта','映画':'Фильм','校内放送':'Объявление','母親':'Мать','記者':'Репортёр','警察官':'Полицейский','軍服を着た男':'Мужчина в форме','通行人':'Прохожий','運転手':'Водитель','一年女子':'Первокурсница','三年の教師':'Учитель 3-го года','#Name[2]':'#Name[2]','？？？':'???','男１':'Мужчина 1'}
for jp,ru in [('ギャング','Бандит'),('コウファン','Фанат Коу'),('仲間','Приятель'),('使用人','Слуга'),('女子生徒','Ученица'),('女性','Женщина'),('孤児院の子ども','Сирота'),('孤児院職員','Работник приюта'),('男子生徒','Ученик'),('男性','Мужчина'),('男','Мужчина'),('街の女性','Женщина на улице'),('街の男性','Мужчина на улице'),('貴族の女の子','Девочка-дворянка'),('貴族女性','Дворянка'),('貴族男性','Дворянин'),('酔った男','Пьяница'),('三年女子','Ученица 3-го г.'),('三年男子','Ученик 3-го г.'),('二年女子','Ученица 2-го г.')]:
 for suffix,letter in [('Ａ','А'),('Ｂ','Б'),('Ｃ','В')]:NAMES[jp+suffix]=ru+' '+letter
for n in '１２３':NAMES['メイド'+n]='Горничная '+str('１２３'.index(n)+1)
TAG=re.compile(r'#[A-Za-z0-9_]+\[[^\]]*\]');JP=re.compile(r'[\u3040-\u30ff\u3400-\u9fff]')
records=[];fixed={};groups=[];gid=0;opening={int(k):v for k,v in json.loads((ROOT/'translation/opening.json').read_text()).items()}
for file in sorted((ROOT/'build/extracted/resources/script').iterdir(),key=lambda p:int(p.name) if p.name.isdigit() else 999999):
 if not file.name.isdigit():continue
 b=file.read_bytes();ts=texts(b);byaction={t['action']:(i,t) for i,t in enumerate(ts)};pos=b.index(b'CODE_START_')+12;end=struct.unpack_from('<I',b,32)[0]-12;speaker='Рассказчик (мужчина)' if file.name=='101' else 'Юи (мысли, девушка)';group=[];page=0;prevtext=False
 while pos<end:
  local,op,count,size=struct.unpack_from('<IIII',b,pos)
  if pos in byaction:
   i,t=byaction[pos];s=t['text']
   if op==0xd4:
    speaker=NAMES.get(s,s)
    if s.strip() and s not in NAMES:raise ValueError(('unknown speaker',s))
   if not prevtext and group:groups.append(group);group=[];page+=1
   if s.strip():
    visible=TAG.sub('',s);budget=40
    # Reserve space for the player name, which is expanded by the game.
    budget-=8*len(re.findall(r'#Name\[[12]\]',s))
    r={'id':gid,'scene':file.name,'index':i,'action':pos,'opcode':hex(op),'speaker':speaker,'group':file.name+':'+str(page),'ja':s,'max_visible':max(16,budget),'target_visible':min(max(16,math.ceil(len(visible)*1.9)),max(16,budget))};records.append(r)
    if op==0xd4:fixed[str(gid)]=NAMES[s]
    elif file.name=='101' and i in opening:fixed[str(gid)]=opening[i]
    elif not JP.search(visible):fixed[str(gid)]=s
    else:group.append(r)
    gid+=1
   prevtext=True
  else:
   if group:groups.append(group);group=[];page+=1
   prevtext=False
  pos+=size
 if group:groups.append(group)
(OUT/'records.json').write_text(json.dumps(records,ensure_ascii=False))
(OUT/'fixed.json').write_text(json.dumps(fixed,ensure_ascii=False,indent=2))
print(json.dumps({'records':len(records),'fixed':len(fixed)}))
