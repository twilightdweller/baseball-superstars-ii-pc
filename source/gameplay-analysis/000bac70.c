/* CCLGame::DrawPitchingBall; research only, not buildable source */

/* CCLGame::DrawPitchingBall(CGsGraphics&) */

void CCLGame::DrawPitchingBall(CGsGraphics *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  CGxPZxAni *pCVar5;
  int iVar6;
  
  iVar6 = DAT_000baeb8 + 0xbac82;
  if (((*(int *)(param_1 + 0x88) != 0) && (0 < *(int *)(param_1 + 0x8c))) &&
     (param_1[0xdc] != (CGsGraphics)0x0)) {
    piVar2 = (int *)CCLPitch::GetBallTransform((CCLPitch *)(param_1 + 4),*(int *)(param_1 + 0xd4));
    iVar3 = CLUtil::GetBallImageFrameIndex((CL_MovableTransformInfo *)piVar2,0xb,DAT_000baebc,false)
    ;
    iVar4 = CLUtil::GetBallImageFrameIndex((CL_MovableTransformInfo *)piVar2,0xb,DAT_000baebc,true);
    iVar1 = DAT_000baec0;
    pCVar5 = (CGxPZxAni *)CBBGResMgr::GetAni(**(CBBGResMgr ***)(iVar6 + DAT_000baec0),0,iVar4);
    CGxPZxAni::Draw(pCVar5,piVar2[4] + 0x20000 >> 0x12,piVar2[5] + 0x20000 >> 0x12,0xb,0,0);
    if (*(uint *)(param_1 + DAT_000baec4) < 0xc) {
                    /* WARNING: Could not emulate address calculation at 0x000bad22 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(*(int *)(iVar6 + DAT_000baec8 + *(uint *)(param_1 + DAT_000baec4) * 4) +
                iVar6 + DAT_000baec8))();
      return;
    }
    pCVar5 = (CGxPZxAni *)CBBGResMgr::GetAni(**(CBBGResMgr ***)(iVar6 + iVar1),0,iVar3);
    CGxPZxAni::Draw(pCVar5,*piVar2 + 0x20000 >> 0x12,piVar2[1] + 0x20000 >> 0x12,0,0,0);
  }
  return;
}


