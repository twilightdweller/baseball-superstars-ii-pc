/* CCLGame::~CCLGame; research only, not buildable source */

/* CCLGame::~CCLGame() */

CCLGame * __thiscall CCLGame::~CCLGame(CCLGame *this)

{
  ~CCLGame(this);
  operator_delete(this);
  return this;
}


