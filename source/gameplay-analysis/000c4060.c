/* CCLPitch::GetStrikeZoneFramePos2; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLPitch::GetStrikeZoneFramePos2() */

bbtagPoint2D * CCLPitch::GetStrikeZoneFramePos2(void)

{
  bbtagPoint2D *in_r0;
  int in_r1;
  bbtagPoint2D *pbVar1;
  
  pbVar1 = *(bbtagPoint2D **)(DAT_000c4094 + 0xc4070 + DAT_000c4098);
  CCLProjection::TransformPoint
            (*(CCLProjection **)(in_r1 + 0xcc),pbVar1,
             (tagCLxPoint3 *)(*(int *)(in_r1 + 0x8c) * 0xc + *(int *)(in_r1 + 0x84)));
  *in_r0 = *pbVar1;
  in_r0[1] = pbVar1[1];
  return in_r0;
}


