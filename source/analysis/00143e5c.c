/* CBBStartUp::EvKeyPress at 00143e5c; decompiler output, not buildable source */

/* CBBStartUp::EvKeyPress(int) */

void __thiscall CBBStartUp::EvKeyPress(CBBStartUp *this,int param_1)

{
  CBBGOption *this_00;
  CBBGEventMgr *this_01;
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00143f74 + 0x143e6c;
  if ((param_1 == 0x61) ||
     ((*(int *)(**(int **)(iVar2 + DAT_00143f78) + 0x3a8) != 9 &&
      (*(char *)(**(int **)(iVar2 + DAT_00143f78) + DAT_00143f7c) == '\0')))) {
    if (*(int *)(this + 0x80) == 0) {
      GsExit(0);
    }
    else {
      this_00 = (CBBGOption *)CBBGDataMgr::GetOption();
      if (this_00 != (CBBGOption *)0x0) {
        if (param_1 == -0xd) {
          if ((char)this_00[0x44] < '\x04') {
            CBBGOption::ChangeSound(this_00,1);
            CBBGOption::Apply();
            if (this_00[0x44] == (CBBGOption)0x1) {
              iVar1 = *(int *)(**(CGsSound ***)(iVar2 + DAT_00143f94) + 0x2c);
              if (iVar1 - 1U < 3) {
                CGsSound::Play(**(CGsSound ***)(iVar2 + DAT_00143f94),iVar1,-1,'\x01');
              }
            }
          }
        }
        else if ((param_1 == -0xe) && ('\0' < (char)this_00[0x44])) {
          CBBGOption::ChangeSound(this_00,-1);
          CBBGOption::Apply();
        }
      }
      this_01 = **(CBBGEventMgr ***)(iVar2 + DAT_00143f84);
      if (this_01[0x43] == (CBBGEventMgr)0x0) {
        if ((((*(int *)(this_01 + 0x10) == 0xc) && (this_01[4] == (CBBGEventMgr)0x0)) &&
            (*(char *)(**(int **)(iVar2 + DAT_00143f90) + 0x10) == '\0')) &&
           ((param_1 != -0x10 || (iVar2 = CBBGSatellite::IsBuyItemConnect(), iVar2 == 0)))) {
          (**(code **)(**(int **)(this + 0x80) + 0xc))(*(int **)(this + 0x80),param_1);
        }
      }
      else if ((**(int **)(iVar2 + DAT_00143f88) == 0) ||
              (*(char *)(**(int **)(iVar2 + DAT_00143f88) + 8) == '\0')) {
        CBBGEventMgr::KeyEvtProc(this_01,param_1);
      }
      else {
        **(int **)(iVar2 + DAT_00143f8c) = param_1;
      }
    }
  }
  return;
}


