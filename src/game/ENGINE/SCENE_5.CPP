#include "include_asm.h"
#include "COMMON/LEVEL_GOAL.H"
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
#include "COMMON/PLAYERPROFILES.H"

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
        items = Render_GetPackSection(region->resource->data, 2);
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
extern void Particle_ProjectPoint(void *, CVector3 *, CVector3 *);
extern f32 func_80278890_de(void *);
static inline f32 sampleDot(CVector3 *a, f32 *b, s32 index) { f32 *d=b+index+128; return a->x*d[0] + a->y*d[1] + a->z*d[2]; }
void Engine_SampleVolumeLighting(ObjectRecAtBC **volumes, s32 count, CVector3 *position, Shared_ParticleLighting *lighting) {
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
            Particle_TransformPoint(volume->inverse, position, &transformed);
            if (func_80277128_de(volume, transformed.x, transformed.y, transformed.z, &localDirection, &weights[sampleIndex]) != 0) {
                Particle_AddVec3(&translatedDirection, &localDirection, &transformed);
                Particle_ProjectPoint(volume->transform, &translatedDirection, &localDirection);
                Particle_SubtractVectors(sampleDirection, position, &localDirection);
                Particle_NormalizeVec3(sampleDirection);
                color = volume->direction;
                if (volume->animatedLight != 0) {
                    level = func_80278890_de(volume);
                    animationColor.x = level;
                    animationColor.y = level;
                    animationColor.z = level;
                    Particle_ScaleVector(&contribution, &animationColor, weights[sampleIndex] * volume->value);
                    animatedVolume = volume;
                    if (volume->flagB8 != 0) {
                        Particle_ScaleVector(&contribution, &contribution, -1.0f);
                    }
                    Particle_AddVec3(&ambient, &ambient, &contribution);
                }
                amount = volume->value * 0.5f;
                scale = 1.0f - amount;
                Particle_ScaleVector(&contribution, &color, weights[sampleIndex] * amount);
                if (volume->flagB8 != 0) {
                    Particle_ScaleVector(&contribution, &contribution, -1.0f);
                }
                Particle_AddVec3(&ambient, &ambient, &contribution);
                weights[sampleIndex] *= scale;
                amount = color.x; if (amount < 0.0f) amount = -amount;
                if (color.y < 0.0f) amount = amount - color.y; else amount = amount + color.y;
                if (color.z < 0.0f) scale = amount - color.z; else scale = amount + color.z;
                Particle_ScaleVector(&contribution, sampleDirection, weights[sampleIndex]);
                Particle_ScaleVector(&contribution, &contribution, scale);
                Particle_AddVec3(&combinedDirection, &combinedDirection, &contribution);
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
    Particle_NormalizeVec3(&combinedDirection);
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
                Particle_ScaleVector(&animatedContribution, &animationColor, scale * samples[sampleIndex]);
                Particle_AddVec3(&diffuse, &diffuse, &animatedContribution);
                Particle_ScaleVector(&animatedContribution, &animationColor, backScale * samples[sampleIndex]);
                Particle_AddVec3(&backLight, &backLight, &animatedContribution);
            }
            Particle_ScaleVector(&contribution, &color, scale * samples[sampleIndex]);
            Particle_AddVec3(&diffuse, &diffuse, &contribution);


            Particle_ScaleVector(&contribution, &color, backScale * samples[sampleIndex]);
            Particle_AddVec3(&backLight, &backLight, &contribution);
            sampleIndex++;
        } while (sampleIndex < count);
    }
    Particle_ScaleVector(&backLight, &backLight, 0.5f);
    Particle_AddVec3(&ambient, &ambient, &backLight);
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

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/WORLD.H"
#include "COMMON/LEVEL_ACTOR.H"
s32 Level_ShowTriggerMessage(void *, void *, void *);
typedef struct SceneTriggerDefinition {
    ActorDefinitionHeader header;
    char pad18[8];
    f32 enterRadius;
    f32 exitRadius;
    f32 touchRadius;
} SceneTriggerDefinition;
/* Fires the movement triggers an actor crosses between two positions. Only kinds 0xB and 1 trip triggers. Kind 6
 * triggers are rings (enter when moving inside enterRadius from outside it, exit when moving outside exitRadius
 * from inside it); kinds 10 and 7 fire their enter event inside their radius while the two actors overlap in height,
 * and a kind 10 trigger first asks func_80204308_de. Distances are measured in the xz plane. */
