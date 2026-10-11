"""Inspect STCM control flow and the decrypted ELF without changing game resources.

Requires pyelftools/capstone in the project venv. Unknown opcodes stay unknown.
Local output includes original Japanese; do not publish the extracted corpus.
"""
import argparse, collections, hashlib, json, struct
from pathlib import Path
from stcm import texts
from engine_layout import CONFIG_ROWS, resource_configuration

ROOT = Path(__file__).resolve().parents[1]

def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def instructions(data):
    pos = data.index(b'CODE_START_') + 12
    end = struct.unpack_from('<I', data, 32)[0] - 12
    rows = []
    while pos < end:
        local, opcode, count, size = struct.unpack_from('<4I', data, pos)
        if size < 16 + count * 12 or pos + size > end:
            raise ValueError(f'Invalid instruction at {pos:#x}')
        rows.append(dict(address=pos, local=bool(local), opcode=opcode,
                         size=size, parameters=[list(struct.unpack_from('<3I', data, pos+16+i*12)) for i in range(count)]))
        pos += size
    assert pos == end
    return rows

def scene(path):
    data = path.read_bytes()
    rows = instructions(data)
    by_address = {r['address']: r for r in rows}
    extracted = texts(data)
    for index, text in enumerate(extracted):
        by_address[text['action']].update(text_index=index, japanese=text['text'], text_capacity_bytes=text['capacity'])
    export_start, link = struct.unpack_from('<I', data, 32)[0], struct.unpack_from('<I', data, 44)[0]
    exports = []
    for p in range(export_start, link-16, 40):
        name = data[p+4:p+36].split(b'\0')[0].decode('cp932')
        target = struct.unpack_from('<I', data, p+36)[0]
        assert target in by_address
        exports.append(dict(name=name, address=target))
    exports_by_address = collections.defaultdict(list)
    for e in exports: exports_by_address[e['address']].append(e['name'])
    edges, pages, current = [], [], []
    speaker, region = '', []
    for i, row in enumerate(rows):
        address, opcode = row['address'], row['opcode']
        if address in exports_by_address:
            region = exports_by_address[address]
        row['storage_region_exports'] = region
        # This is lexical state only; branches and calls can change runtime state.
        if not row['local'] and opcode == 0xd4:
            speaker = row.get('japanese', '')
        row['lexical_speaker'] = speaker
        if row['local']:
            if opcode not in by_address: raise ValueError(f'Unknown local target {opcode:#x}')
            edges.append(dict(source=address, target=opcode, kind='local_call', target_exports=exports_by_address.get(opcode, [])))
        for param in row['parameters']:
            if param[0] == 0xffffff41:
                if param[1] not in by_address: raise ValueError(f'Invalid code reference {param[1]:#x}')
                edges.append(dict(source=address, target=param[1], kind='code_reference; conditional semantics unresolved'))
        if not row['local'] and opcode == 0xd2:
            current.append(row)
        elif current:
            pages.append(dict(run=len(pages), start=current[0]['address'], end=current[-1]['address'],
                              next_command_address=address, next_opcode=hex(opcode),
                              boundary='text run; 0xd3 is a synchronization candidate' if opcode==0xd3 else 'intervening command; may not clear the display',
                              storage_region_exports=current[0]['storage_region_exports'],
                              text_indices=[r['text_index'] for r in current],
                              blank_indices=[r['text_index'] for r in current if not r['japanese'].strip()],
                              lexical_speakers=sorted({r['lexical_speaker'] for r in current})))
            current = []
    if current: raise ValueError('Unterminated text run: investigate before assigning a page')
    return dict(scene=path.name, source_sha256=digest(path), exports=exports, control_references=edges,
                text_runs=pages, instructions=rows,
                warning='Storage order and lexical speaker are not an executed playthrough. Text runs are not proven screen pages.')

