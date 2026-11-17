/* CLFigureArchive::SerializeFigure_V02; research only, not buildable source */

/* CLFigureArchive::SerializeFigure_V02(unsigned char*, CL_Figure*) */

uchar * CLFigureArchive::SerializeFigure_V02(uchar *param_1,CL_Figure *param_2)

{
  int iVar1;
  
  iVar1 = SerializeFigure_V01(param_1,param_2);
  memcpy(param_1 + iVar1,param_2 + 0x218,0x1c);
  return param_1 + iVar1 + (0x1c - (int)param_1);
}


