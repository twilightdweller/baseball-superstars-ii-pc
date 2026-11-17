/* CGxPZAParser::DecodeHeader at 001be21c; decompiler output, not buildable source */

/* CGxPZAParser::DecodeHeader(bool) */

bool __thiscall CGxPZAParser::DecodeHeader(CGxPZAParser *this,bool param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  tagPZxHeader *ptVar3;
  undefined4 *this_00;
  int iVar4;
  bool bVar5;
  tagPZxHeader atStack_14 [4];
  
  iVar4 = DAT_001be2ac + 0x1be228;
  if (param_1) {
    this_00 = *(undefined4 **)(this + 0xc);
    if ((int)(this_00[1] << 3) < 0) {
      ptVar3 = (tagPZxHeader *)CGxStream::GetMemoryBuffer((CGxStream *)this_00,4);
    }
    else {
      ptVar3 = atStack_14;
      (*(code *)this_00[7])(*this_00,ptVar3,4);
    }
    iVar4 = CGxPZxParserBase::CheckPZxType
                      (ptVar3,*(CGxStream **)(this + 0xc),2,(char *)(iVar4 + DAT_001be2b0),
                       (uint)(byte)this[0x11]);
    if (iVar4 == 0) {
      return false;
    }
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


