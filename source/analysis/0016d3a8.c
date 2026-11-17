/* CBBGMenuRun::EVENT_HANDLER_MSTATE_RAISE_MODE at 0016d3a8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_RAISE_MODE() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_RAISE_MODE(void)

{
  char cVar1;
  CPopup CVar2;
  int iVar3;
  int in_r0;
  char *pcVar4;
  CPopup *this;
  CGxPZxFrame *pCVar5;
  CGxPZxFrame *pCVar6;
  CBBGPopup *this_00;
  CPopup *pCVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  CPopup **ppCVar11;
  int iVar12;
  CBBGResMgr **ppCVar13;
  
  iVar10 = DAT_0016d520 + 0x16d3ba;
  CBBGDataMgr::GetOption();
  iVar8 = DAT_0016d52c;
  cVar1 = **(char **)(iVar10 + DAT_0016d528);
  if (*(int *)(in_r0 + 8) != 0) {
    if (*(int *)(in_r0 + 8) != 1) {
      return;
    }
    if (cVar1 == '\0') {
      uVar9 = 4;
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
      uVar9 = 3;
    }
    *(undefined4 *)(in_r0 + 100) = uVar9;
    CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
    return;
  }
  this_00 = **(CBBGPopup ***)(iVar10 + DAT_0016d52c);
  ppCVar13 = *(CBBGResMgr ***)(iVar10 + DAT_0016d530);
  pcVar4 = (char *)CBBGResMgr::GetStr(*ppCVar13,0x36,1);
  CBBGPopup::CreatePopup(this_00,pcVar4,'\x10',0x15b,'\0',(char **)0x0,2,1);
  pcVar4 = (char *)CBBGResMgr::GetGameCodeStr(*ppCVar13,0x10c);
  iVar3 = DAT_0016d534;
  ppCVar11 = *(CPopup ***)(iVar10 + DAT_0016d534);
  if (*ppCVar11 != (CPopup *)0x0) {
    CPopup::SetTitle(*ppCVar11,pcVar4,2);
    iVar12 = DAT_0016d538;
    pCVar7 = *ppCVar11;
    if (pCVar7 != (CPopup *)0x0) {
      *(undefined4 *)(pCVar7 + ((char)pCVar7[DAT_0016d538] + DAT_0016d53c) * 4) = 0xfffffff0;
      CVar2 = pCVar7[iVar12];
      pCVar7[DAT_0016d540 + (char)CVar2 + 4] = (CPopup)0xff;
      pCVar7[iVar12] = (CPopup)((char)CVar2 + '\x01');
      pCVar7 = *ppCVar11;
      goto LAB_0016d456;
    }
  }
  pCVar7 = (CPopup *)0x0;
LAB_0016d456:
  iVar12 = *(int *)(**(int **)(iVar10 + iVar8) + 4);
  iVar8 = *(int *)(iVar12 + 0xc);
  if (iVar8 == 0) {
    pCVar5 = (CGxPZxFrame *)0x0;
    pCVar6 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar5 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x48);
    pCVar6 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x40);
  }
  this = (CPopup *)0x0;
  if (pCVar7 != (CPopup *)0x0) {
    CPopup::AddButton(pCVar7,pCVar5,pCVar6,'\0');
    iVar8 = *(int *)(iVar12 + 0xc);
    this = **(CPopup ***)(iVar10 + iVar3);
  }
  if (iVar8 == 0) {
    pCVar5 = (CGxPZxFrame *)0x0;
    pCVar6 = (CGxPZxFrame *)0x0;
  }
  else {
    pCVar5 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x4c);
    pCVar6 = *(CGxPZxFrame **)(*(int *)(iVar8 + 8) + 0x44);
  }
  if (this != (CPopup *)0x0) {
    CPopup::AddButton(this,pCVar5,pCVar6,'\0');
    ppCVar11 = *(CPopup ***)(iVar10 + iVar3);
    pCVar7 = *ppCVar11;
    if ((pCVar7 != (CPopup *)0x0) &&
       (CPopup::SetButtonDist(pCVar7,0x2d,10), *ppCVar11 != (CPopup *)0x0)) {
      CPopup::NowArrangeButton();
    }
  }
  if ((*(int *)(in_r0 + 100) == 3) && (**(CPopup ***)(iVar10 + iVar3) != (CPopup *)0x0)) {
    CPopup::SetInitFocus(**(CPopup ***)(iVar10 + iVar3),1);
  }
  *(undefined4 *)(in_r0 + 8) = 1;
  return;
}


