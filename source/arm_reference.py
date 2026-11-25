"""Run the supplied build's unmodified ARM routines for extraction and verification."""
import struct
from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM, UC_HOOK_CODE, UC_MODE_THUMB, UC_PROT_NONE
from unicorn.arm_const import (UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_R0, UC_ARM_REG_R1,
                               UC_ARM_REG_R2, UC_ARM_REG_R3, UC_ARM_REG_SP)


class ArmReference:
    regs = (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3)
    stack, stop = 0xd00000, 0xe00000

    def __init__(self, stream):
        self.cpu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
        self.cpu.mem_map(0, 0x1000000)
        elf = ELFFile(stream)
        for seg in elf.iter_segments():
            if seg['p_type'] == 'PT_LOAD':
                self.cpu.mem_write(seg['p_vaddr'], seg.data())
        for section in elf.iter_sections():
            if section['sh_type'] != 'SHT_REL':
                continue
            symbols = elf.get_section(section['sh_link'])
            for rel in section.iter_relocations():
                symbol = symbols.get_symbol(rel['r_info_sym'])
                if symbol['st_shndx'] == 'SHN_UNDEF':
                    continue
                kind, addr = rel['r_info_type'], rel['r_offset']
                if kind in (21, 22):
                    self.put(addr, symbol['st_value'])
                elif kind == 2:
                    self.put(addr, self.word(addr) + symbol['st_value'])
        self.cpu.mem_protect(0, 4096, UC_PROT_NONE)
        self.heap = 0x800000
        self.blocks = {}
        self.free = {}
        for pc in (0x189b18, 0x18d2a4, 0x18d2ac, 0x7764c, 0x77850, 0x189af8, 0x18d294):
            self.hook(pc, self._memory)

    def hook(self, pc, callback):
        self.cpu.hook_add(UC_HOOK_CODE, callback, begin=pc, end=pc)

    def put(self, address, value):
        self.cpu.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def word(self, address):
        return struct.unpack('<I', self.cpu.mem_read(address, 4))[0]

    def _memory(self, cpu, pc, size, unused):
        a, b, n = (cpu.reg_read(r) for r in self.regs[:3])
        if pc == 0x7764c:
            cpu.mem_write(a, bytes(cpu.mem_read(b, n)))
        elif pc == 0x77850:
            cpu.mem_write(a, bytes([b & 255]) * n)
        elif pc in (0x189af8, 0x18d294):
            if a:
                self.free.setdefault(self.blocks.pop(a), []).append(a)
        else:
            size = max(8, (a + 7) & ~7)
            if self.free.get(size):
                address = self.free[size].pop()
            else:
                address = self.heap
                self.heap += size
                if self.heap >= 0xc00000:
                    raise MemoryError('ARM fixture heap exhausted')
            self.blocks[address] = size
            if pc == 0x189b18:
                cpu.mem_write(address, bytes(size))
            cpu.reg_write(self.regs[0], address)
        cpu.reg_write(UC_ARM_REG_PC, cpu.reg_read(UC_ARM_REG_LR))

    def call(self, address, *args, until=None):
        for r, value in zip(self.regs, args):
            self.cpu.reg_write(r, value & 0xffffffff)
        for i, value in enumerate(args[4:]):
            self.put(self.stack + 4*i, value)
        self.cpu.reg_write(UC_ARM_REG_SP, self.stack)
        self.cpu.reg_write(UC_ARM_REG_LR, self.stop+1)
        until = self.stop if until is None else until
        try:
            self.cpu.emu_start(address | 1, until, count=60000000)
            if self.cpu.reg_read(UC_ARM_REG_PC) != until:
                raise RuntimeError('instruction limit reached')
        except Exception as exc:
            raise RuntimeError(f'ARM {address:#x}, PC {self.cpu.reg_read(UC_ARM_REG_PC):#x}, '
                               f'LR {self.cpu.reg_read(UC_ARM_REG_LR):#x}') from exc
        return self.cpu.reg_read(self.regs[0])
