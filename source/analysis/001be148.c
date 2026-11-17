/* CGxPZAParser::~CGxPZAParser at 001be148; decompiler output, not buildable source */

/* CGxPZAParser::~CGxPZAParser() */

CGxPZAParser * __thiscall CGxPZAParser::~CGxPZAParser(CGxPZAParser *this)

{
  *(int *)this = *(int *)(DAT_001be16c + 0x1be154 + DAT_001be170) + 8;
  if (*(void **)(this + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x14));
  }
  CGxPZxParserBase::~CGxPZxParserBase((CGxPZxParserBase *)this);
  return this;
}


