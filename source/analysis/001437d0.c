/* CBBStartUp::CheckSaveFile at 001437d0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBStartUp::CheckSaveFile() */

void CBBStartUp::CheckSaveFile(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  void *__src;
  undefined4 uVar6;
  CPopup *pCVar7;
  char **ppcVar8;
  undefined4 *puVar9;
  char **ppcVar10;
  CPopup **ppCVar11;
  char *pcVar12;
  byte *pbVar13;
  int iVar14;
  char *local_14c [11];
  char *local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined auStack_108 [64];
  undefined4 local_c8;
  undefined4 local_c4;
  int local_c0;
  char acStack_bc [64];
  char acStack_7c [64];
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  int local_2c;
  
  iVar2 = DAT_001439b4;
  iVar14 = DAT_001439b0 + 0x1437e8;
  local_2c = **(int **)(iVar14 + DAT_001439b4);
  local_110 = 0;
  local_10c = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = 0;
  local_118 = 0;
  local_114 = 0;
  memset(auStack_108,0,0x40);
  iVar3 = DAT_001439c0;
  ppcVar10 = local_14c;
  ppcVar8 = (char **)(DAT_001439b8 + iVar14);
  local_14c[0] = *ppcVar8;
  local_14c[1] = ppcVar8[1];
  local_14c[2] = ppcVar8[2];
  local_14c[3] = ppcVar8[3];
  local_14c[4] = ppcVar8[4];
  local_14c[5] = ppcVar8[5];
  local_14c[6] = ppcVar8[6];
  local_14c[7] = ppcVar8[7];
  local_14c[8] = ppcVar8[8];
  local_14c[9] = ppcVar8[9];
  local_14c[10] = ppcVar8[10];
  puVar9 = (undefined4 *)(DAT_001439bc + iVar14);
  do {
    pcVar12 = *ppcVar10;
    iVar4 = CGsFile::IsExist((CGsFile *)&local_118,pcVar12);
    if ((((iVar4 != 0) && (pcVar5 = (char *)GsFSFileSize(pcVar12,1), pcVar5 != (char *)0x0)) &&
        (__src = (void *)MC_knlCalloc(), __src != (void *)0x0)) &&
       ((iVar4 = CGsFile::Load((CGsFile *)&local_118,__src,pcVar12,(uint)pcVar5), iVar4 != 0 &&
        (memcpy(&local_120,__src,4), pcVar12 = local_120, local_120 == pcVar5)))) {
      memcpy(&local_11c,(void *)((int)__src + 4),4);
      pcVar12 = pcVar12 + -8;
      local_3c = *puVar9;
      uStack_38 = puVar9[1];
      uStack_34 = puVar9[2];
      local_30 = puVar9[3];
      **(undefined4 **)(iVar14 + iVar3) = local_11c;
      pbVar13 = (byte *)((int)__src + 8);
      for (; pcVar12 != (char *)0x0; pcVar12 = pcVar12 + -1) {
        bVar1 = *pbVar13;
        iVar4 = Random(0x10);
        *pbVar13 = bVar1 ^ *(byte *)((int)&local_3c + iVar4);
        pbVar13 = pbVar13 + 1;
      }
      uVar6 = GsGetCurrentTime();
      **(undefined4 **)(iVar14 + iVar3) = uVar6;
      memcpy(acStack_7c,(byte *)((int)__src + 8),0x40);
      memset(acStack_bc,0,0x40);
      GsGetPhoneNum(acStack_bc);
      iVar4 = strcmp(acStack_7c,acStack_bc);
      if (iVar4 != 0) {
        CBBGPopup::CreatePopup
                  (**(CBBGPopup ***)(iVar14 + DAT_001439c4),(char *)(DAT_001439c8 + iVar14),'\x02',
                   0x15b,'\0',(char **)0x0,0,0);
        ppCVar11 = *(CPopup ***)(iVar14 + DAT_001439cc);
        pCVar7 = *ppCVar11;
        if (pCVar7 != (CPopup *)0x0) {
          CPopup::SetTitle(pCVar7,(char *)(DAT_001439d0 + iVar14),2);
          pCVar7 = *ppCVar11;
          if (pCVar7 != (CPopup *)0x0) {
            pCVar7[4] = (CPopup)0x3a;
          }
        }
        MC_knlFree(__src);
        uVar6 = 0;
        goto LAB_0014393a;
      }
      MC_knlFree(__src);
    }
    ppcVar10 = ppcVar10 + 1;
    if (&local_120 == ppcVar10) {
      uVar6 = 1;
LAB_0014393a:
      if (local_c0 != 0) {
        MC_knlFree();
      }
      if (local_2c == **(int **)(iVar14 + iVar2)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(uVar6);
    }
  } while( true );
}


