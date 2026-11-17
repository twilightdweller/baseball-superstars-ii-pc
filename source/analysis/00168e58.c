/* CBBGMenuRun::DRAW_HANDLER_MSTATE_MAIN at 00168e58; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DRAW_HANDLER_MSTATE_MAIN() */

void CBBGMenuRun::DRAW_HANDLER_MSTATE_MAIN(void)

{
  bool bVar1;
  CBBGMenuRun CVar2;
  char cVar3;
  ePZX eVar4;
  int iVar5;
  CBBGMenuRun *in_r0;
  int iVar6;
  CGxPZxMgr *pCVar7;
  uint uVar8;
  int iVar9;
  CGsTouchMgr *this;
  CGxPZxAni *pCVar10;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  signed *psVar15;
  int iVar16;
  int iVar17;
  CGsTouchMgr **ppCVar18;
  int iVar19;
  enumDrawOP eVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 uVar24;
  CBBGMenuRun *pCVar25;
  int iVar26;
  CBBGResMgr **ppCVar27;
  int iVar28;
  uint in_r12;
  uchar uVar29;
  int iStack_8c;
  int iStack_84;
  undefined2 local_80;
  ePZX local_78;
  uint uStack_6c;
  int *piStack_64;
  int aiStack_4c [4];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar5 = DAT_00169184;
  iVar28 = DAT_00169180 + 0x168e70;
  ppCVar18 = *(CGsTouchMgr ***)(iVar28 + DAT_00169184);
  CGsTouchMgr::ClearAllTouchRect();
  CGsTouchMgr::SetNoneKeyMapIndex();
  CGsTouchMgr::EnableMovePointer(*ppCVar18,1,-3);
  CGsTouchMgr::EnableMovePointer(*ppCVar18,2,-4);
  CGsTouchMgr::EnableMovePointer(*ppCVar18,4,-1);
  CGsTouchMgr::EnableMovePointer(*ppCVar18,8,-2);
  CBBGCommonMenu::DrawCaptureTitle(*(CBBGCommonMenu **)(in_r0 + 0x6c),'\0','\0');
  if (*(int *)(in_r0 + 0xc) == 7) {
    iVar17 = *(int *)(in_r0 + 0x6c);
    *(undefined *)(iVar17 + 100) = 1;
    *(undefined4 *)(iVar17 + 0x5c) = 2;
    *(undefined *)(iVar17 + 0x65) = 1;
    *(undefined4 *)(iVar17 + 0x68) = 2;
  }
  iVar13 = DAT_0016918c;
  iVar17 = DAT_00169188;
  iVar19 = *(int *)(**(int **)(iVar28 + DAT_00169188) + 0x3c) +
           *(int *)(**(int **)(iVar28 + DAT_00169188) + 0x4c);
  iVar6 = __aeabi_idiv(iVar19 * 0x23,100);
  iVar19 = __aeabi_idiv(iVar19 * 0x4b,100);
  local_2c = 0;
  local_30 = 0;
  in_r0[0x72] = (CBBGMenuRun)0x0;
  psVar15 = (signed *)(in_r0 + 0x79);
  pCVar7 = (CGxPZxMgr *)CBBGResMgr::GetPZxMgr(**(CBBGResMgr ***)(iVar28 + iVar13),0x12);
  iVar16 = *(int *)(in_r0 + 0x150);
  if (iVar16 == 1) {
    if (*(int *)(in_r0 + 0x1c) % 4 == 2) {
      *(uint *)(in_r0 + 0x158) = (uint)(*(int *)(in_r0 + 0x158) == 0);
    }
    if (in_r0[0x9c] == (CBBGMenuRun)0x0) {
      FUN_00168f3c();
      return;
    }
    iVar16 = *(int *)(in_r0 + 0x14c);
    if (((1 < iVar16 + 4U) && (iVar16 != -1)) && (iVar16 != -2)) {
      FUN_00168f3c();
      return;
    }
    *(undefined4 *)(in_r0 + 0x150) = 2;
    uVar24 = 0xffffffff;
    *(undefined4 *)(in_r0 + 0x154) = 0xffffffff;
    *(undefined4 *)(iVar28 + DAT_00169970) = 10;
    in_r0[0x9d] = (CBBGMenuRun)0x0;
    iVar16 = *(int *)(in_r0 + 0x14c);
    if ((iVar16 == -1) || (iVar16 == -3)) {
      uVar24 = 1;
      iVar21 = -1;
    }
    else {
      iVar21 = 1;
    }
    bVar1 = iVar16 + 2U < 2;
    if (bVar1) {
      *(undefined4 *)(in_r0 + 0x150) = 3;
      ppCVar27 = *(CBBGResMgr ***)(iVar28 + iVar13);
      pCVar10 = (CGxPZxAni *)CBBGResMgr::GetAni(*ppCVar27,0x12,0);
      CGxPZxAni::Stop(pCVar10,true);
      pCVar10 = (CGxPZxAni *)CBBGResMgr::GetAni(*ppCVar27,0x12,0);
      CGxPZxAni::Play(pCVar10,false);
    }
    *(undefined4 *)(in_r0 + 0x154) = uVar24;
    SetMenuIdx(in_r0,!bVar1,iVar21);
    if (*(int *)(in_r0 + 0x90) != 0) {
      FUN_00168f3c();
    }
    if (*(int *)(in_r0 + 0x150) != 2) {
      FUN_00168f3c();
    }
    CheckLastGameMode();
    iVar16 = 0;
    FUN_00168f42();
LAB_0016970a:
    iVar13 = *(int *)(in_r0 + 0x154);
    iVar21 = 1;
    if (iVar16 != -3) {
      iVar21 = 3;
    }
  }
  else {
    if (iVar16 == 2) {
      FUN_001697f2();
    }
    if (iVar16 == 3) {
      FUN_0016987e();
    }
    piStack_64 = (int *)0x0;
    MC_grpGetPixelFromRGB(0,0xf6,0xff);
    if (in_r0[DAT_00169190] == (CBBGMenuRun)0x0) {
      iStack_84 = 0;
      CVar2 = in_r0[0x75];
    }
    else {
      uVar24 = *(undefined4 *)(in_r0 + 0x130);
      __aeabi_idivmod(uVar24,0x5f);
      uVar8 = __aeabi_idiv(uVar24,0x5f);
      if (uVar8 != 0) {
        uVar14 = uVar8 + ((int)uVar8 >> 0x1f) ^ (int)uVar8 >> 0x1f;
        if (uVar14 != 0) {
          iVar13 = 0;
          do {
            while (ArrayRotate(in_r0,(signed *)(in_r0 + 0x73),(int)(char)in_r0[0x87],
                               ((int)(uVar8 - 1 | uVar8) >> 0x1f) + -3), 0 < (int)uVar8) {
              *(int *)(in_r0 + 0x130) = *(int *)(in_r0 + 0x130) + -0x5f;
              *(int *)(in_r0 + 0x128) = *(int *)(in_r0 + 0x128) + 0x5f;
              iVar13 = iVar13 + 1;
              SetMenuIdx(in_r0,'\x01',-1);
              if ((int)uVar14 <= iVar13) goto LAB_001691ea;
            }
            *(int *)(in_r0 + 0x130) = *(int *)(in_r0 + 0x130) + 0x5f;
            iVar13 = iVar13 + 1;
            *(int *)(in_r0 + 0x128) = *(int *)(in_r0 + 0x128) + -0x5f;
            SetMenuIdx(in_r0,'\x01',1);
          } while (iVar13 < (int)uVar14);
        }
      }
LAB_001691ea:
      CVar2 = in_r0[0x75];
      iStack_84 = extraout_r1_01;
    }
    eVar4 = (int)(char)CVar2 + 0xc;
    if (eVar4 == 0x12) {
      GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,0xa7);
      DrawPZX(pCVar7,0x50,1,
              (*(int *)(**(int **)(iVar28 + iVar17) + 0x48) >> 1) -
              ((int)(short)(ushort)local_2c >> 1),
              (iVar19 + 0x32) - ((int)(short)local_2c._2_2_ >> 1),0,0,'\0','\x01');
      FUN_00168fc6();
      return;
    }
    GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,eVar4);
    iVar16 = (*(int *)(**(int **)(iVar28 + iVar17) + 0x48) >> 1) -
             ((int)(short)(ushort)local_2c >> 1);
    iVar13 = (iVar19 + 0x32) - ((int)(short)local_2c._2_2_ >> 1);
    if (eVar4 == 0x6a) {
      FUN_001699da();
    }
    if (eVar4 == 0x6b) {
      FUN_001698dc();
    }
    DrawPZX(pCVar7,(char)CVar2 + 0x26,1,iVar16,iVar13,0,0,'\0','\x01');
    GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,*(ePZX *)(in_r0 + 0x158));
    DrawPZX(pCVar7,*(int *)(in_r0 + 0x158),1,
            (*(int *)(**(int **)(iVar28 + iVar17) + 0x48) >> 1) -
            ((int)(short)(ushort)local_2c >> 1),(iVar19 + 0x32) - ((int)(short)local_2c._2_2_ >> 1),
            0,0,'\0','\x01');
    *(undefined2 *)(in_r0 + 0x13c) = 0;
    uStack_6c._0_2_ = (undefined2)(iVar19 + -0x1b);
    *(undefined2 *)(in_r0 + 0x13e) = (undefined2)uStack_6c;
    *(undefined2 *)(in_r0 + 0x140) = 0x1e0;
    *(undefined2 *)(in_r0 + 0x142) = 0x37;
    iVar13 = iStack_84;
    if ('\0' < (char)in_r0[0x87]) {
      iVar26 = DAT_00169198 + iVar28;
      pCVar25 = in_r0 + 0x72;
      eVar20 = 0xfffffffd;
      iVar16 = -1;
      iVar21 = DAT_00169194;
      do {
        MC_grpGetPixelFromRGB(0,0xf6,0xff);
        CVar2 = *pCVar25;
        iVar13 = iStack_84;
        if ((CVar2 != (CBBGMenuRun)0xff) &&
           ((((int)eVar20 < 0 || ((int)eVar20 < 1)) || ((int)eVar20 < 4)))) {
          iVar9 = *(int *)(in_r0 + 0x14c);
          uVar29 = (uchar)eVar20;
          if (iVar9 + 4U < 2) {
            iVar13 = *(int *)(in_r0 + 0x154);
            if (eVar20 == 0xffffffff) {
              if (iVar9 != -3) {
                FUN_00169084();
              }
              FUN_0016910e();
LAB_00169924:
              aiStack_4c[0] = *(int *)(iVar26 + 0x68);
              aiStack_4c[1] = *(undefined4 *)(iVar26 + 0x6c);
              aiStack_4c[2] = *(undefined4 *)(iVar26 + 0x70);
              aiStack_4c[3] = *(undefined4 *)(iVar26 + 0x74);
              uStack_3c = *(undefined4 *)(iVar26 + 0x78);
              uStack_38 = *(undefined4 *)(iVar26 + 0x7c);
              uStack_34 = *(undefined4 *)(iVar26 + 0x80);
              DrawPZX(pCVar7,aiStack_4c[(char)*pCVar25],2,iStack_8c,
                      iVar19 - ((int)(in_r12 << 0x10) >> 0x11),eVar20,eVar20,uVar29,'\x01');
              this = **(CGsTouchMgr ***)(iVar28 + iVar5);
              iVar9 = *piStack_64;
LAB_00169616:
              CGsTouchMgr::AddKeyTouchRect
                        (this,-5,(*(int *)(iVar9 + 0x48) >> 1) + -0x1b + iVar13,iVar19 + -0x1b,0x37,
                         0x37);
            }
            else {
              if (eVar20 != 1) {
                FUN_00169084();
                return;
              }
              if (iVar9 != -4) {
                FUN_00169084();
                return;
              }
            }
          }
          else {
            if ((int)(char)CVar2 == 6) {
              GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,0x97);
            }
            else {
              GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,(int)(char)CVar2);
            }
            in_r12 = (uint)local_2c._2_2_;
            piStack_64 = *(int **)(iVar28 + iVar17);
            iStack_8c = ((*(int *)(*piStack_64 + 0x48) >> 1) + iStack_84) -
                        ((int)((uint)(ushort)local_2c << 0x10) >> 0x11);
            if (eVar20 == 0) {
              if (in_r0[DAT_0016996c] == (CBBGMenuRun)0x0) goto LAB_00169924;
              iVar13 = iVar19 - ((int)(in_r12 << 0x10) >> 0x11);
              if ((char)*pCVar25 == 6) {
                DrawPZX(pCVar7,0x97,0,iStack_8c,iVar13,10,0,uVar29,'\x01');
              }
              else {
                DrawPZX(pCVar7,(int)(char)*pCVar25,0,iStack_8c,iVar13,10,0,uVar29,'\x01');
              }
              this = **(CGsTouchMgr ***)(iVar28 + iVar5);
              iVar9 = **(int **)(iVar28 + iVar17);
              iVar13 = iStack_84;
              goto LAB_00169616;
            }
            iVar13 = (int)(char)*pCVar25;
            iVar22 = iStack_8c + iVar21;
            iVar9 = iVar19 - ((int)(in_r12 << 0x10) >> 0x11);
            if (iVar13 == 6) {
              FUN_001699f8();
              iVar13 = extraout_r1;
            }
            if (iVar16 == -1) {
              FUN_001699a8();
              iVar13 = extraout_r1_00;
            }
            DrawPZX(pCVar7,iVar13,0,iVar22,iVar9,10,0,'\0','\x01');
            in_r0[0x72] = (CBBGMenuRun)((char)in_r0[0x72] + '\x01');
            iVar13 = iStack_84;
            if ((int)(eVar20 + ((int)eVar20 >> 0x1f) ^ (int)eVar20 >> 0x1f) < 3) {
              FUN_00169974();
            }
          }
        }
        iVar16 = iVar16 + 1;
        pCVar25 = pCVar25 + 1;
        eVar20 = eVar20 + 1;
        iVar21 = iVar21 + 0x5f;
      } while (iVar16 < (char)in_r0[0x87] + -1);
    }
    iVar16 = *(int *)(in_r0 + 0x14c);
    iVar21 = 0;
    if (iVar16 + 4U < 2) goto LAB_0016970a;
  }
  if (in_r0[DAT_001695a4] == (CBBGMenuRun)0x0) {
LAB_001692a2:
    iStack_84 = iVar13;
    if (iVar21 == 0) goto LAB_001692a8;
    uVar8 = iVar21 - 2;
    uStack_6c = ~uVar8;
    iVar16 = DAT_00169970;
  }
  else {
    uVar8 = iStack_84 + (iStack_84 >> 0x1f) ^ iStack_84 >> 0x1f;
    iVar16 = DAT_001695a8;
    if (0x2e < (int)uVar8) {
      uVar8 = 0x5f - uVar8;
      iVar16 = DAT_00169970;
    }
    iVar13 = __aeabi_idiv(uVar8 << 2,0x2f);
    *(int *)(iVar28 + iVar16) = iVar13 + 10;
    iVar13 = 0;
    if (iStack_84 == 0) goto LAB_001692a2;
    if (iStack_84 < 1) {
      uStack_6c = 0xfffffffe;
      uVar8 = 1;
      iVar21 = 3;
    }
    else {
      uStack_6c = 0;
      iVar21 = 1;
      uVar8 = 0xffffffff;
    }
  }
  if ((int)(char)in_r0[iVar21 + 0x73] == 6) {
    GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,0x97);
  }
  else {
    GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,(int)(char)in_r0[iVar21 + 0x73]);
  }
  uVar14 = (uint)local_2c._2_2_;
  iVar13 = (int)((uint)(ushort)local_2c << 0x10) >> 0x10;
  iVar26 = ((*(int *)(**(int **)(iVar28 + iVar17) + 0x48) >> 1) + iStack_84) -
           ((int)((uint)(ushort)local_2c << 0x10) >> 0x11);
  if (uVar8 != 0) {
    iVar26 = iVar26 + uVar8 * 0x5f;
  }
  iVar22 = (int)(uVar14 << 0x10) >> 0x10;
  iVar23 = *(int *)(iVar28 + iVar16);
  iVar16 = __aeabi_idiv(iVar13 * iVar23,10);
  iVar9 = __aeabi_idiv(iVar22 * iVar23,10);
  iVar21 = (int)(char)in_r0[iVar21 + 0x73];
  if (iVar21 == 6) {
    iVar12 = *(int *)(*(int *)(pCVar7 + 8) + 8);
    iVar21 = 0x97;
  }
  else {
    iVar12 = *(int *)(*(int *)(pCVar7 + 8) + 8);
  }
  DrawImageProcess(*(CGxPZxZero **)(iVar21 * 4 + iVar12),
                   iVar26 + uStack_6c * ((iVar16 - iVar13) / 2),
                   (iVar19 - ((int)(uVar14 << 0x10) >> 0x11)) - (iVar9 - iVar22) / 2,1,iVar23,0);
