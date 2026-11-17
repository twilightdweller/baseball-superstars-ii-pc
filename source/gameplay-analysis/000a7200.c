/* CLFigureArchive::SetFigureFromBuf_V05; research only, not buildable source */

/* CLFigureArchive::SetFigureFromBuf_V05(CL_Figure*, unsigned char*) */

uchar * CLFigureArchive::SetFigureFromBuf_V05(CL_Figure *param_1,uchar *param_2)

{
  int iVar1;
  
  iVar1 = SetFigureFromBuf_V04(param_1,param_2);
  memcpy(param_1 + 0x270,param_2 + iVar1,0x10);
  return param_2 + iVar1 + (0x10 - (int)param_2);
}


