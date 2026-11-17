/* CBBGMenuRun::SetChangeRunnable at 001684b0; decompiler output, not buildable source */

/* CBBGMenuRun::SetChangeRunnable(int) */

void __thiscall CBBGMenuRun::SetChangeRunnable(CBBGMenuRun *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_001684f4 + 0x1684bc;
  iVar1 = CBBGDataMgr::GetOption();
  *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(this + 100);
  CBBGDataMgr::SaveOption();
  iVar1 = DAT_001684fc;
  *(int *)(this + 0x68) = param_1;
  CBBGScreenMng::SetMode(**(CBBGScreenMng ***)(iVar2 + iVar1),1,0,5,DAT_00168500);
  CBBState::ReserveState((CBBState *)(this + 8),0x27);
  return;
}


