/* CBBGMenuRun::IsInSubMenuMoveWindowRect at 0016776c; decompiler output, not buildable source */

/* CBBGMenuRun::IsInSubMenuMoveWindowRect(GxPointerPos*) */

uint __thiscall CBBGMenuRun::IsInSubMenuMoveWindowRect(CBBGMenuRun *this,GxPointerPos *param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((int)*(short *)(this + 0x144) <= *(int *)param_1) {
    uVar1 = *(uint *)(param_1 + 4);
    if (((int)*(short *)(this + 0x146) <= (int)uVar1) &&
       (*(int *)param_1 <= (int)*(short *)(this + 0x148) + (int)*(short *)(this + 0x144))) {
      uVar2 = (int)*(short *)(this + 0x14a) + (int)*(short *)(this + 0x146);
      return (((int)uVar2 >> 0x1f) - ((int)uVar1 >> 0x1f)) + (uint)(uVar1 <= uVar2) & 0xff;
    }
  }
  return 0;
}


