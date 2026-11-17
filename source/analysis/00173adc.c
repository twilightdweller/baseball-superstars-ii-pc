/* CBBGLogoRun::Initialize at 00173adc; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::Initialize() */

void CBBGLogoRun::Initialize(void)

{
  int iVar1;
  int in_r0;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  CBBGResMgr **ppCVar5;
  
  iVar4 = DAT_00173b34 + 0x173ae8;
  puVar2 = *(undefined4 **)(iVar4 + DAT_00173b38);
  *(undefined4 *)(in_r0 + 8) = 0;
  uVar3 = *puVar2;
  *(undefined4 *)(in_r0 + 0x68) = 0;
  iVar1 = DAT_00173b3c;
  *(undefined4 *)(in_r0 + 100) = uVar3;
  ppCVar5 = *(CBBGResMgr ***)(iVar4 + iVar1);
  CBBGResMgr::AddLoadRes(*ppCVar5,0x13);
  CBBGResMgr::AddLoadRes(*ppCVar5,0x15);
  hideLoadingDialog();
  if ((**(int **)(iVar4 + DAT_00173b40) == 0) ||
     (*(char *)(**(int **)(iVar4 + DAT_00173b40) + 8) == '\0')) {
    CBBState::ReserveState((CBBState *)(in_r0 + 8),5);
  }
  else {
    CBBState::ReserveState((CBBState *)(in_r0 + 8),2);
  }
  return;
}


