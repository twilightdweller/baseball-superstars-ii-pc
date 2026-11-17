/* CBBGMenuRun::EVENT_HANDLER_MSTATE_DATA_UPLOAD at 0016acf4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_DATA_UPLOAD() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_DATA_UPLOAD(void)

{
  char cVar1;
  int in_r0;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  CBBGPopup *pCVar5;
  CBBGSatellite *pCVar6;
  int iVar7;
  CBBGSatellite **ppCVar8;
  CBBGPopup **ppCVar9;
  
  iVar4 = *(int *)(in_r0 + 8);
  iVar7 = DAT_0016aea8 + 0x16ad04;
  if (iVar4 == 1) {
    cVar1 = **(char **)(iVar7 + DAT_0016aec0);
    if (cVar1 == '\0') {
      CBBGDataMgr::MakeMergeSaveBuffer();
      ppCVar8 = *(CBBGSatellite ***)(iVar7 + DAT_0016aeac);
      pCVar6 = *ppCVar8;
      *(undefined4 *)(pCVar6 + 0xb4) = *(undefined4 *)(iVar7 + DAT_0016aedc);
      *(int *)(pCVar6 + 0xb8) = in_r0;
      CGsSound::Suspend();
      iVar4 = *(int *)(in_r0 + 8) + 1;
LAB_0016ae70:
      *(int *)(in_r0 + 8) = iVar4;
      CBBGSatellite::Connect(*ppCVar8,0x32,0);
      return;
    }
  }
  else {
    if (1 < iVar4) {
      if (iVar4 == 2) {
        ppCVar8 = *(CBBGSatellite ***)(iVar7 + DAT_0016aeac);
        if (*(int *)(*ppCVar8 + 0xa4) != 1) {
          return;
        }
        ppCVar9 = *(CBBGPopup ***)(iVar7 + DAT_0016aeb0);
        pCVar5 = *ppCVar9;
        pcVar2 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar7 + DAT_0016aeb4),0x36,0x1b);
        CBBGPopup::CreatePopup(pCVar5,pcVar2,'\x01',0x15b,'\0',(char **)0x0,0,0);
        CBBGPopup::SetTitle((char *)*ppCVar9,iVar7 + DAT_0016aeb8);
        CBBGPopup::SetAutoClose();
        CBBGSatellite::Disconnect(*ppCVar8,'\0');
        CGsSound::Resume();
        *(undefined4 *)(in_r0 + 8) = 100;
        return;
      }
      if (iVar4 != 100) {
        return;
      }
      if (**(char **)(iVar7 + DAT_0016aec0) == -1) {
        return;
      }
      goto LAB_0016ad8e;
    }
    if (iVar4 != 0) {
      return;
    }
    cVar1 = **(char **)(iVar7 + DAT_0016aec0);
    if (cVar1 == '\0') {
      iVar4 = CBBGDataMgr::GetOption();
      if (*(int *)(iVar4 + 0x124) != 0) {
        ppCVar9 = *(CBBGPopup ***)(iVar7 + DAT_0016aeb0);
        pCVar5 = *ppCVar9;
        pcVar2 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar7 + DAT_0016aeb4),0x36,0x1a);
        CBBGPopup::CreatePopup(pCVar5,pcVar2,'\x02',(short)DAT_0016aec8,'\0',(char **)0x0,0,0);
        CBBGPopup::SetTitle((char *)*ppCVar9,iVar7 + DAT_0016aeb8);
        iVar4 = DAT_0016aed0;
        piVar3 = *(int **)(iVar7 + DAT_0016aecc);
        iVar7 = *piVar3;
        if (iVar7 != 0) {
          *(undefined4 *)((*(char *)(iVar7 + DAT_0016aed0) + DAT_0016aed4) * 4 + iVar7) = 0xfffffff0
          ;
          cVar1 = *(char *)(iVar7 + iVar4);
          *(undefined *)(iVar7 + cVar1 + DAT_0016aed8 + 4) = 1;
          *(char *)(iVar7 + iVar4) = cVar1 + '\x01';
          iVar7 = *piVar3;
          if (iVar7 != 0) {
            *(undefined *)(iVar7 + iVar4 + 1) = 1;
          }
        }
        *(int *)(in_r0 + 8) = *(int *)(in_r0 + 8) + 1;
        return;
      }
      CBBGDataMgr::MakeMergeSaveBuffer();
      ppCVar8 = *(CBBGSatellite ***)(iVar7 + DAT_0016aeac);
      pCVar6 = *ppCVar8;
      *(undefined4 *)(pCVar6 + 0xb4) = *(undefined4 *)(iVar7 + DAT_0016aedc);
      *(int *)(pCVar6 + 0xb8) = in_r0;
      CGsSound::Suspend();
      iVar4 = *(int *)(in_r0 + 8) + 2;
      goto LAB_0016ae70;
    }
  }
  if (cVar1 != '\x01') {
    return;
  }
LAB_0016ad8e:
  CBBState::ReserveState((CBBState *)(in_r0 + 8),0xc);
  return;
}


