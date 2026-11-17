/* handleCletEvent at 0019b514; decompiler output, not buildable source */

void handleCletEvent(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = DAT_0019b590 + 0x19b520;
  if (param_1 == DAT_0019b594) {
    if (param_3 != (undefined4 *)0x0) {
      GcxCallbackDo((TGXCALLBACK *)param_3);
    }
  }
  else if (param_1 - 0x17U < 3) {
    piVar2 = *(int **)(iVar3 + DAT_0019b59c);
    *(int *)(*piVar2 + 8) = param_1;
    *(undefined4 *)*piVar2 = param_3[1];
    *(undefined4 *)(*piVar2 + 4) = param_3[2];
    *(undefined4 *)(*piVar2 + 0xc) = *param_3;
    (**(code **)**(undefined4 **)(iVar3 + DAT_0019b598))
              (*(undefined4 **)(iVar3 + DAT_0019b598),param_1,*piVar2,0,param_4);
  }
  else {
    puVar1 = *(undefined4 **)(iVar3 + DAT_0019b598);
    if ((puVar1 != (undefined4 *)0x0) &&
       ((**(code **)*puVar1)(puVar1,param_1,param_2,param_3), param_1 == 2)) {
      GxSendEvent(0xa100,param_2,param_3);
    }
  }
  return;
}


