/* CBBGMenuRun::DRAW_HANDLER_MSTATE_SPECIAL at 001723ec; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DRAW_HANDLER_MSTATE_SPECIAL() */

void CBBGMenuRun::DRAW_HANDLER_MSTATE_SPECIAL(void)

{
  int in_r0;
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_00172770 + 0x172402;
  uVar1 = *(int *)(in_r0 + 0xc) - 0x1b;
  if (uVar1 < 7) {
                    /* WARNING: Could not emulate address calculation at 0x00172418 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar2 + DAT_00172778 + uVar1 * 4) + iVar2 + DAT_00172778))();
    return;
  }
  if (**(int **)(iVar2 + DAT_00172774) != **(int **)(iVar2 + DAT_00172774)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


