#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "FX_2/80271B18.H"
#include "WEAPONS/80213ED4.H"
#include "particle/80271B18_3.H"
#include "RENDER_4/8028FD2C_6.H"

void func_802897B4_de(World37 *world, CVector3 *point, Item37 **output, s32 *total) {
    Region37 *region;
    s32 i, found, regionCount, itemCount;
    f32 x, z;
    Items37 *items;
    Item37 *item, *base;
    region = 0;
    i = 0;
    found = 0;
    x = point->x; z = point->z;
    regionCount = world->count;
    for (; i < regionCount; i++) {
        Bounds2D37 *bounds = world->regions[i].bounds;
        if (bounds->maxX < x || x < bounds->minX ||
            bounds->maxZ < z || z < bounds->minZ) continue;
        region = &world->regions[i];
        break;
    }
    if (region == 0) {
        *total = 0;
    } else {
        items = func_8028FDB4_de(region->resource->data, 2);
        itemCount = items->count;
        base = items->items;
        for (i = 0; i < itemCount; i++) {
            Bounds37 *bounds;
            item = &base[i];
            bounds = &item->bounds;
            if (bounds->maxX > point->x && bounds->maxY > point->y && bounds->maxZ > point->z &&
                bounds->minX <= point->x && bounds->minY <= point->y && bounds->minZ <= point->z) {
                output[found++] = item;
                if (found == 10) break;
            }
        }
        *total = found;
    }
}

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "stddef.h"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern s32 func_80277128_de(ObjectRecAtBC *, f32, f32, f32, CVector3 *, f32 *);
extern void func_80272A10_de(void *, CVector3 *, CVector3 *);
extern f32 func_80278890_de(void *);

