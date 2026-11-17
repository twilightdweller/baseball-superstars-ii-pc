/* CCLSpline::CCLSpline; research only, not buildable source */

/* CCLSpline::CCLSpline(int) */

CCLSpline * __thiscall CCLSpline::CCLSpline(CCLSpline *this,int param_1)

{
  *(int *)this = param_1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  SetMaxPointCount(this,param_1);
  return this;
}


