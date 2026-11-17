/* CLFigureArchive::SetFigureFromBuf; research only, not buildable source */

/* CLFigureArchive::SetFigureFromBuf(CL_Figure*, unsigned char*, unsigned char) */

undefined4 CLFigureArchive::SetFigureFromBuf(CL_Figure *param_1,uchar *param_2,uchar param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (7 < param_3) {
    return 0;
  }
  iVar2 = DAT_000a73c0 + 0xa7384 + DAT_000a73c4;
                    /* WARNING: Could not emulate address calculation at 0x000a7390 */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(*(int *)(iVar2 + (uint)param_3 * 4) + iVar2))();
  return uVar1;
}


