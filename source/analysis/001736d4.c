/* CBBGLogoRun::INIT_HANDLER_MSTATE_LOGO at 001736d4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::INIT_HANDLER_MSTATE_LOGO() */

void CBBGLogoRun::INIT_HANDLER_MSTATE_LOGO(void)

{
  int iVar1;
  int iVar2;
  int in_r0;
  undefined8 uVar3;
  
  changeUIStatus(0);
  uVar3 = GsGetCurrentTime();
  iVar2 = DAT_00173704;
  iVar1 = DAT_00173700;
  *(undefined8 *)(in_r0 + 0x78) = uVar3;
  CGsSound::Play(**(CGsSound ***)(iVar1 + 0x1736ee + iVar2),0,-1,'\0');
  return;
}


