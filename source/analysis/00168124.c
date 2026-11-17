/* CBBGMenuRun::InitMenuList at 00168124; decompiler output, not buildable source */

/* CBBGMenuRun::InitMenuList(eMenuType) */

void __thiscall CBBGMenuRun::InitMenuList(CBBGMenuRun *this,eMenuType param_1)

{
  int iVar1;
  CBBGMenuRun *pCVar2;
  
  if (param_1 < 7) {
    iVar1 = DAT_00168278 + 0x168130 + DAT_0016827c;
                    /* WARNING: Could not emulate address calculation at 0x00168138 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(iVar1 + param_1 * 4) + iVar1))();
    return;
  }
  if (param_1 - 1 < 6) {
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0x88) = 0;
    *(undefined2 *)(this + 0x8c) = 0;
    this[0x8e] = (CBBGMenuRun)0x0;
    *(undefined4 *)(this + 0x98) = 0;
    pCVar2 = this + 0x79;
    do {
      if (*pCVar2 != (CBBGMenuRun)0xff) {
        *(int *)(this + 0x98) = *(int *)(this + 0x98) + 1;
      }
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 != this + 0x80);
    this[0x8b] = (CBBGMenuRun)0x3;
    this[0x88] = (CBBGMenuRun)0x0;
    this[0x8e] = (CBBGMenuRun)0x0;
    this[0x89] = (CBBGMenuRun)0x1;
    this[0x8d] = (CBBGMenuRun)0x1;
    this[0x8a] = (CBBGMenuRun)0x2;
    this[0x8c] = (CBBGMenuRun)0x2;
  }
  return;
}


