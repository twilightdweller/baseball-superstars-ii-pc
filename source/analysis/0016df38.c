/* CBBGMenuRun::EVENT_HANDLER_MSTATE_RANKING at 0016df38; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_RANKING() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_RANKING(void)

{
  void *in_r0;
  int iVar1;
  CPopup *pCVar2;
  CBBGOption *pCVar3;
  CBBGPopup *pCVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  CGsAutomata *this;
  char cVar8;
  byte bVar9;
  int iVar10;
  CBBGSatellite *pCVar11;
  CBBGPopup **ppCVar12;
  uint uVar13;
  char *pcVar14;
  CPopup **ppCVar15;
  CGsAutomata **ppCVar16;
  int iVar17;
  CBBGSatellite **ppCVar18;
  CBBGDataMgr **ppCVar19;
  bool bVar20;
  
  iVar6 = DAT_0016e618;
  iVar17 = DAT_0016e240;
  pcVar14 = (char *)(DAT_0016e23c + 0x16df4c);
  ppCVar16 = *(CGsAutomata ***)(pcVar14 + DAT_0016e240);
  iVar1 = *(int *)((int)in_r0 + 0x30);
  iVar10 = *(int *)((int)in_r0 + 8);
  this = *ppCVar16;
  if (iVar10 == 0x65) {
    CBBGCommonMenu::InitializeAutomaWindow
              (*(CBBGCommonMenu **)((int)in_r0 + 0x6c),3,8,'\x01','\x01');
    CBBGPopup::CreatePopupCb
              (**(CBBGPopup ***)(pcVar14 + DAT_0016e25c),0xa2,
               *(_func_void_void_ptr **)(pcVar14 + DAT_0016e260),
               *(_func_void_void_ptr_int **)(pcVar14 + DAT_0016e264),in_r0,'\0');
    ppCVar15 = *(CPopup ***)(pcVar14 + DAT_0016e268);
    pCVar2 = *ppCVar15;
    if (pCVar2 == (CPopup *)0x0) {
      return;
    }
    CPopup::SetTitle(pCVar2,pcVar14 + DAT_0016e26c,2);
    pCVar2 = *ppCVar15;
    if (pCVar2 == (CPopup *)0x0) {
      return;
    }
    pCVar2[DAT_0016e270] = (CPopup)0x1;
    return;
  }
  if (0x65 < iVar10) {
    if (iVar10 == 0x67) {
      ppCVar18 = *(CBBGSatellite ***)(pcVar14 + DAT_0016e248);
      if (*(int *)(*ppCVar18 + 0xa4) != 1) {
        return;
      }
      pCVar3 = (CBBGOption *)CBBGDataMgr::GetOption();
      CBBGOption::SetUserName(pCVar3,(char *)(*ppCVar16 + 0x28));
      CBBGDataMgr::SaveOption();
      ppCVar12 = *(CBBGPopup ***)(pcVar14 + DAT_0016e25c);
      pCVar4 = *ppCVar12;
      pcVar5 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(pcVar14 + DAT_0016e274),0x36,0x2d);
      CBBGPopup::CreatePopup(pCVar4,pcVar5,'\x01',(short)DAT_0016e27c,'\0',(char **)0x0,0,0);
      CBBGPopup::SetTitle((char *)*ppCVar12,(int)(pcVar14 + DAT_0016e26c));
      CBBGPopup::SetAutoClose();
      *(undefined4 *)((int)in_r0 + 8) = 0;
      CGsAutomata::DeleteTextAll();
      CBBGSatellite::Disconnect(*ppCVar18,'\0');
      CGsSound::Resume();
      return;
    }
    if (iVar10 < 0x67) {
      if (**(char **)(pcVar14 + DAT_0016e244) != -1) {
        if (**(char **)(pcVar14 + DAT_0016e244) != '\0') {
          return;
        }
        ppCVar18 = *(CBBGSatellite ***)(pcVar14 + DAT_0016e248);
        CBBGSatellite::SetUserName(*ppCVar18,(char *)(this + 0x28));
        pCVar11 = *ppCVar18;
        *(undefined4 *)(pCVar11 + 0xb4) = *(undefined4 *)(pcVar14 + DAT_0016e24c);
        *(void **)(pCVar11 + 0xb8) = in_r0;
        CGsSound::Suspend();
        *(int *)((int)in_r0 + 8) = *(int *)((int)in_r0 + 8) + 1;
        CBBGSatellite::Connect(*ppCVar18,100,0);
        return;
      }
LAB_0016e238:
      iVar17 = 0;
    }
    else {
      if (iVar10 != 0xc9) {
        return;
      }
      iVar17 = **(int **)(pcVar14 + DAT_0016e248);
      if (*(int *)(iVar17 + 0xa4) == 1) {
        if (*(char *)(iVar17 + DAT_0016e614) == '\x01') {
          iVar1 = CBBGDataMgr::GetOption();
          *(undefined *)(iVar1 + 0x204) = 1;
          iVar1 = CBBGDataMgr::GetOption();
          if (*(int *)(iVar1 + 0x48) == 1) {
            CBBGModeUiMgr::CreateNormalPopup
                      (*(CBBGModeUiMgr **)((int)in_r0 + 0x108),pcVar14 + DAT_0016e7bc,1,1);
          }
          else {
            CBBGModeUiMgr::CreateNormalPopup
                      (*(CBBGModeUiMgr **)((int)in_r0 + 0x108),pcVar14 + DAT_0016e638,1,1);
          }
          ppCVar19 = *(CBBGDataMgr ***)(pcVar14 + iVar6);
          pCVar3 = (CBBGOption *)CBBGDataMgr::GetOption();
          CBBGOption::AddGPoint(pCVar3,DAT_0016e63c);
          CBBGDataMgr::AddRegistryGainGPoint(*ppCVar19,10,DAT_0016e63c);
          CBBGDataMgr::SaveRegistry((uchar)*ppCVar19);
          *(undefined *)(iVar17 + DAT_0016e614) = 0;
        }
        else {
          iVar6 = CBBGDataMgr::GetOption();
          if (*(char *)(iVar6 + 0x204) == '\0') {
            iVar6 = CBBGDataMgr::GetOption();
            *(undefined *)(iVar6 + 0x204) = 1;
          }
        }
        iVar6 = CBBGDataMgr::GetOption();
        if (*(char *)(iVar6 + 0x58) == '\0') {
          if (*(char *)(iVar17 + DAT_0016e61c) == '\0') {
            *(undefined4 *)((int)in_r0 + 8) = 100;
          }
          else {
            pCVar3 = (CBBGOption *)CBBGDataMgr::GetOption();
            CBBGOption::SetUserName(pCVar3,(char *)(iVar17 + DAT_0016e7b8));
          }
        }
      }
      iVar17 = (int)**(char **)(pcVar14 + DAT_0016e244);
      if (iVar17 != 0) {
        return;
      }
    }
    iVar6 = *(int *)((int)in_r0 + 0x6c);
    *(int *)((int)in_r0 + 8) = iVar17;
LAB_0016e0de:
    *(undefined *)(iVar6 + DAT_0016e258) = 1;
    CBBState::ReserveState((CBBState *)((int)in_r0 + 8),7);
    return;
  }
  if (iVar10 != 0) {
    if (iVar10 != 100) {
      return;
    }
    if (*(char *)(*(int *)((int)in_r0 + 0x6c) + 0x34c) == '\0') {
      return;
    }
    ppCVar12 = *(CBBGPopup ***)(pcVar14 + DAT_0016e25c);
    pCVar4 = *ppCVar12;
    pcVar5 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(pcVar14 + DAT_0016e274),0x36,0x2c);
    CBBGPopup::CreatePopup(pCVar4,pcVar5,'\x01',0x15b,'\0',(char **)0x0,0,0);
    CBBGPopup::SetTitle((char *)*ppCVar12,(int)(pcVar14 + DAT_0016e26c));
    *(int *)((int)in_r0 + 8) = *(int *)((int)in_r0 + 8) + 1;
    return;
  }
  iVar6 = (int)*(char *)(**(int **)(pcVar14 + DAT_0016e254) + 0x25);
  if (iVar6 != -1) {
    if (*(char *)((int)in_r0 + 0xb9) != '\x01') {
      CGsAutomata::SetText(this,(char *)((int)in_r0 + 200));
    }
    if (iVar6 < 3) {
      *(char *)((int)in_r0 + 200) = '\0';
      *(undefined *)((int)in_r0 + 0xc9) = 0;
      *(undefined *)((int)in_r0 + 0xca) = 0;
      *(undefined *)((int)in_r0 + 0xcb) = 0;
      *(undefined *)((int)in_r0 + 0xcc) = 0;
      *(undefined *)((int)in_r0 + 0xcd) = 0;
      *(undefined *)((int)in_r0 + 0xce) = 0;
      *(undefined *)((int)in_r0 + 0xcf) = 0;
      *(undefined *)((int)in_r0 + 0xd0) = 0;
      *(undefined *)((int)in_r0 + 0xd1) = 0;
      *(undefined *)((int)in_r0 + 0xd2) = 0;
      *(undefined *)((int)in_r0 + 0xd3) = 0;
      strcpy((char *)((int)in_r0 + 200),(char *)(this + 0x28));
      *(int *)((int)in_r0 + 0xbc) = iVar6;
      FUN_0016e00c();
      return;
    }
    if (iVar6 != 3) {
      if ((iVar6 < 6) && (*(int *)((int)in_r0 + 0xc4) - 4U < 2)) {
        if (iVar6 == 4) {
          *(undefined *)((int)in_r0 + 0xc0) = 1;
          *(undefined4 *)((int)in_r0 + 0xc4) = 4;
          FUN_0016e00c();
          return;
        }
        *(undefined *)((int)in_r0 + 0xc0) = 0;
        *(undefined4 *)((int)in_r0 + 0xc4) = 5;
      }
      goto code_r0x0016e00c;
    }
    if (1 < *(int *)((int)in_r0 + 0xbc) - 1U) {
      FUN_0016e00c();
      return;
    }
    CGsTouchMgr::ClearAllTouchRect();
    iVar1 = CBBGDataMgr::GetOption();
    iVar6 = DAT_0016e7d0;
    iVar17 = DAT_0016e640;
    if (*(int *)(iVar1 + 0x48) != 1) {
      iVar6 = *(int *)((int)in_r0 + 0x6c);
      *(undefined *)(iVar6 + DAT_0016e640) = 1;
      *(undefined *)(iVar6 + iVar17 + 2) = 1;
      *(undefined *)(iVar6 + iVar17 + 3) = 1;
      *(undefined *)(iVar6 + iVar17 + 1) = 1;
      CGsOemIME::SetCallOem
                (**(CGsOemIME ***)(pcVar14 + DAT_0016e620),(char *)(this + 0x28),9,0,
                 *(_func_void_void_ptr_char_ptr_int **)(pcVar14 + DAT_0016e644),'\x01','\x01','\x01'
                 ,'\x01',(void *)0x0);
      FUN_0016e00c();
      return;
    }
    iVar17 = *(int *)((int)in_r0 + 0x6c);
    *(undefined *)(iVar17 + DAT_0016e7d0) = 1;
    *(undefined *)(iVar17 + iVar6 + 2) = 1;
    *(undefined *)(iVar17 + iVar6 + 3) = 1;
    *(undefined *)(iVar17 + iVar6 + 1) = 1;
    CGsOemIME::SetCallOem
              (**(CGsOemIME ***)(pcVar14 + DAT_0016e7d4),(char *)(this + 0x28),9,2,
               *(_func_void_void_ptr_char_ptr_int **)(pcVar14 + DAT_0016e7d8),'\x01','\x01','\x01',
               '\x01',(void *)0x0);
    FUN_0016e00c();
LAB_0016e79e:
    iVar17 = FilterAutomataSymbol(pcVar14);
    if (iVar17 != 0) {
      return;
    }
LAB_0016e726:
    uVar13 = (uint)*(byte *)((int)in_r0 + 0xb9);
LAB_0016e3a6:
    *(char *)((int)in_r0 + 0xb9) = (char)(uVar13 - 1);
    iVar17 = (uVar13 - 1) * 0x1000000;
    if ((1 < *(int *)((int)in_r0 + 0xc4) - 4U) && (iVar17 >> 0x18 == 2)) {
      *(undefined *)((int)in_r0 + 0xb9) = 1;
      iVar17 = 0x1000000;
    }
    iVar17 = iVar17 >> 0x18;
    if (*(int *)((int)in_r0 + 0xbc) == 0) {
      if (iVar17 != 1) {
        return;
      }
      *(undefined *)((int)in_r0 + 0xb9) = 0;
      return;
    }
    if (iVar17 != 1) {
      return;
    }
LAB_0016e68a:
    this[4] = SUB41(iVar17,0);
    CGsAutomata::SetText(this,(char *)((int)in_r0 + 200));
    return;
  }
code_r0x0016e00c:
  if (iVar1 == 0x6e) {
    pcVar5 = (char *)CGsOemIME::GetText(**(CGsOemIME ***)(pcVar14 + DAT_0016e620),false);
    ppCVar16 = *(CGsAutomata ***)(pcVar14 + iVar17);
    CGsAutomata::DeleteTextAll();
    CGsAutomata::SetText(*ppCVar16,pcVar5);
    *(char *)((int)in_r0 + 200) = '\0';
    *(undefined *)((int)in_r0 + 0xc9) = 0;
    *(undefined *)((int)in_r0 + 0xca) = 0;
    *(undefined *)((int)in_r0 + 0xcb) = 0;
    *(undefined *)((int)in_r0 + 0xcc) = 0;
    *(undefined *)((int)in_r0 + 0xcd) = 0;
    *(undefined *)((int)in_r0 + 0xce) = 0;
    *(undefined *)((int)in_r0 + 0xcf) = 0;
    *(undefined *)((int)in_r0 + 0xd0) = 0;
    *(undefined *)((int)in_r0 + 0xd1) = 0;
    *(undefined *)((int)in_r0 + 0xd2) = 0;
    *(undefined *)((int)in_r0 + 0xd3) = 0;
    strcpy((char *)((int)in_r0 + 200),(char *)(this + 0x28));
    return;
  }
  if (iVar1 == 0x34) {
LAB_0016e4a2:
    cVar8 = *(char *)((int)in_r0 + 0xb9);
    if (cVar8 == '\0') {
      uVar13 = *(int *)((int)in_r0 + 0xbc) - 1;
      *(uint *)((int)in_r0 + 0xbc) = uVar13 & (int)~uVar13 >> 0x1f;
      return;
    }
  }
  else {
    if (iVar1 < 0x35) {
      if (iVar1 == -3) goto LAB_0016e4a2;
      if (iVar1 != -3 && iVar1 + 3 < 0 == SCARRY4(iVar1,3)) {
        if (iVar1 != -1) {
          if (iVar1 + 1 < 0 != SCARRY4(iVar1,1)) {
LAB_0016e044:
            cVar8 = *(char *)((int)in_r0 + 0xb9);
            if ((iVar1 == 0x38) && (cVar8 == '\x01')) {
              return;
            }
            if ('\x02' < cVar8) {
              return;
            }
            if (cVar8 == '\x01') {
              pcVar14 = (char *)((int)in_r0 + 200);
              memset(pcVar14,0,0xc);
              strcpy(pcVar14,(char *)(this + 0x28));
              if ((*(char *)((int)in_r0 + 200) != '\0') &&
                 (iVar17 = FilterAutomataSymbol(pcVar14), iVar17 != 0)) {
                return;
              }
              cVar8 = *(char *)((int)in_r0 + 0xb9);
            }
            *(byte *)((int)in_r0 + 0xb9) = cVar8 + 1U;
            iVar17 = (uint)(byte)(cVar8 + 1U) << 0x18;
            if ((*(int *)((int)in_r0 + 0xbc) == 0) && (iVar17 >> 0x18 == 1)) {
              *(undefined *)((int)in_r0 + 0xb9) = 2;
              iVar17 = 0x2000000;
            }
            iVar17 = iVar17 >> 0x18;
            if ((1 < *(int *)((int)in_r0 + 0xc4) - 4U) && (iVar17 == 2)) {
              *(undefined *)((int)in_r0 + 0xb9) = 3;
LAB_0016e0a0:
              *(undefined *)((int)in_r0 + 0xc1) = 0;
              return;
            }
            if (iVar17 != 1) {
              if (iVar17 != 3) {
                return;
              }
              goto LAB_0016e0a0;
            }
            iVar17 = 1;
            goto LAB_0016e68a;
          }
          if (iVar1 != 0x32) {
            return;
          }
        }
        uVar13 = (uint)*(byte *)((int)in_r0 + 0xb9);
        bVar20 = (int)(uVar13 * 0x1000000) >> 0x18 == 1;
        if ((iVar1 == 0x32) && (bVar20)) {
          return;
        }
        if (uVar13 == 0 || (int)(uVar13 * 0x1000000) < 0) {
          return;
        }
        if (bVar20) {
          pcVar14 = (char *)((int)in_r0 + 200);
          memset(pcVar14,0,0xc);
          strcpy(pcVar14,(char *)(this + 0x28));
          if (*(char *)((int)in_r0 + 200) != '\0') goto LAB_0016e79e;
          goto LAB_0016e726;
        }
        goto LAB_0016e3a6;
      }
      if (iVar1 == -5) {
LAB_0016e40a:
        if (*(char *)((int)in_r0 + 0xb9) != '\x03') {
          return;
        }
        if (*(char *)((int)in_r0 + 0xc1) == '\0') {
          if ((*(int *)((int)in_r0 + 0xbc) == 0) || (*(char *)((int)in_r0 + 200) != '\0')) {
            if (*(uint *)((int)in_r0 + 0xc4) < 6) {
                    /* WARNING: Could not emulate address calculation at 0x0016e440 */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)(pcVar14 +
                        *(int *)(pcVar14 + *(uint *)((int)in_r0 + 0xc4) * 4 + DAT_0016e62c) +
                        DAT_0016e62c))();
              return;
            }
