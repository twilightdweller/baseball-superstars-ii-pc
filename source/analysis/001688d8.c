/* CBBGMenuRun::INIT_HANDLER_MSTATE_RANKING_LIST at 001688d8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_RANKING_LIST() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_RANKING_LIST(void)

{
  int in_r0;
  int iVar1;
  
  CBBGResMgr::AddLoadRes(**(CBBGResMgr ***)(DAT_00168928 + 0x1688e4 + DAT_0016892c),0x19);
  *(undefined *)(in_r0 + 0xd4) = 1;
  iVar1 = DAT_00168930;
  *(undefined4 *)(in_r0 + 8) = 0;
  *(undefined *)(*(int *)(in_r0 + 0x6c) + iVar1) = 0;
  *(undefined *)(*(int *)(in_r0 + 0x6c) + iVar1 + 1) = 0;
  iVar1 = *(int *)(in_r0 + 0x6c);
  *(undefined4 *)(iVar1 + 0x368) = 0xc2;
  *(undefined4 *)(iVar1 + 0x36c) = 0xf5;
  iVar1 = *(int *)(in_r0 + 0x6c);
  *(undefined4 *)(iVar1 + 0x368) = 0x15b;
  *(undefined4 *)(iVar1 + 0x36c) = DAT_00168934;
  InitRankingViewScroll();
  return;
}


