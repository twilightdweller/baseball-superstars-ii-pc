/* CBBGMenuRun::EVENT_HANDLER_MSTATE_TITLE at 00169af8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_TITLE() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_TITLE(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  int in_r0;
  CBBGOption *pCVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  CBBGDataMgr **ppCVar10;
  undefined8 uVar11;
  
  iVar9 = DAT_00169c7c + 0x169b0e;
  CBBGResMgr::GetPZxMgr(**(CBBGResMgr ***)(iVar9 + DAT_00169c80),0x10);
  uVar11 = GsGetCurrentTime();
  uVar2 = (int)((ulonglong)uVar11 >> 0x20) - *(int *)(in_r0 + 0x11c);
  uVar3 = (uint)((uint)uVar11 < *(uint *)(in_r0 + 0x118));
  bVar4 = false;
  if ((0 < (int)(uVar2 - uVar3)) ||
     ((uVar2 == uVar3 && (DAT_00169c88 < (uint)uVar11 - *(uint *)(in_r0 + 0x118))))) {
    bVar4 = true;
  }
  *(bool *)(in_r0 + 0x120) = bVar4;
  iVar5 = DAT_00169c8c;
  iVar8 = *(int *)(in_r0 + 8);
  if (iVar8 == 0) {
    if (*(char *)(in_r0 + 0x15c) == '\0') {
      return;
    }
    if (!bVar4) {
      return;
    }
    *(undefined *)(in_r0 + 0x15c) = 0;
    *(undefined4 *)(in_r0 + 8) = 100;
    return;
  }
  cVar1 = **(char **)(iVar9 + DAT_00169c84);
  if (iVar8 == 1) {
    iVar8 = CBBGDataMgr::GetOption();
    if ((*(char *)(iVar8 + 0x204) == '\0') &&
       (iVar8 = **(int **)(iVar9 + DAT_00169c90), *(int *)(iVar8 + 0xa4) == 1)) {
      if (*(char *)(iVar8 + DAT_00169c94) == '\x01') {
        iVar7 = CBBGDataMgr::GetOption();
        *(undefined *)(iVar7 + 0x204) = 1;
        iVar7 = CBBGDataMgr::GetOption();
        if (*(int *)(iVar7 + 0x48) == 1) {
          CBBGModeUiMgr::CreateNormalPopup
                    (*(CBBGModeUiMgr **)(in_r0 + 0x108),(char *)(iVar9 + DAT_00169ca4),1,1);
        }
        else {
          CBBGModeUiMgr::CreateNormalPopup
                    (*(CBBGModeUiMgr **)(in_r0 + 0x108),(char *)(iVar9 + DAT_00169c9c),1,1);
        }
        ppCVar10 = *(CBBGDataMgr ***)(iVar9 + iVar5);
        pCVar6 = (CBBGOption *)CBBGDataMgr::GetOption();
        CBBGOption::AddGPoint(pCVar6,DAT_00169ca0);
        CBBGDataMgr::AddRegistryGainGPoint(*ppCVar10,10,DAT_00169ca0);
        CBBGDataMgr::SaveRegistry((uchar)*ppCVar10);
        *(undefined *)(iVar8 + DAT_00169c94) = 0;
      }
      else {
        iVar9 = CBBGDataMgr::GetOption();
        if (*(char *)(iVar9 + 0x204) == '\0') {
          iVar9 = CBBGDataMgr::GetOption();
          *(undefined *)(iVar9 + 0x204) = 1;
        }
      }
      iVar9 = CBBGDataMgr::GetOption();
      if ((*(char *)(iVar9 + 0x58) == '\0') && (*(char *)(iVar8 + DAT_00169c98) != '\0')) {
        pCVar6 = (CBBGOption *)CBBGDataMgr::GetOption();
        CBBGOption::SetUserName(pCVar6,(char *)(DAT_00169c98 + iVar8));
      }
      *(undefined4 *)(in_r0 + 8) = 100;
      return;
    }
    if (cVar1 == '\0') {
      *(undefined4 *)(in_r0 + 8) = 100;
      goto LAB_00169b64;
    }
    iVar8 = *(int *)(in_r0 + 8);
  }
  if (iVar8 != 100) {
    return;
  }
LAB_00169b64:
  CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
  return;
}


