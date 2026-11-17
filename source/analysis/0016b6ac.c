/* CBBGMenuRun::DRAW_HANDLER_MSTATE_HELP at 0016b6ac; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DRAW_HANDLER_MSTATE_HELP() */

void CBBGMenuRun::DRAW_HANDLER_MSTATE_HELP(void)

{
  int in_r0;
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  
  iVar2 = DAT_0016b724;
  DRAW_HANDLER_MSTATE_MAIN();
  iVar4 = **(int **)(iVar2 + 0x16b6c2 + DAT_0016b728);
  uVar3 = *(undefined4 *)(iVar4 + 0x48);
  iVar6 = *(int *)(iVar4 + 0x4c);
  iVar4 = *(int *)(iVar4 + 0x3c);
  uVar1 = MC_grpGetPixelFromRGB(0,0,0);
  pcVar5 = **(code ***)(iVar2 + 0x16b6c2 + DAT_0016b72c);
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(0,0,uVar3,iVar4 + iVar6,uVar1,5);
  }
  CBBGCommonMenu::DrawHelp();
  iVar2 = CBBGCommonMenu::IsHelpInquire();
  if (iVar2 == 0) {
    iVar2 = *(int *)(in_r0 + 0x6c);
    uVar1 = 0xf;
  }
  else {
    iVar2 = *(int *)(in_r0 + 0x6c);
    uVar1 = 0x13;
  }
  *(undefined4 *)(iVar2 + 0x5c) = uVar1;
  *(undefined *)(iVar2 + 100) = 1;
  *(undefined *)(iVar2 + 0x65) = 1;
  *(undefined4 *)(iVar2 + 0x68) = 2;
  return;
}


