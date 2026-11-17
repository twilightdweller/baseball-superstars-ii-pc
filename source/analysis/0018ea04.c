/* CBBGResMgr::~CBBGResMgr at 0018ea04; decompiler output, not buildable source */

/* CBBGResMgr::~CBBGResMgr() */

CBBGResMgr * __thiscall CBBGResMgr::~CBBGResMgr(CBBGResMgr *this)

{
  int iVar1;
  
  iVar1 = DAT_0018ea40 + 0x18ea10;
  *(int *)this = *(int *)(iVar1 + DAT_0018ea44) + 8;
  ReleaseAll();
  CGsArray<BBG_RES_ID>::~CGsArray((CGsArray<BBG_RES_ID> *)(this + 0x14c));
  CGsArray<CGxChangePaletteWRT*>::~CGsArray((CGsArray<CGxChangePaletteWRT*> *)(this + 0x13c));
  *(int *)this = *(int *)(iVar1 + DAT_0018ea48) + 8;
  **(undefined4 **)(iVar1 + DAT_0018ea4c) = 0;
  return this;
}


