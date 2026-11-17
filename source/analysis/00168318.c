/* CBBGMenuRun::CheckLastGameMode at 00168318; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::CheckLastGameMode() */

void CBBGMenuRun::CheckLastGameMode(void)

{
  CBBGMenuRun *in_r0;
  int iVar1;
  int iVar2;
  
  iVar1 = CBBGDataMgr::GetOption();
  iVar1 = *(int *)(iVar1 + 0x6c);
  *(int *)(in_r0 + 100) = iVar1;
  if ((iVar1 - 3U < 2) ||
     ((((iVar2 = 6, iVar1 != 2 && (iVar2 = 5, iVar1 != 10)) && (iVar2 = 4, 1 < iVar1 - 8U)) &&
      (((iVar2 = 3, iVar1 != 1 && (iVar2 = 2, iVar1 != 7)) && (iVar2 = 1, 1 < iVar1 - 5U)))))) {
    iVar2 = 7;
  }
  iVar1 = 0;
  do {
    SetMenuIdx(in_r0,'\0',-1);
    ArrayRotate(in_r0,(signed *)(in_r0 + 0x79),7,-1);
    iVar1 = iVar1 + 1;
    ArrayRotate(in_r0,(signed *)(in_r0 + 0x80),7,-1);
  } while (iVar1 < iVar2);
  return;
}


