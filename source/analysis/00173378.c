/* CBBGLogoRun::SatelliteErrorCB at 00173378; decompiler output, not buildable source */

/* CBBGLogoRun::SatelliteErrorCB(void*, int) */

void CBBGLogoRun::SatelliteErrorCB(void *param_1,int param_2)

{
  CGsSound::Resume();
  if (*(int *)((int)param_1 + 0xc) == 0xb) {
    CBBState::ReserveState((CBBState *)((int)param_1 + 8),7);
    *(undefined4 *)((int)param_1 + 8) = 0;
  }
  CBBGCommonMenu::CheckExceptAck(*(CBBGCommonMenu **)((int)param_1 + 100),param_2,0);
  return;
}


