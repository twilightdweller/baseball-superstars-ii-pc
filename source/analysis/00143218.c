/* CBBStartUp::EvAppSuspend at 00143218; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBStartUp::EvAppSuspend() */

void CBBStartUp::EvAppSuspend(void)

{
  int in_r0;
  
  if (*(int **)(in_r0 + 0x80) != (int *)0x0) {
    (**(code **)(**(int **)(in_r0 + 0x80) + 0x14))();
  }
  return;
}


