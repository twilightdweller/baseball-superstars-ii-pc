/* CBBGMenuRun::EVENT_HANDLER_MSTATE_TERMINATE at 00169ab0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_TERMINATE() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_TERMINATE(void)

{
  int in_r0;
  CBBTimer *this;
  CBBGScreenMng *pCVar1;
  CBBGScreenMng **ppCVar2;
  
  ppCVar2 = *(CBBGScreenMng ***)(DAT_00169aec + 0x169abc + DAT_00169af0);
  pCVar1 = *ppCVar2;
  if ((*(int *)(pCVar1 + 4) != 0) && (*(int *)(pCVar1 + 0x10) == 2)) {
    this = (CBBTimer *)CBBGTimer::GetInstance();
    CBBTimer::ChangeRunnable(this,*(int *)(in_r0 + 0x68));
    CBBGScreenMng::SetMode(*ppCVar2,2,0,5,DAT_00169af4);
  }
  return;
}


