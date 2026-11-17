/* CLMath::xAtan; research only, not buildable source */

/* CLMath::xAtan(long) */

int CLMath::xAtan(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == -0x80000000) {
    iVar3 = xAtan(0,DAT_000cb1d0);
  }
  else {
    iVar2 = 0x2d0;
    iVar5 = 0;
    iVar3 = 0x168;
    do {
      iVar4 = iVar3;
      iVar1 = iVar4;
      iVar3 = iVar5;
      if (*(int *)(DAT_000cb1c8 + DAT_000cb1cc + iVar4 * 4 + 0xcb1ac) <=
          (param_1 + (param_1 >> 0x1f) ^ param_1 >> 0x1f)) {
        iVar1 = iVar2;
        iVar5 = iVar4;
        iVar3 = iVar2;
      }
      iVar2 = iVar1;
      iVar3 = iVar4 + iVar3 >> 1;
    } while (iVar3 != iVar4);
    iVar3 = ((uint)(iVar4 << 0x12) >> 0xe) * 0x800;
  }
  return iVar3;
}


