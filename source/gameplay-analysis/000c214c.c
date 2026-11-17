/* CCLSpline::CardinalSplines; research only, not buildable source */

/* CCLSpline::CardinalSplines(int**, int, int, int*, int) */

void __thiscall
CCLSpline::CardinalSplines
          (CCLSpline *this,int **param_1,int param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar1 = __aeabi_idiv(param_3,0x28);
  iVar3 = param_2 + -1;
  if (iVar1 < iVar3) {
    piVar4 = param_1[iVar1];
    local_48 = *piVar4;
    local_44 = piVar4[1];
    piVar5 = param_1[iVar1 + 1];
    local_40 = *piVar5;
    local_3c = piVar5[1];
    if (iVar1 < 0x29) {
      local_38 = __aeabi_idiv(*piVar5 - *piVar4,param_5);
      local_34 = __aeabi_idiv(piVar5[1] - piVar4[1],param_5);
    }
    else {
      piVar2 = param_1[iVar1 + -1];
      local_38 = __aeabi_idiv(*piVar5 - *piVar2,param_5);
      local_34 = __aeabi_idiv(piVar5[1] - piVar2[1],param_5);
    }
    if (iVar1 + 1 < iVar3) {
      piVar5 = param_1[iVar1 + 2];
    }
    local_30 = __aeabi_idiv(*piVar5 - *piVar4,param_5);
    local_2c = __aeabi_idiv(piVar5[1] - piVar4[1],param_5);
    HermiteSplines(this,&local_48,iVar1 * -0x28 + param_3,param_4);
  }
  else {
    *param_4 = *param_1[iVar3];
    param_4[1] = param_1[iVar3][1];
  }
  return;
}


