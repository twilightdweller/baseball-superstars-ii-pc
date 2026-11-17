/* CCLProjection::CalcMovableTransform; research only, not buildable source */

/* CCLProjection::CalcMovableTransform(tagCLxPoint3*, CL_MovableTransformInfo*, long, long) */

void __thiscall
CCLProjection::CalcMovableTransform
          (CCLProjection *this,tagCLxPoint3 *param_1,CL_MovableTransformInfo *param_2,long param_3,
          long param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  tagCLxPoint3 *ptVar6;
  tagCLxPoint3 local_5c;
  tagCLxPoint3 local_58;
  tagCLxPoint3 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  tagCLxPoint3 local_44;
  undefined4 local_40;
  tagCLxPoint3 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar3 = param_1[1];
  iVar5 = DAT_000c36d8 + 0xc35f0;
  ptVar6 = &local_5c;
  iVar1 = *(int *)(**(int **)(iVar5 + DAT_000c36dc) + 4) * -0x40000;
  iVar1 = __aeabi_ldivmod(uVar3 << 0x12,((int)uVar3 >> 0x1f) << 0x12 | uVar3 >> 0xe,iVar1,
                          iVar1 >> 0x1f);
  *(long *)(param_2 + 0x18) = param_4 + iVar1;
  iVar1 = -(param_4 + iVar1);
  uVar3 = iVar1 + 0x40000;
  *(uint *)(param_2 + 0x1c) =
       (uint)((int)("_ZN16CGsParticleMgrEx13CreateEmitterEiPK12tagGsEmitteriiiibbb" + iVar1 + 0x19)
             * 0x20000) >> 0x12 |
       ((((int)uVar3 >> 0x1f) + (uint)(0xfffffffe < uVar3)) * 0x20000 |
       (uint)("_ZN16CGsParticleMgrEx13CreateEmitterEiPK12tagGsEmitteriiiibbb" + iVar1 + 0x19) >> 0xf
       ) << 0xe;
  local_5c = *param_1;
  local_58 = param_1[1];
  local_54 = param_1[2];
  puVar2 = *(undefined4 **)(iVar5 + DAT_000c36e0);
  local_50 = *puVar2;
  local_4c = puVar2[1];
  local_48 = puVar2[2];
  local_40 = 0;
  puVar2 = &local_38;
  local_44 = local_5c;
  local_3c = local_54;
  do {
    puVar4 = puVar2 + 2;
    TransformPoint(this,(CL_xPoint2 *)puVar2,ptVar6);
    ptVar6 = ptVar6 + 3;
    puVar2 = puVar4;
  } while (puVar4 != (undefined4 *)&stack0xffffffe0);
  *(long *)(param_2 + 0x20) = param_3;
  *(undefined4 *)param_2 = local_38;
  *(undefined4 *)(param_2 + 4) = local_34;
  *(undefined4 *)(param_2 + 8) = local_30;
  *(undefined4 *)(param_2 + 0xc) = local_2c;
  *(undefined4 *)(param_2 + 0x10) = local_28;
  *(undefined4 *)(param_2 + 0x14) = local_24;
  return;
}


