/* CCLFigureMgr::DrawOrg; research only, not buildable source */

/* CCLFigureMgr::DrawOrg(CGsGraphics&, int) */

void __thiscall CCLFigureMgr::DrawOrg(CCLFigureMgr *this,CGsGraphics *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + param_2 * 0x24 + 0x3c);
  iVar2 = *(int *)(this + param_2 * 0x24 + 0x38);
  uVar1 = MC_grpGetPixelFromRGB(0,0xff,0xff);
  CLGrp::DrawLine(param_1,0,iVar3,0x1e0,iVar3,uVar1);
  uVar1 = MC_grpGetPixelFromRGB(0,0xff,0xff);
  CLGrp::DrawLine(param_1,iVar2,0,iVar2,0x140,uVar1);
  return;
}


