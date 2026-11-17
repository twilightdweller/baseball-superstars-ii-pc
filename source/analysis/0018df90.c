/* CBBGResMgr::BBGLoadPzfPal at 0018df90; decompiler output, not buildable source */

/* CBBGResMgr::BBGLoadPzfPal(BBG_RES_ID) */

void __thiscall CBBGResMgr::BBGLoadPzfPal(CBBGResMgr *this,BBG_RES_ID param_1)

{
  CGxPZxMgr *this_00;
  char *pcVar1;
  CGxChangePaletteWRT *this_01;
  int iVar2;
  int iVar3;
  int iVar4;
  BBG_RES_ID BStack_64;
  CBBStringBuffer aCStack_60 [20];
  CBBStringBuffer aCStack_4c [20];
  CBBStringBuffer aCStack_38 [20];
  CGxChangePaletteWRT *apCStack_24 [2];
  
  iVar2 = DAT_0018e0d8 + 0x18dfaa;
  if (*(int *)(this + (param_1 + 2) * 4) == 0) {
    iVar3 = iVar2 + DAT_0018e0dc;
    iVar4 = iVar2 + DAT_0018e0e0;
    BStack_64 = param_1;
    CBBStringBuffer::CBBStringBuffer(aCStack_38,*(char **)(param_1 * 4 + iVar3));
    CBBStringBuffer::operator<<(aCStack_38,(char *)(iVar4 + 8));
    CBBStringBuffer::CBBStringBuffer(aCStack_4c,*(char **)(BStack_64 * 4 + iVar3));
    CBBStringBuffer::operator<<(aCStack_4c,(char *)(iVar4 + 0x10));
    CBBStringBuffer::CBBStringBuffer(aCStack_60,*(char **)(BStack_64 * 4 + iVar3));
    CBBStringBuffer::operator<<(aCStack_60,(char *)(iVar2 + DAT_0018e0e4 + 0x78));
    this_00 = (CGxPZxMgr *)operator_new(0x28);
    CGxPZxMgr::CGxPZxMgr(this_00);
    *(CGxPZxMgr **)(this + (BStack_64 + 2) * 4) = this_00;
    CGxPZxMgr::SetParameter
              (this_00,'\a',*(_func_CGxPZDMgr_ptr **)(iVar2 + DAT_0018e0e8),
               *(_func_CGxPZFMgr_ptr **)(iVar2 + DAT_0018e0ec));
    pcVar1 = (char *)CBBStringBuffer::Get();
    CGxPZxMgr::SetSource(this_00,pcVar1,DAT_0018e0f0,false);
    pcVar1 = (char *)CBBStringBuffer::Get();
    CGxPZxMgr::SetSource(this_00,pcVar1,DAT_0018e0f4,false);
    CGxPZxMgr::Open();
    CGxPZxMgr::LoadFrameAll();
    CGxPZDMgr::LoadImageAll();
    CGxPZxMgr::Close();
    this_01 = (CGxChangePaletteWRT *)operator_new(0xc);
    CGxChangePaletteWRT::CGxChangePaletteWRT(this_01);
    apCStack_24[0] = this_01;
    pcVar1 = (char *)CBBStringBuffer::Get();
    CGxChangePaletteWRT::SetSource
              (this_01,pcVar1,0x20000000,*(CGxPZDMgr **)(*(int *)(this + (BStack_64 + 2) * 4) + 8));
    CGsArray<CGxChangePaletteWRT*>::Insert
              ((CGsArray<CGxChangePaletteWRT*> *)(this + 0x13c),*(int *)(this + 0x144),apCStack_24);
    CGsArray<BBG_RES_ID>::Insert
              ((CGsArray<BBG_RES_ID> *)(this + 0x14c),*(int *)(this + 0x154),&BStack_64);
    this[BStack_64 + 0xfc] = (CBBGResMgr)0x1;
    CBBStringBuffer::~CBBStringBuffer(aCStack_60);
    CBBStringBuffer::~CBBStringBuffer(aCStack_4c);
    CBBStringBuffer::~CBBStringBuffer(aCStack_38);
  }
  return;
}


