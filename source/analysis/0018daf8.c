/* CBBGResMgr::GetPZFMgr at 0018daf8; decompiler output, not buildable source */

/* CBBGResMgr::GetPZFMgr(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GetPZFMgr(CBBGResMgr *this,BBG_RES_ID param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(uint *)(param_1 * 4 + DAT_0018db18 + 0x18db02 + DAT_0018db1c) < 3) {
    uVar1 = *(undefined4 *)(*(int *)(this + (param_1 + 2) * 4) + 0xc);
  }
  return uVar1;
}


