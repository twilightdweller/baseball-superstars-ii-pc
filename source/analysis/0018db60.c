/* CBBGResMgr::GetAnis at 0018db60; decompiler output, not buildable source */

/* CBBGResMgr::GetAnis(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GetAnis(CBBGResMgr *this,BBG_RES_ID param_1)

{
  int iVar1;
  
  iVar1 = GetPZAMgr(this,param_1);
  return *(undefined4 *)(iVar1 + 8);
}


