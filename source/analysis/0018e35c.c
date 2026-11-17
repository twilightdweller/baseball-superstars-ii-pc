/* CBBGResMgr::AddLoadRes at 0018e35c; decompiler output, not buildable source */

/* CBBGResMgr::AddLoadRes(BBG_RES_ID) */

void __thiscall CBBGResMgr::AddLoadRes(CBBGResMgr *this,BBG_RES_ID param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((*(int *)(this + (param_1 + 2) * 4) == 0) &&
     (uVar1 = *(uint *)(param_1 * 4 + DAT_0018e3a0 + 0x18e36a + DAT_0018e3a4), uVar1 < 5)) {
    iVar2 = DAT_0018e3a0 + 0x18e36a + DAT_0018e3a8;
                    /* WARNING: Could not emulate address calculation at 0x0018e380 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar2 + uVar1 * 4) + iVar2))();
    return;
  }
  return;
}


