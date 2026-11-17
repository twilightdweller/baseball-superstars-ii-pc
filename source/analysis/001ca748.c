/* CGxZeroPZDParser::DecodeImageData at 001ca748; decompiler output, not buildable source */

/* CGxZeroPZDParser::DecodeImageData(unsigned short, tagImageInfo*) */

undefined4 __thiscall
CGxZeroPZDParser::DecodeImageData(CGxZeroPZDParser *this,ushort param_1,tagImageInfo *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined2 uStack_38;
  undefined2 uStack_36;
  byte bStack_34;
  char cStack_33;
  uint uStack_30;
  int iStack_2c;
  uint uStack_28;
  int aiStack_24 [2];
  
  iVar1 = DAT_001ca8c0;
  iVar5 = DAT_001ca8bc + 0x1ca75a;
  **(undefined4 **)(iVar5 + DAT_001ca8c0) = 0;
  *(undefined2 *)(param_2 + 8) = 0;
  *(undefined2 *)(param_2 + 10) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)param_2 = 0;
  CGxPZxParserBase::SeekIndexTable((CGxPZxParserBase *)this,param_1);
  if ((*(char *)(*(int *)(this + 0x14) + 3) == '\0') && (1 < (byte)((char)this[0x2b] - 9U))) {
    uStack_28 = uStack_28 & 0xffffff00;
    (*(code *)(*(undefined4 **)(this + 0xc))[7])(**(undefined4 **)(this + 0xc),&uStack_28,1);
    *(ushort *)(param_2 + 0xc) = (ushort)(byte)uStack_28;
    uVar2 = MC_knlCalloc((uStack_28 & 0xff) << 1);
    *(undefined4 *)param_2 = uVar2;
    (*(code *)(*(undefined4 **)(this + 0xc))[7])
              (**(undefined4 **)(this + 0xc),uVar2,(uStack_28 & 0xff) << 1);
    param_2[0xe] = (tagImageInfo)0x1;
  }
  (*(code *)(*(undefined4 **)(this + 0xc))[7])(**(undefined4 **)(this + 0xc),&uStack_38,0x10);
  if (cStack_33 != '\x01') {
    cStack_33 = '\0';
  }
  *(undefined2 *)(param_2 + 8) = uStack_38;
  *(undefined2 *)(param_2 + 10) = uStack_36;
  *(uint *)(param_2 + 4) = (uint)bStack_34;
  aiStack_24[0] = 0;
  if (cStack_33 != '\0') {
    (*(code *)(*(undefined4 **)(this + 0xc))[7])(**(undefined4 **)(this + 0xc),aiStack_24,4);
  }
  if (iStack_2c == 0) {
    if (cStack_33 == '\0') {
      uVar3 = MC_knlCalloc(uStack_30);
      (*(code *)(*(undefined4 **)(this + 0xc))[7])(**(undefined4 **)(this + 0xc),uVar3,uStack_30);
    }
    else {
      iVar4 = aiStack_24[0] + uStack_30;
      uVar3 = MC_knlCalloc(iVar4);
      (*(code *)(*(undefined4 **)(this + 0xc))[7])(**(undefined4 **)(this + 0xc),uVar3,iVar4);
    }
  }
  else {
    uVar2 = MC_knlCalloc();
    (*(code *)(*(undefined4 **)(this + 0xc))[7])(**(undefined4 **)(this + 0xc),uVar2,iStack_2c);
    uStack_28 = uStack_30;
    if (cStack_33 == '\0') {
      uVar3 = MC_knlCalloc();
      iVar4 = GxUncompress(uVar3,&uStack_28,uVar2,iStack_2c);
      if (iVar4 != 0) {
        MC_knlFree(uVar2);
        MC_knlFree(uVar3);
        return 0;
      }
    }
    else {
      iVar4 = uStack_30 + aiStack_24[0];
      uVar3 = MC_knlCalloc(iVar4);
      iVar4 = GxUncompress(uVar3,&uStack_28,uVar2,iVar4);
      if (iVar4 != 0) {
        MC_knlFree(uVar2);
        MC_knlFree(uVar3);
        return 0;
      }
    }
    MC_knlFree(uVar2);
  }
  **(uint **)(iVar5 + iVar1) = uStack_30;
  return uVar3;
}


