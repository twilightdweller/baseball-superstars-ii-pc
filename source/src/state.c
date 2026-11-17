#include <stdint.h>
#include <string.h>
static uint32_t rd(const uint8_t*p){uint32_t v;memcpy(&v,p,4);return v;}
static void wr(uint8_t*p,uint32_t v){memcpy(p,&v,4);}
void bs2_state_init(uint8_t*p){
 const unsigned offsets[]={4,16,8,48,44,32,40,68};
 for(unsigned i=0;i<sizeof(offsets)/sizeof(offsets[0]);i++)wr(p+offsets[i],0);
 wr(p+20,UINT32_MAX);p[24]=0;p[26]=0;
}
void bs2_state_reserve(uint8_t*p,uint32_t state){wr(p+12,rd(p+8));wr(p+8,state);p[24]=1;}
int bs2_state_cancel(uint8_t*p){if(p[24]){wr(p+12,rd(p+8));wr(p+8,rd(p+4));p[24]=0;}return 0;}
int bs2_state_check(uint8_t*p){
 if(p[26])wr(p+8,rd(p+4));
 if(rd(p+4)!=rd(p+8)){
  wr(p+16,rd(p+4));wr(p+4,rd(p+8));p[25]=1;wr(p+20,0);wr(p,0);p[24]=0;return 1;
 }
 uint32_t count=rd(p+20)+1;
 /* ARM uses a signed comparison; preserve wrapping arithmetic explicitly. */
 if(count<0x80000000u && count>99999999u)count=0;
 wr(p+20,count);p[25]=0;return 0;
}
