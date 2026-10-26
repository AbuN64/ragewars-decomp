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
f32 Menu_EvaluateTrackScalar(f32 t) {
    s32 *track;
    D_800C7470_Pair *key;
    s32 count;
    s32 i;
    f32 u;
    track = SetN64_GetPackSection(D_800E2830->resource, 3);
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

#include "COMMON/WORLD.H"
extern f32 D_800DCB40[];
extern u8 D_80100030[];
extern s32 Cinema_IsSequenceInWindow(void);
extern void func_802453D4_de(void);
extern CVector3 Menu_GetTrackEyePosition(f32);
extern CVector3 Menu_GetTrackTargetPosition(f32);
extern void GraphU64_ScaleVector(CVector3 *, CVector3 *, f32);
extern void GraphU64_IdentityMatrix(void *);
extern void GraphU64_MatrixFromEulerXYZ(void *, f32, f32, f32);
extern void GraphU64_TransformPoint(void *, CVector3 *, CVector3 *);
extern void Scene_RequestVisibleGridSections(void *);
extern s32 Unicol_MoveActorWithCollision(SharedTrackObject *, f32, f32, f32, void *);
extern void Scene_UnlockActiveSectionResources(void *);
extern f32 GraphU64_GetHorizontalAngle(CVector3 *);
extern f32 GraphU64_GetVerticalAngle(CVector3 *);
/* Follow the keyframe camera and keep the collision result across world cleanup. */
void Menu_UpdateTrackCamera(SharedTrackCamera *camera) {
    CVector3 eye;
    CVector3 target;
    CVector3 delta;
    SharedTrackObjectPrefix saved;
    f32 matrix[16];
    CVector3 rotated;
    SharedTrackObject *actor;
    s32 collisionHit;
    f32 yaw;
    f32 pitch;
    f32 scale;

    if (D_800E2830->active == 0) {
        return;
    }
    if (Cinema_IsSequenceInWindow() == 0) {
        return;
    }
    if (D_800E2830->time < D_800E2830->start || D_800E2830->end < D_800E2830->time) {
        return;
    }
    if (D_800E2830->messageCount > 0) {
        func_802453D4_de();
    }
    eye = Menu_GetTrackEyePosition(D_800E2830->time);
    target = Menu_GetTrackTargetPosition(D_800E2830->time);
    scale = D_800DCB40[0];
    GraphU64_ScaleVector(&eye, &eye, scale);
    GraphU64_ScaleVector(&target, &target, scale);
    camera->distance = 0.0f;
    GraphU64_SubtractVectors(&delta, &target, &eye);
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
        GraphU64_IdentityMatrix(matrix);
        GraphU64_MatrixFromEulerXYZ(matrix, 0.0f, D_800E2830->yaw, 0.0f);
        GraphU64_TransformPoint(matrix, &target, &rotated);
        target = rotated;
        GraphU64_TransformPoint(matrix, &eye, &rotated);
        eye = rotated;
        GraphU64_AddVec3(&target, &target, &D_800E2830->position);
        GraphU64_AddVec3(&eye, &eye, &D_800E2830->position);
        GraphU64_SubtractVectors(&delta, &target, &eye);
        if (actor != 0) {
            saved = actor->prefix;
            actor->prefix.position = target;
            Scene_RequestVisibleGridSections(&g_world);
            collisionHit = Unicol_MoveActorWithCollision(actor, eye.x, eye.y, eye.z, D_80100030);
            Scene_UnlockActiveSectionResources(&g_world);
            actor->prefix = saved;
            if (collisionHit != 0) {
                eye = *(CVector3 *)&D_801001F8;
            }
        }
    }
    yaw = GraphU64_GetHorizontalAngle(&delta);
    pitch = GraphU64_GetVerticalAngle(&delta);
    camera->distance += yaw;
    camera->pitch = -pitch;
    camera->position = eye;
}
