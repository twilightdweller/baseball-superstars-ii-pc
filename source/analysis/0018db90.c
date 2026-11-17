/* CBBGResMgr::GetBitmap at 0018db90; decompiler output, not buildable source */

/* CBBGResMgr::GetBitmap(BBG_RES_ID, int) */

undefined4 __thiscall CBBGResMgr::GetBitmap(CBBGResMgr *this,BBG_RES_ID param_1,int param_2)

{
  int iVar1;
  
  iVar1 = GetPZxMgr(this,param_1);
  return *(undefined4 *)(param_2 * 4 + *(int *)(*(int *)(iVar1 + 8) + 8));
}


