/* CCLFigureMgr::CCLFigureMgr; research only, not buildable source */

/* CCLFigureMgr::CCLFigureMgr() */

CCLFigureMgr * __thiscall CCLFigureMgr::CCLFigureMgr(CCLFigureMgr *this)

{
  int iVar1;
  
  iVar1 = DAT_000a64bc + 0xa645c;
  **(CCLFigureMgr ***)(iVar1 + DAT_000a64c0) = this;
  iVar1 = *(int *)(iVar1 + DAT_000a64c4);
  this[0x334] = (CCLFigureMgr)0x0;
  *(int *)this = iVar1 + 8;
  *(undefined4 *)(this + 0x340) = 300;
  *(undefined4 *)(this + 0x344) = 0x11;
  *(undefined4 *)(this + 0x348) = 0xffffffec;
  *(undefined4 *)(this + 0x34c) = 0xffffffff;
  memset(this + 4,0,0x328);
  *(undefined4 *)(this + 0x32c) = 0;
  *(undefined4 *)(this + 0x330) = 0;
  *(undefined4 *)(this + 0x338) = 0;
  *(undefined4 *)(this + 0x33c) = 0;
  return this;
}


