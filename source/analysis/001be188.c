/* CGxPZAParser::~CGxPZAParser at 001be188; decompiler output, not buildable source */

/* CGxPZAParser::~CGxPZAParser() */

CGxPZAParser * __thiscall CGxPZAParser::~CGxPZAParser(CGxPZAParser *this)

{
  *(int *)this = *(int *)(DAT_001be1ac + 0x1be194 + DAT_001be1b0) + 8;
  if (*(void **)(this + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x14));
  }
  CGxPZxParserBase::~CGxPZxParserBase((CGxPZxParserBase *)this);
  return this;
}


