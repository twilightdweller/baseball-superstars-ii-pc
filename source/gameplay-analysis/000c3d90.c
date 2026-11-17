/* CCLPitch::GetSettingPitchIndex; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLPitch::GetSettingPitchIndex() */

int CCLPitch::GetSettingPitchIndex(void)

{
  int in_r0;
  int iVar1;
  
  if (((0x15 < *(int *)(in_r0 + 0x98) - 1U) ||
      (iVar1 = (uint)*(byte *)(DAT_000c3dc4 + 0xc3d9c + DAT_000c3dc8 + *(int *)(in_r0 + 0x98)) * 4 +
               *(int *)(in_r0 + 0x94), 0x17 < iVar1)) ||
     (*(int *)(in_r0 + (iVar1 + 6) * 4 + 4) == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}


