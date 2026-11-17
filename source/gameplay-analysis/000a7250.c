/* CLFigureArchive::SetFigureFromBuf_V07; research only, not buildable source */

/* CLFigureArchive::SetFigureFromBuf_V07(CL_Figure*, unsigned char*) */

uchar * CLFigureArchive::SetFigureFromBuf_V07(CL_Figure *param_1,uchar *param_2)

{
  int iVar1;
  
  iVar1 = SetFigureFromBuf_V06(param_1,param_2);
  memcpy(param_1 + 0x310,param_2 + iVar1,0x18);
  return param_2 + iVar1 + (0x18 - (int)param_2);
}


