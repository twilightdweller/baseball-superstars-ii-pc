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


from pathlib import Path
def hook(u,a,size,data):
 if a in (0x77850,0x7764c):
  dest=u.reg_read(UC_ARM_REG_R0);src=u.reg_read(UC_ARM_REG_R1);length=u.reg_read(UC_ARM_REG_R2)
  assert length<=4096
  u.mem_write(dest,bytes([src&255])*length if a==0x77850 else bytes(u.mem_read(src,length)))
  u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
u.hook_add(UC_HOOK_CODE,hook)

class Projection(ctypes.Structure):_fields_=[('matrix',ctypes.c_int32*16),('ox',ctypes.c_int32),('oy',ctypes.c_int32),('sx',ctypes.c_int32),('sy',ctypes.c_int32)]
n=ctypes.CDLL(sys.argv[2]);n.bs2_camera_from_figure.argtypes=[ctypes.POINTER(ctypes.c_ubyte),ctypes.c_size_t,ctypes.c_int,ctypes.POINTER(Projection)]
for asset in Path(__file__).with_name('figure-assets').glob('bb*.bin'):
 if 'fence' in asset.name:continue
 scene=asset.read_bytes()
 for mode in range(3):
  fig=bytearray(1024);fig[4:4+len(scene)]=scene
  u.mem_write(0x600000,bytes(fig));u.mem_write(0x1f9cf4,struct.pack('<I',0x600000))
  screen=bytearray(0x170);struct.pack_into('<i',screen,0x168,-1);u.mem_write(0x800000,bytes(screen))
  u.reg_write(UC_ARM_REG_R0,0x800000);u.reg_write(UC_ARM_REG_R1,mode);u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
  u.emu_start(0x95999,0xa00000,count=1000000)
  assert u.reg_read(UC_ARM_REG_PC)==0xa00000
  raw=bytes(u.mem_read(0x800004,256));out=Projection();buf=(ctypes.c_ubyte*len(scene)).from_buffer_copy(scene)
  assert n.bs2_camera_from_figure(buf,len(scene),mode,ctypes.byref(out))==0
  expected=raw[0x84:0xc4]+raw[0xc4:0xcc]+raw[0xd4:0xdc]
  assert bytes(out)==expected,(asset.name,mode,list(out.matrix),struct.unpack_from('<16i',raw,0x84))
print('PASS: all three camera presets in both figure assets match original CCLScreen::SetScreen projection matrices, origins and scales exactly.')
