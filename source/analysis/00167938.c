/* CBBGMenuRun::INIT_HANDLER_MSTATE_GAME_START at 00167938; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_GAME_START() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_GAME_START(void)

{
  int in_r0;
  int iVar1;
  
  *(undefined4 *)(in_r0 + 8) = 0;
  iVar1 = CBBGDataMgr::GetOption();
  *(undefined *)(iVar1 + 99) = 0xff;
  iVar1 = CBBGDataMgr::GetOption();
  *(undefined *)(iVar1 + 100) = 0xff;
  return;
}