void Scene_UpdateMovementTriggers(Shared_World *world, LevelActor *actor, CVector3 *before, CVector3 *after) {
    s32 isKindB;
    s32 isKind1;
    f32 bottom;
    f32 top;
    f32 triggerBottom;
    f32 triggerTop;
    f32 beforeDistance;
    f32 afterDistance;
    f32 enterRadius;
    f32 exitRadius;
    f32 radius;
    s32 kind;
    s32 flags;
    s32 enterOnB;
    s32 enterOn1;
    s32 exitOnB;
    s32 exitOn1;
    s32 entering;
    s32 exiting;
    s32 hit;
    s32 enterMode;
    s32 exitMode;
    s32 ring;
    s32 checkHeight;
    s32 i;
    SceneTriggerDefinition *definition;
    LevelActor *trigger;

    if (before->x == after->x && before->y == after->y && before->z == after->z) {
        return;
    }
    kind = actor->definition->kind;
    isKindB = kind == 0xB;
    isKind1 = kind == 1;
    bottom = actor->position0.y + Sound_GetActorBaseOffset(actor);
    top = bottom + Particle_GetActorHeight(actor);
    for (i = 0; i < world->flaggedCount; i++) {
        trigger = world->flagged[i];
        if (trigger == actor) {
            continue;
        }
        ring = 0;
        checkHeight = 0;
        triggerBottom = trigger->position0.y + Sound_GetActorBaseOffset(trigger);
        triggerTop = triggerBottom + Particle_GetActorHeight(trigger);
        definition = (SceneTriggerDefinition *)trigger->definition;
        switch (definition->header.kind) {
        case 6:
            enterMode = 0;
            ring = 1;
            exitMode = 1;
            flags = definition->header.flags;
            enterRadius = definition->enterRadius;
            exitRadius = definition->exitRadius;
            enterOnB = flags & 4;
            enterOn1 = flags & 8;
            exitOnB = flags & 0x10;
            exitOn1 = flags & 0x20;
            break;
        case 10:
            enterMode = 1;
            exitMode = 0;
            exitOnB = 0;
            exitOn1 = 0;
            checkHeight = 1;
            flags = definition->header.flags;
            enterRadius = definition->exitRadius;
            exitRadius = 0.0f;
            enterOnB = flags & 4;
            enterOn1 = flags & 8;
            break;
        case 7:
            enterMode = 1;
            exitMode = 0;
            exitOnB = 0;
            exitOn1 = 0;
            checkHeight = 1;
            flags = definition->header.flags;
            enterRadius = definition->touchRadius;
            exitRadius = 0.0f;
            enterOnB = flags & 8;
            enterOn1 = flags & 0x10;
            break;
        default:
            enterMode = 0;
            enterRadius = 0.0f;
            enterOnB = 0;
            enterOn1 = 0;
            exitMode = 0;
            exitOnB = 0;
            exitOn1 = 0;
            exitRadius = 0.0f;
            break;
        }
        if (checkHeight && (top < triggerBottom || triggerTop < bottom)) {
            entering = 0;
            exiting = 0;
        } else {
            entering = 0;
            if ((isKindB && enterOnB) || (isKind1 && enterOn1)) {
                entering = 1;
            }
            exiting = 0;
            if ((isKindB && exitOnB) || (isKind1 && exitOn1)) {
                exiting = 1;
            }
        }
        if (entering || exiting) {
            beforeDistance = (before->x - trigger->position0.x) * (before->x - trigger->position0.x) +
                             (before->z - trigger->position0.z) * (before->z - trigger->position0.z);
            afterDistance = (after->x - trigger->position0.x) * (after->x - trigger->position0.x) +
                            (after->z - trigger->position0.z) * (after->z - trigger->position0.z);
            if (entering) {
                if (ring) {
                    radius = enterRadius * enterRadius;
                    hit = 0;
                    if (radius < beforeDistance && afterDistance <= radius) {
                        hit = 1;
                    }
                } else {
                    hit = 1;
                    if (!(afterDistance <= enterRadius * enterRadius)) {
                        hit = 0;
                    }
                }
                if (hit) {
                    if (trigger->definition->kind == 10 && enterMode == 1) {
                        hit = Level_ShowTriggerMessage(trigger, &trigger->behaviorFlags, actor);
                    }
                    if (hit) {
                        Weapons_RequestActorState(trigger, &trigger->behaviorFlags, enterMode);
                    }
                }
            }
            if (exiting) {
                if (ring) {
                    radius = exitRadius * exitRadius;
                    hit = 0;
                    if (beforeDistance <= radius && radius < afterDistance) {
                        hit = 1;
                    }
                } else {
                    hit = 1;
                    if (!(exitRadius * exitRadius < afterDistance)) {
                        hit = 0;
                    }
                }
                if (hit) {
                    Weapons_RequestActorState(trigger, &trigger->behaviorFlags, exitMode);
                }
            }
        }
    }
}

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
extern struct CCameraText_t *Camera_PostScaledScreenMessage(void *, void *, u8 *, f32);
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
            else scene->selectionFlags = Items_FindPlacedObjectsByKey(scene, -1, scene->selectionValues[1], &scene->selectionSpawn, 1);
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
extern void Scene_ReleaseResource(s32, void *);
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
extern ResultsHeadingCharacter D_800DFA6C[];
extern char D_800C5284_de[], D_800C52E4_de[], D_00285160[];
extern char *D_800D3304, *D_800D3334, *D_800D3338, *D_800D333C, *D_800D3340, *D_800D334C_de, *D_800D3350,
    *D_800D3354, *D_800D3358, *D_800D335C, *D_800D3360, *D_800D3364, *D_800D3368_de, *D_800D336C,
    *D_800D3370, *D_800D3374, *D_800D3378, *D_800D337C, *D_800D3380, *D_800D3384, *D_800D3388,
    *D_800D338C, *D_800D3390_de, *D_800D3394, *D_800D3398;
