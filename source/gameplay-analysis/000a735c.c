/* CLFigureArchive::SetFigureFromBuf_V02; research only, not buildable source */

/* CLFigureArchive::SetFigureFromBuf_V02(CL_Figure*, unsigned char*) */

uchar * CLFigureArchive::SetFigureFromBuf_V02(CL_Figure *param_1,uchar *param_2)

{
  int iVar1;
  
  iVar1 = SetFigureFromBuf_V01(param_1,param_2);
  memcpy(param_1 + 0x218,param_2 + iVar1,0x1c);
  return param_2 + iVar1 + (0x1c - (int)param_2);
}


