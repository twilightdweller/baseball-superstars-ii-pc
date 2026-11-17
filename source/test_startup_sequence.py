from native_test_library import load
import ctypes,struct
s=load('bs2-state');t=load('bs2-title-flow')
s.bs2_state_check.argtypes=[ctypes.c_void_p];t.bs2_title_tick.argtypes=[ctypes.c_void_p,ctypes.c_uint64]
obj=(ctypes.c_uint8*512)()
def put(off,value):struct.pack_into('<I',obj,off,value)
def get(off):return struct.unpack_from('<I',obj,off)[0]
# A CBBState begins at CBBGMenuRun + 8. Title initialization has already run.
put(12,6);put(16,6);obj[0x15c]=1
state=ctypes.cast(ctypes.byref(obj,8),ctypes.c_void_p)
assert t.bs2_title_tick(obj,2999)==0 and get(8)==0
assert s.bs2_state_check(state)==0 and get(12)==6
assert t.bs2_title_tick(obj,3000)==0 and get(8)==100
assert s.bs2_state_check(state)==0 and get(12)==6
assert t.bs2_title_tick(obj,3016)==0 and get(16)==7
assert s.bs2_state_check(state)==1 and get(12)==7 and get(24)==6
assert get(8)==0 and obj[33]==1
print('PASS: native sequence stays at title through 2999 ms, schedules transition after 3000 ms, commits menu state 7 on following tick, retaining previous state 6.')
