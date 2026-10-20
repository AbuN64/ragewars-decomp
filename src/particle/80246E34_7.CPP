#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"
#include "FX_2/80271B18.H"

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
extern void func_80268A40_de(void *, CVector3, CVector3 *, f32 *);
extern void func_8027310C_de(f32 *, CVector3 *, f32);
extern void func_80273448_de(void *, f32, f32, f32);
extern void func_802735A8_de(f32 *, f32, f32, f32);
extern void func_80274244_de(void *, f32 *);
extern void func_8026F620_de(void *, f32 *, f32 *);
extern void func_8024BA7C_de(char *, char *, void *, u8);
extern void func_8024ADD0_de(char *, s32, s32);
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

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
s32 func_802799C0_de(void *arg0, s32 arg1);
float func_8024E678_de(void *object);
f32 func_8024E2FC_de(Actor_u1 *arg0);
s32 func_8027254C_de(f32 *arg0, f32 arg1);
void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
void func_80273448_de(char *object, float x, float y, float z);
void func_8027027C_de(f32 *src, PackedMatrixWords *dst);
void func_8026992C_de(void *matrix, s32 pass, u32 alpha);
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x60, 0x64, 0x68, 0x6c, 0x70, 0x80, 0x84, 0x88, 0x8c], gap at: 0x74. */
void func_8024ADD0_de(void *arg0, void *arg1, s32 arg2) {
    f32 sp10[16];
    f32 sp50[3];
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fs1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0f;
    f32 temp_fv1;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv1;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;
    u8 temp_v1;

    temp_v0 = func_802799C0_de(&D_8011FFB0, 1);
    if (temp_v0 != 0) {
        temp_fs0f = func_8024E678_de(arg0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fs1 = (*((f32 *) ((u8 *) (arg0) + 12)) + *((f32 *) ((u8 *) (arg0) + 112))) - temp_fs0f;
        temp_fv0 = func_8024E2FC_de(arg0);
        temp_fv1 = temp_fs1 * D_800C3AB8_de;
        var_fv0 = temp_fv0 - temp_fv1;
        if (!(var_fv0 <= temp_fv0)) {
            var_fv0 = temp_fv0;
        }
        var_fv0_2 = 0.0f;
        if (!(var_fv0 < 0.0f)) {
            var_fv0_2 = temp_fv0 - temp_fv1;
            if (!(var_fv0_2 <= temp_fv0)) {
                var_fv0_2 = temp_fv0;
            }
        }
        if (arg2 != 0) {
            var_fv0_3 = D_800C3ABC_de;
            var_fv1 = D_800C3AC0_de;
        } else {
            var_fv0_3 = D_800C3AC4_de;
            var_fv1 = 0.0f;
        }
        temp_fs0 = var_fv0_2 * var_fv0_3;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp50[0] = *((f32 *) ((u8 *) (arg0) + 8)) + *((f32 *) ((u8 *) (arg1) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp50[2] = *((f32 *) ((u8 *) (arg0) + 16)) + *((f32 *) ((u8 *) (arg1) + 8));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp50[1] = temp_fs0f + var_fv1 + *((f32 *) ((u8 *) (arg1) + 4));
        func_8027254C_de(sp50, 20000.0f);
        func_80274244_de(arg0 + 0x5C, sp10);
        func_8027347C_de(sp10, temp_fs0, 1.0f, temp_fs0);
        func_80273448_de((s8 *) sp10, sp50[0], sp50[1], sp50[2]);
        func_8027027C_de(sp10, (PackedMatrixWords *) temp_v0);
        temp_fv0f = D_800C3ACC_de - (temp_fs1 * D_800C3AC8_de);
        var_v0 = 0xFF;
        if (!(D_800C8BC0 < temp_fv0f)) {
            var_v0 = 0;
            if (!(temp_fv0f < 0.0f)) {
                var_v0 = 0xFF;
                if (!(D_800C8BC0 < temp_fv0f)) {
                    if (D_800C3AD4_de <= temp_fv0f) {
                        var_v0 = (s32) (temp_fv0f - D_800C3AD4_de) | 0x80000000;
                    } else {
                        var_v0 = (s32) temp_fv0f;
                    }
                }
            }
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_v1 = *((u8 *) ((u8 *) (arg0) + 314));
        temp_fv0_2 = (f32) temp_v1 + ((f32) ((var_v0 & 0xFF) - temp_v1) * D_800C3AD8_de);
        if (D_800C3ADC_de <= temp_fv0_2) {
            var_v1 = (s32) (temp_fv0_2 - D_800C3ADC_de) | 0x80000000;
        } else {
            var_v1 = (s32) temp_fv0_2;
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((u8 *) ((u8 *) (arg0) + 314)) = (u8) var_v1;
        func_8026992C_de((void *) temp_v0, arg2 == 0, var_v1 & 0xFF);
    }
}
#else
INCLUDE_ASM("span_1000", func_8024ADD0_de);
#endif
