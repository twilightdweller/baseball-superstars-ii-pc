/* CCLSpline::Bezier; research only, not buildable source */

/* CCLSpline::Bezier(int, tagCLxPoint3*, int, tagCLxPoint3*) */

void __thiscall
CCLSpline::Bezier(CCLSpline *this,int param_1,tagCLxPoint3 *param_2,int param_3,
                 tagCLxPoint3 *param_4)

{
  tagCLxPoint3 *ptVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  longlong lVar12;
  uint local_78;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  
  if (0 < param_1) {
    iVar6 = 0;
    do {
      iVar3 = iVar6 * 4;
      iVar6 = iVar6 + 1;
      *(tagCLxPoint3 *)(*(int *)(this + 4) + iVar3) = *param_2;
      *(tagCLxPoint3 *)(*(int *)(this + 8) + iVar3) = param_2[1];
      ptVar1 = param_2 + 2;
      param_2 = param_2 + 3;
      *(tagCLxPoint3 *)(*(int *)(this + 0xc) + iVar3) = *ptVar1;
    } while (iVar6 != param_1);
  }
  iVar3 = *(int *)(this + 0x14);
  local_78 = iVar3 << 0x12;
  uVar2 = __aeabi_ldivmod(0,((int)local_78 >> 0x1f) << 0x12 | local_78 >> 0xe,DAT_000c2848,
                          DAT_000c284c);
  iVar7 = (param_3 + -1) * 0x40000;
  iVar8 = iVar7 >> 0x1f;
  iVar6 = __aeabi_ldivmod(uVar2 * -0x40000,
                          ((int)(0x40000 - uVar2) >> 0x1f) << 0x12 | 0x40000 - uVar2 >> 0xe,iVar7,
                          iVar8);
  uVar11 = (0x5a - iVar3) * 0x40000;
  iVar3 = __aeabi_ldivmod(0,((int)uVar11 >> 0x1f) << 0x12 | uVar11 >> 0xe,iVar7,iVar8);
  if (0 < param_3) {
    iVar10 = 1;
    do {
      iVar9 = *(int *)(this + 0x10);
      if (iVar9 == 2) {
        uVar11 = CLMath::xSin(local_78);
        local_78 = local_78 + iVar3;
      }
      else if (iVar9 < 3) {
        if (iVar9 == 1) {
          iVar9 = CLMath::xSin(0x1680000 - local_78);
          uVar11 = 0x40000 - iVar9;
          local_78 = local_78 + iVar3;
        }
        else {
LAB_000c2716:
          uVar11 = (iVar10 + -1) * 0x40000;
          uVar11 = __aeabi_ldivmod(0,((int)uVar11 >> 0x1f) << 0x12 | uVar11 >> 0xe,iVar7,iVar8);
        }
      }
      else {
        iVar5 = (int)uVar2 >> 0x1f;
        uVar11 = uVar2;
        iVar4 = iVar5;
        if (iVar9 != 3) {
          if (iVar9 != 4) goto LAB_000c2716;
          lVar12 = __aeabi_lmul(uVar2,iVar5,uVar2,iVar5);
          lVar12 = lVar12 + CONCAT44(DAT_000c2854,DAT_000c2850);
          uVar11 = (uint)lVar12 >> 0x12 | (int)((ulonglong)lVar12 >> 0x20) * 0x4000;
          iVar4 = (int)uVar11 >> 0x1f;
        }
        lVar12 = __aeabi_lmul(uVar11,iVar4,uVar2,iVar5);
        lVar12 = lVar12 + CONCAT44(DAT_000c2854,DAT_000c2850);
        uVar11 = (uint)lVar12 >> 0x12 | (int)((ulonglong)lVar12 >> 0x20) * 0x4000;
        uVar2 = uVar2 + iVar6;
      }
      bc_val(this,param_1 + -1,uVar11,*(long **)(this + 0xc),*(long **)(this + 4),(long *)&local_34,
             (long *)&local_2c);
      bc_val(this,param_1 + -1,uVar11,*(long **)(this + 0xc),*(long **)(this + 8),(long *)&local_34,
             (long *)&local_30);
      iVar10 = iVar10 + 1;
      *(undefined *)param_4 = local_2c;
      *(undefined *)((int)param_4 + 1) = local_2b;
      *(undefined *)((int)param_4 + 2) = local_2a;
      *(undefined *)((int)param_4 + 3) = local_29;
      *(undefined *)(param_4 + 1) = local_30;
      *(undefined *)((int)param_4 + 5) = local_2f;
      *(undefined *)((int)param_4 + 6) = local_2e;
      *(undefined *)((int)param_4 + 7) = local_2d;
      *(undefined *)(param_4 + 2) = local_34;
      *(undefined *)((int)param_4 + 9) = local_33;
      *(undefined *)((int)param_4 + 10) = local_32;
      *(undefined *)((int)param_4 + 0xb) = local_31;
      param_4 = param_4 + 3;
    } while (iVar10 <= param_3);
  }
  return;
}


