#ifndef BS2_CAMERA_H
#define BS2_CAMERA_H
#include "projection.h"
#include <stddef.h>
int bs2_camera_from_figure(const unsigned char *figure,size_t size,int preset,BS2Projection *out);
#endif
