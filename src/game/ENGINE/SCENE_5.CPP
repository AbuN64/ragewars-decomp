#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/SCENERECAT10C0.H"
#include "SCENE/CODE.H"
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

#include "stddef.h"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern s32 func_80277128_de(ObjectRecAtBC *, f32, f32, f32, CVector3 *, f32 *);
extern void func_80272A10_de(void *, CVector3 *, CVector3 *);
extern f32 func_80278890_de(void *);
static inline f32 sampleDot(CVector3 *a, f32 *b, s32 index) { f32 *d=b+index+128; return a->x*d[0] + a->y*d[1] + a->z*d[2]; }
void func_80289970_de(ObjectRecAtBC **volumes, s32 count, CVector3 *position, Shared_ParticleLighting *lighting) {
    Shared_Game *settings;
    /* The first 128 floats are weights; the remaining 384 hold XYZ directions. */
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
    f32 zero;
    f32 one;
    f32 scale;
    f32 brightness;
    f32 level;
    f32 pulse;
    f32 amount;
    f32 backScale;
    f32 ambientRed;
    f32 ambientGreenLevel;
    f32 ambientBlueLevel;
    f32 diffuseRedLevel;
    f32 diffuseGreenLevel;
    f32 ambientGreen;
    f32 ambientBlue;
    f32 diffuseRed;
    f32 diffuseGreen;
    f32 diffuseBlue;
    s32 sampleIndex;
    ObjectRecAtBC *volume;

    settings = &D_801462C8;
    brightness = (f32)(u32)settings->buttons * 0.003921568859368563f;
    animatedVolume = NULL;
    if (settings->flags & 0x4000) {
        lighting->ambientCopy[0] = 0;
        lighting->ambient[0] = 0;
        lighting->ambientCopy[1] = 0;
        lighting->ambient[1] = 0;
        lighting->ambientCopy[2] = 0;
        lighting->ambient[2] = 0;
        lighting->diffuseCopy[0] = 0;
        lighting->diffuse[0] = 0;
        lighting->diffuseCopy[1] = 0;
        lighting->diffuse[1] = 0;
        lighting->diffuseCopy[2] = 0;
        lighting->diffuse[2] = 0;
        lighting->direction[0] = 0x7F;
        lighting->direction[1] = 0;
        lighting->direction[2] = 0;
        return;
    }
    sampleIndex = 0;
    combinedDirection.x = combinedDirection.y = combinedDirection.z = 0.0f;
    ambient.x = ambient.y = ambient.z = 0.0f;
    backLight.x = backLight.y = backLight.z = 0.0f;
    diffuse.x = diffuse.y = diffuse.z = 0.0f;
    if (sampleIndex < count) {

        
        weights = samples;
        directions = samples + 128;
        do {
            sampleDirection = directions + sampleIndex * 3;
            volume = volumes[sampleIndex];
            func_80272898_de(volume->inverse, position, &transformed);
            if (func_80277128_de(volume, transformed.x, transformed.y, transformed.z, &localDirection, &weights[sampleIndex]) != 0) {
                func_80271F34_de(&translatedDirection, &localDirection, &transformed);
                func_80272A10_de(volume->transform, &translatedDirection, &localDirection);
                func_80271F68_de(sampleDirection, position, &localDirection);
                func_8027207C_de(sampleDirection);
                color = volume->direction;
                if (volume->animatedLight != 0) {
                    level = func_80278890_de(volume);
                    animationColor.x = level;
                    animationColor.y = level;
                    animationColor.z = level;
                    func_80271F9C_de(&contribution, &animationColor, weights[sampleIndex] * volume->value);
                    animatedVolume = volume;
                    if (volume->flagB8 != 0) {
                        func_80271F9C_de(&contribution, &contribution, -1.0f);
                    }
                    func_80271F34_de(&ambient, &ambient, &contribution);
                }
                amount = volume->value * 0.5f;
                scale = 1.0f - amount;
                func_80271F9C_de(&contribution, &color, weights[sampleIndex] * amount);
                if (volume->flagB8 != 0) {
                    func_80271F9C_de(&contribution, &contribution, -1.0f);
                }
                func_80271F34_de(&ambient, &ambient, &contribution);
                weights[sampleIndex] *= scale;
                amount = color.x; if (amount < 0.0f) amount = -amount;
                if (color.y < 0.0f) amount = amount - color.y; else amount = amount + color.y;
                if (color.z < 0.0f) scale = amount - color.z; else scale = amount + color.z;
                func_80271F9C_de(&contribution, sampleDirection, weights[sampleIndex]);
                func_80271F9C_de(&contribution, &contribution, scale);
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

        } while (sampleIndex < count);
    }
    func_8027207C_de(&combinedDirection);
    sampleIndex = 0;
    if (sampleIndex < count) {
        one = 1.0f;
        zero = 0.0f;
        do {
            volume = volumes[sampleIndex];
            scale = sampleDot(&combinedDirection, samples, sampleIndex * 3);
            backScale = one - scale; if (scale < zero) backScale = one;
            backScale *= 0.5f;
            color = volume->direction;
            scale = one - backScale;
            if (volume == animatedVolume) {
                pulse = func_80278890_de(volume);
                animationColor.x = pulse;
                animationColor.y = pulse;
                animationColor.z = pulse;
                func_80271F9C_de(&animatedContribution, &animationColor, scale * samples[sampleIndex]);
                func_80271F34_de(&diffuse, &diffuse, &animatedContribution);
                func_80271F9C_de(&animatedContribution, &animationColor, backScale * samples[sampleIndex]);
                func_80271F34_de(&backLight, &backLight, &animatedContribution);
            }
            func_80271F9C_de(&contribution, &color, scale * samples[sampleIndex]);
            func_80271F34_de(&diffuse, &diffuse, &contribution);


            func_80271F9C_de(&contribution, &color, backScale * samples[sampleIndex]);
            func_80271F34_de(&backLight, &backLight, &contribution);
            sampleIndex++;
        } while (sampleIndex < count);
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
    ambientRed = ambient.x;
    if (!(ambientRed <= 255.0f)) ambientRed = 255.0f;
    if (!(5.0f <= ambientRed)) ambientRed = 5.0f;
    ambient.x = ambientRed * (1.0f - brightness) + brightness * 255.0f;
    ambientGreen = ambient.y;
    if (!(ambientGreen <= 255.0f)) ambientGreen = 255.0f;
    ambientGreenLevel = ambientGreen;
    if (!(5.0f <= ambientGreenLevel)) ambientGreenLevel = 5.0f;
    ambient.y = ambientGreenLevel * (1.0f - brightness) + brightness * 255.0f;
    ambientBlue = ambient.z;
    if (!(ambientBlue <= 255.0f)) ambientBlue = 255.0f;
    ambientBlueLevel = ambientBlue;
    if (!(5.0f <= ambientBlueLevel)) ambientBlueLevel = 5.0f;
    ambient.z = ambientBlueLevel * (1.0f - brightness) + brightness * 255.0f;
    diffuseRed = diffuse.x;
    if (!(diffuseRed <= 255.0f)) diffuseRed = 255.0f;
    diffuseRedLevel = diffuseRed;
    if (!(5.0f <= diffuseRedLevel)) diffuseRedLevel = 5.0f;
    diffuse.x = diffuseRedLevel * (1.0f - brightness) + brightness * 255.0f;
    diffuseGreen = diffuse.y;
    if (!(diffuseGreen <= 255.0f)) diffuseGreen = 255.0f;
    diffuseGreenLevel = diffuseGreen;
    if (!(5.0f <= diffuseGreenLevel)) diffuseGreenLevel = 5.0f;
    diffuse.y = diffuseGreenLevel * (1.0f - brightness) + brightness * 255.0f;
    diffuseBlue = diffuse.z;
    if (!(diffuseBlue <= 255.0f)) diffuseBlue = 255.0f;
    if (!(5.0f <= diffuseBlue)) diffuseBlue = 5.0f;
    diffuse.z = diffuseBlue * (1.0f - brightness) + brightness * 255.0f;
    lighting->ambient[0] = lighting->ambientCopy[0] = (u32)ambient.x;
    lighting->ambient[1] = lighting->ambientCopy[1] = (u32)ambient.y;
    lighting->ambient[2] = lighting->ambientCopy[2] = (u32)ambient.z;
    lighting->diffuse[0] = lighting->diffuseCopy[0] = (u32)diffuse.x;
    lighting->diffuse[1] = lighting->diffuseCopy[1] = (u32)diffuse.y;
    lighting->diffuse[2] = lighting->diffuseCopy[2] = (u32)diffuse.z;
    lighting->direction[0] = (s32)(combinedDirection.x * 127.0f);
    lighting->direction[1] = (s32)(combinedDirection.y * 127.0f);
    lighting->direction[2] = (s32)(combinedDirection.z * 127.0f);
}

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "TYPES.H"
s32 func_80204308_de(void *, void *, void *);
#include "COMMON/WORLD.H"
#include "COMMON/LEVEL_ACTOR.H"
typedef struct SceneTriggerDefinition {
    ActorDefinitionHeader header;
    char pad18[8];
    f32 enterRadius;
    f32 exitRadius;
    f32 touchRadius;
} SceneTriggerDefinition;
/* 12/263 aligned edits; remaining: scalar load scheduling and loop join. */
void Scene_UpdateMovementTriggers(void *arg0, void *actor, CVector3 *before, CVector3 *arg3) {
    s32 sp10;
    s32 sp14;
    f32 temp_fs0f;
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
    s32 flags;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 kind;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 i;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    SceneTriggerDefinition *definition;
    LevelActor *temp_s0;

    if ((before->x != arg3->x) || (before->y != arg3->y) || (before->z != arg3->z)) {
        temp_v0 = ((LevelActor *)actor)->definition->kind;
        sp10 = temp_v0 == 0xB;
        sp14 = temp_v0 == 1;
        temp_fs1f = ((LevelActor *)actor)->position0.y + func_8024E420_de(actor);
        i = 0;
        temp_fs2 = temp_fs1f + Particle_GetActorHeight(actor);
        if (((Shared_World *)arg0)->flaggedCount > 0) {
            do {
                temp_s0 = ((Shared_World *)arg0)->flagged[i];
                var_s4 = 0;
                if (temp_s0 != actor) {
                    var_s1 = 0;
                    temp_fs0f = temp_s0->position0.y + func_8024E420_de(temp_s0);
                    temp_fv0 = temp_fs0f + Particle_GetActorHeight(temp_s0);
                    definition = (SceneTriggerDefinition *)temp_s0->definition;
                    kind = definition->header.kind;
                    switch (kind) {
                    case 6:
                        var_s2 = 0;
                        var_s4 = 1;
                        var_s3 = 1;
                        flags = definition->header.flags;
                        var_ft0f = definition->enterRadius;
                        var_fs0 = definition->exitRadius;
                        var_a0 = flags & 4;
                        var_v1 = flags & 8;
                        var_a2 = flags & 0x10;
                        var_a1 = flags & 0x20;
                        break;
                    case 10:
                        var_s2 = 1;
                        var_s3 = 0;
                        var_a2 = 0;
                        var_a1 = 0;
                        var_s1 = 1;
                        temp_v0_3 = definition->header.flags;
                        var_ft0f = definition->exitRadius;
                        var_fs0 = 0.0f;
                        var_a0 = temp_v0_3 & 4;
                        var_v1 = temp_v0_3 & 8;
                        break;
                    case 7:
                        var_s2 = 1;
                        var_s3 = 0;
                        var_a2 = 0;
                        var_a1 = 0;
                        var_s1 = 1;
                        temp_v0_4 = definition->header.flags;
                        var_ft0f = definition->touchRadius;
                        var_fs0 = 0.0f;
                        var_a0 = temp_v0_4 & 8;
                        var_v1 = temp_v0_4 & 0x10;
                        break;
                    default:
                        var_s2 = 0;
                        var_ft0f = 0.0f;
                        var_a0 = 0;
                        var_v1 = 0;
                        var_s3 = 0;
                        var_a2 = 0;
                        var_a1 = 0;
                        var_fs0 = 0.0f;
                        break;
                    }
                    if ((var_s1 != 0) && ((var_v0 = 0, (temp_fs2 < temp_fs0f)) || (temp_fv0 < temp_fs1f))) {
                        var_s1_2 = var_v0;
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
                        temp_fv1f = before->x - temp_s0->position0.x;
                        temp_fv1 = before->z - temp_s0->position0.z;
                        temp_fv0f = arg3->x - temp_s0->position0.x;
                        temp_fv0_3 = arg3->z - temp_s0->position0.z;
                        temp_fv0 = (temp_fv1f * temp_fv1f) + (temp_fv1 * temp_fv1);
                        temp_fs0f = (temp_fv0f * temp_fv0f) + (temp_fv0_3 * temp_fv0_3);
                        if (var_v0 != 0) {
                            if (var_s4 != 0) {
                                temp_fv0_4 = var_ft0f * var_ft0f;
                                var_v1_2 = 0;
                                if (temp_fv0_4 < temp_fv0) {
                                    if (temp_fs0f <= temp_fv0_4) {
                                        var_v1_2 = 1;
                                    }
                                }
                            } else {
                                var_v1_2 = 1;
                                if (!(temp_fs0f <= (var_ft0f * var_ft0f))) {
                                    var_v1_2 = 0;
                                }
                            }
                            if (var_v1_2 != 0) {
                                if ((temp_s0->definition->kind == 0xA) && (var_s2 == 1)) {
                                    var_v1_2 = func_80204308_de(temp_s0, &temp_s0->behaviorFlags, actor);
                                }
                                if (var_v1_2 != 0) {
                                    func_80214178_de(temp_s0, &temp_s0->behaviorFlags, var_s2);
                                }
                            }
                        }
                        if (var_s1_2 != 0) {
                            if (var_s4 != 0) {
                                temp_fv0_5 = var_fs0 * var_fs0;
                                var_v1_2 = 0;
                                if (temp_fv0 <= temp_fv0_5) {
                                    if (temp_fv0_5 < temp_fs0f) {
                                        var_v1_2 = 1;
                                    }
                                }
                            } else {
                                var_v1_2 = 1;
                                if (!((var_fs0 * var_fs0) < temp_fs0f)) {
                                    var_v1_2 = 0;
                                }
                            }
                            if (var_v1_2 != 0) {
                                func_80214178_de(temp_s0, &temp_s0->behaviorFlags, var_s3);
                            }
                        }
                    }
                }
                i += 1;
            } while (i < ((Shared_World *)arg0)->flaggedCount);
        }
    }
}
#else
INCLUDE_ASM("span_1000", Scene_UpdateMovementTriggers);
#endif

#include "TYPES.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLD.H"
extern ColorEntry D_800CD6E4_de[];
extern f32 D_800D2988;

#include "COMMON/MENU_MATCH_GLOBALS.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 *D_800D3A9C[];
#else
extern u8 *D_800D3A9C;
#endif
extern void func_804037D4_de(void), func_804030E0_de(s32);
extern s32 func_802934F8_de(void);
extern void func_80286AA8_de(void *, s32, s32);
extern struct Message *Camera_PostScaledScreenMessage(void *, void *, u8 *, f32);
static inline s32 transitionId(Shared_World *scene) {
    if (scene->selectionFlags != 0) return scene->selectionSpawn.kind;
    return scene->selectionValues[1];
}
void Scene_UpdateSelectionTransition(Shared_World *scene)
{
    ColorEntry *entry = &D_800CD6E4_de[scene->selectionState];
    s32 id;
    MenuSettings *settings;
    switch (scene->frozen) {
    case 0:
        break;
    case 1:
        if (scene->selectionTimer == entry->value) {
            if (scene->selectionValues[1] == 999) { func_804037D4_de(); func_804030E0_de(400); }
            if (scene->selectionState == 0) scene->frozen = 0;
            else scene->frozen = 2;
            if (scene->selectionValues[1] < 0) { scene->selectionValues[1] = ~scene->selectionValues[1]; scene->selectionFlags = 0; }
            else scene->selectionFlags = func_8044D220_de(scene, -1, scene->selectionValues[1], &scene->selectionSpawn, 1);
            scene->selectionValues[0] = scene->selectionValues[1];
            id = transitionId(scene);
            func_80286AA8_de(scene, id, scene->selectionFlags);
            settings = &D_80145088.settings;
            if (scene->previewStart != settings->optionFlags && func_802934F8_de()) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                Camera_PostScaledScreenMessage(&D_80145088, &D_80145088.fallbackCamera, D_800D3A9C[settings->language], 4.0f);
#else
                Camera_PostScaledScreenMessage(&D_80145088, &D_80145088.fallbackCamera, D_800D3A9C, 4.0f);
#endif
                scene->previewStart = settings->optionFlags;
            }
        } else {
            scene->selectionTimer += D_800D2988;
            if (entry->value < scene->selectionTimer) scene->selectionTimer = entry->value;
        }
        break;
    case 2:
        if (scene->selectionTimer == 0.0f) scene->frozen = 0;
        else {
            scene->selectionTimer -= D_800D2988;
            if (scene->selectionTimer < 0.0f) scene->selectionTimer = 0.0f;
        }
        break;
    }
}


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
    bank = func_80254284_de(0, &handle, entry, D_800C5110_de);
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
                                     0, 0, D_800C5290_de, direct);
            if (index != 0) {
                file = func_8028FE3C_de((s32)*index, world->challengeFile, level, &size);
                func_80253838_de(0, index);
                if ((world->resourceHandle =
                         func_8025193C_de(0, file, file, size, mode, 0, D_00285160, D_800C52BC, direct)) == 0) {
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
