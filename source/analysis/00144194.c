/* CBBStartUp::EvAppStart at 00144194; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBStartUp::EvAppStart() */

void CBBStartUp::EvAppStart(void)

{
  int iVar1;
  int *in_r0;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  CGsSound *this;
  CGsGraphics *this_00;
  CGsParticleMgr *this_01;
  CPitchPattern *this_02;
  CBBGameSpdInfo *this_03;
  CBBGLevelData *this_04;
  CBBGScreenMng *this_05;
  CGsTouchMgr *this_06;
  CGsOemIME *this_07;
  CGsAutomata *this_08;
  CBBGCommonMenu *this_09;
  CBBGPlayData *this_10;
  CBBGSatellite *this_11;
  CBBGWeather *this_12;
  CBBGDataMgr *this_13;
  CBBGDailyMgr *this_14;
  int iVar5;
  size_t sVar6;
  CBBGPopup *this_15;
  CBBGResMgr *this_16;
  CBBGMissionData *this_17;
  CBBGChat *this_18;
  CBBGEventMgr *this_19;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined local_17c [4];
  undefined local_178;
  undefined local_174;
  undefined local_170;
  char local_16c [256];
  char acStack_6c [64];
  int local_2c;
  
  iVar1 = DAT_00144238;
  iVar9 = DAT_00144234 + 0x1441aa;
  local_2c = **(int **)(iVar9 + DAT_00144238);
  GsPutMemoryInfo((char *)(iVar9 + DAT_0014423c));
  memset(acStack_6c,0,0x40);
  piVar2 = (int *)operator_new(0x44);
  **(int ***)(iVar9 + DAT_00144240) = piVar2;
  *piVar2 = *(int *)(iVar9 + DAT_00144244) + 8;
  memset(piVar2 + 1,0,0x40);
  pcVar7 = (char *)(DAT_00144248 + iVar9);
  pcVar8 = (char *)(DAT_0014424c + iVar9);
  iVar3 = CGsPhoneInfo::InitPhoneInfo((CGsPhoneInfo *)piVar2,pcVar7,pcVar8,acStack_6c,false);
  if (iVar3 == 0) {
    (**(code **)(*piVar2 + 4))(piVar2);
    (**(code **)(*in_r0 + 0xc))(in_r0);
  }
  else {
    uVar4 = GsGetCurrentTime();
    **(undefined4 **)(iVar9 + DAT_001445e8) = uVar4;
    iVar3 = CBBGTimer::GetInstance();
    in_r0[0x20] = iVar3;
    this = (CGsSound *)operator_new(0x78);
    CGsSound::CGsSound(this,0xd,(char *)(iVar9 + DAT_001445ec),0);
    CGsSound::OnCreate(this,0x38,(int *)0x0);
    this[0x5f] = (CGsSound)0x1;
    this_00 = (CGsGraphics *)operator_new(0x54);
    CGsGraphics::CGsGraphics(this_00,false,false,true,0);
    CGsGraphics::CreateBFont(this_00,pcVar7,pcVar8,(char *)0x0);
    CGsGraphics::ClearScreen(this_00,0);
    this_01 = (CGsParticleMgr *)operator_new(0x7c);
    CGsParticleMgr::CGsParticleMgr(this_01);
    CGsParticleMgr::InitParticleSystem(this_01,(char *)(iVar9 + DAT_001445f0),0x200,true);
    this_02 = (CPitchPattern *)operator_new(0x14);
    CPitchPattern::CPitchPattern(this_02);
    this_03 = (CBBGameSpdInfo *)operator_new(0x14);
    CBBGameSpdInfo::CBBGameSpdInfo(this_03);
    this_04 = (CBBGLevelData *)operator_new(0x208);
    CBBGLevelData::CBBGLevelData(this_04);
    this_05 = (CBBGScreenMng *)operator_new(0x38);
    CBBGScreenMng::CBBGScreenMng(this_05);
    this_06 = (CGsTouchMgr *)operator_new(0x130);
    CGsTouchMgr::CGsTouchMgr(this_06);
    iVar3 = **(int **)(iVar9 + DAT_001445f4);
    CGsTouchMgr::Initialize
              (this_06,*(int *)(iVar3 + 0x48),*(int *)(iVar3 + 0x3c) + *(int *)(iVar3 + 0x4c));
    this_07 = (CGsOemIME *)operator_new(0x1a8);
    CGsOemIME::CGsOemIME(this_07,false,true,0);
    CGsOemIME::Initial(this_07,false);
    CGsTouchMgr::IwantSkinShip();
    this_08 = (CGsAutomata *)operator_new(0x1b8);
    CGsAutomata::CGsAutomata(this_08,'\b');
    CGsAutomata::DeleteTextAll();
    this_09 = (CBBGCommonMenu *)operator_new(DAT_001445fc);
    CBBGCommonMenu::CBBGCommonMenu(this_09);
    iVar3 = DAT_00144600;
    **(CBBGCommonMenu ***)(iVar9 + DAT_00144600) = this_09;
    this_10 = (CBBGPlayData *)operator_new(0x178);
    CBBGPlayData::CBBGPlayData(this_10);
    **(CBBGPlayData ***)(iVar9 + DAT_00144604) = this_10;
    memset(this_10,0,0x178);
    CBBGPlayData::ResetAll();
    this_11 = (CBBGSatellite *)operator_new(DAT_00144608);
    CBBGSatellite::CBBGSatellite(this_11,this_00);
    this_12 = (CBBGWeather *)operator_new(0x24);
    CBBGWeather::CBBGWeather(this_12);
    MakeFxTable();
    SetBlendFunc(0,*(void **)(iVar9 + DAT_0014460c));
    SetZeroBlendFunc(0,*(void **)(iVar9 + DAT_00144610),*(void **)(iVar9 + DAT_00144614));
    SetBlendFunc(1,*(void **)(iVar9 + DAT_00144618));
    SetZeroBlendFunc(1,*(void **)(iVar9 + DAT_0014461c),*(void **)(iVar9 + DAT_00144620));
    SetBlendFunc(2,*(void **)(iVar9 + DAT_00144624));
    SetZeroBlendFunc(2,*(void **)(iVar9 + DAT_00144628),*(void **)(iVar9 + DAT_0014462c));
    SetBlendFunc(4,*(void **)(iVar9 + DAT_00144630));
    SetZeroBlendFunc(4,*(void **)(iVar9 + DAT_00144634),*(void **)(iVar9 + DAT_00144638));
    SetBlendFunc(7,*(void **)(iVar9 + DAT_0014463c));
    SetZeroBlendFunc(7,*(void **)(iVar9 + DAT_00144640),*(void **)(iVar9 + DAT_00144644));
    SetBlendFunc(10,*(void **)(iVar9 + DAT_00144648));
    SetZeroBlendFunc(10,*(void **)(iVar9 + DAT_0014464c),*(void **)(iVar9 + DAT_00144650));
    SetBlendFunc(0xb,*(void **)(iVar9 + DAT_00144654));
    SetZeroBlendFunc(0xb,*(void **)(iVar9 + DAT_00144658),*(void **)(iVar9 + DAT_0014465c));
    SetBlendFunc(0xc,*(void **)(iVar9 + DAT_00144660));
    SetZeroBlendFunc(0xc,*(void **)(iVar9 + DAT_00144664),*(void **)(iVar9 + DAT_00144668));
    SetBlendFunc(0xd,*(void **)(iVar9 + DAT_0014466c));
    SetZeroBlendFunc(0xd,*(void **)(iVar9 + DAT_00144670),*(void **)(iVar9 + DAT_00144674));
    SetBlendFunc(0x10,*(void **)(iVar9 + DAT_00144678));
    SetZeroBlendFunc(0x10,*(void **)(iVar9 + DAT_0014467c),*(void **)(iVar9 + DAT_00144680));
    SetBlendFunc(0x11,*(void **)(iVar9 + DAT_00144684));
    SetZeroBlendFunc(0x11,*(void **)(iVar9 + DAT_00144688),*(void **)(iVar9 + DAT_0014468c));
    SetBlendFunc(0x13,*(void **)(iVar9 + DAT_00144690));
    SetZeroBlendFunc(0x13,*(void **)(iVar9 + DAT_00144694),*(void **)(iVar9 + DAT_00144698));
    SetBlendFunc(0x14,*(void **)(iVar9 + DAT_0014469c));
    SetZeroBlendFunc(0x14,*(void **)(iVar9 + DAT_001446a0),*(void **)(iVar9 + DAT_001446a4));
    SetBlendFunc(0x15,*(void **)(iVar9 + DAT_001446a8));
    SetZeroBlendFunc(0x15,*(void **)(iVar9 + DAT_001446ac),*(void **)(iVar9 + DAT_001446b0));
    SetScreenEffectFunc(0,*(void **)(iVar9 + DAT_001446b4),*(void **)(iVar9 + DAT_001446b8));
    SetScreenEffectFunc(1,*(void **)(iVar9 + DAT_001446bc),*(void **)(iVar9 + DAT_001446c0));
    this_13 = (CBBGDataMgr *)operator_new(0x1120);
    CBBGDataMgr::CBBGDataMgr(this_13);
    this_14 = (CBBGDailyMgr *)operator_new(0x170);
    CBBGDailyMgr::CBBGDailyMgr(this_14);
    CBBGDataMgr::Initialization();
    CBBGDataMgr::GetOption();
    CBBGOption::Apply();
    CBBGDailyMgr::Initialize();
    iVar5 = CBBGDataMgr::GetOption();
    memcpy(local_17c,(void *)(iVar5 + DAT_001446c4),0xd);
    CBBGDailyMgr::SetDaily((sDaily)this_14,local_17c[0],local_178,local_174,local_170);
    iVar5 = CBBGDataMgr::GetOption();
    sVar6 = strlen((char *)(iVar5 + 0x1d0));
    if (8 < sVar6) {
      *(undefined *)(iVar5 + 0x1d8) = 0;
    }
    strcpy((char *)(this_14 + 0x25),(char *)(iVar5 + 0x1d0));
    iVar5 = CBBGDataMgr::GetOption();
    this_14[0x2e] = *(CBBGDailyMgr *)(iVar5 + 0x62);
    this_15 = (CBBGPopup *)operator_new(0x2c);
    CBBGPopup::CBBGPopup(this_15);
    *(undefined4 *)(this_15 + 0x28) = *(undefined4 *)(iVar9 + DAT_001446c8);
    this_16 = (CBBGResMgr *)operator_new(0x178);
    CBBGResMgr::CBBGResMgr(this_16);
    this_17 = (CBBGMissionData *)operator_new(0x150);
    CBBGMissionData::CBBGMissionData(this_17);
    this_18 = (CBBGChat *)operator_new(0x9c);
    CBBGChat::CBBGChat(this_18);
    this_19 = (CBBGEventMgr *)operator_new(0x430);
    CBBGEventMgr::CBBGEventMgr(this_19);
    CBBGEventMgr::SetReserveEvent(this_19,0xc);
    CBBTimer::ChangeRunnable((CBBTimer *)in_r0[0x20],0x100);
    CLx::Startup((char *)(iVar9 + DAT_00144760));
    CBBTimer::Start((CBBTimer *)in_r0[0x20],0x14);
    CBBGDataMgr::GetOption();
    CBBGOption::Apply();
    GsPutMemoryInfo((char *)(iVar9 + DAT_00144764));
    memset(local_16c,0,0x100);
    if (local_16c[0] != '\0') {
      CBBGPopup::CreatePopup
                (**(CBBGPopup ***)(iVar9 + DAT_0014476c),local_16c,'\x01',0x15b,'\0',(char **)0x0,0,
                 0);
    }
    piVar2 = *(int **)(iVar9 + iVar3);
    *(undefined *)(*piVar2 + DAT_00144768) = 1;
    changeUIStatus(0xe);
    iVar3 = *piVar2;
    *(undefined4 *)(iVar3 + 0x3ac) = *(undefined4 *)(iVar3 + 0x3a8);
    *(undefined4 *)(iVar3 + 0x3a8) = 0xe;
  }
  if (local_2c != **(int **)(iVar9 + iVar1)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


