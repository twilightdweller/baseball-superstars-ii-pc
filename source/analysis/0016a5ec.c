/* CBBGMenuRun::~CBBGMenuRun at 0016a5ec; decompiler output, not buildable source */

/* CBBGMenuRun::~CBBGMenuRun() */

CBBGMenuRun * __thiscall CBBGMenuRun::~CBBGMenuRun(CBBGMenuRun *this)

{
  *(int *)this = *(int *)(DAT_0016a60c + 0x16a5f8 + DAT_0016a610) + 8;
  ReleaseObj();
  CBBRunnable::~CBBRunnable((CBBRunnable *)this);
  return this;
}


