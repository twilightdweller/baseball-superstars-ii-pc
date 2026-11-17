/* CCLProjection::TransformPoint; research only, not buildable source */

/* CCLProjection::TransformPoint(CL_xPoint4*, tagCLxPoint3*) */

void __thiscall
CCLProjection::TransformPoint(CCLProjection *this,CL_xPoint4 *param_1,tagCLxPoint3 *param_2)

{
  *(undefined4 *)(param_1 + 0xc) = 0x40000;
  *(tagCLxPoint3 *)param_1 = *param_2;
  *(tagCLxPoint3 *)(param_1 + 4) = param_2[1];
  *(tagCLxPoint3 *)(param_1 + 8) = param_2[2];
  CCLMatrix::MatrixMul(param_1,param_1,(CL_xMatrix *)(this + 0x84));
  return;
}


