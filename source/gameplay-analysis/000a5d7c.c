/* CCLFigureMgr::GetDefenderPos3DBackward; research only, not buildable source */

/* CCLFigureMgr::GetDefenderPos3DBackward(int) */

int CCLFigureMgr::GetDefenderPos3DBackward(int param_1)

{
  undefined4 *puVar1;
  uint in_r2;
  
  if (in_r2 < 9) {
    ToVirtual(param_1);
  }
  else {
    puVar1 = *(undefined4 **)(DAT_000a5db4 + 0xa5d86 + DAT_000a5db8);
    *(undefined4 *)param_1 = *puVar1;
    *(undefined4 *)(param_1 + 4) = puVar1[1];
    *(undefined4 *)(param_1 + 8) = puVar1[2];
  }
  return param_1;
}


