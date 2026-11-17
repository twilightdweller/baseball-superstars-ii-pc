/* CBBGMenuRun::Run at 00172318; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::Run() */

void CBBGMenuRun::Run(void)

{
  int *in_r0;
  int iVar1;
  int iVar2;
  CGsParticleMgr **ppCVar3;
  
  iVar2 = DAT_001723cc + 0x172326;
  if (*(char *)(in_r0 + 8) != '\0') {
    EndProcess();
  }
  CBBState::CheckState();
  CBBState::CheckKeyState();
  if (*(char *)((int)in_r0 + 0x21) != '\0') {
    CGsTouchMgr::ClearAllTouchRect();
    StartProcess();
    *(undefined *)((int)in_r0 + 0x21) = 0;
  }
  RunProcess();
  (**(code **)(*in_r0 + 0x2c))(in_r0);
  iVar1 = CBBGSatellite::Draw();
  CBBGPopup::Draw();
  CGsOemIME::OnDraw();
  if (iVar1 == 0) {
    CBBGCommonMenu::DrawGameFrame();
  }
  CGsTouchMgr::DrawTouchRect();
  ppCVar3 = *(CGsParticleMgr ***)(iVar2 + DAT_001723e4);
  CGsParticleMgr::DrawAll();
  CGsParticleMgr::UpdateAll(*ppCVar3,0,0);
  CBBGScreenMng::Run();
  MemScreenView();
  EndOfScreen();
  return;
}


