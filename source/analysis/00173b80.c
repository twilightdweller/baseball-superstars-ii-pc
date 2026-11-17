/* CBBGLogoRun::~CBBGLogoRun at 00173b80; decompiler output, not buildable source */

/* CBBGLogoRun::~CBBGLogoRun() */

CBBGLogoRun * __thiscall CBBGLogoRun::~CBBGLogoRun(CBBGLogoRun *this)

{
  *(int *)this = *(int *)(DAT_00173ba0 + 0x173b8c + DAT_00173ba4) + 8;
  ReleaseObj();
  CBBRunnable::~CBBRunnable((CBBRunnable *)this);
  return this;
}


