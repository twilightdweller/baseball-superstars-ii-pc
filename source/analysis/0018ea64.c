/* CBBGResMgr::~CBBGResMgr at 0018ea64; decompiler output, not buildable source */

/* CBBGResMgr::~CBBGResMgr() */

CBBGResMgr * __thiscall CBBGResMgr::~CBBGResMgr(CBBGResMgr *this)

{
  int iVar1;
  
  iVar1 = DAT_0018eaa0 + 0x18ea70;
  *(int *)this = *(int *)(iVar1 + DAT_0018eaa4) + 8;
  ReleaseAll();
  CGsArray<BBG_RES_ID>::~CGsArray((CGsArray<BBG_RES_ID> *)(this + 0x14c));
  CGsArray<CGxChangePaletteWRT*>::~CGsArray((CGsArray<CGxChangePaletteWRT*> *)(this + 0x13c));
  *(int *)this = *(int *)(iVar1 + DAT_0018eaa8) + 8;
  **(undefined4 **)(iVar1 + DAT_0018eaac) = 0;
  return this;
}


