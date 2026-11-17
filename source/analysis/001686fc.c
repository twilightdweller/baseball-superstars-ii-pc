/* CBBGMenuRun::CheckTeamLogo at 001686fc; decompiler output, not buildable source */

/* CBBGMenuRun::CheckTeamLogo(char*, int*) */

undefined4 __thiscall CBBGMenuRun::CheckTeamLogo(CBBGMenuRun *this,char *param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = DAT_00168874 + 0x168708;
  pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_00168878));
  if ((pcVar1 == (char *)0x0) &&
     (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_0016887c)), pcVar1 == (char *)0x0)) {
    pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_00168880));
    if ((pcVar1 == (char *)0x0) &&
       (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_00168884)), pcVar1 == (char *)0x0)) {
      pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_00168888));
      if ((pcVar1 == (char *)0x0) &&
         (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_0016888c)), pcVar1 == (char *)0x0)) {
        pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_00168890));
        if ((pcVar1 == (char *)0x0) &&
           (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_00168894)), pcVar1 == (char *)0x0)) {
          pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_00168898));
          if ((pcVar1 == (char *)0x0) &&
             (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_0016889c)), pcVar1 == (char *)0x0)) {
            pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688a0));
            if ((pcVar1 == (char *)0x0) &&
               (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688a4)), pcVar1 == (char *)0x0)) {
              pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688a8));
              if ((pcVar1 == (char *)0x0) &&
                 (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688ac)), pcVar1 == (char *)0x0)) {
                pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688b0));
                if ((pcVar1 == (char *)0x0) &&
                   (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688b4)), pcVar1 == (char *)0x0))
                {
                  pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688b8));
                  if ((pcVar1 == (char *)0x0) &&
                     (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688bc)), pcVar1 == (char *)0x0
                     )) {
                    pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688c0));
                    if ((pcVar1 == (char *)0x0) &&
                       (pcVar1 = strstr(param_1,(char *)(iVar2 + DAT_001688c4)),
                       pcVar1 == (char *)0x0)) {
                      return 0;
                    }
                    *param_2 = 9;
                  }
                  else {
                    *param_2 = 8;
                  }
                }
                else {
                  *param_2 = 7;
                }
              }
              else {
                *param_2 = 6;
              }
            }
            else {
              *param_2 = 5;
            }
          }
          else {
            *param_2 = 4;
          }
        }
        else {
          *param_2 = 3;
        }
      }
      else {
        *param_2 = 2;
      }
    }
    else {
      *param_2 = 1;
    }
  }
  else {
    *param_2 = 0;
  }
  return 1;
}


