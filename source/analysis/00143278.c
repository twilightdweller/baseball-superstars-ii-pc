/* CBBStartUp::DrawSystemPopupBox at 00143278; decompiler output, not buildable source */

/* CBBStartUp::DrawSystemPopupBox(int, int, int, int, void*) */

void CBBStartUp::DrawSystemPopupBox(int param_1,int param_2,int param_3,int param_4,void *param_5)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  CGxPZxMgr *pCVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  CGsGraphics *this;
  int iVar15;
  int local_58;
  int local_54;
  int local_4c [4];
  CGsStringBBF aCStack_3c [12];
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar10 = DAT_00143604;
  CGsStringBBF::CGsStringBBF(aCStack_3c,true);
  this = **(CGsGraphics ***)(iVar10 + 0x1432a8 + DAT_00143608);
  pCVar11 = *(CGxPZxMgr **)(**(int **)(iVar10 + 0x1432a8 + DAT_0014360c) + 4);
  pcVar3 = (char *)CPopup::GetText();
  iVar10 = DAT_0014361c;
  cVar2 = *(char *)((int)param_5 + DAT_00143610);
  if (param_4 < *(short *)((int)param_5 + DAT_00143614)) {
    local_2c = 0;
    iVar10 = param_1 + 2;
    local_30 = 0;
    uVar4 = MC_grpGetPixelFromRGB(0x2a,0x96,0xf0);
    iVar14 = param_2 + 2;
    CGsGraphics::DrawFillRect(this,iVar10,iVar14,param_3 + -4,param_4 + -4,uVar4);
    if (cVar2 == '\x02') {
      GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar11,1);
      if (local_2c._2_2_ < param_4) {
        DrawPZX(pCVar11,1,1,param_1 + -1 + (param_3 - (short)local_2c) / 2,iVar14,0,0,'\0','\x01');
      }
    }
    else if (cVar2 == '\x01') {
      GetPzxSize((CGxPZxMgr *)&local_30,(int)pCVar11,0);
      if ((local_2c._2_2_ < param_4) && ((short)local_2c < param_3)) {
        DrawPZX(pCVar11,0,1,param_1 + 3,param_2 + 3,0,0,'\0','\x01');
      }
    }
    local_54 = param_1 + 3;
    local_58 = param_2 + 3;
    uVar4 = MC_grpGetPixelFromRGB(0xf5,0xf5,0xf5);
    CGsGraphics::DrawRect(this,iVar10,iVar14,param_3 + -4,param_4 + -4,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(6,0x3f,0x84);
    iVar15 = param_1 + param_3;
    iVar5 = iVar15 + -2;
    CGsGraphics::DrawLine(this,iVar10,param_2,iVar5,param_2,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(6,0x3f,0x84);
    iVar7 = param_2 + 1;
    iVar12 = iVar15 + -1;
    iVar6 = param_1 + 1;
    CGsGraphics::DrawLine(this,iVar6,iVar7,iVar12,iVar7,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(5,0x40,0x86);
    iVar8 = param_4 + param_2;
    iVar9 = iVar8 + -2;
    CGsGraphics::DrawLine(this,param_1,iVar14,param_1,iVar9,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(5,0x40,0x86);
    iVar13 = iVar8 + -1;
    CGsGraphics::DrawLine(this,iVar6,iVar7,iVar6,iVar13,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(5,0x40,0x86);
    CGsGraphics::DrawLine(this,iVar15,iVar14,iVar15,iVar9,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(5,0x40,0x86);
    CGsGraphics::DrawLine(this,iVar12,iVar7,iVar12,iVar13,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(6,0x41,0x85);
    CGsGraphics::DrawLine(this,iVar10,iVar8,iVar5,iVar8,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(6,0x41,0x85);
    CGsGraphics::DrawLine(this,iVar6,iVar13,iVar12,iVar13,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(6,0x3f,0x84);
    CGsGraphics::PutPixel(this,iVar10,iVar14,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(6,0x3f,0x84);
    CGsGraphics::PutPixel(this,iVar5,iVar14,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(6,0x41,0x85);
    CGsGraphics::PutPixel(this,iVar10,iVar9,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(6,0x41,0x85);
    CGsGraphics::PutPixel(this,iVar5,iVar9,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(0xf5,0xf5,0xf5);
    CGsGraphics::PutPixel(this,local_54,local_58,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(0xf5,0xf5,0xf5);
    CGsGraphics::PutPixel(this,iVar15 + -3,local_58,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(0xf5,0xf5,0xf5);
    CGsGraphics::PutPixel(this,local_54,iVar8 + -3,uVar4);
    uVar4 = MC_grpGetPixelFromRGB(0xf5,0xf5,0xf5);
    CGsGraphics::PutPixel(this,iVar15 + -3,iVar8 + -3,uVar4);
    if ((*pcVar3 == '\0') && (*(char *)((int)param_5 + DAT_00143618) != '\0')) {
      uVar4 = MC_grpGetPixelFromRGB(8,0x40,0x95);
      CGsGraphics::DrawFillRoundRect
                (this,param_1 + 5,param_2 + 0x16,param_3 + -10,param_4 + -0x1e,2,uVar4);
      uVar4 = MC_grpGetPixelFromRGB(0x84,0xc6,0xff);
      CGsGraphics::DrawRoundRect
                (this,param_1 + 5,param_2 + 0x16,param_3 + -10,param_4 + -0x1e,2,uVar4);
    }
    goto LAB_0014350a;
  }
  CGsStringBBF::DrawBBF
            (aCStack_3c,pcVar3,(param_1 + 10) - param_3 / 2,0,param_3 + -0x14,-1,-1,0,-1,
             (tagGsBBFDrawInfo *)local_4c);
  iVar14 = *(int *)((int)param_5 + iVar10);
  if (iVar14 != 0) {
    if (iVar14 == 1) {
      DrawPZX(pCVar11,0x46,1,param_1,param_2,0,0,'\0','\x01');
      iVar14 = *(int *)((int)param_5 + iVar10);
    }
    if (iVar14 == 2) {
      DrawPZX(pCVar11,0x60,1,param_1,param_2,0,0,'\0','\x01');
      iVar14 = *(int *)((int)param_5 + DAT_001437cc);
    }
    if (iVar14 == 3) {
      DrawPZX(pCVar11,0x3f,1,param_1,param_2,0,0,'\0','\x01');
      iVar14 = *(int *)((int)param_5 + DAT_001437cc);
    }
    if (iVar14 == 4) {
      DrawPZX(pCVar11,0x86,1,param_1,param_2,0,0,'\0','\x01');
    }
    goto LAB_0014350a;
  }
  cVar1 = *(char *)((int)param_5 + 4);
  if (cVar1 == '\x17') {
LAB_001435e6:
    DrawPZX(pCVar11,0x4d,1,param_1,param_2,0,0,'\0','\x01');
  }
  else {
    if (cVar1 < '\x18') {
      if ((byte)(cVar1 - 5U) < 2) goto LAB_001435e6;
    }
    else if (cVar1 == '\'') goto LAB_001435e6;
    iVar10 = local_4c[0] * 0xe + 10;
    if ((cVar2 == '\x02') || (cVar2 != '\x01')) {
      if (iVar10 < 0x88) {
        if (iVar10 < 0x5b) {
          DrawPZX(pCVar11,0x32,1,param_1,param_2,0,0,'\0','\x01');
        }
        else {
          DrawPZX(pCVar11,0x34,1,param_1,param_2,0,0,'\0','\x01');
        }
      }
      else {
        DrawPZX(pCVar11,0x35,1,param_1,param_2,0,0,'\0','\x01');
      }
    }
    else {
      DrawPZX(pCVar11,0x33,1,param_1,param_2,0,0,'\0','\x01');
    }
  }
LAB_0014350a:
  CGsStringBBF::~CGsStringBBF(aCStack_3c);
  return;
}


