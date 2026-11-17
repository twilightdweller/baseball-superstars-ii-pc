/* CBBGLogoRun::KeyPressed at 00173330; decompiler output, not buildable source */

/* CBBGLogoRun::KeyPressed(int) */

void __thiscall CBBGLogoRun::KeyPressed(CBBGLogoRun *this,int param_1)

{
  int iVar1;
  
  iVar1 = **(int **)(DAT_0017334c + 0x173338 + DAT_00173350);
  if ((*(int *)(iVar1 + 4) == 0) || (*(int *)(iVar1 + 0x10) == 0)) {
    *(int *)(this + 0x28) = param_1;
  }
  return;
}


