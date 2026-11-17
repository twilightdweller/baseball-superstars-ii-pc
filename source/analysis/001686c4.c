/* CBBGMenuRun::DRAW_HANDLER_MSTATE_HOMERUN_MODE at 001686c4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DRAW_HANDLER_MSTATE_HOMERUN_MODE() */

void CBBGMenuRun::DRAW_HANDLER_MSTATE_HOMERUN_MODE(void)

{
  int in_r0;
  int iVar1;
  
  if (*(int *)(in_r0 + 8) == 1) {
    iVar1 = *(int *)(in_r0 + 0x6c);
    *(undefined4 *)(iVar1 + 0x5c) = 8;
    *(undefined *)(iVar1 + 100) = 1;
    *(undefined *)(iVar1 + 0x65) = 1;
    *(undefined4 *)(iVar1 + 0x68) = 2;
    *(undefined4 *)(*(int *)(in_r0 + 0x6c) + 0x68) = 3;
    CBBGCommonMenu::DrawCaptureTitle(*(CBBGCommonMenu **)(in_r0 + 0x6c),'\0','\0');
    CBBGCommonMenu::DrawHallOfFame();
  }
  return;
}


