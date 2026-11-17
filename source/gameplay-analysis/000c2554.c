/* CCLSpline::DeleteAllPoints; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLSpline::DeleteAllPoints() */

void CCLSpline::DeleteAllPoints(void)

{
  undefined4 *in_r0;
  
  if ((void *)in_r0[1] != (void *)0x0) {
    operator_delete__((void *)in_r0[1]);
  }
  if ((void *)in_r0[2] != (void *)0x0) {
    operator_delete__((void *)in_r0[2]);
  }
  if ((void *)in_r0[3] != (void *)0x0) {
    operator_delete__((void *)in_r0[3]);
  }
  in_r0[1] = 0;
  in_r0[2] = 0;
  in_r0[3] = 0;
  *in_r0 = 0;
  return;
}


