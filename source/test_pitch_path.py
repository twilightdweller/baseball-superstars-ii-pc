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
heap=0;allocs={};real_scene=False
from collections import deque
trace=deque(maxlen=30)
def hook(u,a,size,data):
 global heap
 trace.append(a)
 if a<0x70000:raise RuntimeError("unexpected external branch")
 if a in (0x77850,0x7764c):
  dest=u.reg_read(UC_ARM_REG_R0);source=u.reg_read(UC_ARM_REG_R1);length=u.reg_read(UC_ARM_REG_R2)
  assert length<=4096
  u.mem_write(dest,bytes([source&255])*length if a==0x77850 else bytes(u.mem_read(source,length)))
  u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
 elif a in (0x18d2a4,0x189b18):
  size=u.reg_read(UC_ARM_REG_R0);assert 0<size<=200
  ptr=heap;heap+=(size+7)&~7;assert heap<0x780000
  allocs[ptr]=size;u.mem_write(ptr,(b'\x00' if a==0x189b18 else b'\xcc')*size)
  u.reg_write(UC_ARM_REG_R0,ptr);u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
 elif a==0x95c7c and not real_scene:
  assert u.reg_read(UC_ARM_REG_R2)==0
  u.mem_write(u.reg_read(UC_ARM_REG_R0),struct.pack('<iii',*scene_base))
  u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
 elif a==0x18d294:
  ptr=u.reg_read(UC_ARM_REG_R0);assert ptr in allocs;del allocs[ptr]
  u.reg_write(UC_ARM_REG_PC,u.reg_read(UC_ARM_REG_LR))
u.hook_add(UC_HOOK_CODE,hook)

class Spec(ctypes.Structure):
 _fields_=[(k,ctypes.c_int32) for k in ['count','frames','style','mirror','coordinate_format','kind','mode','phase']]+[('release',Point),('target',Point)]
n.bs2_pitch_path.argtypes=[ctypes.POINTER(Spec),ctypes.POINTER(Point),ctypes.POINTER(Point),ctypes.POINTER(Point)]
n.bs2_pitch_atan.argtypes=[ctypes.c_int32];n.bs2_pitch_atan.restype=ctypes.c_int32
rng=random.Random(8)
for value in [-2147483648,-1,0,1,2147483647]+[rng.randrange(-2147483648,2147483648) for _ in range(1000)]:
 u.reg_write(UC_ARM_REG_R0,value&0xffffffff);u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
 u.emu_start(0xbb15d,0xa00000,count=100000)
 assert u.reg_read(UC_ARM_REG_PC)==0xa00000
 assert ctypes.c_int32(u.reg_read(UC_ARM_REG_R0)).value==n.bs2_pitch_atan(value),value
print('PASS: 1,005 atan lookup cases match original ARM.')
def compare(record,style,mirror,mode,phase,target,fmt=1,scene=None,raised=0):
 global heap,scene_base,real_scene
 heap=0x700000;allocs.clear();real_scene=scene is not None
 count=len(record['points']);frames=record['base_frames'];kind=record['spline_kind']
 p=(Point*count)(*[Point(*x) for x in record['points']]);controls=(Point*count)();out=(Point*(frames+3))()
 scene_base=(10,-50,180);offset=(style-5,style*2,-style)
 release=Point(*[(a+b)*262144 for a,b in zip(scene_base,offset)])
 if scene is not None:
  scene_buf=(ctypes.c_ubyte*len(scene)).from_buffer_copy(scene)
  assert n.bs2_pitch_release(scene_buf,len(scene),style,raised,ctypes.byref(release))==0
 spec=Spec(count,frames,style,mirror,fmt,kind,mode,phase,release,Point(*target))
 assert n.bs2_pitch_path(ctypes.byref(spec),p,controls,out)==0
 # Controlled scene boundary: figure-manager release offsets and defense position.
 u.mem_write(0x1f9cf4,struct.pack('<I',0x600000));fig=bytearray(1024)
 pos=0x194+style*12 if style<6 else 0x238+(style-6)*12
 struct.pack_into('<iii',fig,pos,*offset)
 if scene is not None:fig[4:4+len(scene)]=scene;fig[0x334]=raised
 u.mem_write(0x600000,bytes(fig))
 obj=bytearray(256);struct.pack_into('<I',obj,0,style)
 struct.pack_into('<III',obj,0x7c,0x840000,count,0x850000)
 struct.pack_into('<I',obj,0x88,frames+3)
 struct.pack_into('<6I',obj,0x9c,count,0x810000,0x820000,0x830000,mode,phase)
 struct.pack_into('<iii',obj,0xc0,*target);obj[0xd4]=fmt;obj[0xd5]=kind
 u.mem_write(0x800000,bytes(obj));u.mem_write(0x840000,bytes(p)+b'\xa5'*16)
 u.mem_write(0x850000,b'\xa5'*((frames+3)*12+16))
 for reg,val in [(UC_ARM_REG_R0,0x800000),(UC_ARM_REG_R1,mirror),(UC_ARM_REG_SP,0x900000),(UC_ARM_REG_LR,0xa00001)]:u.reg_write(reg,val)
 try:u.emu_start(0xb43e9,0xa00000,count=20000000)
 except Exception:
  print([hex(a) for a in trace]);print('FAULT PC',hex(u.reg_read(UC_ARM_REG_PC)),'LR',hex(u.reg_read(UC_ARM_REG_LR)));raise
 label=(record['group'],record['variant'],style,mirror,mode,phase,fmt)
 assert u.reg_read(UC_ARM_REG_PC)==0xa00000,('return',label,hex(u.reg_read(UC_ARM_REG_PC)))
 actual=bytes(u.mem_read(0x840000,count*12))
 assert actual==bytes(controls),('control mismatch',label,struct.unpack('<iii',actual[:12]),tuple((controls[0].x,controls[0].y,controls[0].z)))
 actual=bytes(u.mem_read(0x850000,(frames+3)*12))
 assert actual==bytes(out),('path mismatch',label,next((i,a,b) for i,(a,b) in enumerate(zip(actual,bytes(out))) if a!=b))
 struct.pack_into('<iii',obj,0xb4,release.x,release.y,release.z)
 assert bytes(u.mem_read(0x800000,256))==bytes(obj),('object mismatch',label)
 assert bytes(u.mem_read(0x840000+count*12,16))==b'\xa5'*16
 assert bytes(u.mem_read(0x850000+(frames+3)*12,16))==b'\xa5'*16
 assert not allocs
 return frames+3
