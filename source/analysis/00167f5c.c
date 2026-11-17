/* CBBGMenuRun::RunEditAutomataCB at 00167f5c; decompiler output, not buildable source */

/* CBBGMenuRun::RunEditAutomataCB(void*, int) */

void CBBGMenuRun::RunEditAutomataCB(void *param_1,int param_2)

{
  uchar uVar1;
  ushort uVar2;
  CBBGPlayerNameMgr *this;
  char *pcVar3;
  CGsAutomata **ppCVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar7 = DAT_001680fc;
  iVar8 = DAT_001680f4 + 0x167f72;
  iVar5 = **(int **)(iVar8 + DAT_001680f8);
  iVar9 = *(int *)((int)param_1 + 0x60);
  iVar6 = **(int **)(iVar8 + DAT_001680fc);
  if ((*(char *)(**(int **)(iVar8 + DAT_00168100) + DAT_00168104) != '\0') && (param_2 == 0x23)) {
    CGsTouchMgr::ClearAllTouchRect();
    pcVar3 = (char *)(iVar6 + 0x28);
    iVar6 = CBBGDataMgr::GetOption();
    iVar7 = DAT_00168118;
    if (*(int *)(iVar6 + 0x48) != 1) {
      *(undefined *)(iVar5 + DAT_00168118) = 1;
      *(undefined *)(iVar5 + iVar7 + 2) = 1;
      *(undefined *)(iVar5 + iVar7 + 3) = 1;
      *(undefined *)(iVar5 + iVar7 + 1) = 1;
      CGsOemIME::SetCallOem
                (**(CGsOemIME ***)(iVar8 + DAT_0016811c),pcVar3,9,0,
                 *(_func_void_void_ptr_char_ptr_int **)(iVar8 + DAT_00168120),'\x01','\x01','\x01',
                 '\x01',(void *)0x0);
      return;
    }
    *(undefined *)(iVar5 + DAT_00168118) = 1;
    *(undefined *)(iVar5 + iVar7 + 2) = 1;
    *(undefined *)(iVar5 + iVar7 + 3) = 1;
    *(undefined *)(iVar5 + iVar7 + 1) = 1;
    CGsOemIME::SetCallOem
              (**(CGsOemIME ***)(iVar8 + DAT_0016811c),pcVar3,9,2,
               *(_func_void_void_ptr_char_ptr_int **)(iVar8 + DAT_00168120),'\x01','\x01','\x01',
               '\x01',(void *)0x0);
    return;
  }
  if (param_2 == 0x6e) {
    pcVar3 = (char *)CGsOemIME::GetText(**(CGsOemIME ***)(iVar8 + DAT_0016811c),false);
    ppCVar4 = *(CGsAutomata ***)(iVar8 + iVar7);
    CGsAutomata::DeleteTextAll();
    CGsAutomata::SetText(*ppCVar4,pcVar3);
  }
  iVar5 = CBBGCommonMenu::KeyProcAutomata(iVar5,(uchar)param_2);
  iVar7 = DAT_0016810c;
  if (iVar5 == 0) {
    iVar5 = **(int **)(iVar8 + DAT_00168108);
    if (iVar5 == 0) {
      return;
    }
    *(undefined *)(iVar5 + 8) = 0;
    *(undefined *)(iVar5 + iVar7) = 1;
  }
  else {
    if (iVar5 != 2) {
      return;
    }
    uVar1 = *(uchar *)(iVar9 + 0xeb);
    iVar7 = *(int *)(iVar9 + 0x14);
    iVar7 = *(int *)(iVar7 + 0x14) * *(int *)(iVar7 + 0x10) + *(int *)(iVar7 + 0xc);
    if (uVar1 == '\0') {
      uVar2 = *(ushort *)(*(int *)(iVar9 + 0x2c) + iVar7 * 0x2c + 0x250);
    }
    else {
      uVar2 = *(ushort *)(*(int *)(iVar9 + 0x2c) + iVar7 * 0x34 + 0x14);
    }
    this = (CBBGPlayerNameMgr *)CBBGDataMgr::GetPlayerNameMgr();
    CBBGPlayerNameMgr::ChangingPlayerName(this,uVar2,(char *)(iVar6 + 0x28),uVar1);
    CBBGDataMgr::SaveOption();
    iVar5 = **(int **)(iVar8 + DAT_00168108);
    if (iVar5 == 0) {
      return;
    }
    *(undefined *)(iVar5 + DAT_0016810c) = 1;
    *(undefined *)(iVar5 + 8) = 0;
  }
  *(undefined2 *)(iVar5 + 0x1460) = 4;
  **(undefined **)(iVar8 + DAT_00168110) = 0xff;
  return;
}


