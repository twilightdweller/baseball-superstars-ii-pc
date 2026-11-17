/* CBBGMenuRun::DRAW_HANDLER_MSTATE_RANKING at 0016c524; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::DRAW_HANDLER_MSTATE_RANKING() */

void CBBGMenuRun::DRAW_HANDLER_MSTATE_RANKING(void)

{
  byte bVar1;
  int iVar2;
  int in_r0;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  CGxPZxMgr *pCVar8;
  int iVar9;
  int iVar10;
  CBBGResMgr **ppCVar11;
  int iVar12;
  CGsTouchMgr **ppCVar13;
  int iVar14;
  int *piVar15;
  int local_88;
  ePZX local_74 [4];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  iVar2 = DAT_0016c8a0;
  iVar10 = DAT_0016c89c + 0x16c53a;
  local_2c = **(int **)(iVar10 + DAT_0016c8a0);
  iVar7 = *(int *)(in_r0 + 0x6c);
  *(undefined4 *)(iVar7 + 0x5c) = 0x11;
  *(undefined *)(iVar7 + 100) = 1;
  *(undefined *)(iVar7 + 0x65) = 1;
  *(undefined4 *)(iVar7 + 0x68) = 2;
  DRAW_HANDLER_MSTATE_MAIN();
  iVar7 = **(int **)(iVar10 + DAT_0016c8a4);
  uVar5 = *(undefined4 *)(iVar7 + 0x48);
  iVar14 = *(int *)(iVar7 + 0x4c);
  iVar7 = *(int *)(iVar7 + 0x3c);
  uVar3 = MC_grpGetPixelFromRGB(0,0,0);
  if (**(code ***)(iVar10 + DAT_0016c8a8) != (code *)0x0) {
    (***(code ***)(iVar10 + DAT_0016c8a8))(0,0,uVar5,iVar7 + iVar14,uVar3,5);
  }
  iVar7 = DAT_0016c8ac;
  CGsTouchMgr::ClearAllTouchRect();
  CGsTouchMgr::SetNoneKeyMapIndex();
  iVar14 = DAT_0016c8b0;
  ppCVar11 = *(CBBGResMgr ***)(iVar10 + DAT_0016c8b0);
  CBBGResMgr::GetPZxMgr(*ppCVar11,0x14);
  CBBGResMgr::GetPZxMgr(*ppCVar11,0x23);
  piVar15 = (int *)0x0;
  pCVar8 = *(CGxPZxMgr **)(**(int **)(iVar10 + DAT_0016c8b4) + 4);
  if (*(int *)(pCVar8 + 0xc) != 0) {
    piVar15 = *(int **)(*(int *)(*(int *)(pCVar8 + 0xc) + 8) + 0x188);
  }
  iVar9 = iVar10 + DAT_0016c8b8;
  local_74[0] = *(ePZX *)(iVar9 + 0x7c);
  local_74[1] = *(undefined4 *)(iVar9 + 0x80);
  local_74[2] = *(undefined4 *)(iVar9 + 0x84);
  local_74[3] = *(undefined4 *)(iVar9 + 0x88);
  uStack_64 = *(undefined4 *)(iVar9 + 0x8c);
  uStack_60 = *(undefined4 *)(iVar9 + 0x90);
  CBBGCommonMenu::DrawCommonSpecial
            (*(CBBGCommonMenu **)(in_r0 + 0x6c),0,'\x01',local_74[*(int *)(in_r0 + 0xc4)]);
  iVar9 = *(int *)(in_r0 + 0x6c);
  if (*(char *)(iVar9 + 0x34c) != '\0') {
    bVar1 = *(byte *)(iVar9 + DAT_0016c8bc);
    uVar6 = (uint)bVar1;
    if (uVar6 == 0) {
      iVar4 = (int)*(short *)(iVar9 + 0x360);
      iVar12 = (int)*(short *)(iVar9 + DAT_0016c8c0);
      SetClipRect(iVar4,iVar12,(int)*(short *)(iVar9 + 0x364),*(short *)(iVar9 + DAT_0016c8c4) + 0xf
                 );
      (**(code **)(*piVar15 + 0x10))(piVar15,iVar4,iVar12,0,0,0);
      local_54 = uVar6;
      local_50 = uVar6;
      CGxPZxFrame::GetBoundingBox((int)&local_54,(int)piVar15);
      local_5c = uVar6;
      local_58 = uVar6;
      GetPzxSize((CGxPZxMgr *)&local_5c,(int)pCVar8,local_74[*(int *)(in_r0 + 0xc4)]);
      DrawPZX(pCVar8,local_74[*(int *)(in_r0 + 0xc4)],1,
              ((int)(short)local_50 - (int)(short)local_58 >> 1) + iVar4 + (short)local_54,
              iVar12 + local_54._2_2_ + 1,0,0,bVar1,'\x01');
      CGxPZxFrame::GetBoundingBox((int)&local_54,(int)piVar15);
      uVar3 = CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar10 + iVar14),0x36,0x26);
      DrawFitTextBBF(local_54,local_50,uVar3,0x22,0,0,iVar4,iVar12,1);
      local_88 = 0x68;
      iVar14 = 0;
      do {
        CGxPZxFrame::GetBoundingBox((int)&local_54,(int)piVar15);
        CGxPZxFrame::GetBoundingBox((int)&local_5c,(int)piVar15);
        if (*(int *)(in_r0 + 0xbc) == iVar14) {
          DrawPZX(pCVar8,iVar14 * 2 + 0x69,1,(short)local_5c + iVar4,local_5c._2_2_ + iVar12,0,0,
                  '\0','\x01');
        }
        else {
          DrawPZX(pCVar8,local_88,1,(short)local_5c + iVar4,local_5c._2_2_ + iVar12,0,0,'\0','\x01')
          ;
        }
        ppCVar13 = *(CGsTouchMgr ***)(iVar10 + iVar7);
        iVar14 = iVar14 + 1;
        CGsTouchMgr::AddTouchRect
                  (*ppCVar13,(short)local_54 + iVar4,local_54._2_2_ + iVar12,(int)(short)local_50,
                   (int)local_50._2_2_,0);
        local_88 = local_88 + 2;
      } while (iVar14 != 3);
      CGxPZxFrame::GetBoundingBox((int)&local_54,(int)piVar15);
      CGsTouchMgr::AddTouchRect
                (*ppCVar13,(short)local_54 + iVar4,iVar12 + local_54._2_2_,(int)(short)local_50,
                 (int)local_50._2_2_,0);
      CGxPZxFrame::GetBoundingBox((int)&local_5c,(int)piVar15);
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      MC_knlSprintk(&local_4c,iVar10 + DAT_0016c8c8,in_r0 + 200);
      DrawFitTextBBF(local_5c,local_58,&local_4c,0x22,0,0,iVar4,iVar12,1);
      if (*(int *)(in_r0 + 0xc4) - 4U < 2) {
        iVar14 = 0x6f;
        uVar6 = 0;
        do {
          CGxPZxFrame::GetBoundingBox((int)&local_54,(int)piVar15);
          CGxPZxFrame::GetBoundingBox((int)&local_5c,(int)piVar15);
          if (*(byte *)(in_r0 + 0xc0) == uVar6) {
            DrawPZX(pCVar8,(uVar6 + 0x37) * 2,1,(short)local_5c + iVar4,local_5c._2_2_ + iVar12,0,0,
                    '\0','\x01');
          }
          else {
            DrawPZX(pCVar8,iVar14,1,(short)local_5c + iVar4,local_5c._2_2_ + iVar12,0,0,'\0','\x01')
            ;
          }
          uVar6 = uVar6 + 1;
          CGsTouchMgr::AddTouchRect
                    (**(CGsTouchMgr ***)(iVar10 + iVar7),(short)local_54 + iVar4,
                     local_54._2_2_ + iVar12,(int)(short)local_50,(int)local_50._2_2_,0);
          iVar14 = iVar14 + 2;
        } while (uVar6 != 2);
      }
      CGxPZxFrame::GetBoundingBox((int)&local_5c,(int)piVar15);
      if ((*(int *)(*(int *)(in_r0 + 0x6c) + 0x480) == 1) &&
         (0 < *(int *)(*(int *)(in_r0 + 0x6c) + DAT_0016caf8))) {
        DrawPZX(pCVar8,10,1,(short)local_5c + iVar4,local_5c._2_2_ + iVar12,0,0,'\0','\x01');
      }
      else {
        DrawPZX(pCVar8,8,1,(short)local_5c + iVar4,local_5c._2_2_ + iVar12,0,0,'\0','\x01');
      }
      CGxPZxFrame::GetBoundingBox((int)&local_5c,(int)piVar15);
      if ((*(int *)(*(int *)(in_r0 + 0x6c) + 0x480) == 2) &&
         (0 < *(int *)(*(int *)(in_r0 + 0x6c) + DAT_0016caf8))) {
        DrawPZX(pCVar8,0xb,1,(short)local_5c + iVar4,local_5c._2_2_ + iVar12,0,0,'\0','\x01');
      }
      else {
        DrawPZX(pCVar8,9,1,(short)local_5c + iVar4,local_5c._2_2_ + iVar12,0,0,'\0','\x01');
      }
      CGxPZxFrame::GetBoundingBox((int)&local_54,(int)piVar15);
      ppCVar13 = *(CGsTouchMgr ***)(iVar10 + iVar7);
      CGsTouchMgr::AddKeyTouchRect
                (*ppCVar13,0x188,(short)local_54 + iVar4,local_54._2_2_ + iVar12,
                 (int)(short)local_50,(int)local_50._2_2_);
      CGxPZxFrame::GetBoundingBox((int)&local_54,(int)piVar15);
      CGsTouchMgr::AddKeyTouchRect
                (*ppCVar13,DAT_0016caf4,(short)local_54 + iVar4,local_54._2_2_ + iVar12,
                 (int)(short)local_50,(int)local_50._2_2_);
      iVar7 = *(int *)(*(int *)(in_r0 + 0x6c) + DAT_0016caf8);
      if (0 < iVar7) {
        *(int *)(*(int *)(in_r0 + 0x6c) + DAT_0016caf8) = iVar7 + -1;
      }
      ResetClipRect();
      *(int *)(in_r0 + 0x1c) = *(int *)(in_r0 + 0x1c) + 1;
    }
  }
  if (local_2c == **(int **)(iVar10 + iVar2)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


