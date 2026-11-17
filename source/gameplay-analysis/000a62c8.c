/* CCLFigureMgr::Load; research only, not buildable source */

/* CCLFigureMgr::Load(char const*) */

void __thiscall CCLFigureMgr::Load(CCLFigureMgr *this,char *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = DAT_000a62fc;
  CLFigureArchive::Load((CL_Figure *)(this + 4),param_1);
  puVar2 = *(undefined4 **)(iVar1 + 0xa62da + DAT_000a6300);
  uVar3 = *(undefined4 *)(this + 0x9c);
  uVar4 = *(undefined4 *)(this + 0xa0);
  *puVar2 = *(undefined4 *)(this + 0x98);
  puVar2[1] = uVar3;
  puVar2[2] = uVar4;
  uVar3 = *(undefined4 *)(this + 0xa8);
  puVar2[3] = *(undefined4 *)(this + 0xa4);
  puVar2[4] = uVar3;
  iVar1 = DAT_000a6304;
  *(int *)(this + 0x338) = DAT_000a6304;
  *(int *)(this + 0x33c) = iVar1 + 0x1c2;
  return;
}


