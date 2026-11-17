/* CGxPZFParser::UncompressAllDataFromBAR at 001c0320; decompiler output, not buildable source */

/* CGxPZFParser::UncompressAllDataFromBAR(CGxStream*, unsigned int&) */

int CGxPZFParser::UncompressAllDataFromBAR(CGxStream *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uStack_24;
  
  if ((param_1 != (CGxStream *)0x0) && (*(int *)(param_1 + 4) << 3 < 0)) {
    pbVar5 = (byte *)CGxStream::GetMemoryBuffer(param_1,4);
    uStack_24 = (uint)pbVar5[2] << 0x10 | (uint)pbVar5[3] << 0x18 | (uint)*pbVar5 |
                (uint)pbVar5[1] << 8;
    pbVar5 = (byte *)CGxStream::GetMemoryBuffer(param_1,4);
    bVar1 = pbVar5[2];
    bVar2 = pbVar5[1];
    bVar3 = pbVar5[3];
    bVar4 = *pbVar5;
    iVar6 = MC_knlCalloc(uStack_24);
    if (iVar6 == 0) {
      return 0;
    }
    uVar9 = (uint)bVar4 | (uint)bVar3 << 0x18 | (uint)bVar1 << 0x10 | (uint)bVar2 << 8;
    iVar7 = MC_knlCalloc(uVar9);
    if (iVar7 != 0) {
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,iVar7,uVar9);
      iVar8 = GxUncompress(iVar6,&uStack_24,iVar7,uVar9);
      if (iVar8 != 0) {
        MC_knlFree(iVar6);
        iVar6 = 0;
      }
      *param_2 = uStack_24;
      MC_knlFree(iVar7);
      return iVar6;
    }
  }
  return 0;
}


