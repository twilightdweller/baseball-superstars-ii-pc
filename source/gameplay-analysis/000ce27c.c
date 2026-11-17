/* CBBGRuleEngine::GetBuntType; research only, not buildable source */

/* CBBGRuleEngine::GetBuntType(int) */

undefined4 CBBGRuleEngine::GetBuntType(int param_1)

{
  undefined4 uVar1;
  
  if (0 < param_1) {
    param_1 = param_1 + -0x168;
  }
  uVar1 = 2;
  if ((param_1 + 0x78 < 0 == SCARRY4(param_1,0x78)) &&
     (uVar1 = 3, param_1 + 0x3b < 0 != SCARRY4(param_1,0x3b))) {
    uVar1 = 1;
  }
  return uVar1;
}


