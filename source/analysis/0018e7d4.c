/* CGsSingleton<CBBGResMgr>::~CGsSingleton at 0018e7d4; decompiler output, not buildable source */

/* CGsSingleton<CBBGResMgr>::~CGsSingleton() */

CGsSingleton<CBBGResMgr> * __thiscall
CGsSingleton<CBBGResMgr>::~CGsSingleton(CGsSingleton<CBBGResMgr> *this)

{
  int iVar1;
  
  iVar1 = DAT_0018e7f4 + 0x18e7e0;
  *(int *)this = *(int *)(iVar1 + DAT_0018e7f8) + 8;
  **(undefined4 **)(iVar1 + DAT_0018e7fc) = 0;
  operator_delete(this);
  return this;
}


