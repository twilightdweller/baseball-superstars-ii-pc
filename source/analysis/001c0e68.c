/* CGxPZFParser::Open at 001c0e68; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CGxPZFParser::Open() */

undefined4 CGxPZFParser::Open(void)

{
  CGxPZFParser *in_r0;
  undefined4 uVar1;
  int iVar2;
  CGxStream *pCVar3;
  
  CGxPZxParserBase::Open();
  uVar1 = 1;
  if (in_r0[0x20] == (CGxPZFParser)0x0) {
    iVar2 = DecodeHeader(in_r0,true);
    uVar1 = 0;
    if (iVar2 != 0) {
      CGxPZxParserBase::MoveTopIndexTable();
      if ((**(byte **)(in_r0 + 0x14) & 0xf) != 0) {
        (*(code *)(*(undefined4 **)(in_r0 + 0xc))[9])
                  (**(undefined4 **)(in_r0 + 0xc),1,
                   (uint)*(ushort *)(*(byte **)(in_r0 + 0x14) + 1) << 2);
        pCVar3 = *(CGxStream **)(in_r0 + 0xc);
        if (*(int *)(pCVar3 + 4) << 3 < 0) {
          uVar1 = UncompressAllDataFromBAR(pCVar3,(uint *)(in_r0 + 0x1c));
          *(undefined4 *)(in_r0 + 0x18) = uVar1;
        }
        else {
          uVar1 = UncompressAllDataFromFILE(pCVar3,(uint *)(in_r0 + 0x1c));
          *(undefined4 *)(in_r0 + 0x18) = uVar1;
        }
      }
      in_r0[0x20] = (CGxPZFParser)0x1;
      uVar1 = 1;
    }
  }
  return uVar1;
}


