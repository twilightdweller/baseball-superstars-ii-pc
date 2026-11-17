/* CCLPitch::SetPitchEx; research only, not buildable source */

/* CCLPitch::SetPitchEx(tagCLxPoint3*, int, int, tagPitcherStyle, tagPitchType, int, int) */

void __thiscall
CCLPitch::SetPitchEx
          (CCLPitch *this,void *param_1,int param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  void *__dest;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  PreparePitchArray(this,param_2,param_3,param_4,param_6,param_7,param_8);
  __dest = *(void **)(this + 0x7c);
  if (this[0xd4] == (CCLPitch)0x0) {
    if (0 < *(int *)(this + 0x80)) {
      iVar4 = 0;
      iVar5 = 0;
      do {
        puVar3 = (undefined4 *)((int)param_1 + iVar4);
        puVar2 = (undefined *)(iVar4 + (int)__dest);
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0xc;
        iVar1 = __aeabi_idiv(*puVar3,10);
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = (char)((uint)(iVar1 * -0x40000) >> 0x10);
        puVar2[3] = (char)((uint)(iVar1 * -0x40000) >> 0x18);
        iVar1 = __aeabi_idiv(puVar3[1],10);
        puVar2[4] = 0;
        puVar2[5] = 0;
        puVar2[6] = (char)((uint)(iVar1 * -0x40000) >> 0x10);
        puVar2[7] = (char)((uint)(iVar1 * -0x40000) >> 0x18);
        iVar1 = __aeabi_idiv(puVar3[2],10);
        puVar2[8] = 0;
        puVar2[9] = 0;
        puVar2[10] = (char)((uint)(iVar1 << 0x12) >> 0x10);
        puVar2[0xb] = (char)((uint)(iVar1 << 0x12) >> 0x18);
      } while (iVar5 < *(int *)(this + 0x80));
    }
  }
  else {
    memcpy(__dest,param_1,param_2 * 0xc);
  }
  return;
}


