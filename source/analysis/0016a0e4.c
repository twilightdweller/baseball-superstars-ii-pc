/* CBBGMenuRun::EvPointerMove at 0016a0e4; decompiler output, not buildable source */

/* CBBGMenuRun::EvPointerMove(GxPointerPos*) */

void __thiscall CBBGMenuRun::EvPointerMove(CBBGMenuRun *this,GxPointerPos *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_0016a1fc;
  iVar3 = *(int *)(this + 0xc);
  iVar4 = DAT_0016a1f8 + 0x16a0f4;
  if (iVar3 == 7) {
    if ((this[0x122] == (CBBGMenuRun)0x0) && (this[0x9d] != (CBBGMenuRun)0x0)) {
      if (this[DAT_0016a1fc] == (CBBGMenuRun)0x0) {
        iVar3 = IsInMenuMoveWindowRect(this,param_1);
        if (iVar3 != 0) {
          this[iVar1] = (CBBGMenuRun)0x1;
          *(undefined4 *)(this + 0x128) = *(undefined4 *)param_1;
          SetMenuStart();
          *(undefined4 *)(this + 0x130) = 0;
        }
      }
      else {
        *(int *)(this + 0x130) = *(int *)param_1 - *(int *)(this + 0x128);
      }
    }
    if ((this[DAT_0016a1fc] == (CBBGMenuRun)0x0) && (this[0x9d] != (CBBGMenuRun)0x0)) {
      if (this[0x122] == (CBBGMenuRun)0x0) {
        iVar3 = IsInSubMenuMoveWindowRect(this,param_1);
        if (iVar3 != 0) {
          this[0x122] = (CBBGMenuRun)0x1;
          *(undefined4 *)(this + 300) = *(undefined4 *)(param_1 + 4);
          *(undefined4 *)(this + 0x134) = 0;
        }
      }
      else {
        *(int *)(this + 0x134) = *(int *)(param_1 + 4) - *(int *)(this + 300);
      }
    }
    uVar2 = *(int *)(this + 0x130) >> 0x1f;
    if (2 < (int)(*(int *)(this + 0x130) + uVar2 ^ uVar2)) {
      this[DAT_0016a200] = (CBBGMenuRun)0x0;
    }
    uVar2 = *(int *)(this + 0x134) >> 0x1f;
    if (2 < (int)(*(int *)(this + 0x134) + uVar2 ^ uVar2)) {
      this[0x124] = (CBBGMenuRun)0x0;
    }
    iVar3 = *(int *)(this + 0xc);
  }
  if (iVar3 == 0x1e) {
    CBBGCommonMenu::SLT_TEAM_KEYMOVE(**(CBBGCommonMenu ***)(iVar4 + DAT_0016a204),param_1);
    iVar3 = *(int *)(this + 0xc);
  }
  if (iVar3 == 0x1f) {
    CBBGCommonMenu::SLT_TEAM_KEYMOVE(**(CBBGCommonMenu ***)(iVar4 + DAT_0016a204),param_1);
  }
  return;
}


