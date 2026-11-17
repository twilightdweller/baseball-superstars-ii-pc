#ifndef BS2_PITCH_PATH_H
#define BS2_PITCH_PATH_H
#include "projection.h"
typedef struct {
    int32_t count,frames,style,mirror,coordinate_format,kind,mode,phase;
    BS2Point3 release,target; /* Q18; release supplied by the scene. */
} BS2PitchSpec;
int32_t bs2_pitch_atan(int32_t value);
/* UpdatePitch calculation after resolving the release position from the scene.
 * Buffers hold count transformed controls and frames+3 trajectory points.
 * Inputs and outputs must not overlap. Returns -1 for rejected input. */
int bs2_pitch_path(const BS2PitchSpec *spec,const BS2Point3 *input,
                   BS2Point3 *controls,BS2Point3 *path);
#endif
