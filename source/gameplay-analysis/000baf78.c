/* CCLGame::~CCLGame; research only, not buildable source */

/* CCLGame::~CCLGame() */

CCLGame * __thiscall CCLGame::~CCLGame(CCLGame *this)

{
  int iVar1;
  
  iVar1 = DAT_000bafa8 + 0xbaf84;
  *(int *)this = *(int *)(iVar1 + DAT_000bafac) + 8;
  CCLBallMovable::~CCLBallMovable((CCLBallMovable *)(this + 0xe8));
  CCLPitch::~CCLPitch((CCLPitch *)(this + 4));
  *(int *)this = *(int *)(iVar1 + DAT_000bafb0) + 8;
  **(undefined4 **)(iVar1 + DAT_000bafb4) = 0;
  return this;
}


