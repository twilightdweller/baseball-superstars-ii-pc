/* CCLPitch::SetTotalFrameCount; research only, not buildable source */

/* CCLPitch::SetTotalFrameCount(int) */

void __thiscall CCLPitch::SetTotalFrameCount(CCLPitch *this,int param_1)

{
  void *__s;
  
  if (*(int *)(this + 0x84) != 0) {
    MC_knlFree();
  }
  *(int *)(this + 0x8c) = param_1 + -1;
  *(int *)(this + 0x88) = param_1 + 3;
  __s = (void *)MC_knlCalloc((param_1 + 3) * 0xc);
  *(void **)(this + 0x84) = __s;
  memset(__s,0,*(int *)(this + 0x88) * 0xc);
  return;
}


