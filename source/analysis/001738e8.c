/* CBBGLogoRun::EVENT_HANDLER_MSTATE_LOGO at 001738e8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::EVENT_HANDLER_MSTATE_LOGO() */

void CBBGLogoRun::EVENT_HANDLER_MSTATE_LOGO(void)

{
  uint uVar1;
  uint uVar2;
  CBBGLogoRun *in_r0;
  undefined8 uVar3;
  
  uVar3 = GsGetCurrentTime();
  uVar1 = (int)((ulonglong)uVar3 >> 0x20) - *(int *)(in_r0 + 0x7c);
  uVar2 = (uint)((uint)uVar3 < *(uint *)(in_r0 + 0x78));
  if ((0 < (int)(uVar1 - uVar2)) ||
     ((uVar1 == uVar2 && (DAT_00173930 < (uint)uVar3 - *(uint *)(in_r0 + 0x78))))) {
    *(undefined *)(**(int **)(DAT_00173924 + 0x1738fe + DAT_00173928) + DAT_0017392c) = 1;
    SetChangeRunnable(in_r0,0x101);
  }
  return;
}


