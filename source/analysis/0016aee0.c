/* CBBGMenuRun::EVENT_HANDLER_MSTATE_DATA_DOWNLOAD at 0016aee0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_DATA_DOWNLOAD() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_DATA_DOWNLOAD(void)

{
  byte bVar1;
  int in_r0;
  CBBGSatellite *pCVar2;
  int iVar3;
  size_t sVar4;
  byte *pbVar5;
  CBBGPopup *pCVar6;
  int iVar7;
  int iVar8;
  CBBGPopup **ppCVar9;
  CBBGSatellite **ppCVar10;
  uint uVar11;
  int *piVar12;
  char *pcVar13;
  int local_2c [2];
  
  iVar8 = *(int *)(in_r0 + 8);
  iVar7 = DAT_0016b22c + 0x16aef6;
  if (iVar8 == 10) {
    if (*(int *)(in_r0 + 0xe0) < 1) {
      CBBGDataMgr::Initialization();
      CBBGDataMgr::GetOption();
      CBBGOption::Apply();
      uVar11 = *(int *)(**(int **)(iVar7 + DAT_0016b230) + DAT_0016b27c) << 8 |
               (uint)*(byte *)(**(int **)(iVar7 + DAT_0016b230) + DAT_0016b280);
      if (uVar11 == 0) {
        piVar12 = *(int **)(iVar7 + DAT_0016b284);
        if (*piVar12 != 0) {
          iVar8 = CBBGDataMgr::GetOption();
          *(int *)(iVar8 + 0x40) = *piVar12;
        }
      }
      else {
        iVar8 = CBBGDataMgr::GetOption();
        *(uint *)(iVar8 + 0x40) = uVar11;
      }
      iVar8 = CBBGDataMgr::GetOption();
      *(undefined4 *)(iVar8 + 0x124) = 0;
      iVar3 = CBBGDataMgr::GetOption();
      iVar8 = DAT_0016b288;
      pcVar13 = *(char **)(iVar7 + DAT_0016b288);
      sVar4 = strlen(pcVar13);
      if (0xe < sVar4) {
        pcVar13[0xe] = '\0';
      }
      strcpy((char *)(iVar3 + 0x1c1),*(char **)(iVar7 + iVar8));
      CBBGDataMgr::SaveOption();
      CBBGSatellite::SendBackupConfirm();
      *(undefined4 *)(in_r0 + 8) = 0xb;
      return;
    }
    local_2c[0] = SetSplitFile(*(uint *)(in_r0 + 0xd8),(int *)(in_r0 + 0xdc));
    if (local_2c[0] != 0) {
      *(int *)(in_r0 + 0xe0) = *(int *)(in_r0 + 0xe0) + -1;
      return;
    }
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b234));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b238));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b23c));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b240));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b244));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b248));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b24c));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b250));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b254));
    CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b258));
    ppCVar9 = *(CBBGPopup ***)(iVar7 + DAT_0016b264);
    pCVar6 = *ppCVar9;
    pcVar13 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar7 + DAT_0016b268),0x36,0x1e);
    CBBGPopup::CreatePopup(pCVar6,pcVar13,'\x01',(short)DAT_0016b26c,'\0',(char **)0x0,0,0);
    CBBGPopup::SetTitle((char *)*ppCVar9,iVar7 + DAT_0016b270);
    CBBGPopup::SetAutoClose();
    pCVar2 = **(CBBGSatellite ***)(iVar7 + DAT_0016b230);
LAB_0016b0a4:
    CBBGSatellite::Disconnect(pCVar2,'\0');
    CGsSound::Resume();
    *(undefined4 *)(in_r0 + 8) = 100;
  }
  else {
    if (iVar8 < 0xb) {
      if (iVar8 != 0) {
        if (iVar8 != 1) {
          return;
        }
        ppCVar10 = *(CBBGSatellite ***)(iVar7 + DAT_0016b230);
        if (*(int *)(*ppCVar10 + 0xa4) == 3) {
          ppCVar9 = *(CBBGPopup ***)(iVar7 + DAT_0016b264);
          pCVar6 = *ppCVar9;
          pcVar13 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar7 + DAT_0016b268),0x36,0x1d);
          CBBGPopup::CreatePopup(pCVar6,pcVar13,'\x01',0x15b,'\0',(char **)0x0,0,0);
          CBBGPopup::SetTitle((char *)*ppCVar9,iVar7 + DAT_0016b270);
          CBBGPopup::SetAutoClose();
          CBBGSatellite::Disconnect(*ppCVar10,'\0');
          CGsSound::Resume();
          CBBState::ReserveState((CBBState *)(in_r0 + 8),0xc);
          return;
        }
        if (*(int *)(*ppCVar10 + 0xa4) != 2) {
          return;
        }
        local_2c[0] = 0;
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b234));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b238));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b23c));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b240));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b244));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b248));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b24c));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b250));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b254));
        CGsFile::Delete((CGsFile *)local_2c,(char *)(iVar7 + DAT_0016b258));
        *(undefined4 *)(in_r0 + 8) = 10;
        *(undefined4 *)(in_r0 + 0xdc) = 0;
        pbVar5 = *(byte **)(*ppCVar10 + DAT_0016b25c);
        *(byte **)(in_r0 + 0xd8) = pbVar5;
        bVar1 = *pbVar5;
        *(undefined4 *)(in_r0 + 0xdc) = 1;
        *(uint *)(in_r0 + 0xe0) = (uint)bVar1;
        return;
      }
      if (**(char **)(iVar7 + DAT_0016b260) == '\0') {
        ppCVar10 = *(CBBGSatellite ***)(iVar7 + DAT_0016b230);
        pCVar2 = *ppCVar10;
        *(undefined4 *)(pCVar2 + 0xb4) = *(undefined4 *)(iVar7 + DAT_0016b28c);
        *(int *)(pCVar2 + 0xb8) = in_r0;
        CGsSound::Suspend();
        *(int *)(in_r0 + 8) = *(int *)(in_r0 + 8) + 1;
        CBBGSatellite::Connect(*ppCVar10,0x33,0);
        return;
      }
      if (**(char **)(iVar7 + DAT_0016b260) != '\x01') {
        return;
      }
    }
    else {
      if (iVar8 == 0xb) {
        ppCVar10 = *(CBBGSatellite ***)(iVar7 + DAT_0016b230);
        if (*(int *)(*ppCVar10 + 0xa4) != 1) {
          return;
        }
        ppCVar9 = *(CBBGPopup ***)(iVar7 + DAT_0016b264);
        pCVar6 = *ppCVar9;
        pcVar13 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar7 + DAT_0016b268),0x36,0x1f);
        CBBGPopup::CreatePopup(pCVar6,pcVar13,'\x01',0x15b,'\0',(char **)0x0,0,0);
        CBBGPopup::SetTitle((char *)*ppCVar9,iVar7 + DAT_0016b270);
        CBBGPopup::SetAutoClose();
        pCVar2 = *ppCVar10;
        goto LAB_0016b0a4;
      }
      if (iVar8 != 100) {
        return;
      }
    }
    CBBState::ReserveState((CBBState *)(in_r0 + 8),0xc);
  }
  return;
}


