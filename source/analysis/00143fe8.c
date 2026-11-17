/* CBBStartUp::EvAppStop at 00143fe8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBStartUp::EvAppStop() */

void CBBStartUp::EvAppStop(void)

{
  ClearFxTable();
  CLx::Cleanup();
  MC_knlExit(0);
  return;
}


