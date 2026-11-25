from native_test_library import load
import zipfile,zlib,struct,ctypes,pathlib,sys
from PIL import Image
lib=load('bs2-graphics')
lib.bs2_blit.argtypes=[ctypes.POINTER(ctypes.c_uint16),ctypes.c_size_t,ctypes.c_void_p,ctypes.c_size_t,ctypes.POINTER(ctypes.c_uint16),ctypes.c_size_t,ctypes.c_uint]
def frames(b):
 assert b[:4]==b'PZX\1'
 base=struct.unpack_from('<I',b,4)[0];kind,count,flags=struct.unpack_from('<BHB',b,base)
 if kind!=8 or flags not in (0,1):raise ValueError('Unsupported container variant')
 pos=base+4
 shared=None
 if flags==1:
  colors=b[pos];shared=b[pos+1:pos+1+colors*2];pos+=1+colors*2
 rawsize,compressed=struct.unpack_from('<II',b,pos)
 d=zlib.decompress(b[pos+8:pos+8+compressed]);assert len(d)==rawsize
 offsets=struct.unpack_from('<'+'I'*count,d)
 for index,off in enumerate(offsets):
  if shared is None:
   colors=d[off];pal=d[off+1:off+1+colors*2];pos=off+1+colors*2
  else:
   pal=shared;pos=off
  w,h,mode,flag,padding,size,compressed=struct.unpack_from('<HHBBHII',d,pos);pos+=16
  if flag==1:raise ValueError('Unsupported frame variant')
  payload=zlib.decompress(d[pos:pos+compressed]) if compressed else d[pos:pos+size]
  assert len(payload)==size
  if mode!=2:raise ValueError('Unsupported pixel mode')
  yield index,w,h,pal,payload

def render(w,h,pal,payload):
 dst=(ctypes.c_uint16*(w*h))();palette=(ctypes.c_uint16*(len(pal)//2)).from_buffer_copy(pal)
 status=lib.bs2_blit(dst,w*h,payload,len(payload),palette,len(palette),0)
 assert status==0,status
 return bytes(dst)
if __name__=='__main__':
 out=pathlib.Path(sys.argv[2]);out.mkdir(parents=True,exist_ok=True)
 with zipfile.ZipFile(sys.argv[1]) as z:
  for name in ['assets/ui/title.pzx','assets/mainui/main_title.pzx']:
   for i,w,h,pal,payload in frames(z.read(name)):
    raw=render(w,h,pal,payload)
    rgb=[]
    for (v,) in struct.iter_unpack('<H',raw):rgb.append((((v>>11)&31)*255//31,((v>>5)&63)*255//63,(v&31)*255//31))
    im=Image.new('RGB',(w,h));im.putdata(rgb);im.save(out/(pathlib.Path(name).stem+f'_{i:02}.png'))
    print(name,i,w,h,'decoded')
