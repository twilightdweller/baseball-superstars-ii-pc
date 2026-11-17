/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(bbtagPoint2D*, tagCLxPoint3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,bbtagPoint2D *param_1,tagCLxPoint3 *param_2)

{
  int local_18;
  int local_14;
  
  TransformPoint(this,(CL_xPoint2 *)&local_18,param_2);
  *param_1 = local_18 + 0x20000 >> 0x12;
  param_1[1] = local_14 + 0x20000 >> 0x12;
  return;
}


