/* CBBGLogoRun::DRAW_HANDLER_MSTATE_WARNING at 00173430; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::DRAW_HANDLER_MSTATE_WARNING() */

void CBBGLogoRun::DRAW_HANDLER_MSTATE_WARNING(void)

{
  int iVar1;
  int in_r0;
  uint uVar2;
  int extraout_r1;
  int iVar3;
  int iVar4;
  int iVar5;
  CGsGraphics **ppCVar6;
  CGsGraphics *pCVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  char acStack_6c [64];
  int local_2c;
  
  iVar3 = DAT_00173600;
  iVar1 = DAT_001735fc;
  iVar5 = DAT_001735f8 + 0x173446;
  local_2c = **(int **)(iVar5 + DAT_001735fc);
  ppCVar6 = *(CGsGraphics ***)(iVar5 + DAT_00173600);
  pCVar7 = *ppCVar6;
  uVar2 = MC_grpGetPixelFromRGB(0xff,0xff,0xff);
  CGsGraphics::ClearScreen(pCVar7,uVar2);
  pCVar7 = *ppCVar6;
  uVar9 = *(undefined4 *)(pCVar7 + 0x48);
  iVar4 = (*(int *)(pCVar7 + 0x3c) + *(int *)(pCVar7 + 0x4c)) * 0x10000 >> 0x10;
  uVar2 = MC_grpGetPixelFromRGB(0x93,0xcf,0x2b);
  iVar10 = (int)(short)uVar9;
  CGsGraphics::DrawFillRect(pCVar7,0,0,iVar10,iVar4,uVar2);
  pCVar7 = *ppCVar6;
  uVar2 = MC_grpGetPixelFromRGB(0x72,0xb2,3);
  CGsGraphics::DrawRect(pCVar7,1,0,iVar10 + -2,iVar4 + -1,uVar2);
  pCVar7 = *ppCVar6;
  uVar2 = MC_grpGetPixelFromRGB(0xff,0xff,0xff);
  CGsGraphics::DrawFillRect(pCVar7,2,0x14,iVar10 + -4,iVar4 + -0x16,uVar2);
  pCVar7 = *ppCVar6;
  uVar2 = MC_grpGetPixelFromRGB(0x81,0xc1,0x11);
  CGsGraphics::DrawFillRect(pCVar7,2,1,iVar10 + -4,0x12,uVar2);
  pCVar7 = *ppCVar6;
  uVar2 = MC_grpGetPixelFromRGB(0x91,0xd3,0x1d);
  CGsGraphics::DrawFillRect(pCVar7,3,2,iVar10 + -6,0x10,uVar2);
  pCVar7 = *ppCVar6;
  uVar2 = MC_grpGetPixelFromRGB(0x9f,0xe1,0x2b);
  CGsGraphics::DrawFillRect(pCVar7,3,2,iVar10 + -7,8,uVar2);
  pcVar8 = *(char **)(iVar5 + DAT_00173604);
  iVar10 = iVar5 + DAT_00173608;
  MC_knlSprintk(pcVar8,iVar10,iVar5 + DAT_0017360c);
  pCVar7 = *ppCVar6;
  iVar4 = *(int *)(pCVar7 + 0x3c) + *(int *)(pCVar7 + 0x4c) >> 1;
  DrawTextBBF(pcVar8,0,(iVar4 + -10) -
                       (iVar4 - (*(int *)(pCVar7 + 0x3c) + *(int *)(pCVar7 + 0x4c) >> 0x1f) >> 1),
              *(int *)(pCVar7 + 0x48),0xffffffff,'\0');
  memset(acStack_6c,0,0x40);
  __aeabi_idivmod(*(undefined4 *)(in_r0 + 0x1c),10);
  if (extraout_r1 < 6) {
    MC_knlSprintk(acStack_6c,iVar10,iVar5 + DAT_00173618);
  }
  else {
    MC_knlSprintk(acStack_6c,iVar10,iVar5 + DAT_00173610);
  }
  iVar10 = **(int **)(iVar5 + iVar3);
  iVar3 = *(int *)(iVar10 + 0x3c) + *(int *)(iVar10 + 0x4c);
  iVar4 = iVar3 >> 1;
  DrawTextBBF(acStack_6c,0,(iVar4 - (iVar3 >> 0x1f) >> 1) + iVar4,*(int *)(iVar10 + 0x48),0xffffffff
              ,'\0');
  CGsTouchMgr::SetAllScreenTouch();
  if (local_2c == **(int **)(iVar5 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


