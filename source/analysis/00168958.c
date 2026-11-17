/* CBBGMenuRun::EVENT_HANDLER_MSTATE_SETTING at 00168958; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_SETTING() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_SETTING(void)

{
  int in_r0;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  CGsSound **ppCVar6;
  CBBGResMgr **ppCVar7;
  int iVar8;
  
  iVar1 = CBBGCommonMenu::RunGameSetting(*(CBBGCommonMenu **)(in_r0 + 0x6c),*(int *)(in_r0 + 0x30));
  iVar8 = DAT_001689f4 + 0x168976;
  ppCVar7 = *(CBBGResMgr ***)(iVar8 + DAT_001689f8);
  iVar5 = *(int *)(in_r0 + 0x60);
  uVar2 = CBBGResMgr::GetPZxMgr(*ppCVar7,0x23);
  uVar3 = CBBGResMgr::GetPZxMgr(*ppCVar7,0x1b);
  uVar4 = CBBGResMgr::GetPZxMgr(*ppCVar7,0x14);
  *(undefined4 *)(iVar5 + 0x20) = uVar2;
  *(undefined4 *)(iVar5 + 0x24) = uVar3;
  *(undefined4 *)(iVar5 + 0x28) = uVar4;
  if (iVar1 == 100) {
    CBBState::ReserveState((CBBState *)(in_r0 + 8),0x22);
  }
  else if (iVar1 == 0x65) {
    CBBState::ReserveState((CBBState *)(in_r0 + 8),0x23);
  }
  else if (iVar1 == -100) {
    ppCVar6 = *(CGsSound ***)(iVar8 + DAT_001689fc);
    CGsSound::Stop();
    CGsSound::Play(*ppCVar6,1,-1,'\x01');
    CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
  }
  return;
}


