/* CCLFigureMgr::~CCLFigureMgr; research only, not buildable source */

/* CCLFigureMgr::~CCLFigureMgr() */

CCLFigureMgr * __thiscall CCLFigureMgr::~CCLFigureMgr(CCLFigureMgr *this)

{
  int iVar1;
  
  iVar1 = DAT_000a636c + 0xa6340;
  *(int *)this = *(int *)(iVar1 + DAT_000a6370) + 8;
  if (*(int *)(this + 0x154) != 0) {
    MC_knlFree();
  }
  *(undefined4 *)(this + 0x154) = 0;
  *(int *)this = *(int *)(iVar1 + DAT_000a6374) + 8;
  **(undefined4 **)(iVar1 + DAT_000a6378) = 0;
  return this;
}


