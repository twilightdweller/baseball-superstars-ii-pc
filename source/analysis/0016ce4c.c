/* CBBGMenuRun::INIT_HANDLER_MSTATE_MENU_LEADERBOARD at 0016ce4c; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_MENU_LEADERBOARD() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_MENU_LEADERBOARD(void)

{
  CPopup CVar1;
  int iVar2;
  char *pcVar3;
  CPopup *pCVar4;
  CGxPZxFrame *pCVar5;
  CPopup *pCVar6;
  CGxPZxFrame *pCVar7;
  int iVar8;
  int iVar9;
  CBBGDataMgr **ppCVar10;
  CBBGResMgr **ppCVar11;
  CBBGPopup *this;
  CPopup **ppCVar12;
  int iVar13;
  
  iVar9 = DAT_0016d098 + 0x16ce5c;
  ppCVar10 = *(CBBGDataMgr ***)(iVar9 + DAT_0016d09c);
  CBBGDataMgr::Open(*ppCVar10,2,'\x01');
  CBBGDataMgr::Open(*ppCVar10,4,'\x01');
  CBBGDataMgr::Open(*ppCVar10,3,'\x01');
  CBBGDataMgr::GetRaiseMode(*ppCVar10,4);
  CBBGDataMgr::GetRaiseMode(*ppCVar10,3);
  CBBGDataMgr::GetSeasonMode();
  CBBGDataMgr::GetOption();
  CBBGDataMgr::GetOption();
  CBBGDataMgr::GetOption();
  CBBGDataMgr::GetOption();
  iVar13 = DAT_0016d0a0;
  CBBGDataMgr::Close((eGameMode)*ppCVar10,'\x02');
  CBBGDataMgr::Close((eGameMode)*ppCVar10,'\x04');
  CBBGDataMgr::Close((eGameMode)*ppCVar10,'\x03');
  this = **(CBBGPopup ***)(iVar9 + iVar13);
  ppCVar11 = *(CBBGResMgr ***)(iVar9 + DAT_0016d0a4);
  pcVar3 = (char *)CBBGResMgr::GetStr(*ppCVar11,0x36,0);
  CBBGPopup::CreatePopupType(this,pcVar3,'\x10',0x15b,'\0',(char **)0x0,1,6,4);
  pcVar3 = (char *)CBBGResMgr::GetGameCodeStr(*ppCVar11,0x24);
  iVar2 = DAT_0016d0a8;
  ppCVar12 = *(CPopup ***)(iVar9 + DAT_0016d0a8);
  if (*ppCVar12 != (CPopup *)0x0) {
    CPopup::SetTitle(*ppCVar12,pcVar3,2);
    iVar8 = DAT_0016d0ac;
    pCVar6 = *ppCVar12;
    if (pCVar6 != (CPopup *)0x0) {
      *(undefined4 *)(pCVar6 + ((char)pCVar6[DAT_0016d0ac] + DAT_0016d0b0) * 4) = 0xfffffff0;
      CVar1 = pCVar6[iVar8];
      pCVar6[DAT_0016d0b4 + (char)CVar1 + 4] = (CPopup)0xff;
      pCVar6[iVar8] = (CPopup)((char)CVar1 + '\x01');
      pCVar6 = *ppCVar12;
      iVar13 = *(int *)(**(int **)(iVar9 + iVar13) + 4);
      iVar8 = *(int *)(iVar13 + 0xc);
      goto joined_r0x0016cf5a;
    }
  }
  pCVar6 = (CPopup *)0x0;
  iVar13 = *(int *)(**(int **)(iVar9 + iVar13) + 4);
  iVar8 = *(int *)(iVar13 + 0xc);
joined_r0x0016cf5a:
  if (iVar8 == 0) {
    pCVar5 = (CGxPZxFrame *)0x0;
    pCVar7 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar5 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x21c);
    pCVar7 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x234);
  }
  pCVar4 = (CPopup *)0x0;
  if (pCVar6 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar6,pCVar5,pCVar7,'\0');
    iVar8 = *(int *)(iVar13 + 0xc);
    pCVar4 = **(CPopup ***)(iVar9 + iVar2);
  }
  if (iVar8 == 0) {
    pCVar5 = (CGxPZxFrame *)0x0;
    pCVar7 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar5 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x220);
    pCVar7 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x238);
  }
  pCVar6 = (CPopup *)0x0;
  if (pCVar4 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar4,pCVar5,pCVar7,'\0');
    iVar8 = *(int *)(iVar13 + 0xc);
    pCVar6 = **(CPopup ***)(iVar9 + iVar2);
  }
  if (iVar8 == 0) {
    pCVar5 = (CGxPZxFrame *)0x0;
    pCVar7 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar5 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x224);
    pCVar7 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x23c);
  }
  pCVar4 = (CPopup *)0x0;
  if (pCVar6 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar6,pCVar5,pCVar7,'\0');
    iVar8 = *(int *)(iVar13 + 0xc);
    pCVar4 = **(CPopup ***)(iVar9 + iVar2);
  }
  if (iVar8 == 0) {
    pCVar5 = (CGxPZxFrame *)0x0;
    pCVar7 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar5 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x228);
    pCVar7 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x240);
  }
  pCVar6 = (CPopup *)0x0;
  if (pCVar4 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar4,pCVar5,pCVar7,'\0');
    iVar8 = *(int *)(iVar13 + 0xc);
    pCVar6 = **(CPopup ***)(iVar9 + iVar2);
  }
  if (iVar8 == 0) {
    pCVar5 = (CGxPZxFrame *)0x0;
    pCVar7 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar5 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x22c);
    pCVar7 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x244);
  }
  pCVar4 = (CPopup *)0x0;
  if (pCVar6 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar6,pCVar5,pCVar7,'\0');
    iVar8 = *(int *)(iVar13 + 0xc);
    pCVar4 = **(CPopup ***)(iVar9 + iVar2);
  }
  if (iVar8 == 0) {
    pCVar5 = (CGxPZxFrame *)0x0;
    pCVar7 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar5 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x230);
    pCVar7 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x248);
  }
  if (pCVar4 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar4,pCVar5,pCVar7,'\0');
    ppCVar12 = *(CPopup ***)(iVar9 + iVar2);
    if ((*ppCVar12 != (CPopup *)0x0) &&
       (CPopup::SetButtonDist(*ppCVar12,0x3c,10), *ppCVar12 != (CPopup *)0x0)) {
      CPopup::NowArrangeButton();
      if (*ppCVar12 != (CPopup *)0x0) {
        CPopup::SetInitFocus(*ppCVar12,0);
      }
    }
  }
  return;
}


