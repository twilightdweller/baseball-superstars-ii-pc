/* CBBGResMgr::BBGLoadPzxPal at 0018e150; decompiler output, not buildable source */

/* CBBGResMgr::BBGLoadPzxPal(BBG_RES_ID) */

void __thiscall CBBGResMgr::BBGLoadPzxPal(CBBGResMgr *this,BBG_RES_ID param_1)

{
  BBG_RES_ID BVar1;
  char *pcVar2;
  undefined4 uVar3;
  CGxChangePaletteWRT *this_00;
  char *pcVar4;
  int iVar5;
  int iVar6;
  BBG_RES_ID aBStack_54 [2];
  CBBStringBuffer aCStack_4c [20];
  CBBStringBuffer aCStack_38 [20];
  CGxChangePaletteWRT *apCStack_24 [2];
  
  iVar6 = DAT_0018e280 + 0x18e16a;
  if (*(int *)(this + (param_1 + 2) * 4) == 0) {
    iVar5 = DAT_0018e284 + iVar6;
    aBStack_54[0] = param_1;
    CBBStringBuffer::CBBStringBuffer(aCStack_38,*(char **)(param_1 * 4 + iVar5));
    CBBStringBuffer::operator<<(aCStack_38,(char *)(iVar6 + DAT_0018e288 + 0x18));
    CBBStringBuffer::CBBStringBuffer(aCStack_4c,*(char **)(aBStack_54[0] * 4 + iVar5));
    CBBStringBuffer::operator<<(aCStack_4c,(char *)(iVar6 + DAT_0018e28c + 0x78));
    BVar1 = aBStack_54[0];
    if (*(int *)(aBStack_54[0] * 4 + iVar6 + DAT_0018e290) == 1) {
      pcVar2 = (char *)CBBStringBuffer::Get();
      pcVar4 = (char *)CBBStringBuffer::Get();
      uVar3 = LoadPzx(pcVar2,'\x01',pcVar4,-1,'\0',0,'\0','\0',0);
      *(undefined4 *)(this + (BVar1 + 2) * 4) = uVar3;
    }
    else {
      pcVar2 = (char *)CBBStringBuffer::Get();
      uVar3 = LoadPzx(pcVar2,'\x01',(char *)0x0,-1,'\0',0,'\0','\0',0);
      *(undefined4 *)(this + (BVar1 + 2) * 4) = uVar3;
      this_00 = (CGxChangePaletteWRT *)operator_new(0xc);
      CGxChangePaletteWRT::CGxChangePaletteWRT(this_00);
      apCStack_24[0] = this_00;
      pcVar2 = (char *)CBBStringBuffer::Get();
      CGxChangePaletteWRT::SetSource
                (this_00,pcVar2,0x20000000,
                 *(CGxPZDMgr **)(*(int *)(this + (aBStack_54[0] + 2) * 4) + 8));
      CGsArray<CGxChangePaletteWRT*>::Insert
                ((CGsArray<CGxChangePaletteWRT*> *)(this + 0x13c),*(int *)(this + 0x144),apCStack_24
                );
      CGsArray<BBG_RES_ID>::Insert
                ((CGsArray<BBG_RES_ID> *)(this + 0x14c),*(int *)(this + 0x154),aBStack_54);
    }
    this[aBStack_54[0] + 0xfc] = (CBBGResMgr)0x1;
    CBBStringBuffer::~CBBStringBuffer(aCStack_4c);
    CBBStringBuffer::~CBBStringBuffer(aCStack_38);
  }
  return;
}


