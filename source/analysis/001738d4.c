/* CBBGLogoRun::SetChangeRunnable at 001738d4; decompiler output, not buildable source */

/* CBBGLogoRun::SetChangeRunnable(int) */

void __thiscall CBBGLogoRun::SetChangeRunnable(CBBGLogoRun *this,int param_1)

{
  CBBTimer *this_00;
  
  *(int *)(this + 0x60) = param_1;
  this_00 = (CBBTimer *)CBBGTimer::GetInstance();
  CBBTimer::ChangeRunnable(this_00,*(int *)(this + 0x60));
  return;
}


