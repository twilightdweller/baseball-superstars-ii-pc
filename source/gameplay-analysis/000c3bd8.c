/* CCLProjection::gluPerspective; research only, not buildable source */

/* CCLProjection::gluPerspective(long, long, long, long) */

void __thiscall
CCLProjection::gluPerspective
          (CCLProjection *this,long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  
  iVar1 = CLMath::xTan(param_1);
  lVar5 = __aeabi_lmul(iVar1,iVar1 >> 0x1f,param_3,param_3 >> 0x1f);
  lVar5 = lVar5 + CONCAT44(DAT_000c3ca4,DAT_000c3ca0);
  uVar4 = (uint)lVar5 >> 0x12 | (int)((ulonglong)lVar5 >> 0x20) * 0x4000;
  iVar1 = -uVar4;
  lVar5 = __aeabi_lmul(iVar1,iVar1 >> 0x1f,param_2,param_2 >> 0x1f);
  lVar5 = lVar5 + CONCAT44(DAT_000c3ca4,DAT_000c3ca0);
  uVar2 = (uint)lVar5 >> 0x12 | (int)((ulonglong)lVar5 >> 0x20) * 0x4000;
  lVar5 = __aeabi_lmul(uVar4,(int)uVar4 >> 0x1f,param_2,param_2 >> 0x1f);
  lVar5 = lVar5 + CONCAT44(DAT_000c3ca4,DAT_000c3ca0);
  uVar3 = (uint)lVar5 >> 0x12 | (int)((ulonglong)lVar5 >> 0x20) * 0x4000;
  glFrustum(this,uVar2,uVar3,uVar4,iVar1,param_3,param_4);
  *(long *)(this + 0xe0) = param_1;
  *(long *)(this + 0xe4) = param_2;
  *(long *)(this + 0xe8) = param_3;
  *(long *)(this + 0xec) = param_4;
  *(uint *)(this + 0xf0) = uVar2;
  *(uint *)(this + 0xf4) = uVar3;
  *(uint *)(this + 0xfc) = uVar4;
  *(int *)(this + 0xf8) = iVar1;
  *(undefined4 *)(this + 0xdc) = 0;
  return;
}


