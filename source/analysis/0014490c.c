/* CBBStartUp::EvPointerPress at 0014490c; decompiler output, not buildable source */

/* CBBStartUp::EvPointerPress(GxPointerPos*) */

void __thiscall CBBStartUp::EvPointerPress(CBBStartUp *this,GxPointerPos *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  GVUIMainSystem **ppGVar4;
  CGsTouchMgr **ppCVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  GVUIMainSystem *this_00;
  CGsTouchMgr *pCVar10;
  CGsOemIME **ppCVar11;
  
  iVar7 = DAT_00144ad4 + 0x14491e;
  iVar3 = *(int *)(**(int **)(iVar7 + DAT_00144ad8) + 0x3a8);
  if (0x1f < iVar3) {
    if ((((iVar3 != 0x20) && (iVar3 != 0x21)) && (iVar3 != 0x22)) && (iVar3 != 0x23)) {
      return;
    }
    uVar9 = *(uint *)param_1;
    if (0x32 < uVar9) {
      return;
    }
    iVar8 = *(int *)(param_1 + 4);
    iVar3 = *(int *)(**(int **)(iVar7 + DAT_00144adc) + 0x3c) +
            *(int *)(**(int **)(iVar7 + DAT_00144adc) + 0x4c);
    if (iVar3 < iVar8) {
      return;
    }
    if (iVar8 < iVar3 + -0x1e) {
      return;
    }
    iVar3 = GcxGetMainScreenBuffer();
    CreateParticle(uVar9,iVar8 - *(int *)(iVar3 + 0x44),0x1c,1,'\0',-1,'\0','\0');
    (**(code **)(*(int *)this + 0x18))(this,0xfffffff0);
    return;
  }
  if (iVar3 == 9) {
    return;
  }
  if (*(char *)(**(int **)(iVar7 + DAT_00144ad8) + DAT_00144ae0) != '\0') {
    return;
  }
  iVar3 = *(int *)(**(int **)(iVar7 + DAT_00144ae4) + 0xa4);
  if (iVar3 == 0) {
    return;
  }
  if (iVar3 == 2) {
    return;
  }
  if (*(int *)(param_1 + 0xc) != 10) {
    ppGVar4 = *(GVUIMainSystem ***)(iVar7 + DAT_00144ae8);
    this_00 = *ppGVar4;
    if (this_00 == (GVUIMainSystem *)0x0) {
      this_00 = (GVUIMainSystem *)operator_new(0x40);
      GVUIMainSystem::GVUIMainSystem(this_00);
      *ppGVar4 = this_00;
    }
    iVar3 = GVUISystem::PointerPress((GVUISystem *)this_00,*(int *)param_1,*(int *)(param_1 + 4));
    if (iVar3 != 0) {
      return;
    }
  }
  iVar3 = *(int *)param_1;
  uVar2 = *(undefined4 *)(param_1 + 4);
  ppCVar5 = *(CGsTouchMgr ***)(iVar7 + DAT_00144aec);
  pCVar10 = *ppCVar5;
  uVar6 = *(undefined4 *)(param_1 + 8);
  *(int *)(pCVar10 + 0x3c) = iVar3;
  *(undefined4 *)(pCVar10 + 0x40) = uVar2;
  *(undefined4 *)(pCVar10 + 0x44) = uVar6;
  CGsTouchMgr::CallTouchParticle((int)pCVar10,iVar3);
  pCVar10[0x38] = (CGsTouchMgr)0x0;
  pCVar10[0x25] = (CGsTouchMgr)0xff;
  *(undefined4 *)(pCVar10 + 0x28) = 0;
  CGsTouchMgr::RunTouchScreen(*ppCVar5,param_1,'\x01');
  pCVar10 = *ppCVar5;
  if (pCVar10[0x25] == (CGsTouchMgr)0xff) {
    iVar3 = *(int *)(pCVar10 + 0x28);
    if (iVar3 == 0) goto LAB_00144a22;
  }
  else {
    iVar3 = *(int *)(pCVar10 + 0x28);
  }
  (**(code **)(*(int *)this + 0x18))(this,iVar3);
LAB_00144a22:
  ppCVar11 = *(CGsOemIME ***)(iVar7 + DAT_00144af0);
  CGsOemIME::OnPointerRelease(*ppCVar11,param_1);
  if ((*ppCVar11)[0x10] == (CGsOemIME)0x0) {
    iVar8 = *(int *)param_1;
    iVar7 = *(int *)(param_1 + 4);
    iVar3 = GcxGetMainScreenBuffer();
    CreateParticle(iVar8,iVar7 - *(int *)(iVar3 + 0x44),0x1c,1,'\0',-1,'\0','\0');
    piVar1 = *(int **)(this + 0x80);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x20))(piVar1,param_1);
    }
  }
  else {
    uVar9 = *(uint *)param_1;
    if (uVar9 < 0x33) {
      iVar8 = *(int *)(param_1 + 4);
      iVar3 = *(int *)(**(int **)(iVar7 + DAT_00144adc) + 0x3c) +
              *(int *)(**(int **)(iVar7 + DAT_00144adc) + 0x4c);
      if ((iVar8 <= iVar3) && (iVar3 + -0x1e <= iVar8)) {
        iVar3 = GcxGetMainScreenBuffer();
        CreateParticle(uVar9,iVar8 - *(int *)(iVar3 + 0x44),0x1c,1,'\0',-1,'\0','\0');
        CGsOemIME::CloseOemIME();
      }
    }
  }
  return;
}


