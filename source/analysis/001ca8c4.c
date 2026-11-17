/* CGxZeroPZDParser::Open at 001ca8c4; decompiler output, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CGxZeroPZDParser::Open() */

undefined4 CGxZeroPZDParser::Open(void)

{
  int *in_r0;
  int iVar1;
  int iVar2;
  CGxStream *pCVar3;
  undefined4 uStack_18;
  uint uStack_14;
  
  CGxPZxParserBase::Open();
  if ((int)((uint)*(byte *)((int)in_r0 + 0x2a) << 0x1c) < 0) {
    return 1;
  }
  iVar1 = (**(code **)(*in_r0 + 0x14))(in_r0,1);
  if (iVar1 != 0) {
    if (*(char *)(in_r0[5] + 3) != '\0') {
      (*(code *)((undefined4 *)in_r0[3])[7])(*(undefined4 *)in_r0[3],in_r0 + 0xd,1);
      iVar1 = MC_knlCalloc((uint)*(byte *)(in_r0 + 0xd) << 1);
      in_r0[0xb] = iVar1;
      (*(code *)((undefined4 *)in_r0[3])[7])
                (*(undefined4 *)in_r0[3],iVar1,(uint)*(byte *)(in_r0 + 0xd) << 1);
      *(byte *)((int)in_r0 + 0x2a) = *(byte *)((int)in_r0 + 0x2a) | 4;
    }
    if (*(char *)((int)in_r0 + 0x35) == '\0') {
LAB_001ca92c:
      iVar1 = (*(code *)((undefined4 *)in_r0[3])[9])(*(undefined4 *)in_r0[3],1,0);
      in_r0[1] = iVar1;
      *(byte *)((int)in_r0 + 0x2a) = *(byte *)((int)in_r0 + 0x2a) | 8;
      return 1;
    }
    uStack_14 = 0;
    uStack_18 = 0;
    (*(code *)((undefined4 *)in_r0[3])[7])(*(undefined4 *)in_r0[3],&uStack_14,4);
    (*(code *)((undefined4 *)in_r0[3])[7])(*(undefined4 *)in_r0[3],&uStack_18,4);
    iVar1 = MC_knlCalloc(uStack_18);
    if (iVar1 != 0) {
      (*(code *)((undefined4 *)in_r0[3])[7])(*(undefined4 *)in_r0[3],iVar1,uStack_18);
      iVar2 = MC_knlCalloc(uStack_14);
      in_r0[0xc] = iVar2;
      if (iVar2 == 0) {
        MC_knlFree(iVar1);
        return 0;
      }
      iVar2 = GxUncompress(iVar2,&uStack_14,iVar1,uStack_18);
      if (iVar2 != 0) {
        MC_knlFree(iVar1);
        MC_knlFree(in_r0[0xc]);
        return 0;
      }
      MC_knlFree(iVar1);
      if (*(char *)(in_r0 + 4) != '\0') {
        pCVar3 = (CGxStream *)in_r0[3];
        if (pCVar3 != (CGxStream *)0x0) {
          CGxStream::~CGxStream(pCVar3);
          operator_delete(pCVar3);
          in_r0[3] = 0;
        }
        *(undefined *)(in_r0 + 4) = 0;
      }
      in_r0[3] = 0;
      pCVar3 = (CGxStream *)operator_new(0x28);
      CGxStream::CGxStream(pCVar3);
      in_r0[3] = (int)pCVar3;
      if (pCVar3 != (CGxStream *)0x0) {
        iVar1 = CGxStream::InitStream(pCVar3,(void *)in_r0[0xc],uStack_14 | 0x10000000);
        if (iVar1 == 0) {
          pCVar3 = (CGxStream *)in_r0[3];
          if (pCVar3 != (CGxStream *)0x0) {
            CGxStream::~CGxStream(pCVar3);
            operator_delete(pCVar3);
          }
          in_r0[3] = 0;
          return 0;
        }
        *(undefined *)(in_r0 + 4) = 1;
        goto LAB_001ca92c;
      }
    }
  }
  return 0;
}


