/* CBBGResMgr::GetFrame at 0018db6c; decompiler output, not buildable source */

/* CBBGResMgr::GetFrame(BBG_RES_ID, int) */

undefined4 __thiscall CBBGResMgr::GetFrame(CBBGResMgr *this,BBG_RES_ID param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetPZxMgr(this,param_1);
  uVar2 = 0;
  if (*(int *)(iVar1 + 0xc) != 0) {
    uVar2 = *(undefined4 *)(param_2 * 4 + *(int *)(*(int *)(iVar1 + 0xc) + 8));
  }
  return uVar2;
}


