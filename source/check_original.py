from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_THUMB
from unicorn.arm_const import UC_ARM_REG_R0,UC_ARM_REG_R1,UC_ARM_REG_SP,UC_ARM_REG_LR
import sys
with open(sys.argv[1],'rb') as f:
 e=ELFFile(f);u=Uc(UC_ARCH_ARM,UC_MODE_THUMB)
 u.mem_map(0,0x1000000)
 for p in e.iter_segments():
  if p['p_type']=='PT_LOAD':u.mem_write(p['p_vaddr'],p.data())
 names={s.name:s['st_value'] for s in e.get_section_by_name('.dynsym').iter_symbols()}
 def call(name,arg=0):
  u.reg_write(UC_ARM_REG_R0,0x800000);u.reg_write(UC_ARM_REG_R1,arg&0xffffffff)
  u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
  u.emu_start(names[name],0xa00000,count=10000)
  return u.reg_read(UC_ARM_REG_R0)
 for initial,delta,expected in [(0,100,100),(100,-40,60),(10,-20,0),(999990,20,999999)]:
  call('_ZN10CBBGOption9SetGPointEj',initial)
  assert call('_ZN10CBBGOption9GetGPointEv')==initial
  call('_ZN10CBBGOption9AddGPointEi',delta)
  actual=call('_ZN10CBBGOption9GetGPointEv')
  assert actual==expected,(actual,expected)
  print(f'PASS: {initial} + ({delta}) -> {actual}')
print('Original ARM currency routines passed isolated tests. This is a development test, not a playable port.')
