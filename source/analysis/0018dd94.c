/* CBBGResMgr::BBGLoadXls at 0018dd94; decompiler output, not buildable source */

/* CBBGResMgr::BBGLoadXls(BBG_RES_ID) */

void __thiscall CBBGResMgr::BBGLoadXls(CBBGResMgr *this,BBG_RES_ID param_1)

{
  int iVar1;
  GVXLString *this_00;
  char *pcVar2;
  int iVar3;
  CBBStringBuffer aCStack_2c [20];
  
  iVar3 = DAT_0018de28 + 0x18dda8;
  if (*(int *)(this + (param_1 + 2) * 4) == 0) {
    CBBStringBuffer::CBBStringBuffer(aCStack_2c,(char *)(iVar3 + DAT_0018de2c));
    iVar1 = CBBGDataMgr::GetOption();
    if (*(int *)(iVar1 + 0x48) != 1) {
      CBBStringBuffer::operator<<(aCStack_2c,(char *)(iVar3 + DAT_0018de34));
    }
    CBBStringBuffer::operator<<(aCStack_2c,*(char **)(param_1 * 4 + iVar3 + DAT_0018de38));
    CBBStringBuffer::operator<<(aCStack_2c,(char *)(iVar3 + DAT_0018de3c));
    this_00 = (GVXLString *)operator_new(0xc);
    GVXLString::GVXLString(this_00);
    pcVar2 = (char *)CBBStringBuffer::Get();
    GVXLString::Create(this_00,pcVar2,true);
    *(GVXLString **)(this + (param_1 + 2) * 4) = this_00;
    this[param_1 + 0xfc] = (CBBGResMgr)0x1;
    CBBStringBuffer::~CBBStringBuffer(aCStack_2c);
  }
  return;
}


