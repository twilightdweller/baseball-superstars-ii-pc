/* CBBGMenuRun::SetMenuIdx at 00168284; decompiler output, not buildable source */

/* CBBGMenuRun::SetMenuIdx(unsigned char, int) */

void __thiscall CBBGMenuRun::SetMenuIdx(CBBGMenuRun *this,uchar param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_00168310 + 0x16828c;
  if (param_1 == '\0') {
    iVar2 = param_2 + *(int *)(this + 0x94);
    *(int *)(this + 0x94) = iVar2;
    if (iVar2 < 0) {
      *(int *)(this + 0x94) = *(int *)(this + 0x98) + -1;
    }
    else if (*(int *)(this + 0x98) <= iVar2) {
      *(undefined4 *)(this + 0x94) = 0;
    }
  }
  else {
    uVar1 = param_2 + *(int *)(this + 0x90);
    *(uint *)(this + 0x90) = uVar1;
    if ((int)uVar1 < 0) {
      uVar1 = (int)(char)this[0x87] - 1;
      *(uint *)(this + 0x90) = uVar1;
    }
    else if ((int)(char)this[0x87] <= (int)uVar1) {
      *(undefined4 *)(this + 0x90) = 0;
      InitMenuList(this,1);
      return;
    }
    if (uVar1 < 6) {
      iVar2 = iVar2 + DAT_00168314;
                    /* WARNING: Could not emulate address calculation at 0x001682d8 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(*(int *)(iVar2 + uVar1 * 4) + iVar2))();
      return;
    }
  }
  return;
}


