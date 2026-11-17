/* CBBGRuleEngine::~CBBGRuleEngine; research only, not buildable source */

/* CBBGRuleEngine::~CBBGRuleEngine() */

CBBGRuleEngine * __thiscall CBBGRuleEngine::~CBBGRuleEngine(CBBGRuleEngine *this)

{
  *(int *)this = *(int *)(DAT_000ce428 + 0xce414 + DAT_000ce42c) + 8;
  ReleaseObj();
  CBBObject::~CBBObject((CBBObject *)this);
  return this;
}


