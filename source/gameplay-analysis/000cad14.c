/* CCLMatrix::CCLMatrix; research only, not buildable source */

/* CCLMatrix::CCLMatrix() */

CCLMatrix * __thiscall CCLMatrix::CCLMatrix(CCLMatrix *this)

{
  *(undefined4 *)this = 0x40000;
  *(undefined4 *)(this + 4) = 0x40000;
  *(undefined4 *)(this + 8) = 0x40000;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  MatrixIdentity((CL_xMatrix *)(this + 0x24));
  return this;
}


