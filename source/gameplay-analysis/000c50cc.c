/* CCLPitch::SetPitchData; research only, not buildable source */

/* CCLPitch::SetPitchData(tagPitchType*, tagPitcherStyle, int) */

undefined4 __thiscall
CCLPitch::SetPitchData(CCLPitch *this,tagPitchType *param_1,tagPitcherStyle param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte **this_00;
  CCLPitchCurve *pCVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  int *__dest;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  CCLPitch *pCVar12;
  int local_44;
  
  iVar8 = DAT_000c529c + 0xc50e2;
  *(tagPitcherStyle *)this = param_2;
  if ((int)param_2 < 6) {
    param_2 = param_2 & 0xfffffffe;
  }
  DeletePitchCurves();
  this_00 = (byte **)CreateCurveData();
  iVar2 = DAT_000c52a0;
  iVar10 = 0;
  pCVar12 = this;
  do {
    while( true ) {
      *(undefined4 *)(this + iVar10 + 4) = *(undefined4 *)(param_1 + iVar10);
      iVar5 = *(int *)(param_1 + iVar10);
      if (iVar5 != 0x16) break;
      *(undefined *)(this_00 + 1) = 0x15;
      iVar5 = param_3 + 8;
      if (param_3 < 5) {
        iVar5 = (param_3 + -1) * 3 + 1 + (int)param_2 / 2;
      }
      pCVar3 = (CCLPitchCurve *)operator_new(0xc);
      CCLPitchCurve::CCLPitchCurve(pCVar3);
      CCLCurveData::SetPitchCurve((CCLCurveData *)this_00,pCVar3,iVar5);
      iVar5 = CCLCurveData::GetCurveDetailPtr((CCLCurveData *)this_00,iVar5);
      iVar10 = iVar10 + 4;
      CCLPitchCurve::CreatePointBuffer
                (pCVar3,(uchar *)(iVar5 + (6 - (uint)(*(char *)((int)this_00 + 5) == '\0'))),
                 (uint)(byte)pCVar3[2]);
      *(CCLPitchCurve **)(pCVar12 + 0x1c) = pCVar3;
      pCVar12 = pCVar12 + 0x10;
      if (iVar10 == 0x18) goto LAB_000c5196;
    }
    if (iVar5 != 0) {
      uVar6 = iVar5 - 1U & 0xff;
      *(char *)(this_00 + 1) = (char)(iVar5 - 1U);
      if (*(char *)((int)this_00 + 5) == '\0') {
        pbVar7 = *this_00;
        pbVar11 = pbVar7;
        if (uVar6 <= *pbVar7) goto LAB_000c51d2;
LAB_000c528a:
        iVar5 = -1;
      }
      else {
        pbVar7 = *this_00;
        pbVar11 = pbVar7 + 4;
        if (pbVar7[4] < uVar6) goto LAB_000c528a;
LAB_000c51d2:
        __dest = *(int **)(iVar8 + iVar2);
        memcpy(__dest,pbVar7 + uVar6 * 4 + 1 + (uint)(*(char *)((int)this_00 + 5) != '\0') * 4,4);
        iVar5 = *__dest;
      }
      bVar1 = pbVar11[iVar5 + 1];
      if (bVar1 != 0) {
        local_44 = 0;
        iVar9 = 1;
        iVar5 = iVar10;
        do {
          iVar4 = CCLCurveData::GetCurveDetailPtr((CCLCurveData *)this_00,iVar9);
          if (param_2 == *(byte *)(iVar4 + 4)) {
            pCVar3 = (CCLPitchCurve *)operator_new(0xc);
            CCLPitchCurve::CCLPitchCurve(pCVar3);
            CCLCurveData::SetPitchCurve((CCLCurveData *)this_00,pCVar3,iVar9);
            iVar4 = CCLCurveData::GetCurveDetailPtr((CCLCurveData *)this_00,iVar9);
            CCLPitchCurve::CreatePointBuffer
                      (pCVar3,(uchar *)(iVar4 + (6 - (uint)(*(char *)((int)this_00 + 5) == '\0'))),
                       (uint)(byte)pCVar3[2]);
            *(CCLPitchCurve **)(this + (iVar5 + 6) * 4 + 4) = pCVar3;
            local_44 = local_44 + 1;
            iVar5 = local_44 + iVar10;
          }
        } while ((iVar5 < 0x18) && (iVar9 = iVar9 + 1, iVar9 <= (int)(uint)bVar1));
      }
    }
    iVar10 = iVar10 + 4;
    pCVar12 = pCVar12 + 0x10;
  } while (iVar10 != 0x18);
LAB_000c5196:
  if (this_00 != (byte **)0x0) {
    CCLCurveData::~CCLCurveData((CCLCurveData *)this_00);
    operator_delete(this_00);
  }
  return 1;
}


