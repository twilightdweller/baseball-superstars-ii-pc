/* CCLCurveData::GetCurveDetailPtr; research only, not buildable source */

/* CCLCurveData::GetCurveDetailPtr(int) */

byte * __thiscall CCLCurveData::GetCurveDetailPtr(CCLCurveData *this,int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  CCLCurveData CVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  
  iVar11 = DAT_000c5078 + 0xc4f50;
  if (this[5] == (CCLCurveData)0x0) {
    pbVar8 = *(byte **)this;
    bVar1 = *pbVar8;
    pbVar7 = pbVar8;
  }
  else {
    pbVar8 = *(byte **)this;
    bVar1 = pbVar8[4];
    pbVar7 = pbVar8 + 4;
  }
  if ((uint)bVar1 < (uint)(byte)this[4]) {
    iVar3 = -1;
  }
  else {
    piVar9 = *(int **)(iVar11 + DAT_000c507c);
    memcpy(piVar9,pbVar8 + (uint)(byte)this[4] * 4 + 1 + (uint)(this[5] != (CCLCurveData)0x0) * 4,4)
    ;
    iVar3 = *piVar9;
  }
  iVar2 = DAT_000c507c;
  if (param_1 == 0) {
    return pbVar7 + iVar3 + 2;
  }
  iVar3 = 0;
  iVar10 = 0;
  do {
    CVar5 = this[5];
    uVar6 = (uint)(byte)this[4];
    if (CVar5 == (CCLCurveData)0x0) {
      pbVar7 = *(byte **)this;
      pbVar8 = pbVar7;
      if (*pbVar7 < uVar6) goto LAB_000c5026;
LAB_000c4fa2:
      piVar9 = *(int **)(iVar11 + iVar2);
      memcpy(piVar9,pbVar7 + uVar6 * 4 + 1 + (uint)(CVar5 != (CCLCurveData)0x0) * 4,4);
      CVar5 = this[5];
      uVar4 = (uint)pbVar8[iVar10 + 2 + *piVar9];
      uVar6 = (uint)(byte)this[4];
      pbVar7 = *(byte **)this;
      if (CVar5 != (CCLCurveData)0x0) goto LAB_000c4fd4;
LAB_000c5036:
      pbVar8 = pbVar7;
      if (*pbVar7 < uVar6) goto LAB_000c5040;
LAB_000c4fe0:
      piVar9 = *(int **)(iVar11 + iVar2);
      memcpy(piVar9,pbVar7 + uVar6 * 4 + 1 + (uint)(CVar5 != (CCLCurveData)0x0) * 4,4);
      pbVar8 = pbVar8 + iVar10 + 2 + *piVar9;
    }
    else {
      pbVar7 = *(byte **)this;
      pbVar8 = pbVar7 + 4;
      if (uVar6 <= pbVar7[4]) goto LAB_000c4fa2;
LAB_000c5026:
      uVar4 = (uint)pbVar8[iVar10 + 1];
      if (CVar5 == (CCLCurveData)0x0) goto LAB_000c5036;
LAB_000c4fd4:
      pbVar8 = pbVar7 + 4;
      if (uVar6 <= pbVar7[4]) goto LAB_000c4fe0;
LAB_000c5040:
      pbVar8 = pbVar8 + iVar10 + 1;
    }
    if (param_1 == iVar3 + 1) {
      return pbVar8;
    }
    iVar3 = iVar3 + 1;
    iVar10 = iVar10 + uVar4;
  } while( true );
}


