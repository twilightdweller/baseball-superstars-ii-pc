/* CGxPZFParser::NewFrame at 001c02fc; decompiler output, not buildable source */

/* CGxPZFParser::NewFrame(bool) */

CGxPZxFrame * __thiscall CGxPZFParser::NewFrame(CGxPZFParser *this,bool param_1)

{
  CGxPZxFrame *this_00;
  
  if (param_1) {
    this_00 = (CGxPZxFrame *)operator_new(0x24);
    CGxPZxFrameBB::CGxPZxFrameBB((CGxPZxFrameBB *)this_00);
  }
  else {
    this_00 = (CGxPZxFrame *)operator_new(0x1c);
    CGxPZxFrame::CGxPZxFrame(this_00);
  }
  return this_00;
}


