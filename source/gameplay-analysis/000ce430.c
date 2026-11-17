/* CBBGRuleEngine::CBBGRuleEngine; research only, not buildable source */

/* CBBGRuleEngine::CBBGRuleEngine(CBBGPlayData*) */

CBBGRuleEngine * __thiscall
CBBGRuleEngine::CBBGRuleEngine(CBBGRuleEngine *this,CBBGPlayData *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_000ce454;
  CBBObject::CBBObject((CBBObject *)this);
  iVar2 = DAT_000ce458;
  *(CBBGPlayData **)(this + 8) = param_1;
  *(int *)this = *(int *)(iVar1 + 0xce442 + iVar2) + 8;
  Initialize();
  return this;
}


