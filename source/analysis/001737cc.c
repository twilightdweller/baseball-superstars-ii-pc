/* CBBGLogoRun::StartProcess at 001737cc; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::StartProcess() */

void CBBGLogoRun::StartProcess(void)

{
  int in_r0;
  int iVar1;
  
  iVar1 = *(int *)(in_r0 + 0xc);
  if (iVar1 == 4) {
    INIT_HANDLER_MSTATE_WARNING();
  }
  else if (iVar1 == 5) {
    INIT_HANDLER_MSTATE_LOGO();
  }
  else if (iVar1 == 3) {
    INIT_HANDLER_MSTATE_CERTI();
  }
  return;
}


