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

# Original ARM is executed only in the developer test, never in the native port.
class Point(ctypes.Structure):
 _fields_=[('x',ctypes.c_int32),('y',ctypes.c_int32),('z',ctypes.c_int32)]

import json
from pathlib import Path
n=ctypes.CDLL(sys.argv[2]);n.bs2_pitch_cardinal.argtypes=[ctypes.POINTER(Point),ctypes.c_int,ctypes.POINTER(Point),ctypes.c_int]
heap=0;allocs={}
def hook(u,a,size,data):
 global heap
 if a==0x18d2a4:
  size=u.reg_read(UC_ARM_REG_R0);assert 0<size<=200
  ptr=heap;heap+=(size+7)&~7;assert heap<0x780000
  allocs[ptr]=size;u.mem_write(ptr,b'\xcc'*size)
  u.reg_write(UC_ARM_REG_R0,ptr);u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
 elif a==0x18d294:
  ptr=u.reg_read(UC_ARM_REG_R0);assert ptr in allocs;del allocs[ptr]
  u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
u.hook_add(UC_HOOK_CODE,hook)
def compare(points,frames,label):
 global heap
 heap=0x700000;allocs.clear();count=len(points)
 out=(Point*frames)();ctypes.memset(out,0xa5,ctypes.sizeof(out))
 assert n.bs2_pitch_cardinal(points,count,out,frames)==0
 u.mem_write(0x800000,bytes(24));u.mem_write(0x840000,bytes(points))
 u.mem_write(0x850000,b'\xa5'*(frames*12+16));u.mem_write(0x900000,struct.pack('<I',0x850000))
 for reg,val in [(UC_ARM_REG_R0,0x800000),(UC_ARM_REG_R1,count),(UC_ARM_REG_R2,0x840000),(UC_ARM_REG_R3,frames),(UC_ARM_REG_SP,0x900000),(UC_ARM_REG_LR,0xa00001)]:u.reg_write(reg,val)
 u.emu_start(0xb2241,0xa00000,count=10000000)
 assert u.reg_read(UC_ARM_REG_PC)==0xa00000,('no return',label)
 actual=bytes(u.mem_read(0x850000,frames*12))
 assert actual==bytes(out),('mismatch',label,next((i,a,b) for i,(a,b) in enumerate(zip(actual,bytes(out))) if a!=b))
 assert not allocs,('leaked allocation',label)
 assert bytes(u.mem_read(0x850000+frames*12,16))==b'\xa5'*16
 assert bytes(u.mem_read(0x840000,count*12))==bytes(points)
 return frames
records=json.loads(Path(__file__).with_name('pitch-records.json').read_text());cases=vertices=0
for r in records:
 if r['spline_kind']!=1:continue
 points=(Point*len(r['points']))(*[Point(*p) for p in r['points']])
 vertices+=compare(points,r['base_frames'],('asset',r['group'],r['variant']));cases+=1
print(f'PASS: {cases} original Cardinal records, {vertices} vertices match original ARM exactly.')
rng=random.Random(7);cases=vertices=0
for count in [2,3,4,8,42,50]:
 for frames in [2,3,17,60,120]:
  for scale in [262144,1000000000,2147483647]:
   points=(Point*count)(*[Point(*(rng.randrange(-scale,scale+1) for _ in range(3))) for _ in range(count)])
   vertices+=compare(points,frames,(count,frames,scale));cases+=1
print(f'PASS: {cases} synthetic Cardinal cases, {vertices} vertices; unchanged input, output guards, and allocator lifecycle checked.')
p=(Point*2)();out=(Point*2)();before=bytes(out)
for count,frames in [(0,2),(1,2),(51,2),(2,1),(2,4097)]:
 assert n.bs2_pitch_cardinal(p,count,out,frames)==-1 and bytes(out)==before
print('PASS: invalid Cardinal sizes rejected without output writes.')
