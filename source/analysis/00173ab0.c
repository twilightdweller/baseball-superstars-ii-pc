/* CBBGLogoRun::ReleaseObj at 00173ab0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::ReleaseObj() */

void CBBGLogoRun::ReleaseObj(void)

{
  int in_r0;
  
  CBBGResMgr::ReleaseAll();
  if (*(int **)(in_r0 + 0x6c) != (int *)0x0) {
    (**(code **)(**(int **)(in_r0 + 0x6c) + 4))();
    *(undefined4 *)(in_r0 + 0x6c) = 0;
  }
  return;
}


