/* CBBGMenuRun::DRAW_HANDLER_MSTATE_RANKING_LIST at 0016b730; decompiler output, not buildable source */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DRAW_HANDLER_MSTATE_RANKING_LIST() */

void CBBGMenuRun::DRAW_HANDLER_MSTATE_RANKING_LIST(void)

{
  char cVar1;
  undefined uVar2;
  undefined3 uVar3;
  short sVar4;
  CBBGMenuRun *in_r0;
  undefined4 uVar5;
  CGxPZxMgr *pCVar6;
  CGxPZxBitmap **ppCVar7;
  void *__src;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int extraout_r1;
  char *__src_00;
  int extraout_r1_00;
  uint uVar13;
  CBBGCommonMenu *pCVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  CBBGResMgr **ppCVar24;
  int iVar25;
  CGxPZxMgr *pCVar26;
  int *piVar27;
  CGsTouchMgr **ppCVar28;
  undefined4 uVar29;
  int iVar30;
  int iVar31;
  ushort uVar32;
  uint uVar33;
  short sVar34;
  int local_124;
  int *piStack_120;
  int iStack_110;
  int *piStack_104;
  void *pvStack_100;
  char *pcStack_fc;
  void *pvStack_f0;
  void *pvStack_ec;
  void *local_e4;
  void *pvStack_d8;
  ePZX aeStack_b0 [4];
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  ePZX aeStack_98 [4];
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  short sStack_64;
  short sStack_62;
  ushort uStack_60;
  int iStack_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined local_30;
  int local_2c;
  
  iVar12 = DAT_0016b8e4;
  iVar11 = DAT_0016b8e0 + 0x16b746;
  local_2c = **(int **)(iVar11 + DAT_0016b8e4);
  iVar16 = *(int *)(in_r0 + 0x6c);
  *(undefined4 *)(iVar16 + 0x5c) = 0x11;
  *(undefined *)(iVar16 + 100) = 1;
  *(undefined *)(iVar16 + 0x65) = 1;
  *(undefined4 *)(iVar16 + 0x68) = 2;
  DRAW_HANDLER_MSTATE_MAIN();
  iVar16 = DAT_0016b8e8;
  iVar17 = **(int **)(iVar11 + DAT_0016b8e8);
  uVar29 = *(undefined4 *)(iVar17 + 0x48);
  iVar23 = *(int *)(iVar17 + 0x4c);
  iVar17 = *(int *)(iVar17 + 0x3c);
  uVar5 = MC_grpGetPixelFromRGB(0,0,0);
  if (**(code ***)(iVar11 + DAT_0016b8ec) != (code *)0x0) {
    (***(code ***)(iVar11 + DAT_0016b8ec))(0,0,uVar29,iVar17 + iVar23,uVar5,5);
  }
  iVar23 = DAT_0016b8f4;
  iVar17 = DAT_0016b8f0;
  CGsTouchMgr::ClearAllTouchRect();
  ppCVar24 = *(CBBGResMgr ***)(iVar11 + iVar23);
  pCVar6 = (CGxPZxMgr *)CBBGResMgr::GetPZxMgr(*ppCVar24,0x14);
  CBBGResMgr::GetPZxMgr(*ppCVar24,0x23);
  pCVar26 = *(CGxPZxMgr **)(**(int **)(iVar11 + DAT_0016b8f8) + 4);
  local_30 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  ppCVar7 = (CGxPZxBitmap **)CBBGResMgr::GetBitmaps(*ppCVar24,0x1b);
  iVar21 = DAT_0016b908;
  iVar18 = **(int **)(iVar11 + DAT_0016b8fc);
  iVar19 = (int)*(char *)(iVar18 + DAT_0016b900);
  local_e4 = (void *)0x1;
  if (*(int *)(iVar18 + 0xa4) != 0) {
    local_e4 = (void *)(uint)(*(int *)(iVar18 + 0xa4) == 2);
  }
  if (*(int *)(in_r0 + 0xbc) != 0) {
    if (*(int *)(in_r0 + 0xbc) == 1) {
      FUN_0016c22a();
    }
    FUN_0016b852();
    return;
  }
  cVar1 = *(char *)(iVar18 + iVar19 * 0x1e6 + DAT_0016b904 + 2);
  iVar20 = iVar11 + DAT_0016b908;
  aeStack_98[0] = *(ePZX *)(iVar20 + 0x4c);
  aeStack_98[1] = *(undefined4 *)(iVar20 + 0x50);
  aeStack_98[2] = *(undefined4 *)(iVar20 + 0x54);
  aeStack_98[3] = *(undefined4 *)(iVar20 + 0x58);
  uStack_88 = *(undefined4 *)(iVar20 + 0x5c);
  uStack_84 = *(undefined4 *)(iVar20 + 0x60);
  uStack_80 = 0x130;
  uStack_7c = DAT_0016b90c;
  uStack_78 = 0x132;
  CBBGCommonMenu::DrawCommonSpecial(*(CBBGCommonMenu **)(in_r0 + 0x6c),0,'\x01',0x130);
  iVar20 = *(int *)(in_r0 + 0x6c);
  if ((*(char *)(iVar20 + 0x34c) == '\0') || (*(char *)(iVar20 + DAT_0016b910) != '\0')) {
    if (local_2c == **(int **)(iVar11 + iVar12)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  iVar12 = 0x7e;
  if (*(int *)(in_r0 + 0xbc) == 0) {
    FUN_0016c28a();
    iVar12 = extraout_r1;
  }
  piStack_120 = (int *)0x0;
  if (*(int *)(pCVar26 + 0xc) != 0) {
    piStack_120 = *(int **)(iVar12 * 4 + *(int *)(*(int *)(pCVar26 + 0xc) + 8));
  }
  iVar12 = (int)*(short *)(iVar20 + 0x360);
  iVar20 = (int)*(short *)(iVar20 + DAT_0016bca8);
  (**(code **)(*piStack_120 + 0x10))(piStack_120,iVar12,iVar20,0,0,0);
  if (*(char *)(*(int *)(in_r0 + 0x6c) + 0x34c) == '\0') {
    FUN_0016c33e();
  }
  CGxPZxFrame::GetBoundingBox((int)&sStack_64,(int)piStack_120);
  uVar32 = uStack_60;
  sVar4 = sStack_62;
  sVar34 = sStack_64;
  piStack_104 = (int *)(uint)uStack_60;
  uStack_68 = 0;
  uStack_6c = 0;
  GetPzxSize((CGxPZxMgr *)&uStack_6c,(int)pCVar26,aeStack_98[*(int *)(in_r0 + 0xc4)]);
  DrawPZX(pCVar26,aeStack_98[*(int *)(in_r0 + 0xc4)],1,
          ((int)(short)uVar32 - (int)(short)uStack_68 >> 1) + iVar12 + sVar34,iVar20 + sVar4 + 1,0,0
          ,'\0','\x01');
  if (*(int *)(in_r0 + 0xbc) != 0) {
    FUN_0016c290();
  }
  iVar21 = iVar11 + iVar21;
  aeStack_b0[0] = *(ePZX *)(iVar21 + 100);
  aeStack_b0[1] = *(undefined4 *)(iVar21 + 0x68);
  aeStack_b0[2] = *(undefined4 *)(iVar21 + 0x6c);
  aeStack_b0[3] = *(undefined4 *)(iVar21 + 0x70);
  uStack_a0 = *(undefined4 *)(iVar21 + 0x74);
  uStack_9c = *(undefined4 *)(iVar21 + 0x78);
  CGxPZxFrame::GetBoundingBox((int)&sStack_64,(int)piStack_120);
  GetPzxSize((CGxPZxMgr *)&uStack_6c,(int)pCVar26,aeStack_b0[*(int *)(in_r0 + 0xc4)]);
  sVar34 = (short)uStack_68;
  iVar21 = CBBGDataMgr::GetOption();
  if (*(int *)(iVar21 + 0x48) == 1) {
    FUN_0016c354();
  }
  DrawPZX(pCVar26,aeStack_b0[*(int *)(in_r0 + 0xc4)],1,
          sStack_64 + iVar12 + ((int)(short)uStack_60 - (int)sVar34 >> 1),
          iVar20 + -2 + (int)sStack_62,0,0,'\0','\x01');
  iVar21 = *(int *)(in_r0 + 0xbc);
  iStack_110 = 3;
  if (iVar21 == 0) {
    iStack_110 = 5;
  }
  uStack_74 = 0;
  uStack_70 = 0;
  local_124 = 0;
  pcStack_fc = (char *)0x0;
  pvStack_100 = (void *)(cVar1 + -1);
  pvStack_ec = (void *)(iVar19 * 0xb2);
  iVar30 = 0xbc;
  do {
    iVar15 = iVar21;
    if ((int)pcStack_fc < (int)pvStack_100) {
      if (local_e4 == (void *)0x0) {
        iVar31 = (int)pcStack_fc * 0x2c + iVar19 * 0x1e6;
        __src = (void *)(iVar18 + iVar31 + DAT_0016bcb0);
        iVar15 = (int)pcStack_fc * 0x10 + 8;
        iVar10 = DAT_0016bcb4 + iVar18 + iVar15;
        pvStack_d8 = (void *)((int)pvStack_ec + DAT_0016bcb8 + iVar18 + iVar15);
        iVar25 = 0;
        pcVar8 = (char *)(iVar18 + iVar31 + DAT_0016bcbc);
        pcVar9 = (char *)(iVar18 + iVar31 + DAT_0016bcc0);
        pvStack_f0 = (void *)(iVar18 + iVar31 + DAT_0016bcc4);
        do {
          if (iVar21 == 0) {
            CGxPZxFrame::GetBoundingBox((int)&uStack_74,(int)piStack_120);
            sVar34 = (ushort)uStack_70;
          }
          else {
            CGxPZxFrame::GetBoundingBox((int)&uStack_74,(int)piStack_120);
            sVar34 = (ushort)uStack_70;
          }
          iVar31 = iVar12 + (short)uStack_74;
          uVar33 = local_124 + uStack_74._2_2_ + iVar20;
          if (iVar25 == 2) {
            if (*(int *)(in_r0 + 0xbc) == 0) {
              pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
              uVar3 = *(undefined3 *)((int)pvStack_f0 + 7);
              uVar2 = *(undefined *)((int)pvStack_f0 + 10);
LAB_0016bd90:
              piStack_104 = (int *)CONCAT13(uVar2,uVar3);
              CBBGCommonMenu::DrawNumber
                        (pCVar14,ppCVar7,0,(int)piStack_104,(int)sVar34 / 2 + iVar31,
                         uVar33 + 1 + (int)uStack_70._2_2_ / 2,0,0,0x22,0,0);
              iVar15 = *(int *)(in_r0 + 0xbc);
            }
            else {
              if (*(int *)(in_r0 + 0xbc) == 1) {
                pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
                iVar21 = DAT_0016c4b0 + iVar18 + (int)pcStack_fc * 0x10;
                uVar13 = (uint)*(byte *)((int)pvStack_ec + iVar21 + 0xe);
                uVar22 = (uint)*(uint3 *)((int)pvStack_ec + iVar21 + 0xb);
              }
              else {
                pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
                iVar21 = DAT_0016c0a8 + iVar18 + (int)pcStack_fc * 0x10;
LAB_0016bd6a:
                uVar13 = (uint)*(byte *)((int)pvStack_ec + iVar21 + 10);
                uVar22 = (uint)*(uint3 *)((int)pvStack_ec + iVar21 + 7);
              }
LAB_0016bba4:
              CBBGCommonMenu::DrawNumber
                        (pCVar14,ppCVar7,0,uVar22 | uVar13 << 0x18,(int)sVar34 / 2 + iVar31,
                         uVar33 + 1 + (int)uStack_70._2_2_ / 2,0,0,0x22,0,0);
              iVar15 = *(int *)(in_r0 + 0xbc);
            }
          }
          else if (iVar25 < 3) {
            if (iVar25 != 1) {
LAB_0016bb78:
              if (*(int *)(in_r0 + 0xbc) == 0) {
                pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
                uVar3 = *(undefined3 *)((int)pvStack_f0 + 3);
                uVar2 = *(undefined *)((int)pvStack_f0 + 6);
                goto LAB_0016bd90;
              }
              if (*(int *)(in_r0 + 0xbc) == 1) {
                pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
                iVar21 = DAT_0016c4b0 + iVar18 + (int)pcStack_fc * 0x10;
                goto LAB_0016bd6a;
              }
              pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
              iVar21 = _DAT_0016bcc8 + iVar18 + (int)pcStack_fc * 0x10;
              uVar13 = (uint)*(byte *)((int)pvStack_ec + iVar21 + 6);
              uVar22 = (uint)*(uint3 *)((int)pvStack_ec + iVar21 + 3);
              goto LAB_0016bba4;
            }
            local_58 = 0;
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_48 = 0;
            local_44 = 0;
            local_40 = 0;
            local_3c = 0;
            local_38 = 0;
            local_34 = 0;
            local_30 = 0;
            if (*(int *)(in_r0 + 0xbc) == 0) {
              memcpy(&local_38,__src,8);
              MC_knlSprintk(&local_58,iVar11 + _DAT_0016c0a4,&local_38);
            }
            else if (*(int *)(in_r0 + 0xbc) == 1) {
              memcpy(&local_38,(void *)((int)pvStack_ec + iVar10),8);
              MC_knlSprintk(&local_58,iVar11 + DAT_0016c4a8,&local_38);
            }
            else {
              memcpy(&local_38,pvStack_d8,8);
LAB_0016bd0a:
              piStack_104 = &local_58;
              MC_knlSprintk(piStack_104,iVar11 + _DAT_0016c0a4,&local_38);
            }
LAB_0016bc82:
            piStack_104 = &local_58;
            DrawTextBBF((char *)piStack_104,iVar31,uVar33 + 1,(int)sVar34,0xffffffff,'\0');
            iVar15 = *(int *)(in_r0 + 0xbc);
          }
          else if (iVar25 == 3) {
            iVar15 = *(int *)(in_r0 + 0xbc);
            if ((iVar15 == 0) && (iStack_5c = -1, *(int *)(in_r0 + 0xc4) < 3)) {
              iVar21 = CheckTeamLogo(in_r0,pcVar8,&iStack_5c);
              if (iVar21 != 0) {
                pCVar26 = (CGxPZxMgr *)
                          CBBGResMgr::GetPZxMgr(**(CBBGResMgr ***)(iVar11 + iVar23),0x19);
                sVar34 = 0;
                DrawPZX(pCVar26,iStack_5c,0,iVar31,uVar33,0,0,'\0','\x01');
                iVar21 = *(int *)(in_r0 + 0xbc);
                FUN_0016bbe8();
                iVar15 = 3;
                goto LAB_0016c44e;
              }
              iVar15 = *(int *)(in_r0 + 0xbc);
            }
          }
          else {
            if (iVar25 != 4) goto LAB_0016bb78;
            iVar15 = *(int *)(in_r0 + 0xbc);
            if (iVar15 == 0) {
              __src_00 = pcVar8;
              if (2 < *(int *)(in_r0 + 0xc4) - 3U) {
                __src_00 = pcVar9;
              }
              local_30 = 0;
              local_34 = 0;
              local_38 = 0;
              piStack_104 = &local_58;
              local_58 = iVar15;
              local_54 = iVar15;
              local_50 = iVar15;
              local_4c = iVar15;
              local_48 = iVar15;
              local_44 = iVar15;
              local_40 = iVar15;
              local_3c = iVar15;
              memcpy(&local_38,__src_00,8);
              if ((char)local_38 != '\0') goto LAB_0016bd0a;
              MC_knlSprintk(piStack_104,iVar11 + _DAT_0016bccc);
              goto LAB_0016bc82;
            }
          }
          iVar25 = iVar25 + 1;
          if (iStack_110 <= iVar25) break;
          iVar21 = *(int *)(in_r0 + 0xbc);
        } while( true );
      }
      local_124 = local_124 + 0x12;
      iVar21 = *(int *)(in_r0 + 0xbc);
    }
    pcStack_fc = pcStack_fc + 1;
    if (pcStack_fc == (char *)0xa) break;
    iVar21 = *(int *)(in_r0 + 0xbc);
  } while( true );
  if (iVar15 == 0) {
    cVar1 = *(char *)(iVar18 + iVar19 * 0x1e6 + DAT_0016c0ac + 2);
    local_124 = 5;
  }
  else {
    if (iVar15 == 1) {
      cVar1 = *(char *)(iVar18 + iVar19 * 0xb2 + DAT_0016c51c + 6);
    }
    else {
      cVar1 = *(char *)(iVar18 + iVar19 * 0xb2 + DAT_0016c4ac + 2);
    }
    local_124 = 3;
  }
  iStack_110 = cVar1 + -1;
  if ((-1 < iStack_110) && (local_e4 == (void *)0x0)) {
    iVar15 = iStack_110 * 0x2c + iVar19 * 0x1e6;
    pvStack_f0 = (void *)(iVar18 + iVar15 + DAT_0016c0b0);
    iVar30 = iStack_110 * 0x10 + 8 + iVar19 * 0xb2;
    pvStack_d8 = (void *)(iVar18 + iVar30 + DAT_0016c0b4);
    pvStack_100 = (void *)(iVar18 + iVar30 + DAT_0016c0b8);
    pcStack_fc = (char *)(iVar18 + iVar19 * 0x1e6 + DAT_0016c0bc);
    pvStack_ec = (void *)(iVar18 + iVar15 + DAT_0016c0c0);
    local_e4 = (void *)(iVar18 + iVar15 + DAT_0016c0c4);
    piStack_104 = (int *)(iVar18 + iVar15 + DAT_0016c0ac);
    iVar15 = 0;
    iVar31 = 0xbc;
    do {
      if (iVar21 == 0) {
        CGxPZxFrame::GetBoundingBox((int)&uStack_74,(int)piStack_120);
        uVar32 = (ushort)uStack_70;
      }
      else {
        CGxPZxFrame::GetBoundingBox((int)&uStack_74,(int)piStack_120);
        uVar32 = (ushort)uStack_70;
      }
      uVar33 = (uint)uVar32;
      iVar21 = iVar12 + (short)uStack_74;
      iVar30 = uStack_74._2_2_ + iVar20;
      sVar34 = uStack_70._2_2_;
      if (iVar15 == 2) {
        if (*(int *)(in_r0 + iVar31) == 0) {
          pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
          uVar3 = *(undefined3 *)((int)piStack_104 + 7);
          uVar2 = *(undefined *)((int)piStack_104 + 10);
LAB_0016c3b4:
          iVar10 = CONCAT13(uVar2,uVar3);
          iVar21 = (int)(short)uVar32 / 2 + iVar21;
          iVar30 = iVar30 + 1 + (int)uStack_70._2_2_ / 2;
        }
        else {
          if (*(int *)(in_r0 + iVar31) != 1) {
            pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
            iVar10 = iVar18 + iStack_110 * 0x10 + iVar19 * 0xb2 + DAT_0016c4ac;
            uVar3 = *(undefined3 *)(iVar10 + 7);
            uVar2 = *(undefined *)(iVar10 + 10);
LAB_0016bf36:
            CBBGCommonMenu::DrawNumber
                      (pCVar14,ppCVar7,0,CONCAT13(uVar2,uVar3),(int)(short)uVar32 / 2 + iVar21,
                       iVar30 + 1 + (int)uStack_70._2_2_ / 2,0,0,0x22,0,0);
            goto LAB_0016bf70;
          }
LAB_0016c44e:
          uVar32 = (ushort)uVar33;
          pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
          iVar10 = iVar18 + iStack_110 * 0x10 + iVar19 * 0xb2 + DAT_0016c4b0;
          uVar3 = *(undefined3 *)(iVar10 + 0xb);
          uVar2 = *(undefined *)(iVar10 + 0xe);
LAB_0016c470:
          iVar10 = CONCAT13(uVar2,uVar3);
          iVar21 = (int)(short)uVar32 / 2 + iVar21;
          iVar30 = iVar30 + 1 + (int)sVar34 / 2;
        }
        CBBGCommonMenu::DrawNumber(pCVar14,ppCVar7,0,iVar10,iVar21,iVar30,0,0,0x22,0,0);
      }
      else if (iVar15 < 3) {
        if (iVar15 != 1) {
LAB_0016bf04:
          if (*(int *)(in_r0 + iVar31) != 0) {
            if (*(int *)(in_r0 + iVar31) != 1) {
              pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
              iVar10 = iVar18 + iStack_110 * 0x10 + iVar19 * 0xb2 + DAT_0016c0a8;
              uVar3 = *(undefined3 *)(iVar10 + 3);
              uVar2 = *(undefined *)(iVar10 + 6);
              goto LAB_0016bf36;
            }
            pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
            iVar10 = iVar18 + iStack_110 * 0x10 + iVar19 * 0xb2 + DAT_0016c51c;
            uVar3 = *(undefined3 *)(iVar10 + 7);
            uVar2 = *(undefined *)(iVar10 + 10);
            goto LAB_0016c470;
          }
          pCVar14 = *(CBBGCommonMenu **)(in_r0 + 0x6c);
          uVar3 = *(undefined3 *)((int)piStack_104 + 3);
          uVar2 = *(undefined *)((int)piStack_104 + 6);
          goto LAB_0016c3b4;
        }
        local_38 = 0;
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        local_4c = 0;
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        local_34 = 0;
        local_30 = 0;
        if (*(int *)(in_r0 + iVar31) == 0) {
          memcpy(&local_38,pvStack_f0,8);
        }
        else if (*(int *)(in_r0 + iVar31) == 1) {
          memcpy(&local_38,pvStack_d8,8);
        }
        else {
          memcpy(&local_38,pvStack_100,8);
        }
        MC_knlSprintk(&local_58,iVar11 + DAT_0016c4a8,&local_38);
LAB_0016c11c:
        DrawTextBBF((char *)&local_58,iVar21,iVar30 + 1,(int)(short)uVar32,0xffffffff,'\0');
      }
      else if (iVar15 == 3) {
        iStack_5c = -1;
        if ((*(int *)(in_r0 + 0xc4) < 3) &&
           (iVar10 = CheckTeamLogo(in_r0,pcStack_fc,&iStack_5c), iVar10 != 0)) {
          pCVar26 = (CGxPZxMgr *)CBBGResMgr::GetPZxMgr(**(CBBGResMgr ***)(iVar11 + iVar23),0x19);
          DrawPZX(pCVar26,iStack_5c,0,iVar21,iVar30,0,0,'\0','\x01');
        }
      }
      else {
        if (iVar15 != 4) goto LAB_0016bf04;
        iVar10 = *(int *)(in_r0 + iVar31);
        if (iVar10 == 0) {
          local_58 = iVar10;
          local_54 = iVar10;
          local_50 = iVar10;
          local_4c = iVar10;
          local_48 = iVar10;
          local_44 = iVar10;
          local_40 = iVar10;
          local_3c = iVar10;
          if (*(int *)(in_r0 + 0xc4) - 3U < 3) {
            local_38 = 0;
            local_34 = 0;
            local_30 = 0;
            memcpy(&local_38,local_e4,8);
            if ((char)local_38 == '\0') {
              MC_knlSprintk(&local_58,iVar11 + DAT_0016c0c8);
            }
            else {
              MC_knlSprintk(&local_58,iVar11 + DAT_0016c520,&local_38);
            }
          }
          else {
            local_34 = 0;
            local_38 = 0;
            local_30 = 0;
            memcpy(&local_38,pvStack_ec,8);
            if ((char)local_38 == '\0') {
              MC_knlSprintk(&local_58,iVar11 + DAT_0016c4b4);
            }
            else {
              MC_knlSprintk(&local_58,iVar11 + DAT_0016c520,&local_38);
            }
          }
          goto LAB_0016c11c;
        }
      }
LAB_0016bf70:
      iVar15 = iVar15 + 1;
      if (local_124 <= iVar15) break;
      iVar21 = *(int *)(in_r0 + iVar31);
    } while( true );
  }
  __aeabi_idivmod(*(undefined4 *)(in_r0 + 0x1c),10);
  if (extraout_r1_00 < 5) {
    iVar12 = 7;
    iVar23 = 0;
  }
  else {
    iVar12 = 5;
    iVar23 = 2;
  }
  piVar27 = *(int **)(iVar11 + iVar16);
  DrawPZX(pCVar6,0x86,0,iVar12,(*(int *)(*piVar27 + 0x3c) + *(int *)(*piVar27 + 0x4c) >> 1) + -7,
          0x11,0,'\0','\x01');
  iVar12 = *piVar27;
  DrawPZX(pCVar6,0x86,0,*(int *)(iVar12 + 0x48) + -0xf + iVar23,
          (*(int *)(iVar12 + 0x3c) + *(int *)(iVar12 + 0x4c) >> 1) + -7,0,0,'\0','\x01');
  ppCVar28 = *(CGsTouchMgr ***)(iVar11 + iVar17);
  CGsTouchMgr::AddKeyTouchRect
            (*ppCVar28,-3,0,(*(int *)(*piVar27 + 0x3c) + *(int *)(*piVar27 + 0x4c) >> 1) + -0xf,0x1e
             ,0x1e);
  iVar12 = *piVar27;
  CGsTouchMgr::AddKeyTouchRect
            (*ppCVar28,-4,*(int *)(iVar12 + 0x48) + -0x1e,
             (*(int *)(iVar12 + 0x3c) + *(int *)(iVar12 + 0x4c) >> 1) + -0xf,0x1e,0x1e);
  FUN_0016b8a0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


