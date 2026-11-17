/* CBBGLogoRun::EVENT_HANDLER_MSTATE_DATA_ERROR at 001737f0; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBGLogoRun::EVENT_HANDLER_MSTATE_DATA_ERROR() */

void CBBGLogoRun::EVENT_HANDLER_MSTATE_DATA_ERROR(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14 [2];
  
  iVar1 = DAT_001738ac;
  iVar3 = DAT_001738a0 + 0x1737fc;
  iVar2 = **(int **)(iVar3 + DAT_001738a4);
  if (iVar2 != 0) {
    local_14[0] = 0;
    if (*(char *)(iVar2 + 4) == ':') {
      if (**(char **)(iVar3 + DAT_001738a8) == '\0') {
        *(undefined *)(iVar2 + 4) = 0xff;
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + iVar1));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738b0));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738b4));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738b8));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738bc));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738c0));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738c4));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738c8));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738cc));
        CGsFile::Delete((CGsFile *)local_14,(char *)(iVar3 + DAT_001738d0));
        GsExit(0);
      }
      else if (**(char **)(iVar3 + DAT_001738a8) == '\x01') {
        *(undefined *)(iVar2 + 4) = 0xff;
        GsExit(0);
      }
    }
  }
  return;
}


