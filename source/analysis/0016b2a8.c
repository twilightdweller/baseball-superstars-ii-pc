/* CBBGMenuRun::EVENT_HANDLER_MSTATE_RANKING_LIST at 0016b2a8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_RANKING_LIST() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_RANKING_LIST(void)

{
  int in_r0;
  int iVar1;
  CBBGOption *this;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  CBBGSatellite *pCVar3;
  int iVar4;
  CBBGSatellite **ppCVar5;
  int iVar6;
  CBBGPopup **ppCVar7;
  CBBGPopup *pCVar8;
  
  iVar6 = *(int *)(in_r0 + 0x30);
  iVar4 = DAT_0016b50c + 0x16b2c0;
  iVar1 = CBBGCommonMenu::EventGamevilMessage(*(int *)(in_r0 + 0x6c));
  if (iVar1 == 0) {
    iVar1 = *(int *)(in_r0 + 8);
    if (iVar1 == 1) {
      iVar1 = **(int **)(iVar4 + DAT_0016b510);
      if (*(int *)(iVar1 + 0xa4) == 3) {
        if ((*(char *)(*(int *)(in_r0 + 0x6c) + DAT_0016b514) == '\0') &&
           (*(char *)(iVar1 + 0xa8) != '\0')) {
          ppCVar7 = *(CBBGPopup ***)(iVar4 + DAT_0016b540);
          CBBGPopup::CreatePopup
                    (*ppCVar7,(char *)(iVar1 + *(char *)(iVar1 + 0xa9) * 100 + DAT_0016b544),'\x01',
                     (short)DAT_0016b548,'\0',(char **)0x0,0,0);
          pCVar8 = *ppCVar7;
          iVar1 = CBBGResMgr::GetGameCodeStr(**(CBBGResMgr ***)(iVar4 + DAT_0016b534),0x12a);
          CBBGPopup::SetTitle((char *)pCVar8,iVar1);
          *(undefined *)(*(int *)(in_r0 + 0x6c) + DAT_0016b54c) = 1;
          *(int *)(in_r0 + 8) = *(int *)(in_r0 + 8) + 1;
        }
        else {
          *(undefined4 *)(in_r0 + 8) = 2;
        }
        CBBGSatellite::SetRankSearch();
        InitRankingViewScroll();
      }
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        ppCVar5 = *(CBBGSatellite ***)(iVar4 + DAT_0016b510);
        pCVar3 = *ppCVar5;
        *(undefined4 *)(pCVar3 + 0xb4) = *(undefined4 *)(iVar4 + DAT_0016b520);
        *(int *)(pCVar3 + 0xb8) = in_r0;
        CGsSound::Suspend();
        *(int *)(in_r0 + 8) = *(int *)(in_r0 + 8) + 1;
        CBBGSatellite::Connect(*ppCVar5,0,0);
      }
    }
    else if (iVar1 == 2) {
      this = (CBBGOption *)CBBGDataMgr::GetOption();
      iVar1 = CBBGOption::IsRaiseItemOpened(this,0,2,3);
      if (iVar1 == 0) {
        iVar1 = CBBGSatellite::IsNetworkCertified(**(CBBGSatellite ***)(iVar4 + DAT_0016b510),1);
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = CBBGCommonMenu::DoHiddenOpen(*(CBBGCommonMenu **)(in_r0 + 0x6c),0x24,true);
        }
      }
      uVar2 = iVar6 + 0x10;
      if (uVar2 < 0x49) {
        UNRECOVERED_JUMPTABLE =
             (code *)(*(int *)(iVar4 + DAT_0016b51c + uVar2 * 4) + iVar4 + DAT_0016b51c);
                    /* WARNING: Could not emulate address calculation at 0x0016b350 */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(iVar1,UNRECOVERED_JUMPTABLE,*(undefined4 *)(in_r0 + 0xc4));
        return;
      }
    }
    else if (iVar1 == 3) {
      CBBGSatellite::SendGetRanking();
      *(undefined4 *)(in_r0 + 8) = 1;
    }
  }
  return;
}


