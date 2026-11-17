/* CBBGRuleEngine::CBBGRuleEngine; research only, not buildable source */

/* CBBGRuleEngine::CBBGRuleEngine(CBBGPlayData*) */

CBBGRuleEngine * __thiscall
CBBGRuleEngine::CBBGRuleEngine(CBBGRuleEngine *this,CBBGPlayData *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_000ce480;
  CBBObject::CBBObject((CBBObject *)this);
  iVar2 = DAT_000ce484;
  *(CBBGPlayData **)(this + 8) = param_1;
  *(int *)this = *(int *)(iVar1 + 0xce46e + iVar2) + 8;
  Initialize();
  return this;
}


