/* CCLPitch::GetStrikeZoneFramePos3; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLPitch::GetStrikeZoneFramePos3() */

int * CCLPitch::GetStrikeZoneFramePos3(void)

{
  int iVar1;
  int *in_r0;
  int in_r1;
  int *piVar2;
  int iVar3;
  
  if (*(int *)(in_r1 + 0x84) == 0) {
    iVar3 = **(int **)(DAT_000c3ebc + 0xc3e2e + DAT_000c3ec0);
    CCLFigureMgr::ToVirtual((bbtagPoint2D)in_r0);
    in_r0[1] = -*(int *)(iVar3 + 0x180);
  }
  else {
    piVar2 = (int *)(*(int *)(in_r1 + 0x8c) * 0xc + *(int *)(in_r1 + 0x84));
    iVar3 = *piVar2;
    iVar1 = piVar2[2];
    in_r0[1] = piVar2[1] + 0x20000 >> 0x12;
    in_r0[2] = iVar1 + 0x20000 >> 0x12;
    *in_r0 = iVar3 + 0x20000 >> 0x12;
  }
  return in_r0;
}