LAB_0016e448:
            CBBGSatellite::SetRank
                      (**(CBBGSatellite ***)(pcVar14 + DAT_0016e630),0,
                       (int)(char)*(undefined4 *)((int)in_r0 + 0xbc),(char *)((int)in_r0 + 200));
            pCVar3 = (CBBGOption *)CBBGDataMgr::GetOption();
            CBBGOption::SetGroupName(pCVar3,(char *)((int)in_r0 + 200));
            CBBGDataMgr::SaveOption();
            CBBState::ReserveState((CBBState *)((int)in_r0 + 8),0x24);
            return;
          }
LAB_0016e6d2:
          ppCVar12 = *(CBBGPopup ***)(pcVar14 + DAT_0016e7c0);
          pCVar4 = *ppCVar12;
          pcVar5 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(pcVar14 + DAT_0016e7c4),0x36,0xee);
          CBBGPopup::CreatePopup(pCVar4,pcVar5,'\x01',(short)DAT_0016e7c8,'\0',(char **)0x0,0,0);
          CBBGPopup::SetTitle((char *)*ppCVar12,(int)(pcVar14 + DAT_0016e7cc));
          return;
        }
        goto LAB_0016e238;
      }
      if (iVar1 == -5 || iVar1 + 5 < 0 != SCARRY4(iVar1,5)) {
        if (iVar1 != -0x10) {
          return;
        }
        goto LAB_0016e238;
      }
    }
    else {
      if (iVar1 == 0x188) {
        iVar17 = *(int *)((int)in_r0 + 0x6c);
        uVar7 = 1;
LAB_0016e3fe:
        *(undefined4 *)(iVar17 + 0x480) = uVar7;
        *(undefined4 *)(*(int *)((int)in_r0 + 0x6c) + DAT_0016e628) = 4;
        return;
      }
      if (0x188 < iVar1) {
        if (iVar1 == 0x37c) {
          if (*(int *)(*(int *)((int)in_r0 + 0x6c) + 0x480) != 1) {
            return;
          }
          if ((*(int *)((int)in_r0 + 0xbc) == 0) || (*(char *)((int)in_r0 + 200) != '\0')) {
            if (*(uint *)((int)in_r0 + 0xc4) < 6) {
                    /* WARNING: Could not emulate address calculation at 0x0016e518 */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)(pcVar14 +
                        *(int *)(pcVar14 + *(uint *)((int)in_r0 + 0xc4) * 4 + DAT_0016e634) +
                        DAT_0016e634))();
              return;
            }
            goto LAB_0016e448;
          }
          goto LAB_0016e6d2;
        }
        if (iVar1 != DAT_0016e624) {
          if (iVar1 != DAT_0016e624 + -500) {
            return;
          }
          iVar17 = *(int *)((int)in_r0 + 0x6c);
          uVar7 = 2;
          goto LAB_0016e3fe;
        }
        iVar6 = *(int *)((int)in_r0 + 0x6c);
        if (*(int *)(iVar6 + 0x480) != 2) {
          return;
        }
        *(undefined4 *)((int)in_r0 + 8) = 0;
        goto LAB_0016e0de;
      }
      if (iVar1 != 0x36) {
        if (0x35 < iVar1) {
          if (iVar1 != 0x38) {
            return;
          }
          goto LAB_0016e044;
        }
        goto LAB_0016e40a;
      }
    }
    cVar8 = *(char *)((int)in_r0 + 0xb9);
    if (cVar8 == '\0') {
      iVar17 = *(int *)((int)in_r0 + 0xbc) + 1;
      if (2 < iVar17) {
        iVar17 = 2;
      }
      *(int *)((int)in_r0 + 0xbc) = iVar17;
      return;
    }
  }
  if (cVar8 != '\x02') {
    if (cVar8 != '\x03') {
      return;
    }
    *(byte *)((int)in_r0 + 0xc1) = *(byte *)((int)in_r0 + 0xc1) ^ 1;
    return;
  }
  bVar9 = *(byte *)((int)in_r0 + 0xc0) ^ 1;
  *(byte *)((int)in_r0 + 0xc0) = bVar9;
  if (bVar9 != 0) {
    *(undefined4 *)((int)in_r0 + 0xc4) = 4;
    return;
  }
  *(undefined4 *)((int)in_r0 + 0xc4) = 5;
  return;
}


