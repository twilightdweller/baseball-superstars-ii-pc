/* CCLGame::CCLGame; research only, not buildable source */

/* CCLGame::CCLGame() */

CCLGame * __thiscall CCLGame::CCLGame(CCLGame *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_000bb068 + 0xbb018;
  **(CCLGame ***)(iVar2 + DAT_000bb06c) = this;
  *(int *)this = *(int *)(iVar2 + DAT_000bb070) + 8;
  CCLPitch::CCLPitch((CCLPitch *)(this + 4));
  this[0xdc] = (CCLGame)0x0;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = 0xffffffff;
  CCLBallMovable::CCLBallMovable((CCLBallMovable *)(this + 0xe8));
  iVar1 = DAT_000bb074;
  this[DAT_000bb074] = (CCLGame)0x0;
  *(undefined4 *)(this + iVar1 + 4) = 0xffffffff;
  *(undefined4 *)(this + iVar1 + 0x10) = 0;
  this[iVar1 + 0x14] = (CCLGame)0x0;
  *(int *)(this + 0xd0) = **(int **)(iVar2 + DAT_000bb078) + 4;
  this[DAT_000bb07c] = (CCLGame)0x1;
  return this;
}


