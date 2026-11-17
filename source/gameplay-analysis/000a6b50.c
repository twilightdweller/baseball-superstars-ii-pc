/* CCLFigureMgr::DrawStrikeZone; research only, not buildable source */

/* CCLFigureMgr::DrawStrikeZone(CGsGraphics&, CCLProjection*) */

void __thiscall
CCLFigureMgr::DrawStrikeZone(CCLFigureMgr *this,CGsGraphics *param_1,CCLProjection *param_2)

{
  bbtagPoint2D bVar1;
  int iVar2;
  uint uVar3;
  bbtagPoint2D *pbVar4;
  tagCLxPoint3 *ptVar5;
  tagCLxPoint3 *ptVar6;
  tagCLxPoint3 *ptVar7;
  tagCLxPoint3 local_ac;
  int local_a8;
  undefined4 local_a4;
  int local_a0;
  int local_9c;
  undefined4 local_98;
  int local_94;
  int local_90;
  undefined4 local_8c;
  tagCLxPoint3 local_88;
  int local_84;
  undefined4 local_80;
  bbtagPoint2D local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  tagCLxPoint3 local_5c;
  int local_58;
  undefined4 local_54;
  tagCLxPoint3 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  bbtagPoint2D local_44;
  int local_40;
  bbtagPoint2D local_3c;
  int local_38;
  tagCLxPoint3 local_34;
  int local_30;
  undefined4 local_2c;
  
  if (param_2 == (CCLProjection *)0x0) {
    param_2 = (CCLProjection *)(**(int **)(DAT_000a6dc8 + 0xa6b66 + DAT_000a6dcc) + 4);
  }
  xToVirtual((bbtagPoint2D)&local_34);
  local_58 = *(int *)(this + 0x180) * -0x40000;
  local_54 = local_2c;
  local_48 = local_2c;
  local_5c = local_34;
  local_50 = local_34;
  local_4c = 0;
  local_30 = local_58;
  CCLProjection::TransformPoint(param_2,&local_44,&local_5c);
  CCLProjection::TransformPoint(param_2,&local_3c,&local_50);
  iVar2 = local_40;
  bVar1 = local_44;
  uVar3 = MC_grpGetPixelFromRGB(0,0,0xff);
  CLGrp::DrawEllipse(param_1,bVar1 - 5,iVar2 + -5,10,10,uVar3);
  iVar2 = local_38;
  bVar1 = local_3c;
  uVar3 = MC_grpGetPixelFromRGB(0,0,0xff);
  CLGrp::DrawEllipse(param_1,bVar1 - 5,iVar2 + -5,10,10,uVar3);
  uVar3 = MC_grpGetPixelFromRGB(0xff,0xc4,0);
  CLGrp::DrawLine(param_1,local_44,local_40,local_3c,local_38,uVar3);
  ptVar6 = &local_ac;
  local_ac = local_5c - *(int *)(this + 0x184);
  local_a0 = *(int *)(this + 0x184) + local_5c;
  local_a8 = local_58 - *(int *)(this + 0x188);
  local_90 = *(int *)(this + 0x188) + local_58;
  local_a4 = local_54;
  local_98 = local_54;
  local_8c = local_54;
  local_80 = local_54;
  local_9c = local_a8;
  local_94 = local_a0;
  local_88 = local_ac;
  local_84 = local_90;
  uVar3 = MC_grpGetPixelFromRGB(0xff,0,0);
  pbVar4 = &local_7c;
  ptVar7 = ptVar6;
  do {
    ptVar5 = pbVar4 + 2;
    CCLProjection::TransformPoint(param_2,pbVar4,ptVar7);
    ptVar7 = ptVar7 + 3;
    pbVar4 = ptVar5;
  } while (&local_5c != ptVar5);
  CLGrp::DrawLine(param_1,local_7c,local_78,local_74,local_70,uVar3);
  CLGrp::DrawLine(param_1,local_74,local_70,local_6c,local_68,uVar3);
  CLGrp::DrawLine(param_1,local_6c,local_68,local_64,local_60,uVar3);
  CLGrp::DrawLine(param_1,local_64,local_60,local_7c,local_78,uVar3);
  local_ac = local_5c - *(int *)(this + 0x18c);
  local_a8 = local_58 - *(int *)(this + 400);
  local_90 = *(int *)(this + 400) + local_58;
  local_a4 = local_54;
  local_98 = local_54;
  local_a0 = *(int *)(this + 0x18c) + local_5c;
  local_8c = local_54;
  local_80 = local_54;
  local_9c = local_a8;
  local_94 = local_a0;
  local_88 = local_ac;
  local_84 = local_90;
  uVar3 = MC_grpGetPixelFromRGB(0xff,0xff,0);
  pbVar4 = &local_7c;
  do {
    ptVar7 = pbVar4 + 2;
    CCLProjection::TransformPoint(param_2,pbVar4,ptVar6);
    ptVar6 = ptVar6 + 3;
    pbVar4 = ptVar7;
  } while (&local_5c != ptVar7);
  CLGrp::DrawLine(param_1,local_7c,local_78,local_74,local_70,uVar3);
  CLGrp::DrawLine(param_1,local_74,local_70,local_6c,local_68,uVar3);
  CLGrp::DrawLine(param_1,local_6c,local_68,local_64,local_60,uVar3);
  CLGrp::DrawLine(param_1,local_64,local_60,local_7c,local_78,uVar3);
  return;
}


