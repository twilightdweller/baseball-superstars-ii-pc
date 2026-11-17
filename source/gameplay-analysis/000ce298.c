/* CBBGRuleEngine::GetPatternDirect; research only, not buildable source */

/* CBBGRuleEngine::GetPatternDirect(EnumBattingPatternDirect) */

undefined4 CBBGRuleEngine::GetPatternDirect(EnumBattingPatternDirect param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 < 3) {
    iVar3 = DAT_000ce2d0 + 0xce2a0 + DAT_000ce2d4;
    iVar4 = *(int *)(param_1 * 4 + iVar3);
    iVar3 = *(int *)(iVar3 + param_1 * 4 + 0xc);
  }
  else {
    iVar3 = 0x3c;
    iVar4 = 0x1e;
  }
  iVar1 = bb_rand(0,0x5a);
  uVar2 = 2;
  if ((iVar1 <= iVar3) && (uVar2 = 1, iVar4 <= iVar1)) {
    uVar2 = 0;
  }
  return uVar2;
}


