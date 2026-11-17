/* CGxZeroPZDParser::CGxZeroPZDParser at 001ca710; decompiler output, not buildable source */

/* CGxZeroPZDParser::CGxZeroPZDParser() */

CGxZeroPZDParser * __thiscall CGxZeroPZDParser::CGxZeroPZDParser(CGxZeroPZDParser *this)

{
  int iVar1;
  
  iVar1 = DAT_001ca740;
  CGxPZDParser::CGxPZDParser((CGxPZDParser *)this);
  *(int *)this = *(int *)(iVar1 + 0x1ca720 + DAT_001ca744) + 8;
  this[0x2b] = (CGxZeroPZDParser)0x7;
  this[0x34] = (CGxZeroPZDParser)0x0;
  this[0x11] = (CGxZeroPZDParser)0x2;
  *(undefined4 *)(this + 0x2c) = 0;
  this[0x35] = (CGxZeroPZDParser)0x0;
  *(undefined4 *)(this + 0x30) = 0;
  return this;
}


