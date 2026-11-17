/* Java_com_gamevil_nexus2_Natives_handleCletEvent at 00196030; decompiler output, not buildable source */

void Java_com_gamevil_nexus2_Natives_handleCletEvent
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (**(char **)(DAT_00196090 + 0x19603c + DAT_00196094) != '\0') {
    if (param_3 == 0x1f) {
      handleCletEvent(2,param_4,0);
      handleCletEvent(3,param_4,0);
    }
    else if (((param_3 == 0x19) || (param_3 == 0x17)) || (param_3 == 0x18)) {
      uStack_1c = param_6;
      uStack_14 = param_5;
      uStack_18 = param_4;
      handleCletEvent(param_3,0,&uStack_1c);
    }
    else {
      handleCletEvent(param_3,param_4,param_5);
    }
  }
  return;
}


