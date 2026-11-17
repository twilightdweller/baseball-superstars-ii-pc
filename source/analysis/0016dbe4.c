/* CBBGMenuRun::EVENT_HANDLER_MSTATE_GAME_START at 0016dbe4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_GAME_START() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_GAME_START(void)

{
  int in_r0;
  int iVar1;
  int local_34 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  iVar1 = DAT_0016dc58 + 0x16dbf6 + DAT_0016dc5c;
  local_34[0] = *(int *)(iVar1 + 0x14);
  local_34[1] = *(undefined4 *)(iVar1 + 0x18);
  local_34[2] = *(undefined4 *)(iVar1 + 0x1c);
  local_34[3] = *(undefined4 *)(iVar1 + 0x20);
  uStack_24 = *(undefined4 *)(iVar1 + 0x24);
  uStack_20 = *(undefined4 *)(iVar1 + 0x28);
  local_1c = *(undefined4 *)(iVar1 + 0x2c);
  if (local_34[*(int *)(in_r0 + 0x94)] - 0xfU < 7) {
    iVar1 = DAT_0016dc58 + 0x16dbf6 + DAT_0016dc60;
                    /* WARNING: Could not emulate address calculation at 0x0016dc1a */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar1 + (local_34[*(int *)(in_r0 + 0x94)] - 0xfU) * 4) + iVar1))();
    return;
  }
  return;
}


