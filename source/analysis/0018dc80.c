/* CBBGResMgr::GetStr at 0018dc80; decompiler output, not buildable source */

/* CBBGResMgr::GetStr(BBG_RES_ID, int) */

void __thiscall CBBGResMgr::GetStr(CBBGResMgr *this,BBG_RES_ID param_1,int param_2)

{
  GVXLString *this_00;
  
  this_00 = (GVXLString *)GetGVXString(this,param_1);
  GVXLString::GetStr(this_00,param_2);
  return;
}


