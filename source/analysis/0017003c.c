/* CBBGMenuRun::EVENT_HANDLER_MSTATE_GSHOP at 0017003c; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_GSHOP() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_GSHOP(void)

{
  int in_r0;
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_00170360 + 0x170056;
  *(undefined4 *)(&stack0x00000208 + DAT_00170358) = **(undefined4 **)(iVar2 + DAT_0017035c);
  uVar1 = *(int *)(in_r0 + 0xc) - 0x16;
  if (uVar1 < 5) {
                    /* WARNING: Could not emulate address calculation at 0x0017006a */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar2 + DAT_00170364 + uVar1 * 4) + iVar2 + DAT_00170364))();
    return;
  }
  if (*(int *)(&stack0x00000208 + DAT_00170358) != **(int **)(iVar2 + DAT_0017035c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


