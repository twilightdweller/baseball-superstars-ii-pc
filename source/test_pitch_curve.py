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
n=ctypes.CDLL(sys.argv[2]);n.bs2_pitch_bezier.argtypes=[ctypes.POINTER(Point),ctypes.c_int,ctypes.POINTER(Point),ctypes.c_int,ctypes.c_int,ctypes.c_int]

def compare(points,frames,mode,phase,label):
 count=len(points);out=(Point*frames)()
 assert n.bs2_pitch_bezier(points,count,out,frames,mode,phase)==0
 obj=struct.pack('<6I',count,0x810000,0x820000,0x830000,mode,phase)
 u.mem_write(0x800000,obj);u.mem_write(0x840000,bytes(points))
 u.mem_write(0x850000,b'\xa5'*(frames*12+16));u.mem_write(0x900000,struct.pack('<I',0x850000))
 for reg,val in [(UC_ARM_REG_R0,0x800000),(UC_ARM_REG_R1,count),(UC_ARM_REG_R2,0x840000),(UC_ARM_REG_R3,frames),(UC_ARM_REG_SP,0x900000),(UC_ARM_REG_LR,0xa00001)]:u.reg_write(reg,val)
 u.emu_start(0xb2601,0xa00000,count=20000000)
 assert u.reg_read(UC_ARM_REG_PC)==0xa00000,('no return',label,hex(u.reg_read(UC_ARM_REG_PC)))
 actual=bytes(u.mem_read(0x850000,frames*12))
 assert actual==bytes(out),('mismatch',label,next((i,a,b) for i,(a,b) in enumerate(zip(actual,bytes(out))) if a!=b))
 assert bytes(u.mem_read(0x850000+frames*12,16))==b'\xa5'*16
 assert bytes(u.mem_read(0x840000,count*12))==bytes(points)
 return frames
rng=random.Random(20261026)
cases=0;vertices=0
for count in [1,2,3,4,8,16,50]:
 for frames in [2,3,17,60]:
  for mode in range(5):
   for phase in [0,17,90]:
    points=(Point*count)(*[Point(*(rng.randrange(-1000000000,1000000001) for _ in range(3))) for _ in range(count)])
    vertices+=compare(points,frames,mode,phase,(count,frames,mode,phase));cases+=1
print(f'PASS: {cases} synthetic Bezier cases, {vertices} 3D vertices match original ARM exactly; all five modes, endpoint phases, and 1–50 control points.')
import json
from pathlib import Path
records=json.loads(Path(__file__).with_name('pitch-records.json').read_text())
real_cases=0;real_vertices=0
for record in records:
 if record['spline_kind']!=0:continue
 points=(Point*len(record['points']))(*[Point(*p) for p in record['points']])
 real_vertices+=compare(points,record['base_frames'],0,0,(record['group'],record['variant']))
 real_cases+=1
print(f'PASS: all {real_cases} extracted Bezier curve records, {real_vertices} 3D vertices match original ARM before world-space transformation; input and output guards passed.')
# New API rejects dangerous sizes rather than replicating original out-of-bounds behavior.
p=(Point*1)(Point(1,2,3));o=(Point*2)(Point(11,12,13),Point(14,15,16));before=bytes(o)
for args in [(0,2,0,0),(51,2,0,0),(1,1,0,0),(1,4097,0,0),(1,2,5,0),(1,2,0,-1),(1,2,0,91)]:
 assert n.bs2_pitch_bezier(p,args[0],o,*args[1:])==-1
 assert bytes(o)==before
print('PASS: unsupported arguments rejected without output writes.')
