/* CCLFigureMgr::IntersectStrikeZone; research only, not buildable source */

/* CCLFigureMgr::IntersectStrikeZone(bbtagPoint2D*) */

void __thiscall CCLFigureMgr::IntersectStrikeZone(CCLFigureMgr *this,bbtagPoint2D *param_1)

{
  int iVar1;
  CCLProjection *this_00;
  tagCLxPoint3 local_5c;
  int local_58;
  undefined4 local_54;
  tagCLxPoint3 local_50;
  int local_4c;
  undefined4 local_48;
  bbtagPoint2D local_44;
  int local_40;
  int local_3c;
  int local_38;
  bbtagPoint2D local_34;
  int local_30;
  bbtagPoint2D local_2c;
  int local_28;
  int local_24 [2];
  undefined4 local_1c;
  
  iVar1 = **(int **)(DAT_000a6e6c + 0xa6de0 + DAT_000a6e70);
  xToVirtual((bbtagPoint2D)local_24);
  local_5c = local_24[0] - *(int *)(this + 0x184);
  local_50 = *(int *)(this + 0x184) + local_24[0];
  local_58 = *(int *)(this + 0x180) * -0x40000 - *(int *)(this + 0x188);
  this_00 = (CCLProjection *)(iVar1 + 4);
  local_4c = *(int *)(this + 0x180) * -0x40000 + *(int *)(this + 0x188);
  local_54 = local_1c;
  local_48 = local_1c;
  CCLProjection::TransformPoint(this_00,&local_34,&local_5c);
  CCLProjection::TransformPoint(this_00,&local_2c,&local_50);
  local_44 = local_34;
  local_3c = local_2c - local_34;
  local_40 = local_30;
  local_38 = local_28 - local_30;
  CLUtil::IntersectRect((CL_Rect *)&local_44,param_1);
  return;
}


