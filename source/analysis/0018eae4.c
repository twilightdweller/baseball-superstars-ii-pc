/* CBBGResMgr::ReleaseImgText at 0018eae4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGResMgr::ReleaseImgText() */

void CBBGResMgr::ReleaseImgText(void)

{
  int in_r0;
  CGxChangePaletteWRT *this;
  
  this = *(CGxChangePaletteWRT **)(in_r0 + 0x164);
  if (this != (CGxChangePaletteWRT *)0x0) {
    CGxChangePaletteWRT::~CGxChangePaletteWRT(this);
    operator_delete(this);
    *(undefined4 *)(in_r0 + 0x164) = 0;
  }
  if (*(int **)(in_r0 + 0x160) != (int *)0x0) {
    (**(code **)(**(int **)(in_r0 + 0x160) + 4))();
    *(undefined4 *)(in_r0 + 0x160) = 0;
  }
  return;
}


