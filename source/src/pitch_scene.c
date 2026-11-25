#include "pitch_scene.h"
static int32_t wrap(int64_t v) {
    uint32_t u=(uint32_t)v;
    return u<=INT32_MAX?(int32_t)u:(int32_t)((int64_t)u-4294967296LL);
}
static int32_t read32(const unsigned char *p) {
    return wrap((uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24);
}
static int32_t shift18(int64_t v){return wrap(v>=0?v/262144:-((-v+262143)/262144));}
static int32_t virtual_size(int32_t size,int32_t scale) {
    int32_t product=shift18((int64_t)wrap((int64_t)size*262144)*scale+131072);
    return shift18(wrap((int64_t)product+131072));
}
int bs2_pitch_release(const unsigned char *f,size_t size,int style,int raised,BS2Point3 *out) {
    if(!f||!out||size!=0x328||style<0||style>10||raised<0||raised>1)return -1;
    int32_t width=read32(f+8),height=read32(f+12),scale=read32(f+4);
    if(width<=0||height<=0)return -1;
    int32_t vw=virtual_size(width,scale),vh=virtual_size(height,scale);
    int32_t x=wrap((int64_t)(wrap((int64_t)vw*read32(f+0x34))/width)
                      -(wrap((int64_t)vw*read32(f+0xa8))/width));
    int32_t z=wrap((int64_t)(wrap((int64_t)vh*read32(f+0xac))/height)
                      -(wrap((int64_t)vh*read32(f+0x38))/height));
    int32_t y=raised?0:read32(f+0x214);
    if(raised)z=wrap((int64_t)z+15);
    unsigned offset=style<6?0x190+12*style:0x234+12*(style-6);
    x=wrap((int64_t)x+read32(f+offset));y=wrap((int64_t)y+read32(f+offset+4));z=wrap((int64_t)z+read32(f+offset+8));
    *out=(BS2Point3){wrap((int64_t)x*262144),wrap((int64_t)y*262144),wrap((int64_t)z*262144)};
    return 0;
}

/* IntersectStrikeZone uses the fixed-point xToVirtual overload for the plate
 * and integer virtual coordinates for the origin. They round differently. */
int bs2_zone_corners(const unsigned char *f, size_t size,
                     BS2Point3 *first, BS2Point3 *second) {
    if (!f || size != 0x328 || !first || !second) return -1;
    int32_t width = read32(f + 8), height = read32(f + 12), scale = read32(f + 4);
    if (width <= 0 || width > 4096 || height <= 0 || height > 4096) return -1;
    int32_t vw = virtual_size(width, scale), vh = virtual_size(height, scale);
    int32_t ox = wrap((int64_t)vw * read32(f + 0x34)) / width;
    int32_t oz = wrap((int64_t)vh * read32(f + 0x38)) / height;
    int32_t sx = wrap((int64_t)vw * 262144) / width;
    int32_t sz = wrap((int64_t)vh * 262144) / height;
    int32_t plate_x = wrap((int64_t)read32(f + 0x174) * 262144);
    int32_t plate_z = wrap((int64_t)read32(f + 0x178) * 262144);
    int32_t x = wrap((int64_t)ox * 262144 - shift18((int64_t)sx * plate_x + 131072));
    int32_t z = wrap((int64_t)shift18((int64_t)sz * plate_z + 131072) - (int64_t)oz * 262144);
    int32_t y = wrap(-(int64_t)read32(f + 0x17c) * 262144);
    int32_t dx = read32(f + 0x180), dy = read32(f + 0x184);
    *first = (BS2Point3){wrap((int64_t)x - dx), wrap((int64_t)y - dy), z};
    *second = (BS2Point3){wrap((int64_t)x + dx), wrap((int64_t)y + dy), z};
    return 0;
}
