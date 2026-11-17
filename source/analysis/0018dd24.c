/* CBBGResMgr::GetGameCodeStr at 0018dd24; decompiler output, not buildable source */

/* CBBGResMgr::GetGameCodeStr(int) */

void __thiscall CBBGResMgr::GetGameCodeStr(CBBGResMgr *this,int param_1)

{
  int iVar1;
  
  iVar1 = CBBGDataMgr::GetOption();
  if (*(int *)(iVar1 + 0x48) == 1) {
    GVXLString::GetStr(*(GVXLString **)(this + 0x16c),param_1);
  }
  else {
    GVXLString::GetStr(*(GVXLString **)(this + 0x170),param_1);
  }
  return;
}


