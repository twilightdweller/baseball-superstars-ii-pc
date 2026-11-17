/* CCLPitch::SetPitch; research only, not buildable source */

/* CCLPitch::SetPitch(tagPitchType, int, tagPitcherStyle, unsigned char, unsigned char) */

void __thiscall
CCLPitch::SetPitch(void *this,int param_2,undefined4 param_3,undefined4 param_4,undefined param_11,
                  undefined param_12)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  undefined *__dest;
  undefined4 *__src;
  
  if (param_2 == 0x16) {
    *(undefined4 *)((int)this + 0x94) = 0;
  }
  else {
    *(undefined4 *)((int)this + 0x94) = param_3;
  }
  *(undefined *)((int)this + 0x90) = param_11;
  *(undefined4 *)this = param_4;
  *(int *)((int)this + 0x98) = param_2;
  *(undefined *)((int)this + 0x91) = param_12;
  iVar1 = GetSettingPitchIndex();
  iVar1 = iVar1 + 6;
  *(undefined *)((int)this + 0xd5) = **(undefined **)((int)this + iVar1 * 4 + 4);
  DeletePitchData();
  iVar2 = __aeabi_idiv((uint)*(byte *)((int)this + 0x91) *
                       (uint)*(byte *)(*(int *)((int)this + iVar1 * 4 + 4) + 1),100);
  *(int *)((int)this + 0x8c) = iVar2 + -1;
  *(int *)((int)this + 0x88) = iVar2 + 3;
  pvVar3 = (void *)MC_knlCalloc((iVar2 + 3) * 0xc);
  *(void **)((int)this + 0x84) = pvVar3;
  memset(pvVar3,0,*(int *)((int)this + 0x88) * 0xc);
  uVar4 = (uint)*(byte *)(*(int *)((int)this + iVar1 * 4 + 4) + 2);
  *(uint *)((int)this + 0x80) = uVar4;
  pvVar3 = (void *)MC_knlCalloc(uVar4 * 0xc);
  *(void **)((int)this + 0x7c) = pvVar3;
  memset(pvVar3,0,*(int *)((int)this + 0x80) * 0xc);
  iVar1 = *(int *)((int)this + iVar1 * 4 + 4);
  __dest = *(undefined **)((int)this + 0x7c);
  __src = *(undefined4 **)(iVar1 + 8);
  if (*(char *)(iVar1 + 4) == '\0') {
    if (0 < *(int *)((int)this + 0x80)) {
      iVar1 = 0;
      do {
        iVar2 = __aeabi_idiv(*__src,10);
        *__dest = 0;
        __dest[1] = 0;
        __dest[2] = (char)((uint)(iVar2 * -0x40000) >> 0x10);
        __dest[3] = (char)((uint)(iVar2 * -0x40000) >> 0x18);
        iVar2 = __aeabi_idiv(__src[1],10);
        __dest[4] = 0;
        __dest[5] = 0;
        __dest[6] = (char)((uint)(iVar2 * -0x40000) >> 0x10);
        __dest[7] = (char)((uint)(iVar2 * -0x40000) >> 0x18);
        iVar2 = __aeabi_idiv(__src[2],10);
        __dest[8] = 0;
        __dest[9] = 0;
        __dest[10] = (char)((uint)(iVar2 << 0x12) >> 0x10);
        __dest[0xb] = (char)((uint)(iVar2 << 0x12) >> 0x18);
        iVar1 = iVar1 + 1;
        __src = __src + 3;
        __dest = __dest + 0xc;
      } while (iVar1 < *(int *)((int)this + 0x80));
    }
    *(undefined *)((int)this + 0xd4) = 0;
  }
  else {
    memcpy(__dest,__src,*(int *)((int)this + 0x80) * 0xc);
    *(undefined *)((int)this + 0xd4) = 1;
  }
  return;
}


