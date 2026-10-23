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
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
f32 func_8040184C_de(f32 t) {
    s32 *track;
    D_800C7470_Pair *key;
    s32 count;
    s32 i;
    f32 u;
    track = func_8028FDB4_de(D_800E2830->resource, 3);
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
#include "COMMON/WORLD.H"
extern f32 D_800DCB40[];
extern u8 D_80100030[];
extern s32 func_80245798_de(void);
extern void func_802453D4_de(void);
extern void func_80401214_de(CVector3 *, f32);
extern void func_804013BC_de(CVector3 *, f32);
extern void func_80271F9C_de(CVector3 *, CVector3 *, f32);
extern void func_802727D8_de(void *);
extern void func_80272E3C_de(void *, f32, f32, f32);
extern void func_80272898_de(void *, CVector3 *, CVector3 *);
extern void func_80288470_de(void *);
extern s32 func_80243A90_de(SharedTrackObject *, f32, f32, f32, void *);
extern s32 func_8028D888_de(void *);
extern f32 Particle_GetHorizontalAngle(CVector3 *);
extern f32 func_802725FC_de(CVector3 *);
/* 252/253 words (18 aligned edits); remaining: regalloc, the world-hit flag takes $v0 instead of $s0 so one move drops */
void Menu_UpdateTrackCamera(SharedTrackCamera *camera) {
    CVector3 eye;
    CVector3 target;
    CVector3 delta;
    SharedTrackObjectPrefix saved;
    f32 matrix[16];
    CVector3 rotated;
    SharedTrackObject *actor;
    s32 hit;
    f32 yaw;
    f32 pitch;
    f32 scale;

    if (D_800E2830->active == 0) {
        return;
    }
    if (func_80245798_de() == 0) {
        return;
    }
    if (D_800E2830->time < D_800E2830->start || D_800E2830->end < D_800E2830->time) {
        return;
    }
    if (D_800E2830->messageCount > 0) {
        func_802453D4_de();
    }
    func_80401214_de(&eye, D_800E2830->time);
    func_804013BC_de(&target, D_800E2830->time);
    scale = D_800DCB40[0];
    func_80271F9C_de(&eye, &eye, scale);
    func_80271F9C_de(&target, &target, scale);
    camera->distance = 0.0f;
    func_80271F68_de(&delta, &target, &eye);
    if (((D_800E2830->spec.flags & 1) && D_800E2830->target != 0) || (D_800E2830->spec.flags & 2)) {
        actor = D_80145060.actorList;
        if ((D_800E2830->spec.flags & 1) && D_800E2830->target != 0) {
            D_800E2830->position = D_800E2830->target->prefix.position;
            D_800E2830->yaw = D_800E2830->target->yaw + D_800DCB40[1];
        }
        if (D_800E2830->spec.flags & 2) {
            if (actor != 0) {
                D_800E2830->position = actor->prefix.position;
                D_800E2830->yaw = actor->yaw;
            } else {
                D_800E2830->position.x = 0.0f;
                D_800E2830->position.y = 0.0f;
                D_800E2830->position.z = 0.0f;
                D_800E2830->yaw = 0.0f;
            }
        }
        func_802727D8_de(matrix);
        func_80272E3C_de(matrix, 0.0f, D_800E2830->yaw, 0.0f);
        func_80272898_de(matrix, &target, &rotated);
        target = rotated;
        func_80272898_de(matrix, &eye, &rotated);
        eye = rotated;
        func_80271F34_de(&target, &target, &D_800E2830->position);
        func_80271F34_de(&eye, &eye, &D_800E2830->position);
        func_80271F68_de(&delta, &target, &eye);
        if (actor != 0) {
            saved = actor->prefix;
            actor->prefix.position = target;
            func_80288470_de(&D_8011FE88);
            func_80243A90_de(actor, eye.x, eye.y, eye.z, D_80100030);
            hit = func_8028D888_de(&D_8011FE88);
            actor->prefix = saved;
            if (hit != 0) {
                eye = *(CVector3 *)&D_801001F8;
            }
        }
    }
    yaw = Particle_GetHorizontalAngle(&delta);
    pitch = func_802725FC_de(&delta);
    camera->distance += yaw;
    camera->pitch = -pitch;
    camera->position = eye;
}
#else
INCLUDE_ASM("ovl_80400000", Menu_UpdateTrackCamera);
#endif
