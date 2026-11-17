/* CBBGMenuRun::INIT_HANDLER_MSTATE_MAIN at 00169ca8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_MAIN() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_MAIN(void)

{
  CBBGMenuRun *in_r0;
  CGxPZxAni *pCVar1;
  int iVar2;
  CBBGResMgr **ppCVar3;
  int iVar4;
  
  iVar4 = DAT_00169da0 + 0x169cb4;
  if (*(int *)(in_r0 + 0x18) == 6) {
    in_r0[0x87] = (CBBGMenuRun)0x6;
    CBBGCommonMenu::ScreenCapture(*(CBBGCommonMenu **)(in_r0 + 0x6c),'\x01','\x01');
    InitMenuList(in_r0,0);
    InitMenuList(in_r0,1);
    iVar2 = *(int *)(in_r0 + 0x6c);
    *(undefined *)(iVar2 + 0x60) = 1;
    *(undefined2 *)(iVar2 + 0x62) = 1;
    *(undefined4 *)(in_r0 + 0x150) = 1;
    *(undefined4 *)(in_r0 + 0x154) = 0;
    *(undefined4 *)(in_r0 + 0x158) = 1;
    *(undefined4 *)(in_r0 + 0x14c) = 0;
    CheckLastGameMode();
    hideTitleComponent();
  }
  ppCVar3 = *(CBBGResMgr ***)(iVar4 + DAT_00169da4);
  iVar2 = 2;
  pCVar1 = (CGxPZxAni *)CBBGResMgr::GetAni(*ppCVar3,0x12,0);
  CGxPZxAni::Stop(pCVar1,true);
  pCVar1 = (CGxPZxAni *)CBBGResMgr::GetAni(*ppCVar3,0x12,0);
  CGxPZxAni::Play(pCVar1,false);
  pCVar1 = (CGxPZxAni *)CBBGResMgr::GetAni(*ppCVar3,0x12,1);
  CGxPZxAni::Stop(pCVar1,true);
  pCVar1 = (CGxPZxAni *)CBBGResMgr::GetAni(*ppCVar3,0x12,1);
  CGxPZxAni::Play(pCVar1,true);
  do {
    pCVar1 = (CGxPZxAni *)CBBGResMgr::GetAni(*ppCVar3,0x12,iVar2);
    CGxPZxAni::Stop(pCVar1,true);
    pCVar1 = (CGxPZxAni *)CBBGResMgr::GetAni(*ppCVar3,0x12,iVar2);
    iVar2 = iVar2 + 1;
    CGxPZxAni::Play(pCVar1,true);
  } while (iVar2 != 9);
  iVar4 = *(int *)(**(int **)(iVar4 + DAT_00169da8) + DAT_00169dac);
  if (0x1d < CONCAT11(*(undefined *)(iVar4 + DAT_00169db0),*(undefined *)(iVar4 + 0x174))) {
    CBBGCommonMenu::DoHiddenOpen(*(CBBGCommonMenu **)(in_r0 + 0x6c),0x38,true);
  }
  CBBGCommonMenu::CheckSpecialRecord();
  return;
}