LAB_001692a8:
  SetClipRect((*(int *)(**(int **)(iVar28 + iVar17) + 0x48) >> 1) + -0xa0,iVar6 + -100,0x140,200);
  uStack_6c = 0;
  if (in_r0[0x122] != (CBBGMenuRun)0x0) {
    uVar24 = *(undefined4 *)(in_r0 + 0x134);
    __aeabi_idivmod(uVar24,0x19);
    iVar13 = __aeabi_idiv(uVar24,0x19);
    uStack_6c = extraout_r1_02;
    if (iVar13 != 0) {
      uVar8 = iVar13 >> 0x1f;
      iVar19 = -2 - ((int)(uVar8 - iVar13) >> 0x1f);
      uVar8 = iVar13 + uVar8 ^ uVar8;
      if (uVar8 != 0) {
        iVar16 = 0;
        do {
          while( true ) {
            ArrayRotate(in_r0,psVar15,7,iVar19);
            ArrayRotate(in_r0,(signed *)(in_r0 + 0x80),7,iVar19);
            if (0 < iVar13) break;
            *(int *)(in_r0 + 0x134) = *(int *)(in_r0 + 0x134) + 0x19;
            iVar16 = iVar16 + 1;
            *(int *)(in_r0 + 300) = *(int *)(in_r0 + 300) + -0x19;
            SetMenuIdx(in_r0,'\0',1);
            if ((int)uVar8 <= iVar16) goto LAB_0016936c;
          }
          *(int *)(in_r0 + 0x134) = *(int *)(in_r0 + 0x134) + -0x19;
          *(int *)(in_r0 + 300) = *(int *)(in_r0 + 300) + 0x19;
          SetMenuIdx(in_r0,'\0',-1);
          iVar16 = iVar16 + 1;
        } while (iVar16 < (int)uVar8);
      }
    }
  }
