import ctypes,struct,random,sys
from elftools.elf.elffile import ELFFile
from unicorn import Uc,UC_ARCH_ARM,UC_MODE_THUMB
from unicorn.arm_const import *
u=Uc(UC_ARCH_ARM,UC_MODE_THUMB);u.mem_map(0,0x1000000)
with open(sys.argv[1],'rb') as f:
 e=ELFFile(f)
 for p in e.iter_segments():
  if p['p_type']=='PT_LOAD':u.mem_write(p['p_vaddr'],p.data())
n=ctypes.CDLL('/tmp/bs2-state.so')
r=random.Random(42)
funcs=[('bs2_state_init',0xd1441),('bs2_state_reserve',0xd1639),('bs2_state_cancel',0xd1645),('bs2_state_check',0xd1461)]
for name,addr in funcs:
 fn=getattr(n,name);fn.argtypes=[ctypes.c_void_p,ctypes.c_uint32]
 for i in range(500):
  obj=bytearray(r.randbytes(80));arg=r.randrange(256)
  if name=='bs2_state_check':
   struct.pack_into('<I',obj,4,6);struct.pack_into('<I',obj,8,6 if i%2 else 7);obj[26]=i%3==0
   struct.pack_into('<I',obj,20,[0,99999998,99999999,100000000,0x7fffffff,0xffffffff][i%6])
  native=(ctypes.c_uint8*80).from_buffer_copy(obj);result=fn(native,arg)
  u.mem_write(0x800000,bytes(obj));u.reg_write(UC_ARM_REG_R0,0x800000);u.reg_write(UC_ARM_REG_R1,arg);u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
  u.emu_start(addr,0xa00000,count=1000)
  assert u.reg_read(UC_ARM_REG_PC)==0xa00000
  assert bytes(native)==bytes(u.mem_read(0x800000,80)),(name,i)
  if name in ['bs2_state_check','bs2_state_cancel']:assert result==u.reg_read(UC_ARM_REG_R0)
print('PASS: 2,000 state-machine cases match original object writes and defined return values.')
