/* CCLPitch::GetBallTransform; research only, not buildable source */

/* CCLPitch::GetBallTransform(int) */

int __thiscall CCLPitch::GetBallTransform(CCLPitch *this,int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  CL_xPoint2 *pCVar4;
  int iVar5;
  longlong lVar6;
  tagCLxPoint3 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  tagCLxPoint3 local_34 [2];
  undefined4 local_2c;
  
  iVar3 = DAT_000c41b0 + 0xc40e0;
  iVar5 = DAT_000c41b4;
  if (*(int *)(this + 0x84) != 0) {
    iVar2 = (*(int *)(this + 0x88) + -3) * 0x40000;
    memcpy(local_34,(void *)(param_1 * 0xc + *(int *)(this + 0x84)),0xc);
    iVar5 = DAT_000c41b4;
    local_40 = local_34[0];
    local_38 = local_2c;
    local_3c = 0;
    pCVar4 = (CL_xPoint2 *)(iVar3 + DAT_000c41b4);
    CCLProjection::TransformPoint(*(CCLProjection **)(this + 0xcc),pCVar4,local_34);
    CCLProjection::TransformPoint(*(CCLProjection **)(this + 0xcc),pCVar4 + 0x10,&local_40);
    uVar1 = __aeabi_ldivmod(0,((param_1 << 0x12) >> 0x1f) << 0x12 | (uint)(param_1 << 0x12) >> 0xe,
                            iVar2,iVar2 >> 0x1f);
    *(uint *)(pCVar4 + 0x18) = uVar1;
    uVar1 = (uVar1 + 1) * 0x20000 >> 0x12 |
            ((((int)uVar1 >> 0x1f) + (uint)(0xfffffffe < uVar1)) * 0x20000 | uVar1 + 1 >> 0xf) <<
            0xe;
    lVar6 = __aeabi_lmul(uVar1,(int)uVar1 >> 0x1f);
    lVar6 = lVar6 + CONCAT44(DAT_000c41ac,DAT_000c41a8);
    *(uint *)(pCVar4 + 0x1c) = (uint)lVar6 >> 0x12 | (int)((ulonglong)lVar6 >> 0x20) * 0x4000;
  }
  return iVar3 + iVar5;
}


