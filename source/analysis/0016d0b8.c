/* CBBGMenuRun::EVENT_HANDLER_MSTATE_VS at 0016d0b8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_VS() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_VS(void)

{
  CBBGMenuRun *in_r0;
  int iVar1;
  char *pcVar2;
  CPopup *this;
  undefined4 uVar3;
  int iVar4;
  CPopup **ppCVar5;
  CBBGPopup *this_00;
  
  iVar4 = DAT_0016d17c + 0x16d0c4;
  iVar1 = CBBGDataMgr::GetOption();
  if (*(char *)(iVar1 + 0x86) == '\0') {
    this_00 = **(CBBGPopup ***)(iVar4 + DAT_0016d18c);
    pcVar2 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar4 + DAT_0016d190),0x36,0x36);
    CBBGPopup::CreatePopup(this_00,pcVar2,'\x01',(short)DAT_0016d194,'\0',(char **)0x0,0,0);
    ppCVar5 = *(CPopup ***)(iVar4 + DAT_0016d198);
    this = *ppCVar5;
    if ((this != (CPopup *)0x0) &&
       (CPopup::SetTitle(this,(char *)(iVar4 + DAT_0016d19c),2), *ppCVar5 != (CPopup *)0x0)) {
      CPopup::SetAutoClose();
    }
    CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
  }
  else {
    iVar1 = CBBGDataMgr::GetOption();
    if (*(char *)(iVar1 + 0x99) == '\0') {
      iVar1 = CBBGDataMgr::GetOption();
      if (*(char *)(iVar1 + 0x98) == '\0') {
        *(undefined4 *)(in_r0 + 100) = 8;
        SetChangeRunnable(in_r0,0x106);
        CBBGScreenMng::SetMode(**(CBBGScreenMng ***)(iVar4 + DAT_0016d184),1,0,5,DAT_0016d188);
        return;
      }
      uVar3 = 8;
    }
    else {
      uVar3 = 9;
    }
    *(undefined4 *)(in_r0 + 100) = uVar3;
    CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
  }
  return;
}


