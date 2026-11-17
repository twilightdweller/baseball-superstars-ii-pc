/* CCLFigureMgr::DrawFence; research only, not buildable source */

/* CCLFigureMgr::DrawFence(CGsGraphics&, bool, bool, CCLProjection*) */

void __thiscall
CCLFigureMgr::DrawFence
          (CCLFigureMgr *this,CGsGraphics *param_1,bool param_2,bool param_3,CCLProjection *param_4)

{
  int iVar1;
  int iVar2;
  bbtagPoint2D bVar3;
  bbtagPoint2D bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  bbtagPoint2D *pbVar17;
  bbtagPoint2D *pbVar18;
  tagCLxPoint3 tVar19;
  longlong lVar20;
  int local_164;
  int local_158;
  int local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  undefined4 local_d8;
  int local_d4;
  undefined4 local_d0;
  bbtagPoint2D local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  bbtagPoint2D abStack_a0 [2];
  tagCLxPoint3 local_98;
  int local_94;
  int local_90;
  tagCLxPoint3 local_8c;
  int local_88;
  int local_84;
  bbtagPoint2D local_80;
  int local_7c;
  bbtagPoint2D local_78;
  int local_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  tagCLxPoint3 local_34;
  tagCLxPoint3 local_30;
  tagCLxPoint3 local_2c;
  
  iVar2 = DAT_000a6834;
  iVar1 = DAT_000a6830;
  iVar5 = DAT_000a682c + 0xa6624;
  if (param_4 == (CCLProjection *)0x0) {
    param_4 = (CCLProjection *)(**(int **)(iVar5 + DAT_000a6b4c) + 4);
  }
  iVar12 = **(int **)(iVar5 + DAT_000a6830);
  iVar8 = *(int *)(iVar12 + 0x138);
  iVar6 = iVar8 >> 1;
  if (*(int *)(iVar12 + 0x134) < 1) {
    return;
  }
  local_158 = 0;
  local_164 = 0;
  iVar9 = iVar12;
  if (0 < *(int *)(iVar12 + 0x134)) goto LAB_000a679e;
  do {
    piVar13 = *(int **)(iVar5 + iVar2);
    local_f4 = piVar13[2];
    local_f8 = piVar13[1];
    local_fc = *piVar13;
    iVar7 = local_164;
    while( true ) {
      if (*(int *)(iVar12 + 0x134) + -1 == iVar7) {
        if (*(int *)(iVar9 + 0x134) < 1) {
          piVar13 = *(int **)(iVar5 + iVar2);
          local_f0 = *piVar13;
          local_e8 = piVar13[2];
          local_ec = piVar13[1];
        }
        else {
          ToVirtual((bbtagPoint2D)&local_58);
          iVar9 = **(int **)(iVar5 + iVar1);
          local_f0 = local_58;
          local_e8 = local_50;
          local_ec = local_54;
        }
        local_e0 = local_ec - iVar6;
      }
      else {
        if (iVar7 + 1 < *(int *)(iVar9 + 0x134)) {
          ToVirtual((bbtagPoint2D)&local_64);
          iVar9 = **(int **)(iVar5 + iVar1);
          local_f0 = local_64;
          local_e8 = local_5c;
          local_ec = local_60;
        }
        else {
          piVar13 = *(int **)(iVar5 + iVar2);
          local_e8 = piVar13[2];
          local_ec = piVar13[1];
          local_f0 = *piVar13;
        }
        local_e0 = local_ec - iVar6;
      }
      local_164 = iVar7 + 1;
      local_e4 = local_f0;
      local_dc = local_e8;
      if (iVar7 < *(int *)(iVar9 + 0x134)) {
        ToVirtual((bbtagPoint2D)&local_70);
        local_d0 = local_68;
        local_d4 = local_6c;
        local_d8 = local_70;
      }
      else {
        puVar14 = *(undefined4 **)(iVar5 + iVar2);
        local_d0 = puVar14[2];
        local_d4 = puVar14[1];
        local_d8 = *puVar14;
      }
      local_d4 = local_d4 - iVar6;
      pbVar17 = &local_c0;
      piVar13 = &local_fc;
      do {
        pbVar18 = pbVar17 + 2;
        CCLProjection::TransformPoint(param_4,pbVar17,(CL_Point3 *)piVar13);
        iVar9 = local_bc;
        bVar3 = local_c0;
        piVar13 = piVar13 + 3;
        pbVar17 = pbVar18;
      } while (abStack_a0 != pbVar18);
      uVar10 = DAT_000a683c;
      if ((*(int *)(iVar12 + 0x13c) <= iVar7) && (iVar7 < *(int *)(iVar12 + 0x140))) {
        uVar10 = DAT_000a6838;
      }
      if (param_3) {
        uVar15 = MC_grpGetPixelFromRGB(0xff,0,0xff);
        CLGrp::DrawEllipse(param_1,bVar3,iVar9,1,1,uVar15);
        bVar3 = local_c0;
        iVar9 = local_bc + -5;
        uVar15 = MC_grpGetPixelFromRGB(0xff,0,0xff);
        CLGrp::DrawEllipse(param_1,bVar3 - 5,iVar9,10,10,uVar15);
      }
      CLGrp::DrawLine(param_1,local_c0,local_bc,local_b8,local_b4,uVar10);
      if (param_2) {
        CLGrp::DrawLine(param_1,local_b8,local_b4,local_b0,local_ac,uVar10);
        CLGrp::DrawLine(param_1,local_b0,local_ac,local_a8,local_a4,uVar10);
        CLGrp::DrawLine(param_1,local_a8,local_a4,local_c0,local_bc,uVar10);
        CLGrp::DrawLine(param_1,local_c0,local_bc,local_b0,local_ac,uVar10);
        uVar15 = local_ec * 0x40000 + local_f8 * -0x40000;
        uVar16 = local_e8 * 0x40000 + local_f4 * -0x40000;
        uVar10 = local_f0 * 0x40000 + local_fc * -0x40000;
        tVar19 = local_fc * 0x40000 +
                 ((((int)uVar10 >> 0x1f) + (uint)(0xfffffffe < uVar10)) * 0x20000 |
                 uVar10 + 1 >> 0xf) * 0x4000;
        iVar11 = local_f8 * 0x40000 + (iVar8 >> 2) * -0x40000 +
                 ((((int)uVar15 >> 0x1f) + (uint)(0xfffffffe < uVar15)) * 0x20000 |
                 uVar15 + 1 >> 0xf) * 0x4000;
        iVar7 = ((((int)uVar16 >> 0x1f) + (uint)(0xfffffffe < uVar16)) * 0x20000 | uVar16 + 1 >> 0xf
                ) * 0x4000 + local_f4 * 0x40000;
        piVar13 = (int *)(*(int *)(**(int **)(iVar5 + DAT_000a6b48) + 8) + local_158);
        iVar9 = piVar13[2];
        uVar15 = (uint)*(byte *)((int)piVar13 + 7) * 0x1000000 | (uint)*(uint3 *)(piVar13 + 1);
        local_98 = tVar19;
        local_94 = iVar11;
        local_90 = iVar7;
        lVar20 = __aeabi_lmul(*piVar13,*piVar13 >> 0x1f,100,0);
        uVar10 = (uint)(lVar20 + 1);
        local_8c = (uVar10 * 0x20000 >> 0x12 |
                   ((int)((ulonglong)(lVar20 + 1) >> 0x20) * 0x20000 | uVar10 >> 0xf) << 0xe) +
                   tVar19;
        lVar20 = __aeabi_lmul(uVar15,(int)uVar15 >> 0x1f,100,0);
        uVar10 = (uint)(lVar20 + 1);
        local_88 = iVar11 + (uVar10 * 0x20000 >> 0x12 |
                            ((int)((ulonglong)(lVar20 + 1) >> 0x20) * 0x20000 | uVar10 >> 0xf) <<
                            0xe);
        lVar20 = __aeabi_lmul(iVar9,iVar9 >> 0x1f,100,0);
        uVar10 = (uint)(lVar20 + 1);
        local_84 = iVar7 + (uVar10 * 0x20000 >> 0x12 |
                           ((int)((ulonglong)(lVar20 + 1) >> 0x20) * 0x20000 | uVar10 >> 0xf) << 0xe
                           );
        CCLProjection::TransformPoint(param_4,&local_80,&local_98);
        CCLProjection::TransformPoint(param_4,&local_78,&local_8c);
        iVar7 = local_74;
        bVar4 = local_78;
        iVar9 = local_7c;
        bVar3 = local_80;
        uVar10 = MC_grpGetPixelFromRGB(0xff,0,0xff);
        CLGrp::DrawLine(param_1,bVar3,iVar9,bVar4,iVar7,uVar10);
        local_34 = local_fc << 0x12;
        local_30 = local_f8 << 0x12;
        local_2c = local_f4 << 0x12;
        local_40 = local_f0 << 0x12;
        local_3c = local_ec << 0x12;
        local_38 = local_e8 << 0x12;
        iVar9 = CCLFenceCollisionDetect::CheckPointPosByLineXZ
                          (local_34,local_30,local_2c,false,0,local_38,local_8c,(char)local_88,
                           local_84,0);
        if (iVar9 == 0) {
          uVar10 = MC_grpGetPixelFromRGB(0xff,0,0xff);
        }
        else if (iVar9 < 0) {
          uVar10 = MC_grpGetPixelFromRGB(0xff,0xff,0);
        }
        else {
          uVar10 = MC_grpGetPixelFromRGB(0,0xff,0xff);
        }
        CLGrp::DrawFillEllipse(param_1,local_78 - 5,local_74 + -5,10,10,uVar10);
      }
      local_158 = local_158 + 0xc;
      if (*(int *)(iVar12 + 0x134) <= local_164) {
        return;
      }
      iVar9 = **(int **)(iVar5 + iVar1);
      if (*(int *)(iVar9 + 0x134) <= local_164) break;
LAB_000a679e:
      ToVirtual((bbtagPoint2D)&local_4c);
      iVar9 = **(int **)(iVar5 + iVar1);
      local_f4 = local_44;
      local_f8 = local_48;
      local_fc = local_4c;
      iVar7 = local_164;
    }
  } while( true );
}


