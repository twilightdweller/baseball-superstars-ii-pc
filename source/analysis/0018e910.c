/* CBBGResMgr::LoadResReserved at 0018e910; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGResMgr::LoadResReserved() */

void CBBGResMgr::LoadResReserved(void)

{
  CBBGResMgr *in_r0;
  BBG_RES_ID BVar1;
  BBG_RES_ID BVar2;
  
  BVar2 = 0;
  do {
    while (in_r0[BVar2 + 0xfc] != (CBBGResMgr)0x0) {
      BVar2 = BVar2 + 1;
      if (BVar2 == 0x3d) goto LAB_0018e936;
    }
    BVar1 = BVar2 + 1;
    Release(in_r0,BVar2);
    BVar2 = BVar1;
  } while (BVar1 != 0x3d);
LAB_0018e936:
  BVar2 = 0;
  do {
    while (in_r0[BVar2 + 0xfc] != (CBBGResMgr)0x0) {
      BVar1 = BVar2 + 1;
      AddLoadRes(in_r0,BVar2);
      BVar2 = BVar1;
      if (BVar1 == 0x3d) {
        return;
      }
    }
    BVar2 = BVar2 + 1;
  } while (BVar2 != 0x3d);
  return;
}


