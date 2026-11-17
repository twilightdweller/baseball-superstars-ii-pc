/* CBBGLogoRun::KeyReleased at 00173354; decompiler output, not buildable source */

/* CBBGLogoRun::KeyReleased(int) */

void __thiscall CBBGLogoRun::KeyReleased(CBBGLogoRun *this,int param_1)

{
  int iVar1;
  
  iVar1 = **(int **)(DAT_00173370 + 0x17335c + DAT_00173374);
  if ((*(int *)(iVar1 + 4) == 0) || (*(int *)(iVar1 + 0x10) == 0)) {
    *(int *)(this + 0x2c) = param_1;
  }
  return;
}


