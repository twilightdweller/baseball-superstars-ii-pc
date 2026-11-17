/* CBBGMenuRun::KeyPressed at 0016a208; decompiler output, not buildable source */

/* CBBGMenuRun::KeyPressed(int) */

void __thiscall CBBGMenuRun::KeyPressed(CBBGMenuRun *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = DAT_0016a2d8;
  iVar3 = DAT_0016a2c8 + 0x16a218;
  if (param_1 == DAT_0016a2cc) {
    iVar2 = *(int *)(**(int **)(iVar3 + DAT_0016a2d4) + 0xa4);
    if ((iVar2 != 0) && (iVar2 != 2)) {
      piVar4 = *(int **)(iVar3 + DAT_0016a2d8);
      CBBGCommonMenu::DeleteHelp();
      iVar2 = CBBGDataMgr::GetOption();
      if (*(int *)(iVar2 + 0x48) == 1) {
        changeUIStatus(0x20);
        iVar2 = *piVar4;
        *(undefined4 *)(iVar2 + 0x3ac) = *(undefined4 *)(iVar2 + 0x3a8);
        *(undefined4 *)(iVar2 + 0x3a8) = 0x20;
      }
      else {
        changeUIStatus(0x21);
        iVar2 = *piVar4;
        *(undefined4 *)(iVar2 + 0x3ac) = *(undefined4 *)(iVar2 + 0x3a8);
        *(undefined4 *)(iVar2 + 0x3a8) = 0x21;
      }
      CBBState::ReserveState((CBBState *)(this + 8),7);
      *(undefined *)(**(int **)(iVar3 + iVar1) + DAT_0016a2e0) = 0;
    }
  }
  else if (((param_1 == 0x60) && (*(int *)(this + 0xc) != 7)) && (*(int *)(this + 0xc) == 0x16)) {
    CBBState::ReserveState((CBBState *)(this + 8),7);
  }
  if ((*(int *)(**(int **)(iVar3 + DAT_0016a2d0) + 4) == 0) ||
     (*(int *)(**(int **)(iVar3 + DAT_0016a2d0) + 0x10) == 0)) {
    *(int *)(this + 0x28) = param_1;
  }
  return;
}


