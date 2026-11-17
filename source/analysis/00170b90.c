/* CBBGMenuRun::EVENT_HANDLER_MSTATE_SPECIAL at 00170b90; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_SPECIAL() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_SPECIAL(void)

{
  int in_r0;
  int iVar1;
  uint uVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined local_30;
  undefined4 local_2c;
  
  local_2c = **(undefined4 **)(DAT_00170ea0 + 0x170ba6 + DAT_00170ea4);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  uVar2 = *(int *)(in_r0 + 0xc) - 0x1b;
  if (6 < uVar2) {
    FUN_00170cd2();
    return;
  }
  iVar1 = DAT_00170ea0 + 0x170ba6 + DAT_00170ea8;
                    /* WARNING: Could not emulate address calculation at 0x00170bd2 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(iVar1 + uVar2 * 4) + iVar1))(&local_38,*(undefined4 *)(in_r0 + 0x30));
  return;
}


