#ifndef PARTICLE_CAMERA_SCALE_H
#define PARTICLE_CAMERA_SCALE_H
#include "TYPES.H"
#include "COMMON/ASSERT.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
/* Distance (in units) where the particle size ramp starts and ends. */
#define PARTICLE_DEPTH_RAMP_START 16.0f
#define PARTICLE_DEPTH_RAMP_END 2048.0f
#define PARTICLE_DEPTH_RAMP_LENGTH (PARTICLE_DEPTH_RAMP_END - PARTICLE_DEPTH_RAMP_START)
/* Size scale of a particle seen through a camera: a descriptor with flag 4 scales with the distance, ramping from the
 * descriptor's near scale to its far scale, in thousandths of the distance, between
 * PARTICLE_DEPTH_RAMP_START and PARTICLE_DEPTH_RAMP_END (others use 1); the result is corrected for the camera's
 * vertical field of view against the 47.5 degree default. Particle_CameraScale is its out-of-line copy and
 * Particle_BuildMatrix inlines it, as the release build did.
 *
 * What pins the text: the original's debug build. Its read-only data survives in the eu and eu-x ROMs (eu rom
 * 0x14EF58, eu-x 0x143F58): this function's assert strings "DistFromCamera >= 0.0f", "pEffect" and "pCamera", in that
 * order, then its float pool, one word per float literal the -O0 code loads: 16 16 2032 1 | 16 16 2032 1 |
 * 16 2032 16 2032 | 0.001 | 1 | 47.5 4 47.5. This text compiled at -O0 gives exactly those bytes, strings included:
 * the three asserts on entry, the clamp (MAX before the division, MIN with 1 outside, each macro evaluating its
 * operand twice), a second statement that evaluates (distance - 16) / 2032 twice, the 0.001 factor, the else 1, and
 * the field-of-view tail with its division by 4. The release units are built with -ffast-math (config.toml): only
 * that flag turns these divisions into the ROM's reciprocal multiplies (1/2032, 0.25, 1/47.5) and its
 * scale * (1/47.5) * (...) order.
 * The second farness line has no reader: farness is not read after the lerp, and the release build deletes it after
 * register allocation; its compare keeping the distance live until then is why the distance sits in $f5. Nothing in
 * either build read it: the release keeps no trace of its value, its debug build adds no string or literal after it
 * (so no assert or trace used it), its 2032 appears nowhere else in any ROM (no shared macro), and writing it into
 * the distance instead (where the entry assert would cover it) makes gcc copy the argument where Particle_BuildMatrix
 * inlines this function, which the ROM does not do. */
static inline f32 particleCameraScale(Shared_Particle *particle, f32 distFromCamera, GameplayCamera *camera) {
    struct Shared_ParticleDesc *desc;
    f32 scale;
    f32 farness;
    f32 fov;
    ASSERT(distFromCamera >= 0.0f);
    desc = particle->desc;
    ASSERT(desc);
    ASSERT(camera);
    if (desc->flags & 4) {
        scale = distFromCamera;
        farness = RW_MIN_LT(1.0f, RW_MAX_GT(0.0f, scale - PARTICLE_DEPTH_RAMP_START) / PARTICLE_DEPTH_RAMP_LENGTH);
        scale *= desc->scaling->nearScale + (desc->scaling->farScale - desc->scaling->nearScale) * farness;
        farness = RW_MAX_GT(0.0f, (distFromCamera - PARTICLE_DEPTH_RAMP_START) / PARTICLE_DEPTH_RAMP_LENGTH);
        scale *= 0.001f;
    } else {
        scale = 1.0f;
    }
    fov = camera->fovY;
    return scale * ((fov + (47.5f - fov) / 4.0f) / 47.5f);
}
#endif
