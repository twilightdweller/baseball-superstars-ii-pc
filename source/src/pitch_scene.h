#ifndef BS2_PITCH_SCENE_H
#define BS2_PITCH_SCENE_H
#include "pitch_curve.h"
#include <stddef.h>
/* Decoded version-7 CL_Figure bytes, not the serialized asset.
 * Resolves pitcher position zero and the style offset used by UpdatePitch.
 * raised corresponds to CCLFigureMgr byte 0x334. Output is Q18. */
int bs2_pitch_release(const unsigned char *figure,size_t size,int style,int raised,BS2Point3 *out);
int bs2_batting_center(const unsigned char *figure, size_t size, BS2Point3 *center);
int bs2_zone_corners(const unsigned char *figure, size_t size, BS2Point3 *first, BS2Point3 *second);
#endif
