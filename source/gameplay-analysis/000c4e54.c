/* CCLPitch::CCLPitch; research only, not buildable source */

/* CCLPitch::CCLPitch() */

CCLPitch * __thiscall CCLPitch::CCLPitch(CCLPitch *this)

{
  *(undefined4 *)this = 0xb;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 0x14;
  *(undefined4 *)(this + 0x8c) = 0;
  this[0x90] = (CCLPitch)0x0;
  this[0x91] = (CCLPitch)0x64;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  CCLSpline::CCLSpline((CCLSpline *)(this + 0x9c),10);
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  this[0xd4] = (CCLPitch)0x0;
  this[0xd5] = (CCLPitch)0x0;
  memset(this + 0x1c,0,0x60);
  return this;
}


