/* CBBGLogoRun::~CBBGLogoRun at 00173b44; decompiler output, not buildable source */

/* CBBGLogoRun::~CBBGLogoRun() */

CBBGLogoRun * __thiscall CBBGLogoRun::~CBBGLogoRun(CBBGLogoRun *this)

{
  *(int *)this = *(int *)(DAT_00173b64 + 0x173b50 + DAT_00173b68) + 8;
  ReleaseObj();
  CBBRunnable::~CBBRunnable((CBBRunnable *)this);
  return this;
}


