/* CCLGame::DrawBattingBall; research only, not buildable source */

/* CCLGame::DrawBattingBall(CGsGraphics&, bool, int) */

void CCLGame::DrawBattingBall(CGsGraphics *param_1,bool param_2,int param_3)

{
  CCLBallMovable::Draw((CCLBallMovable *)(param_1 + 0xe8),(CGsGraphics *)(uint)param_2);
  if (param_3 != 0) {
    CCLDefenseDraw::SetBallTailParticle((CCLBallMovable *)(param_1 + 0xe8));
    CCLDefenseDraw::PlayBallTailParticle();
  }
  return;
}


