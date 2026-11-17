/* CBBGResMgr::GetPZDMgr at 0018db20; decompiler output, not buildable source */

/* CBBGResMgr::GetPZDMgr(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GetPZDMgr(CBBGResMgr *this,BBG_RES_ID param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(uint *)(param_1 * 4 + DAT_0018db40 + 0x18db2a + DAT_0018db44) < 3) {
    uVar1 = *(undefined4 *)(*(int *)(this + (param_1 + 2) * 4) + 8);
  }
  return uVar1;
}


