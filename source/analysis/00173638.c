/* CBBGLogoRun::DrawProcess at 00173638; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::DrawProcess() */

void CBBGLogoRun::DrawProcess(void)

{
  int in_r0;
  int iVar1;
  
  iVar1 = *(int *)(in_r0 + 0xc);
  if (iVar1 == 3) {
    DRAW_HANDLER_MSTATE_CERTI();
  }
  else if (iVar1 < 4) {
    if (iVar1 == 2) {
      DRAW_HANDLER_MSTATE_DATA_ERROR();
    }
  }
  else if (iVar1 == 4) {
    DRAW_HANDLER_MSTATE_WARNING();
  }
  else if (iVar1 == 5) {
    DRAW_HANDLER_MSTATE_LOGO();
  }
  return;
}


