/* CBBGMenuRun::ArrayRotate at 00167804; decompiler output, not buildable source */

/* CBBGMenuRun::ArrayRotate(signed char*, int, int) */

void __thiscall CBBGMenuRun::ArrayRotate(CBBGMenuRun *this,signed *param_1,int param_2,int param_3)

{
  undefined uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  char *pcVar7;
  bool bVar8;
  
  if ((param_2 < 1) || (iVar6 = 0, *(char *)param_1 != -1)) {
LAB_00167814:
    iVar6 = 0;
  }
  else {
    do {
      iVar6 = iVar6 + 1;
      if (param_2 <= iVar6) goto LAB_00167814;
    } while (*(char *)((int)param_1 + iVar6) == -1);
  }
  iVar3 = param_2 + -1;
  iVar4 = param_2;
  if ((-1 < iVar3) && (iVar4 = iVar3, *(char *)((int)param_1 + iVar3) == -1)) {
    pcVar7 = (char *)((int)param_1 + param_2 + -2);
    do {
      bVar8 = iVar3 == 0;
      iVar3 = iVar3 + -1;
      iVar4 = param_2;
      if (bVar8) break;
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + -1;
      iVar4 = iVar3;
    } while (cVar2 == -1);
  }
  if ((param_3 == -3) || (param_3 == -1)) {
    uVar1 = *(undefined *)((int)param_1 + iVar4);
    if (iVar6 <= iVar4) {
      puVar5 = (undefined *)((int)param_1 + iVar4 + -1);
      do {
        iVar4 = iVar4 + -1;
        puVar5[1] = *puVar5;
        puVar5 = puVar5 + -1;
      } while (iVar6 <= iVar4);
    }
    *(undefined *)((int)param_1 + iVar6) = uVar1;
  }
  else if ((param_3 == -4) || (param_3 == -2)) {
    puVar5 = (undefined *)((int)param_1 + iVar6);
    uVar1 = *puVar5;
    for (; iVar6 < iVar4; iVar6 = iVar6 + 1) {
      *puVar5 = puVar5[1];
      puVar5 = puVar5 + 1;
    }
    *(undefined *)((int)param_1 + iVar4) = uVar1;
  }
  return;
}


