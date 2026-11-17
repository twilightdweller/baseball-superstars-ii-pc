/* CBBGMenuRun::EVENT_HANDLER_MSTATE_MAIN at 0016a6d0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EVENT_HANDLER_MSTATE_MAIN() */

void CBBGMenuRun::EVENT_HANDLER_MSTATE_MAIN(void)

{
  CBBGMenuRun *in_r0;
  int iVar1;
  CPopup *pCVar2;
  int iVar3;
  int iVar4;
  CPopup **ppCVar5;
  int iVar6;
  int iVar7;
  int local_40 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar6 = DAT_0016a9bc + 0x16a6e8;
  iVar7 = *(int *)(in_r0 + 0x30);
  if (in_r0[0x9d] == (CBBGMenuRun)0x0) {
    return;
  }
  iVar1 = CBBGCommonMenu::DoCheckRegistryHiddenOpen();
  if (iVar1 != 0) {
    return;
  }
  iVar3 = *(int *)(in_r0 + 0x90);
  iVar1 = iVar6 + DAT_0016a9c4;
  local_40[0] = *(int *)(iVar1 + 4);
  local_40[1] = *(undefined4 *)(iVar1 + 8);
  local_40[2] = *(undefined4 *)(iVar1 + 0xc);
  local_40[3] = *(undefined4 *)(iVar1 + 0x10);
  uStack_30 = *(undefined4 *)(iVar1 + 0x14);
  uStack_2c = *(undefined4 *)(iVar1 + 0x18);
  iVar4 = local_40[iVar3];
  iVar1 = (int)*(char *)(**(int **)(iVar6 + DAT_0016a9c8) + 0x25);
  if ((iVar1 != -1) && ((char)in_r0[0x72] <= iVar1)) {
    iVar7 = CheckTouchResult(in_r0,iVar1);
  }
  if (iVar7 == DAT_0016a9cc) goto LAB_0016a7ba;
  if (DAT_0016a9cc < iVar7) {
    if (iVar7 == DAT_0016a9f0) {
      if (in_r0[0x124] != (CBBGMenuRun)0x0) {
        iVar6 = CheckTouchResult(in_r0,0);
        if (iVar6 == -2) goto LAB_0016a886;
LAB_0016a882:
        if (iVar6 == -1) goto LAB_0016a886;
      }
    }
    else if (DAT_0016a9f0 < iVar7) {
      if (iVar7 == DAT_0016a9f4) goto LAB_0016a784;
      if (DAT_0016a9f4 < iVar7) {
        if (iVar7 == DAT_0016aa04) {
          if (in_r0[0x124] != (CBBGMenuRun)0x0) {
            iVar6 = CheckTouchResult(in_r0,5);
            if (iVar6 != -2) goto LAB_0016aac0;
            iVar6 = -2;
LAB_0016a886:
            *(int *)(in_r0 + 0x14c) = iVar6;
            goto LAB_0016a7c2;
          }
        }
        else if (iVar7 < DAT_0016aa04) {
          if (in_r0[0x124] != (CBBGMenuRun)0x0) {
            iVar6 = CheckTouchResult(in_r0,4);
            goto joined_r0x0016a87e;
          }
        }
        else if ((iVar7 == DAT_0016aa04 + 1) && (in_r0[0x124] != (CBBGMenuRun)0x0)) {
          iVar6 = CheckTouchResult(in_r0,6);
          if (iVar6 != -2) goto LAB_0016a882;
          goto LAB_0016a886;
        }
      }
      else if (iVar7 == 0x1960) {
        if (in_r0[0x124] != (CBBGMenuRun)0x0) {
          iVar6 = CheckTouchResult(in_r0,1);
          if (iVar6 == -2) {
            iVar6 = -2;
            goto LAB_0016a886;
          }
LAB_0016aac0:
          if (iVar6 == -1) {
            *(undefined4 *)(in_r0 + 0x14c) = 0xffffffff;
            goto LAB_0016a7c2;
          }
        }
      }
      else if ((iVar7 == DAT_0016a9f8) && (in_r0[0x124] != (CBBGMenuRun)0x0)) {
        iVar6 = CheckTouchResult(in_r0,2);
joined_r0x0016a87e:
        if (iVar6 == -2) {
          *(undefined4 *)(in_r0 + 0x14c) = 0xfffffffe;
          goto LAB_0016a7c2;
        }
        goto LAB_0016a882;
      }
    }
    else {
      if (iVar7 == DAT_0016a9f0 + -0x1f0) {
LAB_0016a7ba:
        in_r0[0x124] = (CBBGMenuRun)0x1;
        goto LAB_0016a7c2;
      }
      if (DAT_0016a9f0 + -0x1f0 < iVar7) {
        if ((iVar7 == DAT_0016a9e0) || (iVar7 == DAT_0016a9e0 + 1)) goto LAB_0016a7ba;
      }
      else {
        if (iVar7 == DAT_0016a9f0 + -0x1f2) goto LAB_0016a7ba;
        if (iVar7 == DAT_0016a9f0 + -0x1f1) {
          handleCletEvent(2,DAT_0016abd0,0);
          in_r0[0x124] = (CBBGMenuRun)0x1;
          goto LAB_0016a7c2;
        }
      }
    }
switchD_0016a7aa_caseD_6:
    if ((1 < iVar7 + 4U) && (iVar7 != 0x34)) goto LAB_0016a7c2;
  }
  else {
    if (iVar7 == DAT_0016a9d0) {
LAB_0016a982:
      in_r0[DAT_0016a9d8] = (CBBGMenuRun)0x1;
    }
    else {
      if (iVar7 <= DAT_0016a9d0) {
        if (iVar7 == DAT_0016a9d4) {
LAB_0016a784:
          if ((in_r0[DAT_0016a9d8] == (CBBGMenuRun)0x0) && (in_r0[0x124] == (CBBGMenuRun)0x0)) {
            return;
          }
          if (iVar4 - 8U < 6) {
                    /* WARNING: Could not emulate address calculation at 0x0016a7a6 */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)(*(int *)(iVar6 + DAT_0016a9dc + (iVar4 - 8U) * 4) + iVar6 + DAT_0016a9dc))();
            return;
          }
        }
        else if (DAT_0016a9d4 < iVar7) {
          if ((iVar7 == DAT_0016aa00) || (iVar7 == DAT_0016aa00 + 1)) goto LAB_0016a982;
        }
        else {
          if (iVar7 == -0x10) {
            if (iVar3 == 0) {
              iVar3 = CBBGDataMgr::GetOption();
              iVar1 = DAT_0016abd8;
              if (*(int *)(iVar3 + 0x48) == 1) {
                CBBGPopup::CreatePopup
                          (**(CBBGPopup ***)(iVar6 + DAT_0016abd8),(char *)(iVar6 + DAT_0016abec),
                           '\x02',(short)DAT_0016abe0,'\0',(char **)0x0,0,0);
              }
              else {
                CBBGPopup::CreatePopup
                          (**(CBBGPopup ***)(iVar6 + DAT_0016abd8),(char *)(iVar6 + DAT_0016abdc),
                           '\x02',(short)DAT_0016abe0,'\0',(char **)0x0,0,0);
              }
              CBBGPopup::SetTitle(**(char ***)(iVar6 + iVar1),iVar6 + DAT_0016abe4);
              ppCVar5 = *(CPopup ***)(iVar6 + DAT_0016abe8);
              pCVar2 = *ppCVar5;
              if (pCVar2 != (CPopup *)0x0) {
                pCVar2[4] = (CPopup)0x39;
                pCVar2 = *ppCVar5;
                if (pCVar2 != (CPopup *)0x0) {
                  CPopup::SetInitFocus(pCVar2,1);
                }
              }
            }
            else {
              InitMenuList(in_r0,0);
              InitMenuList(in_r0,1);
              CheckLastGameMode();
            }
            goto LAB_0016a7c2;
          }
          if (iVar7 == -5) goto LAB_0016a784;
        }
        goto switchD_0016a7aa_caseD_6;
      }
      if (iVar7 == DAT_0016a9fc) {
        if (in_r0[DAT_0016abcc] != (CBBGMenuRun)0x0) {
          *(undefined4 *)(in_r0 + 0x14c) = 0xfffffffd;
          *(undefined4 *)(in_r0 + 0x158) = 2;
          in_r0[0x70] = (CBBGMenuRun)0x1;
        }
      }
      else if (DAT_0016a9fc < iVar7) {
        if (iVar7 == DAT_0016abc8) {
          if (in_r0[DAT_0016abcc] != (CBBGMenuRun)0x0) {
            *(undefined4 *)(in_r0 + 0x14c) = 0xfffffffc;
            *(undefined4 *)(in_r0 + 0x158) = 3;
            in_r0[0x70] = (CBBGMenuRun)0x2;
          }
        }
        else {
          if (iVar7 == DAT_0016abc8 + 0x1f0) goto LAB_0016a7ba;
          if (iVar7 != DAT_0016abc8 + -1) goto switchD_0016a7aa_caseD_6;
          if (in_r0[DAT_0016abcc] != (CBBGMenuRun)0x0) {
            *(undefined4 *)(in_r0 + 0x14c) = 0xfffffffc;
            *(undefined4 *)(in_r0 + 0x158) = 3;
            in_r0[0x70] = (CBBGMenuRun)0x1;
          }
        }
      }
      else {
        if (iVar7 == DAT_0016a9fc + -0x1f1) goto LAB_0016a982;
        if (iVar7 != DAT_0016a9fc + -1) goto switchD_0016a7aa_caseD_6;
        if (in_r0[DAT_0016a9d8] != (CBBGMenuRun)0x0) {
          *(undefined4 *)(in_r0 + 0x14c) = 0xfffffffd;
          *(undefined4 *)(in_r0 + 0x158) = 2;
          in_r0[0x70] = (CBBGMenuRun)0x2;
        }
      }
    }
