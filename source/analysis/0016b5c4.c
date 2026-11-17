/* CBBGMenuRun::DRAW_HANDLER_MSTATE_DATA_UPLOAD at 0016b5c4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DRAW_HANDLER_MSTATE_DATA_UPLOAD() */

void CBBGMenuRun::DRAW_HANDLER_MSTATE_DATA_UPLOAD(void)

{
  int in_r0;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  
  iVar4 = DAT_0016b62c;
  DRAW_HANDLER_MSTATE_MAIN();
  iVar3 = **(int **)(iVar4 + 0x16b5da + DAT_0016b630);
  uVar2 = *(undefined4 *)(iVar3 + 0x48);
  iVar6 = *(int *)(iVar3 + 0x4c);
  iVar3 = *(int *)(iVar3 + 0x3c);
  uVar1 = MC_grpGetPixelFromRGB(0,0,0);
  pcVar5 = **(code ***)(iVar4 + 0x16b5da + DAT_0016b634);
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(0,0,uVar2,iVar3 + iVar6,uVar1,5);
  }
  iVar4 = *(int *)(in_r0 + 0x6c);
  *(undefined4 *)(iVar4 + 0x5c) = 0xe;
  *(undefined *)(iVar4 + 100) = 1;
  *(undefined *)(iVar4 + 0x65) = 1;
  *(undefined4 *)(iVar4 + 0x68) = 2;
  CBBGCommonMenu::DrawGameSetting(*(CBBGCommonMenu **)(in_r0 + 0x6c),false);
  return;
}


