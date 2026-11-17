/* CBBGResMgr::GetStrSize at 0018dc70; decompiler output, not buildable source */

/* CBBGResMgr::GetStrSize(BBG_RES_ID, int) */

void __thiscall CBBGResMgr::GetStrSize(CBBGResMgr *this,BBG_RES_ID param_1,int param_2)

{
  GVXLString *this_00;
  
  this_00 = (GVXLString *)GetGVXString(this,param_1);
  GVXLString::GetLength(this_00,param_2);
  return;
}


