/* CCLPitch::GetAboveStrikeZoneBallPos; research only, not buildable source */

/* CCLPitch::GetAboveStrikeZoneBallPos(int) */

int CCLPitch::GetAboveStrikeZoneBallPos(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_r1;
  int iVar4;
  int in_r2;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  bbtagPoint2D *pbVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  tagCLxPoint3 local_34;
  int local_30;
  int local_2c;
  
  iVar8 = *(int *)(in_r1 + 0x84);
  iVar10 = DAT_000c4050 + 0xc3ee0;
  if (iVar8 == 0) {
    iVar10 = iVar10 + DAT_000c4054;
    *(undefined4 *)param_1 = *(undefined4 *)(iVar10 + 0x18);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar10 + 0x1c);
  }
  else {
    piVar7 = (int *)(*(int *)(in_r1 + 0x8c) * 0xc + iVar8);
    iVar1 = piVar7[2];
    iVar2 = piVar7[1];
    iVar3 = *piVar7;
    piVar7 = (int *)(iVar8 + -0xc + *(int *)(in_r1 + 0x88) * 0xc);
    iVar8 = __aeabi_ldivmod(0,((in_r2 << 0x12) >> 0x1f) << 0x12 | (uint)(in_r2 << 0x12) >> 0xe,
                            DAT_000c4040,DAT_000c4044);
    iVar4 = iVar8 >> 0x1f;
    iVar5 = piVar7[1] - iVar2;
    lVar11 = __aeabi_lmul(iVar8,iVar4,iVar5,iVar5 >> 0x1f);
    lVar11 = lVar11 + CONCAT44(DAT_000c404c,DAT_000c4048);
    uVar6 = (uint)lVar11 >> 0x12 | (int)((ulonglong)lVar11 >> 0x20) * 0x4000;
    iVar5 = piVar7[2] - iVar1;
    lVar11 = __aeabi_lmul(iVar8,iVar4,iVar5,iVar5 >> 0x1f,uVar6);
    lVar11 = lVar11 + CONCAT44(DAT_000c404c,DAT_000c4048);
    iVar5 = *piVar7 - iVar3;
    lVar12 = __aeabi_lmul(iVar8,iVar4,iVar5,iVar5 >> 0x1f);
    lVar12 = lVar12 + CONCAT44(DAT_000c404c,DAT_000c4048);
    local_34 = iVar3 + ((uint)lVar12 >> 0x12 | (int)((ulonglong)lVar12 >> 0x20) * 0x4000);
    local_30 = uVar6 + iVar2;
    local_2c = iVar1 + ((uint)lVar11 >> 0x12 | (int)((ulonglong)lVar11 >> 0x20) * 0x4000);
    pbVar9 = *(bbtagPoint2D **)(iVar10 + DAT_000c4058);
    CCLProjection::TransformPoint(*(CCLProjection **)(in_r1 + 0xcc),pbVar9,&local_34);
    *(bbtagPoint2D *)param_1 = *pbVar9;
    *(bbtagPoint2D *)(param_1 + 4) = pbVar9[1];
  }
  return param_1;
}


