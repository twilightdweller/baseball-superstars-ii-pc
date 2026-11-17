/* CGxPZFParser::DecodeHeader at 001c0d38; decompiler output, not buildable source */

/* CGxPZFParser::DecodeHeader(bool) */

bool __thiscall CGxPZFParser::DecodeHeader(CGxPZFParser *this,bool param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  tagPZxHeader *ptVar3;
  undefined4 *this_00;
  int iVar4;
  bool bVar5;
  tagPZxHeader atStack_18 [7];
  undefined uStack_11;
  
  iVar4 = DAT_001c0de4 + 0x1c0d44;
  if (param_1) {
    this_00 = *(undefined4 **)(this + 0xc);
    if ((int)(this_00[1] << 3) < 0) {
      ptVar3 = (tagPZxHeader *)CGxStream::GetMemoryBuffer((CGxStream *)this_00,4);
    }
    else {
      ptVar3 = atStack_18;
      (*(code *)this_00[7])(*this_00,ptVar3,4);
    }
    iVar4 = CGxPZxParserBase::CheckPZxType
                      (ptVar3,*(CGxStream **)(this + 0xc),1,(char *)(iVar4 + DAT_001c0de8),
                       (uint)(byte)this[0x11]);
    if (iVar4 == 0) {
      return false;
    }
  }
  if (this[0x11] == (CGxPZFParser)0x2) {
    uStack_11 = 0;
    (*(code *)(*(undefined4 **)(this + 0xc))[7])(**(undefined4 **)(this + 0xc),&uStack_11,1);
  }
  pvVar1 = operator_new(3);
  *(void **)(this + 0x14) = pvVar1;
  (*(code *)(*(undefined4 **)(this + 0xc))[7])(**(undefined4 **)(this + 0xc),pvVar1,1);
  (*(code *)(*(undefined4 **)(this + 0xc))[7])
            (**(undefined4 **)(this + 0xc),*(int *)(this + 0x14) + 1,2);
  uVar2 = (*(code *)(*(undefined4 **)(this + 0xc))[9])(**(undefined4 **)(this + 0xc),1,0);
  *(undefined4 *)(this + 4) = uVar2;
  bVar5 = *(short *)((int)*(void **)(this + 0x14) + 1) == 0;
  if (bVar5) {
    operator_delete__(*(void **)(this + 0x14));
    *(undefined4 *)(this + 0x14) = 0;
  }
  return !bVar5;
}


