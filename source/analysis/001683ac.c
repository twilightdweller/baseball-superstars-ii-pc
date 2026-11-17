/* CBBGMenuRun::SetSubMenuSelectIdx at 001683ac; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::SetSubMenuSelectIdx() */

void CBBGMenuRun::SetSubMenuSelectIdx(void)

{
  CBBGMenuRun *in_r0;
  int extraout_r1;
  
  if ((in_r0[0x122] != (CBBGMenuRun)0x0) &&
     (__aeabi_idivmod(*(undefined4 *)(in_r0 + 0x134),0x19),
     0xc < (extraout_r1 + (extraout_r1 >> 0x1f) ^ extraout_r1 >> 0x1f))) {
    if (extraout_r1 < 1) {
      ArrayRotate(in_r0,(signed *)(in_r0 + 0x79),7,-2);
      ArrayRotate(in_r0,(signed *)(in_r0 + 0x80),7,-2);
      if (extraout_r1 != 0) {
        SetMenuIdx(in_r0,'\0',1);
      }
    }
    else {
      ArrayRotate(in_r0,(signed *)(in_r0 + 0x79),7,-1);
      ArrayRotate(in_r0,(signed *)(in_r0 + 0x80),7,-1);
      SetMenuIdx(in_r0,'\0',-1);
    }
  }
  return;
}


