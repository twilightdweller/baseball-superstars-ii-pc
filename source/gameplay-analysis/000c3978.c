/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(CL_xPoint4*, CL_fPoint3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,CL_xPoint4 *param_1,CL_fPoint3 *param_2)

{
  tagCLxPoint3 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  __mulsf3(*(undefined4 *)param_2,0x48800000);
  local_24 = __aeabi_f2iz();
  __mulsf3(*(undefined4 *)(param_2 + 4),0x48800000);
  local_20 = __aeabi_f2iz();
  __mulsf3(*(undefined4 *)(param_2 + 8),0x48800000);
  local_1c = __aeabi_f2iz();
  TransformPoint(this,param_1,&local_24);
  return;
}


