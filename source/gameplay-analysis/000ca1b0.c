/* CCLMatrix::MulPoint; research only, not buildable source */

/* CCLMatrix::MulPoint(CL_Point3*, CL_Point3*) */

void __thiscall CCLMatrix::MulPoint(CCLMatrix *this,CL_Point3 *param_1,CL_Point3 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  longlong lVar6;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  
  local_30 = *(int *)param_2 << 0x12;
  local_2c = *(int *)(param_2 + 4) << 0x12;
  local_28 = *(int *)(param_2 + 8) << 0x12;
  local_24 = 0x40000;
  MatrixMul((CL_xPoint4 *)&local_30,(CL_xPoint4 *)&local_30,(CL_xMatrix *)(this + 0x24));
  uVar1 = local_24 * 2 + 1;
  iVar4 = DAT_000ca2a0 + 0xca204;
  uVar3 = uVar1 * 0x20000 >> 0x12 |
          (((((int)local_24 >> 0x1f) << 1 | local_24 >> 0x1f) + (uint)(0xfffffffe < local_24 * 2)) *
           0x20000 | uVar1 >> 0xf) << 0xe;
  iVar2 = (int)uVar3 >> 0x1f;
  lVar6 = __aeabi_lmul(uVar3,iVar2,local_30,local_30 >> 0x1f);
  lVar6 = lVar6 + CONCAT44(DAT_000ca29c,DAT_000ca298);
  uVar1 = (uint)lVar6 >> 0x12 | (int)((ulonglong)lVar6 >> 0x20) * 0x4000;
  puVar5 = *(uint **)(iVar4 + DAT_000ca2a4);
  *puVar5 = uVar1;
  lVar6 = __aeabi_lmul(uVar3,iVar2,local_2c,local_2c >> 0x1f);
  lVar6 = lVar6 + CONCAT44(DAT_000ca29c,DAT_000ca298);
  puVar5[1] = (uint)lVar6 >> 0x12 | (int)((ulonglong)lVar6 >> 0x20) * 0x4000;
  lVar6 = __aeabi_lmul(uVar3,iVar2,local_28,local_28 >> 0x1f);
  lVar6 = lVar6 + CONCAT44(DAT_000ca29c,DAT_000ca298);
  puVar5[2] = (uint)lVar6 >> 0x12 | (int)((ulonglong)lVar6 >> 0x20) * 0x4000;
  *(int *)param_1 = (int)(uVar1 + 0x20000) >> 0x12;
  *(int *)(param_1 + 4) = (int)(puVar5[1] + 0x20000) >> 0x12;
  *(int *)(param_1 + 8) = (int)(puVar5[2] + 0x20000) >> 0x12;
  return;
}


