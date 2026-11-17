/* CCLFigureMgr::DrawFoulLine; research only, not buildable source */

/* CCLFigureMgr::DrawFoulLine(CGsGraphics&, CCLProjection*) */

void __thiscall
CCLFigureMgr::DrawFoulLine(CCLFigureMgr *this,CGsGraphics *param_1,CCLProjection *param_2)

{
  bbtagPoint2D bVar1;
  int iVar2;
  bbtagPoint2D bVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  bbtagPoint2D local_68;
  int local_64;
  bbtagPoint2D local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (param_2 == (CCLProjection *)0x0) {
    param_2 = (CCLProjection *)(**(int **)(DAT_000a6604 + 0xa64de + DAT_000a6608) + 4);
  }
  ToVirtual((bbtagPoint2D)&local_34);
  local_80 = local_34;
  local_7c = local_30;
  local_78 = local_2c;
  ToVirtual((bbtagPoint2D)&local_40);
  local_74 = local_40;
  local_70 = local_3c;
  local_6c = local_38;
  CCLProjection::TransformPoint(param_2,&local_68,(CL_Point3 *)&local_80);
  CCLProjection::TransformPoint(param_2,&local_60,(CL_Point3 *)&local_74);
  iVar4 = local_5c;
  bVar3 = local_60;
  iVar2 = local_64;
  bVar1 = local_68;
  uVar5 = MC_grpGetPixelFromRGB(0xff,0,0xff);
  CLGrp::DrawLine(param_1,bVar1,iVar2,bVar3,iVar4,uVar5);
  ToVirtual((bbtagPoint2D)&local_4c);
  local_80 = local_4c;
  local_7c = local_48;
  local_78 = local_44;
  ToVirtual((bbtagPoint2D)&local_58);
  local_74 = local_58;
  local_70 = local_54;
  local_6c = local_50;
  CCLProjection::TransformPoint(param_2,&local_68,(CL_Point3 *)&local_80);
  CCLProjection::TransformPoint(param_2,&local_60,(CL_Point3 *)&local_74);
  uVar5 = MC_grpGetPixelFromRGB(0xff,0,0xff);
  CLGrp::DrawLine(param_1,local_68,local_64,local_60,local_5c,uVar5);
  return;
}


