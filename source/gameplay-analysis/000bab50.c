/* CCLGame::SetBattingPattern; research only, not buildable source */

/* CCLGame::SetBattingPattern(int, int, int, int) */

void CCLGame::SetBattingPattern(int param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  int *piVar2;
  CL_PatternInfo *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar6 = DAT_000bac44 + 0xbab66;
  pCVar3 = *(CL_PatternInfo **)(iVar6 + DAT_000bac48);
  pCVar3[4] = param_4;
  iVar5 = DAT_000bac4c;
  pCVar3[2] = param_2;
  puVar1 = *(undefined **)(iVar6 + iVar5);
  *pCVar3 = param_1;
  *puVar1 = 1;
  iVar5 = DAT_000bac50;
  pCVar3[1] = 0;
  pCVar3[3] = param_3;
  piVar2 = *(int **)(iVar6 + iVar5);
  iVar6 = **(int **)(iVar6 + DAT_000bac54);
  iVar4 = *piVar2;
  CCLFigureMgr::ToVirtual((bbtagPoint2D)&local_34);
  iVar5 = DAT_000bac58;
  iVar6 = *(int *)(iVar6 + 0x180);
  local_30 = -iVar6;
  iVar6 = iVar6 * -0x40000;
  *(int *)(iVar4 + 0xf4) = local_34 << 0x12;
  *(int *)(iVar4 + 0xf8) = iVar6;
  *(int *)(iVar4 + 0xfc) = local_2c << 0x12;
  *(int *)(iVar4 + iVar5) = local_34 << 0x12;
  *(int *)(iVar4 + DAT_000bac5c) = iVar6;
  *(int *)(iVar4 + 0xab0) = local_2c << 0x12;
  CCLBallMovable::Stop();
  iVar5 = *piVar2;
  CCLParabolaMovement::Throw_Pattern2010((CCLParabolaMovement *)(iVar5 + 0xe8),pCVar3);
  *(undefined *)(iVar5 + DAT_000bac60) = 0;
  iVar6 = *piVar2;
  *(undefined4 *)(iVar6 + 0xaa0) = 2;
  *(undefined *)(iVar6 + DAT_000bac64) = 1;
  *(undefined *)(iVar6 + 0xae0) = 0;
  iVar5 = DAT_000bac68;
  *(undefined4 *)(iVar6 + DAT_000bac68) = 100;
  *(undefined4 *)(iVar6 + iVar5 + 4) = 10;
  CCLBallMovable::ReadyToThrow();
  *(undefined4 *)(*piVar2 + DAT_000bac6c) = 0;
  return;
}


