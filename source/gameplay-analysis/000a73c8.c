/* CLFigureArchive::Load; research only, not buildable source */

/* CLFigureArchive::Load(CL_Figure*, char const*) */

void CLFigureArchive::Load(CL_Figure *param_1,char *param_2)

{
  uchar *__s;
  int iVar1;
  int iVar2;
  int iVar3;
  void *__src;
  uchar uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  iVar2 = DAT_000a74c0;
  iVar1 = DAT_000a74bc;
  __s = &stack0xffffffec + DAT_000a74bc;
  iVar6 = DAT_000a74c4 + 0xa73e4;
  *(undefined4 *)(&stack0xffffffe0 + DAT_000a74c8 + DAT_000a74bc) =
       **(undefined4 **)(iVar6 + DAT_000a74c0);
  memset(__s,0,0x650);
  iVar3 = GsFSOpen((signed *)param_2,1,1);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_000a746c:
    *(int *)(&stack0xffffffe8 + iVar1) = iVar3;
    __src = (void *)GcxLoadResData(param_2,&stack0xffffffe8 + iVar1);
    bVar7 = false;
    if (__src == (void *)0x0) goto LAB_000a7442;
    *(int *)(&stack0xffffffe4 + iVar1) = iVar3;
    memcpy(&stack0xffffffe4 + iVar1,__src,4);
    uVar5 = *(uint *)(&stack0xffffffe4 + iVar1);
    uVar4 = (uchar)(uVar5 >> 0x18);
    if (7 < uVar5 >> 0x18) {
      GcxFreeResData(__src);
      bVar7 = false;
      goto LAB_000a7442;
    }
    memcpy(__s,(void *)((int)__src + 4),DAT_000a74cc & uVar5);
    GcxFreeResData(__src);
  }
  else {
    if (iVar3 == 0) goto LAB_000a746c;
    *(undefined4 *)(&stack0xffffffe4 + iVar1) = 0;
    MC_fsRead(iVar3,&stack0xffffffe4 + iVar1,4);
    uVar5 = *(uint *)(&stack0xffffffe4 + iVar1);
    uVar4 = (uchar)(uVar5 >> 0x18);
    if (7 < uVar5 >> 0x18) {
      MC_fsClose(iVar3);
      bVar7 = false;
      goto LAB_000a7442;
    }
    MC_fsRead(iVar3,__s,DAT_000a74cc & uVar5);
    MC_fsClose(iVar3);
  }
  iVar3 = SetFigureFromBuf(param_1,__s,uVar4);
  bVar7 = iVar3 != 0;
LAB_000a7442:
  if (*(int *)(&stack0xffffffe0 + DAT_000a74c8 + iVar1) == **(int **)(iVar6 + iVar2)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bVar7);
}


