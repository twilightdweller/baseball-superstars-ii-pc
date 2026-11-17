/* CCLProjection::Update; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLProjection::Update() */

void CCLProjection::Update(void)

{
  int in_r0;
  CL_xMatrix *pCVar1;
  
  pCVar1 = (CL_xMatrix *)(in_r0 + 0x84);
  CCLMatrix::MatrixIdentity(pCVar1);
  CCLMatrix::MatrixMul(pCVar1,pCVar1,(CL_xMatrix *)(in_r0 + 4));
  CCLMatrix::MatrixMul(pCVar1,pCVar1,(CL_xMatrix *)(in_r0 + 0x44));
  return;
}


