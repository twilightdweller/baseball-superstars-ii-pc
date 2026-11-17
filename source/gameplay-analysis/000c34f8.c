/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(CL_xPoint2*, tagCLxPoint3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,CL_xPoint2 *param_1,tagCLxPoint3 *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  uint local_2c;
  uint local_28;
  int local_24;
  
  CCLMatrix::MatrixMul(&local_2c,param_2,(CL_xMatrix *)(this + 0x84));
  if (local_24 != 0) {
    iVar1 = __aeabi_ldivmod(DAT_000c35b8,DAT_000c35bc,local_24,local_24 >> 0x1f);
    lVar2 = __aeabi_lmul(iVar1,iVar1 >> 0x1f,local_2c,(int)local_2c >> 0x1f);
    lVar2 = lVar2 + CONCAT44(DAT_000c35c4,DAT_000c35c0);
    lVar3 = __aeabi_lmul(iVar1,iVar1 >> 0x1f,local_28,(int)local_28 >> 0x1f);
    lVar3 = lVar3 + CONCAT44(DAT_000c35c4,DAT_000c35c0);
    local_28 = (uint)lVar3 >> 0x12 | (int)((ulonglong)lVar3 >> 0x20) * 0x4000;
    local_2c = (int)((ulonglong)lVar2 >> 0x20) * 0x4000 | (uint)lVar2 >> 0x12;
  }
  lVar2 = __aeabi_lmul(local_2c,(int)local_2c >> 0x1f,*(int *)(this + 0xd4),
                       *(int *)(this + 0xd4) >> 0x1f);
  lVar2 = lVar2 + CONCAT44(DAT_000c35c4,DAT_000c35c0);
  lVar3 = __aeabi_lmul(*(int *)(this + 0xd8),*(int *)(this + 0xd8) >> 0x1f,local_28,
                       (int)local_28 >> 0x1f);
  lVar3 = lVar3 + CONCAT44(DAT_000c35c4,DAT_000c35c0);
  iVar1 = *(int *)(this + 200);
  *(uint *)param_1 =
       *(int *)(this + 0xc4) - ((uint)lVar2 >> 0x12 | (int)((ulonglong)lVar2 >> 0x20) * 0x4000);
  *(uint *)(param_1 + 4) = ((uint)lVar3 >> 0x12 | (int)((ulonglong)lVar3 >> 0x20) * 0x4000) + iVar1;
  return;
}


