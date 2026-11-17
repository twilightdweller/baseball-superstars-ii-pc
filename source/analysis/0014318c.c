/* CBBStartUp::Initial at 0014318c; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CBBStartUp::Initial() */

void CBBStartUp::Initial(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = DAT_001431e8 + 0x143196;
  **(undefined4 **)(iVar2 + DAT_001431ec) = 0;
  **(undefined4 **)(iVar2 + DAT_001431f0) = 0;
  **(undefined4 **)(iVar2 + DAT_001431f4) = 0;
  **(undefined4 **)(iVar2 + DAT_001431f8) = 0;
  **(undefined4 **)(iVar2 + DAT_001431fc) = 0;
  puVar1 = *(undefined4 **)(iVar2 + DAT_00143200);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 1;
  *(undefined *)(puVar1 + 3) = 0;
  *(undefined *)((int)puVar1 + 0xd) = 0;
  *(undefined *)((int)puVar1 + 0xe) = 0;
  *(undefined *)((int)puVar1 + 0xf) = 0;
  *(undefined *)(puVar1 + 4) = 0;
  *(undefined *)((int)puVar1 + 0x11) = 0;
  **(undefined4 **)(iVar2 + DAT_00143204) = 0;
  **(undefined4 **)(iVar2 + DAT_00143208) = 0;
  **(undefined4 **)(iVar2 + DAT_0014320c) = 0;
  **(undefined **)(iVar2 + DAT_00143210) = 0;
  **(undefined **)(iVar2 + DAT_00143214) = 0;
  return;
}


