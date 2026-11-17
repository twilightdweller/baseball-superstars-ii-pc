/* CCLFigureMgr::ToVirtual; research only, not buildable source */

/* CCLFigureMgr::ToVirtual(bbtagPoint2D) */

bbtagPoint2D CCLFigureMgr::ToVirtual(bbtagPoint2D param_1)

{
  int iVar1;
  int in_r1;
  int in_r2;
  int in_r3;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
  iVar3 = *(int *)(in_r1 + 0xc);
  lVar4 = __aeabi_lmul(iVar3 << 0x12,(iVar3 << 0x12) >> 0x1f,*(int *)(in_r1 + 8),
                       *(int *)(in_r1 + 8) >> 0x1f);
  lVar4 = lVar4 + CONCAT44(DAT_000a5c1c,DAT_000a5c18);
  iVar2 = (int)(((uint)lVar4 >> 0x12 | (int)((ulonglong)lVar4 >> 0x20) * 0x4000) + 0x20000) >> 0x12;
  iVar1 = __aeabi_idiv(iVar2 * *(int *)(in_r1 + 0x38),iVar3);
  iVar2 = __aeabi_idiv(iVar2 * in_r2,iVar3);
  *(int *)param_1 = iVar1 - iVar2;
  *(undefined4 *)(param_1 + 4) = 0;
  iVar2 = *(int *)(in_r1 + 0x10);
  lVar4 = __aeabi_lmul(iVar2 << 0x12,(iVar2 << 0x12) >> 0x1f,*(int *)(in_r1 + 8),
                       *(int *)(in_r1 + 8) >> 0x1f);
  lVar4 = lVar4 + CONCAT44(DAT_000a5c1c,DAT_000a5c18);
  iVar3 = (int)(((uint)lVar4 >> 0x12 | (int)((ulonglong)lVar4 >> 0x20) * 0x4000) + 0x20000) >> 0x12;
  iVar1 = __aeabi_idiv(iVar3 * in_r3,iVar2);
  iVar2 = __aeabi_idiv(iVar3 * *(int *)(in_r1 + 0x3c),iVar2);
  *(int *)(param_1 + 8) = iVar1 - iVar2;
  return param_1;
}


