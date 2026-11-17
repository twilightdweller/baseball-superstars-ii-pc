/* CBBGMenuRun::EVENT_HANDLER_MSTATE_MISSION_MODE at 0016d1a0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_MISSION_MODE() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_MISSION_MODE(void)

{
  char cVar1;
  CPopup CVar2;
  int iVar3;
  int in_r0;
  CPopup *this;
  char *pcVar4;
  CBBGPopup *pCVar5;
  CGxPZxFrame *pCVar6;
  CGxPZxFrame *pCVar7;
  CPopup *pCVar8;
  int iVar9;
  int iVar10;
  CPopup **ppCVar11;
  int iVar12;
  CBBGResMgr **ppCVar13;
  CBBGPopup **ppCVar14;
  
  iVar10 = DAT_0016d378 + 0x16d1b2;
  CBBGDataMgr::GetOption();
  iVar9 = DAT_0016d384;
  cVar1 = **(char **)(iVar10 + DAT_0016d380);
  if (*(int *)(in_r0 + 8) != 0) {
    if (*(int *)(in_r0 + 8) != 1) {
      return;
    }
    if (cVar1 == '\0') {
      *(undefined4 *)(in_r0 + 100) = 6;
      CBBGCommonMenu::InitHallOfFame((uchar)*(undefined4 *)(in_r0 + 0x6c),'\0');
      iVar9 = DAT_0016d384;
      if (*(char *)(*(int *)(in_r0 + 0x6c) + DAT_0016d39c) != '\0') goto LAB_0016d33c;
      *(undefined4 *)(in_r0 + 8) = 0;
      ppCVar14 = *(CBBGPopup ***)(iVar10 + iVar9);
      pCVar5 = *ppCVar14;
    }
    else {
      if (cVar1 != '\x01') {
        if (cVar1 != -1) {
          return;
        }
        *(undefined4 *)(in_r0 + 8) = 0;
        CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
        return;
      }
      *(undefined4 *)(in_r0 + 100) = 5;
      CBBGCommonMenu::InitHallOfFame((uchar)*(undefined4 *)(in_r0 + 0x6c),'\x01');
      iVar9 = DAT_0016d384;
      if (*(char *)(*(int *)(in_r0 + 0x6c) + DAT_0016d39c) != '\0') {
LAB_0016d33c:
        CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
        return;
      }
      *(undefined4 *)(in_r0 + 8) = 0;
      ppCVar14 = *(CBBGPopup ***)(iVar10 + iVar9);
      pCVar5 = *ppCVar14;
    }
    pcVar4 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar10 + DAT_0016d388),0x36,0xeb);
    CBBGPopup::CreatePopup(pCVar5,pcVar4,'\x01',(short)DAT_0016d3a0,'\0',(char **)0x0,0,0);
    CBBGPopup::SetTitle((char *)*ppCVar14,iVar10 + DAT_0016d3a4);
    CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
    return;
  }
  pCVar5 = **(CBBGPopup ***)(iVar10 + DAT_0016d384);
  ppCVar13 = *(CBBGResMgr ***)(iVar10 + DAT_0016d388);
  pcVar4 = (char *)CBBGResMgr::GetStr(*ppCVar13,0x36,1);
  CBBGPopup::CreatePopup(pCVar5,pcVar4,'\x10',0x15b,'\0',(char **)0x0,2,1);
  pcVar4 = (char *)CBBGResMgr::GetGameCodeStr(*ppCVar13,0x26);
  iVar3 = DAT_0016d38c;
  ppCVar11 = *(CPopup ***)(iVar10 + DAT_0016d38c);
  if (*ppCVar11 != (CPopup *)0x0) {
    CPopup::SetTitle(*ppCVar11,pcVar4,2);
    iVar12 = DAT_0016d390;
    pCVar8 = *ppCVar11;
    if (pCVar8 != (CPopup *)0x0) {
      *(undefined4 *)(pCVar8 + ((char)pCVar8[DAT_0016d390] + DAT_0016d394) * 4) = 0xfffffff0;
      CVar2 = pCVar8[iVar12];
      pCVar8[DAT_0016d398 + (char)CVar2 + 4] = (CPopup)0xff;
      pCVar8[iVar12] = (CPopup)((char)CVar2 + '\x01');
      pCVar8 = *ppCVar11;
      goto LAB_0016d24c;
    }
  }
  pCVar8 = (CPopup *)0x0;
LAB_0016d24c:
  iVar12 = *(int *)(**(int **)(iVar10 + iVar9) + 4);
  iVar9 = *(int *)(iVar12 + 0xc);
  if (iVar9 == 0) {
    pCVar7 = (CGxPZxFrame *)0x0;
    pCVar6 = pCVar7;
  }
  else {
    pCVar7 = *(CGxPZxFrame **)(*(int *)(iVar9 + 8) + 0x48);
    pCVar6 = *(CGxPZxFrame **)(*(int *)(iVar9 + 8) + 0x40);
  }
  this = (CPopup *)0x0;
  if (pCVar8 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar8,pCVar7,pCVar6,'\0');
    iVar9 = *(int *)(iVar12 + 0xc);
    this = **(CPopup ***)(iVar10 + iVar3);
  }
  if (iVar9 == 0) {
    pCVar6 = (CGxPZxFrame *)0x0;
    pCVar7 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar6 = *(CGxPZxFrame **)(*(int *)(iVar9 + 8) + 0x4c);
    pCVar7 = *(CGxPZxFrame **)(*(int *)(iVar9 + 8) + 0x44);
  }
  if (this != (CPopup *)0x0) {
    CPopup::AddButton(this,pCVar6,pCVar7,'\0');
    ppCVar11 = *(CPopup ***)(iVar10 + iVar3);
    pCVar8 = *ppCVar11;
    if ((pCVar8 != (CPopup *)0x0) &&
       (CPopup::SetButtonDist(pCVar8,0x28,0), *ppCVar11 != (CPopup *)0x0)) {
      CPopup::NowArrangeButton();
    }
  }
  *(undefined4 *)(in_r0 + 8) = 1;
  return;
}


