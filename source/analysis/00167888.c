/* CBBGMenuRun::CheckTouchResult at 00167888; decompiler output, not buildable source */

/* CBBGMenuRun::CheckTouchResult(int) */

undefined4 __thiscall CBBGMenuRun::CheckTouchResult(CBBGMenuRun *this,int param_1)

{
  undefined4 uVar1;
  
  if (this[param_1 + 0x79] == (CBBGMenuRun)0xff) {
    uVar1 = *(undefined4 *)(this + 0x30);
  }
  else if (param_1 < 3) {
    this[0x70] = (CBBGMenuRun)('\x03' - (char)param_1);
    uVar1 = 0xffffffff;
  }
  else if (param_1 == 3) {
    uVar1 = 0xfffffffb;
  }
  else {
    this[0x70] = (CBBGMenuRun)((char)param_1 + -3);
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


