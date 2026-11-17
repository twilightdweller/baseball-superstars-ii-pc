/* CCLGame::SetBattingPattern; research only, not buildable source */

/* CCLGame::SetBattingPattern(int, int) */

void CCLGame::SetBattingPattern(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  int iVar3;
  int extraout_r1_00;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar2 = DAT_000bab1c;
  iVar6 = DAT_000bab18 + 0xba926;
  if (param_1 < 0) {
    iVar8 = **(int **)(iVar6 + DAT_000bab1c);
    iVar3 = *(int *)(iVar8 + 0x2a4);
LAB_000bab04:
    __aeabi_idivmod(param_1,iVar3);
    param_1 = extraout_r1_00;
  }
  else {
    iVar8 = **(int **)(iVar6 + DAT_000bab1c);
    iVar3 = *(int *)(iVar8 + 0x2a4);
    if (iVar3 <= param_1) goto LAB_000bab04;
  }
  if (param_2 < 0) {
    iVar3 = *(int *)(iVar8 + param_1 * 0x1c + 4);
  }
  else {
    iVar3 = *(int *)(iVar8 + param_1 * 0x1c + 4);
    if (param_2 < iVar3) goto LAB_000ba958;
  }
  __aeabi_idivmod(param_2,iVar3);
  param_2 = extraout_r1;
LAB_000ba958:
  piVar4 = *(int **)(iVar6 + DAT_000bab20);
  *piVar4 = param_1;
  piVar4[1] = param_2;
  **(undefined **)(iVar6 + DAT_000bab24) = 0;
  SelectBattingPattern();
  piVar4 = (int *)(param_2 * 0x10 + *(int *)(**(int **)(iVar6 + iVar2) + param_1 * 0x1c + 0x1c));
  iVar3 = *piVar4;
  iVar2 = piVar4[2];
  uVar5 = piVar4[1] + DAT_000bab28;
  if ((uint)(piVar4[1] + DAT_000bab2c) <= DAT_000bab30) {
    iVar8 = __aeabi_ldivmod(uVar5 * 0x40000,((int)uVar5 >> 0x1f) << 0x12 | uVar5 >> 0xe,DAT_000bab10
                            ,DAT_000bab14);
    lVar9 = __aeabi_lmul(iVar8,iVar8 >> 0x1f,0x14,0);
    uVar1 = (uint)(lVar9 + 1);
    uVar5 = uVar5 - (uVar1 * 0x20000 >> 0x12 |
                    ((int)((ulonglong)(lVar9 + 1) >> 0x20) * 0x20000 | uVar1 >> 0xf) << 0xe);
  }
  if (uVar5 + 0x1680000 < uVar5) {
    iVar8 = __aeabi_ldivmod(uVar5 * -0x40000,((int)-uVar5 >> 0x1f) << 0x12 | -uVar5 >> 0xe,
                            DAT_000bab10,DAT_000bab14);
    lVar9 = __aeabi_lmul(iVar8,iVar8 >> 0x1f,0x14,0);
    uVar1 = (uint)(lVar9 + 1);
    uVar5 = uVar5 + (uVar1 * 0x20000 >> 0x12 |
                    ((int)((ulonglong)(lVar9 + 1) >> 0x20) * 0x20000 | uVar1 >> 0xf) << 0xe);
  }
  piVar4 = *(int **)(iVar6 + DAT_000bab34);
  *(undefined *)(*piVar4 + 0xa80) = 1;
  iVar8 = DAT_000bab3c;
  iVar7 = **(int **)(iVar6 + DAT_000bab38);
  CCLFigureMgr::ToVirtual((bbtagPoint2D)&local_34);
  iVar6 = *piVar4;
  local_30 = -3 - *(int *)(iVar7 + 0x180);
  *(int *)(iVar6 + 0xf4) = local_34 << 0x12;
  *(int *)(iVar6 + 0xf8) = local_30 * 0x40000;
  *(int *)(iVar6 + 0xfc) = local_2c << 0x12;
  *(int *)(iVar6 + iVar8) = local_34 << 0x12;
  *(int *)(iVar6 + DAT_000bab40) = local_30 * 0x40000;
  *(int *)(iVar6 + iVar8 + 8) = local_2c << 0x12;
  CCLBallMovable::Stop();
  iVar6 = *piVar4;
  *(int *)(iVar6 + 0xf0) = iVar2 + 0x140000;
  *(int *)(iVar6 + 0xe8) = iVar3 + 0x140000;
  *(uint *)(iVar6 + 0xec) = uVar5 + 0x2d00000;
  iVar6 = *piVar4;
  *(undefined4 *)(iVar6 + 0xaa0) = 0;
  *(undefined *)(iVar6 + DAT_000bab44) = 1;
  *(undefined *)(iVar6 + 0xae0) = 0;
  iVar2 = DAT_000bab48;
  *(undefined4 *)(iVar6 + DAT_000bab48) = 100;
  *(undefined4 *)(iVar6 + iVar2 + 4) = 10;
  CCLBallMovable::ReadyToThrow();
  *(undefined4 *)(*piVar4 + DAT_000bab4c) = 0;
  return;
}


