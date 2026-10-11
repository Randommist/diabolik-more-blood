"""Width check and word re-wrap of translated text runs (a run = records shown together in one text box, one record per line).
Width in font units as used by check_block: glyph width from font-0, '#Name[n]' reserves 88, other #tags are zero width.
Limit per run: max(340, widest original Japanese line) -- same rule as docs/QUALITY.md."""
import re,json,sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).parent))
from engine_layout import metrics,encoded_code
ROOT=Path(__file__).resolve().parents[1]
_font=None
TAG=re.compile(r'#[A-Za-z0-9_]+\[[^\]]*\]|#n')
def font():
    global _font
    if _font is None:_font=metrics(ROOT/'build/patched-crisp/font-0')
    return _font
def width(s):
    w=88*len(re.findall(r'#Name\[[12]\]',s));s=TAG.sub('',s)
    f=font()
    for ch in s:
        c=encoded_code(ch);w+=f[c][0] if c in f else 20
    return w
def limit(ja_lines):return max(340,max((width(j) for j in ja_lines),default=0))
def wrap(lines,lim,spare):
    """Greedy spill of trailing words into the next line; `spare` extra empty lines may be filled at the end. Returns (new_lines, ok)."""
    out=[];carry='';lines=list(lines)+['']*spare
    for k,l in enumerate(lines):
        t=(carry+l) if carry else l;carry=''
        while width(t)>lim:
            cut=t.rstrip().rfind(' ')
            if cut<=0:return None,False
            carry=t[cut+1:]+(' '+carry if carry else '') if False else t[cut+1:]+((' '+carry) if carry else '')
            t=t[:cut]
        out.append(t)
        if k==len(lines)-1 and carry:return None,False
    return out,True

def flow(lines,lim):
    """Re-flow all words of the run into lines no wider than lim. Returns list of lines or None if a single word is wider."""
    words=' '.join(l.strip('　 ') for l in lines).split(' ');out=[];cur=''
    for w in words:
        t=(cur+' '+w) if cur else w
        if width(t)<=lim:cur=t
        else:
            if not cur:return None
            out.append(cur);cur=w
            if width(cur)>lim:return None
    if cur:out.append(cur)
    return out

OTHER_TAG=re.compile(r'#(?!n\b|Name\[)[A-Za-z0-9_]+')
def apply(by_key,ru,verbose=True):
    """Return ru with over-wide runs re-flowed. Runs with other control tags or untranslated lines are left alone."""
    import collections
    ru=dict(ru);stat=collections.Counter();left=[]
    for scene in sorted({k[0] for k in by_key},key=int):
        d=json.loads((ROOT/'analysis/scenes'/f'{scene}.json').read_text())
        for run in d['text_runs']:
            idx=run['text_indices'];nb=[i for i in idx if i not in run['blank_indices']]
            recs=[by_key.get((scene,i)) for i in nb]
            if not nb or any(r is None for r in recs):continue
            if any(ru.get(r['id']) is None or ru[r['id']]==r['ja'] for r in recs):continue
            lines=[ru[r['id']] for r in recs];lim=limit([r['ja'] for r in recs])
            if all(width(l)<=lim for l in lines):continue
            stat['over']+=1
            if any(OTHER_TAG.search(l) or '#n' in l for l in lines):stat['skipped_tags']+=1;left.append((scene,nb,'tags'));continue
            n=len(nb);best=None
            for lm in (lim,max(lim,360)):
                L=flow(lines,lm)
                if L is None:break
                if len(L)<=max(n,3):best=L;break
                best=best or L
            if best is None:stat['word_too_wide']+=1;left.append((scene,nb,'word'));continue
            if len(best)>max(n,3):stat['over_3_lines']+=1
            if len(best)<=n:new=best+['　']*(n-len(best))
            else:new=best[:n-1]+['#n'.join(best[n-1:])]
            for r,t in zip(recs,new):ru[r['id']]=t
            stat['reflowed']+=1
    if verbose:print('reflow:',dict(stat))
    return ru,left
