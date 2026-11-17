/* CBBGMenuRun::CBBGMenuRun at 0016a650; decompiler output, not buildable source */

/* CBBGMenuRun::CBBGMenuRun() */

CBBGMenuRun * __thiscall CBBGMenuRun::CBBGMenuRun(CBBGMenuRun *this)

{
  int iVar1;
  
  CBBRunnable::CBBRunnable((CBBRunnable *)this);
  iVar1 = DAT_0016a678;
  CBBState::CBBState((CBBState *)(this + 8));
  *(int *)this = *(int *)(iVar1 + 0x16a668 + DAT_0016a67c) + 8;
  Initialize();
  return this;
}


