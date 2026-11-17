/* CBBGLogoRun::INIT_HANDLER_MSTATE_CERTI at 00173708; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::INIT_HANDLER_MSTATE_CERTI() */

void CBBGLogoRun::INIT_HANDLER_MSTATE_CERTI(void)

{
  int iVar1;
  int in_r0;
  CGsCertification *this;
  int iVar2;
  char acStack_b0 [128];
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  int local_24;
  
  iVar1 = DAT_001737b0;
  iVar2 = DAT_001737ac + 0x17371a;
  local_24 = **(int **)(iVar2 + DAT_001737b0);
  local_28 = 0;
  local_30 = 0;
  local_2c = 0;
  getVersion(&local_30);
  if (*(int *)(in_r0 + 0x68) == 0) {
    this = (CGsCertification *)operator_new(0x180);
    CGsCertification::CGsCertification(this);
    *(CGsCertification **)(in_r0 + 0x68) = this;
    if (this != (CGsCertification *)0x0) {
      memset(acStack_b0,0,0x80);
      GsGetPhoneNum(acStack_b0);
      CGsCertification::Initial
                (*(CGsCertification **)(in_r0 + 0x68),(char *)(iVar2 + DAT_001737b8),
                 (char *)(iVar2 + DAT_001737bc),(char *)(iVar2 + DAT_001737c4),(char *)&local_30,
                 (char *)(iVar2 + DAT_001737b4),DAT_001737c0,DAT_001737c8,acStack_b0,0xe,(char *)0x0
                );
    }
  }
  if (local_24 == **(int **)(iVar2 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


