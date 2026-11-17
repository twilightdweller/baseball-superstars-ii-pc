/* CGxPZFParser::Close at 001c03d8; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CGxPZFParser::Close() */

void CGxPZFParser::Close(void)

{
  int in_r0;
  
  CGxPZxParserBase::Close();
  if (*(byte **)(in_r0 + 0x14) != (byte *)0x0) {
    if (((**(byte **)(in_r0 + 0x14) & 0xf) != 0) && (*(int *)(in_r0 + 0x18) != 0)) {
      MC_knlFree();
      *(undefined4 *)(in_r0 + 0x18) = 0;
    }
  }
  *(undefined4 *)(in_r0 + 0x18) = 0;
  *(undefined4 *)(in_r0 + 0x1c) = 0;
  *(undefined *)(in_r0 + 0x20) = 0;
  return;
}


