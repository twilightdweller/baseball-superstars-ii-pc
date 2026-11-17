/* CCLGame::~CCLGame; research only, not buildable source */

/* CCLGame::~CCLGame() */

CCLGame * __thiscall CCLGame::~CCLGame(CCLGame *this)

{
  int iVar1;
  
  iVar1 = DAT_000baffc + 0xbafd8;
  *(int *)this = *(int *)(iVar1 + DAT_000bb000) + 8;
  CCLBallMovable::~CCLBallMovable((CCLBallMovable *)(this + 0xe8));
  CCLPitch::~CCLPitch((CCLPitch *)(this + 4));
  *(int *)this = *(int *)(iVar1 + DAT_000bb004) + 8;
  **(undefined4 **)(iVar1 + DAT_000bb008) = 0;
  return this;
}


