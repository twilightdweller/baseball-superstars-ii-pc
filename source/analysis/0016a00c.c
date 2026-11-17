/* CBBGMenuRun::EvPointerPress at 0016a00c; decompiler output, not buildable source */

/* CBBGMenuRun::EvPointerPress(GxPointerPos*) */

void __thiscall CBBGMenuRun::EvPointerPress(CBBGMenuRun *this,GxPointerPos *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(this + 0xc);
  iVar2 = DAT_0016a0d8 + 0x16a018;
  if (iVar1 != 7) goto joined_r0x0016a052;
  this[0x123] = (CBBGMenuRun)0x0;
  this[0x124] = (CBBGMenuRun)0x0;
  if ((this[0x122] == (CBBGMenuRun)0x0) && (this[0x9d] != (CBBGMenuRun)0x0)) {
    iVar1 = IsInMenuMoveWindowRect(this,param_1);
    if (iVar1 != 0) {
      this[DAT_0016a0dc] = (CBBGMenuRun)0x1;
      *(undefined4 *)(this + 0x128) = *(undefined4 *)param_1;
      *(undefined4 *)(this + 0x130) = 0;
      SetMenuStart();
      goto LAB_0016a046;
    }
    this[DAT_0016a0dc] = (CBBGMenuRun)0x0;
LAB_0016a080:
    if (this[0x9d] != (CBBGMenuRun)0x0) {
      iVar1 = IsInSubMenuMoveWindowRect(this,param_1);
      if (iVar1 == 0) {
        this[0x122] = (CBBGMenuRun)0x0;
        iVar1 = *(int *)(this + 0xc);
      }
      else {
        this[0x122] = (CBBGMenuRun)0x1;
        *(undefined4 *)(this + 300) = *(undefined4 *)(param_1 + 4);
        *(undefined4 *)(this + 0x134) = 0;
        iVar1 = *(int *)(this + 0xc);
      }
      goto joined_r0x0016a052;
    }
  }
  else {
LAB_0016a046:
    if (this[DAT_0016a0dc] == (CBBGMenuRun)0x0) goto LAB_0016a080;
  }
  iVar1 = *(int *)(this + 0xc);
joined_r0x0016a052:
  if (iVar1 == 0x1e) {
    CBBGCommonMenu::SLT_TEAM_KEYPRESS(**(CBBGCommonMenu ***)(iVar2 + DAT_0016a0e0),param_1);
    iVar1 = *(int *)(this + 0xc);
  }
  if (iVar1 == 0x1f) {
    CBBGCommonMenu::SLT_TEAM_KEYPRESS(**(CBBGCommonMenu ***)(iVar2 + DAT_0016a0e0),param_1);
  }
  return;
}


