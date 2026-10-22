#include "include_asm.h"
#include "COMMON/DESCRIPTORRECAT29.H"
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

extern void func_80253754_de(void *, Node80253610 *);
extern void func_80272018_de(CVector3 *, CVector3 *, CVector3 *);

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

    resource = func_80295F14_de(object->texture, -1);
    if (resource != 0) {
        func_80295F78_de(resource, &animation);
        if (animation.unk0 != 0) {
            descriptor = object->descriptor;
            frame = animation.unk8;
            phase = object->phase / frame[1];
            scale = descriptor->textureScale * (object->textureScale * 768.0f);
            scaleS = (s32)((1 << frame[2]) * scale);
            scaleT = (s32)((1 << frame[3]) * scale);
            gDPPipeSync(D_80110634++);
            frameIndex = (s32)phase % animation.unk0;
#if defined(VERSION_US_REV1)
            func_80295FB4_us_rev1(object->texture, resource,
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
                func_80268CE0_de(32);
                gDPSetEnvColor(D_80110634++, descriptor->envRed, descriptor->envGreen, descriptor->envBlue, 255);
                center[0] = descriptor->red;
                center[1] = descriptor->green;
                center[2] = descriptor->blue;
                rim[0] = descriptor->red;
                rim[1] = descriptor->green;
                rim[2] = descriptor->blue;
                break;
            case 0: case 1:
                func_80268CE0_de(33);
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
                t = func_80296930_de(view->clipPlane, &points[0].x, &points[i].x);
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
                func_80271F68_de(&edge0, &triangle[1], &triangle[0]);
                func_80271F68_de(&edge1, &triangle[2], &triangle[1]);
                func_80272018_de(&normal, &edge0, &edge1);
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
                        gSPVertex(D_80110634++, &object->vertices[D_800D297C][face * 3], 3, 0);
                        gSP1Triangle(D_80110634++, 0, 1, 2, 0);
                    }
                }
            }
        }
        func_80253754_de(0, resource);
    }
}

#ifdef NON_MATCHING
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
extern char D_8011FE88;
extern f32 D_800D2988;
extern f32 D_800C35D4_de, D_800C35D8_de, D_800C35DC_de, D_800C35E0_de, D_800C35E4_de, D_800C35E8_de, D_800C35EC_de;
extern Shared_ReactionFlags *func_8028B2F8_de(void *, void *);
extern f32 func_80275DD4_de(void *, s32, s32);
extern void func_802390D0_de(CVector3 *, void *);
extern void func_80295E84_de(s32 *, s32);
extern void func_80255ED8_de(void *, void *);
extern void func_80255D14_de(void *, void *);
extern void func_80255CB8_de(void *, void *);
void func_8023AFF0_de(Scene *scene, HostView8023AFF0 *host) {
    CVector3 anchor;
    CVector3 probe;
    Shared_ReactionFlags *entry;
    DescriptorRecAt29 *descriptor;
    ObjectRecAt220 *object;
    ObjectRecAt220 *next;
    void *resource;
    f32 hostDepth, limit, fadeLimit, step, value, depth;
    s32 below;
    s32 count;
    s32 remove;
    u16 mask;
    u32 bit;

    if (D_801371DC != 0) {
        return;
    }
    resource = host->resource;
    if (resource == 0) {
        return;
    }
    entry = func_8028B2F8_de(&D_8011FE88, resource);
    if (entry == 0) {
        return;
    }
    hostDepth = 0.0f;
    below = 0;
    limit = func_80275DD4_de(resource, host->field38, host->field40);
    if (entry->flags & 1) {
        func_802390D0_de(&anchor, host);
        fadeLimit = D_800C35D4_de;
        value = (entry->height - anchor.y) * fadeLimit;
        if (D_800C35D8_de < value) {
            fadeLimit = D_800C35D8_de;
        } else {
            func_802390D0_de(&probe, host);
            fadeLimit = (entry->height - probe.y) * fadeLimit;
        }
        func_802390D0_de(&anchor, host);
        if (anchor.y < entry->height) {
            below = 1;
        } else {
            below = 0;
        }
        hostDepth = entry->height - fadeLimit;
    }
    mask = entry->mask;
    count = D_801370CC - 1;
    descriptor = D_801370C8;
    if (count != -1) {
        bit = 1;
        do {
            if ((mask & bit) && descriptor->texture != 0 && !(scene->effectMask & bit)) {
                object = (ObjectRecAt220 *)scene->freeObjects.head;
                if (object != 0) {
                    func_80255ED8_de(&scene->freeObjects, object);
                    func_80255D14_de(&scene->objects, object);
                }
                if (object != 0) {
                    object->descriptor = descriptor;
                    object->mask = bit;
                    func_80295E84_de(object->texture, descriptor->texture);
                    object->offsetS = 0.0f;
                    object->offsetT = 0.0f;
                    object->throttle = 0.0f;
                    object->phase = 0.0f;
                    object->phaseScale = D_800C35DC_de;
                    object->textureScale = D_800C35DC_de;
                    object->trim = 0.0f;
                    object->opacity = D_800C35DC_de;
                    scene->effectMask |= bit;
                }
            }
            descriptor++;
            count--;
            bit <<= 1;
        } while (count != -1);
    }
    if (mask == 0) {
        return;
    }
    object = scene->objects;
    if (object == 0) {
        return;
    }
    do {
        next = object->next;
        descriptor = object->descriptor;
        remove = 0;
        if (object->mask & mask) {
            value = object->throttle + descriptor->throttleRate * D_800D2988;
            if (D_800C35E0_de < value) {
                value = D_800C35E0_de;
            }
            object->throttle = value;
        } else if (object->throttle == 0.0f) {
            remove = 1;
        } else {
            value = object->throttle - descriptor->throttleRate * D_800D2988;
            if (value < 0.0f) {
                value = 0.0f;
            }
            object->throttle = value;
        }
        if (!remove) {
            object->phase = object->phase + D_800D2988 * descriptor->phaseRate * object->phaseScale;
            step = D_800D2988 * D_800CD744_de * descriptor->spinRate;
            value = object->offsetS + step * D_800C35E4_de;
            object->offsetS = value;
            if (D_800C35E8_de < value) {
                object->offsetS = value - D_800C35E8_de;
            }
            value = object->offsetT + step * D_800C35EC_de;
            object->offsetT = value;
            if (D_800C35E8_de < value) {
                object->offsetT = value - D_800C35E8_de;
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
        } else {
            scene->effectMask &= ~object->mask;
            func_80255ED8_de(&scene->objects, object);
            func_80255CB8_de(&scene->freeObjects, object);
        }
        object = next;
    } while (object != 0);
}
#else
INCLUDE_ASM("span_1000", func_8023AFF0_de);
#endif
