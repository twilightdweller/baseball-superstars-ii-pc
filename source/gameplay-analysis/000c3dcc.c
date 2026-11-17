/* CCLPitch::SetPitchEndPosCenter; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLPitch::SetPitchEndPosCenter() */

void CCLPitch::SetPitchEndPosCenter(void)

{
  int in_r0;
  int iVar1;
  int local_24 [2];
  int local_1c;
  
  iVar1 = **(int **)(DAT_000c3e18 + 0xc3dd8 + DAT_000c3e1c);
  CCLFigureMgr::ToVirtual((bbtagPoint2D)local_24);
  iVar1 = *(int *)(iVar1 + 0x180);
  *(int *)(in_r0 + 0xc0) = local_24[0] << 0x12;
  *(int *)(in_r0 + 0xc4) = iVar1 * -0x40000;
  *(int *)(in_r0 + 200) = local_1c << 0x12;
  return;
}


