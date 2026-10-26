#include "include_asm.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "SCHED/8023A284.H"
#include "COMMON/RESIDENTSTATE.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/GAMEPLAY_REACTIONS.H"
#include "COMMON/FRUSTUM.H"
#include "TEXTURE/80294C64_12.H"
#include "TEXTURE/80294C64_13.H"
#include "TEXTURE/80294C64_15.H"
#include "COMMON/WORLD.H"

extern void Cache_UnlockResource(void *, Node80253610 *);
extern void GraphU64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

/* Clip and draw a textured translucent fan at the object's depth. */
void func_8023A4E0_de(ObjectRecAt220 *object, ClipView *view) {
    AnimationInfo animation;
    CVector3 points[5];
    f32 red[5], green[5], blue[5], alpha[5];
    CVector3 triangle[3];
    CVector3 texcoord[3];
    f32 triRed[3], triGreen[3], triBlue[3], triAlpha[3];
    CVector3 edge0, edge1, normal;
    u8 center[3], rim[3];
    s32 below;
    void *resource;
    DescriptorRecAt29 *descriptor;
    s32 frameIndex, scaleS, scaleT;
    u8 *frame;
    f32 phase, fadeRange, fadeOffset;
    s32 format;
    s32 i, face, first, second, third;
    f32 scale, texturePeriod, wrapPeriod, distance, fade, depth, t;
    f32 maxS, minS, maxT, minT, shiftS, shiftT, factor;
    UnitVtx *vertex;

    resource = TextLoad_RequestTextureVariation(object->texture, -1);
    if (resource != 0) {
        TextLoad_ReadTextureAnimationInfo(resource, &animation);
        if (animation.unk0 != 0) {
            descriptor = object->descriptor;
            frame = animation.unk8;
            phase = object->phase / frame[1];
            scale = descriptor->textureScale * (object->textureScale * 768.0f);
            scaleS = (s32)((1 << frame[2]) * scale);
            scaleT = (s32)((1 << frame[3]) * scale);
            gDPPipeSync(g_displayListCursor++);
            frameIndex = (s32)phase % animation.unk0;
#if defined(VERSION_US_REV1)
            TextLoad_LoadTextureFrameTiles(object->texture, resource,
#else
            func_802950B4_de(object->texture, resource,
#endif
                frameIndex, 0,
                scaleS, scaleT, 0, 0, 15);
            texturePeriod = 5120.0f;
            wrapPeriod = 10240.0f;
            frame = animation.unk8;
            format = frame[0];
            switch (format) {
            case 2:
            default:
                Geometry_SetCombineMode(32);
                gDPSetEnvColor(g_displayListCursor++, descriptor->envRed, descriptor->envGreen, descriptor->envBlue, 255);
                center[0] = descriptor->red;
                center[1] = descriptor->green;
                center[2] = descriptor->blue;
                rim[0] = descriptor->red;
                rim[1] = descriptor->green;
                rim[2] = descriptor->blue;
                break;
            case 0: case 1:
                Geometry_SetCombineMode(33);
                center[0] = 255; center[1] = 255; center[2] = 255;
                rim[0] = 255; rim[1] = 255; rim[2] = 255;
                break;
            }
            below = 1;
            depth = object->depth;
            if (!(view->fan[0].y < (view->fan[1].y + view->fan[2].y + view->fan[3].y + view->fan[4].y) * 0.25f)) below = 0;
            distance = view->fan[0].y - depth;
            fade = descriptor->alpha;
            if (distance < 0.0f) distance = -distance;
            if (distance < descriptor->fadeDepth) {
                fadeOffset = distance - descriptor->fadeDepth * 0.25f;
                fadeRange = descriptor->fadeDepth * 0.75f;
                if (fadeOffset < 0.0f) fade = 0.0f;
                else fade = fadeOffset * fade / fadeRange;
            }
            fade *= object->throttle * object->opacity;
            for (i = 0; i < 5; i++) {
                points[i].x = view->fan[i].x;
                points[i].y = depth;
                points[i].z = view->fan[i].z;
                red[i] = i == 0 ? center[0] : rim[0];
                green[i] = i == 0 ? center[1] : rim[1];
                blue[i] = i == 0 ? center[2] : rim[2];
                alpha[i] = i == 0 ? fade : 0.0f;
            }
            for (i = 1; i < 5; i++) {
                t = VisData_GetPlaneSegmentFraction(view->clipPlane, &points[0].x, &points[i].x);
                if (t >= 0.0f && t < 1.0f) {
                    points[i].x = points[0].x + t * (points[i].x - points[0].x);
                    points[i].z = points[0].z + t * (points[i].z - points[0].z);
                }
            }
            for (face = 0; face < 4; face++) {
                switch (face) {
                case 0:
                default: first = 0; second = 1; third = 3; break;
                case 1: first = 0; second = 3; third = 4; break;
                case 2: first = 0; second = 4; third = 2; break;
                case 3: first = 0; second = 2; third = 1; break;
                }
                triangle[0] = points[first];
                triangle[1] = points[second];
                triangle[2] = points[third];
                GraphU64_SubtractVectors(&edge0, &triangle[1], &triangle[0]);
                GraphU64_SubtractVectors(&edge1, &triangle[2], &triangle[1]);
                GraphU64_CrossVectors(&normal, &edge0, &edge1);
                if (normal.y <= 0.0f) {
                    if (below != 1) goto draw_face;
                } else {
                    if (below != 0) {
draw_face:
                        triRed[0] = red[first]; triRed[1] = red[second]; triRed[2] = red[third];
                        triGreen[0] = green[first]; triGreen[1] = green[second]; triGreen[2] = green[third];
                        triBlue[0] = blue[first]; triBlue[1] = blue[second]; triBlue[2] = blue[third];
                        triAlpha[0] = alpha[first]; triAlpha[1] = alpha[second]; triAlpha[2] = alpha[third];
                        texcoord[0] = points[first];
                        texcoord[1] = points[second];
                        texcoord[2] = points[third];
                        for (i = 0; i < 3; i++) {
                            texcoord[i].x -= triangle[0].x * 0.5f;
                            texcoord[i].z -= triangle[0].z * 0.5f;
                            texcoord[i].x += object->offsetS;
                            texcoord[i].z += object->offsetT;
                        }
                        maxS = texcoord[2].x;
                        if (!(texcoord[1].x <= maxS)) maxS = texcoord[1].x;
                        if (!(texcoord[0].x <= maxS)) maxS = texcoord[0].x;
                        minS = texcoord[2].x;
                        if (!(minS <= texcoord[1].x)) minS = texcoord[1].x;
                        if (!(minS <= texcoord[0].x)) minS = texcoord[0].x;
                        maxT = texcoord[2].z;
                        if (!(texcoord[1].z <= maxT)) maxT = texcoord[1].z;
                        if (!(texcoord[0].z <= maxT)) maxT = texcoord[0].z;
                        minT = texcoord[2].z;
                        if (!(minT <= texcoord[1].z)) minT = texcoord[1].z;
                        if (!(minT <= texcoord[0].z)) minT = texcoord[0].z;
                        if (wrapPeriod <= maxS) shiftS = (s32)(maxS / wrapPeriod) * -wrapPeriod;
                        else if (minS <= -wrapPeriod) shiftS = (s32)(minS / wrapPeriod) * wrapPeriod;
                        else shiftS = 0.0f;
                        if (wrapPeriod <= maxT) shiftT = (s32)(maxT / wrapPeriod) * -wrapPeriod;
                        else if (minT <= -wrapPeriod) shiftT = (s32)(minT / wrapPeriod) * wrapPeriod;
                        else shiftT = 0.0f;
                        for (i = 0; i < 3; i++) {
                            vertex = i + &object->vertices[D_800D297C][face * 3];
                            vertex->flag = 0;
                            vertex->x = (s32)triangle[i].x;
                            vertex->y = (s32)triangle[i].y;
                            vertex->z = (s32)triangle[i].z;
                            factor = 16384.0f / texturePeriod;
                            vertex->s = (s32)((texcoord[i].x + shiftS) * factor);
                            vertex->t = (s32)((texcoord[i].z + shiftT) * factor);
                            vertex->r = (u32)triRed[i];
                            vertex->g = (u32)triGreen[i];
                            vertex->b = (u32)triBlue[i];
                            vertex->a = (u32)triAlpha[i];
                        }
                        gSPVertex(g_displayListCursor++, &object->vertices[D_800D297C][face * 3], 3, 0);
                        gSP1Triangle(g_displayListCursor++, 0, 1, 2, 0);
                    }
                }
            }
        }
        Cache_UnlockResource(0, resource);
    }
}

/* Updates the scene's effect objects for one host: spawns an object for every enabled effect
 * descriptor bit that has none yet, then fades each active object up or down, advances its phase and
 * texture scroll, sets its depth from the host, and returns objects that have faded out to the free list. */
typedef struct HostView8023AFF0 {
    char pad00[0x24];
    s32 stalled;
    char pad28[0x10];
    s32 field38;
    char pad3C[4];
    s32 field40;
    char pad44[0x14];
    void *resource;
    char pad5C[0xD0];
    f32 speed;
} HostView8023AFF0;
extern DescriptorRecAt29 *D_801370C8;
extern s32 D_801370CC;
extern f32 D_800D2988;
extern Shared_ReactionFlags *Scene_GetModelRecordByIndexPointer(void *, void *);
extern f32 Region_GetPolygonHeight(void *, s32, s32);
extern void Sky_GetObjectPositionAt260(CVector3 *, void *);
extern void TextLoad_LocateTextureResource(s32 *, s32);
extern void func_80255ED8_de(void *, void *);
extern void func_80255D14_de(void *, void *);
extern void func_80255CB8_de(void *, void *);
static inline ObjectRecAt220 *allocateSceneEffect(Scene *scene) {
    ObjectRecAt220 *object = (ObjectRecAt220 *)scene->freeObjects.head;
    if (object != 0) {
        func_80255ED8_de(&scene->freeObjects, object);
        func_80255D14_de(&scene->objects, object);
    }
    return object;
}

static inline s32 updateSceneEffect(ObjectRecAt220 *object, HostView8023AFF0 *host, u16 mask, s32 below, f32 hostDepth, f32 limit) {
    DescriptorRecAt29 *descriptor = object->descriptor;
    f32 value, step, depth, wrapPeriod, fadeStep;
    if (object->mask & mask) {
        value = object->throttle;
        fadeStep = descriptor->throttleRate * D_800D2988;
        value += fadeStep;
        if (1.0f < value) {
            value = 1.0f;
        }
        object->throttle = value;
    } else if (object->throttle == 0.0f) {
        return 1;
    } else {
        value = object->throttle - descriptor->throttleRate * D_800D2988;
        if (value < 0.0f) {
            value = 0.0f;
        }
        object->throttle = value;
    }
    object->phase = object->phase + D_800D2988 * descriptor->phaseRate * object->phaseScale;
    step = D_800D2988 * D_800CD744_de * descriptor->spinRate;
    value = object->offsetS + step * 1.536f;
    wrapPeriod = 20480.0f;
    object->offsetS = value;
    if (wrapPeriod < value) {
        object->offsetS = value - wrapPeriod;
    }
    value = object->offsetT + step * 3.072f;
    object->offsetT = value;
    if (wrapPeriod < value) {
        object->offsetT = value - wrapPeriod;
    }
    depth = descriptor->baseSpeed + object->trim;
    if (below && host->stalled == 0) {
        depth += hostDepth;
    } else if (descriptor->flags & 1) {
        depth += host->speed * descriptor->hostScale;
    } else if (descriptor->flags & 2) {
        depth += limit;
    }
    object->depth = depth;
    return 0;
}

void Sky_UpdateSceneEffects(Scene *scene, HostView8023AFF0 *host) {
    CVector3 anchor;
    CVector3 probe;
    Shared_ReactionFlags *entry;
    DescriptorRecAt29 *descriptor;
    ObjectRecAt220 *object;
    ObjectRecAt220 *next;
    void *resource;
    f32 hostDepth, limit, fadeLimit, value;
    s32 below;
    s32 count;
    u16 mask;
    u32 bit;

    if (g_world.frozen != 0) {
        return;
    }
    resource = host->resource;
    if (resource == 0) {
        return;
    }
    entry = Scene_GetModelRecordByIndexPointer(&g_world, resource);
    if (entry == 0) {
        return;
    }
    hostDepth = 0.0f;
    limit = Region_GetPolygonHeight(resource, host->field38, host->field40);
    below = 0;
    if (entry->flags & 1) {
        Sky_GetObjectPositionAt260(&anchor, host);
        fadeLimit = 0.5f;
        value = (entry->height - anchor.y) * fadeLimit;
        if (20.48f < value) {
            fadeLimit = 20.48f;
        } else {
            Sky_GetObjectPositionAt260(&probe, host);
            fadeLimit = (entry->height - probe.y) * fadeLimit;
        }
        Sky_GetObjectPositionAt260(&anchor, host);
        if (!(anchor.y < entry->height)) {
            below = 0;
        } else {
            below = 1;
        }
        hostDepth = entry->height - fadeLimit;
    }
    mask = entry->mask;
    count = D_801370CC;
    descriptor = D_801370C8;
    bit = 1;
    while (--count != -1) {
        if ((u16)(mask & bit) && descriptor->texture != 0 && !(scene->effectMask & bit)) {
            object = allocateSceneEffect(scene);
            if (object != 0) {
                object->descriptor = descriptor;
                object->mask = bit;
                TextLoad_LocateTextureResource(object->texture, descriptor->texture);
                object->offsetS = 0.0f;
                object->offsetT = 0.0f;
                object->throttle = 0.0f;
                object->phase = 0.0f;
                object->phaseScale = 1.0f;
                object->textureScale = 1.0f;
                object->trim = 0.0f;
                object->opacity = 1.0f;
                scene->effectMask |= bit;
            }
        }
        descriptor++;
        bit <<= 1;
    }
    if ((u16)mask == 0) {
        return;
    }
    object = scene->objects;
    if (object == 0) {
        return;
    }
    do {
        next = object->next;
        if (updateSceneEffect(object, host, mask, below, hostDepth, limit)) {
            scene->effectMask &= ~object->mask;
            func_80255ED8_de(&scene->objects, object);
            func_80255CB8_de(&scene->freeObjects, object);
        }
        object = next;
    } while (object != 0);
}
