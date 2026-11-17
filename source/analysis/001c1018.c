/* CGxPZFParser::BeginDecodeFrame at 001c1018; decompiler output, not buildable source */

/* CGxPZFParser::BeginDecodeFrame(unsigned short, CGxStream*, int*, unsigned char*, long, long) */

undefined4
CGxPZFParser::BeginDecodeFrame
          (ushort param_1,CGxStream *param_2,int *param_3,uchar *param_4,long param_5,long param_6)

{
  int iVar1;
  CGxPZxParserBase *this;
  undefined4 uVar2;
  byte *pbVar3;
  undefined *puVar4;
  int iVar5;
  undefined uStack_23;
  undefined uStack_22;
  byte abStack_21 [5];
  
  this = (CGxPZxParserBase *)(uint)param_1;
  uVar2 = CGxPZxParserBase::SeekIndexTable(this,(ushort)param_2);
  iVar5 = DAT_001c1154 + 0x1c103c;
  if ((**(byte **)(this + 0x14) & 0xf) == 0) {
    CGxStream::Attach((CGxStream *)param_3,*(CGxStream **)(this + 0xc));
    if ((*(uint *)(*(int *)(this + 0xc) + 4) & 0x10000000) == 0) {
      *(undefined4 *)(this + 0x24) = 0x18;
      *(undefined4 *)(this + 0x28) = 1;
      iVar1 = DAT_001c115c;
      *(undefined4 *)(this + 0x30) = 0;
      *(undefined4 *)(this + 0x2c) = *(undefined4 *)(iVar5 + iVar1);
      abStack_21[0] = 0;
      (*(code *)param_3[7])(*param_3,abStack_21,1);
      if (param_4 != (uchar *)0x0) {
        *(uint *)param_4 = (uint)abStack_21[0];
      }
      uStack_22 = 0;
      (*(code *)param_3[7])(*param_3,&uStack_22,1);
      if (param_5 != 0) {
        *(undefined *)param_5 = uStack_22;
      }
      if (**(byte **)(this + 0x14) >> 4 == 3) {
        uStack_23 = 0;
        (*(code *)param_3[7])(*param_3,&uStack_23,1);
        if (param_5 != 0) {
          *(undefined *)(param_5 + 1) = uStack_23;
        }
      }
      goto LAB_001c1096;
    }
  }
  else {
    CGxStream::InitStream
              ((CGxStream *)param_3,*(void **)(this + 0x18),*(uint *)(this + 0x1c) | 0x10000000);
    (*(code *)param_3[9])(*param_3,0,uVar2);
  }
  *(undefined4 *)(this + 0x24) = 0x1c;
  *(undefined4 *)(this + 0x28) = 1;
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(iVar5 + DAT_001c1158);
  *(undefined4 *)(this + 0x30) = 0;
  pbVar3 = (byte *)CGxStream::GetMemoryBuffer((CGxStream *)param_3,1);
  if (param_4 != (uchar *)0x0) {
    *(uint *)param_4 = (uint)*pbVar3;
  }
  puVar4 = (undefined *)CGxStream::GetMemoryBuffer((CGxStream *)param_3,1);
  if (param_5 != 0) {
    *(undefined *)param_5 = *puVar4;
  }
  if (**(byte **)(this + 0x14) >> 4 == 3) {
    puVar4 = (undefined *)CGxStream::GetMemoryBuffer((CGxStream *)param_3,1);
    if (param_5 != 0) {
      *(undefined *)(param_5 + 1) = *puVar4;
    }
  }
LAB_001c1096:
  if (((param_6 == 0) || (param_4 == (uchar *)0x0)) || (*(int *)param_4 < 1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = MC_knlCalloc(*(int *)param_4 << 4);
  }
  return uVar2;
}


