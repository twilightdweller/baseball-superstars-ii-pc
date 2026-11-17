/* CCLGame::Draw; research only, not buildable source */

/* CCLGame::Draw(CGsGraphics&, int) */

void __thiscall CCLGame::Draw(CCLGame *this,CGsGraphics *param_1,int param_2)

{
  int iVar1;
  CCLFigureMgr **ppCVar2;
  
  iVar1 = DAT_000baf3c + 0xbaed8;
  if (param_2 == 0) {
    if (this[DAT_000baf40] != (CCLGame)0x0) {
      ppCVar2 = *(CCLFigureMgr ***)(iVar1 + DAT_000baf44);
      CCLFigureMgr::DrawFloor(*ppCVar2,param_1,(CCLProjection *)0x0);
      CCLFigureMgr::DrawFoulLine(*ppCVar2,param_1,(CCLProjection *)0x0);
      CCLFigureMgr::DrawPitchStartPos(*ppCVar2,param_1,-1,(CCLProjection *)0x0);
    }
  }
  else if ((param_2 == 1) &&
          (DrawPitchingBall((CGsGraphics *)this), this[DAT_000baf40] != (CCLGame)0x0)) {
    ppCVar2 = *(CCLFigureMgr ***)(iVar1 + DAT_000baf44);
    CCLFigureMgr::DrawStrikeZone(*ppCVar2,param_1,(CCLProjection *)0x0);
    CCLFigureMgr::DrawOrg(*ppCVar2,param_1,*(int *)(**(int **)(iVar1 + DAT_000baf48) + 0x16c));
  }
  return;
}


