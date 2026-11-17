"""Decode the versioned pitch table supplied in the II APK. No inferred pitch names."""
import json,struct,sys,zlib,zipfile
from pathlib import Path
with zipfile.ZipFile(sys.argv[1]) as apk:
    packed=apk.read('assets/data/pitch.zt1')
compressed,uncompressed=struct.unpack_from('<II',packed)
assert compressed==len(packed)
data=zlib.decompress(packed[8:])
assert len(data)==uncompressed and data[:4]==bytes.fromhex('a79d392e')
groups=data[4];records=[]
for group in range(groups):
    pos=4+struct.unpack_from('<I',data,5+4*group)[0]
    assert data[pos]==group
    count=data[pos+1];pos+=2
    for variant in range(count):
        size,kind,frames,n,style,fmt=data[pos:pos+6]
        assert size==6+12*n and fmt==1
        points=[list(struct.unpack_from('<iii',data,pos+6+12*i)) for i in range(n)]
        records.append(dict(group=group,variant=variant,spline_kind=kind,
                            base_frames=frames,style=style,coordinate_format=fmt,points=points))
        pos+=size
    expected=4+struct.unpack_from('<I',data,5+4*(group+1))[0] if group+1<groups else len(data)
    assert pos==expected
Path(sys.argv[2]).write_text(json.dumps(records,separators=(',',':'))+'\n')
print(f'Decoded {len(records)} curve records in {groups} groups; all lengths and group boundaries checked.')
