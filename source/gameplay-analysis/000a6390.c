/* CCLFigureMgr::~CCLFigureMgr; research only, not buildable source */

/* CCLFigureMgr::~CCLFigureMgr() */

CCLFigureMgr * __thiscall CCLFigureMgr::~CCLFigureMgr(CCLFigureMgr *this)

{
  int iVar1;
  
  iVar1 = DAT_000a63c8 + 0xa639c;
  *(int *)this = *(int *)(iVar1 + DAT_000a63cc) + 8;
  if (*(int *)(this + 0x154) != 0) {
    MC_knlFree();
  }
  *(undefined4 *)(this + 0x154) = 0;
  *(int *)this = *(int *)(iVar1 + DAT_000a63d0) + 8;
  **(undefined4 **)(iVar1 + DAT_000a63d4) = 0;
  return this;
}


