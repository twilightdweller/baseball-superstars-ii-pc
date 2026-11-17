#include "pitch_curve.h"
#include "pitch_sine.h"
#define ONE 262144
static int32_t mulq(int32_t a,int32_t b) {
    /* ARM arithmetic shift, including negative products, with half-unit bias. */
    int64_t v=(int64_t)a*b+131072;
    return (int32_t)(v>=0?v/ONE:-((-v+ONE-1)/ONE));
}
static int32_t add32(int32_t a,int32_t b) {
    uint32_t u=(uint32_t)a+(uint32_t)b;
    return u<=INT32_MAX?(int32_t)u:(int32_t)((int64_t)u-4294967296LL);
}
static int32_t wrap32(int64_t v) {
    uint32_t u=(uint32_t)v;
    return u<=INT32_MAX?(int32_t)u:(int32_t)((int64_t)u-4294967296LL);
}
static int32_t hermite(int32_t a,int32_t b,int32_t ta,int32_t tb,int t) {
    int t2=t*t,t3=t2*t;
    int32_t v1=wrap32((int64_t)(t3-80*t2+1600*t)*ta)/64000;
    int32_t v2=wrap32((int64_t)(t3-40*t2)*tb)/64000;
    int32_t v3=wrap32((int64_t)a*(t3-60*t2+32000)*2)/64000;
    int32_t v4=wrap32((int64_t)(60*t2-t3)*2*b)/64000;
    return add32(add32(v1,v2),add32(v3,v4));
}
int bs2_pitch_cardinal(const BS2Point3 *p,int count,BS2Point3 *out,int frames) {
    if(!p||!out||count<2||count>50||frames<2||frames>4096)return -1;
    int32_t q[50][3];
    for(int i=0;i<count;i++) {
        int32_t xyz[3]={p[i].x,p[i].y,p[i].z};
        for(int k=0;k<3;k++) {
            int32_t v=add32(xyz[k],131072);
            q[i][k]=(int32_t)(v>=0?v/ONE:-((-(int64_t)v+ONE-1)/ONE));
        }
    }
    int time=(count-1)*40,step=time/(frames-1);
    for(int frame=frames-1;frame>0 && time>0;frame--,time-=step) {
        int segment=time/40;int32_t v[3];
        for(int k=0;k<3;k++) {
            if(segment>=count-1)v[k]=q[count-1][k];
            else {
                int next=segment+1,last=next<count-1?next+1:next;
                /* Preserve the original unusual threshold of 41 segments. */
                int first=segment<41?segment:segment-1;
                int32_t ta=(q[next][k]-q[first][k])/2;
                int32_t tb=(q[last][k]-q[segment][k])/2;
                v[k]=hermite(q[segment][k],q[next][k],ta,tb,time-segment*40);
            }
            v[k]=wrap32((int64_t)v[k]*ONE);
        }
        out[frame]=(BS2Point3){v[0],v[1],v[2]};
    }
    out[0]=p[0];
    return 0;
}
static void basis(int32_t *b,int degree,int32_t t) {
    if (!degree) { b[0]=ONE; return; }
    int32_t s=ONE-t;b[0]=s;b[1]=t;
    for(int n=2;n<=degree;n++) {
        b[n]=mulq(t,b[n-1]);
        for(int j=n-1;j>0;j--)b[j]=add32(mulq(s,b[j]),mulq(t,b[j-1]));
        b[0]=mulq(s,b[0]);
    }
}
int bs2_pitch_bezier(const BS2Point3 *p,int count,BS2Point3 *out,
                     int frames,int mode,int phase) {
    if(!p||!out||count<1||count>50||frames<2||frames>4096||
       mode<0||mode>4||phase<0||phase>90)return -1;
    int32_t b[50],u=phase*ONE/90,du=(ONE-u)/(frames-1);
    int32_t angle=phase*ONE,da=(90-phase)*ONE/(frames-1);
    for(int f=0;f<frames;f++) {
        int32_t t;
        if(mode==1) {t=ONE-pitch_sine[(90*ONE-angle)>>15];angle+=da;}
        else if(mode==2) {t=pitch_sine[angle>>15];angle+=da;}
        else if(mode==3) {t=mulq(u,u);u+=du;}
        else if(mode==4) {t=mulq(mulq(u,u),u);u+=du;}
        else t=(int32_t)((int64_t)f*ONE/(frames-1));
        basis(b,count-1,t);
        int32_t x=0,y=0,z=0;
        for(int j=0;j<count;j++) {
            x=add32(x,mulq(b[j],p[j].x));
            y=add32(y,mulq(b[j],p[j].y));
            z=add32(z,mulq(b[j],p[j].z));
        }
        out[f]=(BS2Point3){x,y,z};
    }
    return 0;
}
