/* CBBGMenuRun::INIT_HANDLER_MSTATE_GSHOP at 0016dc64; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_GSHOP() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_GSHOP(void)

{
  int in_r0;
  int iVar1;
  uint uVar2;
  
  uVar2 = *(int *)(in_r0 + 0xc) - 0x16;
  if (uVar2 < 5) {
    iVar1 = DAT_0016dde4 + 0x16dc72 + DAT_0016dde8;
                    /* WARNING: Could not emulate address calculation at 0x0016dc7c */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar1 + uVar2 * 4) + iVar1))();
    return;
  }
  return;
}


