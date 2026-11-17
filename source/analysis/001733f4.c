/* CBBGLogoRun::Suspend at 001733f4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::Suspend() */

void CBBGLogoRun::Suspend(void)

{
  int in_r0;
  
  if (*(int *)(in_r0 + 0x68) != 0) {
    CGsCertification::Suspend();
  }
  return;
}


