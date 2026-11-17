/* CBBGMenuRun::EvPointerRelease at 00169f80; decompiler output, not buildable source */

/* CBBGMenuRun::EvPointerRelease(GxPointerPos*) */

void CBBGMenuRun::EvPointerRelease(GxPointerPos *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = DAT_0016a000 + 0x169f8c;
  if (iVar1 == 7) {
    if ((param_1[0x122] == (GxPointerPos)0x0) && (param_1[0x9d] != (GxPointerPos)0x0)) {
      SetMenuSelectIdx();
      param_1[DAT_0016a004] = (GxPointerPos)0x0;
    }
    else if (param_1[DAT_0016a004] != (GxPointerPos)0x0) {
      return;
    }
    if (param_1[0x9d] == (GxPointerPos)0x0) {
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      SetSubMenuSelectIdx();
      param_1[0x122] = (GxPointerPos)0x0;
      iVar1 = *(int *)(param_1 + 0xc);
    }
  }
  if (iVar1 == 0x1e) {
    CBBGCommonMenu::SLT_TEAM_KEYRELEASE(**(GxPointerPos ***)(iVar2 + DAT_0016a008));
    iVar1 = *(int *)(param_1 + 0xc);
  }
  if (iVar1 == 0x1f) {
    CBBGCommonMenu::SLT_TEAM_KEYRELEASE(**(GxPointerPos ***)(iVar2 + DAT_0016a008));
  }
  return;
}


