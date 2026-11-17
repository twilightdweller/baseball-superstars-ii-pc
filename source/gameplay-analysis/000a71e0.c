/* CLFigureArchive::SetFigureFromBuf_V04; research only, not buildable source */

/* CLFigureArchive::SetFigureFromBuf_V04(CL_Figure*, unsigned char*) */

uchar * CLFigureArchive::SetFigureFromBuf_V04(CL_Figure *param_1,uchar *param_2)

{
  int iVar1;
  
  iVar1 = SetFigureFromBuf_V03(param_1,param_2);
  memcpy(param_1 + 0x234,param_2 + iVar1,0x3c);
  return param_2 + iVar1 + (0x3c - (int)param_2);
}


