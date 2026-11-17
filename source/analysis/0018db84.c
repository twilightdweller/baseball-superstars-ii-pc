/* CBBGResMgr::GetFrames at 0018db84; decompiler output, not buildable source */

/* CBBGResMgr::GetFrames(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GetFrames(CBBGResMgr *this,BBG_RES_ID param_1)

{
  int iVar1;
  
  iVar1 = GetPZFMgr(this,param_1);
  return *(undefined4 *)(iVar1 + 8);
}


