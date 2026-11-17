/* CBBGMenuRun::SetMenuSelectIdx at 00168430; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::SetMenuSelectIdx() */

void CBBGMenuRun::SetMenuSelectIdx(void)

{
  CBBGMenuRun *in_r0;
  int extraout_r1;
  signed *psVar1;
  
  if ((in_r0[DAT_001684ac] != (CBBGMenuRun)0x0) &&
     (__aeabi_idivmod(*(undefined4 *)(in_r0 + 0x130),0x5f),
     0x2f < (extraout_r1 + (extraout_r1 >> 0x1f) ^ extraout_r1 >> 0x1f))) {
    psVar1 = (signed *)(in_r0 + 0x73);
    if (extraout_r1 < 1) {
      if (extraout_r1 == 0) {
        ArrayRotate(in_r0,psVar1,(int)(char)in_r0[0x87],-3);
      }
      else {
        ArrayRotate(in_r0,psVar1,(int)(char)in_r0[0x87],-4);
        SetMenuIdx(in_r0,'\x01',1);
      }
    }
    else {
      ArrayRotate(in_r0,psVar1,(int)(char)in_r0[0x87],-3);
      SetMenuIdx(in_r0,'\x01',-1);
    }
  }
  return;
}


