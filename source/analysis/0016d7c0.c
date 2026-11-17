/* CBBGMenuRun::EVENT_HANDLER_MSTATE_NORMAL_MODE at 0016d7c0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_NORMAL_MODE() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_NORMAL_MODE(void)

{
  char cVar1;
  CPopup CVar2;
  uchar uVar3;
  CBBGMenuRun *in_r0;
  int iVar4;
  char *pcVar5;
  CPopup *pCVar6;
  int iVar7;
  CGxPZxFrame *pCVar8;
  CGxPZxFrame *pCVar9;
  CBBGPopup *pCVar10;
  int iVar11;
  int iVar12;
  CBBGResMgr **ppCVar13;
  CPopup **ppCVar14;
  int iVar15;
  CBBGPopup **ppCVar16;
  CPopup *this;
  
  iVar12 = DAT_0016dacc + 0x16d7d4;
  iVar4 = CBBGDataMgr::GetOption();
  iVar7 = DAT_0016daf0;
  iVar11 = DAT_0016dad8;
  iVar15 = *(int *)(in_r0 + 8);
  cVar1 = **(char **)(iVar12 + DAT_0016dad4);
  uVar3 = (uchar)iVar15;
  if (iVar15 == 1) {
    if (cVar1 == '\0') {
      iVar7 = CBBGDataMgr::GetOption();
      iVar11 = DAT_0016daf0;
      if (*(char *)(iVar7 + 0x91) == '\0') {
        *(undefined4 *)(in_r0 + 100) = 1;
        **(undefined4 **)(iVar12 + iVar11) = 1;
        *(undefined4 *)(**(int **)(iVar12 + DAT_0016daf4) + 4) = 1;
        SetChangeRunnable(in_r0,0x102);
        return;
      }
      *(undefined4 *)(in_r0 + 100) = 1;
      CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
      return;
    }
    if (cVar1 == '\x01') {
      iVar7 = CBBGDataMgr::GetOption();
      iVar11 = DAT_0016dbdc;
      if (*(char *)(iVar7 + 0x91) == '\0') {
        *(undefined4 *)(in_r0 + 100) = 1;
        **(undefined4 **)(iVar12 + iVar11) = 1;
        *(undefined4 *)(**(int **)(iVar12 + DAT_0016dbe0) + 4) = 1;
        SetChangeRunnable(in_r0,0x102);
        return;
      }
      ppCVar16 = *(CBBGPopup ***)(iVar12 + DAT_0016dad8);
      pCVar10 = *ppCVar16;
      ppCVar13 = *(CBBGResMgr ***)(iVar12 + DAT_0016dadc);
      pcVar5 = (char *)CBBGResMgr::GetStr(*ppCVar13,0x36,2);
      CBBGPopup::CreatePopup(pCVar10,pcVar5,0x82,0x15b,'\0',(char **)0x0,0,0);
      pCVar10 = *ppCVar16;
      iVar11 = CBBGResMgr::GetGameCodeStr(*ppCVar13,0x24);
      CBBGPopup::SetTitle((char *)pCVar10,iVar11);
      iVar11 = DAT_0016dae4;
      iVar7 = **(int **)(iVar12 + DAT_0016dae0);
      if (iVar7 != 0) {
        *(undefined4 *)((*(char *)(iVar7 + DAT_0016dae4) + DAT_0016dae8) * 4 + iVar7) = 0xfffffff0;
        cVar1 = *(char *)(iVar7 + iVar11);
        *(undefined *)(iVar7 + cVar1 + DAT_0016daec + 4) = 1;
        *(char *)(iVar7 + iVar11) = cVar1 + '\x01';
      }
      *(undefined4 *)(in_r0 + 8) = 2;
      return;
    }
    if (cVar1 == '\x02') {
      iVar11 = CBBGDataMgr::GetOption();
      if (*(char *)(iVar11 + *(int *)(in_r0 + 100) + 0x90) != '\0') {
        ppCVar16 = *(CBBGPopup ***)(iVar12 + DAT_0016dbc4);
        pCVar10 = *ppCVar16;
        ppCVar13 = *(CBBGResMgr ***)(iVar12 + DAT_0016dbc8);
        pcVar5 = (char *)CBBGResMgr::GetStr(*ppCVar13,0x36,2);
        CBBGPopup::CreatePopup(pCVar10,pcVar5,0x82,0x15b,'\0',(char **)0x0,0,0);
        pCVar10 = *ppCVar16;
        iVar11 = CBBGResMgr::GetGameCodeStr(*ppCVar13,0x24);
        CBBGPopup::SetTitle((char *)pCVar10,iVar11);
        iVar11 = DAT_0016dbd0;
        iVar7 = **(int **)(iVar12 + DAT_0016dbcc);
        if (iVar7 != 0) {
          *(undefined4 *)((*(char *)(iVar7 + DAT_0016dbd0) + DAT_0016dbd4) * 4 + iVar7) = 0xfffffff0
          ;
          cVar1 = *(char *)(iVar7 + iVar11);
          *(uchar *)(iVar7 + cVar1 + DAT_0016dbd8 + 4) = uVar3;
          *(char *)(iVar7 + iVar11) = cVar1 + '\x01';
        }
        *(undefined4 *)(in_r0 + 8) = 3;
        return;
      }
      *(uchar *)(*(int *)(in_r0 + 0x6c) + 0x394) = uVar3;
      iVar11 = DAT_0016dbdc;
      *(undefined4 *)(in_r0 + 100) = 1;
      **(undefined4 **)(iVar12 + iVar11) = 1;
      *(undefined4 *)(**(int **)(iVar12 + DAT_0016dbe0) + 4) = 1;
      SetChangeRunnable(in_r0,0x108);
      return;
    }
    if (cVar1 != -1) {
      return;
    }
LAB_0016d818:
    CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
    return;
  }
  if (1 < iVar15) {
    if (iVar15 == 2) {
      if (cVar1 == '\0') {
        *(undefined4 *)(in_r0 + 100) = 1;
        **(undefined4 **)(iVar12 + iVar7) = 1;
        *(undefined4 *)(**(int **)(iVar12 + DAT_0016daf4) + 4) = 1;
        SetChangeRunnable(in_r0,0x102);
        return;
      }
      if ((cVar1 != -1) && (cVar1 != '\x01')) {
        return;
      }
    }
    else {
      if (iVar15 != 3) {
        return;
      }
      if (cVar1 == '\0') {
        *(undefined *)(*(int *)(in_r0 + 0x6c) + 0x394) = 1;
        iVar11 = DAT_0016daf0;
        *(undefined4 *)(in_r0 + 100) = 1;
        **(undefined4 **)(iVar12 + iVar11) = 1;
        *(undefined4 *)(**(int **)(iVar12 + DAT_0016daf4) + 4) = 1;
        SetChangeRunnable(in_r0,0x108);
        return;
      }
      if ((cVar1 != -1) && (cVar1 != '\x01')) {
        return;
      }
      *(undefined4 *)(in_r0 + 8) = 0;
    }
    goto LAB_0016d818;
  }
  if (iVar15 != 0) {
    return;
  }
  *(uchar *)(*(int *)(in_r0 + 0x6c) + 0x394) = uVar3;
  pCVar10 = **(CBBGPopup ***)(iVar12 + iVar11);
  ppCVar13 = *(CBBGResMgr ***)(iVar12 + DAT_0016dadc);
  pcVar5 = (char *)CBBGResMgr::GetStr(*ppCVar13,0x36,0);
  CBBGPopup::CreatePopupType(pCVar10,pcVar5,'\x10',0x15b,uVar3,(char **)0x0,1,3,1);
  pcVar5 = (char *)CBBGResMgr::GetGameCodeStr(*ppCVar13,0x24);
  iVar7 = DAT_0016dae0;
  ppCVar14 = *(CPopup ***)(iVar12 + DAT_0016dae0);
  if (*ppCVar14 == (CPopup *)0x0) {
LAB_0016da3e:
    pCVar6 = (CPopup *)0x0;
  }
  else {
    CPopup::SetTitle(*ppCVar14,pcVar5,2);
    iVar15 = DAT_0016dae4;
    pCVar6 = *ppCVar14;
    if (pCVar6 == (CPopup *)0x0) goto LAB_0016da3e;
    *(undefined4 *)(pCVar6 + ((char)pCVar6[DAT_0016dae4] + DAT_0016dae8) * 4) = 0xfffffff0;
    CVar2 = pCVar6[iVar15];
    pCVar6[DAT_0016daec + (char)CVar2 + 4] = (CPopup)0xff;
    pCVar6[iVar15] = (CPopup)((char)CVar2 + '\x01');
    pCVar6 = *ppCVar14;
  }
  iVar15 = *(int *)(**(int **)(iVar12 + iVar11) + 4);
  iVar11 = *(int *)(iVar15 + 0xc);
  if (iVar11 == 0) {
    pCVar9 = (CGxPZxFrame *)0x0;
    pCVar8 = pCVar9;
  }
  else {
    pCVar8 = *(CGxPZxFrame **)(*(int *)(iVar11 + 8) + 0x120);
    pCVar9 = *(CGxPZxFrame **)(*(int *)(iVar11 + 8) + 0x11c);
  }
  this = (CPopup *)0x0;
  if (pCVar6 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar6,pCVar8,pCVar9,'\0');
    iVar11 = *(int *)(iVar15 + 0xc);
    this = **(CPopup ***)(iVar12 + iVar7);
  }
  if (iVar11 == 0) {
    pCVar8 = (CGxPZxFrame *)0x0;
    pCVar9 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar8 = *(CGxPZxFrame **)(*(int *)(iVar11 + 8) + 0x128);
    pCVar9 = *(CGxPZxFrame **)(*(int *)(iVar11 + 8) + 0x124);
  }
  pCVar6 = (CPopup *)0x0;
  if (this != (CPopup *)0x0) {
    CPopup::AddButton(this,pCVar8,pCVar9,'\0');
    iVar11 = *(int *)(iVar15 + 0xc);
    pCVar6 = **(CPopup ***)(iVar12 + iVar7);
  }
  if (iVar11 == 0) {
    pCVar8 = (CGxPZxFrame *)0x0;
    pCVar9 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar8 = *(CGxPZxFrame **)(*(int *)(iVar11 + 8) + 0x130);
    pCVar9 = *(CGxPZxFrame **)(*(int *)(iVar11 + 8) + 300);
  }
  if (pCVar6 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar6,pCVar8,pCVar9,'\0');
    ppCVar14 = *(CPopup ***)(iVar12 + iVar7);
    if ((*ppCVar14 != (CPopup *)0x0) &&
       (CPopup::SetButtonDist(*ppCVar14,0x3c,10), *ppCVar14 != (CPopup *)0x0)) {
      CPopup::NowArrangeButton();
      pCVar6 = *ppCVar14;
      goto LAB_0016d9a0;
    }
  }
  pCVar6 = (CPopup *)0x0;
LAB_0016d9a0:
  if ((*(int *)(in_r0 + 0x18) == 0x25) || (*(char *)(iVar4 + 0x91) == '\0')) {
    if (pCVar6 != (CPopup *)0x0) {
      CPopup::SetInitFocus(pCVar6,1);
    }
  }
  else if (pCVar6 != (CPopup *)0x0) {
    CPopup::SetInitFocus(pCVar6,0);
  }
  *(int *)(in_r0 + 8) = *(int *)(in_r0 + 8) + 1;
  return;
}


