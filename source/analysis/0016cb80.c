/* CBBGMenuRun::INIT_HANDLER_MSTATE_RANKING at 0016cb80; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_RANKING() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_RANKING(void)

{
  int in_r0;
  int iVar1;
  int iVar2;
  char *__src;
  size_t sVar3;
  int iVar4;
  char *__dest;
  CGsAutomata *this;
  CGsAutomata **ppCVar5;
  
  *(undefined4 *)(in_r0 + 8) = 0;
  CBBGCommonMenu::InitCommonSpecial();
  iVar4 = *(int *)(in_r0 + 0x6c);
  *(undefined4 *)(iVar4 + 0x368) = DAT_0016ccb0;
  *(undefined4 *)(iVar4 + 0x36c) = 0xe0;
  *(undefined *)(in_r0 + 0xb9) = 0;
  *(undefined4 *)(in_r0 + 0xbc) = 0;
  *(undefined *)(in_r0 + 0xc0) = 1;
  *(undefined *)(in_r0 + 0xc1) = 0;
  *(undefined4 *)(in_r0 + 0xc4) = *(undefined4 *)(in_r0 + 0x94);
  iVar4 = DAT_0016ccb4;
  *(undefined4 *)(*(int *)(in_r0 + 0x6c) + 0x480) = 0;
  iVar4 = iVar4 + 0x16cbd2;
  CBBGSatellite::InitRankSearch();
  iVar1 = CBBGDataMgr::GetOption();
  if (*(char *)(iVar1 + 0x58) == '\0') {
    *(undefined4 *)(in_r0 + 8) = 100;
  }
  CBBGCommonMenu::InitializeAutomaWindow(*(CBBGCommonMenu **)(in_r0 + 0x6c),3,8,'\x01','\x01');
  iVar1 = DAT_0016ccc0;
  ppCVar5 = *(CGsAutomata ***)(iVar4 + DAT_0016ccc0);
  this = *ppCVar5;
  iVar2 = CBBGDataMgr::GetOption();
  CGsAutomata::SetText(this,(char *)(iVar2 + 0x4f));
  __dest = (char *)(in_r0 + 200);
  *__dest = '\0';
  *(undefined *)(in_r0 + 0xc9) = 0;
  *(undefined *)(in_r0 + 0xca) = 0;
  *(undefined *)(in_r0 + 0xcb) = 0;
  *(undefined *)(in_r0 + 0xcc) = 0;
  *(undefined *)(in_r0 + 0xcd) = 0;
  *(undefined *)(in_r0 + 0xce) = 0;
  *(undefined *)(in_r0 + 0xcf) = 0;
  *(undefined *)(in_r0 + 0xd0) = 0;
  *(undefined *)(in_r0 + 0xd1) = 0;
  *(undefined *)(in_r0 + 0xd2) = 0;
  *(undefined *)(in_r0 + 0xd3) = 0;
  strcpy(__dest,(char *)(*ppCVar5 + 0x28));
  if (*(char *)(in_r0 + 200) == '\0') {
    __src = (char *)CBBGResMgr::GetGameCodeStr
                              (**(CBBGResMgr ***)(iVar4 + DAT_0016ccc4),DAT_0016ccc8);
    strcpy(__dest,__src);
    iVar2 = CBBGDataMgr::GetOption();
    sVar3 = strlen(__dest);
    if (8 < sVar3) {
      *(undefined *)(in_r0 + 0xd0) = 0;
    }
    strcpy((char *)(iVar2 + 0x4f),__dest);
    CGsAutomata::SetText(**(CGsAutomata ***)(iVar4 + iVar1),__dest);
  }
  return;
}


