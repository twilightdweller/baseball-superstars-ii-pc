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

class Point2(ctypes.Structure):_fields_=[('x',ctypes.c_int32),('y',ctypes.c_int32)]
class Projection(ctypes.Structure):_fields_=[('matrix',ctypes.c_int32*16),('origin_x',ctypes.c_int32),('origin_y',ctypes.c_int32),('scale_x',ctypes.c_int32),('scale_y',ctypes.c_int32)]
n=ctypes.CDLL(sys.argv[2]);n.bs2_project_point.argtypes=[ctypes.POINTER(Point2),ctypes.POINTER(Point),ctypes.POINTER(Projection)]
n.bs2_matrix_point.argtypes=[ctypes.POINTER(Point),ctypes.POINTER(Point),ctypes.POINTER(ctypes.c_int32)]
rng=random.Random(73)
for case in range(1200):
 scale=262144 if case<400 else 2147483647
 m=[rng.randrange(-scale,scale+1) for _ in range(16)]
 if case%4==0:m[3]=m[7]=m[11]=m[15]=0 # zero homogeneous divisor
 if case%4==1:m[2]=m[6]=m[10]=m[14]=0 # zero projection depth
 if case%4==2:m=[262144 if i%5==0 else 0 for i in range(16)]
 p=Point(*(rng.randrange(-scale,scale+1) for _ in range(3)))
 camera=Projection((ctypes.c_int32*16)(*m),*(rng.randrange(-scale,scale+1) for _ in range(4)))
 obj=bytearray(256);struct.pack_into('<16i',obj,0x84,*m)
 struct.pack_into('<ii',obj,0xc4,camera.origin_x,camera.origin_y)
 struct.pack_into('<ii',obj,0xd4,camera.scale_x,camera.scale_y)
 for address,size,kind in [(0xb9b51,12,'matrix'),(0xb34f9,8,'projection')]:
  out=Point() if kind=='matrix' else Point2()
  if kind=='matrix':n.bs2_matrix_point(ctypes.byref(out),ctypes.byref(p),camera.matrix)
  else:n.bs2_project_point(ctypes.byref(out),ctypes.byref(p),ctypes.byref(camera))
  u.mem_write(0x800000,bytes(obj));u.mem_write(0x840000,bytes(p));u.mem_write(0x850000,b'\xa5'*32)
  args=(0x850000,0x840000,0x800084) if kind=='matrix' else (0x800000,0x850000,0x840000)
  for reg,val in zip([UC_ARM_REG_R0,UC_ARM_REG_R1,UC_ARM_REG_R2],args):u.reg_write(reg,val)
  u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
  u.emu_start(address,0xa00000,count=100000)
  assert u.reg_read(UC_ARM_REG_PC)==0xa00000,('return',case,kind)
  actual=bytes(u.mem_read(0x850000,size))
  assert actual==bytes(out),('mismatch',case,kind,actual.hex(),bytes(out).hex())
  assert bytes(u.mem_read(0x850000+size,16))==b'\xa5'*16
  assert bytes(u.mem_read(0x840000,12))==bytes(p)
  assert bytes(u.mem_read(0x800000,256))==bytes(obj)
 # Exercise native in-place matrix contract independently of ARM output allocation.
 expected=Point();n.bs2_matrix_point(ctypes.byref(expected),ctypes.byref(p),camera.matrix)
 n.bs2_matrix_point(ctypes.byref(p),ctypes.byref(p),camera.matrix)
 assert bytes(p)==bytes(expected)
print('PASS: 1,200 matrix transforms and 1,200 screen projections match original ARM exactly, including zero divisors and full signed-32-bit input range; guards and unchanged inputs passed. Native in-place transforms passed.')

class Transform(ctypes.Structure):_fields_=[('scale',ctypes.c_int32*3),('rotation',ctypes.c_int32*3),('translation',ctypes.c_int32*3),('matrix',ctypes.c_int32*16)]
n.bs2_matrix_update.argtypes=[ctypes.POINTER(Transform)]
for case in range(1200):
 vals=[rng.randrange(-2147483648,2147483648) for _ in range(25)]
 if case<20:vals[3:6]=[case*90*262144-720*262144]*3
 t=Transform.from_buffer_copy(struct.pack('<25i',*vals))
 u.mem_write(0x800000,bytes(t)+b'\xa5'*16)
 n.bs2_matrix_update(ctypes.byref(t))
 u.reg_write(UC_ARM_REG_R0,0x800000);u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
 u.emu_start(0xbad69,0xa00000,count=100000)
 assert u.reg_read(UC_ARM_REG_PC)==0xa00000,('matrix update return',case)
 actual=bytes(u.mem_read(0x800000,100))
 assert actual==bytes(t),('matrix update mismatch',case,[(i,a,b) for i,(a,b) in enumerate(zip(actual,bytes(t))) if a!=b])
 assert bytes(u.mem_read(0x800064,16))==b'\xa5'*16
print('PASS: 1,200 scale/rotation/translation matrix updates match original object writes exactly, including preserved matrix slot and output guard.')
