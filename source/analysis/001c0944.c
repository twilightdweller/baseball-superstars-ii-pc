/* CGxPZFParser::EndDecodeFrameFromBAR at 001c0944; decompiler output, not buildable source */

/* CGxPZFParser::EndDecodeFrameFromBAR(CGxStream*, int, CGxPZxFrame**, long, long) */

undefined4 __thiscall
CGxPZFParser::EndDecodeFrameFromBAR
          (CGxPZFParser *this,CGxStream *param_1,int param_2,CGxPZxFrame **param_3,long param_4,
          long param_5)

{
  char cVar1;
  undefined2 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  if ((param_4 == 0) || (puVar6 = *(undefined4 **)(*param_3 + 8), puVar6 == (undefined4 *)0x0)) {
    iVar7 = 0;
    if (0 < param_2) {
      do {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)param_1,1,6);
        pcVar3 = (char *)CGxStream::GetMemoryBuffer(param_1,1);
        if (*pcVar3 != '\0') {
          (**(code **)(param_1 + 0x24))(*(undefined4 *)param_1,1);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_2);
    }
  }
  else if (0 < param_2) {
    iVar7 = 0;
    while( true ) {
      *puVar6 = 0;
      *(undefined2 *)(puVar6 + 1) = 0;
      *(undefined2 *)((int)puVar6 + 6) = 0;
      puVar6[2] = 0;
      *(undefined *)(puVar6 + 3) = 0;
      if (this[0x11] == (CGxPZFParser)0x2) {
        puVar5 = (undefined *)CGxStream::GetMemoryBuffer(param_1,1);
        *(undefined *)(iVar7 + param_5) = *puVar5;
      }
      puVar2 = (undefined2 *)CGxStream::GetMemoryBuffer(param_1,2);
      *(undefined2 *)(iVar7 * 2 + param_4) = *puVar2;
      puVar2 = (undefined2 *)CGxStream::GetMemoryBuffer(param_1,2);
      *(undefined2 *)(puVar6 + 1) = *puVar2;
      puVar2 = (undefined2 *)CGxStream::GetMemoryBuffer(param_1,2);
      *(undefined2 *)((int)puVar6 + 6) = *puVar2;
      pcVar3 = (char *)CGxStream::GetMemoryBuffer(param_1,1);
      cVar1 = *pcVar3;
      if (cVar1 != '\0') {
        *(char *)(puVar6 + 3) = cVar1;
        uVar4 = MC_knlCalloc();
        puVar6[2] = uVar4;
        (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,uVar4,cVar1);
      }
      if (param_2 <= iVar7 + 1) break;
      iVar7 = iVar7 + 1;
      puVar6 = puVar6 + 4;
    }
  }
  CGxStream::CloseStream();
  return 1;
}


