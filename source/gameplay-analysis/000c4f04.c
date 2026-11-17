/* CCLPitch::CreateCurveData; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLPitch::CreateCurveData() */

CCLCurveData * CCLPitch::CreateCurveData(void)

{
  CCLCurveData *this;
  int iVar1;
  
  this = (CCLCurveData *)operator_new(8);
  CCLCurveData::CCLCurveData(this);
  iVar1 = CCLCurveData::Load();
  if ((iVar1 == 0) && (this != (CCLCurveData *)0x0)) {
    CCLCurveData::~CCLCurveData(this);
    operator_delete(this);
    this = (CCLCurveData *)0x0;
  }
  return this;
}


