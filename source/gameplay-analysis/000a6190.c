/* CCLFigureMgr::DrawFloor; research only, not buildable source */

/* CCLFigureMgr::DrawFloor(CGsGraphics&, CCLProjection*) */

void __thiscall
CCLFigureMgr::DrawFloor(CCLFigureMgr *this,CGsGraphics *param_1,CCLProjection *param_2)

{
  uint uVar1;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined auStack_1c [8];
  int local_14;
  
  if (param_2 == (CCLProjection *)0x0) {
    param_2 = (CCLProjection *)(**(int **)(DAT_000a61fc + 0xa619c + DAT_000a6208) + 4);
  }
  GetDefensePos3D((int)auStack_1c);
  local_48 = 0;
  local_3c = 0;
  local_30 = 0;
  local_24 = 0;
  local_44 = local_14 + DAT_000a6204;
  local_4c = 0xffffff9c;
  local_40 = 100;
  local_38 = local_14;
  local_34 = 100;
  local_20 = local_14;
  local_28 = 0xffffff9c;
  local_2c = local_44;
  uVar1 = MC_grpGetPixelFromRGB(0,0xff,0);
  CLUtil::DrawGridRect(param_2,param_1,(CL_Point3 *)&local_4c,0x32,uVar1);
  return;
}


