/* CBBGResMgr::ChangePal at 0018dc90; decompiler output, not buildable source */

/* CBBGResMgr::ChangePal(BBG_RES_ID, int) */

void __thiscall CBBGResMgr::ChangePal(CBBGResMgr *this,BBG_RES_ID param_1,int param_2)

{
  char *pcVar1;
  CGxPZxMgr *pCVar2;
  int iVar3;
  int iVar4;
  CBBStringBuffer aCStack_2c [20];
  
  iVar4 = DAT_0018dd14 + 0x18dca0;
  iVar3 = *(int *)(param_1 * 4 + iVar4 + DAT_0018dd18);
  if (iVar3 == 1) {
    CBBStringBuffer::CBBStringBuffer(aCStack_2c,*(char **)(param_1 * 4 + iVar4 + DAT_0018dd1c));
    CBBStringBuffer::operator<<(aCStack_2c,(char *)(iVar4 + DAT_0018dd20 + 0x78));
    pcVar1 = (char *)CBBStringBuffer::Get();
    pCVar2 = (CGxPZxMgr *)GetPZxMgr(this,param_1);
    ChangePzxPal(pcVar1,pCVar2,param_2);
    CBBStringBuffer::~CBBStringBuffer(aCStack_2c);
  }
  else if ((iVar3 == 2) && (iVar3 = GetPzxPalIndex(this,param_1), iVar3 != -1)) {
    CGxChangePaletteWRT::ChangePalette
              (*(CGxChangePaletteWRT **)(iVar3 * 4 + *(int *)(this + 0x140)),param_2);
  }
  return;
}


