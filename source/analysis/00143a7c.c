/* CBBStartUp::OnEvent at 00143a7c; decompiler output, not buildable source */

/* CBBStartUp::OnEvent(int, int, int) */

undefined4 __thiscall CBBStartUp::OnEvent(CBBStartUp *this,int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  CBBGSeasonRun *this_00;
  CBBTimer *this_01;
  CBBGOption *this_02;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = DAT_00143da4 + 0x143a92;
  if ((param_1 == 2) && ((param_2 == -0x10 || (param_2 == -8)))) {
    iVar6 = *(int *)(**(int **)(iVar6 + DAT_00143da8) + 0x3a8);
    if ((iVar6 != 0xe) && (iVar6 != 0x13)) {
      return 1;
    }
    (**(code **)(*(int *)this + 0x18))(this,0xfffffff0);
    return 1;
  }
  uVar1 = CGxFrameT1::OnEvent((CGxFrameT1 *)this,param_1,param_2,param_3);
  iVar3 = DAT_00143da8;
  piVar2 = *(int **)(this + 0x80);
  if (piVar2 == (int *)0x0) {
    return uVar1;
  }
  if (param_1 == 0x20) {
    if ((param_2 != 2) && (param_2 == 1)) {
      CBBGDataMgr::SaveRegistry((uchar)**(undefined4 **)(iVar6 + DAT_00143dac));
      CBBGDataMgr::SaveOption();
      iVar3 = DAT_00143db0;
      piVar2 = *(int **)(iVar6 + DAT_00143db0);
      CBBGCommonMenu::ApplyBuyPaidItem
                (**(CBBGCommonMenu ***)(iVar6 + DAT_00143da8),(int)*(char *)(*piVar2 + DAT_00143db4)
                );
      if ((*(int *)(this + 0x80) != 0) &&
         (this_00 = *(CBBGSeasonRun **)(*(int *)(this + 0x80) + 8), this_00 != (CBBGSeasonRun *)0x0)
         ) {
        if (**(int **)(iVar6 + DAT_00143db8) - 3U < 2) {
          CBBGRaiseRun::ApplyBuyPaidItem
                    ((CBBGRaiseRun *)this_00,(int)*(char *)(*piVar2 + DAT_00143db4));
        }
        else if (**(int **)(iVar6 + DAT_00143db8) == 2) {
          CBBGSeasonRun::ApplyBuyPaidItem(this_00,(int)*(char *)(*piVar2 + DAT_00143db4));
        }
      }
      CBBGTimer::GetInstance();
      CBBTimer::RemoveCallBackData();
      this_01 = (CBBTimer *)CBBGTimer::GetInstance();
      CBBTimer::AddCallbackData(this_01,200);
      CBBGSatellite::Connect(**(CBBGSatellite ***)(iVar6 + iVar3),0x68,0);
      piVar2 = *(int **)(this + 0x80);
    }
    goto LAB_00143aca;
  }
  if (param_1 == 0x23) goto LAB_00143aca;
  if (param_1 == 0x21) {
    piVar2 = *(int **)(iVar6 + DAT_00143da8);
    *(undefined *)(*piVar2 + DAT_00143dc0) = 0;
    CGsSound::Resume();
    iVar4 = *piVar2;
    iVar5 = *(int *)(iVar4 + 0x3a8);
    *(undefined *)(iVar4 + DAT_00143dbc) = 1;
    uVar7 = 0xe;
    if (*(int *)(**(int **)(iVar6 + iVar3) + 0x3ac) == 0x13) {
      uVar7 = 0x13;
    }
    sendAndroidEvent(0x192);
    changeUIStatus(uVar7);
    iVar6 = **(int **)(iVar6 + iVar3);
    *(undefined4 *)(iVar6 + 0x3ac) = *(undefined4 *)(iVar6 + 0x3a8);
    *(undefined4 *)(iVar6 + 0x3a8) = uVar7;
    if (iVar5 == 0x22 || iVar5 == 0x23) {
      (**(code **)(*(int *)this + 0x18))(this,0xfffffff0);
      piVar2 = *(int **)(this + 0x80);
      goto LAB_00143aca;
    }
  }
  else {
    if (param_1 == 0x28) {
      sendAndroidEvent(0x192);
      CBBGCommonMenu::SendBuyItemLog(**(CBBGCommonMenu ***)(iVar6 + DAT_00143da8),param_2);
      piVar2 = *(int **)(this + 0x80);
      goto LAB_00143aca;
    }
    if (param_1 != 0x29) goto LAB_00143aca;
    if (param_2 == 1) {
      iVar3 = CBBGDataMgr::GetOption();
      *(undefined4 *)(iVar3 + 0x214) = 0;
      CBBGDataMgr::SaveOption();
      iVar3 = DAT_00143da8;
      piVar2 = *(int **)(iVar6 + DAT_00143da8);
      *(undefined *)(*piVar2 + DAT_00143dbc) = 1;
    }
    else {
      if (param_2 != 2) {
        if (param_2 == 3) {
          piVar2 = *(int **)(iVar6 + DAT_00143da8);
          *(undefined *)(*piVar2 + DAT_00143dbc) = 1;
          uVar7 = 0xe;
          if (*(int *)(*piVar2 + 0x3ac) == 0x13) {
            uVar7 = 0x13;
          }
          sendAndroidEvent(0x192);
          changeUIStatus(uVar7);
          piVar2 = *(int **)(iVar6 + iVar3);
          iVar6 = *piVar2;
          *(undefined4 *)(iVar6 + 0x3ac) = *(undefined4 *)(iVar6 + 0x3a8);
          *(undefined4 *)(iVar6 + 0x3a8) = uVar7;
          (**(code **)(*(int *)this + 0x18))(this,0xfffffff0);
          *(undefined *)(*piVar2 + DAT_00143dc0) = 0;
          piVar2 = *(int **)(this + 0x80);
          goto LAB_00143aca;
        }
        if (param_2 == 4) {
          piVar2 = *(int **)(iVar6 + DAT_00143da8);
          iVar6 = *piVar2;
          uVar7 = *(undefined4 *)(iVar6 + 0x3a8);
          *(undefined4 *)(iVar6 + 0x3ac) = uVar7;
          *(undefined4 *)(iVar6 + 0x3a8) = 0xe;
          (**(code **)(*(int *)this + 0x18))(this,0xfffffff0);
          iVar6 = *piVar2;
          *(undefined4 *)(iVar6 + 0x3ac) = *(undefined4 *)(iVar6 + 0x3a8);
          *(undefined4 *)(iVar6 + 0x3a8) = uVar7;
          piVar2 = *(int **)(this + 0x80);
          goto LAB_00143aca;
        }
        if (param_2 == 5) {
          this_02 = (CBBGOption *)CBBGDataMgr::GetOption();
          CBBGOption::AddGPoint(this_02,param_3);
        }
        goto LAB_00143c4a;
      }
      piVar2 = *(int **)(iVar6 + DAT_00143da8);
      *(undefined *)(*piVar2 + DAT_00143dbc) = 1;
    }
    uVar7 = 0xe;
    if (*(int *)(*piVar2 + 0x3ac) == 0x13) {
      uVar7 = 0x13;
    }
    sendAndroidEvent(0x192);
    changeUIStatus(uVar7);
    iVar6 = **(int **)(iVar6 + iVar3);
    *(undefined4 *)(iVar6 + 0x3ac) = *(undefined4 *)(iVar6 + 0x3a8);
    *(undefined4 *)(iVar6 + 0x3a8) = uVar7;
  }
LAB_00143c4a:
  piVar2 = *(int **)(this + 0x80);
LAB_00143aca:
  (**(code **)(*piVar2 + 0x1c))(piVar2,param_1,param_2,param_3);
  return uVar1;
}


