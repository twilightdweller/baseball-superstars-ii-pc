/* CCLProjection::SetPrePos; research only, not buildable source */

/* CCLProjection::SetPrePos(tagCLxPoint3) */

void CCLProjection::SetPrePos(tagCLxPoint3 param_1)

{
  undefined4 *puVar1;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  puVar1 = *(undefined4 **)(DAT_000c3488 + 0xc347c + DAT_000c348c);
  puVar1[2] = in_r3;
  puVar1[1] = in_r2;
  *puVar1 = in_r1;
  return;
}


