/* CCLMatrix::MatrixMul; research only, not buildable source */

/* CCLMatrix::MatrixMul(tagCLxPoint3*, tagCLxPoint3*, CL_xMatrix*) */

void CCLMatrix::MatrixMul(tagCLxPoint3 *param_1,tagCLxPoint3 *param_2,CL_xMatrix *param_3)

{
  tagCLxPoint3 tVar1;
  tagCLxPoint3 tVar2;
  tagCLxPoint3 tVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  tagCLxPoint3 *ptVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  longlong lVar15;
  longlong lVar16;
  longlong lVar17;
  undefined local_38;
  
  iVar10 = DAT_000c9e6c;
  uVar5 = DAT_000c9e68;
  lVar4 = CONCAT44(DAT_000c9e6c,DAT_000c9e68);
  iVar13 = DAT_000c9e78 + 0xc9b6e;
  tVar1 = *param_2;
  ptVar11 = *(tagCLxPoint3 **)(iVar13 + DAT_000c9e7c);
  *ptVar11 = tVar1;
  tVar2 = param_2[1];
  ptVar11[1] = tVar2;
  tVar3 = param_2[2];
  ptVar11[3] = 0x40000;
  ptVar11[2] = tVar3;
  iVar6 = (int)tVar1 >> 0x1f;
  iVar12 = (int)tVar3 >> 0x1f;
  iVar7 = (int)tVar2 >> 0x1f;
  lVar15 = __aeabi_lmul(*(int *)(param_3 + 0x10),*(int *)(param_3 + 0x10) >> 0x1f,tVar2,iVar7);
  lVar16 = __aeabi_lmul(*(int *)param_3,*(int *)param_3 >> 0x1f,tVar1,iVar6);
  lVar17 = __aeabi_lmul(*(int *)(param_3 + 0x20),*(int *)(param_3 + 0x20) >> 0x1f,tVar3,iVar12);
  uVar8 = *(uint *)(param_3 + 0x30) * 0x40000;
  iVar9 = ((uint)(lVar15 + lVar4) >> 0x12 | (int)((ulonglong)(lVar15 + lVar4) >> 0x20) * 0x4000) +
          ((uint)(lVar16 + lVar4) >> 0x12 | (int)((ulonglong)(lVar16 + lVar4) >> 0x20) * 0x4000) +
          ((uint)(lVar17 + lVar4) >> 0x12 | (int)((ulonglong)(lVar17 + lVar4) >> 0x20) * 0x4000) +
          (uVar8 + uVar5 >> 0x12 |
          ((*(uint *)(param_3 + 0x30) >> 0xe) + iVar10 + (uint)CARRY4(uVar8,uVar5)) * 0x4000);
  piVar14 = *(int **)(iVar13 + DAT_000c9e80);
  *piVar14 = iVar9;
  lVar15 = __aeabi_lmul(*(int *)(param_3 + 0x14),*(int *)(param_3 + 0x14) >> 0x1f,tVar2,iVar7);
  lVar16 = __aeabi_lmul(*(int *)(param_3 + 4),*(int *)(param_3 + 4) >> 0x1f,tVar1,iVar6);
  lVar17 = __aeabi_lmul(*(int *)(param_3 + 0x24),*(int *)(param_3 + 0x24) >> 0x1f,tVar3,iVar12);
  uVar8 = *(uint *)(param_3 + 0x34) * 0x40000;
  piVar14[1] = ((uint)(lVar15 + lVar4) >> 0x12 | (int)((ulonglong)(lVar15 + lVar4) >> 0x20) * 0x4000
               ) + ((uint)(lVar16 + lVar4) >> 0x12 |
                   (int)((ulonglong)(lVar16 + lVar4) >> 0x20) * 0x4000) +
               ((uint)(lVar17 + lVar4) >> 0x12 | (int)((ulonglong)(lVar17 + lVar4) >> 0x20) * 0x4000
               ) + (uVar8 + uVar5 >> 0x12 |
                   ((*(uint *)(param_3 + 0x34) >> 0xe) + iVar10 + (uint)CARRY4(uVar8,uVar5)) *
                   0x4000);
  lVar15 = __aeabi_lmul(*(int *)(param_3 + 0x18),*(int *)(param_3 + 0x18) >> 0x1f,tVar2,iVar7);
  lVar16 = __aeabi_lmul(*(int *)(param_3 + 8),*(int *)(param_3 + 8) >> 0x1f,tVar1,iVar6);
  lVar17 = __aeabi_lmul(*(int *)(param_3 + 0x28),*(int *)(param_3 + 0x28) >> 0x1f,tVar3,iVar12);
  uVar8 = *(uint *)(param_3 + 0x38) * 0x40000;
  piVar14[2] = ((uint)(lVar15 + lVar4) >> 0x12 | (int)((ulonglong)(lVar15 + lVar4) >> 0x20) * 0x4000
               ) + ((uint)(lVar16 + lVar4) >> 0x12 |
                   (int)((ulonglong)(lVar16 + lVar4) >> 0x20) * 0x4000) +
               ((uint)(lVar17 + lVar4) >> 0x12 | (int)((ulonglong)(lVar17 + lVar4) >> 0x20) * 0x4000
               ) + (uVar8 + uVar5 >> 0x12 |
                   ((*(uint *)(param_3 + 0x38) >> 0xe) + iVar10 + (uint)CARRY4(uVar8,uVar5)) *
                   0x4000);
  lVar15 = __aeabi_lmul(*(int *)(param_3 + 0x1c),*(int *)(param_3 + 0x1c) >> 0x1f,tVar2,iVar7);
  lVar16 = __aeabi_lmul(*(int *)(param_3 + 0xc),*(int *)(param_3 + 0xc) >> 0x1f,tVar1,iVar6);
  lVar17 = __aeabi_lmul(*(int *)(param_3 + 0x2c),*(int *)(param_3 + 0x2c) >> 0x1f,tVar3,iVar12);
  uVar8 = *(uint *)(param_3 + 0x3c) * 0x40000;
  iVar10 = ((uint)(lVar17 + lVar4) >> 0x12 | (int)((ulonglong)(lVar17 + lVar4) >> 0x20) * 0x4000) +
           ((uint)(lVar16 + lVar4) >> 0x12 | (int)((ulonglong)(lVar16 + lVar4) >> 0x20) * 0x4000) +
           ((uint)(lVar15 + lVar4) >> 0x12 | (int)((ulonglong)(lVar15 + lVar4) >> 0x20) * 0x4000) +
           (uVar8 + uVar5 >> 0x12 |
           ((*(uint *)(param_3 + 0x3c) >> 0xe) + iVar10 + (uint)CARRY4(uVar8,uVar5)) * 0x4000);
  piVar14[3] = iVar10;
  if (iVar10 == 0) {
    local_38 = (undefined)iVar9;
    *(undefined *)param_1 = local_38;
    *(char *)((int)param_1 + 1) = (char)((uint)iVar9 >> 8);
    *(char *)((int)param_1 + 2) = (char)((uint)iVar9 >> 0x10);
    *(char *)((int)param_1 + 3) = (char)((uint)iVar9 >> 0x18);
    *(undefined *)(param_1 + 1) = *(undefined *)(piVar14 + 1);
    *(undefined *)((int)param_1 + 5) = *(undefined *)((int)piVar14 + 5);
    *(undefined *)((int)param_1 + 6) = *(undefined *)((int)piVar14 + 6);
    *(undefined *)((int)param_1 + 7) = *(undefined *)((int)piVar14 + 7);
    *(undefined *)(param_1 + 2) = *(undefined *)(piVar14 + 2);
    *(undefined *)((int)param_1 + 9) = *(undefined *)((int)piVar14 + 9);
    *(undefined *)((int)param_1 + 10) = *(undefined *)((int)piVar14 + 10);
    *(undefined *)((int)param_1 + 0xb) = *(undefined *)((int)piVar14 + 0xb);
  }
  else {
    iVar10 = __aeabi_ldivmod(DAT_000c9e70,DAT_000c9e74,iVar10,iVar10 >> 0x1f);
    iVar6 = iVar10 >> 0x1f;
    lVar15 = __aeabi_lmul(iVar10,iVar6,iVar9,iVar9 >> 0x1f);
    lVar15 = lVar15 + lVar4;
    iVar7 = (int)((ulonglong)lVar15 >> 0x20) * 0x4000;
    *(char *)param_1 = (char)((uint)lVar15 >> 0x12);
    *(byte *)((int)param_1 + 1) = (byte)((ulonglong)lVar15 >> 0x18) >> 2 | (byte)((uint)iVar7 >> 8);
    *(char *)((int)param_1 + 2) = (char)((uint)iVar7 >> 0x10);
    *(char *)((int)param_1 + 3) = (char)((uint)iVar7 >> 0x18);
    lVar15 = __aeabi_lmul(iVar10,iVar6,piVar14[1],piVar14[1] >> 0x1f);
    lVar15 = lVar15 + lVar4;
    iVar7 = (int)((ulonglong)lVar15 >> 0x20) * 0x4000;
    *(char *)(param_1 + 1) = (char)((uint)lVar15 >> 0x12);
    *(byte *)((int)param_1 + 5) = (byte)((ulonglong)lVar15 >> 0x18) >> 2 | (byte)((uint)iVar7 >> 8);
    *(char *)((int)param_1 + 6) = (char)((uint)iVar7 >> 0x10);
    *(char *)((int)param_1 + 7) = (char)((uint)iVar7 >> 0x18);
    lVar15 = __aeabi_lmul(iVar10,iVar6,piVar14[2],piVar14[2] >> 0x1f);
    lVar15 = lVar15 + lVar4;
    iVar10 = (int)((ulonglong)lVar15 >> 0x20) * 0x4000;
    *(char *)(param_1 + 2) = (char)((uint)lVar15 >> 0x12);
    *(byte *)((int)param_1 + 9) = (byte)((ulonglong)lVar15 >> 0x18) >> 2 | (byte)((uint)iVar10 >> 8)
    ;
    *(char *)((int)param_1 + 10) = (char)((uint)iVar10 >> 0x10);
    *(char *)((int)param_1 + 0xb) = (char)((uint)iVar10 >> 0x18);
  }
  return;
}


