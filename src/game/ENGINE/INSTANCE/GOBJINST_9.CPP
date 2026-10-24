#include "include_asm.h"
#include "RENDER_4/8026AC38.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"
#include "FX_2/80271B18.H"

/* Draws an object's cast shadow: objects without shadow flag 0x10000000 get the blob shadow of
 * Instance_DrawBlobShadow; otherwise, once per frame the shadow model from func_802799C0_de is built for an object above
 * the ground: the light of the current view (direction from its signed bytes, strength from its colour)
 * is sampled at the object through func_80268A40_de, the shadow alpha is 128 plus 56 per unit of light (faded
 * by D_800D15F0 during a fade), the light direction is kept at least 0.15 from horizontal, and the shadow
 * is projected along it onto a plane just below the object (0.9 of its height up to 512), grown by 0.003
 * per unit of height, turned by the object's orientation and placed on the ground; the shadow is then
 * submitted through func_8024BA7C_de. */
extern char D_8011FFB0;
extern char D_8013B1A8;
extern s32 D_800D297C;
extern s32 func_8024E158_de(void *);
extern f32 func_8024E650_de(char *, s32);
extern void *func_802799C0_de(void *, s32);
extern f32 func_802B72B0_de(f32);
extern void func_80268A40_de(void *, CVector3, CVector3 *, f32 *);
extern void func_8027310C_de(f32 *, CVector3 *, f32);
extern void func_80273448_de(void *, f32, f32, f32);
extern void func_802735A8_de(f32 *, f32, f32, f32);
#ifndef NON_MATCHING
extern void func_80274244_de(void *, f32 *);
#endif
extern void func_8026F620_de(void *, f32 *, f32 *);
extern void func_8024BA7C_de(char *, char *, void *, u8);
extern void Instance_DrawBlobShadow(struct LevelActor *, CVector3 *, s32);
void func_8024AA18_de(char *obj, s32 unused, char *info) {
    CVector3 dir;
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
    if (((struct LevelActor *)(obj))->model == 0 || func_8024E158_de(obj) == 0 || (((struct LevelActor *)(obj))->flags & 0x200000)) {
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
                alpha = alpha * D_800D15E4[3] * 0.003921569f;
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
        Instance_DrawBlobShadow((struct LevelActor *)obj, ((struct ActorRenderSettings *)(info))->shadowOffset, 0);
    }
}

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
float func_8024E678_de(void *object);
f32 func_8024E2FC_de(Actor_u1 *arg0);
s32 func_8027254C_de(f32 *arg0, f32 arg1);
void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);

void func_8027027C_de(f32 *src, PackedMatrixWords *dst);
void func_8026992C_de(void *matrix, s32 pass, u32 alpha);
/* 29/167 aligned edits; remaining: radius/float allocation and call setup. */
void Instance_DrawBlobShadow(struct LevelActor *actor, CVector3 *offset, s32 raised) {
    f32 matrix[16];
    CVector3 position;
    f32 scale;
    f32 groundHeight;
    f32 height;
    f32 baseRadius;
    f32 opacity;
    f32 shrink;
    f32 limitedRadius;
    f32 radius;
    f32 scaleFactor;
    f32 lift;
    PackedMatrixWords *packed;
    u8 targetAlpha;

    packed = func_802799C0_de(&D_8011FFB0, 1);
    if (packed != 0) {
        groundHeight = func_8024E678_de(actor);
        height = (actor->position0.y + actor->eyeHeight) - groundHeight;
        baseRadius = func_8024E2FC_de((Actor_u1 *)actor);
        shrink = height * D_800C3AB8_de;
        limitedRadius = baseRadius - shrink;
        if (!(limitedRadius <= baseRadius)) {
            limitedRadius = baseRadius;
        }
        radius = 0.0f;
        if (!(limitedRadius < 0.0f)) {
            radius = baseRadius - shrink;
            if (!(radius <= baseRadius)) {
                radius = baseRadius;
            }
        }
        if (raised != 0) {
            scaleFactor = D_800C3ABC_de;
            lift = D_800C3AC0_de;
        } else {
            scaleFactor = D_800C3AC4_de;
            lift = 0.0f;
        }
        scale = radius * scaleFactor;
        position.x = actor->position0.x + offset->x;
        position.z = actor->position0.z + offset->z;
        position.y = groundHeight + lift + offset->y;
        func_8027254C_de((f32 *)&position, 20000.0f);
        func_80274244_de(&actor->rotation, matrix);
        func_8027347C_de(matrix, scale, 1.0f, scale);
        func_80273448_de((s8 *) matrix, position.x, position.y, position.z);
        func_8027027C_de(matrix, (PackedMatrixWords *) packed);
        opacity = D_800C3ACC_de - (height * D_800C3AC8_de);
        targetAlpha = 0xFF;
        if (!(D_800C8BC0 < opacity)) {
            targetAlpha = 0;
            if (!(opacity < 0.0f)) {
                targetAlpha = 0xFF;
                if (!(D_800C8BC0 < opacity)) {
                    targetAlpha = (u8)opacity;
                }
            }
        }
        actor->shadowAlpha = (u8)(actor->shadowAlpha +
            ((s32)targetAlpha - actor->shadowAlpha) * D_800C3AD8_de);
        func_8026992C_de(packed, raised == 0, actor->shadowAlpha);
    }
}
#else
INCLUDE_ASM("span_1000", Instance_DrawBlobShadow);
#endif
