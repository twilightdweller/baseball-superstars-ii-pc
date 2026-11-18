"""Inspect original ELF Thumb symbols using the installed Windows dumpbin.

Wraps unmodified function bytes in a temporary ARMNT COFF section whose virtual
address matches the ELF. Does not execute, patch, or rebuild original code.
Literal pools may appear as instructions: use ELF bytes to resolve those words.
Usage: python source/tools/inspect_arm_windows.py build/libgameDSO.so SYMBOL...
"""
import argparse
import os
from pathlib import Path
import struct
import subprocess
import tempfile
from elftools.elf.elffile import ELFFile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('elf', type=Path)
    parser.add_argument('symbols', nargs='+')
    parser.add_argument('--output', type=Path, default=Path('build/arm-inspection'))
    args = parser.parse_args()
    vswhere = Path(os.environ.get('ProgramFiles(x86)', r'C:\Program Files (x86)')) / 'Microsoft Visual Studio/Installer/vswhere.exe'
    root = subprocess.check_output([str(vswhere), '-latest', '-products', '*', '-requires',
                                    'Microsoft.VisualStudio.Component.VC.Tools.x86.x64',
                                    '-property', 'installationPath'], text=True).strip()
    versions = Path(root) / 'VC/Tools/MSVC'
    candidates = sorted(versions.glob('*/bin/Hostx64/x64/dumpbin.exe'),
                        key=lambda p: tuple(map(int, p.parents[3].name.split('.'))))
    if not candidates:
        raise SystemExit('MSVC dumpbin not found.')
    args.output.mkdir(parents=True, exist_ok=True)
    with args.elf.open('rb') as stream:
        elf = ELFFile(stream)
        symbols = {s.name: s for s in elf.get_section_by_name('.dynsym').iter_symbols()}
        targets = {}
        for symbol in symbols.values():
            if symbol['st_info']['type'] == 'STT_FUNC' and symbol['st_shndx'] != 'SHN_UNDEF':
                targets.setdefault(symbol['st_value'] & ~1, []).append(symbol.name)
        for name in args.symbols:
            symbol = symbols[name]
            if symbol['st_info']['type'] != 'STT_FUNC' or not symbol['st_value'] & 1:
                raise ValueError('Expected a defined Thumb function: ' + name)
            address, size = symbol['st_value'] & ~1, symbol['st_size']
            segment = next(p for p in elf.iter_segments() if p['p_type'] == 'PT_LOAD'
                           and p['p_vaddr'] <= address < address + size <= p['p_vaddr'] + p['p_filesz'])
            offset = address - segment['p_vaddr']
            code = segment.data()[offset:offset + size]
            header = struct.pack('<HHIIIHH', 0x1c4, 1, 0, 0, 0, 0, 0)
            section = struct.pack('<8sIIIIIIHHI', b'.text', 0, address, size, 60, 0, 0, 0, 0, 0x60000020)
            with tempfile.TemporaryDirectory() as temporary:
                obj = Path(temporary) / 'function.obj'
                obj.write_bytes(header + section + code)
                output = subprocess.check_output([str(candidates[-1]), '/disasm:bytes', str(obj)], text=True)
            for target, names in targets.items():
                token = f'bl          {target:08X}'
                output = output.replace(token, token + ' ; ' + ' / '.join(names))
            destination = args.output / f'{address:08x}.txt'
            destination.write_text(name + '\n' + output, encoding='utf-8')
            print(destination)


if __name__ == '__main__':
    main()
