/* CLFigureArchive::SerializeFigure; research only, not buildable source */

/* CLFigureArchive::SerializeFigure(unsigned char*, CL_Figure*, unsigned char) */

undefined4 CLFigureArchive::SerializeFigure(uchar *param_1,CL_Figure *param_2,uchar param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (7 < param_3) {
    return 0;
  }
  iVar2 = DAT_000a7034 + 0xa6ff8 + DAT_000a7038;
                    /* WARNING: Could not emulate address calculation at 0x000a7004 */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(*(int *)(iVar2 + (uint)param_3 * 4) + iVar2))();
  return uVar1;
}


