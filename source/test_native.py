from native_test_library import load
import ctypes,random,struct,sys
# Reuse the original ELF-loading test harness. It defines u and call.
exec(open(__file__.replace('test_native.py','check_original.py')).read())
n=load('bs2-currency')
for name in ['bs2_checksum','bs2_set','bs2_get','bs2_add','bs2_cheat_grant']:
 getattr(n,name).restype=ctypes.c_uint32
n.bs2_set.argtypes=[ctypes.c_uint32]
n.bs2_checksum.argtypes=[ctypes.c_uint32]
n.bs2_add.argtypes=[ctypes.c_uint32,ctypes.c_int32]
n.bs2_cheat_grant.argtypes=[ctypes.c_uint32,ctypes.c_bool,ctypes.c_uint32]
r=random.Random(20261026)
for i in range(2000):
 value=r.randrange(0,2**32) if i%2 else r.randrange(1000000)
 delta=r.randrange(-2000000,2000000)
 call('_ZN10CBBGOption9SetGPointEj',value)
 encoded=n.bs2_set(value)
 assert struct.unpack('<I',u.mem_read(0x800068,4))[0]==encoded
 assert struct.unpack('<I',u.mem_read(0x8002e4,4))[0]==n.bs2_checksum(encoded)
 call('_ZN10CBBGOption9AddGPointEi',delta)
 encoded=n.bs2_add(encoded,delta)
 assert struct.unpack('<I',u.mem_read(0x800068,4))[0]==encoded
 assert struct.unpack('<I',u.mem_read(0x8002e4,4))[0]==n.bs2_checksum(encoded)
 assert call('_ZN10CBBGOption9GetGPointEv')==n.bs2_get(encoded)
 assert n.bs2_cheat_grant(encoded,False,10000)==encoded
 assert n.bs2_get(n.bs2_cheat_grant(encoded,True,1000000))==999999
print('PASS: 2,000 deterministic differential cases, including original encoded balance and checksum; cheat off/on checks passed.')
