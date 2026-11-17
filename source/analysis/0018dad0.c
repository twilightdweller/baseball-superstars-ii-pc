/* CBBGResMgr::GetPZAMgr at 0018dad0; decompiler output, not buildable source */

/* CBBGResMgr::GetPZAMgr(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GetPZAMgr(CBBGResMgr *this,BBG_RES_ID param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(uint *)(param_1 * 4 + DAT_0018daf0 + 0x18dada + DAT_0018daf4) < 3) {
    uVar1 = *(undefined4 *)(*(int *)(this + (param_1 + 2) * 4) + 0x10);
  }
  return uVar1;
}


