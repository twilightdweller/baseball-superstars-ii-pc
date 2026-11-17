/* CCLPitch::UpdatePitch; research only, not buildable source */

/* CCLPitch::UpdatePitch(bool) */

void __thiscall CCLPitch::UpdatePitch(CCLPitch *this,bool param_1)

{
  undefined *puVar1;
  ushort uVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  ushort *puVar18;
  uint uVar19;
  uint uVar20;
  uint *puVar21;
  int iVar22;
  tagCLxPoint3 *ptVar23;
  longlong lVar24;
  int local_ac;
  int local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  CL_xMatrix aCStack_74 [64];
  int local_34;
  int local_30;
  int local_2c;
  
  uVar20 = *(uint *)this;
  iVar10 = DAT_000c4464 + 0xc43fe;
  if ((int)uVar20 < 6) {
    iVar9 = **(int **)(iVar10 + DAT_000c4468);
    if (uVar20 < 0xb) {
      CCLFigureMgr::GetDefensePos3D((int)&local_34);
      iVar9 = uVar20 * 0xc + iVar9;
      local_34 = *(int *)(iVar9 + 0x194) + local_34;
      local_30 = *(int *)(iVar9 + 0x198) + local_30;
      local_2c = *(int *)(iVar9 + 0x19c) + local_2c;
      goto LAB_000c441e;
    }
  }
  else {
    iVar9 = **(int **)(iVar10 + DAT_000c4ac0);
    if (uVar20 - 6 < 5) {
      CCLFigureMgr::GetDefensePos3D((int)&local_34);
      iVar9 = (uVar20 - 6) * 0xc + iVar9;
      local_34 = *(int *)(iVar9 + 0x238) + local_34;
      local_30 = *(int *)(iVar9 + 0x23c) + local_30;
      local_2c = *(int *)(iVar9 + 0x240) + local_2c;
      goto LAB_000c441e;
    }
  }
  piVar11 = *(int **)(iVar10 + DAT_000c446c);
  local_34 = *piVar11;
  local_30 = piVar11[1];
  local_2c = piVar11[2];
LAB_000c441e:
  *(int *)(this + 0xb4) = local_34 << 0x12;
  *(int *)(this + 0xb8) = local_30 << 0x12;
  *(int *)(this + 0xbc) = local_2c << 0x12;
  if (((param_1) && (*(int *)this < 6)) && (*(int *)this % 2 == 1)) {
    if (this[0xd4] == (CCLPitch)0x1) {
      if (0 < *(int *)(this + 0x80)) {
        iVar10 = 0;
        iVar9 = 0;
        do {
          iVar9 = iVar9 + 1;
          piVar11 = (int *)(iVar10 + *(int *)(this + 0x7c));
          iVar10 = iVar10 + 0xc;
          lVar24 = __aeabi_lmul(*piVar11,*piVar11 >> 0x1f,0xfffffffe,0xffffffff);
          uVar20 = (uint)(lVar24 + 1);
          uVar19 = uVar20 * 0x20000;
          iVar6 = ((int)((ulonglong)(lVar24 + 1) >> 0x20) * 0x20000 | uVar20 >> 0xf) << 0xe;
          *(char *)piVar11 = (char)(uVar19 >> 0x12);
          *(byte *)((int)piVar11 + 1) = (byte)(uVar19 >> 0x1a) | (byte)((uint)iVar6 >> 8);
          *(char *)((int)piVar11 + 2) = (char)((uint)iVar6 >> 0x10);
          *(char *)((int)piVar11 + 3) = (char)((uint)iVar6 >> 0x18);
        } while (iVar9 < *(int *)(this + 0x80));
      }
    }
    else if (0 < *(int *)(this + 0x80)) {
      iVar10 = 0;
      iVar9 = 0;
      do {
        iVar9 = iVar9 + 1;
        puVar18 = (ushort *)(iVar10 + *(int *)(this + 0x7c));
        uVar2 = *puVar18;
        *(undefined *)puVar18 = 0;
        *(undefined *)((int)puVar18 + 1) = 0;
        *(char *)(puVar18 + 1) = (char)((uint)uVar2 * -0x40000 >> 0x10);
        *(char *)((int)puVar18 + 3) = (char)((uint)uVar2 * -0x40000 >> 0x18);
        iVar10 = iVar10 + 0xc;
      } while (iVar9 < *(int *)(this + 0x80));
    }
  }
  CCLMatrix::CCLMatrix((CCLMatrix *)&local_98);
  puVar12 = *(uint **)(this + 0x7c);
  puVar21 = puVar12 + *(int *)(this + 0x80) * 3 + -3;
  if (0 < *(int *)(this + 0x80)) {
    iVar9 = 0;
    iVar10 = 0;
    puVar13 = puVar12;
    while( true ) {
      piVar11 = (int *)(iVar9 + (int)puVar13);
      iVar10 = iVar10 + 1;
      iVar6 = *piVar11 - *puVar21;
      *(char *)piVar11 = (char)iVar6;
      *(char *)((int)piVar11 + 1) = (char)((uint)iVar6 >> 8);
      *(char *)((int)piVar11 + 2) = (char)((uint)iVar6 >> 0x10);
      *(char *)((int)piVar11 + 3) = (char)((uint)iVar6 >> 0x18);
      iVar14 = iVar9 + *(int *)(this + 0x7c);
      iVar6 = *(int *)(iVar14 + 4) - puVar21[1];
      *(char *)(iVar14 + 4) = (char)iVar6;
      *(char *)(iVar14 + 5) = (char)((uint)iVar6 >> 8);
      *(char *)(iVar14 + 6) = (char)((uint)iVar6 >> 0x10);
      *(char *)(iVar14 + 7) = (char)((uint)iVar6 >> 0x18);
      iVar14 = iVar9 + *(int *)(this + 0x7c);
      iVar9 = iVar9 + 0xc;
      iVar6 = *(int *)(iVar14 + 8) - puVar21[2];
      *(char *)(iVar14 + 8) = (char)iVar6;
      *(char *)(iVar14 + 9) = (char)((uint)iVar6 >> 8);
      *(char *)(iVar14 + 10) = (char)((uint)iVar6 >> 0x10);
      *(char *)(iVar14 + 0xb) = (char)((uint)iVar6 >> 0x18);
      if (*(int *)(this + 0x80) <= iVar10) break;
      puVar13 = *(uint **)(this + 0x7c);
    }
  }
  iVar22 = puVar21[2] - puVar12[2];
  uVar20 = puVar12[1];
  uVar19 = *puVar12;
  iVar14 = iVar22 >> 0x1f;
  lVar3 = __aeabi_ldivmod(uVar20 << 0x12,((int)uVar20 >> 0x1f) << 0x12 | uVar20 >> 0xe,iVar22,iVar14
                         );
  iVar10 = CLMath::xAtan(lVar3);
  uVar4 = *puVar12;
  lVar3 = __aeabi_ldivmod(uVar4 << 0x12,((int)uVar4 >> 0x1f) << 0x12 | uVar4 >> 0xe,iVar22,iVar14);
  iVar9 = CLMath::xAtan(lVar3);
  uVar4 = *(int *)(this + 0xb8) - *(int *)(this + 0xc4);
  iVar7 = *(int *)(this + 0xb4);
  iVar15 = *(int *)(this + 0xc0);
  lVar3 = __aeabi_ldivmod(uVar4 * 0x40000,((int)uVar4 >> 0x1f) << 0x12 | uVar4 >> 0xe,iVar22,iVar14)
  ;
  iVar6 = CLMath::xAtan(lVar3);
  uVar5 = *(int *)(this + 0xb4) - *(int *)(this + 0xc0);
  lVar3 = __aeabi_ldivmod(uVar5 * 0x40000,((int)uVar5 >> 0x1f) << 0x12 | uVar5 >> 0xe,iVar22,iVar14)
  ;
  iVar14 = CLMath::xAtan(lVar3);
  local_94 = 0x40000;
  local_90 = 0x40000;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_98 = 0x40000;
  CCLMatrix::MatrixIdentity(aCStack_74);
  local_8c = iVar6 * ((int)uVar4 >> 0x1f | 1U) + iVar10 * ((int)~uVar20 >> 0x1f | 1U);
  local_84 = 0;
  local_88 = (~(iVar7 - iVar15) >> 0x1f | 1U) * iVar14 + iVar9 * ((int)uVar19 >> 0x1f | 1U);
  CCLMatrix::Update();
  iVar10 = *(int *)(this + 0x80);
  ptVar23 = *(tagCLxPoint3 **)(this + 0x7c);
  if (0 < iVar10) {
    iVar9 = 0;
    do {
      iVar9 = iVar9 + 1;
      CCLMatrix::MulPoint((CCLMatrix *)&local_98,ptVar23,ptVar23);
      ptVar23 = ptVar23 + 3;
    } while (iVar9 < iVar10);
    iVar10 = *(int *)(this + 0x80);
  }
  iVar9 = puVar21[2] - puVar12[2];
  if (iVar9 == 0) {
    local_ac = 0x40000;
  }
  else {
    uVar20 = *(int *)(this + 200) - *(int *)(this + 0xbc);
    local_ac = __aeabi_ldivmod(uVar20 * 0x40000,((int)uVar20 >> 0x1f) << 0x12 | uVar20 >> 0xe,iVar9,
                               iVar9 >> 0x1f);
  }
  if (0 < iVar10) {
    iVar10 = 0;
    iVar9 = 0;
    do {
      iVar14 = iVar10 + *(int *)(this + 0x7c);
      iVar9 = iVar9 + 1;
      lVar24 = __aeabi_lmul(local_ac,local_ac >> 0x1f,*(int *)(iVar14 + 8),
                            *(int *)(iVar14 + 8) >> 0x1f);
      lVar24 = lVar24 + CONCAT44(DAT_000c4abc,DAT_000c4ab8);
      iVar6 = (int)((ulonglong)lVar24 >> 0x20) * 0x4000;
      *(char *)(iVar14 + 8) = (char)((uint)lVar24 >> 0x12);
      *(byte *)(iVar14 + 9) = (byte)((ulonglong)lVar24 >> 0x18) >> 2 | (byte)((uint)iVar6 >> 8);
      *(char *)(iVar14 + 0xb) = (char)((uint)iVar6 >> 0x18);
      *(char *)(iVar14 + 10) = (char)((uint)iVar6 >> 0x10);
      piVar11 = (int *)(iVar10 + *(int *)(this + 0x7c));
      iVar6 = *piVar11 + *(int *)(this + 0xc0);
      *(char *)piVar11 = (char)iVar6;
      *(char *)((int)piVar11 + 1) = (char)((uint)iVar6 >> 8);
      *(char *)((int)piVar11 + 2) = (char)((uint)iVar6 >> 0x10);
      *(char *)((int)piVar11 + 3) = (char)((uint)iVar6 >> 0x18);
      iVar14 = iVar10 + *(int *)(this + 0x7c);
      iVar6 = *(int *)(iVar14 + 4) + *(int *)(this + 0xc4);
      *(char *)(iVar14 + 4) = (char)iVar6;
      *(char *)(iVar14 + 5) = (char)((uint)iVar6 >> 8);
      *(char *)(iVar14 + 6) = (char)((uint)iVar6 >> 0x10);
      *(char *)(iVar14 + 7) = (char)((uint)iVar6 >> 0x18);
      iVar14 = iVar10 + *(int *)(this + 0x7c);
      iVar10 = iVar10 + 0xc;
      iVar6 = *(int *)(iVar14 + 8) + *(int *)(this + 200);
      *(char *)(iVar14 + 8) = (char)iVar6;
      *(char *)(iVar14 + 9) = (char)((uint)iVar6 >> 8);
      *(char *)(iVar14 + 10) = (char)((uint)iVar6 >> 0x10);
      *(char *)(iVar14 + 0xb) = (char)((uint)iVar6 >> 0x18);
    } while (iVar9 < *(int *)(this + 0x80));
  }
  CCLMatrix::~CCLMatrix((CCLMatrix *)&local_98);
  iVar10 = *(int *)(this + 0x88);
  local_a8 = iVar10 + -3;
  if (this[0xd5] == (CCLPitch)0x1) {
    CCLSpline::Cardinal((CCLSpline *)(this + 0x9c),*(int *)(this + 0x80),
                        *(tagCLxPoint3 **)(this + 0x7c),local_a8,*(tagCLxPoint3 **)(this + 0x84));
  }
  else {
    CCLSpline::Bezier((CCLSpline *)(this + 0x9c),*(int *)(this + 0x80),
                      *(tagCLxPoint3 **)(this + 0x7c),local_a8,*(tagCLxPoint3 **)(this + 0x84));
  }
  iVar16 = local_a8 * 0xc;
  iVar22 = *(int *)(this + 0x84);
  iVar8 = iVar16 + iVar22;
  iVar9 = *(int *)(iVar8 + -0xc);
  iVar17 = iVar9 - *(int *)(iVar8 + -0x18);
  iVar6 = *(int *)(iVar8 + -8);
  iVar14 = *(int *)(iVar8 + -0x14);
  iVar7 = *(int *)(iVar8 + -4);
  iVar15 = *(int *)(iVar8 + -0x10);
  if (local_a8 < *(int *)(this + 0x88)) {
    iVar10 = (iVar10 + -2) * 0xc;
    while( true ) {
      iVar9 = iVar9 + iVar17;
      *(char *)(iVar16 + iVar22) = (char)iVar9;
      *(char *)(iVar8 + 1) = (char)((uint)iVar9 >> 8);
      *(char *)(iVar8 + 3) = (char)((uint)iVar9 >> 0x18);
      *(char *)(iVar8 + 2) = (char)((uint)iVar9 >> 0x10);
      iVar22 = iVar16 + *(int *)(this + 0x84);
      iVar9 = *(int *)(iVar22 + -8) + (iVar6 - iVar14);
      *(char *)(iVar22 + 4) = (char)iVar9;
      *(char *)(iVar22 + 5) = (char)((uint)iVar9 >> 8);
      *(char *)(iVar22 + 6) = (char)((uint)iVar9 >> 0x10);
      *(char *)(iVar22 + 7) = (char)((uint)iVar9 >> 0x18);
      iVar22 = iVar16 + *(int *)(this + 0x84);
      iVar16 = iVar16 + 0xc;
      iVar9 = *(int *)(iVar22 + -4) + (iVar7 - iVar15);
      *(char *)(iVar22 + 8) = (char)iVar9;
      *(char *)(iVar22 + 9) = (char)((uint)iVar9 >> 8);
      *(char *)(iVar22 + 10) = (char)((uint)iVar9 >> 0x10);
      *(char *)(iVar22 + 0xb) = (char)((uint)iVar9 >> 0x18);
      local_a8 = local_a8 + 1;
      if (*(int *)(this + 0x88) <= local_a8) break;
      iVar22 = *(int *)(this + 0x84);
      puVar1 = (undefined *)(iVar10 + iVar22 + -0xc);
      iVar9 = iVar10 + iVar22 + -0xc;
      iVar10 = iVar10 + 0xc;
      iVar9 = CONCAT13(*(undefined *)(iVar9 + 3),
                       CONCAT12(*(undefined *)(iVar9 + 2),
                                CONCAT11(*(undefined *)(iVar9 + 1),*puVar1)));
      iVar8 = iVar16 + iVar22;
    }
  }
  return;
}


