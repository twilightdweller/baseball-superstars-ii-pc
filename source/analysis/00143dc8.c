/* CBBStartUp::EvKeyRelease at 00143dc8; decompiler output, not buildable source */

/* CBBStartUp::EvKeyRelease(int) */

void __thiscall CBBStartUp::EvKeyRelease(CBBStartUp *this,int param_1)

{
  CBBGEventMgr *this_00;
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = DAT_00143e40 + 0x143dd2;
  iVar1 = *(int *)(**(int **)(iVar3 + DAT_00143e44) + 0x3a8);
  if ((((iVar1 < 0x20) && (iVar1 != 9)) &&
      (*(char *)(**(int **)(iVar3 + DAT_00143e44) + DAT_00143e48) == '\0')) &&
     (piVar2 = *(int **)(this + 0x80), piVar2 != (int *)0x0)) {
    this_00 = **(CBBGEventMgr ***)(iVar3 + DAT_00143e4c);
    if (this_00[0x43] == (CBBGEventMgr)0x0) {
      if (((*(int *)(this_00 + 0x10) == 0xc) && (this_00[4] == (CBBGEventMgr)0x0)) &&
         (*(char *)(**(int **)(iVar3 + DAT_00143e58) + 0x10) == '\0')) {
        (**(code **)(*piVar2 + 0x10))(piVar2);
      }
    }
    else if ((**(int **)(iVar3 + DAT_00143e50) == 0) ||
            (*(char *)(**(int **)(iVar3 + DAT_00143e50) + 8) == '\0')) {
      CBBGEventMgr::KeyEvtProc(this_00,param_1);
    }
    else {
      **(int **)(iVar3 + DAT_00143e54) = param_1;
    }
  }
  return;
}


