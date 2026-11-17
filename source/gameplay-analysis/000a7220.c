/* CLFigureArchive::SetFigureFromBuf_V06; research only, not buildable source */

/* CLFigureArchive::SetFigureFromBuf_V06(CL_Figure*, unsigned char*) */

uchar * CLFigureArchive::SetFigureFromBuf_V06(CL_Figure *param_1,uchar *param_2)

{
  int iVar1;
  uchar *__src;
  
  iVar1 = SetFigureFromBuf_V05(param_1,param_2);
  __src = param_2 + iVar1;
  memcpy(param_1 + 0x280,__src,0x48);
  memcpy(param_1 + 0x2c8,__src + 0x48,0x48);
  return __src + (0x90 - (int)param_2);
}


