/* CBBGRuleEngine::~CBBGRuleEngine; research only, not buildable source */

/* CBBGRuleEngine::~CBBGRuleEngine() */

CBBGRuleEngine * __thiscall CBBGRuleEngine::~CBBGRuleEngine(CBBGRuleEngine *this)

{
  *(int *)this = *(int *)(DAT_000ce3ec + 0xce3d8 + DAT_000ce3f0) + 8;
  ReleaseObj();
  CBBObject::~CBBObject((CBBObject *)this);
  return this;
}


