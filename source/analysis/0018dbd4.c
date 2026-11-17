/* CBBGResMgr::GetPzxPalIndex at 0018dbd4; decompiler output, not buildable source */

/* CBBGResMgr::GetPzxPalIndex(BBG_RES_ID) */

int __thiscall CBBGResMgr::GetPzxPalIndex(CBBGResMgr *this,BBG_RES_ID param_1)

{
  int iVar1;
  BBG_RES_ID BVar2;
  
  if (*(int *)(this + 0x154) < 1) {
LAB_0018dbfe:
    iVar1 = -1;
  }
  else {
    iVar1 = 0;
    BVar2 = **(BBG_RES_ID **)(this + 0x150);
    while (BVar2 != param_1) {
      iVar1 = iVar1 + 1;
      if (*(int *)(this + 0x154) <= iVar1) goto LAB_0018dbfe;
      BVar2 = (*(BBG_RES_ID **)(this + 0x150))[iVar1];
    }
  }
  return iVar1;
}


