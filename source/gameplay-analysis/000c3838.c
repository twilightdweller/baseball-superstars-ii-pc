/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(CL_fPoint2*, CL_fPoint3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,CL_fPoint2 *param_1,CL_fPoint3 *param_2)

{
  undefined4 uVar1;
  tagCLxPoint3 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  __mulsf3(*(undefined4 *)param_2,0x48800000);
  local_2c = __aeabi_f2iz();
  __mulsf3(*(undefined4 *)(param_2 + 4),0x48800000);
  local_28 = __aeabi_f2iz();
  __mulsf3(*(undefined4 *)(param_2 + 8),0x48800000);
  local_24 = __aeabi_f2iz();
  TransformPoint(this,(CL_xPoint2 *)&local_20,&local_2c);
  uVar1 = __aeabi_i2f(local_20);
  uVar1 = __mulsf3(uVar1,0x36800000);
  *(undefined4 *)param_1 = uVar1;
  uVar1 = __aeabi_i2f(local_1c);
  uVar1 = __mulsf3(uVar1,0x36800000);
  *(undefined4 *)(param_1 + 4) = uVar1;
  return;
}


