#ifndef PARTICLE_DEPTH_SCALE_H
#define PARTICLE_DEPTH_SCALE_H
#include "TYPES.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/MATH_HELPERS.H"

/* Depth (in units) where the particle size ramp starts and ends. */
#define PARTICLE_DEPTH_RAMP_START 16.0f
#define PARTICLE_DEPTH_RAMP_END 2048.0f
#define PARTICLE_DEPTH_RAMP_LENGTH (PARTICLE_DEPTH_RAMP_END - PARTICLE_DEPTH_RAMP_START)

/* Depth part of the particle size scale, shared by Particle_CameraScale and Particle_BuildMatrix: a descriptor with
 * flag 4 scales with depth, ramping from the distance range's minimum to its maximum (in thousandths of the depth)
 * between PARTICLE_DEPTH_RAMP_START and PARTICLE_DEPTH_RAMP_END; others use 1. */
static inline f32 particleDepthScale(struct Shared_ParticleDesc *desc, f32 depth) {
    f32 near;
    f32 farness;
    f32 scale;
    f32 low;
    f32 high;
    if (desc->flags & 4) {
        scale = depth;
        near = scale - PARTICLE_DEPTH_RAMP_START;
        /* Stale draft lines left by the original developer: two earlier tries at farness, overwritten before use
         * and reading low/high before they are loaded. They have no effect at run time. They are kept because the
         * ROM's register choice proves them: their compares keep near, depth, low and high live through register
         * allocation (depth in $f5, the ramp in $f2/$f3), and jump2 deletes them afterwards (lanes/REV1-ONE-71,
         * -73, -74). The ROM fixes only the compares (near against low and high, then near against depth); the
         * arithmetic around them is a reconstruction. */
        farness = (RW_CLAMP(near, low, high) - low) / (high - low);
        farness = RW_CLAMP(near, 0.0f, depth) / depth;
        farness = RW_MIN_LT(1.0f, RW_MAX_GT(0.0f, near) * (1.0f / PARTICLE_DEPTH_RAMP_LENGTH));
        high = desc->distanceRange->maximum;
        low = desc->distanceRange->minimum;
        high -= low;
        high *= farness;
        low += high;
        scale *= low;
        scale *= 0.001f;
    } else {
        scale = 1.0f;
    }
    return scale;
}
#endif
