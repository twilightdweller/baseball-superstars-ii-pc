/* CBBGMenuRun::EVENT_HANDLER_MSTATE_HOMERUN_MODE at 0016abf0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_HOMERUN_MODE() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_HOMERUN_MODE(void)

{
  int in_r0;
  char *pcVar1;
  int iVar2;
  CBBGPopup *this;
  int iVar3;
  CBBGPopup **ppCVar4;
  
  iVar3 = DAT_0016acd8 + 0x16ac00;
  if (*(int *)(in_r0 + 8) == 0) {
    CBBGCommonMenu::InitHallOfFame((uchar)*(undefined4 *)(in_r0 + 0x6c),'\0');
    iVar2 = *(int *)(in_r0 + 0x6c);
    if (*(char *)(iVar2 + DAT_0016acdc) == '\0') {
      ppCVar4 = *(CBBGPopup ***)(iVar3 + DAT_0016ace4);
      this = *ppCVar4;
      pcVar1 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar3 + DAT_0016ace8),0x36,0xeb);
      CBBGPopup::CreatePopup(this,pcVar1,'\x01',(short)DAT_0016acec,'\0',(char **)0x0,0,0);
      CBBGPopup::SetTitle((char *)*ppCVar4,iVar3 + DAT_0016acf0);
      CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
    }
    else {
      *(undefined *)(iVar2 + 0x60) = 1;
      *(undefined2 *)(iVar2 + 0x62) = 1;
      iVar3 = *(int *)(in_r0 + 0x6c);
      *(undefined4 *)(iVar3 + 0x338) = 0;
      *(undefined2 *)(iVar3 + 0x348) = 2;
      *(undefined2 *)(iVar3 + DAT_0016ace0) = 1;
      *(undefined *)(iVar3 + 0x70) = 0;
      CBBGCommonMenu::ScreenCapture(*(CBBGCommonMenu **)(in_r0 + 0x6c),'\x01','\0');
      *(undefined4 *)(*(int *)(in_r0 + 0x6c) + 0x4a0) = 1;
      *(undefined4 *)(in_r0 + 8) = 1;
    }
  }
  else if (*(int *)(in_r0 + 8) == 1) {
    iVar3 = CBBGCommonMenu::RunHallOfFame(*(CBBGCommonMenu **)(in_r0 + 0x6c),*(int *)(in_r0 + 0x30))
    ;
    if (iVar3 == 3) {
      *(undefined4 *)(in_r0 + 8) = 0;
      CBBGCommonMenu::DeleteHallOfFame();
      CBBGCommonMenu::ScreenCapture(*(CBBGCommonMenu **)(in_r0 + 0x6c),'\x01','\x01');
      CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
    }
    else if (iVar3 == 7) {
      *(undefined4 *)(in_r0 + 100) = 7;
      CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
    }
  }
  return;
}


