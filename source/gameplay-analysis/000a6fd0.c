/* CLFigureArchive::SerializeFigure_V07; research only, not buildable source */

/* CLFigureArchive::SerializeFigure_V07(unsigned char*, CL_Figure*) */

uchar * CLFigureArchive::SerializeFigure_V07(uchar *param_1,CL_Figure *param_2)

{
  int iVar1;
  
  iVar1 = SerializeFigure_V06(param_1,param_2);
  memcpy(param_1 + iVar1,param_2 + 0x310,0x18);
  return param_1 + iVar1 + (0x18 - (int)param_1);
}


