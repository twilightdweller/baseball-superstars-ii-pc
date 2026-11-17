/* CBBGMenuRun::INIT_HANDLER_MSTATE_SPECIAL at 00168b54; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_SPECIAL() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_SPECIAL(void)

{
  int in_r0;
  int iVar1;
  uint uVar2;
  
  *(undefined4 *)(in_r0 + 8) = 0;
  uVar2 = *(int *)(in_r0 + 0xc) - 0x1d;
  if (4 < uVar2) {
    return;
  }
  iVar1 = DAT_00168e44 + 0x168b6c + DAT_00168e48;
                    /* WARNING: Could not emulate address calculation at 0x00168b78 */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(iVar1 + uVar2 * 4) + iVar1))();
  return;
}


