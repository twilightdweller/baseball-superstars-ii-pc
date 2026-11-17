/* CBBGCommonMenu::DrawCaptureTitle at 0012de34; decompiler output, not buildable source */

/* CBBGCommonMenu::DrawCaptureTitle(unsigned char, unsigned char) */

undefined4 __thiscall
CBBGCommonMenu::DrawCaptureTitle(CBBGCommonMenu *this,uchar param_1,uchar param_2)

{
  CGxPZxMgr *pCVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  CGsGraphics *this_00;
  undefined4 uVar6;
  int iVar7;
  long *plVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  CBBGScreenMng **ppCVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  
  iVar4 = DAT_0012e090;
  iVar7 = DAT_0012e08c + 0x12de4a;
  this_00 = **(CGsGraphics ***)(iVar7 + DAT_0012e090);
  if (param_1 == '\0') {
    if (this[0x58] == (CBBGCommonMenu)0x0) {
      pCVar1 = (CGxPZxMgr *)CBBGResMgr::GetPZxMgr(**(CBBGResMgr ***)(iVar7 + DAT_0012e094),0x11);
      uVar6 = 1;
      if (pCVar1 != (CGxPZxMgr *)0x0) {
        DrawPZX(pCVar1,0,0,0,0,0,0,'\0','\x01');
        uVar6 = 1;
      }
    }
    else {
      CBBGScreenMng::DrawBackupScreen
                (**(CBBGScreenMng ***)(iVar7 + DAT_0012e098),*(long **)(iVar7 + DAT_0012e09c));
      uVar6 = 1;
    }
  }
  else {
    pCVar1 = (CGxPZxMgr *)CBBGResMgr::GetPZxMgr(**(CBBGResMgr ***)(iVar7 + DAT_0012e094),0x11);
    if (pCVar1 != (CGxPZxMgr *)0x0) {
      DrawPZX(pCVar1,0,0,0,0,0,0,'\0','\x01');
    }
    if (param_2 != '\0') {
      iVar13 = **(int **)(iVar7 + iVar4);
      iVar10 = *(int *)(iVar13 + 0x3c) + *(int *)(iVar13 + 0x4c);
      iVar2 = __aeabi_idiv(iVar10 * 0x23,100);
      iVar10 = __aeabi_idiv(iVar10 * 0x4b,100);
      iVar3 = __aeabi_idiv(0x100,iVar2);
      uVar14 = DAT_0012e0a0;
      if (-1 < iVar2) {
        iVar11 = 0x100;
        iVar15 = iVar2;
        while( true ) {
          iVar11 = iVar11 - (iVar3 + 1);
          if (iVar11 < 1) {
            iVar11 = 1;
            uVar5 = DAT_0012e0a4;
          }
          else {
            uVar5 = iVar11 * 0x1000000 | uVar14;
          }
          iVar13 = *(int *)(iVar13 + 0x48) >> 1;
          CGsGraphics::DrawLine(this_00,iVar13 + -0xa0,iVar15,iVar13 + 0xa0,iVar15,uVar5);
          iVar15 = iVar15 + -1;
          if (iVar15 < 0) break;
          iVar13 = **(int **)(iVar7 + iVar4);
        }
        iVar13 = **(int **)(iVar7 + iVar4);
      }
      iVar15 = 0x100;
      while( true ) {
        iVar15 = iVar15 - (iVar3 + 1);
        if (iVar15 < 1) {
          iVar15 = 1;
          uVar14 = DAT_0012e0a4;
        }
        else {
          uVar14 = iVar15 * 0x1000000 | DAT_0012e0a0;
        }
        iVar13 = *(int *)(iVar13 + 0x48) >> 1;
        CGsGraphics::DrawLine(this_00,iVar13 + -0xa0,iVar2,iVar13 + 0xa0,iVar2,uVar14);
        if (iVar10 + 0x1b <= iVar2 + 1) break;
        iVar13 = **(int **)(iVar7 + iVar4);
        iVar2 = iVar2 + 1;
      }
      iVar3 = *(int *)(**(int **)(iVar7 + iVar4) + 0x48);
      iVar13 = iVar3 >> 1;
      iVar2 = __aeabi_idiv(0x100,iVar13);
      if (0 < iVar13) {
        iVar15 = 0;
        iVar11 = 0x100;
        do {
          iVar11 = iVar11 - (iVar2 + 1);
          if (iVar11 < 1) {
            iVar11 = 1;
            uVar14 = DAT_0012e0ac;
          }
          else {
            uVar14 = iVar11 * 0x1000000 | 0xa0;
          }
          CGsGraphics::DrawLine
                    (this_00,iVar13 - iVar15,iVar10 + 0x28,iVar13 - iVar15,iVar10 + 0x3c,uVar14);
          piVar9 = *(int **)(iVar7 + iVar4);
          iVar3 = iVar15 + (*(int *)(*piVar9 + 0x48) >> 1);
          CGsGraphics::DrawLine(this_00,iVar3,iVar10 + 0x28,iVar3,iVar10 + 0x3c,uVar14);
          iVar15 = iVar15 + 1;
          iVar3 = *(int *)(*piVar9 + 0x48);
          iVar13 = iVar3 >> 1;
        } while (iVar15 < iVar13);
      }
      CGsGraphics::DrawFillRect(this_00,0,iVar10 + -0x15,iVar3,0x30,DAT_0012e0a8);
    }
    ppCVar12 = *(CBBGScreenMng ***)(iVar7 + DAT_0012e098);
    plVar8 = *(long **)(iVar7 + DAT_0012e09c);
    iVar4 = CBBGScreenMng::CreateBackupScreen(*ppCVar12,plVar8);
    this[0x58] = SUB41(iVar4,0);
    uVar6 = 0;
    if (iVar4 != 0) {
      CBBGScreenMng::DrawBackupScreen(*ppCVar12,plVar8);
      uVar6 = 1;
    }
  }
  return uVar6;
}