LAB_0016936c:
  iVar13 = -3;
  *(short *)(in_r0 + 0x144) = (short)(*(int *)(**(int **)(iVar28 + iVar17) + 0x48) >> 1) + -0xa0;
  local_80 = (undefined2)(iVar6 + -100);
  *(undefined2 *)(in_r0 + 0x146) = local_80;
  *(undefined2 *)(in_r0 + 0x148) = 0x140;
  *(undefined2 *)(in_r0 + 0x14a) = 200;
  iVar19 = -0x4b;
  iVar21 = 0;
  iVar16 = DAT_001695ac;
  do {
    iVar26 = (int)*(char *)psVar15;
    if (iVar26 == -1) {
      CGsTouchMgr::AddKeyTouchRect(**(CGsTouchMgr ***)(iVar28 + iVar5),iVar16,iVar21,-10,1,1);
    }
    else {
      iVar9 = 0x11;
      if (iVar26 < 0x3e) {
LAB_001694a2:
        if (iVar26 == 0x67) {
LAB_001694a8:
          iVar9 = 2;
        }
      }
      else {
        iVar9 = 1;
        if (iVar26 != 0x5c) {
          if (iVar26 != 0x66) {
            iVar9 = 7;
            goto LAB_001694a2;
          }
          goto LAB_001694a8;
        }
      }
      if (1 < *(byte *)((int)psVar15 + 0xf)) {
        iVar22 = 0;
        if ((*(byte *)((int)psVar15 + 0xf) == 2) && (iVar22 = 3, -1 < iVar13)) {
          if (iVar13 == 0) {
            iVar22 = 0;
            goto LAB_001693d4;
          }
          iVar22 = -3;
          local_78 = *(ePZX *)(in_r0 + 0x14c);
          if (local_78 != -1) goto LAB_001693e0;
LAB_001694d8:
          iVar23 = *(int *)(in_r0 + 0x154);
        }
        else {
LAB_001693d4:
          local_78 = *(ePZX *)(in_r0 + 0x14c);
          if (local_78 == -1) goto LAB_001694d8;
LAB_001693e0:
          iVar23 = uStack_6c;
          if (local_78 == -2) goto LAB_001694d8;
        }
        if (iVar13 == 0) {
          local_78 = iVar26 + iVar9;
          if ((byte)(*(char *)psVar15 + 0x91U) < 3) {
            local_78 = (local_78 - iVar9) + 0x2f;
          }
          GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,local_78);
          piVar11 = *(int **)(iVar28 + iVar17);
          iVar23 = (iVar6 - ((int)(short)local_2c._2_2_ >> 1)) + iVar23;
          DrawPZX(pCVar7,local_78,0,
                  (*(int *)(*piVar11 + 0x48) >> 1) - ((int)(short)(ushort)local_2c >> 1),iVar23,0,0,
                  '\0','\x01');
          CGsTouchMgr::AddKeyTouchRect
                    (**(CGsTouchMgr ***)(iVar28 + iVar5),iVar16,
                     (*(int *)(*piVar11 + 0x48) >> 1) + -0xa0,iVar23 + -0xb,0x140,0x2a);
        }
        else {
          cVar3 = *(char *)((int)psVar15 + 7);
          GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar7,(int)cVar3);
          iVar26 = 8;
          if (iVar13 < 1) {
            iVar26 = -8;
          }
          iVar26 = (iVar6 - ((int)(short)local_2c._2_2_ >> 1)) + iVar19 + iVar22 + iVar23 + iVar26;
          DrawPZX(pCVar7,(int)cVar3,1,
                  (*(int *)(**(int **)(iVar28 + iVar17) + 0x48) >> 1) -
                  ((int)(short)(ushort)local_2c >> 1),iVar26 + 4,0,0,'\0','\x01');
          CGsTouchMgr::AddKeyTouchRect
                    (**(CGsTouchMgr ***)(iVar28 + iVar5),iVar16,
                     (*(int *)(**(int **)(iVar28 + iVar17) + 0x48) >> 1) + -0xa0,iVar26 + -4,0x140,
                     0x1a);
        }
      }
    }
    iVar21 = iVar21 + -10;
    psVar15 = (signed *)((int)psVar15 + 1);
    iVar16 = iVar16 + 1;
    iVar19 = iVar19 + 0x19;
    iVar13 = iVar13 + 1;
    if (iVar21 == -0x46) {
      IncDspSubMenu();
      ResetClipRect();
      return;
    }
  } while( true );
}


