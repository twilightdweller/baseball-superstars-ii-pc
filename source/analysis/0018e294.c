/* CBBGResMgr::BBGLoadPzx at 0018e294; decompiler output, not buildable source */

/* CBBGResMgr::BBGLoadPzx(BBG_RES_ID) */

void __thiscall CBBGResMgr::BBGLoadPzx(CBBGResMgr *this,BBG_RES_ID param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  CBBStringBuffer aCStack_2c [20];
  
  iVar4 = DAT_0018e348 + 0x18e2a8;
  if (*(int *)(this + (param_1 + 2) * 4) == 0) {
    CBBStringBuffer::CBBStringBuffer(aCStack_2c,*(char **)(param_1 * 4 + iVar4 + DAT_0018e34c));
    iVar1 = CBBGDataMgr::GetOption();
    if ((*(int *)(iVar1 + 0x48) != 1) &&
       ((((((param_1 == 0x12 || (param_1 == 2)) || (param_1 == 0x14)) ||
          ((param_1 == 0x13 || (param_1 == 0x24)))) ||
         ((param_1 == 0x15 || ((param_1 == 0x25 || (param_1 == 0x27)))))) || (param_1 == 0x29)))) {
      CBBStringBuffer::operator<<(aCStack_2c,(char *)(iVar4 + DAT_0018e354));
    }
    CBBStringBuffer::operator<<(aCStack_2c,(char *)(iVar4 + DAT_0018e358 + 0x18));
    pcVar2 = (char *)CBBStringBuffer::Get();
    uVar3 = LoadPzx(pcVar2,'\x01',(char *)0x0,-1,'\0',0,'\0','\0',0);
    *(undefined4 *)(this + (param_1 + 2) * 4) = uVar3;
    this[param_1 + 0xfc] = (CBBGResMgr)0x1;
    CBBStringBuffer::~CBBStringBuffer(aCStack_2c);
  }
  return;
}


