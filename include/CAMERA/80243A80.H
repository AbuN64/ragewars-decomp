#ifndef CAMERA_80243A80_H
#define CAMERA_80243A80_H
#include "COMMON/GROUP.H"
#include "COMMON/LEGACY_COLLISION_ACTOR.H"
#include "COMMON/MOTION_STEP.H"
#include "COMMON/SHAREDPLAYER.H"
struct CollisionState {
    s32 active0;
    u8 pad[0x98];
    s32 active9c;
};
struct CollisionInfoCode80243A80 {
    s32 flags;
    u8 ground_behavior;
    u8 instance_behavior;
    u8 pad[2];
    s32 w[5];
};
struct Access_s32_C4 {
    char pad[0xC4];
    s32 field;
};
struct Access_s32_D0 {
    char pad[0xD0];
    s32 field;
};
struct Group {
    void *lead;
    char pad4[0x24];
    char members[1];
};
struct VectorPair {
    CVector3 first;
    CVector3 second;
    char pad[8];
};
struct Work80244494 {
    char data[0x1B8];
};
struct Shared_Func80243A80Global {
    u8 pad[216]; /* +0x0: src/func_80243A80.c */
    s32 x; /* +0xD8: src/func_80243A80.c */
    f32 y; /* +0xDC: src/func_80243A80.c */
    s32 z; /* +0xE0: src/func_80243A80.c */
};
struct Shared_Func80243A80Bits {
    union {
        struct {
            f32 f; /* +0x0: src/func_80243A80.c */
        } view0_0;
        struct {
            s32 i; /* +0x0: src/func_80243A80.c */
        } view0_1;
    } views0;
};
struct Access_s8_E6 {
    char pad[0xE6];
    s8 field;
};
struct Range;
extern s32 func_8023D158_de(ActorMotion *object);
extern void func_8023E690_de(struct Range *range, f32 low, f32 mid, f32 high, f32 extra);
extern s32 Camera_MoveActorWithCollision(Func80243A80Actor *actor, CVector3 position, u32 *flags);
extern s32 func_802446E0_de(char *arg0, CVector3 arg1, CVector3 arg2, struct MotionSurface *arg3, f32 arg4);
#endif
