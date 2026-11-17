/* CCLCurveData::SetPitchCurve; research only, not buildable source */

/* CCLCurveData::SetPitchCurve(CCLPitchCurve*, int) */

void __thiscall CCLCurveData::SetPitchCurve(CCLCurveData *this,CCLPitchCurve *param_1,int param_2)

{
  int iVar1;
  CCLPitchCurve CVar2;
  
  iVar1 = GetCurveDetailPtr(this,param_2);
  param_1[3] = *(CCLPitchCurve *)(iVar1 + 4);
  iVar1 = GetCurveDetailPtr(this,param_2);
  param_1[1] = *(CCLPitchCurve *)(iVar1 + 2);
  iVar1 = GetCurveDetailPtr(this,param_2);
  param_1[2] = *(CCLPitchCurve *)(iVar1 + 3);
  iVar1 = GetCurveDetailPtr(this,param_2);
  *param_1 = *(CCLPitchCurve *)(iVar1 + 1);
  CVar2 = (CCLPitchCurve)0x0;
  if (this[5] != (CCLCurveData)0x0) {
    iVar1 = GetCurveDetailPtr(this,param_2);
    CVar2 = *(CCLPitchCurve *)(iVar1 + 5);
  }
  param_1[4] = CVar2;
  return;
}


