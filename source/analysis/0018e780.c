/* CBBGResMgr::ReleaseXls at 0018e780; decompiler output, not buildable source */

/* CBBGResMgr::ReleaseXls(BBG_RES_ID) */

void __thiscall CBBGResMgr::ReleaseXls(CBBGResMgr *this,BBG_RES_ID param_1)

{
  GVXLString *this_00;
  
  this_00 = *(GVXLString **)(this + (param_1 + 2) * 4);
  if (this_00 != (GVXLString *)0x0) {
    GVXLString::~GVXLString(this_00);
    operator_delete(this_00);
  }
  *(undefined4 *)(this + (param_1 + 2) * 4) = 0;
  this[param_1 + 0xfc] = (CBBGResMgr)0x0;
  return;
}


