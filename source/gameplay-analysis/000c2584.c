/* CCLSpline::SetMaxPointCount; research only, not buildable source */

/* CCLSpline::SetMaxPointCount(int) */

void __thiscall CCLSpline::SetMaxPointCount(CCLSpline *this,int param_1)

{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = param_1 * 4;
  DeleteAllPoints();
  pvVar1 = operator_new__(uVar2);
  *(void **)(this + 4) = pvVar1;
  pvVar1 = operator_new__(uVar2);
  *(void **)(this + 8) = pvVar1;
  pvVar1 = operator_new__(uVar2);
  *(int *)this = param_1;
  *(void **)(this + 0xc) = pvVar1;
  return;
}


