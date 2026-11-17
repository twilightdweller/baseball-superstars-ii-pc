/* CBBGResMgr::GetPZxMgr at 0018daa0; decompiler output, not buildable source */

/* CBBGResMgr::GetPZxMgr(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GetPZxMgr(CBBGResMgr *this,BBG_RES_ID param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 * 4 + DAT_0018dac8 + 0x18daa8 + DAT_0018dacc);
  if ((uVar2 < 5) && ((1 << (uVar2 & 0xff) & 0x17U) != 0)) {
    uVar1 = *(undefined4 *)(this + (param_1 + 2) * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


