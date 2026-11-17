#ifndef BS2_PROJECTION_H
#define BS2_PROJECTION_H
#include "pitch_curve.h"
typedef struct { int32_t x,y; } BS2Point2;
typedef struct {
    int32_t scale[3],rotation[3],translation[3],matrix[16];
} BS2Transform;
/* Original CCLMatrix::Update; rotation is Q18 degrees. Matrix slot 11 is
 * preserved, as in the original (normally zero after initialization). */
void bs2_matrix_update(BS2Transform *transform);
typedef struct {
    int32_t matrix[16]; /* Original column-major Q18 matrix. */
    int32_t origin_x,origin_y,scale_x,scale_y;
} BS2Projection;
/* Original CCLMatrix::MatrixMul(tagCLxPoint3*,...). In-place supported. */
void bs2_matrix_point(BS2Point3 *out,const BS2Point3 *point,const int32_t matrix[16]);
/* Original CCLProjection::TransformPoint(CL_xPoint2*,tagCLxPoint3*). */
void bs2_project_point(BS2Point2 *out,const BS2Point3 *point,const BS2Projection *projection);
#endif
