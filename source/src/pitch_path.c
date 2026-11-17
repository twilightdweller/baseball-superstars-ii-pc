#include "pitch_path.h"
#include "pitch_tangent.h"
#include <string.h>
#define Q 262144
static int32_t w(int64_t v) {
    uint32_t u=(uint32_t)v;
    return u<=INT32_MAX?(int32_t)u:(int32_t)((int64_t)u-4294967296LL);
}
static int32_t sub(int32_t a,int32_t b){return w((int64_t)a-b);}
static int32_t mul(int32_t a,int32_t b) {
    int64_t v=(int64_t)a*b+131072;
    return w(v>=0?v/Q:-((-v+Q-1)/Q));
}
static int32_t divq(int32_t a,int32_t b){return w((int64_t)a*Q/b);}
static int sign(int32_t v){return v<0?-1:1;}
int32_t bs2_pitch_atan(int32_t value) {
    if(value==INT32_MIN)return 270*Q;
    int32_t magnitude=value<0?-value:value;
    int low=0,high=720,index=360;
    for(;;) {
        if(pitch_tangent[index]<=magnitude)low=index;else high=index;
        int next=(low+high)/2;
        if(next==index)return index*32768;
        index=next;
    }
}
int bs2_pitch_path(const BS2PitchSpec *s,const BS2Point3 *input,
                   BS2Point3 *controls,BS2Point3 *path) {
    if(!s||!input||!controls||!path||s->count<2||s->count>50||
       s->frames<2||s->frames>4096||s->kind<0||s->kind>1||
       s->mode<0||s->mode>4||s->phase<0||s->phase>90||
       s->style<0||s->style>10||s->coordinate_format<0||s->coordinate_format>1)return -1;
    BS2Point3 p[50];memcpy(p,input,(unsigned)s->count*sizeof(*p));
    if(!sub(p[s->count-1].z,p[0].z))return -1;
    if(s->mirror && s->style<6 && s->style%2==1)
        for(int i=0;i<s->count;i++)p[i].x=s->coordinate_format==1?w(-(int64_t)p[i].x):w(-(int64_t)(uint16_t)p[i].x*Q);
    BS2Point3 last=p[s->count-1];
    for(int i=0;i<s->count;i++)p[i]=(BS2Point3){sub(p[i].x,last.x),sub(p[i].y,last.y),sub(p[i].z,last.z)};
    int32_t depth=sub(p[s->count-1].z,p[0].z);
    int32_t dy=sub(s->release.y,s->target.y),dx=sub(s->release.x,s->target.x);
    BS2Transform t={0};t.scale[0]=t.scale[1]=t.scale[2]=Q;
    t.rotation[0]=w((int64_t)bs2_pitch_atan(divq(dy,depth))*sign(dy)
                      -(int64_t)bs2_pitch_atan(divq(p[0].y,depth))*sign(p[0].y));
    t.rotation[1]=w(-(int64_t)bs2_pitch_atan(divq(dx,depth))*sign(dx)
                      +(int64_t)bs2_pitch_atan(divq(p[0].x,depth))*sign(p[0].x));
    bs2_matrix_update(&t);
    /* Update creates an affine rotation with w=Q, so the original MulPoint
     * and MatrixMul normalization coincide here. */
    for(int i=0;i<s->count;i++)bs2_matrix_point(&p[i],&p[i],t.matrix);
    depth=sub(p[s->count-1].z,p[0].z);
    int32_t scale=depth?divq(sub(s->target.z,s->release.z),depth):Q;
    for(int i=0;i<s->count;i++)p[i]=(BS2Point3){w((int64_t)p[i].x+s->target.x),
        w((int64_t)p[i].y+s->target.y),w((int64_t)mul(scale,p[i].z)+s->target.z)};
    if(s->kind==1)bs2_pitch_cardinal(p,s->count,path,s->frames);
    else bs2_pitch_bezier(p,s->count,path,s->frames,s->mode,s->phase);
    BS2Point3 a=path[s->frames-1],b=path[s->frames-2];
    BS2Point3 delta={sub(a.x,b.x),sub(a.y,b.y),sub(a.z,b.z)};
    for(int i=s->frames;i<s->frames+3;i++) {
        a=(BS2Point3){w((int64_t)a.x+delta.x),w((int64_t)a.y+delta.y),w((int64_t)a.z+delta.z)};
        path[i]=a;
    }
    memcpy(controls,p,(unsigned)s->count*sizeof(*p));
    return 0;
}
