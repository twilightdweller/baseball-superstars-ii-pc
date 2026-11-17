#include <stdint.h>
#include <stddef.h>
/* Bounded reconstruction of DrawOP_COPY_Compress_16. Returns 0 on success. */
int bs2_blit(uint16_t *dst,size_t pixels,const uint8_t *src,size_t size,const uint16_t *palette,size_t colors,unsigned gap) {
 size_t p=0,out=0;
 if(size>=10 && src[0]==0xfb && src[1]==0xff)p=10;
 while(p+2<=size){
  unsigned tag=src[p]|((unsigned)src[p+1]<<8);p+=2;
  if(tag==0xffff)return 0;
  if(tag==0xfffe){if(gap>pixels-out)return -1;out+=gap;continue;}
  if(!(tag&0x8000)){if(tag>pixels-out)return -2;out+=tag;continue;}
  unsigned count=tag&0x7fff;
  if(count>size-p || count>pixels-out)return -3;
  for(unsigned k=0;k<count;k++){unsigned idx=src[p++];if(idx>=colors)return -4;dst[out++]=palette[idx];}
 }
 return -5;
}
