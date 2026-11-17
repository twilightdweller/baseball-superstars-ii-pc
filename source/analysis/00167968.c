/* CBBGMenuRun::SatelliteErrorCB at 00167968; decompiler output, not buildable source */

/* CBBGMenuRun::SatelliteErrorCB(void*, int) */

void CBBGMenuRun::SatelliteErrorCB(void *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = DAT_00167a1c + 0x167974;
  CGsSound::Resume();
  uVar1 = *(int *)((int)param_1 + 0xc) - 0xb;
  if (uVar1 < 0x1a) {
    iVar2 = iVar2 + DAT_00167a24;
                    /* WARNING: Could not emulate address calculation at 0x0016798a */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar2 + uVar1 * 4) + iVar2))();
    return;
  }
  if (param_2 + 0x10U < 4) {
    piVar3 = *(int **)(iVar2 + DAT_00167a28);
    *(undefined *)(*piVar3 + DAT_00167a2c) = 1;
    changeUIStatus(0xe);
    iVar2 = *piVar3;
    *(undefined4 *)(iVar2 + 0x3ac) = *(undefined4 *)(iVar2 + 0x3a8);
    *(undefined4 *)(iVar2 + 0x3a8) = 0xe;
  }
  CBBGCommonMenu::CheckExceptAck(*(CBBGCommonMenu **)((int)param_1 + 0x6c),param_2,1);
  return;
}


