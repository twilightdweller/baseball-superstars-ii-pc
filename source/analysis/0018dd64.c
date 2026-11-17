/* CBBGResMgr::GetGameCodeGVXString at 0018dd64; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGResMgr::GetGameCodeGVXString() */

undefined4 CBBGResMgr::GetGameCodeGVXString(void)

{
  int in_r0;
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = CBBGDataMgr::GetOption();
  if (*(int *)(iVar1 + 0x48) == 1) {
    uVar2 = *(undefined4 *)(in_r0 + 0x16c);
  }
  else {
    uVar2 = *(undefined4 *)(in_r0 + 0x170);
  }
  return uVar2;
}


