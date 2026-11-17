/* CCLProjection::~CCLProjection; research only, not buildable source */

/* CCLProjection::~CCLProjection() */

CCLProjection * __thiscall CCLProjection::~CCLProjection(CCLProjection *this)

{
  ~CCLProjection(this);
  operator_delete(this);
  return this;
}


