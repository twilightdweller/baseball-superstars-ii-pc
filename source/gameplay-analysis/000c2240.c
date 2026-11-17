/* CCLSpline::Cardinal; research only, not buildable source */

/* CCLSpline::Cardinal(int, tagCLxPoint3*, int, tagCLxPoint3*) */

void __thiscall
CCLSpline::Cardinal(CCLSpline *this,int param_1,tagCLxPoint3 *param_2,int param_3,
                   tagCLxPoint3 *param_4)

{
  int **ppiVar1;
  tagCLxPoint3 tVar2;
  int **ppiVar3;
  int **ppiVar4;
  void *pvVar5;
  int iVar6;
  tagCLxPoint3 *ptVar7;
  int iVar8;
  int *piVar9;
  tagCLxPoint3 *ptVar10;
  int iVar11;
  int iVar12;
  int iStack_38;
  int local_34;
  int local_30;
  int local_2c;
  
  ppiVar3 = (int **)operator_new__(param_1 * 4);
  ppiVar4 = (int **)operator_new__(param_1 * 4);
  if (0 < param_1) {
    iVar8 = 0;
    iVar11 = 0;
    do {
      pvVar5 = operator_new__(8);
      *(void **)((int)ppiVar3 + iVar8) = pvVar5;
      pvVar5 = operator_new__(8);
      iVar11 = iVar11 + 1;
      *(void **)((int)ppiVar4 + iVar8) = pvVar5;
      iVar8 = iVar8 + 4;
    } while (iVar11 < param_1);
    iVar11 = 0;
    iVar8 = 0;
    ptVar7 = param_2;
    do {
      iVar8 = iVar8 + 1;
      *(int *)(*(int *)((int)ppiVar3 + iVar11) + 4) = (int)(*ptVar7 + 0x20000) >> 0x12;
      *(int *)(*(int *)((int)ppiVar4 + iVar11) + 4) = (int)(ptVar7[1] + 0x20000) >> 0x12;
      ptVar10 = ptVar7 + 2;
      piVar9 = *(int **)((int)ppiVar3 + iVar11);
      ptVar7 = ptVar7 + 3;
      ppiVar1 = (int **)((int)ppiVar4 + iVar11);
      iVar6 = (int)(*ptVar10 + 0x20000) >> 0x12;
      iVar11 = iVar11 + 4;
      **ppiVar1 = iVar6;
      *piVar9 = iVar6;
    } while (iVar8 != param_1);
  }
  tVar2 = *param_2;
  *(char *)param_4 = (char)tVar2;
  *(char *)((int)param_4 + 1) = (char)(tVar2 >> 8);
  *(char *)((int)param_4 + 2) = (char)(tVar2 >> 0x10);
  *(char *)((int)param_4 + 3) = (char)(tVar2 >> 0x18);
  tVar2 = param_2[1];
  *(char *)(param_4 + 1) = (char)tVar2;
  *(char *)((int)param_4 + 5) = (char)(tVar2 >> 8);
  *(char *)((int)param_4 + 6) = (char)(tVar2 >> 0x10);
  *(char *)((int)param_4 + 7) = (char)(tVar2 >> 0x18);
  tVar2 = param_2[2];
  *(char *)(param_4 + 2) = (char)tVar2;
  *(char *)((int)param_4 + 9) = (char)(tVar2 >> 8);
  *(char *)((int)param_4 + 0xb) = (char)(tVar2 >> 0x18);
  *(char *)((int)param_4 + 10) = (char)(tVar2 >> 0x10);
  ptVar10 = param_4 + (param_3 + -1) * 3;
  ptVar7 = param_2 + (param_1 + -1) * 3;
  tVar2 = *ptVar7;
  *(char *)ptVar10 = (char)tVar2;
  *(char *)((int)ptVar10 + 1) = (char)(tVar2 >> 8);
  *(char *)((int)ptVar10 + 2) = (char)(tVar2 >> 0x10);
  *(char *)((int)ptVar10 + 3) = (char)(tVar2 >> 0x18);
  tVar2 = ptVar7[1];
  *(char *)(ptVar10 + 1) = (char)tVar2;
  *(char *)((int)ptVar10 + 5) = (char)(tVar2 >> 8);
  *(char *)((int)ptVar10 + 6) = (char)(tVar2 >> 0x10);
  *(char *)((int)ptVar10 + 7) = (char)(tVar2 >> 0x18);
  tVar2 = ptVar7[2];
  *(char *)(ptVar10 + 2) = (char)tVar2;
  *(char *)((int)ptVar10 + 9) = (char)(tVar2 >> 8);
  *(char *)((int)ptVar10 + 0xb) = (char)(tVar2 >> 0x18);
  iVar11 = (param_1 + -1) * 0x28;
  *(char *)((int)ptVar10 + 10) = (char)(tVar2 >> 0x10);
  iVar8 = __aeabi_idiv(iVar11);
  if (0 < iVar11) {
    iVar6 = iVar11 - iVar8;
    iVar12 = 1;
    do {
      CardinalSplines(this,ppiVar3,param_1,iVar11,&local_30,2);
      CardinalSplines(this,ppiVar4,param_1,iVar11,&iStack_38,2);
      *(undefined *)((int)ptVar10 + 9) = 0;
      *(undefined *)(ptVar10 + 2) = 0;
      *(char *)((int)ptVar10 + 10) = (char)((uint)(local_30 << 0x12) >> 0x10);
      *(char *)((int)ptVar10 + 0xb) = (char)((uint)(local_30 << 0x12) >> 0x18);
      *(undefined *)ptVar10 = 0;
      *(undefined *)((int)ptVar10 + 1) = 0;
      *(char *)((int)ptVar10 + 2) = (char)((uint)(local_2c << 0x12) >> 0x10);
      *(char *)((int)ptVar10 + 3) = (char)((uint)(local_2c << 0x12) >> 0x18);
      *(undefined *)((int)ptVar10 + 5) = 0;
      *(undefined *)(ptVar10 + 1) = 0;
      *(char *)((int)ptVar10 + 6) = (char)((uint)(local_34 << 0x12) >> 0x10);
      *(char *)((int)ptVar10 + 7) = (char)((uint)(local_34 << 0x12) >> 0x18);
      iVar12 = iVar12 + 1;
      if (param_3 <= iVar12) break;
      ptVar10 = ptVar10 + -3;
      iVar6 = iVar6 + -iVar8;
      iVar11 = iVar11 + -iVar8;
    } while (0 < iVar8 + iVar6);
  }
  tVar2 = *param_2;
  *(char *)param_4 = (char)tVar2;
  *(char *)((int)param_4 + 1) = (char)(tVar2 >> 8);
  *(char *)((int)param_4 + 2) = (char)(tVar2 >> 0x10);
  *(char *)((int)param_4 + 3) = (char)(tVar2 >> 0x18);
  tVar2 = param_2[1];
  *(char *)(param_4 + 1) = (char)tVar2;
  *(char *)((int)param_4 + 5) = (char)(tVar2 >> 8);
  *(char *)((int)param_4 + 6) = (char)(tVar2 >> 0x10);
  *(char *)((int)param_4 + 7) = (char)(tVar2 >> 0x18);
  tVar2 = param_2[2];
  *(char *)(param_4 + 2) = (char)tVar2;
  *(char *)((int)param_4 + 9) = (char)(tVar2 >> 8);
  *(char *)((int)param_4 + 10) = (char)(tVar2 >> 0x10);
  *(char *)((int)param_4 + 0xb) = (char)(tVar2 >> 0x18);
  if (0 < param_1) {
    iVar8 = 0;
    iVar11 = 0;
    do {
      if (*(void **)((int)ppiVar3 + iVar8) != (void *)0x0) {
        operator_delete__(*(void **)((int)ppiVar3 + iVar8));
      }
      if (*(void **)((int)ppiVar4 + iVar8) != (void *)0x0) {
        operator_delete__(*(void **)((int)ppiVar4 + iVar8));
      }
      iVar11 = iVar11 + 1;
      iVar8 = iVar8 + 4;
    } while (iVar11 < param_1);
  }
  if (ppiVar3 != (int **)0x0) {
    operator_delete__(ppiVar3);
  }
  if (ppiVar4 != (int **)0x0) {
    operator_delete__(ppiVar4);
  }
  return;
}