def elf_analysis(path, output):
    from elftools.elf.elffile import ELFFile
    from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS32, CS_MODE_LITTLE_ENDIAN
    with path.open('rb') as f:
        elf = ELFFile(f)
        segments=[dict(s.header) for s in elf.iter_segments()]
        executable=[s for s in elf.iter_sections() if s['sh_flags'] & 4 and s['sh_type']=='SHT_PROGBITS']
        md=Cs(CS_ARCH_MIPS, CS_MODE_MIPS32 | CS_MODE_LITTLE_ENDIAN); md.skipdata=True
        with (output/'eboot.disassembly.txt').open('w') as out:
            for section in executable:
                for ins in md.disasm(section.data(), section['sh_addr']):
                    out.write(f'{ins.address:08x} {ins.mnemonic} {ins.op_str}\n')
        def read(address, length):
            for s in elf.iter_segments():
                if s['p_type']=='PT_LOAD' and s['p_vaddr']<=address and address+length<=s['p_vaddr']+s['p_filesz']:
                    f.seek(s['p_offset']+address-s['p_vaddr']); return f.read(length)
            raise ValueError(f'Address not in file-backed segment: {address:#x}')
        # Reverse engineered configurations; assertions tie evidence to this binary.
        configs={}
        for address in [0x31f274,0x31f2a8]:
            values=list(struct.unpack('<13I',read(address,52)))
            assert values[3]==2 and values[12]==17
            configs[hex(address)]=dict(raw_words=values, advance_mode=values[3], horizontal_spacing_font_units=values[4], vertical_spacing_font_units=values[5],
                                      requested_font_height=values[12], status='static default; scripts/settings may override')
        fonts={}
        for name in ['0','100']:
            b=(ROOT/'build/extracted/resources/font'/name).read_bytes()
            if len(b)<0x434:
                fonts[name]=dict(bytes=len(b),status='renderer settings loaded by 0x58004 / converted by 0x57f78',configurations={k:resource_configuration(k) for k in CONFIG_ROWS});continue
            table,data=struct.unpack_from('<II',b,24)
            widths={};heights=collections.Counter()
            for p in range(0x428,table,12):
                a,z,index=struct.unpack_from('<III',b,p)
                for code in range(a,z):
                    w,h=struct.unpack_from('<BB',b,table+(index+code-a)*8);widths[code]=w;heights[h]+=1
            fonts[name]=dict(height_histogram=dict(heights),sample_widths={ch:widths.get(int.from_bytes(ch.encode('cp932'),'big')) for ch in ['あ','漢','A',' ','…']})
        return dict(source_sha256=digest(path), architecture='MIPS32 little endian PSP PRX', segments=segments,
                    address_note='Module-relative addresses. PRX relocations are not applied; BSS references require their segment base. Allegrex-only instructions may appear as .byte.',
                    configurations=configs, fonts=fonts,
                    evidence={
                        '0x25854-0x25864':'name_win receives configuration 0x31f2a8',
                        '0x26f1c-0x26f24':'main_win receives configuration 0x31f274',
                        '0x5b770-0x5b78c':'scale = requested font height / font base height unless fixed-scale flag is set',
                        '0x5c658-0x5c6c4':'proportional horizontal advance uses glyph width plus spacing, multiplied by scale',
                        '0x5bca8-0x5bcb8':'#n invokes line completion',
                        '0x5b154-0x5b1dc':'next horizontal line resets x and advances y using font height and vertical spacing',
                        '0x3611c-0x3613c':'default window geometry has center 240,136 and dimensions 480,272; this is not proof of text-safe margins'},
                    hard_text_width_pixels=None,
                    warning='Static ELF defaults differ from active font/100 settings. layout-runtime-proof.json and dialogue-runtime-proof.json validate coordinates for captured horizontal novel/dialogue windows. Other scenes need their actual window origin, mode and tag expansion; no global width limit.')

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--scene',default=None);args=parser.parse_args()
    out=ROOT/'analysis';out.mkdir(exist_ok=True);(out/'scenes').mkdir(exist_ok=True)
    files=sorted(p for p in (ROOT/'build/extracted/resources/script').iterdir() if p.name.isdigit() and (args.scene is None or p.name==args.scene))
    summary=[]
    for path in files:
        result=scene(path);(out/'scenes'/f'{path.name}.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
        summary.append(dict(scene=path.name,instructions=len(result['instructions']),exports=len(result['exports']),text_runs=len(result['text_runs']),blank_text_slots=sum(len(p['blank_indices']) for p in result['text_runs']),control_references=len(result['control_references'])))
    layout=elf_analysis(out/'EBOOT.decrypted.bin',out)
    (out/'font-layout.json').write_text(json.dumps(layout,ensure_ascii=False,indent=2)+'\n')
    (out/'scene-inventory.json').write_text(json.dumps(summary,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(dict(scenes=len(summary),instructions=sum(s['instructions'] for s in summary),text_runs=sum(s['text_runs'] for s in summary),blank_text_slots=sum(s['blank_text_slots'] for s in summary),font_layout=layout['configurations']),ensure_ascii=False))

if __name__=='__main__': main()
