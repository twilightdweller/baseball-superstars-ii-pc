/* CBBGLogoRun::CBBGLogoRun at 00173bd8; decompiler output, not buildable source */

/* CBBGLogoRun::CBBGLogoRun() */

CBBGLogoRun * __thiscall CBBGLogoRun::CBBGLogoRun(CBBGLogoRun *this)

{
  int iVar1;
  
  CBBRunnable::CBBRunnable((CBBRunnable *)this);
  iVar1 = DAT_00173c00;
  CBBState::CBBState((CBBState *)(this + 8));
  *(int *)this = *(int *)(iVar1 + 0x173bf0 + DAT_00173c04) + 8;
  Initialize();
  return this;
}


