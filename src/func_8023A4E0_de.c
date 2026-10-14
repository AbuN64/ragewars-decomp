#include "span_1000/code_8023A284.h"
#include "span_1000/code_80294C64.h"
#include "gfx.h"
#include "gbi.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/func_80214624_de_closed.h"
#include "span_1000/code_8022F3E8.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_80296014.h"

extern void func_80253754_de(void *, Node80253610 *);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);

/* Clip and draw a textured translucent fan at the object's depth. */
void func_8023A4E0_de(ObjectRecAt220 *object, View_func_8023B3F8_de *view) {
    func_80296F7C_S1 animation;
    Vec3 points[5];
    f32 red[5], green[5], blue[5], alpha[5];
    Vec3 triangle[3];
    Vec3 texcoord[3];
    f32 triRed[3], triGreen[3], triBlue[3], triAlpha[3];
    Vec3 edge0, edge1, normal;
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