records=json.loads(Path(__file__).with_name('pitch-records.json').read_text());cases=vertices=0
for r in records:
 vertices+=compare(r,r['style'],0,0,0,(3*262144,-10*262144,0));cases+=1
print(f'PASS: {cases} full UpdatePitch comparisons with extracted records, {vertices} path vertices including extrapolation; controlled scene inputs.')
for style in range(11):
 for kind in [0,1]:
  r=next(x for x in records if x['spline_kind']==kind)
  for mode in range(5):
   for fmt in [0,1]:
    compare(r,style,1,mode,17,(-5*262144,9*262144,2*262144),fmt)
print('PASS: 220 additional UpdatePitch cases cover all 11 styles, both curve kinds, five timing modes, mirroring and legacy coordinate handling; transformed controls, full object, guards and allocation lifetime matched.')

# Validate decoded asset layout against original version-7 decoder.
from extract_figure import decode
n.bs2_pitch_release.argtypes=[ctypes.POINTER(ctypes.c_ubyte),ctypes.c_size_t,ctypes.c_int,ctypes.c_int,ctypes.POINTER(Point)]
asset_cases=0
for asset in sorted(Path(__file__).with_name('figure-assets').glob('*.fig')):
 raw=asset.read_bytes();scene,fence=decode(raw)
 heap=0x700000;allocs.clear()
 u.mem_write(0x800000,bytes(0x328)+b'\xa5'*16);u.mem_write(0x840000,raw[4:])
 u.reg_write(UC_ARM_REG_R0,0x800000);u.reg_write(UC_ARM_REG_R1,0x840000)
 u.reg_write(UC_ARM_REG_SP,0x900000);u.reg_write(UC_ARM_REG_LR,0xa00001)
 u.emu_start(0x97251,0xa00000,count=100000)
 assert u.reg_read(UC_ARM_REG_PC)==0xa00000
 assert u.reg_read(UC_ARM_REG_R0)==len(raw)-4
 actual=bytearray(u.mem_read(0x800000,0x328));ptr=struct.unpack_from('<I',actual,0x150)[0]
 assert bytes(u.mem_read(ptr,len(fence)))==fence and allocs=={ptr:len(fence)}
 struct.pack_into('<I',actual,0x150,0);assert bytes(actual)==scene
 assert bytes(u.mem_read(0x800328,16))==b'\xa5'*16
 for r in records:
  for raised in [0,1]:
   compare(r,r['style'],1,0,0,(0,-10*262144,0),scene=scene,raised=raised);asset_cases+=1
print(f'PASS: two figure assets decode exactly; {asset_cases} full UpdatePitch comparisons use original scene-position code with no scene callback substitution.')
# Rejected path input must not mutate either output buffer.
r=records[0];p=(Point*len(r['points']))(*[Point(*x) for x in r['points']])
controls=(Point*50)();path=(Point*4099)();ctypes.memset(controls,0xa5,ctypes.sizeof(controls));ctypes.memset(path,0xa5,ctypes.sizeof(path))
before=(bytes(controls),bytes(path))
base=Spec(len(p),16,0,0,1,0,0,0,Point(0,0,0),Point(0,0,0))
for field,value in [('count',1),('count',51),('frames',1),('frames',4097),('style',-1),('style',11),('kind',2),('mode',5),('phase',91),('coordinate_format',2)]:
 spec=Spec.from_buffer_copy(bytes(base));setattr(spec,field,value)
 assert n.bs2_pitch_path(ctypes.byref(spec),p,controls,path)==-1
 assert (bytes(controls),bytes(path))==before
flat=(Point*len(p))(*[Point(x.x,x.y,0) for x in p])
assert n.bs2_pitch_path(ctypes.byref(base),flat,controls,path)==-1 and (bytes(controls),bytes(path))==before
print('PASS: invalid and zero-depth path inputs rejected without output writes.')
