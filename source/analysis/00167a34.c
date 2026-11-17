/* CBBGMenuRun::DrawNetIdAutomataCB at 00167a34; decompiler output, not buildable source */

/* CBBGMenuRun::DrawNetIdAutomataCB(void*) */

void CBBGMenuRun::DrawNetIdAutomataCB(void *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  CBBGCommonMenu *this;
  CGxPZxMgr *pCVar6;
  int iVar7;
  int iVar8;
  CBBGResMgr **ppCVar9;
  int iVar10;
  int iVar11;
  CGsTouchMgr **ppCVar12;
  int iVar13;
  int iVar14;
  CGxPZxMgr aCStack_30 [4];
  short local_2c;
  short sStack_2a;
  
  iVar8 = DAT_00167bdc + 0x167a4a;
  this = **(CBBGCommonMenu ***)(iVar8 + DAT_00167be0);
  ppCVar9 = *(CBBGResMgr ***)(iVar8 + DAT_00167be4);
  pcVar2 = (char *)CBBGResMgr::GetStr(*ppCVar9,0x36,0x2f);
  CBBGResMgr::GetPZxMgr(*ppCVar9,0x14);
  iVar1 = DAT_00167bec;
  iVar7 = DAT_00167be8;
  iVar10 = *(int *)(**(int **)(iVar8 + DAT_00167be8) + 4);
  iVar11 = *(int *)(**(int **)(iVar8 + DAT_00167bec) + 0x3c) +
           *(int *)(**(int **)(iVar8 + DAT_00167bec) + 0x4c) >> 1;
  iVar3 = CBBGDataMgr::GetOption();
  iVar14 = 0x18;
  if (*(int *)(iVar3 + 0x48) != 1) {
    iVar14 = 0x1f;
  }
  iVar13 = *(int *)(**(int **)(iVar8 + iVar1) + 0x48) >> 1;
  uVar4 = MC_grpGetPixelFromRGB(0xff,0xff,0xff);
  DrawTextBBF(pcVar2,iVar13 + -0xa3,(iVar11 + -0xd) - iVar14,0x147,uVar4,'\0');
  iVar3 = *(int *)(iVar10 + 0xc);
  piVar5 = (int *)0x0;
  if (iVar3 != 0) {
    piVar5 = *(int **)(*(int *)(iVar3 + 8) + 0x1f0);
  }
  iVar10 = (int)(short)((short)iVar13 + -100);
  iVar11 = (int)(short)((short)iVar11 + 5);
  (**(code **)(*piVar5 + 0x10))(piVar5,iVar10,iVar11 + -3,0,0,0);
  iVar3 = MC_grpGetPixelFromRGB(0xff,0xff,0xff);
  CBBGCommonMenu::DrawAutomataWindow(this,iVar10 + 100,iVar11 + 3,iVar3,'\x01',0x12);
  ppCVar12 = *(CGsTouchMgr ***)(iVar8 + DAT_00167bf4);
  CGsTouchMgr::AddKeyTouchRect(*ppCVar12,0x23,iVar10 + -5,iVar11 + -5,0xd3,0x19);
  if ((*ppCVar12)[DAT_00167bf8] != (CGsTouchMgr)0x0) {
    pCVar6 = *(CGxPZxMgr **)(**(int **)(iVar8 + iVar7) + 4);
    GetPzxSize(aCStack_30,(int)pCVar6,0xc);
    piVar5 = *(int **)(iVar8 + iVar1);
    iVar7 = (int)local_2c / 2;
    DrawPZX(pCVar6,0xc,1,(*(int *)(*piVar5 + 0x48) >> 1) - iVar7,iVar11 + 0x25,0,0,'\0','\x01');
    CGsTouchMgr::AddKeyTouchRect
              (*ppCVar12,-5,((*(int *)(*piVar5 + 0x48) >> 1) + -5) - iVar7,iVar11 + 0x20,
               local_2c + 10,sStack_2a + 10);
  }
  return;
}


