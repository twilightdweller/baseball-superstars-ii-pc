/* CGxPZFParser::~CGxPZFParser at 001c0408; decompiler output, not buildable source */

/* CGxPZFParser::~CGxPZFParser() */

CGxPZFParser * __thiscall CGxPZFParser::~CGxPZFParser(CGxPZFParser *this)

{
  *(int *)this = *(int *)(DAT_001c042c + 0x1c0414 + DAT_001c0430) + 8;
  if (*(void **)(this + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x14));
  }
  CGxPZxParserBase::~CGxPZxParserBase((CGxPZxParserBase *)this);
  return this;
}


