/* CCLMatrix::Update; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLMatrix::Update() */

void CCLMatrix::Update(void)

{
  longlong lVar1;
  int *in_r0;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint *puVar16;
  uint uVar17;
  longlong lVar18;
  longlong lVar19;
  
  iVar2 = CLMath::xSin(in_r0[3]);
  iVar3 = CLMath::xSin(0x1680000 - in_r0[3]);
  iVar4 = CLMath::xSin(in_r0[4]);
  iVar12 = DAT_000cb080;
  iVar5 = CLMath::xSin(0x1680000 - in_r0[4]);
  iVar6 = CLMath::xSin(in_r0[5]);
  iVar7 = CLMath::xSin(0x1680000 - in_r0[5]);
  lVar1 = CONCAT44(DAT_000cb07c,DAT_000cb078);
  iVar13 = iVar7 >> 0x1f;
  iVar8 = iVar5 >> 0x1f;
  lVar18 = __aeabi_lmul(iVar7,iVar13,iVar5,iVar8);
  uVar9 = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  puVar16 = *(uint **)(iVar12 + 0xcadb0 + DAT_000cb084);
  *puVar16 = uVar9;
  iVar12 = -iVar6;
  iVar10 = iVar12 >> 0x1f;
  lVar18 = __aeabi_lmul(iVar12,iVar10,iVar5,iVar8);
  puVar16[1] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  iVar11 = *in_r0;
  iVar14 = iVar11 >> 0x1f;
  lVar18 = __aeabi_lmul(uVar9,(int)uVar9 >> 0x1f,iVar11,iVar14);
  in_r0[9] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  lVar18 = __aeabi_lmul(puVar16[1],(int)puVar16[1] >> 0x1f,iVar11,iVar14);
  in_r0[10] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  lVar18 = __aeabi_lmul(-iVar4,-iVar4 >> 0x1f,iVar11,iVar14);
  in_r0[0xc] = 0;
  in_r0[0xb] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  lVar18 = __aeabi_lmul(iVar4,iVar4 >> 0x1f,iVar2,iVar2 >> 0x1f);
  uVar9 = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  *puVar16 = uVar9;
  iVar14 = iVar3 >> 0x1f;
  lVar18 = __aeabi_lmul(uVar9,(int)uVar9 >> 0x1f,iVar7,iVar13);
  lVar19 = __aeabi_lmul(iVar6,iVar6 >> 0x1f,iVar3,iVar14);
  uVar17 = ((uint)(lVar19 + lVar1) >> 0x12 | (int)((ulonglong)(lVar19 + lVar1) >> 0x20) * 0x4000) +
           ((uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000);
  puVar16[1] = uVar17;
  lVar18 = __aeabi_lmul(uVar9,(int)uVar9 >> 0x1f,iVar12,iVar10);
  lVar19 = __aeabi_lmul(iVar3,iVar14,iVar7,iVar13);
  puVar16[2] = ((uint)(lVar19 + lVar1) >> 0x12 | (int)((ulonglong)(lVar19 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar18 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000);
  lVar18 = __aeabi_lmul(iVar2,iVar2 >> 0x1f,iVar5,iVar8);
  puVar16[3] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  iVar11 = in_r0[1];
  iVar15 = iVar11 >> 0x1f;
  lVar18 = __aeabi_lmul(uVar17,(int)uVar17 >> 0x1f,iVar11,iVar15);
  in_r0[0xd] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  lVar18 = __aeabi_lmul(puVar16[2],(int)puVar16[2] >> 0x1f,iVar11,iVar15);
  in_r0[0xe] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  lVar18 = __aeabi_lmul(puVar16[3],(int)puVar16[3] >> 0x1f,iVar11,iVar15);
  in_r0[0xf] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  in_r0[0x10] = 0;
  lVar18 = __aeabi_lmul(iVar3,iVar14,iVar4,iVar4 >> 0x1f);
  uVar9 = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  *puVar16 = uVar9;
  iVar2 = -iVar2;
  lVar18 = __aeabi_lmul(uVar9,(int)uVar9 >> 0x1f,iVar7,iVar13);
  lVar19 = __aeabi_lmul(iVar2,iVar2 >> 0x1f,iVar6,iVar6 >> 0x1f);
  uVar17 = ((uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000) +
           ((uint)(lVar19 + lVar1) >> 0x12 | (int)((ulonglong)(lVar19 + lVar1) >> 0x20) * 0x4000);
  puVar16[1] = uVar17;
  lVar18 = __aeabi_lmul(uVar9,(int)uVar9 >> 0x1f,iVar12,iVar10);
  lVar19 = __aeabi_lmul(iVar2,iVar2 >> 0x1f,iVar7,iVar13);
  puVar16[2] = ((uint)(lVar19 + lVar1) >> 0x12 | (int)((ulonglong)(lVar19 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar18 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000);
  lVar18 = __aeabi_lmul(iVar3,iVar14,iVar5,iVar8);
  puVar16[3] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000;
  iVar12 = in_r0[2];
  iVar2 = iVar12 >> 0x1f;
  lVar18 = __aeabi_lmul(uVar17,(int)uVar17 >> 0x1f,iVar12,iVar2);
  in_r0[0x11] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000
  ;
  lVar18 = __aeabi_lmul(puVar16[2],(int)puVar16[2] >> 0x1f,iVar12,iVar2);
  in_r0[0x12] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000
  ;
  lVar18 = __aeabi_lmul(puVar16[3],(int)puVar16[3] >> 0x1f,iVar12,iVar2);
  in_r0[0x13] = (uint)(lVar18 + lVar1) >> 0x12 | (int)((ulonglong)(lVar18 + lVar1) >> 0x20) * 0x4000
  ;
  in_r0[0x15] = in_r0[6];
  in_r0[0x16] = in_r0[7];
  in_r0[0x17] = in_r0[8];
  in_r0[0x18] = 0x40000;
  return;
}


