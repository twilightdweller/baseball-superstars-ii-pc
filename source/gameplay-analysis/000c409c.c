/* CCLPitch::GetPitchCurveScreenPos; research only, not buildable source */

/* CCLPitch::GetPitchCurveScreenPos(int) */

int CCLPitch::GetPitchCurveScreenPos(int param_1)

{
  int in_r1;
  int in_r2;
  
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  if (*(int *)(in_r1 + 0x84) != 0) {
    CCLProjection::TransformPoint
              (*(CCLProjection **)(in_r1 + 0xcc),(bbtagPoint2D *)param_1,
               (tagCLxPoint3 *)(in_r2 * 0xc + *(int *)(in_r1 + 0x84)));
  }
  return param_1;
}


