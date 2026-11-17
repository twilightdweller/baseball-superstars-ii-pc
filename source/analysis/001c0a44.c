/* CGxPZFParser::EndDecodeFrameFromFILE at 001c0a44; decompiler output, not buildable source */

/* CGxPZFParser::EndDecodeFrameFromFILE(CGxStream*, int, CGxPZxFrame**, long, long) */

undefined4 __thiscall
CGxPZFParser::EndDecodeFrameFromFILE
          (CGxPZFParser *this,CGxStream *param_1,int param_2,CGxPZxFrame **param_3,long param_4,
          long param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 uStack_2c;
  char cStack_2a;
  undefined auStack_29 [5];
  
  if ((param_4 == 0) || (puVar3 = *(undefined4 **)(*param_3 + 8), puVar3 == (undefined4 *)0x0)) {
    if (0 < param_2) {
      iVar2 = 0;
      do {
        (**(code **)(param_1 + 0x24))(*(undefined4 *)param_1,1,6);
        cStack_2a = '\0';
        (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,&cStack_2a,1);
        if (cStack_2a != '\0') {
          (**(code **)(param_1 + 0x24))(*(undefined4 *)param_1,1);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2);
    }
  }
  else if (0 < param_2) {
    iVar2 = 0;
    while( true ) {
      *puVar3 = 0;
      *(undefined2 *)(puVar3 + 1) = 0;
      *(undefined2 *)((int)puVar3 + 6) = 0;
      puVar3[2] = 0;
      *(undefined *)(puVar3 + 3) = 0;
      if (this[0x11] == (CGxPZFParser)0x2) {
        auStack_29[0] = 0;
        (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,auStack_29,1);
        *(undefined *)(iVar2 + param_5) = auStack_29[0];
      }
      uStack_2c = 0;
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,&uStack_2c,2);
      *(undefined2 *)(iVar2 * 2 + param_4) = uStack_2c;
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,puVar3 + 1,2);
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,(int)puVar3 + 6,2);
      cStack_2a = '\0';
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,&cStack_2a,1);
      if (cStack_2a != '\0') {
        *(char *)(puVar3 + 3) = cStack_2a;
        uVar1 = MC_knlCalloc(cStack_2a);
        puVar3[2] = uVar1;
        (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,uVar1,cStack_2a);
      }
      if (param_2 <= iVar2 + 1) break;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 4;
    }
  }
  CGxStream::CloseStream();
  return 1;
}


