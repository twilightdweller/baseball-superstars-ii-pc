/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(CL_xPoint4*, CL_Point3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,CL_xPoint4 *param_1,CL_Point3 *param_2)

{
  tagCLxPoint3 local_14;
  int local_10;
  int local_c;
  
  local_14 = *(int *)param_2 << 0x12;
  local_10 = *(int *)(param_2 + 4) << 0x12;
  local_c = *(int *)(param_2 + 8) << 0x12;
  TransformPoint(this,param_1,&local_14);
  return;
}


