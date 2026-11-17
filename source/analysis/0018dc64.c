/* CBBGResMgr::GetStrMax at 0018dc64; decompiler output, not buildable source */

/* CBBGResMgr::GetStrMax(BBG_RES_ID) */

void __thiscall CBBGResMgr::GetStrMax(CBBGResMgr *this,BBG_RES_ID param_1)

{
  GetGVXString(this,param_1);
  GVXLString::GetMax();
  return;
}


