/* CBBGMenuRun::StartProcess at 0016de0c; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::StartProcess() */

void CBBGMenuRun::StartProcess(void)

{
  int in_r0;
  int iVar1;
  int *piVar2;
  
  if (*(int *)(in_r0 + 0xc) == 7) {
    piVar2 = *(int **)(DAT_0016df2c + 0x16de18 + DAT_0016df30);
    *(undefined *)(*piVar2 + DAT_0016df34) = 1;
    changeUIStatus(0x13);
    iVar1 = *piVar2;
    *(undefined4 *)(iVar1 + 0x3ac) = *(undefined4 *)(iVar1 + 0x3a8);
    *(undefined4 *)(iVar1 + 0x3a8) = 0x13;
  }
  else {
    piVar2 = *(int **)(DAT_0016df2c + 0x16de18 + DAT_0016df30);
    *(undefined *)(*piVar2 + DAT_0016df34) = 1;
    changeUIStatus(0xe);
    iVar1 = *piVar2;
    *(undefined4 *)(iVar1 + 0x3ac) = *(undefined4 *)(iVar1 + 0x3a8);
    *(undefined4 *)(iVar1 + 0x3a8) = 0xe;
    sendAndroidEvent(0x192);
  }
  iVar1 = *(int *)(in_r0 + 0xc);
  if (iVar1 < 0x22) {
    if (iVar1 < 0x1b) {
      if (iVar1 == 10) {
        INIT_HANDLER_MSTATE_HELP();
      }
      else if (iVar1 < 0xb) {
        if (iVar1 == 7) {
          INIT_HANDLER_MSTATE_MAIN();
        }
        else if (iVar1 == 8) {
          INIT_HANDLER_MSTATE_GAME_START();
        }
        else if (iVar1 == 6) {
          INIT_HANDLER_MSTATE_TITLE();
        }
      }
      else if (iVar1 == 0xc) {
        INIT_HANDLER_MSTATE_SETTING();
      }
      else if (iVar1 < 0xc) {
        INIT_HANDLER_MSTATE_RANKING();
      }
      else if (0x15 < iVar1) {
        INIT_HANDLER_MSTATE_GSHOP();
      }
    }
    else {
      INIT_HANDLER_MSTATE_SPECIAL();
    }
  }
  else if (iVar1 == 0x25) {
    INIT_HANDLER_MSTATE_GAME_DATA();
  }
  else if (iVar1 < 0x26) {
    if (iVar1 == 0x23) {
      INIT_HANDLER_MSTATE_DATA_DOWNLOAD();
    }
    else if (iVar1 < 0x24) {
      INIT_HANDLER_MSTATE_DATA_UPLOAD();
    }
    else {
      INIT_HANDLER_MSTATE_RANKING_LIST();
    }
  }
  else if (iVar1 == 0xb7) {
    INIT_HANDLER_MSTATE_MENU_LEADERBOARD();
  }
  else if (iVar1 == 0xb8) {
    INIT_HANDLER_MSTATE_MENU_FRIEND();
  }
  else if (iVar1 == 0xb6) {
    INIT_HANDLER_MSTATE_MENU_ACHIVEMENT();
  }
  return;
}


