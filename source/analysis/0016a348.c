/* CBBGMenuRun::ReleaseObj at 0016a348; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::ReleaseObj() */

void CBBGMenuRun::ReleaseObj(void)

{
  int in_r0;
  
  CBBGCommonMenu::DeleteScreenCapture();
  CBBGResMgr::ReleaseAll();
  if (*(int **)(in_r0 + 0xa0) != (int *)0x0) {
    (**(code **)(**(int **)(in_r0 + 0xa0) + 4))();
    *(undefined4 *)(in_r0 + 0xa0) = 0;
  }
  if (*(int **)(in_r0 + 0xa4) != (int *)0x0) {
    (**(code **)(**(int **)(in_r0 + 0xa4) + 4))();
    *(undefined4 *)(in_r0 + 0xa4) = 0;
  }
  if (*(int **)(in_r0 + 0xac) != (int *)0x0) {
    (**(code **)(**(int **)(in_r0 + 0xac) + 4))();
    *(undefined4 *)(in_r0 + 0xac) = 0;
  }
  if (*(int **)(in_r0 + 0x60) != (int *)0x0) {
    (**(code **)(**(int **)(in_r0 + 0x60) + 4))();
    *(undefined4 *)(in_r0 + 0x60) = 0;
  }
  if (*(int **)(in_r0 + 0x108) != (int *)0x0) {
    (**(code **)(**(int **)(in_r0 + 0x108) + 4))();
    *(undefined4 *)(in_r0 + 0x108) = 0;
  }
  return;
}


