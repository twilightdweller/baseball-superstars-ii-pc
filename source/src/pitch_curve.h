#ifndef BS2_PITCH_CURVE_H
#define BS2_PITCH_CURVE_H
#include <stdint.h>
typedef struct { int32_t x,y,z; } BS2Point3;
/* Port of CCLSpline::Bezier. Coordinates are signed Q18 fixed point.
 * Non-overlapping input/output; caller allocates frames output points.
 * Returns -1 for unsupported/unsafe arguments without writing output. */
int bs2_pitch_bezier(const BS2Point3 *points,int count,BS2Point3 *out,
                     int frames,int mode,int phase_degrees);
int bs2_pitch_cardinal(const BS2Point3 *points,int count,BS2Point3 *out,int frames);
#endif
