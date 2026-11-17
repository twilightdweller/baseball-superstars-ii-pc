from native_test_library import load
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
now=0
calls=[]
def hook(u,a,size,data):
 if a==0x17daa0:
  calls.append('resource');u.reg_write(UC_ARM_REG_R0,0);u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
 if a==0x8f590:
  calls.append('time');u.reg_write(UC_ARM_REG_R0,now&0xffffffff);u.reg_write(UC_ARM_REG_R1,now>>32);u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
u.hook_add(UC_HOOK_CODE,hook)
n=load('bs2-title-flow');n.bs2_title_tick.argtypes=[ctypes.c_void_p,ctypes.c_uint64]
count=0
for state in [0,100]:
 for auto in [0,1]:
  for start in [0,123456,0xfffffffe,0x100000001]:
   for delta in [-1,0,2999,3000,3001,100000]:
    now=(start+delta)&((1<<64)-1)
    obj=bytearray(512);struct.pack_into('<I',obj,8,state);struct.pack_into('<Q',obj,0x118,start);obj[0x15c]=auto
    native=(ctypes.c_uint8*len(obj)).from_buffer_copy(obj)
    assert n.bs2_title_tick(native,now)==0
    u.mem_write(0x800000,bytes(obj));u.reg_write(UC_ARM_REG_R0,0x800000);u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
    calls.clear();u.emu_start(0x159af9,0xa00000,count=10000)
    assert u.reg_read(UC_ARM_REG_PC)==0xa00000
    actual=bytes(u.mem_read(0x800000,len(obj)))
    assert actual==bytes(native),(state,auto,start,delta,[(i,a,b) for i,(a,b) in enumerate(zip(actual,bytes(native))) if a!=b])
    assert calls==['resource','time']
    count+=1
print(f'PASS: {count} automatic title-state cases match original object writes, including 3-second boundary and 64-bit time rollover.')
