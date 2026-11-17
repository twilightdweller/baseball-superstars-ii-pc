/* CCLGame::CheckBattingBallPosition; research only, not buildable source */

/* CCLGame::CheckBattingBallPosition(int) */

undefined4 __thiscall CCLGame::CheckBattingBallPosition(CCLGame *this,int param_1)

{
  undefined4 uVar1;
  
  if (((DAT_000ba8dc < *(uint *)(this + DAT_000ba8d8 + -4)) ||
      (DAT_000ba8dc - 0xa0 < *(uint *)(this + DAT_000ba8d8))) && (3 < *(int *)(this + DAT_000ba8e0))
     ) {
    uVar1 = 1;
    if (*(int *)(this + DAT_000ba8e4) < param_1) {
      *(int *)(this + DAT_000ba8e4) = *(int *)(this + DAT_000ba8e4) + 1;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


