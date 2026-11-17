/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(CL_fPoint2*, CL_Point3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,CL_fPoint2 *param_1,CL_Point3 *param_2)

{
  undefined4 uVar1;
  tagCLxPoint3 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_24 = *(int *)param_2 << 0x12;
  local_20 = *(int *)(param_2 + 4) << 0x12;
  local_1c = *(int *)(param_2 + 8) << 0x12;
  TransformPoint(this,(CL_xPoint2 *)&local_18,&local_24);
  uVar1 = __aeabi_i2f(local_18);
  uVar1 = __mulsf3(uVar1,0x36800000);
  *(undefined4 *)param_1 = uVar1;
  uVar1 = __aeabi_i2f(local_14);
  uVar1 = __mulsf3(uVar1,0x36800000);
  *(undefined4 *)(param_1 + 4) = uVar1;
  return;
}


