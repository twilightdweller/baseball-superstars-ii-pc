/* CBBGLogoRun::EVENT_HANDLER_MSTATE_CERTI at 00173934; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::EVENT_HANDLER_MSTATE_CERTI() */

void CBBGLogoRun::EVENT_HANDLER_MSTATE_CERTI(void)

{
  CBBGLogoRun *in_r0;
  int iVar1;
  
  if (*(CGsCertification **)(in_r0 + 0x68) != (CGsCertification *)0x0) {
    CGsCertification::KeyPress(*(CGsCertification **)(in_r0 + 0x68),*(int *)(in_r0 + 0x30));
    iVar1 = CGsCertification::Update();
    if (iVar1 == 2) {
      if (*(int **)(in_r0 + 0x68) != (int *)0x0) {
        (**(code **)(**(int **)(in_r0 + 0x68) + 0x20))();
        *(undefined4 *)(in_r0 + 0x68) = 0;
      }
      SetChangeRunnable(in_r0,DAT_0017397c);
    }
    else {
      if (iVar1 != 0) {
        if (iVar1 != 4) {
          return;
        }
        iVar1 = 0;
      }
      GsExit(iVar1);
    }
  }
  return;
}


