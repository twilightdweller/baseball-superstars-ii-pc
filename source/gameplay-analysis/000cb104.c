/* CLMath::xAtan; research only, not buildable source */

/* CLMath::xAtan(long, long) */

int CLMath::xAtan(long param_1,long param_2)

{
  int iVar1;
  
  if ((param_2 != 0) || (iVar1 = 0, param_1 != 0)) {
    if ((uint)param_1 < 0x21) {
      iVar1 = 0x1680000;
    }
    else {
      iVar1 = __aeabi_ldivmod(param_2 * 0x40000,(param_2 >> 0x1f) << 0x12 | (uint)param_2 >> 0xe,
                              param_1,param_1 >> 0x1f);
      iVar1 = xAtan(iVar1 + (iVar1 >> 0x1f) ^ iVar1 >> 0x1f);
    }
    if (param_2 < 0) {
      if (param_1 < 0) {
        iVar1 = iVar1 + 0x2d00000;
      }
      else {
        iVar1 = 0x5a00000 - iVar1;
      }
    }
    else if (param_1 < 0) {
      iVar1 = 0x2d00000 - iVar1;
    }
  }
  return iVar1;
}


