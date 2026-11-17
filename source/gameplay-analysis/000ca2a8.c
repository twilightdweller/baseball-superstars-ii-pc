/* CCLMatrix::MatrixMul; research only, not buildable source */

/* CCLMatrix::MatrixMul(CL_xMatrix*, CL_xMatrix*, CL_xPoint4*) */

void CCLMatrix::MatrixMul(CL_xMatrix *param_1,CL_xMatrix *param_2,CL_xPoint4 *param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  
  lVar1 = CONCAT44(DAT_000ca4c4,DAT_000ca4c0);
  iVar2 = *(int *)(param_3 + 4);
  piVar5 = *(int **)(DAT_000ca4c8 + 0xca2c4 + DAT_000ca4cc);
  lVar8 = __aeabi_lmul();
  lVar9 = __aeabi_lmul(*(int *)param_3,*(int *)param_3 >> 0x1f,*(int *)param_2,
                       *(int *)param_2 >> 0x1f);
  iVar6 = *(int *)(param_3 + 8) >> 0x1f;
  lVar10 = __aeabi_lmul(*(undefined4 *)(param_3 + 8),iVar6,*(int *)(param_2 + 8),
                        *(int *)(param_2 + 8) >> 0x1f);
  iVar3 = *(int *)(param_3 + 0xc);
  iVar4 = iVar3 >> 0x1f;
  lVar11 = __aeabi_lmul();
  *piVar5 = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
            ((uint)(lVar8 + lVar1) >> 0x12 | (int)((ulonglong)(lVar8 + lVar1) >> 0x20) * 0x4000) +
            ((uint)(lVar10 + lVar1) >> 0x12 | (int)((ulonglong)(lVar10 + lVar1) >> 0x20) * 0x4000) +
            ((uint)(lVar11 + lVar1) >> 0x12 | (int)((ulonglong)(lVar11 + lVar1) >> 0x20) * 0x4000);
  lVar8 = __aeabi_lmul(iVar2,iVar2 >> 0x1f,*(int *)(param_2 + 0x14),*(int *)(param_2 + 0x14) >> 0x1f
                      );
  iVar7 = *(int *)param_3 >> 0x1f;
  lVar9 = __aeabi_lmul(*(undefined4 *)param_3,iVar7,*(int *)(param_2 + 0x10),
                       *(int *)(param_2 + 0x10) >> 0x1f);
  lVar10 = __aeabi_lmul(*(undefined4 *)(param_3 + 8),iVar6,*(int *)(param_2 + 0x18),
                        *(int *)(param_2 + 0x18) >> 0x1f);
  lVar11 = __aeabi_lmul(iVar3,iVar4,*(int *)(param_2 + 0x1c),*(int *)(param_2 + 0x1c) >> 0x1f);
  piVar5[1] = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar8 + lVar1) >> 0x12 | (int)((ulonglong)(lVar8 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar10 + lVar1) >> 0x12 | (int)((ulonglong)(lVar10 + lVar1) >> 0x20) * 0x4000)
              + ((uint)(lVar11 + lVar1) >> 0x12 |
                (int)((ulonglong)(lVar11 + lVar1) >> 0x20) * 0x4000);
  iVar2 = *(int *)(param_3 + 4);
  lVar8 = __aeabi_lmul(*(undefined4 *)(param_3 + 4),iVar2 >> 0x1f,*(int *)(param_2 + 0x24),
                       *(int *)(param_2 + 0x24) >> 0x1f);
  lVar9 = __aeabi_lmul(*(undefined4 *)param_3,iVar7,*(int *)(param_2 + 0x20),
                       *(int *)(param_2 + 0x20) >> 0x1f);
  lVar10 = __aeabi_lmul(*(undefined4 *)(param_3 + 8),iVar6,*(int *)(param_2 + 0x28),
                        *(int *)(param_2 + 0x28) >> 0x1f);
  lVar11 = __aeabi_lmul(iVar3,iVar4,*(int *)(param_2 + 0x2c),*(int *)(param_2 + 0x2c) >> 0x1f);
  piVar5[2] = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar8 + lVar1) >> 0x12 | (int)((ulonglong)(lVar8 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar10 + lVar1) >> 0x12 | (int)((ulonglong)(lVar10 + lVar1) >> 0x20) * 0x4000)
              + ((uint)(lVar11 + lVar1) >> 0x12 |
                (int)((ulonglong)(lVar11 + lVar1) >> 0x20) * 0x4000);
  lVar8 = __aeabi_lmul(*(undefined4 *)(param_3 + 4),iVar2 >> 0x1f,*(int *)(param_2 + 0x34),
                       *(int *)(param_2 + 0x34) >> 0x1f);
  lVar9 = __aeabi_lmul(*(undefined4 *)param_3,iVar7,*(int *)(param_2 + 0x30),
                       *(int *)(param_2 + 0x30) >> 0x1f);
  lVar10 = __aeabi_lmul(*(int *)(param_3 + 8),*(int *)(param_3 + 8) >> 0x1f,*(int *)(param_2 + 0x38)
                        ,*(int *)(param_2 + 0x38) >> 0x1f);
  lVar11 = __aeabi_lmul(iVar3,iVar4,*(int *)(param_2 + 0x3c),*(int *)(param_2 + 0x3c) >> 0x1f);
  piVar5[3] = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar8 + lVar1) >> 0x12 | (int)((ulonglong)(lVar8 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar10 + lVar1) >> 0x12 | (int)((ulonglong)(lVar10 + lVar1) >> 0x20) * 0x4000)
              + ((uint)(lVar11 + lVar1) >> 0x12 |
                (int)((ulonglong)(lVar11 + lVar1) >> 0x20) * 0x4000);
  iVar2 = piVar5[1];
  iVar3 = piVar5[2];
  *(int *)param_1 = *piVar5;
  *(int *)(param_1 + 4) = iVar2;
  *(int *)(param_1 + 8) = iVar3;
  *(int *)(param_1 + 0xc) = piVar5[3];
  return;
}


