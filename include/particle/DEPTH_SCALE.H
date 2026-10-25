#ifndef PARTICLE_DEPTH_SCALE_H
#define PARTICLE_DEPTH_SCALE_H
#include "TYPES.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/DEBUG_HELPERS.H"
/* Depth part of the particle size scale, shared by Particle_CameraScale and Particle_BuildMatrix: a descriptor with
 * flag 4 scales with depth, ramping from the distance range's minimum to its maximum (in thousandths of the depth)
 * between 16 and 2048 units; others use 1.
 * The two range watches run before the range is loaded, so the first one tests whatever the registers hold. They
 * have no effect, but the ROM needs them: depth only takes $f5 (and the ramp $f2/$f3) when near, depth, low and high
 * stay live through register allocation and the tests are deleted after it, in jump2 (lanes/REV1-ONE-71 RTL proof;
 * lanes/REV1-ONE-73 maps the reads the ROM needs: near against low and high, and near against depth). */
static inline f32 particleDepthScale(struct Shared_ParticleDesc *desc, f32 depth) {
    f32 near;
    f32 farness;
    f32 scale;
    f32 low;
    f32 high;
    if (desc->flags & 4) {
        scale = depth;
        near = scale - 16.0f;
        RW_DEBUG_RANGE(farness, near, low, high);
        RW_DEBUG_RANGE(farness, near, 0.0f, depth);
        farness = RW_MIN_LT(1.0f, RW_MAX_GT(0.0f, near) * (1.0f / 2032.0f));
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
