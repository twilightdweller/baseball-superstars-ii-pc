/* CBBGMenuRun::EVENT_HANDLER_MSTATE_RECEIVE_GIFT at 0016e7dc; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_RECEIVE_GIFT() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_RECEIVE_GIFT(void)

{
  int in_r0;
  int iVar1;
  CBBStringBuffer aCStack_154 [296];
  undefined4 local_2c;
  
  iVar1 = DAT_0016eaa0 + 0x16e7f2;
  local_2c = **(undefined4 **)(iVar1 + DAT_0016eaa4);
  CBBStringBuffer::CBBStringBuffer(aCStack_154);
  if (9 < *(uint *)(in_r0 + 8)) {
    switchD_0016e81e::caseD_2();
    return;
  }
  iVar1 = iVar1 + DAT_0016eaac;
                    /* WARNING: Could not emulate address calculation at 0x0016e81a */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(iVar1 + *(uint *)(in_r0 + 8) * 4) + iVar1))();
  return;
}


