/* CBBGResMgr::GexWholePal at 0018dc04; decompiler output, not buildable source */

/* CBBGResMgr::GexWholePal(BBG_RES_ID) */

undefined4 __thiscall CBBGResMgr::GexWholePal(CBBGResMgr *this,BBG_RES_ID param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 * 4 + DAT_0018dc38 + 0x18dc10 + DAT_0018dc3c);
  if (((iVar2 == 2) || (iVar2 == 4)) && (iVar2 = GetPzxPalIndex(this,param_1), iVar2 != -1)) {
    uVar1 = *(undefined4 *)(iVar2 * 4 + *(int *)(this + 0x140));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


