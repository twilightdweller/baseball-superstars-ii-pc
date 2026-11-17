/* CBBGResMgr::GetBitmaps at 0018dba4; decompiler output, not buildable source */

/* CBBGResMgr::GetBitmaps(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GetBitmaps(CBBGResMgr *this,BBG_RES_ID param_1)

{
  int iVar1;
  
  iVar1 = GetPZDMgr(this,param_1);
  return *(undefined4 *)(iVar1 + 8);
}


