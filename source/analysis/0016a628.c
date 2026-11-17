/* CBBGMenuRun::~CBBGMenuRun at 0016a628; decompiler output, not buildable source */

/* CBBGMenuRun::~CBBGMenuRun() */

CBBGMenuRun * __thiscall CBBGMenuRun::~CBBGMenuRun(CBBGMenuRun *this)

{
  *(int *)this = *(int *)(DAT_0016a648 + 0x16a634 + DAT_0016a64c) + 8;
  ReleaseObj();
  CBBRunnable::~CBBRunnable((CBBRunnable *)this);
  return this;
}


