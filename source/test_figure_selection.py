import sys,ctypes,struct,random
from elftools.elf.elffile import ELFFile
from unicorn import Uc,UC_ARCH_ARM,UC_MODE_THUMB,UC_HOOK_CODE
from unicorn.arm_const import *
u=Uc(UC_ARCH_ARM,UC_MODE_THUMB);u.mem_map(0,0x1000000)
with open(sys.argv[1],'rb') as f:
 e=ELFFile(f)
 for p in e.iter_segments():
  if p['p_type']=='PT_LOAD':u.mem_write(p['p_vaddr'],p.data())
 for sec in e.iter_sections():
  if sec['sh_type']!='SHT_REL':continue
  syms=e.get_section(sec['sh_link'])
  for rel in sec.iter_relocations():
   t=rel['r_info_type'];a=rel['r_offset'];s=syms.get_symbol(rel['r_info_sym'])
   if s['st_shndx']=='SHN_UNDEF':continue
   if t in [21,22]:u.mem_write(a,struct.pack('<I',s['st_value']))
   if t==2:
    old=struct.unpack('<I',u.mem_read(a,4))[0];u.mem_write(a,struct.pack('<I',(old+s['st_value'])&0xffffffff))


# Stop at FigureMgr::Load to observe the filename actually supplied by CLx::Startup.
# Supply an existing singleton so this focused trace does not allocate the manager.
u.mem_write(0x1f9cf4,struct.pack('<I',0x600000));observed=[]
def hook(u,a,size,data):
 if a==0x962c8:
  pointer=u.reg_read(UC_ARM_REG_R1)
  observed.append(bytes(u.mem_read(pointer,128)).split(b'\0')[0].decode())
  u.emu_stop()
u.hook_add(UC_HOOK_CODE,hook)
u.mem_write(0x800000,b'data/stadium.fig\0')
u.reg_write(UC_ARM_REG_R0,0x800000);u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
u.emu_start(0xbdc9d,0xa00000,count=10000)
assert observed==['data/bb2011_480x320.fig'],observed
assert u.reg_read(UC_ARM_REG_PC)==0x962c8
print('PASS: original CLx::Startup requests data/bb2011_480x320.fig from FigureMgr::Load, overriding the supplied data/stadium.fig argument.')
