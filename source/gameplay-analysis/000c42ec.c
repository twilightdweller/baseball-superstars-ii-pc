/* CCLPitch::SetPitchEx; research only, not buildable source */

/* CCLPitch::SetPitchEx(CL_Point3*, int, int, tagPitcherStyle, tagPitchType, int, int) */

void __thiscall
CCLPitch::SetPitchEx
          (CCLPitch *this,int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  PreparePitchArray(this,param_2,param_3,param_4,param_6,param_7,param_8);
  puVar3 = *(undefined **)(this + 0x7c);
  if (this[0xd4] == (CCLPitch)0x0) {
    if (0 < *(int *)(this + 0x80)) {
      iVar2 = 0;
      do {
        iVar1 = __aeabi_idiv(*param_1,10);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = (char)((uint)(iVar1 * -0x40000) >> 0x10);
        puVar3[3] = (char)((uint)(iVar1 * -0x40000) >> 0x18);
        iVar1 = __aeabi_idiv(param_1[1],10);
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[6] = (char)((uint)(iVar1 * -0x40000) >> 0x10);
        puVar3[7] = (char)((uint)(iVar1 * -0x40000) >> 0x18);
        iVar1 = __aeabi_idiv(param_1[2],10);
        puVar3[8] = 0;
        puVar3[9] = 0;
        puVar3[10] = (char)((uint)(iVar1 << 0x12) >> 0x10);
        puVar3[0xb] = (char)((uint)(iVar1 << 0x12) >> 0x18);
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 3;
        puVar3 = puVar3 + 0xc;
      } while (iVar2 < *(int *)(this + 0x80));
    }
  }
  else if (0 < *(int *)(this + 0x80)) {
    iVar2 = 0;
    do {
      iVar1 = *param_1;
      puVar3[1] = 0;
      puVar3[2] = (char)((uint)(iVar1 << 0x12) >> 0x10);
      *puVar3 = 0;
      puVar3[3] = (char)((uint)(iVar1 << 0x12) >> 0x18);
      iVar1 = param_1[1];
      puVar3[5] = 0;
      puVar3[6] = (char)((uint)(iVar1 << 0x12) >> 0x10);
      puVar3[4] = 0;
      puVar3[7] = (char)((uint)(iVar1 << 0x12) >> 0x18);
      iVar1 = param_1[2];
      puVar3[9] = 0;
      puVar3[8] = 0;
      puVar3[10] = (char)((uint)(iVar1 << 0x12) >> 0x10);
      puVar3[0xb] = (char)((uint)(iVar1 << 0x12) >> 0x18);
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 3;
      puVar3 = puVar3 + 0xc;
    } while (iVar2 < *(int *)(this + 0x80));
  }
  return;
}


