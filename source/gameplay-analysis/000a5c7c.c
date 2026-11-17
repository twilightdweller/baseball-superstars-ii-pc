/* CCLFigureMgr::GetDefensePos3D; research only, not buildable source */

/* CCLFigureMgr::GetDefensePos3D(int) */

int CCLFigureMgr::GetDefensePos3D(int param_1)

{
  int in_r1;
  undefined4 *puVar1;
  uint in_r2;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  if (in_r2 < 0x11) {
    if (*(char *)(in_r1 + 0x334) == '\0') {
      if (in_r2 == 0) {
        ToVirtual((bbtagPoint2D)&local_1c);
        uVar2 = *(undefined4 *)(in_r1 + 0x218);
        *(undefined4 *)param_1 = local_1c;
        *(undefined4 *)(param_1 + 4) = uVar2;
        *(int *)(param_1 + 8) = local_14;
        return param_1;
      }
    }
    else if (in_r2 == 0) {
      ToVirtual((bbtagPoint2D)&local_1c);
      *(undefined4 *)param_1 = local_1c;
      *(undefined4 *)(param_1 + 4) = local_18;
      *(int *)(param_1 + 8) = local_14 + 0xf;
      return param_1;
    }
    ToVirtual(param_1);
  }
  else {
    puVar1 = *(undefined4 **)(DAT_000a5d34 + 0xa5c88 + DAT_000a5d38);
    *(undefined4 *)param_1 = *puVar1;
    *(undefined4 *)(param_1 + 4) = puVar1[1];
    *(undefined4 *)(param_1 + 8) = puVar1[2];
  }
  return param_1;
}


