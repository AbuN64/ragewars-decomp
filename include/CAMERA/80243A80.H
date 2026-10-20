#ifndef CAMERA_80243A80_H
#define CAMERA_80243A80_H
#include "COMMON/GROUP.H"
#include "COMMON/LEGACY_COLLISION_ACTOR.H"
#include "COMMON/MOTION_STEP.H"
struct Range;
extern s32 func_8023D158_de(ActorMotion *object);
extern void func_8023E690_de(struct Range *range, f32 low, f32 mid, f32 high, f32 extra);
extern s32 func_80243A90_de(Func80243A80Actor *actor, CVector3 position, u32 *flags);
extern s32 func_802446E0_de(char *arg0, CVector3 arg1, CVector3 arg2, struct MotionSurface *arg3, f32 arg4);
#endif
