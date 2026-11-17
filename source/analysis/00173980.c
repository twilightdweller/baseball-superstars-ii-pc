/* CBBGLogoRun::RunProcess at 00173980; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::RunProcess() */

void CBBGLogoRun::RunProcess(void)

{
  int in_r0;
  int iVar1;
  
  iVar1 = DAT_001739d4;
  RunFilterPopup();
  iVar1 = CBBGPopup::Run(**(CBBGPopup ***)(iVar1 + 0x173990 + DAT_001739d8),*(int *)(in_r0 + 0x30));
  if (iVar1 == 0) {
    iVar1 = *(int *)(in_r0 + 0xc);
    if (iVar1 == 3) {
      EVENT_HANDLER_MSTATE_CERTI();
    }
    else if (iVar1 < 4) {
      if (iVar1 == 2) {
        EVENT_HANDLER_MSTATE_DATA_ERROR();
      }
    }
    else if (iVar1 == 4) {
      EVENT_HANDLER_MSTATE_WARNING();
    }
    else if (iVar1 == 5) {
      EVENT_HANDLER_MSTATE_LOGO();
    }
  }
  return;
}


