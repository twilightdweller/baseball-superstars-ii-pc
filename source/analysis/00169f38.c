/* CBBGMenuRun::Resume at 00169f38; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::Resume() */

void CBBGMenuRun::Resume(void)

{
  int in_r0;
  int iVar1;
  CBBGSatellite **ppCVar2;
  
  iVar1 = DAT_00169f74;
  *(undefined *)(*(int *)(in_r0 + 0x6c) + DAT_00169f70) = 0;
  ppCVar2 = *(CBBGSatellite ***)(iVar1 + 0x169f4a + DAT_00169f78);
  iVar1 = CBBGSatellite::IsBuyItemConnect();
  if (iVar1 != 0) {
    CBBGSatellite::Disconnect(*ppCVar2,'\0');
    CGsSound::Resume();
    *(undefined *)(*(int *)(in_r0 + 0x6c) + 0xc) = 0;
  }
  return;
}


