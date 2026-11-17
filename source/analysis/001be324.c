/* CGxPZAParser::DecodeAnimationData at 001be324; decompiler output, not buildable source */

/* CGxPZAParser::DecodeAnimationData(unsigned short, int) */

CGxPZxAni * __thiscall
CGxPZAParser::DecodeAnimationData(CGxPZAParser *this,ushort param_1,int param_2)

{
  CGxPZxAni CVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  CGxPZxAni *pCVar4;
  undefined2 *puVar5;
  undefined *puVar6;
  char *pcVar7;
  CGxPZxAni *this_00;
  int *piVar8;
  uint uVar9;
  int iVar10;
  undefined4 auStack_54 [7];
  code *pcStack_38;
  code *pcStack_30;
  undefined2 uStack_2c;
  char cStack_2a;
  CGxPZxAni aCStack_29 [5];
  
  if (*(short *)(*(int *)(this + 0x14) + 1) == 0) {
    return (CGxPZxAni *)0x0;
  }
  uVar2 = CGxPZxParserBase::SeekIndexTable((CGxPZxParserBase *)this,param_1);
  CGxStream::CGxStream((CGxStream *)auStack_54);
  if ((**(byte **)(this + 0x14) & 0xf) == 0) {
    CGxStream::Attach((CGxStream *)auStack_54,*(CGxStream **)(this + 0xc));
    uVar9 = (uint)(*(int *)(*(int *)(this + 0xc) + 4) << 3) >> 0x1f;
  }
  else {
    CGxStream::InitStream
              ((CGxStream *)auStack_54,*(void **)(this + 0x18),*(uint *)(this + 0x1c) | 0x10000000);
    (*pcStack_30)(auStack_54[0],0,uVar2);
    uVar9 = 1;
  }
  piVar8 = *(int **)(this + 0x24);
  if (piVar8 == (int *)0x0) {
    this_00 = (CGxPZxAni *)operator_new(0x18);
    CGxPZxAni::CGxPZxAni(this_00);
  }
  else {
    if (piVar8[1] <= (int)(uint)param_1) goto LAB_001be38e;
    this_00 = (CGxPZxAni *)(*piVar8 + (uint)param_1 * 0x18);
  }
  if (this_00 != (CGxPZxAni *)0x0) {
    if (uVar9 == 0) {
      aCStack_29[0] = (CGxPZxAni)0x0;
      (*pcStack_38)(auStack_54[0],aCStack_29,1);
      puVar3 = (undefined4 *)MC_knlCalloc((uint)(byte)aCStack_29[0] * 0xc);
      *(undefined4 **)(this_00 + 0x10) = puVar3;
      this_00[0x14] = aCStack_29[0];
      if (aCStack_29[0] != (CGxPZxAni)0x0) {
        iVar10 = 0;
        do {
          *(undefined *)(puVar3 + 2) = 0;
          *(undefined2 *)(puVar3 + 1) = 0;
          *(undefined2 *)((int)puVar3 + 6) = 0;
          *puVar3 = 0;
          uStack_2c = 0;
          (*pcStack_38)(auStack_54[0],&uStack_2c,2);
          if (param_2 != 0) {
            *(undefined2 *)(param_2 + iVar10 * 2) = uStack_2c;
          }
          (*pcStack_38)(auStack_54[0],puVar3 + 2,1);
          (*pcStack_38)(auStack_54[0],puVar3 + 1,2);
          (*pcStack_38)(auStack_54[0],(int)puVar3 + 6,2);
          cStack_2a = '\0';
          (*pcStack_38)(auStack_54[0],&cStack_2a,1);
          if (cStack_2a == '\0') {
            if ((int)(uint)(byte)this_00[0x14] <= iVar10 + 1) break;
          }
          else {
            (*pcStack_30)(auStack_54[0],0);
            if ((int)(uint)(byte)this_00[0x14] <= iVar10 + 1) break;
          }
          iVar10 = iVar10 + 1;
          puVar3 = puVar3 + 3;
        } while( true );
      }
    }
    else {
      pCVar4 = (CGxPZxAni *)CGxStream::GetMemoryBuffer((CGxStream *)auStack_54,1);
      CVar1 = *pCVar4;
      uVar9 = (uint)(byte)CVar1;
      if (uVar9 != 0) {
        uVar2 = MC_knlCalloc(uVar9 * 0xc);
        *(undefined4 *)(this_00 + 0x10) = uVar2;
      }
      this_00[0x14] = CVar1;
      puVar3 = *(undefined4 **)(this_00 + 0x10);
      if (uVar9 != 0) {
        iVar10 = 0;
        while( true ) {
          *(undefined *)(puVar3 + 2) = 0;
          *(undefined2 *)(puVar3 + 1) = 0;
          *(undefined2 *)((int)puVar3 + 6) = 0;
          *puVar3 = 0;
          puVar5 = (undefined2 *)CGxStream::GetMemoryBuffer((CGxStream *)auStack_54,2);
          if (param_2 != 0) {
            *(undefined2 *)(param_2 + iVar10 * 2) = *puVar5;
          }
          puVar6 = (undefined *)CGxStream::GetMemoryBuffer((CGxStream *)auStack_54,1);
          *(undefined *)(puVar3 + 2) = *puVar6;
          puVar5 = (undefined2 *)CGxStream::GetMemoryBuffer((CGxStream *)auStack_54,2);
          *(undefined2 *)(puVar3 + 1) = *puVar5;
          puVar5 = (undefined2 *)CGxStream::GetMemoryBuffer((CGxStream *)auStack_54,2);
          *(undefined2 *)((int)puVar3 + 6) = *puVar5;
          pcVar7 = (char *)CGxStream::GetMemoryBuffer((CGxStream *)auStack_54,1);
          if (*pcVar7 != '\0') {
            (*pcStack_30)(auStack_54[0],0);
          }
          iVar10 = iVar10 + 1;
          if ((int)(uint)(byte)this_00[0x14] <= iVar10) break;
          puVar3 = puVar3 + 3;
        }
      }
    }
    CGxStream::CloseStream();
    CGxStream::~CGxStream((CGxStream *)auStack_54);
    return this_00;
  }
LAB_001be38e:
  CGxStream::CloseStream();
  CGxStream::~CGxStream((CGxStream *)auStack_54);
  return (CGxPZxAni *)0x0;
}


