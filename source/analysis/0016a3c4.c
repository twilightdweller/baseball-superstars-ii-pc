/* CBBGMenuRun::Initialize at 0016a3c4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::Initialize() */

void CBBGMenuRun::Initialize(void)

{
  CBBGMenuRun *in_r0;
  CBBGListMgr *this;
  CBBGEntry *this_00;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  CBBGModeUiMgr *this_01;
  int iVar4;
  int *piVar5;
  int iVar6;
  CBBGResMgr **ppCVar7;
  int iVar8;
  CGsSound **ppCVar9;
  
  iVar8 = DAT_0016a5d0 + 0x16a3da;
  *(undefined4 *)(in_r0 + 0x6c) = **(undefined4 **)(iVar8 + DAT_0016a5d4);
  *(undefined4 *)(in_r0 + 100) = **(undefined4 **)(iVar8 + DAT_0016a5d8);
  piVar5 = *(int **)(iVar8 + DAT_0016a5dc);
  iVar4 = *piVar5;
  ppCVar7 = *(CBBGResMgr ***)(iVar8 + DAT_0016a5e0);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x13);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x15);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x36);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x37);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x14);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x23);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x1b);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x38);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x3b);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x3a);
  CBBGResMgr::AddLoadRes(*ppCVar7,0x27);
  this = (CBBGListMgr *)operator_new(0xbc);
  CBBGListMgr::CBBGListMgr(this);
  *(CBBGListMgr **)(in_r0 + 0xac) = this;
  **(CBBGListMgr ***)(iVar8 + DAT_0016a5e4) = this;
  in_r0[0x72] = (CBBGMenuRun)0x0;
  in_r0[0x71] = (CBBGMenuRun)0x0;
  in_r0[0x70] = (CBBGMenuRun)0x0;
  in_r0[0x9d] = (CBBGMenuRun)0x1;
  in_r0[0x9c] = (CBBGMenuRun)0x0;
  in_r0[0x115] = (CBBGMenuRun)0x0;
  *(undefined *)(*(int *)(in_r0 + 0x6c) + 0x39c) = 1;
  this_00 = (CBBGEntry *)operator_new(0x1f0);
  CBBGEntry::CBBGEntry(this_00);
  *(CBBGEntry **)(in_r0 + 0x60) = this_00;
  uVar1 = CBBGResMgr::GetPZxMgr(*ppCVar7,0x23);
  uVar2 = CBBGResMgr::GetPZxMgr(*ppCVar7,0x1b);
  uVar3 = CBBGResMgr::GetPZxMgr(*ppCVar7,0x14);
  *(undefined4 *)(this_00 + 0x20) = uVar1;
  *(undefined4 *)(this_00 + 0x28) = uVar3;
  *(undefined4 *)(this_00 + 0x24) = uVar2;
  if (iVar4 == -1) {
    CBBGResMgr::AddLoadRes(*ppCVar7,0x10);
    CBBState::ReserveState((CBBState *)(in_r0 + 8),6);
  }
  else {
    iVar4 = *piVar5;
    if (iVar4 == 0x25) {
      *piVar5 = -1;
      *(undefined *)(*(int *)(in_r0 + 0x6c) + 100) = 0;
      *(undefined *)(*(int *)(in_r0 + 0x6c) + 0x65) = 0;
      CBBState::ReserveState((CBBState *)(in_r0 + 8),0x25);
      return;
    }
    CBBGCommonMenu::ScreenCapture(*(CBBGCommonMenu **)(in_r0 + 0x6c),'\x01','\x01');
    in_r0[0x87] = (CBBGMenuRun)0x6;
    InitMenuList(in_r0,0);
    InitMenuList(in_r0,1);
    iVar6 = *(int *)(in_r0 + 0x6c);
    *(undefined *)(iVar6 + 0x60) = 1;
    *(undefined2 *)(iVar6 + 0x62) = 1;
    *(undefined4 *)(in_r0 + 0x150) = 1;
    *(undefined4 *)(in_r0 + 0x154) = 0;
    *(undefined4 *)(in_r0 + 0x158) = 1;
    *(undefined4 *)(in_r0 + 0x14c) = 0;
    CheckLastGameMode();
    ppCVar9 = *(CGsSound ***)(iVar8 + DAT_0016a5e8);
    CGsSound::Stop();
    CGsSound::Play(*ppCVar9,1,-1,'\x01');
    CBBGResMgr::AddLoadRes(*ppCVar7,0x12);
    CBBState::ReserveState((CBBState *)(in_r0 + 8),iVar4);
    *piVar5 = -1;
  }
  *(undefined4 *)(in_r0 + 0xa4) = 0;
  this_01 = (CBBGModeUiMgr *)operator_new(0x2e8);
  CBBGModeUiMgr::CBBGModeUiMgr(this_01);
  *(CBBGModeUiMgr **)(in_r0 + 0x108) = this_01;
  *(undefined4 *)(in_r0 + 0x118) = 0;
  *(undefined4 *)(in_r0 + 0x11c) = 0;
  in_r0[0x120] = (CBBGMenuRun)0x0;
  in_r0[0x15c] = (CBBGMenuRun)0x0;
  return;
}


