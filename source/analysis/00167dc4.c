/* CBBGMenuRun::RunNetIdAutomataCB at 00167dc4; decompiler output, not buildable source */

/* CBBGMenuRun::RunNetIdAutomataCB(void*, int) */

void CBBGMenuRun::RunNetIdAutomataCB(void *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  CGsAutomata **ppCVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = DAT_00167f30;
  iVar5 = DAT_00167f28 + 0x167dd6;
  iVar6 = **(int **)(iVar5 + DAT_00167f2c);
  iVar2 = **(int **)(iVar5 + DAT_00167f30);
  if ((*(char *)(**(int **)(iVar5 + DAT_00167f34) + DAT_00167f38) == '\0') || (param_2 != 0x23)) {
    if (param_2 == 0x6e) {
      pcVar1 = (char *)CGsOemIME::GetText(**(CGsOemIME ***)(iVar5 + DAT_00167f54),false);
      ppCVar4 = *(CGsAutomata ***)(iVar5 + iVar3);
      CGsAutomata::DeleteTextAll();
      CGsAutomata::SetText(*ppCVar4,pcVar1);
    }
    iVar2 = CBBGCommonMenu::KeyProcAutomata(iVar6,(uchar)param_2);
    iVar3 = DAT_00167f40;
    if (iVar2 == 0) {
      iVar2 = **(int **)(iVar5 + DAT_00167f3c);
      if (iVar2 != 0) {
        *(undefined *)(iVar2 + 8) = 0;
        *(undefined *)(iVar2 + iVar3) = 1;
        *(undefined2 *)(iVar2 + 0x1460) = 4;
        **(undefined **)(iVar5 + DAT_00167f44) = 0xff;
      }
      *(undefined4 *)((int)param_1 + 8) = 0;
      *(undefined *)(iVar6 + DAT_00167f48) = 1;
      CBBState::ReserveState((CBBState *)((int)param_1 + 8),7);
    }
    else if (iVar2 == 2) {
      *(int *)((int)param_1 + 8) = *(int *)((int)param_1 + 8) + 1;
      iVar3 = **(int **)(iVar5 + DAT_00167f3c);
      if (iVar3 != 0) {
        *(undefined *)(iVar3 + DAT_00167f40) = 1;
        *(undefined *)(iVar3 + 8) = 0;
        *(undefined2 *)(iVar3 + 0x1460) = 4;
      }
      **(undefined **)(iVar5 + DAT_00167f44) = 0;
    }
  }
  else {
    CGsTouchMgr::ClearAllTouchRect();
    pcVar1 = (char *)(iVar2 + 0x28);
    iVar2 = CBBGDataMgr::GetOption();
    iVar3 = DAT_00167f50;
    if (*(int *)(iVar2 + 0x48) == 1) {
      *(undefined *)(iVar6 + DAT_00167f50) = 1;
      *(undefined *)(iVar6 + iVar3 + 2) = 1;
      *(undefined *)(iVar6 + iVar3 + 3) = 1;
      *(undefined *)(iVar6 + iVar3 + 1) = 1;
      CGsOemIME::SetCallOem
                (**(CGsOemIME ***)(iVar5 + DAT_00167f54),pcVar1,9,2,
                 *(_func_void_void_ptr_char_ptr_int **)(iVar5 + DAT_00167f58),'\x01','\x01','\x01',
                 '\x01',(void *)0x0);
    }
    else {
      *(undefined *)(iVar6 + DAT_00167f50) = 1;
      *(undefined *)(iVar6 + iVar3 + 2) = 1;
      *(undefined *)(iVar6 + iVar3 + 3) = 1;
      *(undefined *)(iVar6 + iVar3 + 1) = 1;
      CGsOemIME::SetCallOem
                (**(CGsOemIME ***)(iVar5 + DAT_00167f54),pcVar1,9,0,
                 *(_func_void_void_ptr_char_ptr_int **)(iVar5 + DAT_00167f58),'\x01','\x01','\x01',
                 '\x01',(void *)0x0);
    }
  }
  return;
}


