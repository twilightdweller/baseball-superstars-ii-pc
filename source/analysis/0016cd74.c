/* CBBGMenuRun::INIT_HANDLER_MSTATE_DATA_DOWNLOAD at 0016cd74; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGMenuRun::INIT_HANDLER_MSTATE_DATA_DOWNLOAD() */

void CBBGMenuRun::INIT_HANDLER_MSTATE_DATA_DOWNLOAD(void)

{
  CPopup CVar1;
  char *pcVar2;
  int iVar3;
  CPopup *pCVar4;
  int iVar5;
  CBBGPopup *this;
  CPopup **ppCVar6;
  
  iVar5 = DAT_0016ce1c + 0x16cd80;
  this = **(CBBGPopup ***)(iVar5 + DAT_0016ce20);
  pcVar2 = (char *)CBBGResMgr::GetStr(**(CBBGResMgr ***)(iVar5 + DAT_0016ce24),0x36,0x1c);
  CBBGPopup::CreatePopup(this,pcVar2,'\x02',0x15b,'\0',(char **)0x0,0,0);
  ppCVar6 = *(CPopup ***)(iVar5 + DAT_0016ce28);
  if (*ppCVar6 != (CPopup *)0x0) {
    CPopup::SetTitle(*ppCVar6,(char *)(iVar5 + DAT_0016ce2c),2);
    iVar3 = DAT_0016ce30;
    pCVar4 = *ppCVar6;
    if (pCVar4 != (CPopup *)0x0) {
      *(undefined4 *)(pCVar4 + ((char)pCVar4[DAT_0016ce30] + DAT_0016ce34) * 4) = 0xfffffff0;
      CVar1 = pCVar4[iVar3];
      pCVar4[DAT_0016ce38 + (char)CVar1 + 4] = (CPopup)0x1;
      pCVar4[iVar3] = (CPopup)((char)CVar1 + '\x01');
      if (*ppCVar6 != (CPopup *)0x0) {
        (*ppCVar6)[iVar3 + 1] = (CPopup)0x1;
      }
    }
  }
  iVar3 = CBBGDataMgr::GetOption();
  memcpy(*(void **)(iVar5 + DAT_0016ce40),(void *)(iVar3 + DAT_0016ce44),0xf);
  iVar3 = CBBGDataMgr::GetOption();
  **(undefined4 **)(iVar5 + DAT_0016ce48) = *(undefined4 *)(iVar3 + 0x40);
  return;
}


