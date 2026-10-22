#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "TYPES.H"
#include "MENU_2/80400000_16.H"
#include "RENDER_4/8028FD2C_6.H"

/* Evaluates keyframe track 3 of the current record's resource at time t: before the first key or
   after the last it holds that key's value, otherwise it finds the surrounding keys and blends
   their values with the smoothstep weight 3u^2 - 2u^3; an empty track yields D_800E0B60[1]. */
extern func_80203E78_S1 *D_800E2830;
f32 func_8040184C_de(f32 t) {
    s32 *track;
    D_800C7470_Pair *key;
    s32 count;
    s32 i;
    f32 u;
    track = func_8028FDB4_de(D_800E2830->unk4, 3);
    key = (D_800C7470_Pair *)(track + 2);
    count = track[1];
    for (i = 0; i < count; i++) {
    }
    if (count == 0) {
        return D_800E0B60[1];
    }
    if (t <= key[0].second) {
        return key[0].first;
    }
    if (key[count - 1].second <= t) {
        return key[count - 1].first;
    }
    while (key->second < t) {
        key++;
    }
    u = (t - key[-1].second) / (key->second - key[-1].second);
    u = u * (u * D_800DCB38) - 2.0f * u * u * u;
    return key[-1].first * ((*(&D_800DCB38 + 1)) - u) + key->first * u;
}

#ifdef NON_MATCHING
#define CM_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
#include "COMMON/WORLD.H"
typedef struct CamVec { f32 x; f32 y; f32 z; } CamVec;
typedef struct CamCopy50 { u8 bytes[0x50]; } CamCopy50;
extern u8 *D_80145060;
extern f32 D_800DCB40[];
extern u8 D_80100030[];
extern s32 func_80245798_de();
extern void func_802453D4_de();
extern void func_80401214_de();
extern void func_804013BC_de();
extern void func_80271F9C_de();
extern void func_80271F68_de();
extern void func_80271F34_de();
extern void func_802727D8_de();
extern void func_80272E3C_de();
extern void func_80272898_de();
extern void func_80288470_de();
extern s32 func_80243A90_de();
extern s32 func_8028D888_de();
extern f32 func_80271AA8_de();
extern f32 func_802725FC_de();
void func_80401980_de(u8 *out) {
    CamVec eye;
    CamVec target;
    CamVec delta;
    CamVec rotated;
    CamVec scratch;
    u8 matrix[0x40];
    CamCopy50 saved;
    u8 *camera = ((u8 *)D_800E2830);
    u8 *object;
    f32 yaw;
    f32 pitch;
    if (CM_FIELD(camera, s32, 0x38) == 0) {
        return;
    }
    if (func_80245798_de() == 0) {
        return;
    }
    camera = ((u8 *)D_800E2830);
    if (CM_FIELD(camera, f32, 0x1C) < CM_FIELD(camera, f32, 0x30) || CM_FIELD(camera, f32, 0x34) < CM_FIELD(camera, f32, 0x1C)) {
        return;
    }
    if (CM_FIELD(camera, s32, 0x1E0) > 0) {
        func_802453D4_de();
    }
    func_80401214_de(&eye, CM_FIELD(((u8 *)D_800E2830), f32, 0x1C));
    func_804013BC_de(&target, CM_FIELD(((u8 *)D_800E2830), f32, 0x1C));
    func_80271F9C_de(&eye, &eye, D_800DCB40[0]);
    func_80271F9C_de(&target, &target, D_800DCB40[0]);
    CM_FIELD(out, s32, 0x28) = 0;
    func_80271F68_de(&delta, &target, &eye);
    camera = ((u8 *)D_800E2830);
    if (((CM_FIELD(camera, u32, 0x74) & 1) && CM_FIELD(camera, u8 *, 0x18) != 0) || (CM_FIELD(camera, u32, 0x74) & 2)) {
        camera = ((u8 *)D_800E2830);
        object = D_80145060;
        if ((CM_FIELD(camera, u32, 0x74) & 1) && CM_FIELD(camera, u8 *, 0x18) != 0) {
            CM_FIELD(camera, CamVec, 0xF0) = CM_FIELD(CM_FIELD(camera, u8 *, 0x18), CamVec, 8);
            CM_FIELD(camera, f32, 0xFC) = CM_FIELD(CM_FIELD(camera, u8 *, 0x18), f32, 0x6C) + D_800DCB40[1];
        }
        if (CM_FIELD(((u8 *)D_800E2830), u32, 0x74) & 2) {
            camera = ((u8 *)D_800E2830);
            if (object == 0) {
                CM_FIELD(camera, s32, 0xF0) = 0;
                CM_FIELD(camera, s32, 0xF4) = 0;
                CM_FIELD(camera, s32, 0xF8) = 0;
                CM_FIELD(camera, s32, 0xFC) = 0;
            } else {
                CM_FIELD(camera, CamVec, 0xF0) = CM_FIELD(object, CamVec, 8);
                CM_FIELD(camera, f32, 0xFC) = CM_FIELD(object, f32, 0x6C);
            }
        }
        func_802727D8_de(matrix);
        func_80272E3C_de(matrix, 0.0f, CM_FIELD(((u8 *)D_800E2830), f32, 0xFC), 0.0f);
        func_80272898_de(matrix, &target, &rotated);
        target = rotated;
        func_80272898_de(matrix, &eye, &rotated);
        eye = rotated;
        func_80271F34_de(&target, &target, ((u8 *)D_800E2830) + 0xF0);
        func_80271F34_de(&eye, &eye, ((u8 *)D_800E2830) + 0xF0);
        func_80271F68_de(&delta, &target, &eye);
        if (object != 0) {
            saved = *(CamCopy50 *)object;
            CM_FIELD(object, CamVec, 8) = target;
            func_80288470_de(&D_8011FE88);
            func_80243A90_de(object, eye.x, eye.y, eye.z, D_80100030);
            if (func_8028D888_de(&D_8011FE88) != 0) {
                *(CamCopy50 *)object = saved;
                eye = *(CamVec *)&D_801001F8;
            } else {
                *(CamCopy50 *)object = saved;
            }
        }
    }
    yaw = func_80271AA8_de(&delta);
    pitch = func_802725FC_de(&delta);
    CM_FIELD(out, f32, 0x28) = CM_FIELD(out, f32, 0x28) + yaw;
    CM_FIELD(out, f32, 0x2C) = -pitch;
    CM_FIELD(out, CamVec, 0x38) = eye;
}
#else
INCLUDE_ASM("ovl_80400000", func_80401980_de);
#endif
