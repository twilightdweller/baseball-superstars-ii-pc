/* CLFigureArchive::SetFigureFromBuf_V03; research only, not buildable source */

/* CLFigureArchive::SetFigureFromBuf_V03(CL_Figure*, unsigned char*) */

uchar * CLFigureArchive::SetFigureFromBuf_V03(CL_Figure *param_1,uchar *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  uchar *puVar4;
  
  memcpy(param_1,param_2,0x84);
  memcpy(param_1 + 0x84,param_2 + 0x84,0x10);
  memcpy(param_1 + 0x94,param_2 + 0x94,0x14);
  memcpy(param_1 + 0xa8,param_2 + 0xa8,0x88);
  if (*(int *)(param_1 + 0x150) != 0) {
    MC_knlFree();
  }
  memcpy(param_1 + 0x130,param_2 + 0x130,4);
  memcpy(param_1 + 0x134,param_2 + 0x134,4);
  puVar4 = param_2 + 0x138;
  if (0 < *(int *)(param_1 + 0x130)) {
    uVar1 = MC_knlCalloc(*(int *)(param_1 + 0x130) << 3);
    *(undefined4 *)(param_1 + 0x150) = uVar1;
  }
  iVar3 = 0;
  do {
    iVar2 = iVar3 + 0x27;
    iVar3 = iVar3 + 1;
    memcpy(param_1 + iVar2 * 8,puVar4,8);
    puVar4 = puVar4 + 8;
  } while (iVar3 != 3);
  puVar4 = param_2 + 0x150;
  if (0 < *(int *)(param_1 + 0x130)) {
    __n = *(int *)(param_1 + 0x130) * 8;
    memcpy(*(void **)(param_1 + 0x150),puVar4,__n);
    puVar4 = puVar4 + __n;
  }
  memcpy(param_1 + 0x154,puVar4,0x20);
  memcpy(param_1 + 0x174,puVar4 + 0x20,0xa4);
  memcpy(param_1 + 0x218,puVar4 + 0xc4,0x1c);
  return puVar4 + (0xe0 - (int)param_2);
}


