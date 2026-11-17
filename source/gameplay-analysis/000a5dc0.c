/* CCLFigureMgr::xToVirtual; research only, not buildable source */

/* CCLFigureMgr::xToVirtual(bbtagPoint2D) */

bbtagPoint2D CCLFigureMgr::xToVirtual(bbtagPoint2D param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int in_r1;
  int in_r2;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_r3;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  
  iVar4 = *(int *)(in_r1 + 0xc);
  iVar5 = iVar4 << 0x12;
  iVar7 = *(int *)(in_r1 + 8);
  lVar9 = __aeabi_lmul(iVar5,iVar5 >> 0x1f,iVar7,iVar7 >> 0x1f);
  lVar1 = CONCAT44(DAT_000a5efc,DAT_000a5ef8);
  iVar2 = (int)(((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000)
               + 0x20000) >> 0x12;
  iVar6 = *(int *)(in_r1 + 0x10) << 0x12;
  lVar9 = __aeabi_lmul(iVar6,iVar6 >> 0x1f,iVar7,iVar7 >> 0x1f);
  iVar7 = (int)(((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000)
               + 0x20000) >> 0x12;
  iVar3 = __aeabi_idiv(*(int *)(in_r1 + 0x3c) * iVar7,*(undefined4 *)(in_r1 + 0x10));
  iVar4 = __aeabi_idiv(iVar2 * *(int *)(in_r1 + 0x38),iVar4);
  uVar8 = iVar2 << 0x12;
  iVar2 = __aeabi_ldivmod(0,((int)uVar8 >> 0x1f) << 0x12 | uVar8 >> 0xe,iVar5,iVar5 >> 0x1f);
  lVar9 = __aeabi_lmul(iVar2,iVar2 >> 0x1f,in_r2 << 0x12,(in_r2 << 0x12) >> 0x1f);
  iVar2 = iVar4 * 0x40000 -
          ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000);
  *(char *)(param_1 + 1) = (char)((uint)iVar2 >> 8);
  *(char *)(param_1 + 2) = (char)((uint)iVar2 >> 0x10);
  uVar8 = iVar7 << 0x12;
  *(char *)param_1 = (char)iVar2;
  *(char *)(param_1 + 3) = (char)((uint)iVar2 >> 0x18);
  *(undefined *)(param_1 + 4) = 0;
  *(undefined *)(param_1 + 5) = 0;
  *(undefined *)(param_1 + 6) = 0;
  *(undefined *)(param_1 + 7) = 0;
  iVar2 = __aeabi_ldivmod(0,((int)uVar8 >> 0x1f) << 0x12 | uVar8 >> 0xe,iVar6,iVar6 >> 0x1f);
  lVar9 = __aeabi_lmul(iVar2,iVar2 >> 0x1f,in_r3 << 0x12,(in_r3 << 0x12) >> 0x1f);
  iVar2 = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
          iVar3 * -0x40000;
  *(char *)(param_1 + 8) = (char)iVar2;
  *(char *)(param_1 + 9) = (char)((uint)iVar2 >> 8);
  *(char *)(param_1 + 0xb) = (char)((uint)iVar2 >> 0x18);
  *(char *)(param_1 + 10) = (char)((uint)iVar2 >> 0x10);
  return param_1;
}


