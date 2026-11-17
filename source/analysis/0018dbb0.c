/* CBBGResMgr::GetGVXString at 0018dbb0; decompiler output, not buildable source */

/* CBBGResMgr::GetGVXString(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GetGVXString(CBBGResMgr *this,BBG_RES_ID param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 * 4 + DAT_0018dbcc + 0x18dbba + DAT_0018dbd0) == 3) {
    uVar1 = *(undefined4 *)(this + (param_1 + 2) * 4);
  }
  return uVar1;
}


