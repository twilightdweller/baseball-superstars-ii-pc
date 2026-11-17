/* CCLPitch::IsSame; research only, not buildable source */

/* CCLPitch::IsSame(tagPitchType*) */

byte __thiscall CCLPitch::IsSame(CCLPitch *this,tagPitchType *param_1)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0;
  bVar3 = 1;
  do {
    iVar2 = iVar4 + 4;
    iVar5 = iVar5 + (uint)(*(int *)(this + iVar2) == 0);
    piVar1 = (int *)(param_1 + iVar4);
    iVar4 = iVar4 + 4;
    bVar3 = bVar3 & -(*piVar1 == *(int *)(this + iVar2));
  } while (iVar4 != 0x18);
  return bVar3 & -(iVar5 != 0x16);
}


