/* CCLProjection::SetOrigin; research only, not buildable source */

/* CCLProjection::SetOrigin(int, int) */

void __thiscall CCLProjection::SetOrigin(CCLProjection *this,int param_1,int param_2)

{
  *(int *)(this + 0xc4) = param_1 << 0x12;
  *(int *)(this + 200) = param_2 << 0x12;
  return;
}


