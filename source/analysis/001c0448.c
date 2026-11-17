/* CGxPZFParser::~CGxPZFParser at 001c0448; decompiler output, not buildable source */

/* CGxPZFParser::~CGxPZFParser() */

CGxPZFParser * __thiscall CGxPZFParser::~CGxPZFParser(CGxPZFParser *this)

{
  *(int *)this = *(int *)(DAT_001c046c + 0x1c0454 + DAT_001c0470) + 8;
  if (*(void **)(this + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x14));
  }
  CGxPZxParserBase::~CGxPZxParserBase((CGxPZxParserBase *)this);
  return this;
}


