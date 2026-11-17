/* CBBGRuleEngine::PitchJudge; research only, not buildable source */

/* CBBGRuleEngine::PitchJudge(unsigned char) */

int __thiscall CBBGRuleEngine::PitchJudge(CBBGRuleEngine *this,uchar param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 8);
  iVar1 = 4;
  if (*(char *)(iVar2 + 0x12) == '\0') {
    if ((param_1 == '\0') && (*(char *)(iVar2 + 0x10) == '\0')) {
      iVar1 = 3 - ((uint)((uint)(int)*(char *)(iVar2 + 5) < 3) - ((int)*(char *)(iVar2 + 5) >> 0x1f)
                  );
    }
    else {
      iVar1 = 1;
      if ('\x01' < *(char *)(iVar2 + 4)) {
        iVar1 = 5;
      }
    }
  }
  return iVar1;
}


