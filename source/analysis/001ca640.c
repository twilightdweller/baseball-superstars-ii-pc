/* CGxZeroPZDParser::DecodeHeader at 001ca640; decompiler output, not buildable source */

/* CGxZeroPZDParser::DecodeHeader(bool) */

undefined4 __thiscall CGxZeroPZDParser::DecodeHeader(CGxZeroPZDParser *this,bool param_1)

{
  CGxZeroPZDParser CVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = CGxPZDParser::DecodeHeader((CGxPZDParser *)this,param_1);
  uVar3 = 1;
  if (iVar2 == 0) {
    uVar3 = 0;
    CVar1 = **(CGxZeroPZDParser **)(this + 0x14);
    if ((byte)((char)CVar1 - 8U) < 3) {
      this[0x2b] = CVar1;
      CVar1 = **(CGxZeroPZDParser **)(this + 0x14);
      this[0x35] = (CGxZeroPZDParser)
                   (CVar1 == (CGxZeroPZDParser)0xa || CVar1 == (CGxZeroPZDParser)0x8);
      uVar3 = 1;
    }
  }
  return uVar3;
}


