/* CBBStartUp::EvPointerRelease at 00144838; decompiler output, not buildable source */

/* CBBStartUp::EvPointerRelease(GxPointerPos*) */

void __thiscall CBBStartUp::EvPointerRelease(CBBStartUp *this,GxPointerPos *param_1)

{
  int *piVar1;
  int iVar2;
  GVUIMainSystem **ppGVar3;
  CGsTouchMgr *pCVar4;
  int iVar5;
  GVUIMainSystem *this_00;
  CGsTouchMgr **ppCVar6;
  
  iVar5 = DAT_001448f4 + 0x144848;
  iVar2 = *(int *)(**(int **)(iVar5 + DAT_001448f8) + 0x3a8);
  if (0x1f < iVar2) {
    return;
  }
  if (iVar2 == 9) {
    return;
  }
  if (*(char *)(**(int **)(iVar5 + DAT_001448f8) + DAT_001448fc) != '\0') {
    return;
  }
  iVar2 = *(int *)(**(int **)(iVar5 + DAT_00144900) + 0xa4);
  if (iVar2 == 0) {
    return;
  }
  if (iVar2 == 2) {
    return;
  }
  if (*(int *)(param_1 + 0xc) != 10) {
    ppGVar3 = *(GVUIMainSystem ***)(iVar5 + DAT_00144904);
    this_00 = *ppGVar3;
    if (this_00 == (GVUIMainSystem *)0x0) {
      this_00 = (GVUIMainSystem *)operator_new(0x40);
      GVUIMainSystem::GVUIMainSystem(this_00);
      *ppGVar3 = this_00;
    }
    iVar2 = GVUISystem::PointerRelease((GVUISystem *)this_00,*(int *)param_1,*(int *)(param_1 + 4));
    if (iVar2 != 0) {
      return;
    }
  }
  ppCVar6 = *(CGsTouchMgr ***)(iVar5 + DAT_00144908);
  CGsTouchMgr::RunTouchScreen(*ppCVar6,param_1,'\0');
  pCVar4 = *ppCVar6;
  if (pCVar4[0x25] == (CGsTouchMgr)0xff) {
    iVar2 = *(int *)(pCVar4 + 0x28);
    if (iVar2 == 0) goto LAB_001448c2;
  }
  else {
    iVar2 = *(int *)(pCVar4 + 0x28);
  }
  (**(code **)(*(int *)this + 0x1c))(this,iVar2);
  CGsTouchMgr::ClearTouch();
LAB_001448c2:
  piVar1 = *(int **)(this + 0x80);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(piVar1,param_1);
  }
  return;
}


