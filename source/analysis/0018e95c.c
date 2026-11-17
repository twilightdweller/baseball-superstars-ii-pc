/* CBBGResMgr::ReleaseAll at 0018e95c; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGResMgr::ReleaseAll() */

void CBBGResMgr::ReleaseAll(void)

{
  CBBGResMgr *in_r0;
  int iVar1;
  CGxChangePaletteWRT *this;
  BBG_RES_ID BVar2;
  BBG_RES_ID BVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(in_r0 + 0x154);
  iVar6 = DAT_0018e9fc + 0x18e976;
  if (0 < iVar1) {
    iVar5 = 0;
    do {
      CGxChangePaletteWRT::Delete();
      this = *(CGxChangePaletteWRT **)(*(int *)(in_r0 + 0x140) + iVar5 * 4);
      if (this != (CGxChangePaletteWRT *)0x0) {
        CGxChangePaletteWRT::~CGxChangePaletteWRT(this);
        operator_delete(this);
        *(undefined4 *)(*(int *)(in_r0 + 0x140) + iVar5 * 4) = 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  iVar1 = DAT_0018ea00;
  *(undefined4 *)(in_r0 + 0x144) = 0;
  *(undefined4 *)(in_r0 + 0x154) = 0;
  piVar4 = (int *)(iVar1 + iVar6);
  BVar2 = 0;
  do {
    while (*piVar4 == 3) {
      BVar3 = BVar2 + 1;
      ReleaseXls(in_r0,BVar2);
      piVar4 = piVar4 + 1;
      BVar2 = BVar3;
      if (BVar3 == 0x3d) {
        return;
      }
    }
    BVar3 = BVar2 + 1;
    Release(in_r0,BVar2);
    piVar4 = piVar4 + 1;
    BVar2 = BVar3;
  } while (BVar3 != 0x3d);
  return;
}


