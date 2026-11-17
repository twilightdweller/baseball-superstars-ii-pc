/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(int, int, int) */

int CCLProjection::TransformPoint(int param_1,int param_2,int param_3,byte param_4,int param_5)

{
  tagCLxPoint3 local_1c;
  int local_18;
  int local_14;
  
  local_18 = (uint)param_4 << 0x12;
  local_1c = param_3 << 0x12;
  local_14 = param_5 << 0x12;
  TransformPoint((CCLProjection *)param_2,(bbtagPoint2D *)param_1,&local_1c);
  return param_1;
}


