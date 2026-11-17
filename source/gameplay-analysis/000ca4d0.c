/* CCLMatrix::MatrixMul; research only, not buildable source */

/* CCLMatrix::MatrixMul(CL_xMatrix*, CL_xMatrix*, CL_xMatrix*) */

void CCLMatrix::MatrixMul(CL_xMatrix *param_1,CL_xMatrix *param_2,CL_xMatrix *param_3)

{
  longlong lVar1;
  int *__src;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  longlong lVar21;
  longlong lVar22;
  longlong lVar23;
  longlong lVar24;
  
  lVar1 = CONCAT44(DAT_000ca8d4,DAT_000ca8d0);
  __src = *(int **)(DAT_000ca8d8 + 0xca4e6 + DAT_000ca8dc);
  iVar2 = *(int *)(param_3 + 0x10);
  iVar7 = *(int *)(param_2 + 4);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x10),iVar2 >> 0x1f,iVar7,iVar7 >> 0x1f);
  lVar22 = __aeabi_lmul(*(int *)param_3,*(int *)param_3 >> 0x1f,*(int *)param_2,
                        *(int *)param_2 >> 0x1f);
  iVar8 = *(int *)(param_3 + 0x20) >> 0x1f;
  iVar3 = *(int *)(param_2 + 8) >> 0x1f;
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x20),iVar8,*(undefined4 *)(param_2 + 8),iVar3);
  iVar4 = *(int *)(param_3 + 0x30) >> 0x1f;
  iVar9 = *(int *)(param_2 + 0xc);
  iVar5 = iVar9 >> 0x1f;
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x30),iVar4,iVar9,iVar5);
  iVar10 = *(int *)(param_3 + 0x14);
  *__src = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000) +
           ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000) +
           ((uint)(lVar23 + lVar1) >> 0x12 | (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
           ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x14),iVar10 >> 0x1f,iVar7,iVar7 >> 0x1f);
  iVar11 = *(int *)param_2;
  lVar22 = __aeabi_lmul(*(int *)(param_3 + 4),*(int *)(param_3 + 4) >> 0x1f,*(undefined4 *)param_2);
  iVar12 = *(int *)(param_3 + 0x24) >> 0x1f;
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x24),iVar12,*(undefined4 *)(param_2 + 8),iVar3);
  iVar13 = *(int *)(param_3 + 0x34) >> 0x1f;
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x34),iVar13,iVar9,iVar5);
  iVar7 = *(int *)(param_3 + 0x18);
  __src[1] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  iVar14 = *(int *)(param_2 + 4);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x18),iVar7 >> 0x1f,*(undefined4 *)(param_2 + 4));
  lVar22 = __aeabi_lmul(*(int *)(param_3 + 8),*(int *)(param_3 + 8) >> 0x1f,*(undefined4 *)param_2,
                        iVar11 >> 0x1f);
  iVar6 = *(int *)(param_3 + 0x28) >> 0x1f;
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x28),iVar6,*(undefined4 *)(param_2 + 8),iVar3);
  iVar15 = *(int *)(param_3 + 0x38) >> 0x1f;
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x38),iVar15,iVar9,iVar5);
  iVar3 = *(int *)(param_3 + 0x1c);
  __src[2] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x1c),iVar3 >> 0x1f,*(undefined4 *)(param_2 + 4),
                        iVar14 >> 0x1f);
  lVar22 = __aeabi_lmul(*(int *)(param_3 + 0xc),*(int *)(param_3 + 0xc) >> 0x1f,
                        *(undefined4 *)param_2,iVar11 >> 0x1f);
  iVar11 = *(int *)(param_3 + 0x2c) >> 0x1f;
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x2c),iVar11,*(int *)(param_2 + 8),
                        *(int *)(param_2 + 8) >> 0x1f);
  iVar16 = *(int *)(param_3 + 0x3c);
  iVar14 = iVar16 >> 0x1f;
  lVar24 = __aeabi_lmul(iVar16,iVar14,iVar9,iVar5);
  iVar5 = *(int *)(param_2 + 0x14);
  __src[3] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x10),iVar2 >> 0x1f,iVar5,iVar5 >> 0x1f);
  iVar9 = *(int *)param_3 >> 0x1f;
  lVar22 = __aeabi_lmul(*(undefined4 *)param_3,iVar9,*(int *)(param_2 + 0x10),
                        *(int *)(param_2 + 0x10) >> 0x1f);
  iVar17 = *(int *)(param_2 + 0x18);
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x20),iVar8,*(undefined4 *)(param_2 + 0x18));
  iVar2 = *(int *)(param_2 + 0x1c);
  iVar18 = iVar2 >> 0x1f;
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x30),iVar4,iVar2,iVar18);
  __src[4] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x14),iVar10 >> 0x1f,iVar5,iVar5 >> 0x1f);
  iVar10 = *(int *)(param_3 + 4) >> 0x1f;
  iVar5 = *(int *)(param_2 + 0x10) >> 0x1f;
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 4),iVar10,*(undefined4 *)(param_2 + 0x10),iVar5);
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x24),iVar12,*(undefined4 *)(param_2 + 0x18),
                        iVar17 >> 0x1f);
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x34),iVar13,iVar2,iVar18);
  __src[5] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  iVar19 = *(int *)(param_2 + 0x14);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x18),iVar7 >> 0x1f,
                        *(undefined4 *)(param_2 + 0x14));
  iVar7 = *(int *)(param_3 + 8) >> 0x1f;
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 8),iVar7,*(undefined4 *)(param_2 + 0x10),iVar5);
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x28),iVar6,*(undefined4 *)(param_2 + 0x18),
                        iVar17 >> 0x1f);
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x38),iVar15,iVar2,iVar18);
  __src[6] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x1c),iVar3 >> 0x1f,
                        *(undefined4 *)(param_2 + 0x14),iVar19 >> 0x1f);
  iVar17 = *(int *)(param_3 + 0xc) >> 0x1f;
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 0xc),iVar17,*(undefined4 *)(param_2 + 0x10),iVar5)
  ;
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x2c),iVar11,*(int *)(param_2 + 0x18),
                        *(int *)(param_2 + 0x18) >> 0x1f);
  lVar24 = __aeabi_lmul(iVar16,iVar14,iVar2,iVar18);
  iVar18 = *(int *)(param_3 + 0x10);
  __src[7] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  iVar2 = *(int *)(param_2 + 0x24);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x10),iVar18 >> 0x1f);
  lVar22 = __aeabi_lmul(*(undefined4 *)param_3,iVar9,*(int *)(param_2 + 0x20),
                        *(int *)(param_2 + 0x20) >> 0x1f);
  iVar19 = *(int *)(param_2 + 0x28);
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x20),iVar8,*(undefined4 *)(param_2 + 0x28));
  iVar3 = *(int *)(param_2 + 0x2c);
  iVar8 = iVar3 >> 0x1f;
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x30),iVar4,iVar3,iVar8);
  iVar5 = *(int *)(param_3 + 0x14);
  __src[8] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x14),iVar5 >> 0x1f,iVar2,iVar2 >> 0x1f);
  iVar20 = *(int *)(param_2 + 0x20);
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 4),iVar10,*(undefined4 *)(param_2 + 0x20));
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x24),iVar12,*(undefined4 *)(param_2 + 0x28),
                        iVar19 >> 0x1f);
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x34),iVar13,iVar3,iVar8);
  iVar12 = *(int *)(param_3 + 0x18);
  __src[9] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
             + ((uint)(lVar21 + lVar1) >> 0x12 | (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar23 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000) +
             ((uint)(lVar24 + lVar1) >> 0x12 | (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  iVar2 = *(int *)(param_2 + 0x24);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x18),iVar12 >> 0x1f,
                        *(undefined4 *)(param_2 + 0x24),iVar2 >> 0x1f);
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 8),iVar7,*(undefined4 *)(param_2 + 0x20),
                        iVar20 >> 0x1f);
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x28),iVar6,*(undefined4 *)(param_2 + 0x28),
                        iVar19 >> 0x1f);
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x38),iVar15,iVar3,iVar8);
  iVar6 = *(int *)(param_3 + 0x1c);
  __src[10] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000)
              + ((uint)(lVar21 + lVar1) >> 0x12 |
                (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar23 + lVar1) >> 0x12 | (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000)
              + ((uint)(lVar24 + lVar1) >> 0x12 |
                (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x1c),iVar6 >> 0x1f,
                        *(undefined4 *)(param_2 + 0x24),iVar2 >> 0x1f);
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 0xc),iVar17,*(undefined4 *)(param_2 + 0x20),
                        iVar20 >> 0x1f);
  lVar23 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x2c),iVar11,*(int *)(param_2 + 0x28),
                        *(int *)(param_2 + 0x28) >> 0x1f);
  lVar24 = __aeabi_lmul(iVar16,iVar14,iVar3,iVar8);
  iVar3 = *(int *)(param_2 + 0x34);
  __src[0xb] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar21 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000) +
               ((uint)(lVar23 + lVar1) >> 0x12 | (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar24 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x10),iVar18 >> 0x1f,iVar3,iVar3 >> 0x1f);
  lVar22 = __aeabi_lmul(*(undefined4 *)param_3,iVar9,*(int *)(param_2 + 0x30),
                        *(int *)(param_2 + 0x30) >> 0x1f);
  iVar11 = *(int *)(param_2 + 0x38);
  lVar23 = __aeabi_lmul(*(int *)(param_3 + 0x20),*(int *)(param_3 + 0x20) >> 0x1f,
                        *(undefined4 *)(param_2 + 0x38));
  iVar2 = *(int *)(param_2 + 0x3c);
  iVar8 = iVar2 >> 0x1f;
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x30),iVar4,iVar2,iVar8);
  __src[0xc] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar21 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000) +
               ((uint)(lVar23 + lVar1) >> 0x12 | (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar24 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x14),iVar5 >> 0x1f,iVar3,iVar3 >> 0x1f);
  iVar3 = *(int *)(param_2 + 0x30);
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 4),iVar10,*(undefined4 *)(param_2 + 0x30));
  lVar23 = __aeabi_lmul(*(int *)(param_3 + 0x24),*(int *)(param_3 + 0x24) >> 0x1f,
                        *(undefined4 *)(param_2 + 0x38),iVar11 >> 0x1f);
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x34),iVar13,iVar2,iVar8);
  __src[0xd] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar21 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000) +
               ((uint)(lVar23 + lVar1) >> 0x12 | (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar24 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  iVar4 = *(int *)(param_2 + 0x34);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x18),iVar12 >> 0x1f,
                        *(undefined4 *)(param_2 + 0x34));
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 8),iVar7,*(undefined4 *)(param_2 + 0x30),
                        iVar3 >> 0x1f);
  lVar23 = __aeabi_lmul(*(int *)(param_3 + 0x28),*(int *)(param_3 + 0x28) >> 0x1f,
                        *(undefined4 *)(param_2 + 0x38),iVar11 >> 0x1f);
  lVar24 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x38),iVar15,iVar2,iVar8);
  __src[0xe] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar21 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000) +
               ((uint)(lVar23 + lVar1) >> 0x12 | (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar24 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  lVar21 = __aeabi_lmul(*(undefined4 *)(param_3 + 0x1c),iVar6 >> 0x1f,
                        *(undefined4 *)(param_2 + 0x34),iVar4 >> 0x1f);
  lVar22 = __aeabi_lmul(*(undefined4 *)(param_3 + 0xc),iVar17,*(undefined4 *)(param_2 + 0x30),
                        iVar3 >> 0x1f);
  lVar23 = __aeabi_lmul(*(int *)(param_3 + 0x2c),*(int *)(param_3 + 0x2c) >> 0x1f,
                        *(int *)(param_2 + 0x38),*(int *)(param_2 + 0x38) >> 0x1f);
  lVar24 = __aeabi_lmul(iVar16,iVar14,iVar2,iVar8);
  __src[0xf] = ((uint)(lVar22 + lVar1) >> 0x12 | (int)((ulonglong)(lVar22 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar21 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar21 + lVar1) >> 0x20) * 0x4000) +
               ((uint)(lVar23 + lVar1) >> 0x12 | (int)((ulonglong)(lVar23 + lVar1) >> 0x20) * 0x4000
               ) + ((uint)(lVar24 + lVar1) >> 0x12 |
                   (int)((ulonglong)(lVar24 + lVar1) >> 0x20) * 0x4000);
  memcpy(param_1,__src,0x40);
  return;
}


