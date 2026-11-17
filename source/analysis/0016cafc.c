/* CBBGMenuRun::DRAW_HANDLER_MSTATE_GSHOP at 0016cafc; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DRAW_HANDLER_MSTATE_GSHOP() */

void CBBGMenuRun::DRAW_HANDLER_MSTATE_GSHOP(void)

{
  int in_r0;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  
  iVar4 = DAT_0016cb74 + 0x16cb0c;
  iVar3 = **(int **)(iVar4 + DAT_0016cb78);
  uVar2 = *(undefined4 *)(iVar3 + 0x48);
  iVar6 = *(int *)(iVar3 + 0x4c);
  iVar3 = *(int *)(iVar3 + 0x3c);
  uVar1 = MC_grpGetPixelFromRGB(0,0,0);
  pcVar5 = **(code ***)(iVar4 + DAT_0016cb7c);
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(0,0,uVar2,iVar3 + iVar6,uVar1,5);
  }
  iVar3 = *(int *)(in_r0 + 0x6c);
  *(undefined4 *)(iVar3 + 0x5c) = 0x10;
  *(undefined *)(iVar3 + 100) = 1;
  *(undefined *)(iVar3 + 0x65) = 1;
  *(undefined4 *)(iVar3 + 0x68) = 2;
  *(undefined4 *)(*(int *)(in_r0 + 0x6c) + 0x68) = 2;
  if (*(int *)(in_r0 + 0xc) == 0x16) {
    CBBGCommonMenu::DrawBuyGPoint();
  }
  else if (*(int *)(in_r0 + 0xc) == 0x17) {
    CBBGCommonMenu::DrawGiftGPoint();
  }
  return;
}


