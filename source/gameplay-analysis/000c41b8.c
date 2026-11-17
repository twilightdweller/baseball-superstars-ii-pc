/* CCLPitch::DeletePitchData; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLPitch::DeletePitchData() */

void CCLPitch::DeletePitchData(void)

{
  int in_r0;
  
  if (*(int *)(in_r0 + 0x84) != 0) {
    MC_knlFree();
  }
  if (*(int *)(in_r0 + 0x7c) != 0) {
    MC_knlFree();
  }
  *(undefined4 *)(in_r0 + 0x84) = 0;
  *(undefined4 *)(in_r0 + 0x7c) = 0;
  return;
}


