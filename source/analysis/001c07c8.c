/* CGxPZFParser::DecodeBoundingBoxFromFILE at 001c07c8; decompiler output, not buildable source */

/* CGxPZFParser::DecodeBoundingBoxFromFILE(CGxStream*, unsigned char*, CGxPZxFrameBB**) */

void __thiscall
CGxPZFParser::DecodeBoundingBoxFromFILE
          (CGxPZFParser *this,CGxStream *param_1,uchar *param_2,CGxPZxFrameBB **param_3)

{
  CGxPZxFrameBB CVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  CGxPZxFrameBB *pCVar7;
  int iVar8;
  char cStack_2c;
  char cStack_2b;
  char cStack_2a;
  char acStack_29 [5];
  
  pCVar7 = *param_3;
  CVar1 = (CGxPZxFrameBB)*param_2;
  uVar2 = (uint)(byte)CVar1;
  pCVar7[0x20] = CVar1;
  uVar5 = (uint)(byte)*(CGxPZxFrameBB *)(param_2 + 1);
  pCVar7[0x21] = *(CGxPZxFrameBB *)(param_2 + 1);
  pCVar7[0x22] = (CGxPZxFrameBB)(**(byte **)(this + 0x14) >> 4);
  if ((byte)((**(byte **)(this + 0x14) >> 4) - 1) < 2) {
    uVar5 = 0;
  }
  else if (**(byte **)(this + 0x14) >> 4 != 3) {
    uVar2 = GetAttCount((uchar)CVar1);
    uVar5 = GetDamCount((uchar)pCVar7[0x20]);
  }
  iVar8 = uVar5 + uVar2;
  if (iVar8 != 0) {
    if (**(byte **)(this + 0x14) >> 4 == 2) {
      iVar4 = MC_knlCalloc(iVar8 * 4);
      iVar6 = 0;
      *(int *)(pCVar7 + 0x1c) = iVar4;
      do {
        (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,iVar4,2);
        iVar6 = iVar6 + 1;
        (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,iVar4 + 2,2);
        iVar4 = iVar4 + 4;
      } while (iVar6 < iVar8);
    }
    else {
      pcVar3 = (char *)MC_knlCalloc(iVar8 * 8);
      *(char **)(pCVar7 + 0x1c) = pcVar3;
      if ((**(byte **)(this + 0x14) >> 4 == 3) || (**(byte **)(this + 0x14) >> 4 == 1)) {
        iVar4 = 0;
        do {
          (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,pcVar3,2);
          (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,pcVar3 + 2,2);
          (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,pcVar3 + 4,2);
          iVar4 = iVar4 + 1;
          (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,pcVar3 + 6,2);
          pcVar3 = pcVar3 + 8;
        } while (iVar4 < iVar8);
      }
      else {
        iVar4 = 0;
        do {
          (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,acStack_29,1);
          (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,&cStack_2a,1);
          (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,&cStack_2b,1);
          (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,&cStack_2c,1);
          iVar4 = iVar4 + 1;
          *pcVar3 = acStack_29[0];
          pcVar3[1] = acStack_29[0] >> 7;
          pcVar3[2] = cStack_2a;
          pcVar3[3] = cStack_2a >> 7;
          pcVar3[4] = cStack_2b;
          pcVar3[5] = '\0';
          pcVar3[6] = cStack_2c;
          pcVar3[7] = '\0';
          pcVar3 = pcVar3 + 8;
        } while (iVar4 < iVar8);
      }
    }
  }
  return;
}


