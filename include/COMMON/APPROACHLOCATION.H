#ifndef COMMON_APPROACHLOCATION_H
#define COMMON_APPROACHLOCATION_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "COMMON/PROBE.H"
#include "FX_2/80271B18.H"

typedef struct { CVector3 pos; s32 unkC; } ApproachLocation;
extern f32 D_800C2160_de[],D_800C215C_de;
extern f32 Weapons_GetSignedAngleToPoint(Actor_func_80214624_de *,CVector3);
extern f32 Particle_GetActorRadius(Actor_u1 *);
extern f32 Particle_GetHorizontalAngle(CVector3 *);
struct Cursor;
extern ApproachLocation *func_80219408_de(struct Cursor *);
extern s32 func_80240660_de(Actor_func_80214624_de *,CVector3,s32,s32,CVector3 *);
struct Node75;
extern s32 Nav_IsPointInTriangleXZ(struct Node75 *,f32,f32);
extern void func_8024E79C_de(Actor_func_80214624_de *,CVector3,CVector3 *,s32 *,s32,s32);
extern void Particle_AddVec3(void *,void *,void *);
extern void Particle_SubtractVectors(void *,void *,void *);
extern void Particle_ScaleVector(CVector3 *,CVector3 *,f32);
static inline void approach(Actor_func_80214624_de *arg0,Actor_func_80214624_de *arg2,Actor_func_80214624_de *temp_a2,CVector3 *posp,s32 *roomp) {
 CVector3 delta,offset; f32 temp_f20;
        if (temp_a2 != 0) {
            Particle_SubtractVectors(&delta, &arg2->pos, &temp_a2->pos);
            delta.y = 0;
            Particle_NormalizeVec3(&delta);
        } else {
            delta.x = 0;
            delta.y = 0;
            delta.z = 0;
        }
        temp_f20 = Particle_GetActorRadius(arg2);
        Particle_ScaleVector(&delta, &delta, temp_f20 + Particle_GetActorRadius(arg0) + D_800C215C_de);
        Particle_AddVec3(&offset, &arg2->pos, &delta);
        func_8024E79C_de(arg2, offset, posp, roomp, 0, 0);
}
#endif
