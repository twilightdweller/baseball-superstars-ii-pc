#include <stdint.h>
/* Reconstructed automatic title path only. Network-linked state 1 is unsupported.
   Input/output buffer layout intentionally matches the original CBBGMenuRun object
   for differential validation. This is not yet integrated with the Windows viewer. */
#include <string.h>
static uint32_t rd(const uint8_t *p){uint32_t v;memcpy(&v,p,4);return v;}
static void wr(uint8_t *p,uint32_t v){memcpy(p,&v,4);}
int bs2_title_tick(uint8_t *object,uint64_t now){
 uint32_t state=rd(object+8);
 if(state!=0 && state!=100)return -1;
 uint64_t start=(uint64_t)rd(object+0x118)|((uint64_t)rd(object+0x11c)<<32);
 uint64_t elapsed=now-start;
 int ready=!(elapsed>>63) && elapsed>2999;
 object[0x120]=(uint8_t)ready;
 if(state==0){if(object[0x15c]&&ready){object[0x15c]=0;wr(object+8,100);}return 0;}
 wr(object+0x14,rd(object+0x10));wr(object+0x10,7);object[0x20]=1;
 return 0;
}
