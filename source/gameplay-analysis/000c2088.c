/* CCLSpline::HermiteSplines; research only, not buildable source */

/* CCLSpline::HermiteSplines(int (*) [2], int, int*) */

void __thiscall CCLSpline::HermiteSplines(CCLSpline *this,int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_2 * param_2;
  iVar5 = iVar6 * param_2;
  iVar7 = 0;
  do {
    iVar1 = __aeabi_idiv((iVar5 + iVar6 * -0x50 + param_2 * 0x640) *
                         *(int *)((int)param_1 + iVar7 + 0x10),64000);
    iVar2 = __aeabi_idiv((iVar6 * -0x28 + iVar5) * *(int *)((int)param_1 + iVar7 + 0x18),64000);
    iVar3 = __aeabi_idiv(*(int *)((int)param_1 + iVar7) * (iVar5 + iVar6 * -0x3c + 32000) * 2,64000)
    ;
    iVar4 = __aeabi_idiv((iVar6 * 0x3c - iVar5) * 2 * *(int *)((int)param_1 + iVar7 + 8),64000);
    *(int *)((int)param_3 + iVar7) = iVar4 + iVar1 + iVar2 + iVar3;
    iVar7 = iVar7 + 4;
  } while (iVar7 != 8);
  return;
}


