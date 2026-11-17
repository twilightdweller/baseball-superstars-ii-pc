/* CLFigureArchive::SerializeFigure_V06; research only, not buildable source */

/* CLFigureArchive::SerializeFigure_V06(unsigned char*, CL_Figure*) */

uchar * CLFigureArchive::SerializeFigure_V06(uchar *param_1,CL_Figure *param_2)

{
  int iVar1;
  uchar *__dest;
  
  iVar1 = SerializeFigure_V05(param_1,param_2);
  __dest = param_1 + iVar1;
  memcpy(__dest,param_2 + 0x280,0x48);
  memcpy(__dest + 0x48,param_2 + 0x2c8,0x48);
  return __dest + (0x90 - (int)param_1);
}


