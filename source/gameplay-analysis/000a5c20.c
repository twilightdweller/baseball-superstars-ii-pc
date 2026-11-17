/* CCLFigureMgr::GetDefensePos2D; research only, not buildable source */

/* CCLFigureMgr::GetDefensePos2D(int) */

void CCLFigureMgr::GetDefensePos2D(int param_1)

{
  int in_r1;
  uint in_r2;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (in_r2 < 0x11) {
    if ((*(int *)(in_r1 + 0x34c) == -1) || (6 < in_r2 - 2)) {
      iVar1 = in_r2 + 0x15;
    }
    else {
      iVar1 = *(int *)(in_r1 + 0x34c) * 9 + in_r2 + 0x50;
    }
    iVar1 = in_r1 + iVar1 * 8;
    iVar3 = *(int *)(iVar1 + 8);
    *(int *)param_1 = *(int *)(iVar1 + 4) + *(int *)(in_r1 + 0x32c);
    *(int *)(param_1 + 4) = iVar3 + *(int *)(in_r1 + 0x330);
  }
  else {
    puVar2 = *(undefined4 **)(DAT_000a5c74 + 0xa5c28 + DAT_000a5c78);
    *(undefined4 *)param_1 = *puVar2;
    *(undefined4 *)(param_1 + 4) = puVar2[1];
  }
  return;
}


