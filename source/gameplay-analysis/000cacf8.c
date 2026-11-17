/* CCLMatrix::MatrixIdentity; research only, not buildable source */

/* CCLMatrix::MatrixIdentity(CL_xMatrix*) */

void CCLMatrix::MatrixIdentity(CL_xMatrix *param_1)

{
  memset(param_1,0,0x40);
  *(undefined4 *)param_1 = 0x40000;
  *(undefined4 *)(param_1 + 0x14) = 0x40000;
  *(undefined4 *)(param_1 + 0x28) = 0x40000;
  *(undefined4 *)(param_1 + 0x3c) = 0x40000;
  return;
}


