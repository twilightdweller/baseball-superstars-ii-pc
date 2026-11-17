/* CBBGMenuRun::INIT_HANDLER_MSTATE_SETTING at 00168a00; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_SETTING() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_SETTING(void)

{
  int in_r0;
  int iVar1;
  
  if (1 < *(int *)(in_r0 + 0x18) - 0x22U) {
    iVar1 = *(int *)(in_r0 + 0x94);
    CGsSound::Stop();
    CBBGCommonMenu::InitGameSetting(*(CBBGCommonMenu **)(in_r0 + 0x6c),iVar1,'\0');
    *(undefined4 *)(in_r0 + 0xfc) = 0;
    *(undefined4 *)(in_r0 + 0x100) = 0;
    *(undefined *)(in_r0 + 0x104) = 0;
  }
  return;
}


