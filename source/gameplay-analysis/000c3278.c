/* CCLProjection::SetViewport; research only, not buildable source */

/* CCLProjection::SetViewport(int, int, int, int) */

void __thiscall
CCLProjection::SetViewport(CCLProjection *this,int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  
  *(int *)(this + 0xc4) = param_1 << 0x12;
  uVar2 = param_3 * 0x40000;
  *(int *)(this + 200) = param_2 << 0x12;
  *(uint *)(this + 0xcc) = uVar2;
  uVar1 = param_4 * 0x40000;
  *(uint *)(this + 0xd0) = uVar1;
  *(uint *)(this + 0xd4) =
       ((((int)uVar2 >> 0x1f) + (uint)(0xfffffffe < uVar2)) * 0x20000 | uVar2 + 1 >> 0xf) << 0xe;
  *(uint *)(this + 0xd8) =
       ((((int)uVar1 >> 0x1f) + (uint)(0xfffffffe < uVar1)) * 0x20000 | uVar1 + 1 >> 0xf) << 0xe;
  return;
}