LAB_0016a7c2:
    if (((iVar7 != DAT_0016a9e4) &&
        (((iVar7 != 0x36 && (iVar7 != DAT_0016a9e4 + 3)) && (iVar7 != DAT_0016a9e4 + 1)))) &&
       (iVar7 != DAT_0016a9e4 + 4)) goto LAB_0016a7f6;
  }
  if ((in_r0[DAT_0016a9d8] != (CBBGMenuRun)0x0) &&
     (in_r0[0x9c] = (CBBGMenuRun)0x1, (char)in_r0[0x70] < '\x02')) {
    in_r0[0x70] = (CBBGMenuRun)0x1;
  }
LAB_0016a7f6:
  if ((((((uint)(iVar7 + DAT_0016a9e8) < 3) || (iVar7 == DAT_0016a9ec)) ||
       ((iVar7 == DAT_0016a9ec + 2 ||
        ((((iVar7 == DAT_0016a9ec + 1 || (iVar7 == 0x38)) || (iVar7 == 0x32)) ||
         ((iVar7 == -2 || (iVar7 == -1)))))))) && (in_r0[0x124] != (CBBGMenuRun)0x0)) &&
     (in_r0[0x9c] = (CBBGMenuRun)0x1, (char)in_r0[0x70] < '\x02')) {
    in_r0[0x70] = (CBBGMenuRun)0x1;
  }
  return;
}


