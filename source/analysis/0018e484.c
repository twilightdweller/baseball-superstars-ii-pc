/* CBBGResMgr::ReserveLoadRes at 0018e484; decompiler output, not buildable source */

/* CBBGResMgr::ReserveLoadRes(BBG_RES_ID*, int) */

void __thiscall CBBGResMgr::ReserveLoadRes(CBBGResMgr *this,BBG_RES_ID *param_1,int param_2)

{
  BBG_RES_ID BVar1;
  int iVar2;
  
  memset(this + 0xfc,0,0x3d);
  if (0 < param_2) {
    iVar2 = 0;
    do {
      BVar1 = *param_1;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      this[BVar1 + 0xfc] = (CBBGResMgr)0x1;
    } while (iVar2 != param_2);
  }
  return;
}


