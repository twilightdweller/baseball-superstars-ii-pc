/* CBBGResMgr::LoadImgText at 0018e3ac; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGResMgr::LoadImgText() */

void CBBGResMgr::LoadImgText(void)

{
  int in_r0;
  int iVar1;
  CGxChangePaletteWRT *this;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = DAT_0018e46c + 0x18e3b8;
  iVar1 = CBBGDataMgr::GetOption();
  if (*(int *)(iVar1 + 0x48) == 1) {
    if (*(int *)(in_r0 + 0x160) == 0) {
      uVar2 = LoadPzx((char *)(iVar3 + DAT_0018e480),'\x01',(char *)(iVar3 + DAT_0018e474),-1,'\0',0
                      ,'\0','\0',0);
      *(undefined4 *)(in_r0 + 0x160) = uVar2;
    }
    if (*(int *)(in_r0 + 0x164) != 0) {
      return;
    }
    this = (CGxChangePaletteWRT *)operator_new(0xc);
    CGxChangePaletteWRT::CGxChangePaletteWRT(this);
    *(CGxChangePaletteWRT **)(in_r0 + 0x164) = this;
    iVar1 = DAT_0018e474;
  }
  else {
    if (*(int *)(in_r0 + 0x160) == 0) {
      uVar2 = LoadPzx((char *)(iVar3 + DAT_0018e47c),'\x01',(char *)(iVar3 + DAT_0018e478),-1,'\0',0
                      ,'\0','\0',0);
      *(undefined4 *)(in_r0 + 0x160) = uVar2;
    }
    if (*(int *)(in_r0 + 0x164) != 0) {
      return;
    }
    this = (CGxChangePaletteWRT *)operator_new(0xc);
    CGxChangePaletteWRT::CGxChangePaletteWRT(this);
    iVar1 = DAT_0018e478;
    *(CGxChangePaletteWRT **)(in_r0 + 0x164) = this;
  }
  CGxChangePaletteWRT::SetSource
            (this,(char *)(iVar3 + iVar1),0x20000000,*(CGxPZDMgr **)(*(int *)(in_r0 + 0x160) + 8));
  return;
}


