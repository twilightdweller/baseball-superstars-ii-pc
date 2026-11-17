/* CCLSpline::bc_val; research only, not buildable source */

/* CCLSpline::bc_val(int, long, long*, long*, long*, long*) */

void __thiscall
CCLSpline::bc_val(CCLSpline *this,int param_1,long param_2,long *param_3,long *param_4,long *param_5
                 ,long *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  
  iVar4 = DAT_000c2080 + 0xc1fde;
  bp01(this,param_1,param_2);
  *param_5 = 0;
  iVar8 = DAT_000c2084;
  if (param_1 < 0) {
    *param_6 = 0;
  }
  else {
    iVar5 = (param_1 + 1) * 4;
    iVar3 = *(int *)(iVar4 + DAT_000c2084);
    iVar7 = 0;
    iVar6 = 0;
    do {
      iVar2 = *(int *)(iVar3 + iVar6);
      piVar1 = (int *)((int)param_3 + iVar6);
      iVar6 = iVar6 + 4;
      lVar9 = __aeabi_lmul(iVar2,iVar2 >> 0x1f,*piVar1,*piVar1 >> 0x1f);
      lVar9 = lVar9 + CONCAT44(DAT_000c207c,DAT_000c2078);
      iVar7 = iVar7 + ((uint)lVar9 >> 0x12 | (int)((ulonglong)lVar9 >> 0x20) * 0x4000);
      *param_5 = iVar7;
    } while (iVar6 != iVar5);
    *param_6 = 0;
    iVar3 = 0;
    iVar6 = 0;
    iVar8 = *(int *)(iVar4 + iVar8);
    do {
      piVar1 = (int *)((int)param_4 + iVar3);
      iVar4 = *(int *)(iVar8 + iVar3);
      iVar3 = iVar3 + 4;
      lVar9 = __aeabi_lmul(iVar4,iVar4 >> 0x1f,*piVar1,*piVar1 >> 0x1f);
      lVar9 = lVar9 + CONCAT44(DAT_000c207c,DAT_000c2078);
      iVar6 = iVar6 + ((uint)lVar9 >> 0x12 | (int)((ulonglong)lVar9 >> 0x20) * 0x4000);
      *param_6 = iVar6;
    } while (iVar3 != iVar5);
  }
  return;
}


