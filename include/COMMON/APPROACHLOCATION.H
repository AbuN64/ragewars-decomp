#ifndef COMMON_APPROACHLOCATION_H
#define COMMON_APPROACHLOCATION_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "COMMON/PROBE.H"
#include "FX/80271B18.H"

typedef struct { CVector3 pos; s32 unkC; } ApproachLocation;
extern f32 D_800C2160_de[],D_800C215C_de;
extern f32 Barrel_GetSignedAngleToPoint(Actor_func_80214624_de *,CVector3);
extern f32 GameObject_GetActorRadius(Actor_u1 *);
extern f32 GraphU64_GetHorizontalAngle(CVector3 *);
struct Cursor;
extern ApproachLocation *func_80219408_de(struct Cursor *);
extern s32 CCollision_CopyProbePosition(Actor_func_80214624_de *,CVector3,s32,s32,CVector3 *);
struct Node75;
extern s32 Region_IsPointInTriangleXZ(struct Node75 *,f32,f32);
extern void InstHdr_CopyActorPositionAndModel(Actor_func_80214624_de *,CVector3,CVector3 *,s32 *,s32,s32);
extern void GraphU64_AddVec3(CVector3 *,CVector3 *,CVector3 *);
extern void GraphU64_SubtractVectors(CVector3 *,CVector3 *,CVector3 *);
extern void GraphU64_ScaleVector(CVector3 *,CVector3 *,f32);
static inline void approach(Actor_func_80214624_de *arg0,Actor_func_80214624_de *arg2,Actor_func_80214624_de *temp_a2,CVector3 *posp,s32 *roomp) {
 CVector3 delta,offset; f32 temp_f20;
        if (temp_a2 != 0) {
            GraphU64_SubtractVectors(&delta, &arg2->pos, &temp_a2->pos);
            delta.y = 0;
            GraphU64_NormalizeVec3(&delta);
        } else {
            delta.x = 0;
            delta.y = 0;
            delta.z = 0;
        }
        temp_f20 = GameObject_GetActorRadius(arg2);
        GraphU64_ScaleVector(&delta, &delta, temp_f20 + GameObject_GetActorRadius(arg0) + D_800C215C_de);
        GraphU64_AddVec3(&offset, &arg2->pos, &delta);
        InstHdr_CopyActorPositionAndModel(arg2, offset, posp, roomp, 0, 0);
}
#endif
