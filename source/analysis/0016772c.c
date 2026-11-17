/* CBBGMenuRun::IsInMenuMoveWindowRect at 0016772c; decompiler output, not buildable source */

/* CBBGMenuRun::IsInMenuMoveWindowRect(GxPointerPos*) */

uint __thiscall CBBGMenuRun::IsInMenuMoveWindowRect(CBBGMenuRun *this,GxPointerPos *param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((int)*(short *)(this + 0x13c) <= *(int *)param_1) {
    uVar1 = *(uint *)(param_1 + 4);
    if (((int)*(short *)(this + 0x13e) <= (int)uVar1) &&
       (*(int *)param_1 <= (int)*(short *)(this + 0x140) + (int)*(short *)(this + 0x13c))) {
      uVar2 = (int)*(short *)(this + 0x142) + (int)*(short *)(this + 0x13e);
      return (((int)uVar2 >> 0x1f) - ((int)uVar1 >> 0x1f)) + (uint)(uVar1 <= uVar2) & 0xff;
    }
  }
  return 0;
}


