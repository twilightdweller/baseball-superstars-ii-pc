/* CBBGMenuRun::INIT_HANDLER_MSTATE_TITLE at 00169db4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_TITLE() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_TITLE(void)

{
  bool bVar1;
  int in_r0;
  int iVar2;
  CBBGPlayerData *pCVar3;
  int iVar4;
  CGsSound **ppCVar5;
  EnumPassiveSkills EVar6;
  CBBGDataMgr **ppCVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  
  iVar9 = DAT_00169f24;
  changeUIStatus(0xe);
  iVar9 = iVar9 + 0x169dd2;
  iVar4 = **(int **)(iVar9 + DAT_00169f28);
  iVar8 = 0;
  *(undefined4 *)(iVar4 + 0x3ac) = *(undefined4 *)(iVar4 + 0x3a8);
  *(undefined4 *)(iVar4 + 0x3a8) = 0xe;
  showTitleComponent();
  *(undefined *)(in_r0 + 0x15c) = 1;
  iVar4 = DAT_00169f2c;
  *(undefined4 *)(in_r0 + 8) = 0;
  bVar1 = false;
  CBBGResMgr::AddLoadRes(**(CBBGResMgr ***)(iVar9 + iVar4),0x12);
  ppCVar5 = *(CGsSound ***)(iVar9 + DAT_00169f30);
  CGsSound::Stop();
  CGsSound::Play(*ppCVar5,1,-1,'\x01');
  uVar10 = GsGetCurrentTime();
  *(undefined8 *)(in_r0 + 0x118) = uVar10;
  *(undefined *)(in_r0 + 0x120) = 0;
  iVar4 = DAT_00169f34;
  ppCVar7 = *(CBBGDataMgr ***)(iVar9 + DAT_00169f34);
  do {
    iVar2 = CBBGDataMgr::IsHallOfFrameSlot(*ppCVar7,iVar8,'\0');
    if ((iVar2 != 0) &&
       (pCVar3 = (CBBGPlayerData *)CBBGDataMgr::GetHallOfFameBatter(*ppCVar7,iVar8),
       pCVar3 != (CBBGPlayerData *)0x0)) {
      EVar6 = 0;
      do {
        iVar2 = CBBGPlayerData::HasPassiveSkill(pCVar3,EVar6);
        if ((iVar2 != 0) &&
           (iVar2 = CBBGCommonMenu::GetSkillType(*(CBBGCommonMenu **)(in_r0 + 0x6c),0,EVar6),
           iVar2 == 4)) {
          CBBGPlayerData::DelPassiveSkill(pCVar3,EVar6);
          bVar1 = true;
        }
        EVar6 = EVar6 + 1;
      } while (EVar6 != 0x20);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0x13);
  iVar8 = 0;
  ppCVar7 = *(CBBGDataMgr ***)(iVar9 + iVar4);
  do {
    iVar9 = CBBGDataMgr::IsHallOfFrameSlot(*ppCVar7,iVar8,'\x01');
    if ((iVar9 != 0) &&
       (pCVar3 = (CBBGPlayerData *)CBBGDataMgr::GetHallOfFamePitcher(*ppCVar7,iVar8),
       pCVar3 != (CBBGPlayerData *)0x0)) {
      EVar6 = 0;
      do {
        iVar9 = CBBGPlayerData::HasPassiveSkill(pCVar3,EVar6);
        if ((iVar9 != 0) &&
           (iVar9 = CBBGCommonMenu::GetSkillType(*(CBBGCommonMenu **)(in_r0 + 0x6c),1,EVar6),
           iVar9 == 4)) {
          CBBGPlayerData::DelPassiveSkill(pCVar3,EVar6);
          bVar1 = true;
        }
        EVar6 = EVar6 + 1;
      } while (EVar6 != 0x20);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0x13);
  if (bVar1) {
    CBBGDataMgr::SaveHallOfFame();
  }
  CBBGDataMgr::GetOption();
  return;
}


