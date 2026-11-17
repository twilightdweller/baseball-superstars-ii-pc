/* CBBStartUp::EvAppResume at 00143f9c; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBStartUp::EvAppResume() */

void CBBStartUp::EvAppResume(void)

{
  int in_r0;
  int iVar1;
  
  CGsSound::SetMuteKeyton
            ((uchar)**(undefined4 **)(DAT_00143fdc + 0x143fa8 + DAT_00143fe0),'\x01','\x01');
  if (*(int *)(in_r0 + 0x80) != 0) {
    iVar1 = CBBGDataMgr::GetOption();
    if (iVar1 != 0) {
      CBBGOption::Apply();
    }
    (**(code **)(**(int **)(in_r0 + 0x80) + 0x18))();
  }
  return;
}


