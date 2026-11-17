/* CLFigureArchive::SerializeFigure_V05; research only, not buildable source */

/* CLFigureArchive::SerializeFigure_V05(unsigned char*, CL_Figure*) */

uchar * CLFigureArchive::SerializeFigure_V05(uchar *param_1,CL_Figure *param_2)

{
  int iVar1;
  
  iVar1 = SerializeFigure_V04(param_1,param_2);
  memcpy(param_1 + iVar1,param_2 + 0x270,0x10);
  return param_1 + iVar1 + (0x10 - (int)param_1);
}


