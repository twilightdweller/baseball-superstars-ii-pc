/* CGxPZFParser::CGxPZFParser at 001c0560; decompiler output, not buildable source */

/* CGxPZFParser::CGxPZFParser() */

CGxPZFParser * __thiscall CGxPZFParser::CGxPZFParser(CGxPZFParser *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_001c0598;
  CGxPZxParserBase::CGxPZxParserBase((CGxPZxParserBase *)this);
  uVar2 = *(undefined4 *)(iVar1 + 0x1c0570 + DAT_001c05a0);
  *(int *)this = *(int *)(iVar1 + 0x1c0570 + DAT_001c059c) + 8;
  this[0x20] = (CGxPZFParser)0x0;
  *(undefined4 *)(this + 0x24) = 0x18;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x28) = 1;
  *(undefined4 *)(this + 0x2c) = uVar2;
  *(undefined4 *)(this + 0x30) = 0;
  this[0x11] = (CGxPZFParser)0x1;
  return this;
}


