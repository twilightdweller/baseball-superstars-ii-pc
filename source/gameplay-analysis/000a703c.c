/* CLFigureArchive::Save; research only, not buildable source */

/* CLFigureArchive::Save(CL_Figure*, char const*) */

void CLFigureArchive::Save(CL_Figure *param_1,char *param_2)

{
  uchar *__s;
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint *puVar7;
  undefined *puVar8;
  
  iVar2 = DAT_000a70d4;
  iVar1 = DAT_000a70d0;
  puVar7 = (uint *)(&stack0xffffffe4 + DAT_000a70d0);
  puVar8 = &stack0xffffffe4 + DAT_000a70d0;
  __s = &stack0xffffffe8 + DAT_000a70d0;
  iVar6 = DAT_000a70d8 + 0xa7056;
  *(undefined4 *)(&stack0xffffffe4 + DAT_000a70dc + DAT_000a70d0) =
       **(undefined4 **)(iVar6 + DAT_000a70d4);
  memset(__s,0,0x650);
  uVar3 = SerializeFigure(__s,param_1,'\a');
  iVar4 = GsFSOpen((signed *)param_2,2,1);
  if ((iVar4 < 0) || (iVar4 == 0)) {
    uVar5 = 0;
  }
  else {
    *puVar7 = uVar3 | 0x7000000;
    MC_fsWrite(iVar4,puVar8,4);
    MC_fsWrite(iVar4,__s,uVar3);
    MC_fsClose(iVar4);
    uVar5 = 1;
  }
  if (*(int *)(&stack0xffffffe4 + DAT_000a70dc + iVar1) == **(int **)(iVar6 + iVar2)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}


