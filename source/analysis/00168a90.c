/* CBBGMenuRun::INIT_HANDLER_MSTATE_HELP at 00168a90; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_HELP() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_HELP(void)

{
  int in_r0;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(in_r0 + 0x94);
  iVar3 = DAT_00168b48 + 0x168aa2;
  CBBGCommonMenu::InitHelp(*(CBBGCommonMenu **)(in_r0 + 0x6c),iVar4,'\0');
  if (iVar4 == 6) {
    iVar4 = CBBGDataMgr::GetOption();
    if (*(int *)(iVar4 + 0x48) == 1) {
      changeUIStatus(5);
      iVar3 = **(int **)(iVar3 + DAT_00168b50);
      *(undefined4 *)(iVar3 + 0x3ac) = *(undefined4 *)(iVar3 + 0x3a8);
      *(undefined4 *)(iVar3 + 0x3a8) = 5;
    }
    else {
      changeUIStatus(0x1f);
      iVar3 = **(int **)(iVar3 + DAT_00168b50);
      *(undefined4 *)(iVar3 + 0x3ac) = *(undefined4 *)(iVar3 + 0x3a8);
      *(undefined4 *)(iVar3 + 0x3a8) = 0x1f;
    }
  }
  else {
    iVar1 = CBBGDataMgr::GetOption();
    if (*(int *)(iVar1 + 0x48) == 1) {
      if (iVar4 == 0) {
        changeUIStatus(4);
        iVar3 = **(int **)(iVar3 + DAT_00168b50);
        *(undefined4 *)(iVar3 + 0x3ac) = *(undefined4 *)(iVar3 + 0x3a8);
        *(undefined4 *)(iVar3 + 0x3a8) = 4;
        return;
      }
      iVar4 = iVar4 + 0x13;
    }
    else {
      iVar4 = iVar4 + 0x19;
    }
    changeUIStatus(iVar4);
    iVar3 = **(int **)(iVar3 + DAT_00168b50);
    uVar2 = *(undefined4 *)(iVar3 + 0x3a8);
    *(int *)(iVar3 + 0x3a8) = iVar4;
    *(undefined4 *)(iVar3 + 0x3ac) = uVar2;
  }
  return;
}