static inline f32 sampleDot(CVector3 *a, f32 *b, s32 index) { f32 *d=b+index+128; return a->x*d[0] + a->y*d[1] + a->z*d[2]; }
void func_80289970_de(ObjectRecAtBC **arg0, s32 arg1, CVector3 *arg2, Shared_ParticleLighting *arg3) {
    Shared_Game *settings;
    /* First128 floats are weights; the remaining384 hold XYZ directions. */
    f32 samples[512];
    f32 *weights;
    f32 *directions;
    f32 *sampleDirection;
    CVector3 transformed;
    CVector3 combinedDirection;
    CVector3 color;
    CVector3 ambient;
    CVector3 backLight;
    CVector3 diffuse;
    CVector3 contribution;
    CVector3 localDirection;
    CVector3 translatedDirection;
    CVector3 animationColor;
    CVector3 animatedContribution;
    ObjectRecAtBC *animatedVolume;
    CVector3 *transformedPosition;
    CVector3 *colorPtr;
    f32 *direction;
    ObjectRecAtBC **volumeCursor;
    f32 zero;
    f32 one;
    f32 temp_fs0;
    f32 brightness;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0f;
    f32 var_fs0f;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv0_4;
    f32 var_fv0_5;
    f32 var_fv0f_4;
    f32 var_fv0f_5;
    f32 var_fv0f_6;
    f32 var_fv0f_7;
    f32 var_fv0f_8;
    s32 sampleIndex;
    s32 directionOffset;
    ObjectRecAtBC *volume;

    settings = &D_801462C8;
    brightness = (f32)(u32)settings->buttons * 0.003921568859368563f;
    animatedVolume = NULL;
    if (settings->flags & 0x4000) {
        arg3->ambientCopy[0] = 0;
        arg3->ambient[0] = 0;
        arg3->ambientCopy[1] = 0;
        arg3->ambient[1] = 0;
        arg3->ambientCopy[2] = 0;
        arg3->ambient[2] = 0;
        arg3->diffuseCopy[0] = 0;
        arg3->diffuse[0] = 0;
        arg3->diffuseCopy[1] = 0;
        arg3->diffuse[1] = 0;
        arg3->diffuseCopy[2] = 0;
        arg3->diffuse[2] = 0;
        arg3->direction[0] = 0x7F;
        arg3->direction[1] = 0;
        arg3->direction[2] = 0;
        return;
    }
    sampleIndex = 0;
    combinedDirection.x = combinedDirection.y = combinedDirection.z = 0.0f;
    ambient.x = ambient.y = ambient.z = 0.0f;
    backLight.x = backLight.y = backLight.z = 0.0f;
    diffuse.x = diffuse.y = diffuse.z = 0.0f;
    if (arg1 > 0) {

        
        weights = samples;
        directions = samples + 128;
        transformedPosition = &transformed;
        do {
            sampleDirection = directions + sampleIndex * 3;
            volume = arg0[sampleIndex];
            func_80272898_de(volume->inverse, arg2, transformedPosition);
            if (func_80277128_de(volume, transformed.x, transformed.y, transformed.z, &localDirection, &weights[sampleIndex]) != 0) {
                func_80271F34_de(&translatedDirection, &localDirection, transformedPosition);
                func_80272A10_de(volume->transform, &translatedDirection, &localDirection);
                func_80271F68_de(sampleDirection, arg2, &localDirection);
                func_8027207C_de(sampleDirection);
                color = volume->direction;
                if (volume->animatedLight != 0) {
                    temp_fv0 = func_80278890_de(volume);
                    animationColor.x = temp_fv0;
                    animationColor.y = temp_fv0;
                    animationColor.z = temp_fv0;
                    func_80271F9C_de(&contribution, &animationColor, weights[sampleIndex] * volume->value);
                    animatedVolume = volume;
                    if (volume->flagB8 != 0) {
                        func_80271F9C_de(&contribution, &contribution, -1.0f);
                    }
                    func_80271F34_de(&ambient, &ambient, &contribution);
                }
                temp_fv0f = volume->value * 0.5f;
                temp_fs0 = 1.0f - temp_fv0f;
                func_80271F9C_de(&contribution, &color, weights[sampleIndex] * temp_fv0f);
                if (volume->flagB8 != 0) {
                    func_80271F9C_de(&contribution, &contribution, -1.0f);
                }
                func_80271F34_de(&ambient, &ambient, &contribution);
                weights[sampleIndex] *= temp_fs0;
                temp_fv0f = color.x; if (temp_fv0f < 0.0f) temp_fv0f = -temp_fv0f;
                if (color.y < 0.0f) temp_fv0f = temp_fv0f - color.y; else temp_fv0f = temp_fv0f + color.y;
                if (color.z < 0.0f) temp_fs0 = temp_fv0f - color.z; else temp_fs0 = temp_fv0f + color.z;
                func_80271F9C_de(&contribution, sampleDirection, *&weights[sampleIndex]);
                func_80271F9C_de(&contribution, &contribution, temp_fs0);
                func_80271F34_de(&combinedDirection, &combinedDirection, &contribution);
                if (volume->flagB8 != 0) {
                    weights[sampleIndex] = -weights[sampleIndex];
                }
            } else {
                sampleDirection[0] = 0.0f;
                sampleDirection[1] = 0.0f;
                sampleDirection[2] = 0.0f;
                weights[sampleIndex] = 0.0f;
            }

            
            sampleIndex += 1;

        } while (sampleIndex < arg1);
    }
    func_8027207C_de(&combinedDirection);
    sampleIndex = 0;
    if (arg1 > 0) {

        directionOffset = 0;
        volumeCursor = arg0;
        one = 1.0f;
        zero = 0.0f;
        colorPtr = &color;
        do {
            temp_fs0 = sampleDot(&combinedDirection, samples, directionOffset);
            volume = *volumeCursor;
            var_fs0f = one - temp_fs0; if (temp_fs0 < zero) var_fs0f = one;
            var_fs0f *= 0.5f;
            color = volume->direction;
            temp_fs0 = one - var_fs0f;
            if (volume == animatedVolume) {
                temp_fv0_2 = func_80278890_de(volume);
                animationColor.x = temp_fv0_2;
                animationColor.y = temp_fv0_2;
                animationColor.z = temp_fv0_2;
                func_80271F9C_de(&animatedContribution, &animationColor, temp_fs0 * samples[sampleIndex]);
                func_80271F34_de(&diffuse, &diffuse, &animatedContribution);
                func_80271F9C_de(&animatedContribution, &animationColor, var_fs0f * samples[sampleIndex]);
                func_80271F34_de(&backLight, &backLight, &animatedContribution);
            }
            func_80271F9C_de(&contribution, colorPtr, temp_fs0 * samples[sampleIndex]);
            func_80271F34_de(&diffuse, &diffuse, &contribution);


            func_80271F9C_de(&contribution, colorPtr, var_fs0f * samples[sampleIndex]);
            func_80271F34_de(&backLight, &backLight, &contribution);
            volumeCursor++;
            sampleIndex++;
            directionOffset += 3;
        } while (sampleIndex < arg1);
    }
    func_80271F9C_de(&backLight, &backLight, 0.5f);
    func_80271F34_de(&ambient, &ambient, &backLight);
    if (ambient.x < 0.0f) {
        diffuse.x += ambient.x;
    }
    if (ambient.y < 0.0f) {
        diffuse.y += ambient.y;
    }
    if (ambient.z < 0.0f) {
        diffuse.z += ambient.z;
    }
    var_fv0 = ambient.x;
    if (!(var_fv0 <= 255.0f)) var_fv0 = 255.0f;
    if (!(5.0f <= var_fv0)) var_fv0 = 5.0f;
    ambient.x = var_fv0 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_4 = ambient.y;
    if (!(var_fv0f_4 <= 255.0f)) var_fv0f_4 = 255.0f;
    var_fv0_2 = var_fv0f_4;
    if (!(5.0f <= var_fv0_2)) var_fv0_2 = 5.0f;
    ambient.y = var_fv0_2 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_5 = ambient.z;
    if (!(var_fv0f_5 <= 255.0f)) var_fv0f_5 = 255.0f;
    var_fv0_3 = var_fv0f_5;
    if (!(5.0f <= var_fv0_3)) var_fv0_3 = 5.0f;
    ambient.z = var_fv0_3 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_6 = diffuse.x;
    if (!(var_fv0f_6 <= 255.0f)) var_fv0f_6 = 255.0f;
    var_fv0_4 = var_fv0f_6;
    if (!(5.0f <= var_fv0_4)) var_fv0_4 = 5.0f;
    diffuse.x = var_fv0_4 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_7 = diffuse.y;
    if (!(var_fv0f_7 <= 255.0f)) var_fv0f_7 = 255.0f;
    var_fv0_5 = var_fv0f_7;
    if (!(5.0f <= var_fv0_5)) var_fv0_5 = 5.0f;
    diffuse.y = var_fv0_5 * (1.0f - brightness) + brightness * 255.0f;
    var_fv0f_8 = diffuse.z;
    if (!(var_fv0f_8 <= 255.0f)) var_fv0f_8 = 255.0f;
    if (!(5.0f <= var_fv0f_8)) var_fv0f_8 = 5.0f;
    diffuse.z = var_fv0f_8 * (1.0f - brightness) + brightness * 255.0f;
    arg3->ambient[0] = arg3->ambientCopy[0] = (u32)ambient.x;
    arg3->ambient[1] = arg3->ambientCopy[1] = (u32)ambient.y;
    arg3->ambient[2] = arg3->ambientCopy[2] = (u32)ambient.z;
    arg3->diffuse[0] = arg3->diffuseCopy[0] = (u32)diffuse.x;
    arg3->diffuse[1] = arg3->diffuseCopy[1] = (u32)diffuse.y;
    arg3->diffuse[2] = arg3->diffuseCopy[2] = (u32)diffuse.z;
    arg3->direction[0] = (s32)(combinedDirection.x * 127.0f);
    arg3->direction[1] = (s32)(combinedDirection.y * 127.0f);
    arg3->direction[2] = (s32)(combinedDirection.z * 127.0f);
}
#else
INCLUDE_ASM("span_1000", func_80289970_de);
#endif

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "TYPES.H"
s32 func_80204308_de(void *, void *, void *);
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x48, 0x4c, 0x58, 0x5c, 0x60, 0x64], gap at: 0x40. */
void func_8028A27C_de(void *arg0, void *arg1, CVector3 *arg2, CVector3 *arg3) {
    s32 sp10;
    s32 sp14;
    f32 temp_fs0f;
    f32 temp_fs0f_2;
    f32 temp_fs1;
    f32 temp_fs1f;
    f32 temp_fs2;
    f32 temp_ft0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0f;
    f32 temp_fv1;
    f32 temp_fv1f;
    f32 var_fs0;
    f32 var_ft0f;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    void *temp_a0;
    void *temp_s0;

    if ((arg2->x != arg3->x) || (arg2->y != arg3->y) || (arg2->z != arg3->z)) {
        temp_v0 = *((s32 **) arg1)[24 / sizeof(s32 *)];
        sp10 = temp_v0 == 0xB;
        sp14 = temp_v0 == 1;
        temp_fs1f = ((f32 *) arg1)[12 / sizeof(f32)] + func_8024E420_de(arg1);
        var_s5 = 0;
        temp_fs2 = temp_fs1f + Particle_GetActorHeight(arg1);
        if (((s32 *) arg0)[4060 / sizeof(s32)] > 0) {
            do {
                temp_s0 = *((void **) ((u8 *) ((arg0 + (var_s5 * 4))) + 3932));
                var_s4 = 0;
                if (temp_s0 != arg1) {
                    var_s1 = 0;
                    temp_fs0f = ((f32 *) temp_s0)[12 / sizeof(f32)] + func_8024E420_de(temp_s0);
                    temp_a0 = ((void **) temp_s0)[24 / sizeof(void *)];
                    temp_v1 = ((s32 *) temp_a0)[0 / sizeof(s32)];
                    temp_fv0 = temp_fs0f + Particle_GetActorHeight(temp_s0);
                    if (temp_v1 != 7) {
                        if (temp_v1 < 8) {
                            var_s2 = 0;
                            if (temp_v1 != 6) {
                                goto block_14;
                            }
                            var_s4 = 1;
                            var_s3 = 1;
                            temp_v0_2 = ((s32 *) temp_a0)[20 / sizeof(s32)];
                            var_ft0f = ((f32 *) temp_a0)[32 / sizeof(f32)];
                            var_fs0 = ((f32 *) temp_a0)[36 / sizeof(f32)];
                            var_a0 = temp_v0_2 & 4;
                            var_v1 = temp_v0_2 & 8;
                            var_a2 = temp_v0_2 & 0x10;
                            var_a1 = temp_v0_2 & 0x20;
                        } else {
                            var_s2 = 0;
                            if (temp_v1 != 0xA) {
block_14:
                                var_ft0f = 0.0f;
                                var_a0 = 0;
                                var_v1 = 0;
                                var_s3 = 0;
                                var_a2 = 0;
                                var_a1 = 0;
                                var_fs0 = 0.0f;
                            } else {
                                var_s2 = 1;
                                var_s3 = 0;
                                var_a2 = 0;
                                var_a1 = 0;
                                var_s1 = 1;
                                temp_v0_3 = ((s32 *) temp_a0)[20 / sizeof(s32)];
                                var_ft0f = ((f32 *) temp_a0)[36 / sizeof(f32)];
                                var_fs0 = 0.0f;
                                var_a0 = temp_v0_3 & 4;
                                var_v1 = temp_v0_3 & 8;
                            }
                        }
                    } else {
                        var_s2 = 1;
                        var_s3 = 0;
                        var_a2 = 0;
                        var_a1 = 0;
                        var_s1 = 1;
                        temp_v0_4 = ((s32 *) temp_a0)[20 / sizeof(s32)];
                        var_ft0f = ((f32 *) temp_a0)[40 / sizeof(f32)];
                        var_fs0 = 0.0f;
                        var_a0 = temp_v0_4 & 8;
                        var_v1 = temp_v0_4 & 0x10;
                    }
                    if ((var_s1 != 0) && ((var_v0 = 0, (temp_fs2 < temp_fs0f)) || (temp_fv0 < temp_fs1f))) {
                        var_s1_2 = 0;
                    } else {
                        var_v0 = 0;
                        if (sp10 != 0) {
                            if (var_a0 != 0) {
                                var_v0 = 1;
                            } else {
                                goto block_23;
                            }
                        } else {
block_23:
                            if ((sp14 != 0) && (var_v1 != 0)) {
                                var_v0 = 1;
                            }
                        }
                        var_s1_2 = 0;
                        if (((sp10 != 0) && (var_a2 != 0)) || ((sp14 != 0) && (var_a1 != 0))) {
                            var_s1_2 = 1;
                        }
                    }
                    if ((var_v0 != 0) || (var_s1_2 != 0)) {
                        temp_fv0_2 = ((f32 *) temp_s0)[8 / sizeof(f32)];
                        temp_fv1f = arg2->x - temp_fv0_2;
                        temp_ft0 = ((f32 *) temp_s0)[16 / sizeof(f32)];
                        temp_fv1 = arg2->z - temp_ft0;
                        temp_fv0f = arg3->x - temp_fv0_2;
                        temp_fv0_3 = arg3->z - temp_ft0;
                        temp_fs1 = (temp_fv1f * temp_fv1f) + (temp_fv1 * temp_fv1);
                        temp_fs0f_2 = (temp_fv0f * temp_fv0f) + (temp_fv0_3 * temp_fv0_3);
                        if (var_v0 != 0) {
                            if (var_s4 != 0) {
                                temp_fv0_4 = var_ft0f * var_ft0f;
                                var_v1_2 = 0;
                                if (temp_fv0_4 < temp_fs1) {
                                    if (temp_fs0f_2 <= temp_fv0_4) {
                                        var_v1_2 = 1;
                                    }
                                }
                            } else {
                                var_v1_2 = 1;
                                if (!(temp_fs0f_2 <= (var_ft0f * var_ft0f))) {
                                    var_v1_2 = 0;
                                }
                            }
                            if (var_v1_2 != 0) {
                                if ((*((s32 *) ((u8 *) (((void **) temp_s0)[24 / sizeof(void *)]) + 0)) == 0xA) && (var_s2 == 1)) {
                                    var_v1_2 = func_80204308_de(temp_s0, temp_s0 + 0x170, arg1);
                                }
                                if (var_v1_2 != 0) {
                                    func_80214178_de(temp_s0, temp_s0 + 0x170, var_s2);
                                }
                            }
                        }
                        if (var_s1_2 != 0) {
                            if (var_s4 != 0) {
                                temp_fv0_5 = var_fs0 * var_fs0;
                                var_v1_3 = 0;
                                if (temp_fs1 <= temp_fv0_5) {
                                    if (temp_fv0_5 < temp_fs0f_2) {
                                        var_v1_3 = 1;
                                    }
                                }
                            } else {
                                var_v1_3 = 1;
                                if (!((var_fs0 * var_fs0) < temp_fs0f_2)) {
                                    var_v1_3 = 0;
                                }
                            }
                            if (var_v1_3 != 0) {
                                func_80214178_de(temp_s0, temp_s0 + 0x170, var_s3);
                            }
                        }
                    }
                }
                var_s5 += 1;
            } while (var_s5 < ((s32 *) arg0)[4060 / sizeof(s32)]);
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_8028A27C_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/COLORENTRY.H"
typedef struct DraftSceneA698 {
    u8 pad[0x1B410]; s32 index, state; f32 timer; s32 loaded;
    u8 data[0x10]; s16 id; u8 pad432[2]; s32 current, pending;
    u8 pad43C[0x10]; s32 epoch;
} DraftSceneA698;
extern ColorEntry D_800CD6E4_de[];
extern f32 D_800D2988;
extern s32 D_801462CC;
#include "COMMON/MENU_MATCH_GLOBALS.H"
extern char D_80141008;
extern void *D_800D3A9C;
extern void func_804037D4_de(void), func_804030E0_de(s32);
extern s32 func_8044D220_de(void *, s32, s32, void *, s32), func_802934F8_de(void);
extern void func_80286AA8_de(void *, s32, s32), func_80239770_de(void *, void *, void *, f32);
void func_8028A698_de(DraftSceneA698 *scene)
{
    ColorEntry *entry = &D_800CD6E4_de[scene->index];
    s32 id;
    if (scene->state == 1) {
        if (scene->timer == entry->value) {
            if (scene->pending == 999) { func_804037D4_de(); func_804030E0_de(400); }
            if (scene->index == 0) scene->state = 0;
            else scene->state = 2;
            if (scene->pending < 0) { scene->pending = ~scene->pending; scene->loaded = 0; }
            else scene->loaded = func_8044D220_de(scene, -1, scene->pending, scene->data, 1);
            scene->current = scene->pending;
            if (!scene->loaded) id = scene->pending;
            else id = scene->id;
            func_80286AA8_de(scene, id, scene->loaded);
            if (scene->epoch != D_801462CC && func_802934F8_de()) {
                func_80239770_de(&D_80145088, &D_80141008, D_800D3A9C, 4.0f);
                scene->epoch = D_801462CC;
            }
        } else {
            scene->timer += D_800D2988;
            if (entry->value < scene->timer) scene->timer = entry->value;
        }
    } else if (scene->state == 2) {
        if (scene->timer == 0.0f) scene->state = 0;
        else {
            scene->timer -= D_800D2988;
            if (scene->timer < 0.0f) scene->timer = 0.0f;
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_8028A698_de);
#endif

#include "COMMON/WORLD.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/RESULTS_TEXT.H"
typedef struct ResultsText {
    char *text;
    s32 length;
} ResultsText;
typedef struct ResultsCourse {
    u8 unknown0[0x21];
    u8 laps;          /* 0x21 */
    u8 targetCount;   /* 0x22 */
    u8 rounds;        /* 0x23 */
    u8 timeLimit;     /* 0x24: seconds */
    u8 unknown25[3];
    u8 lives;         /* 0x28 */
} ResultsCourse;
typedef struct LevelChallenge {
    u8 unknown0[4];
    u8 character;     /* 0x4: the opponent's character key */
    u8 unknown5;
    u16 weapons[8];   /* 0x6: starting weapon item ids (read by the achieve loadout) */
} LevelChallenge;
extern s32 D_8015402C;
extern ResultsCourse *D_800E4680;
extern Profile D_80102B00[];
extern ResultsHeadingCharacter D_800DFA6C[];
extern char D_800C5284_de[], D_800C52E4_de[], D_00285160[];
extern char *D_800D3304, *D_800D3334, *D_800D3338, *D_800D333C, *D_800D3340, *D_800D334C_de, *D_800D3350,
    *D_800D3354, *D_800D3358, *D_800D335C, *D_800D3360, *D_800D3364, *D_800D3368_de, *D_800D336C,
    *D_800D3370, *D_800D3374, *D_800D3378, *D_800D337C, *D_800D3380, *D_800D3384, *D_800D3388,
    *D_800D338C, *D_800D3390_de, *D_800D3394, *D_800D3398;
extern void func_80245AC8_de(void);
extern void func_80245A78_de(char *);
extern s32 func_8028FE28_de(s32 *, s32, s32);
extern void *func_80254284_de(s32, void **, s32, void *);
extern ResultsText *func_80254408_de(s32, void *, s32, s32, void *, s32, void *);
extern void func_802BD3A0_de(void *, const void *, s32);
extern void func_80253838_de(s32, void *);
extern s32 func_802A0C08_de(char *, const char *, ...);
extern u8 func_8022F454_de(Profile *, s32);
extern void func_8028DA74_de(Shared_World *);
extern void *func_8025193C_de(s32, u32, u32, u32, u32, s32, void *, const char *, u32);
extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);
extern s32 func_8041F140_de(s32);
static inline void copyLevelName(Shared_World *world, s32 level, char *out, s32 limit) {
    void *handle;
    s32 entry;
    void *bank;
    ResultsText *name;
    s32 length;

    entry = func_8028FE28_de(world->resourceDirectory, world->resourceBank, level);
    bank = func_80254284_de(0, &handle, entry, &D_800C5110_de);
    name = func_80254408_de(0, handle, 8, entry, world, 0, D_800C5284_de);
    length = name->length;
    if (limit < length) {
        length = limit;
    }
    func_802BD3A0_de(out, name->text, length);
    func_80253838_de(0, name);
    if (world->level != level) {
        func_80253838_de(0, bank);
    }
}
static inline LevelChallenge *findLevelChallenge(Shared_World *world, s32 level) {
    s32 size;
    void **index;
    s32 file;
    s32 mode;
    s32 direct;

    if (world->resourceHandle == 0 || world->resourceKey != level) {
        func_8028DA74_de(world);
        if (world->challengeFile != 0) {
            mode = 0x10;
            direct = 1;
            index = func_8025193C_de(0, world->challengeFile, world->challengeFile, world->challengeFileSize, mode,
                                     0, 0, &D_800C5290_de, direct);
            if (index != 0) {
                file = func_8028FE3C_de((s32)*index, world->challengeFile, level, &size);
                func_80253838_de(0, index);
                if ((world->resourceHandle =
                         func_8025193C_de(0, file, file, size, mode, 0, D_00285160, &D_800C52BC, direct)) == 0) {
                    goto missing;
                }
                world->resourceKey = level;
            }
        }
    }
    if (world->resourceHandle != 0) {
        return *world->resourceHandle;
    }
missing:
    return 0;
}

/* Print the level name, then the goal line and the mode's detail line of the results screen. */
void Scene_ShowResultsGoal(void) {
    char name[40];
    char goal[40];
    s32 *levelGoal;
    u8 mode;
    u8 minutes;
    s32 seconds;
    s32 players;
    LevelChallenge *challenge;
    ResultsHeadingCharacter *character;

    func_80245AC8_de();
    copyLevelName(&D_8011FE88, D_8015402C, name, 63);
    func_80245A78_de(name);
    if (currentGame()->controllerMode == 0) {
        return;
    }
    levelGoal = &D_8014DD98; /* kind (0 rounds, 1 laps, 2 single laps, 3 targets), then the target goal */
    switch (levelGoal[0]) {
    case 0:
        if (currentGame()->controllerMode == 2) {
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3354, D_800E17A4), D_800E4680->rounds);
        } else if (D_800E4680->rounds < 2) {
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D334C_de, D_800E1784), D_800E4680->rounds);
        } else {
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3350, D_800E1794_eu), D_800E4680->rounds);
        }
        break;
    case 1:
        if (currentGame()->controllerMode == 2) {
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3360, D_800E17D4), D_800E4680->laps);
        } else if (D_800E4680->laps < 2) {
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3358, D_800E17B4), D_800E4680->laps);
        } else {
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D335C, D_800E17C4), D_800E4680->laps);
        }
        break;
    case 2:
        if (D_800E4680->laps < 2) {
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3364, D_800E17E4_eu), D_800E4680->laps);
        } else {
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3368_de, D_800E17F4), D_800E4680->laps);
        }
        break;
    case 3:
        switch (levelGoal[1]) {
        case 4:
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3390_de, D_800E1894), RESULTS_TEXT(D_800D3334, D_800E1724));
            break;
        case 9:
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3394, D_800E18A4), RESULTS_TEXT(D_800D3338, D_800E1734_eu),
                             RESULTS_TEXT(D_800D3304, D_800E1664_eu));
            break;
        case 22:
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3390_de, D_800E1894), RESULTS_TEXT(D_800D333C, D_800E1744));
            break;
        case 35:
            func_802A0C08_de(goal, RESULTS_TEXT(D_800D3390_de, D_800E1894), RESULTS_TEXT(D_800D3340, D_800E1754));
            break;
        default:
            if (D_800E4680->targetCount < 2) {
                func_802A0C08_de(goal, RW_LOCALIZED_TEXT(D_800D336C, D_800E1804, D_800E1804, D_80152789),
                                 D_800E4680->targetCount);
            } else {
                func_802A0C08_de(goal, RW_LOCALIZED_TEXT(D_800D3370, D_800E1814, D_800E1814, D_80152789),
                                 D_800E4680->targetCount);
            }
            break;
        }
        break;
    }
    mode = currentGame()->controllerMode;
    switch (mode) {
    case 1:
        func_80245A78_de(goal);
        players = (func_8022F454_de(D_80102B00, D_80102B00[0].slot) >> 1) + 1;
        if (players < 2) {
            func_802A0C08_de(name, RESULTS_TEXT(D_800D3388, D_800E1874), players);
        } else {
            func_802A0C08_de(name, RESULTS_TEXT(D_800D338C, D_800E1884), players);
        }
        func_80245A78_de(name);
        break;
    case 3:
        func_80245A78_de(goal);
        if (D_800E4680->timeLimit <= 60) {
            func_802A0C08_de(name, RESULTS_TEXT(D_800D3374, D_800E1824), D_800E4680->timeLimit);
        } else {
            minutes = D_800E4680->timeLimit / 60;
            if (minutes < 2) {
                seconds = D_800E4680->timeLimit % 60;
                if (seconds == 0) {
                    func_802A0C08_de(name, RESULTS_TEXT(D_800D3380, D_800E1854_eu), minutes);
                } else {
                    func_802A0C08_de(name, RESULTS_TEXT(D_800D3378, D_800E1834), minutes, seconds);
                }
            } else {
                seconds = D_800E4680->timeLimit % 60;
                if (seconds == 0) {
                    func_802A0C08_de(name, RESULTS_TEXT(D_800D3384, D_800E1864), minutes);
                } else {
                    func_802A0C08_de(name, RESULTS_TEXT(D_800D337C, D_800E1844), minutes, seconds);
                }
            }
        }
        func_80245A78_de(name);
        break;
    case 4:
        challenge = findLevelChallenge(&D_8011FE88, D_8015402C);
        character = &RESULTS_CHARACTERS[func_8041F140_de(challenge->character)];
        func_802A0C08_de(name, RESULTS_NAME_FORMAT, character->name[RESULTS_LANGUAGE].text);
        func_80245A78_de(name);
        func_80245A78_de(goal);
        if (D_800E4680->lives < 2) {
            func_802A0C08_de(name, RESULTS_TEXT(D_800D3388, D_800E1874), D_800E4680->lives);
        } else {
            func_802A0C08_de(name, RESULTS_TEXT(D_800D338C, D_800E1884), D_800E4680->lives);
        }
        func_80245A78_de(name);
        break;
    case 2:
        func_80245A78_de(goal);
        switch (D_8014DD98) {
        case 0:
            break;
        case 1:
            func_80245A78_de(RESULTS_TEXT(D_800D3398, D_800E18B4_eu));
            break;
        case 2:
            func_80245A78_de(RESULTS_TEXT(D_800D3398, D_800E18B4_eu));
            break;
        }
        break;
    }
}
