/* CBBGLogoRun::CBBGLogoRun at 00173ba8; decompiler output, not buildable source */

/* CBBGLogoRun::CBBGLogoRun() */

CBBGLogoRun * __thiscall CBBGLogoRun::CBBGLogoRun(CBBGLogoRun *this)

{
  int iVar1;
  
  CBBRunnable::CBBRunnable((CBBRunnable *)this);
  iVar1 = DAT_00173bd0;
  CBBState::CBBState((CBBState *)(this + 8));
  *(int *)this = *(int *)(iVar1 + 0x173bc0 + DAT_00173bd4) + 8;
  Initialize();
  return this;
}


