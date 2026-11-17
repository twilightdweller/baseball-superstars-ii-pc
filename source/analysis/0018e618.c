/* CBBGResMgr::CBBGResMgr at 0018e618; decompiler output, not buildable source */

/* CBBGResMgr::CBBGResMgr() */

CBBGResMgr * __thiscall CBBGResMgr::CBBGResMgr(CBBGResMgr *this)

{
  GVXLString *pGVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = DAT_0018e754 + 0x18e624;
  iVar3 = *(int *)(iVar5 + DAT_0018e75c);
  **(CBBGResMgr ***)(iVar5 + DAT_0018e758) = this;
  *(int *)this = *(int *)(iVar5 + DAT_0018e760) + 8;
  *(int *)(this + 0x13c) = iVar3 + 8;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = 8;
  CGsArray<CGxChangePaletteWRT*>::ExtendCapacity((CGsArray<CGxChangePaletteWRT*> *)(this + 0x13c),8)
  ;
  *(int *)(this + 0x14c) = *(int *)(iVar5 + DAT_0018e764) + 8;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = 8;
  CGsArray<BBG_RES_ID>::ExtendCapacity((CGsArray<BBG_RES_ID> *)(this + 0x14c),8);
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 4;
    *(undefined4 *)(this + iVar3 + 8) = 0;
    iVar3 = iVar4;
  } while (iVar4 != 0xf4);
  memset(this + 0xfc,0,0x3d);
  this[0x15c] = (CBBGResMgr)0x0;
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x164) = 0;
  LoadImgText();
  pGVar1 = (GVXLString *)operator_new(0xc);
  GVXLString::GVXLString(pGVar1);
  *(GVXLString **)(this + 4) = pGVar1;
  iVar3 = CBBGDataMgr::GetOption();
  if (*(int *)(iVar3 + 0x48) == 1) {
    GVXLString::Create(*(GVXLString **)(this + 4),(char *)(iVar5 + DAT_0018e77c),true);
  }
  else {
    GVXLString::Create(*(GVXLString **)(this + 4),(char *)(iVar5 + DAT_0018e76c),true);
  }
  pGVar1 = (GVXLString *)operator_new(0xc);
  GVXLString::GVXLString(pGVar1);
  iVar3 = DAT_0018e770;
  *(GVXLString **)(this + 0x16c) = pGVar1;
  GVXLString::Create(pGVar1,(char *)(iVar5 + iVar3),true);
  pGVar1 = (GVXLString *)operator_new(0xc);
  GVXLString::GVXLString(pGVar1);
  iVar3 = DAT_0018e774;
  *(GVXLString **)(this + 0x170) = pGVar1;
  GVXLString::Create(pGVar1,(char *)(iVar5 + iVar3),true);
  uVar2 = LoadPzx((char *)(iVar5 + DAT_0018e778),'\x01',(char *)0x0,-1,'\0',0,'\0','\0',0);
  *(undefined4 *)(this + 0x168) = uVar2;
  return this;
}


