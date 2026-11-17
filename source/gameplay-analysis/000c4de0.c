/* CCLPitch::~CCLPitch; research only, not buildable source */

/* CCLPitch::~CCLPitch() */

CCLPitch * __thiscall CCLPitch::~CCLPitch(CCLPitch *this)

{
  DeletePitchCurves();
  DeletePitchData();
  CCLSpline::~CCLSpline((CCLSpline *)(this + 0x9c));
  return this;
}


