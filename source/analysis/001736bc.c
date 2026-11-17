/* CBBGLogoRun::INIT_HANDLER_MSTATE_WARNING at 001736bc; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::INIT_HANDLER_MSTATE_WARNING() */

void CBBGLogoRun::INIT_HANDLER_MSTATE_WARNING(void)

{
  int in_r0;
  undefined8 uVar1;
  
  *(undefined *)(in_r0 + 0x70) = 0;
  uVar1 = MC_knlCurrentTime();
  *(undefined4 *)(in_r0 + 8) = 0;
  *(undefined8 *)(in_r0 + 0x78) = uVar1;
  return;
}


