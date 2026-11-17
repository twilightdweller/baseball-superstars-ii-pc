/* CCLFigureMgr::IntersectStrikeZone; research only, not buildable source */

/* CCLFigureMgr::IntersectStrikeZone(CL_Point3*) */

void __thiscall CCLFigureMgr::IntersectStrikeZone(CCLFigureMgr *this,CL_Point3 *param_1)

{
  int iVar1;
  CCLProjection *this_00;
  tagCLxPoint3 local_6c;
  int local_68;
  undefined4 local_64;
  tagCLxPoint3 local_60;
  int local_5c;
  undefined4 local_58;
  bbtagPoint2D local_54;
  int local_50;
  int local_4c;
  int local_48;
  bbtagPoint2D local_44;
  int local_40;
  bbtagPoint2D local_3c;
  int local_38;
  int local_34 [2];
  undefined4 local_2c;
  bbtagPoint2D abStack_28 [2];
  
  iVar1 = **(int **)(DAT_000a62c0 + 0xa6220 + DAT_000a62c4);
  xToVirtual((bbtagPoint2D)local_34);
  this_00 = (CCLProjection *)(iVar1 + 4);
  iVar1 = *(int *)(this + 0x180);
  CCLProjection::TransformPoint(this_00,abStack_28,param_1);
  local_6c = local_34[0] - *(int *)(this + 0x184);
  local_68 = iVar1 * -0x40000 - *(int *)(this + 0x188);
  local_60 = local_34[0] + *(int *)(this + 0x184);
  local_5c = iVar1 * -0x40000 + *(int *)(this + 0x188);
  local_64 = local_2c;
  local_58 = local_2c;
  CCLProjection::TransformPoint(this_00,&local_44,&local_6c);
  CCLProjection::TransformPoint(this_00,&local_3c,&local_60);
  local_54 = local_44;
  local_4c = local_3c - local_44;
  local_50 = local_40;
  local_48 = local_38 - local_40;
  CLUtil::IntersectRect((CL_Rect *)&local_54,abStack_28);
  return;
}


