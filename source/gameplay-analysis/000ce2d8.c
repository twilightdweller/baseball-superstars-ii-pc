/* CBBGRuleEngine::GetAngleAOnPlate; research only, not buildable source */

/* CBBGRuleEngine::GetAngleAOnPlate(bbtagPoint3D) */

int CBBGRuleEngine::GetAngleAOnPlate(bbtagPoint3D param_1)

{
  int iVar1;
  int in_r2;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1 + DAT_000ce354;
  iVar1 = 0;
  if (iVar4 != 0) {
    iVar5 = DAT_000ce358 - in_r2;
    iVar1 = __aeabi_idiv(iVar4 * 100,iVar5);
    iVar1 = GsArcTan100(iVar1 + (iVar1 >> 0x1f) ^ iVar1 >> 0x1f);
    iVar2 = (iVar5 >> 0x1f) - iVar5;
    iVar3 = (iVar4 >> 0x1f) - iVar4;
    if ((iVar3 < 0) && (iVar2 < 0)) {
      iVar1 = iVar1 + -0x5a;
    }
    if ((iVar4 < 0) && (iVar2 < 0)) {
      iVar1 = -0x5a - iVar1;
    }
    if (iVar5 < 0) {
      if (iVar3 < 0) {
        iVar1 = 0x5a - iVar1;
      }
      if ((iVar5 < 0) && (iVar4 < 0)) {
        iVar1 = iVar1 + 0x5a;
      }
    }
    if (0 < iVar1) {
      iVar1 = iVar1 + -0x168;
    }
  }
  return iVar1;
}


