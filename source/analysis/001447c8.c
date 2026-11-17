/* CBBStartUp::CBBStartUp at 001447c8; decompiler output, not buildable source */

/* CBBStartUp::CBBStartUp() */

CBBStartUp * __thiscall CBBStartUp::CBBStartUp(CBBStartUp *this)

{
  int iVar1;
  
  iVar1 = DAT_001447e8;
  CGcxFrame::CGcxFrame((CGcxFrame *)this);
  *(int *)this = *(int *)(iVar1 + 0x1447d8 + DAT_001447ec) + 8;
  Initial();
  return this;
}


