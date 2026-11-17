/* CBBGMenuRun::IncDspSubMenu at 001677c0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::IncDspSubMenu() */

void CBBGMenuRun::IncDspSubMenu(void)

{
  char cVar1;
  int in_r0;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)(in_r0 + 0x88);
  iVar3 = 0;
  do {
    cVar1 = *pcVar2;
    *pcVar2 = cVar1 + '\x01';
    if ('\x03' < (char)(cVar1 + '\x01')) {
      *pcVar2 = '\x03';
    }
    iVar3 = iVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (iVar3 != 7);
  return;
}


