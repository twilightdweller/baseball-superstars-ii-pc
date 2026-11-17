/* CBBStartUp::EvPointerMove at 001439d4; decompiler output, not buildable source */

/* CBBStartUp::EvPointerMove(GxPointerPos*) */

void __thiscall CBBStartUp::EvPointerMove(CBBStartUp *this,GxPointerPos *param_1)

{
  int *piVar1;
  int iVar2;
  GVUIMainSystem **ppGVar3;
  int iVar4;
  GVUIMainSystem *this_00;
  
  iVar4 = DAT_00143a64 + 0x1439e4;
  iVar2 = *(int *)(**(int **)(iVar4 + DAT_00143a68) + 0x3a8);
  if ((((iVar2 < 0x20) && (iVar2 != 9)) &&
      (*(char *)(**(int **)(iVar4 + DAT_00143a68) + DAT_00143a6c) == '\0')) &&
     ((iVar2 = *(int *)(**(int **)(iVar4 + DAT_00143a70) + 0xa4), iVar2 != 0 && (iVar2 != 2)))) {
    if (*(int *)(param_1 + 0xc) != 10) {
      ppGVar3 = *(GVUIMainSystem ***)(iVar4 + DAT_00143a74);
      this_00 = *ppGVar3;
      if (this_00 == (GVUIMainSystem *)0x0) {
        this_00 = (GVUIMainSystem *)operator_new(0x40);
        GVUIMainSystem::GVUIMainSystem(this_00);
        *ppGVar3 = this_00;
      }
      iVar2 = GVUISystem::PointerMove((GVUISystem *)this_00,*(int *)param_1,*(int *)(param_1 + 4));
      if (iVar2 != 0) {
        return;
      }
    }
    *(undefined *)(**(int **)(iVar4 + DAT_00143a78) + 0x38) = 1;
    piVar1 = *(int **)(this + 0x80);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x28))(piVar1,param_1);
    }
  }
  return;
}


