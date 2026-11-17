/* CBBGRuleEngine::BoundJudge; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGRuleEngine::BoundJudge() */

undefined4 CBBGRuleEngine::BoundJudge(void)

{
  int in_r0;
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xd;
  if ((*(char *)(*(int *)(in_r0 + 8) + 0x1f) == '\0') &&
     (uVar1 = 0, *(char *)(*(int *)(in_r0 + 8) + 0x19) == '\0')) {
    iVar2 = CBBGPlayData::IsFoul();
    if (iVar2 == 0) {
      iVar2 = *(int *)(in_r0 + 8);
      if (*(int *)(iVar2 + 0x154) < 1) {
        if (*(int *)(iVar2 + 0x20) < 1) {
          return 6;
        }
        if (*(char *)(iVar2 + 0x1e) == '\0') {
          return 8;
        }
      }
      else if ((*(char *)(iVar2 + 0x1e) == '\0') || (*(int *)(iVar2 + 0x20) == -1)) {
        return 0xc;
      }
      uVar1 = 10;
    }
    else if ((*(char *)(*(int *)(in_r0 + 8) + 4) < '\x02') ||
            (uVar1 = 0xb, *(char *)(*(int *)(in_r0 + 8) + 0x13) == '\0')) {
      uVar1 = 7;
    }
  }
  return uVar1;
}


