/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(bbtagPoint2D*, CL_Point3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,bbtagPoint2D *param_1,CL_Point3 *param_2)

{
  tagCLxPoint3 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_24 = *(int *)param_2 << 0x12;
  local_20 = *(int *)(param_2 + 4) << 0x12;
  local_1c = *(int *)(param_2 + 8) << 0x12;
  TransformPoint(this,(CL_xPoint2 *)&local_18,&local_24);
  *param_1 = local_18 + 0x20000 >> 0x12;
  param_1[1] = local_14 + 0x20000 >> 0x12;
  return;
}


