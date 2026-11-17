/* CCLMatrix::MatrixMul; research only, not buildable source */

/* CCLMatrix::MatrixMul(CL_xPoint4*, CL_xPoint4*, CL_xMatrix*) */

void CCLMatrix::MatrixMul(CL_xPoint4 *param_1,CL_xPoint4 *param_2,CL_xMatrix *param_3)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  
  lVar1 = CONCAT44(DAT_000ca09c,DAT_000ca098);
  piVar2 = *(int **)(DAT_000ca0a0 + 0xc9e9e + DAT_000ca0a4);
  iVar3 = *(int *)(param_2 + 4);
  lVar8 = __aeabi_lmul(*(int *)(param_3 + 0x10),*(int *)(param_3 + 0x10) >> 0x1f);
  lVar9 = __aeabi_lmul(*(int *)param_3,*(int *)param_3 >> 0x1f,*(int *)param_2,
                       *(int *)param_2 >> 0x1f);
  iVar5 = *(int *)(param_2 + 8);
  lVar10 = __aeabi_lmul(*(int *)(param_3 + 0x20),*(int *)(param_3 + 0x20) >> 0x1f,
                        *(undefined4 *)(param_2 + 8));
  iVar4 = *(int *)(param_2 + 0xc);
  iVar6 = iVar4 >> 0x1f;
  lVar11 = __aeabi_lmul(*(int *)(param_3 + 0x30),*(int *)(param_3 + 0x30) >> 0x1f,iVar4,iVar6);
  *piVar2 = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
            ((uint)(lVar8 + lVar1) >> 0x12 | (int)((ulonglong)(lVar8 + lVar1) >> 0x20) * 0x4000) +
            ((uint)(lVar10 + lVar1) >> 0x12 | (int)((ulonglong)(lVar10 + lVar1) >> 0x20) * 0x4000) +
            ((uint)(lVar11 + lVar1) >> 0x12 | (int)((ulonglong)(lVar11 + lVar1) >> 0x20) * 0x4000);
  lVar8 = __aeabi_lmul(*(int *)(param_3 + 0x14),*(int *)(param_3 + 0x14) >> 0x1f,iVar3,iVar3 >> 0x1f
                      );
  iVar3 = *(int *)param_2;
  lVar9 = __aeabi_lmul(*(int *)(param_3 + 4),*(int *)(param_3 + 4) >> 0x1f,*(undefined4 *)param_2);
  lVar10 = __aeabi_lmul(*(int *)(param_3 + 0x24),*(int *)(param_3 + 0x24) >> 0x1f,
                        *(undefined4 *)(param_2 + 8),iVar5 >> 0x1f);
  lVar11 = __aeabi_lmul(*(int *)(param_3 + 0x34),*(int *)(param_3 + 0x34) >> 0x1f,iVar4,iVar6);
  piVar2[1] = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar8 + lVar1) >> 0x12 | (int)((ulonglong)(lVar8 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar10 + lVar1) >> 0x12 | (int)((ulonglong)(lVar10 + lVar1) >> 0x20) * 0x4000)
              + ((uint)(lVar11 + lVar1) >> 0x12 |
                (int)((ulonglong)(lVar11 + lVar1) >> 0x20) * 0x4000);
  iVar7 = *(int *)(param_2 + 4);
  lVar8 = __aeabi_lmul(*(int *)(param_3 + 0x18),*(int *)(param_3 + 0x18) >> 0x1f,
                       *(undefined4 *)(param_2 + 4));
  lVar9 = __aeabi_lmul(*(int *)(param_3 + 8),*(int *)(param_3 + 8) >> 0x1f,*(undefined4 *)param_2,
                       iVar3 >> 0x1f);
  lVar10 = __aeabi_lmul(*(int *)(param_3 + 0x28),*(int *)(param_3 + 0x28) >> 0x1f,
                        *(undefined4 *)(param_2 + 8),iVar5 >> 0x1f);
  lVar11 = __aeabi_lmul(*(int *)(param_3 + 0x38),*(int *)(param_3 + 0x38) >> 0x1f,iVar4,iVar6);
  piVar2[2] = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar8 + lVar1) >> 0x12 | (int)((ulonglong)(lVar8 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar10 + lVar1) >> 0x12 | (int)((ulonglong)(lVar10 + lVar1) >> 0x20) * 0x4000)
              + ((uint)(lVar11 + lVar1) >> 0x12 |
                (int)((ulonglong)(lVar11 + lVar1) >> 0x20) * 0x4000);
  lVar8 = __aeabi_lmul(*(int *)(param_3 + 0x1c),*(int *)(param_3 + 0x1c) >> 0x1f,
                       *(undefined4 *)(param_2 + 4),iVar7 >> 0x1f);
  lVar9 = __aeabi_lmul(*(int *)(param_3 + 0xc),*(int *)(param_3 + 0xc) >> 0x1f,
                       *(undefined4 *)param_2,iVar3 >> 0x1f);
  lVar10 = __aeabi_lmul(*(int *)(param_3 + 0x2c),*(int *)(param_3 + 0x2c) >> 0x1f,
                        *(int *)(param_2 + 8),*(int *)(param_2 + 8) >> 0x1f);
  lVar11 = __aeabi_lmul(*(int *)(param_3 + 0x3c),*(int *)(param_3 + 0x3c) >> 0x1f,iVar4,iVar6);
  piVar2[3] = ((uint)(lVar9 + lVar1) >> 0x12 | (int)((ulonglong)(lVar9 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar8 + lVar1) >> 0x12 | (int)((ulonglong)(lVar8 + lVar1) >> 0x20) * 0x4000) +
              ((uint)(lVar10 + lVar1) >> 0x12 | (int)((ulonglong)(lVar10 + lVar1) >> 0x20) * 0x4000)
              + ((uint)(lVar11 + lVar1) >> 0x12 |
                (int)((ulonglong)(lVar11 + lVar1) >> 0x20) * 0x4000);
  iVar3 = piVar2[1];
  iVar4 = piVar2[2];
  *(int *)param_1 = *piVar2;
  *(int *)(param_1 + 4) = iVar3;
  *(int *)(param_1 + 8) = iVar4;
  *(int *)(param_1 + 0xc) = piVar2[3];
  return;
}


