/* CCLFigureMgr::DrawMagicPitchStartPos; research only, not buildable source */

/* CCLFigureMgr::DrawMagicPitchStartPos(CGsGraphics&, int, CCLProjection*) */

void __thiscall
CCLFigureMgr::DrawMagicPitchStartPos
          (CCLFigureMgr *this,CGsGraphics *param_1,int param_2,CCLProjection *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  bbtagPoint2D local_28;
  int local_24;
  
  if (param_3 == (CCLProjection *)0x0) {
    param_3 = (CCLProjection *)(**(int **)(DAT_000a605c + 0xa5f88 + DAT_000a6064) + 4);
  }
  if ((uint)param_2 < 5) {
    GetDefensePos3D((int)&local_40);
    local_34 = *(int *)(this + param_2 * 0xc + 0x238) + local_40;
    local_30 = *(int *)(this + param_2 * 0xc + 0x23c) + local_3c;
    local_2c = *(int *)(this + param_2 * 0xc + 0x240) + local_38;
  }
  else {
    piVar2 = *(int **)(DAT_000a605c + 0xa5f88 + DAT_000a6060);
    local_34 = *piVar2;
    local_30 = piVar2[1];
    local_2c = piVar2[2];
  }
  CCLProjection::TransformPoint(param_3,&local_28,(CL_Point3 *)&local_34);
  iVar6 = 0;
  iVar5 = 2;
  do {
    iVar3 = local_28 - iVar5;
    iVar7 = iVar5 * 2;
    iVar4 = local_24 - iVar5;
    uVar1 = MC_grpGetPixelFromRGB(0xff,iVar6,0);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x7f;
    CLGrp::DrawEllipse(param_1,iVar3,iVar4,iVar7,iVar7,uVar1);
  } while (iVar5 != 5);
  uVar1 = MC_grpGetPixelFromRGB(0,0x40,0xff);
  CLGrp::DrawFillEllipse(param_1,local_28 - 1,local_24 + -1,2,2,uVar1);
  return;
}


