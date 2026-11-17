/* CBBGMenuRun::IsFinishDspSubMenu at 001677e4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::IsFinishDspSubMenu() */

undefined4 CBBGMenuRun::IsFinishDspSubMenu(void)

{
  int in_r0;
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(in_r0 + iVar1 + 0x88) != '\x03') {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 7);
  return 1;
}


