#include "projection.h"
#include "pitch_sine.h"
static int32_t wrap(int64_t v) {
    uint32_t u=(uint32_t)v;
    return u<=INT32_MAX?(int32_t)u:(int32_t)((int64_t)u-4294967296LL);
}
static int32_t mul(int32_t a,int32_t b) {
    int64_t v=(int64_t)a*b+131072;
    return wrap(v>=0?v/262144:-((-v+262143)/262144));
}
static int32_t sine(int32_t degrees) {
    int64_t a=degrees;
    a%=360LL*262144;
    if(a<0)a+=360LL*262144;
    int sign=1;
    if(a>180LL*262144) {a-=180LL*262144;sign=-1;}
    if(a>90LL*262144)a=180LL*262144-a;
    return sign*pitch_sine[a/32768];
}
void bs2_matrix_update(BS2Transform *t) {
    int32_t sx=sine(t->rotation[0]),cx=sine(wrap(23592960LL-t->rotation[0]));
    int32_t sy=sine(t->rotation[1]),cy=sine(wrap(23592960LL-t->rotation[1]));
    int32_t sz=sine(t->rotation[2]),cz=sine(wrap(23592960LL-t->rotation[2]));
    int32_t *m=t->matrix,a=mul(sy,sx);
    m[0]=mul(mul(cz,cy),t->scale[0]);
    m[1]=mul(mul(-sz,cy),t->scale[0]);
    m[2]=mul(-sy,t->scale[0]);m[3]=0;
    m[4]=mul(wrap((int64_t)mul(a,cz)+mul(sz,cx)),t->scale[1]);
    m[5]=mul(wrap((int64_t)mul(a,-sz)+mul(cx,cz)),t->scale[1]);
    m[6]=mul(mul(sx,cy),t->scale[1]);m[7]=0;
    a=mul(cx,sy);
    m[8]=mul(wrap((int64_t)mul(a,cz)+mul(-sx,sz)),t->scale[2]);
    m[9]=mul(wrap((int64_t)mul(a,-sz)+mul(-sx,cz)),t->scale[2]);
    m[10]=mul(mul(cx,cy),t->scale[2]);
    m[12]=t->translation[0];m[13]=t->translation[1];m[14]=t->translation[2];m[15]=262144;
}
void bs2_matrix_point(BS2Point3 *out,const BS2Point3 *point,const int32_t m[16]) {
    int32_t v[4];
    for(int i=0;i<4;i++)
        v[i]=wrap((int64_t)mul(m[i],point->x)+mul(m[4+i],point->y)+mul(m[8+i],point->z)+m[12+i]);
    if(v[3]) {
        int32_t reciprocal=wrap(68719476736LL/v[3]);
        for(int i=0;i<3;i++)v[i]=mul(reciprocal,v[i]);
    }
    *out=(BS2Point3){v[0],v[1],v[2]};
}
void bs2_project_point(BS2Point2 *out,const BS2Point3 *point,const BS2Projection *p) {
    BS2Point3 v;bs2_matrix_point(&v,point,p->matrix);
    if(v.z) {
        int32_t reciprocal=wrap(68719476736LL/v.z);
        v.x=mul(reciprocal,v.x);v.y=mul(reciprocal,v.y);
    }
    *out=(BS2Point2){wrap((int64_t)p->origin_x-mul(v.x,p->scale_x)),
                   wrap((int64_t)p->origin_y+mul(p->scale_y,v.y))};
}
