/* CBBGMenuRun::EVENT_HANDLER_MSTATE_HELP at 00168a44; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_HELP() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_HELP(void)

{
  int in_r0;
  int iVar1;
  int iVar2;
  int *this;
  int **ppiVar3;
  
  iVar2 = DAT_00168a88 + 0x168a52;
  iVar1 = CBBGCommonMenu::RunHelp(*(CBBGCommonMenu **)(in_r0 + 0x6c),*(int *)(in_r0 + 0x30));
  if (iVar1 == -100) {
    CBBState::ReserveState((CBBState *)(in_r0 + 8),7);
    ppiVar3 = *(int ***)(iVar2 + DAT_00168a8c);
    this = *ppiVar3;
    if (this == (int *)0x0) {
      this = (int *)operator_new(0x40);
      GVUIMainSystem::GVUIMainSystem((GVUIMainSystem *)this);
      *ppiVar3 = this;
    }
    (**(code **)(*this + 8))(this);
  }
  return;
}


