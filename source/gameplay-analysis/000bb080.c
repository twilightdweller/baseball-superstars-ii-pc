/* CCLGame::CCLGame; research only, not buildable source */

/* CCLGame::CCLGame() */

CCLGame * __thiscall CCLGame::CCLGame(CCLGame *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_000bb0dc + 0xbb08c;
  **(CCLGame ***)(iVar2 + DAT_000bb0e0) = this;
  *(int *)this = *(int *)(iVar2 + DAT_000bb0e4) + 8;
  CCLPitch::CCLPitch((CCLPitch *)(this + 4));
  this[0xdc] = (CCLGame)0x0;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = 0xffffffff;
  CCLBallMovable::CCLBallMovable((CCLBallMovable *)(this + 0xe8));
  iVar1 = DAT_000bb0e8;
  this[DAT_000bb0e8] = (CCLGame)0x0;
  *(undefined4 *)(this + iVar1 + 4) = 0xffffffff;
  *(undefined4 *)(this + iVar1 + 0x10) = 0;
  this[iVar1 + 0x14] = (CCLGame)0x0;
  *(int *)(this + 0xd0) = **(int **)(iVar2 + DAT_000bb0ec) + 4;
  this[DAT_000bb0f0] = (CCLGame)0x1;
  return this;
}


