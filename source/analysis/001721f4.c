/* CBBGMenuRun::RunProcess at 001721f4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::RunProcess() */

void CBBGMenuRun::RunProcess(void)

{
  int in_r0;
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = DAT_001722fc;
  RunFilterPopup();
  iVar3 = iVar3 + 0x172204;
  piVar4 = *(int **)(iVar3 + DAT_00172300);
  iVar1 = *piVar4;
  if ((((iVar1 != 0) && (*(char *)(iVar1 + 8) != '\0')) && (*(char *)(iVar1 + 4) == '9')) &&
     (**(char **)(iVar3 + DAT_0017230c) == '\0')) {
    CBBGDataMgr::SaveOption();
    CGsSound::ForcedStopBGM();
    CGsSound::Stop();
    iVar1 = *piVar4;
    if (iVar1 != 0) {
      *(undefined *)(iVar1 + 4) = 0xff;
    }
    GsExit(0);
  }
  iVar1 = CBBGPopup::Run(**(CBBGPopup ***)(iVar3 + DAT_00172304),*(int *)(in_r0 + 0x30));
  if ((iVar1 == 0) && (uVar2 = *(int *)(in_r0 + 0xc) - 6, uVar2 < 0xb3)) {
                    /* WARNING: Could not emulate address calculation at 0x0017223a */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar3 + DAT_00172308 + uVar2 * 4) + iVar3 + DAT_00172308))();
    return;
  }
  return;
}


