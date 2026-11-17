/* CBBGLogoRun::EvPointerPress at 001733d4; decompiler output, not buildable source */

/* CBBGLogoRun::EvPointerPress(GxPointerPos*) */

void __thiscall CBBGLogoRun::EvPointerPress(CBBGLogoRun *this,GxPointerPos *param_1)

{
  if (*(CGsCertification **)(this + 0x68) != (CGsCertification *)0x0) {
    CGsCertification::PointerPress
              (*(CGsCertification **)(this + 0x68),
               CONCAT22((short)*(undefined4 *)(param_1 + 4),(short)*(undefined4 *)param_1));
  }
  return;
}


