"""Decode version-7 figure assets; preserve ARM object offsets without pointers."""
import struct

def decode(data):
    if len(data)<4:raise ValueError('truncated figure header')
    header=struct.unpack_from('<I',data)[0]
    if header>>24!=7 or header&0xffffff!=len(data)-4:
        raise ValueError('unsupported figure version or size')
    p=data[4:]
    if len(p)<0x150:raise ValueError('truncated figure')
    count=struct.unpack_from('<i',p,0x130)[0]
    if count<0 or count>200:raise ValueError('invalid fence count')
    expected=0x150+count*8+0xe0+0x3c+0x10+0x90+0x18
    if len(p)!=expected:raise ValueError('invalid figure payload size')
    out=bytearray(0x328);out[:0x150]=p[:0x150]
    fence=p[0x150:0x150+count*8];q=0x150+count*8
    for dest,size in [(0x154,0xe0),(0x234,0x3c),(0x270,0x10),(0x280,0x90),(0x310,0x18)]:
        out[dest:dest+size]=p[q:q+size];q+=size
    return bytes(out),fence

if __name__=='__main__':
    import sys,zipfile
    from pathlib import Path
    destination=Path(sys.argv[2]);destination.mkdir(parents=True,exist_ok=True)
    with zipfile.ZipFile(sys.argv[1]) as apk:
        for name in ['bb2011_240x320','bb2011_480x320']:
            original=apk.read('assets/data/'+name+'.fig')
            figure,fence=decode(original)
            (destination/(name+'.fig')).write_bytes(original)
            (destination/(name+'.bin')).write_bytes(figure)
            (destination/(name+'-fence.bin')).write_bytes(fence)
            print(f'{name}: {len(figure)} object bytes, {len(fence)//8} fence points')
