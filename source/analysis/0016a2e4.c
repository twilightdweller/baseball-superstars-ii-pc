/* CBBGMenuRun::EndProcess at 0016a2e4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::EndProcess() */

void CBBGMenuRun::EndProcess(void)

{
  int in_r0;
  int iVar1;
  int iVar2;
  CBBGResMgr **ppCVar3;
  
  iVar1 = *(int *)(in_r0 + 0xc);
  iVar2 = DAT_0016a340 + 0x16a2ee;
  if (iVar1 < 0x20) {
    if (iVar1 < 0x1e) {
      if (iVar1 == 0x1d) {
        ppCVar3 = *(CBBGResMgr ***)(iVar2 + DAT_0016a344);
        CBBGResMgr::Release(*ppCVar3,0x16);
        CBBGResMgr::Release(*ppCVar3,0x1a);
      }
    }
    else {
      ppCVar3 = *(CBBGResMgr ***)(iVar2 + DAT_0016a344);
      CBBGResMgr::Release(*ppCVar3,0x17);
      CBBGResMgr::Release(*ppCVar3,0x18);
    }
  }
  else if (iVar1 == 0x21) {
    ppCVar3 = *(CBBGResMgr ***)(iVar2 + DAT_0016a344);
    CBBGResMgr::Release(*ppCVar3,0x1c);
    CBBGResMgr::ReleaseXls(*ppCVar3,0x39);
  }
  return;
}


