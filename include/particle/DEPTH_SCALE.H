#ifndef PARTICLE_DEPTH_SCALE_H
#define PARTICLE_DEPTH_SCALE_H
#include "TYPES.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/GAMEPLAY_CAMERA.H"

/* Depth (in units) where the particle size ramp starts and ends. */
#define PARTICLE_DEPTH_RAMP_START 16.0f
#define PARTICLE_DEPTH_RAMP_END 2048.0f
#define PARTICLE_DEPTH_RAMP_LENGTH (PARTICLE_DEPTH_RAMP_END - PARTICLE_DEPTH_RAMP_START)

/* Size scale of a particle seen through a camera: a descriptor with flag 4 scales with depth, ramping from the
 * distance range's minimum (near scale) to its maximum (far scale), in thousandths of the depth, between
 * PARTICLE_DEPTH_RAMP_START and PARTICLE_DEPTH_RAMP_END (others use 1); the result is corrected for the camera's
 * vertical field of view against the 47.5 degree default. Particle_CameraScale is its out-of-line copy and
 * Particle_BuildMatrix inlines it, as the release build did.
 *
 * What pins the text: the original's debug build. Its read-only data survives in the eu and eu-x ROMs (eu rom
 * 0x14EF58, eu-x 0x143F58): this function's assert strings "DistFromCamera >= 0.0f", "pEffect" and "pCamera", then
 * its float pool, one word per float literal the -O0 code loads: 16 16 2032 1 | 16 16 2032 1 | 16 2032 16 2032 |
 * 0.001 | 1 | 47.5 4 47.5. This text compiled at -O0 gives exactly that pool: the clamp (MAX before the division,
 * MIN with 1 outside, each macro evaluating its operand twice), a second statement that evaluates
 * (depth - 16) / 2032 twice, the 0.001 factor, the else 1, and the field-of-view tail with its division by 4. The
 * release units are built with -ffast-math (config.toml): only that flag turns these divisions into the ROM's
 * reciprocal multiplies (1/2032, 0.25, 1/47.5) and its scale * (1/47.5) * (...) order.
 * The second farness line is dead: farness is not read after the lerp, and the release build deletes it after
 * register allocation. Its compare keeps depth live until then, which is why depth sits in $f5. Every value it
 * reads is set. The pool cannot tell which macro or which variable that line used; this spelling is one of several
 * that match the pool and the ROM in all five versions (lanes/REV1-ONE-75/RESULT.md lists them). */
static inline f32 particleCameraScale(Shared_Particle *particle, f32 depth, GameplayCamera *camera) {
    struct Shared_ParticleDesc *desc;
    f32 scale;
    f32 farness;
    f32 fov;
    desc = particle->desc;
    if (desc->flags & 4) {
        scale = depth;
        farness = RW_MIN_LT(1.0f, RW_MAX_GT(0.0f, scale - PARTICLE_DEPTH_RAMP_START) / PARTICLE_DEPTH_RAMP_LENGTH);
        scale *= desc->distanceRange->minimum + (desc->distanceRange->maximum - desc->distanceRange->minimum) * farness;
        farness = RW_MAX_GT(0.0f, (depth - PARTICLE_DEPTH_RAMP_START) / PARTICLE_DEPTH_RAMP_LENGTH);
        scale *= 0.001f;
    } else {
        scale = 1.0f;
    }
    fov = camera->fovY;
    return scale * ((fov + (47.5f - fov) / 4.0f) / 47.5f);
}
#endif
