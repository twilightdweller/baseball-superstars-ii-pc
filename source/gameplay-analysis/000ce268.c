/* CBBGRuleEngine::IsFoulAngle; research only, not buildable source */

/* CBBGRuleEngine::IsFoulAngle(int) */

bool CBBGRuleEngine::IsFoulAngle(int param_1)

{
  if (0 < param_1) {
    param_1 = param_1 + -0x168;
  }
  return 0x5a < param_1 + 0x87U;
}


