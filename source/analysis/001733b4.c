/* CBBGLogoRun::EvPointerRelease at 001733b4; decompiler output, not buildable source */

/* CBBGLogoRun::EvPointerRelease(GxPointerPos*) */

void CBBGLogoRun::EvPointerRelease(GxPointerPos *param_1)

{
  if (*(TGXPOINT *)(param_1 + 0x68) != 0) {
    CGsCertification::PointerRelease(*(TGXPOINT *)(param_1 + 0x68));
  }
  return;
}


