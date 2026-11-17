/* CBBGResMgr::Release at 0018e800; decompiler output, not buildable source */

/* CBBGResMgr::Release(BBG_RES_ID) */

void __thiscall CBBGResMgr::Release(CBBGResMgr *this,BBG_RES_ID param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  BBG_RES_ID BVar4;
  int iVar5;
  int iVar6;
  CGxChangePaletteWRT *this_00;
  int iVar7;
  
  if ((*(int *)(param_1 * 4 + DAT_0018e908 + 0x18e812 + DAT_0018e90c) == 2) &&
     (0 < *(int *)(this + 0x154))) {
    iVar6 = 0;
    iVar7 = 0;
    BVar4 = **(BBG_RES_ID **)(this + 0x150);
    while (param_1 != BVar4) {
      iVar6 = iVar6 + 1;
      if (*(int *)(this + 0x154) <= iVar6) goto LAB_0018e81c;
      iVar7 = iVar6 * 4;
      BVar4 = (*(BBG_RES_ID **)(this + 0x150))[iVar6];
    }
    CGxChangePaletteWRT::Delete();
    this_00 = *(CGxChangePaletteWRT **)(*(int *)(this + 0x140) + iVar7);
    if (this_00 != (CGxChangePaletteWRT *)0x0) {
      CGxChangePaletteWRT::~CGxChangePaletteWRT(this_00);
      operator_delete(this_00);
      *(undefined4 *)(*(int *)(this + 0x140) + iVar7) = 0;
    }
    if (iVar6 < *(int *)(this + 0x144)) {
      iVar7 = *(int *)(this + 0x144) + -1;
      if (iVar6 < iVar7) {
        iVar2 = iVar6 << 2;
        iVar3 = (iVar6 + 1) * 4;
        iVar5 = iVar6;
        do {
          iVar5 = iVar5 + 1;
          puVar1 = (undefined4 *)(*(int *)(this + 0x140) + iVar3);
          iVar3 = iVar3 + 4;
          *(undefined4 *)(*(int *)(this + 0x140) + iVar2) = *puVar1;
          iVar2 = iVar2 + 4;
          iVar7 = *(int *)(this + 0x144) + -1;
        } while (iVar5 < iVar7);
      }
      *(int *)(this + 0x144) = iVar7;
    }
    if (iVar6 < *(int *)(this + 0x154)) {
      iVar7 = *(int *)(this + 0x154) + -1;
      if (iVar6 < iVar7) {
        iVar5 = iVar6 << 2;
        iVar6 = iVar6 + 1;
        iVar2 = iVar6 * 4;
        while( true ) {
          puVar1 = (undefined4 *)(*(int *)(this + 0x150) + iVar2);
          iVar2 = iVar2 + 4;
          *(undefined4 *)(*(int *)(this + 0x150) + iVar5) = *puVar1;
          iVar5 = iVar5 + 4;
          iVar7 = *(int *)(this + 0x154) + -1;
          if (iVar7 <= iVar6) break;
          iVar6 = iVar6 + 1;
        }
      }
      *(int *)(this + 0x154) = iVar7;
    }
  }
LAB_0018e81c:
  if (*(int **)(this + (param_1 + 2) * 4) != (int *)0x0) {
    (**(code **)(**(int **)(this + (param_1 + 2) * 4) + 4))();
  }
  *(undefined4 *)(this + (param_1 + 2) * 4) = 0;
  this[param_1 + 0xfc] = (CBBGResMgr)0x0;
  return;
}


