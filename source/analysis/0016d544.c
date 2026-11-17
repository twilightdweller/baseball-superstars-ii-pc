/* CBBGMenuRun::EVENT_HANDLER_MSTATE_TOURMENT_MODE at 0016d544; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_TOURMENT_MODE() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_TOURMENT_MODE(void)

{
  char cVar1;
  CPopup CVar2;
  int iVar3;
  int in_r0;
  int iVar4;
  CPopup *pCVar5;
  CGxPZxFrame *pCVar6;
  CGxPZxFrame *pCVar7;
  char *pcVar8;
  CBBGPopup *pCVar9;
  int iVar10;
  CBBGResMgr **ppCVar11;
  CPopup **ppCVar12;
  int iVar13;
  CBBGPopup **ppCVar14;
  
  iVar10 = DAT_0016d78c + 0x16d556;
  iVar4 = CBBGDataMgr::GetOption();
  iVar13 = DAT_0016d79c;
  cVar1 = **(char **)(iVar10 + DAT_0016d794);
  if (*(int *)(in_r0 + 8) == 0) {
    if (*(char *)(iVar4 + 0x8e) == '\0') {
      ppCVar11 = *(CBBGResMgr ***)(iVar10 + DAT_0016d79c);
      pCVar9 = **(CBBGPopup ***)(iVar10 + DAT_0016d798);
      pcVar8 = (char *)CBBGResMgr::GetStr(*ppCVar11,0x36,0xba);
      CBBGPopup::CreatePopup(pCVar9,pcVar8,'\x10',0x15b,'\0',(char **)0x0,2,1);
      pcVar8 = (char *)CBBGResMgr::GetGameCodeStr(*ppCVar11,DAT_0016d7a0);
      iVar4 = DAT_0016d7a4;
      ppCVar12 = *(CPopup ***)(iVar10 + DAT_0016d7a4);
      pCVar5 = *ppCVar12;
      if (pCVar5 != (CPopup *)0x0) {
        CPopup::SetTitle(pCVar5,pcVar8,2);
        iVar3 = DAT_0016d7a8;
        pCVar5 = *ppCVar12;
        if (pCVar5 != (CPopup *)0x0) {
          *(undefined4 *)(pCVar5 + ((char)pCVar5[DAT_0016d7a8] + DAT_0016d7ac) * 4) = 0xfffffff0;
          CVar2 = pCVar5[iVar3];
          pCVar5[DAT_0016d7b0 + (char)CVar2 + 4] = (CPopup)0xff;
          pCVar5[iVar3] = (CPopup)((char)CVar2 + '\x01');
        }
      }
      ppCVar11 = *(CBBGResMgr ***)(iVar10 + iVar13);
      pCVar6 = (CGxPZxFrame *)CBBGResMgr::GetFrame(*ppCVar11,0x12,0x22);
      pCVar7 = (CGxPZxFrame *)CBBGResMgr::GetFrame(*ppCVar11,0x12,0x24);
      pCVar5 = **(CPopup ***)(iVar10 + iVar4);
      if (pCVar5 != (CPopup *)0x0) {
        CPopup::AddButton(pCVar5,pCVar6,pCVar7,'\0');
      }
      ppCVar11 = *(CBBGResMgr ***)(iVar10 + iVar13);
      pCVar6 = (CGxPZxFrame *)CBBGResMgr::GetFrame(*ppCVar11,0x12,0x23);
      pCVar7 = (CGxPZxFrame *)CBBGResMgr::GetFrame(*ppCVar11,0x12,0x25);
      ppCVar12 = *(CPopup ***)(iVar10 + iVar4);
      if (*ppCVar12 != (CPopup *)0x0) {
        CPopup::AddButton(*ppCVar12,pCVar6,pCVar7,'\0');
        if ((*ppCVar12 != (CPopup *)0x0) &&
           (CPopup::SetButtonDist(*ppCVar12,0x14,0), *ppCVar12 != (CPopup *)0x0)) {
          CPopup::NowArrangeButton();
        }
      }
      *(undefined4 *)(in_r0 + 8) = 1;
    }
    else {
      *(undefined4 *)(in_r0 + 100) = 10;
      CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
    }
  }
  else if (*(int *)(in_r0 + 8) == 1) {
    if (cVar1 == '\0') {
      iVar13 = CBBGDataMgr::GetOption();
      if (*(char *)(iVar13 + 0x86) != '\0') {
        *(undefined4 *)(in_r0 + 100) = 10;
        *(undefined *)(*(int *)(in_r0 + 0x6c) + DAT_0016d7b4) = 1;
        CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
        return;
      }
      ppCVar14 = *(CBBGPopup ***)(iVar10 + DAT_0016d798);
      pCVar9 = *ppCVar14;
      pcVar8 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar10 + DAT_0016d79c),0x36,0xbb);
      CBBGPopup::CreatePopup(pCVar9,pcVar8,'\x01',(short)DAT_0016d7b8,'\0',(char **)0x0,0,0);
      CBBGPopup::SetTitle((char *)*ppCVar14,iVar10 + DAT_0016d7bc);
      CBBGPopup::SetAutoClose();
    }
    else {
      if (cVar1 == '\x01') {
        iVar13 = 0;
        while (((iVar13 == 9 || (iVar13 == 4)) ||
               (iVar4 = CBBGDataMgr::GetOption(), *(char *)(iVar4 + iVar13 + 200) == '\0'))) {
          iVar13 = iVar13 + 1;
          if (iVar13 == 10) {
            ppCVar14 = *(CBBGPopup ***)(iVar10 + DAT_0016d798);
            pCVar9 = *ppCVar14;
            pcVar8 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar10 + DAT_0016d79c),0x36,0xbc)
            ;
            CBBGPopup::CreatePopup(pCVar9,pcVar8,'\x01',(short)DAT_0016d7b8,'\0',(char **)0x0,0,0);
            CBBGPopup::SetTitle((char *)*ppCVar14,iVar10 + DAT_0016d7bc);
            CBBGPopup::SetAutoClose();
            *(undefined4 *)(in_r0 + 8) = 0;
            CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
            return;
          }
        }
        *(undefined4 *)(in_r0 + 100) = 10;
        *(undefined *)(*(int *)(in_r0 + 0x6c) + DAT_0016d7b4) = 0;
        CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
        return;
      }
      if (cVar1 != -1) {
        return;
      }
    }
    *(undefined4 *)(in_r0 + 8) = 0;
    CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
  }
  return;
}


