#ifndef COMMON_APPROACHLOCATION_H
#define COMMON_APPROACHLOCATION_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "COMMON/PROBE.H"
#include "FX_2/80271B18.H"

typedef struct { CVector3 pos; s32 unkC; } ApproachLocation;
extern s32 D_8013B290;
extern f32 D_800C2160_de[],D_800C215C_de;
extern f32 func_80216F44_de(Actor_func_80214624_de *,CVector3);
extern f32 func_8024D398_de(Actor_u1 *);
extern f32 func_80271AA8_de(CVector3 *);
struct Cursor;
extern ApproachLocation *func_80219408_de(struct Cursor *);
extern s32 func_80240660_de(Actor_func_80214624_de *,CVector3,s32,s32,CVector3 *);
struct Node75;
extern s32 func_80275B10_de(struct Node75 *,f32,f32);
extern void func_8024E79C_de(Actor_func_80214624_de *,CVector3,CVector3 *,s32 *,s32,s32);
extern void func_80271F34_de(void *,void *,void *);
extern void func_80271F68_de(void *,void *,void *);
extern void func_80271F9C_de(CVector3 *,CVector3 *,f32);
static inline void approach(Actor_func_80214624_de *arg0,Actor_func_80214624_de *arg2,Actor_func_80214624_de *temp_a2,CVector3 *posp,s32 *roomp) {
 CVector3 delta,offset; f32 temp_f20;
        if (temp_a2 != 0) {
            func_80271F68_de(&delta, &arg2->pos, &temp_a2->pos);
            delta.y = 0;
            func_8027207C_de(&delta);
        } else {
            delta.x = 0;
            delta.y = 0;
            delta.z = 0;
        }
        temp_f20 = func_8024D398_de(arg2);
        func_80271F9C_de(&delta, &delta, temp_f20 + func_8024D398_de(arg0) + D_800C215C_de);
        func_80271F34_de(&offset, &arg2->pos, &delta);
        func_8024E79C_de(arg2, offset, posp, roomp, 0, 0);
}
#endif
