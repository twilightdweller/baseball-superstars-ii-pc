/* CCLProjection::UpdateProjection; research only, not buildable source */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CCLProjection::UpdateProjection() */

void CCLProjection::UpdateProjection(void)

{
  CCLProjection *in_r0;
  
  if (*(int *)(in_r0 + 0xdc) == 0) {
    gluPerspective(in_r0,*(long *)(in_r0 + 0xe0),*(long *)(in_r0 + 0xe4),*(long *)(in_r0 + 0xe8),
                   *(long *)(in_r0 + 0xec));
    Update();
  }
  else if (*(int *)(in_r0 + 0xdc) == 1) {
    glOrtho(in_r0,*(long *)(in_r0 + 0xf0),*(long *)(in_r0 + 0xf4),*(long *)(in_r0 + 0xf8),
            *(long *)(in_r0 + 0xfc),*(long *)(in_r0 + 0xe8),*(long *)(in_r0 + 0xec));
    Update();
  }
  return;
}


