/* CCLMatrix::MulPoint; research only, not buildable source */

/* CCLMatrix::MulPoint(tagCLxPoint3*, tagCLxPoint3*) */

void __thiscall CCLMatrix::MulPoint(CCLMatrix *this,tagCLxPoint3 *param_1,tagCLxPoint3 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  tagCLxPoint3 local_28;
  tagCLxPoint3 local_24;
  tagCLxPoint3 local_20;
  int local_1c;
  
  local_28 = *param_2;
  local_24 = param_2[1];
  local_20 = param_2[2];
  local_1c = 0x40000;
  MatrixMul((CL_xPoint4 *)&local_28,(CL_xPoint4 *)&local_28,(CL_xMatrix *)(this + 0x24));
  uVar2 = local_1c * 2 + 1;
  uVar2 = uVar2 * 0x20000 >> 0x12 |
          (((uint)(0xfffffffe < (uint)(local_1c * 2)) - (local_1c >> 0x1f)) * 0x20000 | uVar2 >> 0xf
          ) << 0xe;
  iVar3 = (int)uVar2 >> 0x1f;
  lVar4 = __aeabi_lmul(uVar2,iVar3,local_28,(int)local_28 >> 0x1f);
  lVar4 = lVar4 + CONCAT44(DAT_000ca1ac,DAT_000ca1a8);
  iVar1 = (int)((ulonglong)lVar4 >> 0x20) * 0x4000;
  *(char *)param_1 = (char)((uint)lVar4 >> 0x12);
  *(byte *)((int)param_1 + 1) = (byte)((ulonglong)lVar4 >> 0x18) >> 2 | (byte)((uint)iVar1 >> 8);
  *(char *)((int)param_1 + 2) = (char)((uint)iVar1 >> 0x10);
  *(char *)((int)param_1 + 3) = (char)((uint)iVar1 >> 0x18);
  lVar4 = __aeabi_lmul(uVar2,iVar3,local_24,(int)local_24 >> 0x1f);
  lVar4 = lVar4 + CONCAT44(DAT_000ca1ac,DAT_000ca1a8);
  iVar1 = (int)((ulonglong)lVar4 >> 0x20) * 0x4000;
  *(char *)(param_1 + 1) = (char)((uint)lVar4 >> 0x12);
  *(byte *)((int)param_1 + 5) = (byte)((ulonglong)lVar4 >> 0x18) >> 2 | (byte)((uint)iVar1 >> 8);
  *(char *)((int)param_1 + 6) = (char)((uint)iVar1 >> 0x10);
  *(char *)((int)param_1 + 7) = (char)((uint)iVar1 >> 0x18);
  lVar4 = __aeabi_lmul(uVar2,iVar3,local_20,(int)local_20 >> 0x1f);
  lVar4 = lVar4 + CONCAT44(DAT_000ca1ac,DAT_000ca1a8);
  iVar1 = (int)((ulonglong)lVar4 >> 0x20) * 0x4000;
  *(char *)(param_1 + 2) = (char)((uint)lVar4 >> 0x12);
  *(byte *)((int)param_1 + 9) = (byte)((ulonglong)lVar4 >> 0x18) >> 2 | (byte)((uint)iVar1 >> 8);
  *(char *)((int)param_1 + 10) = (char)((uint)iVar1 >> 0x10);
  *(char *)((int)param_1 + 0xb) = (char)((uint)iVar1 >> 0x18);
  return;
}


