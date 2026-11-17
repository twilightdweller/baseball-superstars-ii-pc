/* CBBGMenuRun::GameRun at 00168504; decompiler output, not buildable source */

/* CBBGMenuRun::GameRun(eGameMode) */

void __thiscall CBBGMenuRun::GameRun(CBBGMenuRun *this,eGameMode param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_00168684 + 0x168516;
  iVar2 = CBBGDataMgr::GetOption();
  *(undefined *)(**(int **)(iVar3 + DAT_0016868c) + 3) = 2;
  iVar1 = DAT_00168690;
  *(eGameMode *)(iVar2 + 0x6c) = param_1;
  **(eGameMode **)(iVar3 + iVar1) = param_1;
  *(eGameMode *)(**(int **)(iVar3 + DAT_00168694) + 4) = param_1;
  if (param_1 < 0xb) {
                    /* WARNING: Could not emulate address calculation at 0x00168546 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar3 + DAT_00168698 + param_1 * 4) + iVar3 + DAT_00168698))();
    return;
  }
  CBBGDataMgr::SaveOption();
  return;
}


