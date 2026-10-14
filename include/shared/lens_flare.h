#ifndef RAGEWARS_LENS_FLARE_H
#define RAGEWARS_LENS_FLARE_H

#include "types.h"

/* Seven flare elements: radius, opacity, and RGB components. */
typedef struct FlareRadii { f32 value[7]; } FlareRadii;
typedef struct FlareAlphas { s32 value[7]; } FlareAlphas;
typedef struct FlareColors { s32 value[21]; } FlareColors;
extern const FlareRadii D_800C344C_de;
extern const FlareAlphas D_800C3468_de;
extern const FlareColors D_800C3484_de;

#endif
