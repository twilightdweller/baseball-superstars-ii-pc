/* CCLPitch::PreparePitchArray; research only, not buildable source */

/* CCLPitch::PreparePitchArray(int, int, tagPitcherStyle, tagPitchType, int, int) */

void __thiscall
CCLPitch::PreparePitchArray
          (void *this,int param_2,int param_3,undefined4 param_4,undefined4 param_11,
          undefined param_12,undefined param_13)

{
  void *pvVar1;
  
  *(undefined4 *)((int)this + 0x94) = 0;
  *(undefined *)((int)this + 0x90) = 0;
  *(undefined *)((int)this + 0x91) = 100;
  *(undefined4 *)this = param_4;
  *(undefined4 *)((int)this + 0x98) = param_11;
  *(undefined *)((int)this + 0xd5) = param_12;
  DeletePitchData();
  *(int *)((int)this + 0x8c) = param_3 + -1;
  *(int *)((int)this + 0x88) = param_3 + 3;
  pvVar1 = (void *)MC_knlCalloc((param_3 + 3) * 0xc);
  *(void **)((int)this + 0x84) = pvVar1;
  memset(pvVar1,0,*(int *)((int)this + 0x88) * 0xc);
  *(int *)((int)this + 0x80) = param_2;
  pvVar1 = (void *)MC_knlCalloc(param_2 * 0xc);
  *(void **)((int)this + 0x7c) = pvVar1;
  memset(pvVar1,0,*(int *)((int)this + 0x80) * 0xc);
  *(undefined *)((int)this + 0xd4) = param_13;
  return;
}


