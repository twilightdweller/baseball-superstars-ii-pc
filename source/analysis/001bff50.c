/* CGxPZFParser::DecodeBoundingBoxFromBAR at 001bff50; decompiler output, not buildable source */

/* CGxPZFParser::DecodeBoundingBoxFromBAR(CGxStream*, unsigned char*, CGxPZxFrameBB**) */

void __thiscall
CGxPZFParser::DecodeBoundingBoxFromBAR
          (CGxPZFParser *this,CGxStream *param_1,uchar *param_2,CGxPZxFrameBB **param_3)

{
  CGxPZxFrameBB CVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  uint uVar9;
  CGxPZxFrameBB *pCVar10;
  int iVar11;
  int iVar12;
  
  pCVar10 = *param_3;
  CVar1 = (CGxPZxFrameBB)*param_2;
  uVar4 = (uint)(byte)CVar1;
  pCVar10[0x20] = CVar1;
  uVar9 = (uint)(byte)*(CGxPZxFrameBB *)(param_2 + 1);
  pCVar10[0x21] = *(CGxPZxFrameBB *)(param_2 + 1);
  pCVar10[0x22] = (CGxPZxFrameBB)(**(byte **)(this + 0x14) >> 4);
  if ((byte)((**(byte **)(this + 0x14) >> 4) - 1) < 2) {
    uVar9 = 0;
  }
  else if (**(byte **)(this + 0x14) >> 4 != 3) {
    uVar4 = GetAttCount((uchar)CVar1);
    uVar9 = GetDamCount((uchar)pCVar10[0x20]);
  }
  iVar12 = uVar9 + uVar4;
  if (iVar12 != 0) {
    if (**(byte **)(this + 0x14) >> 4 == 2) {
      puVar7 = (undefined2 *)MC_knlCalloc(iVar12 * 4);
      iVar11 = 0;
      *(undefined2 **)(pCVar10 + 0x1c) = puVar7;
      do {
        puVar8 = (undefined2 *)CGxStream::GetMemoryBuffer(param_1,4);
        iVar11 = iVar11 + 1;
        *puVar7 = *puVar8;
        puVar7[1] = puVar8[1];
        puVar7 = puVar7 + 2;
      } while (iVar11 < iVar12);
    }
    else {
      pcVar5 = (char *)MC_knlCalloc(iVar12 * 8);
      *(char **)(pCVar10 + 0x1c) = pcVar5;
      if ((**(byte **)(this + 0x14) >> 4 == 3) || (iVar11 = 0, **(byte **)(this + 0x14) >> 4 == 1))
      {
        iVar11 = 0;
        do {
          puVar7 = (undefined2 *)CGxStream::GetMemoryBuffer(param_1,8);
          uVar3 = *puVar7;
          iVar11 = iVar11 + 1;
          *pcVar5 = (char)uVar3;
          pcVar5[1] = (char)((ushort)uVar3 >> 8);
          uVar3 = puVar7[1];
          pcVar5[2] = (char)uVar3;
          pcVar5[3] = (char)((ushort)uVar3 >> 8);
          uVar3 = puVar7[2];
          pcVar5[4] = (char)uVar3;
          pcVar5[5] = (char)((ushort)uVar3 >> 8);
          uVar3 = puVar7[3];
          pcVar5[6] = (char)uVar3;
          pcVar5[7] = (char)((ushort)uVar3 >> 8);
          pcVar5 = pcVar5 + 8;
        } while (iVar11 < iVar12);
      }
      else {
        do {
          pcVar6 = (char *)CGxStream::GetMemoryBuffer(param_1,4);
          cVar2 = *pcVar6;
          iVar11 = iVar11 + 1;
          *pcVar5 = cVar2;
          pcVar5[1] = cVar2 >> 7;
          cVar2 = pcVar6[1];
          pcVar5[2] = cVar2;
          pcVar5[3] = cVar2 >> 7;
          pcVar5[4] = pcVar6[2];
          pcVar5[5] = '\0';
          pcVar5[6] = pcVar6[3];
          pcVar5[7] = '\0';
          pcVar5 = pcVar5 + 8;
        } while (iVar11 < iVar12);
      }
    }
  }
  return;
}


