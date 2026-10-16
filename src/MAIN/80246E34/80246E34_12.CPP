#include "common/unused.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80246E34.h"
#include "TYPES.H"
#include "math_helpers.h"
/* Draws an object's cast shadow: objects without shadow flag 0x10000000 get the blob shadow of
 * func_8024ADD0_de; otherwise, once per frame the shadow model from func_802799C0_de is built for an object above
 * the ground: the light of the current view (direction from its signed bytes, strength from its colour)
 * is sampled at the object through func_80268A40_de, the shadow alpha is 128 plus 56 per unit of light (faded
 * by D_800D15F0 during a fade), the light direction is kept at least 0.15 from horizontal, and the shadow
 * is projected along it onto a plane just below the object (0.9 of its height up to 512), grown by 0.003
 * per unit of height, turned by the object's orientation and placed on the ground; the shadow is then
 * submitted through func_8024BA7C_de. */
extern char D_8011FFB0;
extern char D_8013B1A8;
extern s32 D_800D297C;
extern s32 D_800D15E0;
extern f32 D_800D15F0;
extern s32 func_8024E158_de(void);
extern f32 func_8024E650_de(char *, s32);
extern void *func_802799C0_de(void *, s32);
extern f32 func_802B72B0_de(f32);
extern void func_80268A40_de(void *, Vec3, Vec3 *, f32 *);
extern void func_8027207C_de(Vec3 *);
extern void func_8027310C_de(f32 *, Vec3 *, f32);
extern void func_80273448_de(void *, f32, f32, f32);
extern void func_802735A8_de(f32 *, f32, f32, f32);
extern void func_80274244_de(void *, f32 *);
extern void func_8026F620_de(void *, f32 *, f32 *);
extern void func_8024BA7C_de(char *, char *, void *, u8);
extern void func_8024ADD0_de(char *, s32, s32);
void func_8024AA18_de(char *obj, s32 unused, char *info) {
    Vec3 dir;
    f32 projection[16];
    f32 turn[16];
    f32 strength;
    f32 ground;
    f32 height;
    f32 plane;
    f32 scale;
    f32 diff;
    char *light;
    s32 alpha;
    if (((struct LevelActor *)(obj))->model == 0 || func_8024E158_de() == 0 || (((struct LevelActor *)(obj))->flags & 0x200000)) {
        return;
    }
    if (((struct LevelActor *)(obj))->flags & 0x10000000) {
        if (((struct LevelActor *)(obj))->shadow == 0) {
            ground = func_8024E650_de(obj, 0);
            if (((struct LevelActor *)(obj))->position0.y < ground) {
                return;
            }
            diff = ((struct LevelActor *)(obj))->position0.y - ground;
            height = (512.0f < diff) ? 512.0f : diff;
            if ((((struct LevelActor *)(obj))->shadow = func_802799C0_de(&D_8011FFB0, 1)) == 0) {
                return;
            }
            light = obj + (D_800D297C * 0x18 + 0x140);
            dir.x = ((struct Shared_ParticleLighting *)(light))->direction[0] * 0.007874016f;
            dir.y = ((struct Shared_ParticleLighting *)(light))->direction[1] * 0.007874016f;
            dir.z = ((struct Shared_ParticleLighting *)(light))->direction[2] * 0.007874016f;
            strength = func_802B72B0_de((f32)((struct Shared_ParticleLighting *)(light))->diffuse[0] * (f32)((struct Shared_ParticleLighting *)(light))->diffuse[0] +
                                         (f32)((struct Shared_ParticleLighting *)(light))->diffuse[1] * (f32)((struct Shared_ParticleLighting *)(light))->diffuse[1] +
                                         (f32)((struct Shared_ParticleLighting *)(light))->diffuse[1] * (f32)((struct Shared_ParticleLighting *)(light))->diffuse[1]) *
                       -0.00090497744f;
            func_80268A40_de(&D_8013B1A8, ((Player *)(obj))->pos, &dir, &strength);
            if (strength < -1.0f) {
                strength = -1.0f;
            }
            alpha = strength * 56.0f + 128.0f;
            if (D_800D15E0 == 1) {
                alpha = alpha * D_800D15F0 * 0.003921569f;
            }
            ((struct LevelActor *)(obj))->shadowAlpha = alpha;
            dir.y = 1.0f;
            func_8027207C_de(&dir);
            if (RW_ABS(dir.y) < 0.15f) {
                if (dir.y >= 0.0f) {
                    dir.y = 0.15f;
                } else {
                    dir.y = -0.15f;
                }
                func_8027207C_de(&dir);
            }
            plane = ground + height * 0.9f;
            func_8027310C_de(projection, &dir, plane);
            func_80273448_de(projection, -((struct LevelActor *)(obj))->position0.x, -plane, -((struct LevelActor *)(obj))->position0.z);
            scale = height * 0.003f + 1.0f;
            func_802735A8_de(projection, scale, scale, scale);
            func_80274244_de(obj + 0x5C, turn);
            func_8026F620_de(((struct LevelActor *)(obj))->shadow, projection, turn);
            func_80273448_de(((struct LevelActor *)(obj))->shadow, ((struct LevelActor *)(obj))->position0.x, ground, ((struct LevelActor *)(obj))->position0.z);
            if (((struct LevelActor *)(obj))->shadow == 0) {
                return;
            }
        }
        func_8024BA7C_de(obj, info, ((struct LevelActor *)(obj))->shadow, ((struct LevelActor *)(obj))->shadowAlpha);
    } else {
        func_8024ADD0_de(obj, ((struct ActorRenderSettings *)(info))->shadowType, 0);
    }
}
