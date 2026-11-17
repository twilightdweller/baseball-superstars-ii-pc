/* CCLCurveData::Delete; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLCurveData::Delete() */

void CCLCurveData::Delete(void)

{
  int *in_r0;
  
  if (*in_r0 != 0) {
    MC_knlFree();
  }
  *in_r0 = 0;
  return;
}


