/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(bbtagPoint2D*, CL_fPoint3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,bbtagPoint2D *param_1,CL_fPoint3 *param_2)

{
  tagCLxPoint3 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  
  __mulsf3(*(undefined4 *)param_2,0x48800000);
  local_2c = __aeabi_f2iz();
  __mulsf3(*(undefined4 *)(param_2 + 4),0x48800000);
  local_28 = __aeabi_f2iz();
  __mulsf3(*(undefined4 *)(param_2 + 8),0x48800000);
  local_24 = __aeabi_f2iz();
  TransformPoint(this,(CL_xPoint2 *)&local_20,&local_2c);
  *param_1 = local_20 + 0x20000 >> 0x12;
  param_1[1] = local_1c + 0x20000 >> 0x12;
  return;
}


