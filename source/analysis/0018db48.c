/* CBBGResMgr::GetAni at 0018db48; decompiler output, not buildable source */

/* CBBGResMgr::GetAni(BBG_RES_ID, int) */

undefined4 __thiscall CBBGResMgr::GetAni(CBBGResMgr *this,BBG_RES_ID param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetPZxMgr(this,param_1);
  uVar2 = 0;
  if (*(int *)(iVar1 + 0x10) != 0) {
    uVar2 = *(undefined4 *)(param_2 * 4 + *(int *)(*(int *)(iVar1 + 0x10) + 8));
  }
  return uVar2;
}


