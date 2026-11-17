/* CCLPitch::DeletePitchCurves; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLPitch::DeletePitchCurves() */

void CCLPitch::DeletePitchCurves(void)

{
  int in_r0;
  CCLPitchCurve *this;
  int iVar1;
  
  iVar1 = 0;
  do {
    this = *(CCLPitchCurve **)(in_r0 + 0x1c);
    if (this != (CCLPitchCurve *)0x0) {
      CCLPitchCurve::~CCLPitchCurve(this);
      operator_delete(this);
    }
    iVar1 = iVar1 + 1;
    *(undefined4 *)(in_r0 + 0x1c) = 0;
    in_r0 = in_r0 + 4;
  } while (iVar1 != 0x18);
  return;
}


