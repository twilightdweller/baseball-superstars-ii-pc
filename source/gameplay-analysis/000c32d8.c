/* CCLProjection::glFrustum; research only, not buildable source */

/* CCLProjection::glFrustum(long, long, long, long, long, long) */

void __thiscall
CCLProjection::glFrustum
          (CCLProjection *this,long param_1,long param_2,long param_3,long param_4,long param_5,
          long param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  longlong lVar17;
  
  uVar11 = param_5 * 4 + 1;
  uVar6 = uVar11 >> 0xf;
  uVar12 = (((param_5 >> 0x1f) * 4 | (uint)param_5 >> 0x1e) +
           (uint)(0xfffffffe < (uint)(param_5 * 4))) * 0x20000;
  uVar11 = uVar11 * 0x20000;
  uVar13 = uVar11 >> 0x12 | (uVar12 | uVar6) << 0xe;
  puVar14 = *(uint **)(DAT_000c3460 + 0xc332c + DAT_000c3464);
  uVar7 = param_2 - param_1;
  puVar14[1] = uVar7;
  uVar2 = param_4 - param_3;
  puVar14[2] = uVar2;
  uVar16 = param_3 + param_4;
  uVar15 = param_2 + param_1;
  puVar14[4] = uVar16;
  puVar14[3] = uVar15;
  uVar1 = -(param_6 + param_5);
  puVar14[5] = uVar1;
  uVar8 = param_6 - param_5;
  *puVar14 = uVar13;
  puVar14[6] = uVar8;
  lVar17 = __aeabi_lmul(param_6,param_6 >> 0x1f);
  lVar17 = lVar17 + CONCAT44(DAT_000c345c,DAT_000c3458);
  uVar10 = (int)((ulonglong)lVar17 >> 0x20) * 0x4000;
  uVar3 = (uint)lVar17 >> 0x12 | uVar10;
  puVar14[7] = uVar3;
  uVar9 = uVar3 * 4 + 1;
  puVar14[8] = -(uVar9 * 0x20000 >> 0x12 |
                (((((int)uVar3 >> 0x1f) * 4 | uVar10 >> 0x1e) + (uint)(0xfffffffe < uVar3 * 4)) *
                 0x20000 | uVar9 >> 0xf) << 0xe);
  uVar3 = ((int)uVar13 >> 0x1f) << 0x12 | uVar12 & 0x3ffff | uVar6;
  uVar11 = uVar11 & 0xfffc0000;
  uVar4 = __aeabi_ldivmod(uVar11,uVar3,uVar7,(int)uVar7 >> 0x1f);
  *(undefined4 *)(this + 0x44) = uVar4;
  *(undefined4 *)(this + 0x48) = 0;
  uVar4 = __aeabi_ldivmod(uVar15 * 0x40000,((int)uVar15 >> 0x1f) << 0x12 | uVar15 >> 0xe,uVar7,
                          (int)uVar7 >> 0x1f);
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x4c) = uVar4;
  uVar4 = __aeabi_ldivmod(uVar11,uVar3,uVar2,(int)uVar2 >> 0x1f);
  *(undefined4 *)(this + 0x58) = uVar4;
  uVar4 = __aeabi_ldivmod(uVar16 * 0x40000,((int)uVar16 >> 0x1f) << 0x12 | uVar16 >> 0xe,uVar2,
                          (int)uVar2 >> 0x1f);
  *(undefined4 *)(this + 0x5c) = uVar4;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  uVar5 = __aeabi_ldivmod((param_6 + param_5) * -0x40000,((int)uVar1 >> 0x1f) << 0x12 | uVar1 >> 0xe
                          ,uVar8,(int)uVar8 >> 0x1f);
  uVar4 = DAT_000c3468;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x6c) = uVar5;
  *(undefined4 *)(this + 0x7c) = uVar4;
  return;
}


