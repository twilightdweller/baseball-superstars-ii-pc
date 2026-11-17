/* CBBGMenuRun::KeyReleased at 0016768c; decompiler output, not buildable source */

/* CBBGMenuRun::KeyReleased(int) */

void __thiscall CBBGMenuRun::KeyReleased(CBBGMenuRun *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_00167720;
  iVar3 = DAT_0016771c + 0x167696;
  if ((**(int **)(iVar3 + DAT_00167720) != 0) &&
     (*(char *)(**(int **)(iVar3 + DAT_00167720) + 8) != '\0')) {
    *(int *)(this + 0x28) = param_1;
  }
  iVar2 = *(int *)(this + 0xc);
  if ((iVar2 != 7) && (iVar2 != 0x13)) {
    if (iVar2 == 0xb) {
      if (*(int *)(this + 8) != 0) goto LAB_001676fc;
    }
    else if ((((iVar2 != 0x1c) && (iVar2 != 0x1d)) && (iVar2 != 0x1e)) && (iVar2 != 0x1f)) {
      if (iVar2 != 0xc) goto LAB_001676fc;
      iVar2 = *(int *)(*(int *)(this + 0x6c) + DAT_00167724);
      if ((iVar2 == 0) ||
         ((iVar2 = *(int *)(iVar2 + 0x10) * *(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0xc),
          iVar2 != 3 && (iVar2 != 4)))) goto LAB_001676fc;
      *(undefined4 *)(*(int *)(this + 0x6c) + 0x480) = 0xffffffff;
      if ((**(int **)(iVar3 + iVar1) != 0) && (*(char *)(**(int **)(iVar3 + iVar1) + 8) != '\0'))
      goto LAB_001676fc;
    }
  }
  *(int *)(this + 0x28) = param_1;
LAB_001676fc:
  if ((*(int *)(**(int **)(iVar3 + DAT_00167728) + 4) == 0) ||
     (*(int *)(**(int **)(iVar3 + DAT_00167728) + 0x10) == 0)) {
    *(int *)(this + 0x2c) = param_1;
  }
  return;
}


