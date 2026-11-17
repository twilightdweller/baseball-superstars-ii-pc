/* CCLFigureMgr::~CCLFigureMgr; research only, not buildable source */

/* CCLFigureMgr::~CCLFigureMgr() */

CCLFigureMgr * __thiscall CCLFigureMgr::~CCLFigureMgr(CCLFigureMgr *this)

{
  ~CCLFigureMgr(this);
  operator_delete(this);
  return this;
}


