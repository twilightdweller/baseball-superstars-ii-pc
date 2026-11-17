/* CCLFigureMgr::DrawPitchStartPos; research only, not buildable source */

/* CCLFigureMgr::DrawPitchStartPos(CGsGraphics&, int, CCLProjection*) */

void __thiscall
CCLFigureMgr::DrawPitchStartPos
          (CCLFigureMgr *this,CGsGraphics *param_1,int param_2,CCLProjection *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  CCLProjection *local_58;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  bbtagPoint2D local_30;
  int local_2c;
  
  local_58 = param_3;
  if (param_3 == (CCLProjection *)0x0) {
    local_58 = (CCLProjection *)(**(int **)(DAT_000a6188 + 0xa607e + DAT_000a618c) + 4);
  }
  piVar7 = (int *)(this + 0x194);
  iVar8 = 0;
  do {
    GetDefensePos3D((int)&local_48);
    local_3c = *piVar7 + local_48;
    iVar6 = 0;
    local_38 = piVar7[1] + local_44;
    local_34 = piVar7[2] + local_40;
    CCLProjection::TransformPoint(local_58,&local_30,(CL_Point3 *)&local_3c);
    iVar5 = 2;
    do {
      if (param_2 != -1 && param_2 != iVar8) {
        uVar1 = MC_grpGetPixelFromRGB(iVar6,iVar6,iVar6);
      }
      else {
        uVar1 = MC_grpGetPixelFromRGB(0xff,iVar6,0);
      }
      iVar4 = iVar5 << 1;
      iVar2 = local_30 - iVar5;
      iVar3 = local_2c - iVar5;
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x7f;
      CLGrp::DrawEllipse(param_1,iVar2,iVar3,iVar4,iVar4,uVar1);
    } while (iVar5 != 5);
    if (param_2 != -1 && param_2 != iVar8) {
      uVar1 = MC_grpGetPixelFromRGB(0,0,0);
    }
    else {
      uVar1 = MC_grpGetPixelFromRGB(0,0x40,0xff);
    }
    iVar8 = iVar8 + 1;
    CLGrp::DrawFillEllipse(param_1,local_30 - 1,local_2c + -1,2,2,uVar1);
    piVar7 = piVar7 + 3;
  } while (iVar8 != 6);
  return;
}


