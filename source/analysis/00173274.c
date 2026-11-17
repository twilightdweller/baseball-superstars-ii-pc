/* CBBGMenuRun::DrawProcess at 00173274; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DrawProcess() */

void CBBGMenuRun::DrawProcess(void)

{
  int in_r0;
  int iVar1;
  
  iVar1 = *(int *)(in_r0 + 0xc);
  if (iVar1 < 0x1b) {
    if (iVar1 < 0x16) {
      if (iVar1 == 10) {
        DRAW_HANDLER_MSTATE_HELP();
      }
      else if (iVar1 < 0xb) {
        if (iVar1 == 6) {
          DRAW_HANDLER_MSTATE_TITLE();
        }
        else if ((5 < iVar1) && (iVar1 < 9)) {
          DRAW_HANDLER_MSTATE_MAIN();
        }
      }
      else if (iVar1 == 0xc) {
        DRAW_HANDLER_MSTATE_SETTING();
      }
      else if (iVar1 < 0xc) {
        DRAW_HANDLER_MSTATE_RANKING();
      }
      else if (iVar1 == 0x13) {
        DRAW_HANDLER_MSTATE_HOMERUN_MODE();
      }
    }
    else {
      DRAW_HANDLER_MSTATE_MAIN();
      DRAW_HANDLER_MSTATE_GSHOP();
    }
  }
  else if (iVar1 == 0x23) {
    DRAW_HANDLER_MSTATE_DATA_DOWNLOAD();
  }
  else if (iVar1 < 0x24) {
    if (iVar1 < 0x22) {
      DRAW_HANDLER_MSTATE_SPECIAL();
    }
    else {
      DRAW_HANDLER_MSTATE_DATA_UPLOAD();
    }
  }
  else if (iVar1 == 0xb6) {
    DRAW_HANDLER_MSTATE_MENU_ACHIVEMENT();
  }
  else if (iVar1 < 0xb7) {
    if (iVar1 == 0x24) {
      DRAW_HANDLER_MSTATE_RANKING_LIST();
    }
  }
  else if (iVar1 == 0xb7) {
    DRAW_HANDLER_MSTATE_MENU_LEADERBOARD();
  }
  else if (iVar1 == 0xb8) {
    DRAW_HANDLER_MSTATE_MENU_FRIEND();
  }
  return;
}


