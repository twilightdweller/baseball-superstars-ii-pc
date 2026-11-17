/* CGxPZFParser::UncompressAllDataFromFILE at 001c0dec; decompiler output, not buildable source */

/* CGxPZFParser::UncompressAllDataFromFILE(CGxStream*, unsigned int&) */

int CGxPZFParser::UncompressAllDataFromFILE(CGxStream *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_20;
  uint uStack_1c;
  
  if (param_1 != (CGxStream *)0x0) {
    uStack_1c = 0;
    uStack_20 = 0;
    (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,&uStack_1c,4);
    (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,&uStack_20,4);
    iVar1 = MC_knlCalloc(uStack_20);
    if (iVar1 != 0) {
      iVar2 = MC_knlCalloc(uStack_1c);
      if (iVar2 == 0) {
        return 0;
      }
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)param_1,iVar1,uStack_20);
      iVar3 = GxUncompress(iVar2,&uStack_1c,iVar1,uStack_20);
      if (iVar3 != 0) {
        MC_knlFree(iVar2);
        iVar2 = 0;
      }
      *param_2 = uStack_1c;
      MC_knlFree(iVar1);
      return iVar2;
    }
  }
  return 0;
}


