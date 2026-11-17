#include "camera.h"
#include "pitch_sine.h"
#include <string.h>
#include <math.h>
static int32_t w(int64_t v){uint32_t u=(uint32_t)v;return u<=INT32_MAX?(int32_t)u:(int32_t)((int64_t)u-4294967296LL);}
static int32_t rd(const unsigned char *p){return w((uint32_t)p[0]|(uint32_t)p[1]<<8|(uint32_t)p[2]<<16|(uint32_t)p[3]<<24);}
static int32_t mul(int32_t a,int32_t b){int64_t v=(int64_t)a*b+131072;return w(v>=0?v/262144:-((-v+262143)/262144));}
static int32_t dq(int32_t a,int32_t b){return w((int64_t)a*262144/b);}
static int32_t from_float(float a){if(a>=2147483648.0f)return INT32_MAX;if(a<=-2147483648.0f)return INT32_MIN;return (int32_t)a;}
static float rf(const unsigned char *p){uint32_t u=(uint32_t)rd(p);float f;memcpy(&f,&u,4);return f;}
int bs2_camera_from_figure(const unsigned char *f,size_t size,int preset,BS2Projection *out){
 if(!f||!out||size!=0x328||preset<0||preset>2)return -1;
 int32_t width=rd(f+8),height=rd(f+12);const unsigned char *v=f+0x18+36*preset;
 float angle=rf(v+24),near_f=rf(f+16),far_f=rf(f+20);
 if(width<=0||height<=0||width>4096||height>4096||!isfinite(angle)||angle<0||angle>90||!isfinite(near_f)||!isfinite(far_f))return -1;
 int32_t a=from_float(angle*262144.0f),near=from_float(near_f*262144.0f),far=from_float(far_f*262144.0f);
 float aspect_float=(float)width/(float)height;
 int32_t aspect=from_float(aspect_float*262144.0f);
 int32_t sn=pitch_sine[a/32768],cs=pitch_sine[(23592960-a)/32768];
 int32_t tan=cs?dq(sn,cs):262144,top=mul(tan,near),bottom=w(-(int64_t)top);
 int32_t left=mul(bottom,aspect),right=mul(top,aspect),dx=w((int64_t)right-left),dy=w((int64_t)bottom-top),dz=w((int64_t)far-near);
 if(!dx||!dy||!dz)return -1;
 int32_t p[16]={0};p[0]=dq(w((int64_t)near*2),dx);p[2]=dq(w((int64_t)right+left),dx);
 p[5]=dq(w((int64_t)near*2),dy);p[6]=dq(w((int64_t)top+bottom),dy);
 p[10]=dq(w(-((int64_t)far+near)),dz);p[14]=-262144;
 BS2Transform t={0};t.scale[0]=t.scale[1]=t.scale[2]=262144;
 for(int i=0;i<3;i++){t.rotation[i]=w((int64_t)rd(v+4*i)*262144);t.translation[i]=w((int64_t)rd(v+12+4*i)*262144);}
 bs2_matrix_update(&t);BS2Projection result={0};
 for(int col=0;col<4;col++)for(int row=0;row<4;row++){
  int64_t sum=0;for(int k=0;k<4;k++)sum+=mul(p[row+4*k],t.matrix[k+4*col]);result.matrix[row+4*col]=w(sum);
 }
 result.origin_x=w((int64_t)rd(v+28)*262144);result.origin_y=w((int64_t)rd(v+32)*262144);
 result.scale_x=width*131072;result.scale_y=height*131072;*out=result;return 0;
}
