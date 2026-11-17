/* CGxZeroPZDParser::Close at 001ca5d0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CGxZeroPZDParser::Close() */

void CGxZeroPZDParser::Close(void)

{
  int in_r0;
  CGxStream *this;
  
  CGxPZxParserBase::Close();
  if (((int)((uint)*(byte *)(in_r0 + 0x2a) << 0x1d) < 0) && (*(int *)(in_r0 + 0x2c) != 0)) {
    MC_knlFree();
    *(undefined4 *)(in_r0 + 0x2c) = 0;
  }
  *(undefined *)(in_r0 + 0x34) = 0;
  *(byte *)(in_r0 + 0x2a) = *(byte *)(in_r0 + 0x2a) & 0xf7;
  if (*(char *)(in_r0 + 0x35) != '\0') {
    if (*(char *)(in_r0 + 0x10) != '\0') {
      CGxStream::CloseStream();
      this = *(CGxStream **)(in_r0 + 0xc);
      if (this != (CGxStream *)0x0) {
        CGxStream::~CGxStream(this);
        operator_delete(this);
      }
      *(undefined *)(in_r0 + 0x10) = 0;
    }
    *(undefined4 *)(in_r0 + 0xc) = 0;
    MC_knlFree(*(undefined4 *)(in_r0 + 0x30));
    *(undefined4 *)(in_r0 + 0x30) = 0;
    *(undefined *)(in_r0 + 0x35) = 0;
  }
  return;
}


