/* CBBGMenuRun::INIT_HANDLER_MSTATE_DATA_UPLOAD at 0016cccc; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_DATA_UPLOAD() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_DATA_UPLOAD(void)

{
  CPopup CVar1;
  int in_r0;
  char *pcVar2;
  CPopup *pCVar3;
  int iVar4;
  CBBGPopup *this;
  CPopup **ppCVar5;
  
  iVar4 = DAT_0016cd50 + 0x16ccd8;
  this = **(CBBGPopup ***)(iVar4 + DAT_0016cd54);
  pcVar2 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar4 + DAT_0016cd58),0x36,0x19);
  CBBGPopup::CreatePopup(this,pcVar2,'\x02',0x15b,'\0',(char **)0x0,0,0);
  ppCVar5 = *(CPopup ***)(iVar4 + DAT_0016cd5c);
  if (*ppCVar5 != (CPopup *)0x0) {
    CPopup::SetTitle(*ppCVar5,(char *)(iVar4 + DAT_0016cd60),2);
    if (*ppCVar5 != (CPopup *)0x0) {
      (*ppCVar5)[DAT_0016cd64] = (CPopup)0x1;
      iVar4 = DAT_0016cd68;
      pCVar3 = *ppCVar5;
      if (pCVar3 != (CPopup *)0x0) {
        CVar1 = pCVar3[DAT_0016cd68];
        *(undefined4 *)(pCVar3 + ((char)CVar1 + DAT_0016cd6c) * 4) = 0xfffffff0;
        pCVar3[DAT_0016cd70 + (char)CVar1 + 4] = (CPopup)0x1;
        pCVar3[iVar4] = (CPopup)((char)CVar1 + '\x01');
      }
    }
  }
  *(undefined4 *)(in_r0 + 8) = 0;
  return;
}


