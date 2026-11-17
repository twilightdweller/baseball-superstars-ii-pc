/* CBBGMenuRun::CBBGMenuRun at 0016a680; decompiler output, not buildable source */

/* CBBGMenuRun::CBBGMenuRun() */

CBBGMenuRun * __thiscall CBBGMenuRun::CBBGMenuRun(CBBGMenuRun *this)

{
  int iVar1;
  
  CBBRunnable::CBBRunnable((CBBRunnable *)this);
  iVar1 = DAT_0016a6a8;
  CBBState::CBBState((CBBState *)(this + 8));
  *(int *)this = *(int *)(iVar1 + 0x16a698 + DAT_0016a6ac) + 8;
  Initialize();
  return this;
}


