/* CGxPZFParser::DecodeFrameData at 001c01a0; decompiler output, not buildable source */

/* CGxPZFParser::DecodeFrameData(unsigned short, long, long) */

int * __thiscall
CGxPZFParser::DecodeFrameData(CGxPZFParser *this,ushort param_1,long param_2,long param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  CGxStream aCStack_54 [40];
  undefined4 uStack_2c;
  int *piStack_28;
  undefined2 uStack_24;
  
  if (*(short *)(*(int *)(this + 0x14) + 1) == 0) {
    return (int *)0x0;
  }
  uStack_24 = 0;
  piStack_28 = (int *)0x0;
  uStack_2c = 0;
  CGxStream::CGxStream(aCStack_54);
  iVar1 = (**(code **)(*(int *)this + 0x14))
                    (this,param_1,aCStack_54,&uStack_2c,&uStack_24,param_2,param_3);
  if (((char)uStack_24 == '\0') && (uStack_24._1_1_ == '\0')) {
    piStack_28 = (int *)(**(code **)(*(int *)this + 0x20))(this,0);
    if (piStack_28 != (int *)0x0) {
LAB_001c0234:
      piStack_28[2] = iVar1;
      *(short *)(piStack_28 + 3) = (short)uStack_2c;
      iVar1 = *(int *)(this + 0x28) >> 1;
      if (*(int *)(this + 0x28) << 0x1f < 0) {
        pcVar3 = *(code **)(*(int *)(this + iVar1) + *(int *)(this + 0x24));
      }
      else {
        pcVar3 = *(code **)(this + 0x24);
      }
      iVar1 = (*pcVar3)(this + iVar1,aCStack_54,uStack_2c,&piStack_28,param_2,param_3);
      piVar4 = piStack_28;
      if (iVar1 != 0) goto LAB_001c0270;
      if (piStack_28 != (int *)0x0) {
        (**(code **)(*piStack_28 + 4))();
        piVar4 = (int *)0x0;
        goto LAB_001c0270;
      }
    }
  }
  else {
    piStack_28 = (int *)(**(code **)(*(int *)this + 0x20))(this,1);
    if (piStack_28 != (int *)0x0) {
      iVar2 = *(int *)(this + 0x30) >> 1;
      if (*(int *)(this + 0x30) << 0x1f < 0) {
        pcVar3 = *(code **)(*(int *)(this + iVar2) + *(int *)(this + 0x2c));
      }
      else {
        pcVar3 = *(code **)(this + 0x2c);
      }
      (*pcVar3)(this + iVar2,aCStack_54,&uStack_24,&piStack_28);
      goto LAB_001c0234;
    }
  }
  piVar4 = (int *)0x0;
LAB_001c0270:
  CGxStream::~CGxStream(aCStack_54);
  return piVar4;
}


