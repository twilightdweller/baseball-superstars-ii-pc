/* CBBGLogoRun::EVENT_HANDLER_MSTATE_WARNING at 00173668; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::EVENT_HANDLER_MSTATE_WARNING() */

void CBBGLogoRun::EVENT_HANDLER_MSTATE_WARNING(void)

{
  uint uVar1;
  uint uVar2;
  int in_r0;
  undefined8 uVar3;
  
  if (*(int *)(in_r0 + 0x30) == 0) {
    uVar3 = GsGetCurrentTime();
    uVar1 = (int)((ulonglong)uVar3 >> 0x20) - *(int *)(in_r0 + 0x7c);
    uVar2 = (uint)((uint)uVar3 < *(uint *)(in_r0 + 0x78));
    if ((int)(uVar1 - uVar2) < 1) {
      if (uVar1 != uVar2) {
        return;
      }
      if ((uint)uVar3 - *(uint *)(in_r0 + 0x78) <= DAT_001736b8) {
        return;
      }
    }
    *(undefined *)(in_r0 + 0x70) = 1;
  }
  CBBGDataMgr::SaveOption();
  CBBState::ReserveState((CBBState *)(in_r0 + 8),5);
  return;
}


