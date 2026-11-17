/* CCLCurveData::Load; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLCurveData::Load() */

undefined4 CCLCurveData::Load(void)

{
  int **in_r0;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_1c [2];
  
  iVar1 = DAT_000c4ef8;
  Delete();
  local_1c[0] = 0;
  iVar1 = GcxLoadResData(iVar1 + 0xc4ebe + DAT_000c4efc,local_1c);
  uVar2 = 0;
  if (iVar1 != 0) {
    piVar3 = (int *)GxUncompressZT1(iVar1);
    GcxFreeResData(iVar1);
    *in_r0 = piVar3;
    *(undefined *)((int)in_r0 + 5) = 0;
    uVar2 = 1;
    if (*piVar3 == DAT_000c4f00) {
      *(undefined *)((int)in_r0 + 5) = 1;
    }
  }
  return uVar2;
}


