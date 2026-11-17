/* CCLSpline::bp01; research only, not buildable source */

/* CCLSpline::bp01(int, long) */

CCLSpline * __thiscall CCLSpline::bp01(CCLSpline *this,int param_1,long param_2)

{
  longlong lVar1;
  CCLSpline *pCVar2;
  CCLSpline **ppCVar3;
  CCLSpline **ppCVar4;
  longlong lVar5;
  longlong lVar6;
  CCLSpline **local_3c;
  CCLSpline *local_38;
  
  if (param_1 == 0) {
    **(undefined4 **)(DAT_000c1fb8 + 0xc1ec6 + DAT_000c1fbc) = 0x40000;
  }
  else if (0 < param_1) {
    pCVar2 = (CCLSpline *)(0x40000 - param_2);
    ppCVar3 = *(CCLSpline ***)(DAT_000c1fb8 + 0xc1ec6 + DAT_000c1fbc);
    *ppCVar3 = pCVar2;
    ppCVar3[1] = (CCLSpline *)param_2;
    lVar1 = CONCAT44(DAT_000c1fb4,DAT_000c1fb0);
    this = pCVar2;
    if (param_1 != 1) {
      this = (CCLSpline *)(param_1 + -1);
      local_38 = (CCLSpline *)0x0;
      ppCVar4 = ppCVar3;
      do {
        local_3c = ppCVar4 + 1;
        lVar5 = __aeabi_lmul(param_2,param_2 >> 0x1f,*local_3c,(int)*local_3c >> 0x1f);
        ppCVar4[2] = (CCLSpline *)
                     ((uint)(lVar5 + lVar1) >> 0x12 |
                     (int)((ulonglong)(lVar5 + lVar1) >> 0x20) * 0x4000);
        ppCVar4 = ppCVar3 + (int)local_38;
        do {
          lVar5 = __aeabi_lmul(pCVar2,(int)pCVar2 >> 0x1f,ppCVar4[1],(int)ppCVar4[1] >> 0x1f);
          lVar6 = __aeabi_lmul(param_2,param_2 >> 0x1f,*ppCVar4,(int)*ppCVar4 >> 0x1f);
          ppCVar4[1] = (CCLSpline *)
                       (((uint)(lVar5 + lVar1) >> 0x12 |
                        (int)((ulonglong)(lVar5 + lVar1) >> 0x20) * 0x4000) +
                       ((uint)(lVar6 + lVar1) >> 0x12 |
                       (int)((ulonglong)(lVar6 + lVar1) >> 0x20) * 0x4000));
          ppCVar4 = ppCVar4 + -1;
        } while (ppCVar4 != ppCVar3 + -1);
        lVar5 = __aeabi_lmul(*ppCVar3,(int)*ppCVar3 >> 0x1f,pCVar2,(int)pCVar2 >> 0x1f);
        lVar5 = lVar5 + CONCAT44(DAT_000c1fb4,DAT_000c1fb0);
        *ppCVar3 = (CCLSpline *)((uint)lVar5 >> 0x12 | (int)((ulonglong)lVar5 >> 0x20) * 0x4000);
        local_38 = local_38 + 1;
        ppCVar4 = local_3c;
      } while (local_38 != this);
    }
  }
  return this;
}


