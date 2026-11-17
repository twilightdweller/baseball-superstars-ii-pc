import sys,zipfile,struct
from elftools.elf.elffile import ELFFile
from unicorn import Uc,UC_ARCH_ARM,UC_MODE_THUMB
from unicorn.arm_const import *
from extract_title import frames,render
u=Uc(UC_ARCH_ARM,UC_MODE_THUMB);u.mem_map(0,0x1000000)
with open(sys.argv[1],'rb') as f:
 e=ELFFile(f)
 for p in e.iter_segments():
  if p['p_type']=='PT_LOAD':u.mem_write(p['p_vaddr'],p.data())
count=0
with zipfile.ZipFile(sys.argv[2]) as z:
 for name in ['assets/ui/title.pzx','assets/mainui/main_title.pzx']:
  for idx,w,h,pal,payload in frames(z.read(name)):
   expected=render(w,h,pal,payload)
   u.mem_write(0x400000,b'\0'*(w*h*2));u.mem_write(0x500000,payload);u.mem_write(0x600000,pal)
   for reg,val in [(UC_ARM_REG_R0,0x400000),(UC_ARM_REG_R1,0x500000),(UC_ARM_REG_R2,0x600000),(UC_ARM_REG_R3,0),(UC_ARM_REG_SP,0x900000),(UC_ARM_REG_LR,0xa00001)]:u.reg_write(reg,val)
   u.emu_start(0x1aaa79,0xa00000,count=20000000)
   assert u.reg_read(UC_ARM_REG_PC)==0xa00000,'Original routine did not finish'
   actual=bytes(u.mem_read(0x400000,w*h*2))
   assert actual==expected,(name,idx)
   count+=1
print(f'PASS: {count} frames match original ARM drawing routine byte for byte.')