extern void Camera_ClearMessageCount(void);
extern void func_80245A78_de(char *);
extern s32 Render_GetDirectoryEntry(s32 *, s32, s32);
extern void *func_80254284_de(s32, void **, s32, void *);
extern ResultsText *func_80254408_de(s32, void *, s32, s32, void *, s32, void *);
extern void func_802BD3A0_de(void *, const void *, s32);
extern s32 func_802A0C08_de(char *, const char *, ...);
extern u8 Weapons_GetLevelProgress(Profile *, s32);
extern void func_8028DA74_de(Shared_World *);
extern void *Scene_RequestResource(s32, u32, u32, u32, u32, s32, void *, const char *, u32);
extern s32 Render_LocatePackSection(s32, s32, s32, s32 *);
extern s32 Frontend_FindKeyIndex(s32);
static inline void copyLevelName(Shared_World *world, s32 level, char *out, s32 limit) {
    void *handle;
    s32 entry;
    void *bank;
    ResultsText *name;
    s32 length;

    entry = Render_GetDirectoryEntry(world->resourceDirectory, world->resourceBank, level);
    bank = func_80254284_de(0, &handle, entry, D_800C5110_de);
    name = func_80254408_de(0, handle, 8, entry, world, 0, D_800C5284_de);
    length = name->length;
    if (limit < length) {
        length = limit;
    }
    func_802BD3A0_de(out, name->text, length);
    Scene_ReleaseResource(0, name);
    if (world->level != level) {
        Scene_ReleaseResource(0, bank);
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
            index = Scene_RequestResource(0, world->challengeFile, world->challengeFile, world->challengeFileSize, mode,
                                     0, 0, D_800C5290_de, direct);
            if (index != 0) {
                file = Render_LocatePackSection((s32)*index, world->challengeFile, level, &size);
                Scene_ReleaseResource(0, index);
                if ((world->resourceHandle =
                         Scene_RequestResource(0, file, file, size, mode, 0, D_00285160, D_800C52BC, direct)) == 0) {
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
    LevelGoal *levelGoal;
    u8 mode;
    u8 minutes;
    s32 seconds;
    s32 players;
    LevelChallenge *challenge;
    ResultsHeadingCharacter *character;

    Camera_ClearMessageCount();
    copyLevelName(&D_8011FE88, D_8015402C, name, 63);
    func_80245A78_de(name);
    if (currentGame()->controllerMode == 0) {
        return;
    }
    levelGoal = &D_8014DD98; /* kind (0 rounds, 1 laps, 2 single laps, 3 targets), then the target goal */
    switch (levelGoal->kind) {
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
        switch (levelGoal->goal) {
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
        players = (Weapons_GetLevelProgress(D_80102B00, D_80102B00[0].slot) >> 1) + 1;
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
        character = &RESULTS_CHARACTERS[Frontend_FindKeyIndex(challenge->character)];
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
        switch (D_8014DD98.kind) {
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
