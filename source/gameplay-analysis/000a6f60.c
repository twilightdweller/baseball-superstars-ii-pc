/* CLFigureArchive::SerializeFigure_V04; research only, not buildable source */

/* CLFigureArchive::SerializeFigure_V04(unsigned char*, CL_Figure*) */

uchar * CLFigureArchive::SerializeFigure_V04(uchar *param_1,CL_Figure *param_2)

{
  int iVar1;
  
  iVar1 = SerializeFigure_V03(param_1,param_2);
  memcpy(param_1 + iVar1,param_2 + 0x234,0x3c);
  return param_1 + iVar1 + (0x3c - (int)param_1);
}


