/* CLFigureArchive::SerializeFigure_V01; research only, not buildable source */

/* CLFigureArchive::SerializeFigure_V01(unsigned char*, CL_Figure*) */

uchar * CLFigureArchive::SerializeFigure_V01(uchar *param_1,CL_Figure *param_2)

{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  size_t __n;
  
  memcpy(param_1,param_2,0x84);
  memcpy(param_1 + 0x84,param_2 + 0x84,0x10);
  memcpy(param_1 + 0x94,param_2 + 0x94,0x14);
  memcpy(param_1 + 0xa8,param_2 + 0xa8,0x88);
  memcpy(param_1 + 0x130,param_2 + 0x130,4);
  memcpy(param_1 + 0x134,param_2 + 0x134,4);
  puVar2 = param_1 + 0x138;
  iVar3 = 0;
  do {
    iVar1 = iVar3 + 0x27;
    iVar3 = iVar3 + 1;
    memcpy(puVar2,param_2 + iVar1 * 8,8);
    puVar2 = puVar2 + 8;
  } while (iVar3 != 3);
  puVar2 = param_1 + 0x150;
  if (0 < *(int *)(param_2 + 0x130)) {
    __n = *(int *)(param_2 + 0x130) * 8;
    memcpy(puVar2,*(void **)(param_2 + 0x150),__n);
    puVar2 = puVar2 + __n;
  }
  memcpy(puVar2,param_2 + 0x154,0x20);
  memcpy(puVar2 + 0x20,param_2 + 0x174,0xa4);
  return puVar2 + (0xc4 - (int)param_1);
}


