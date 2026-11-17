/* CBBGGameRun::GetBattingTiming; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGGameRun::GetBattingTiming() */

byte CBBGGameRun::GetBattingTiming(void)

{
  byte bVar1;
  int in_r0;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(**(int **)(DAT_00173e90 + 0x173e68 + DAT_00173e94) + 0x90);
  bVar1 = 100;
  if (*(int *)(in_r0 + 0x2c4) != iVar2) {
    iVar2 = iVar2 - *(int *)(in_r0 + 0x2c4);
    uVar3 = iVar2 >> 0x1f;
    bVar1 = -((iVar2 + uVar3 ^ uVar3) == 1) & 0x4b;
  }
  return bVar1;
}


