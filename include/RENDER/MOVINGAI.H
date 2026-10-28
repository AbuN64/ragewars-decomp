#ifndef RENDER_MOVINGAI_H
#define RENDER_MOVINGAI_H
#include "COMMON/REC.H"
#include "COMMON/SHAREDPLAYER.H"
struct RiderCode80206258 {
    char pad0[0x35];
    s8 animation;
    char pad36;
    s8 state;
    char pad38[4];
    s32 flags;
    char pad40[4];
    f32 timer;
    char pad48[0xC];
    CVector3 pos;
    char pad60[4];
    f32 throttle;
    char pad68[0x34];
    f32 baseYaw;
    CVector3 base;
    char padAC[0x78];
    f32 triggerTime;
    CVector3 shake;
    char pad134[8];
    f32 phase;
};
struct func_802070D0_S1 {
    char pad0[0x54];
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    char pad5C[0x34];
    u8 unk94;
    char pad94[0x9F];
    f32 unk134;
    f32 unk138;
    char pad138[0x4];
    f32 unk140;
    f32 unk144;
    f32 unk148;
    f32 unk14C;
    f32 unk150;
    f32 unk154;
    f32 unk158;
    f32 unk15C;
    f32 unk160;
    f32 unk164;
    f32 unk168;
    f32 unk16C;
};
struct Rec {
    char pad0[0xC];
    void *a;
    void *b;
};
struct func_802070D0_S3 {
    char pad0[0x8];
    func_802070D0_S3_U8 unk8;
    f32 unkC;
    f32 unk10;
    char pad10[0x24];
    s32 unk38;
    char pad38[0x30];
    f32 unk6C;
};
struct func_802070D0_S2 {
    Triple pos;
    char pad8[0x4];
    f32 unk10;
    WaypointFlags unk14;
    char pad14[0x4];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
};
struct TrackCode80206258 {
    char prefix[0x14];
    struct CPlatformIntelligence segment;
};
struct func_80206604_G1 {
    u8 unk0;
};
struct Actor_func_80206DD4_de {
    char pad0[8];
    f32 x;
    f32 y;
    f32 z;
    s32 model;
    union { char *track; struct TrackCode80206258 *motionTrack; };
    char pad1C[0x1C];
    u32 inputFlags;
    char pad3C[0x30];
    f32 yaw;
    char pad70[0x90];
    u32 flags;
};
extern int func_80206758_de(void *arg0, struct Dest *arg1);
extern void func_802062B0_de(struct Trigger *arg0);
extern void func_80206604_de(struct LevelActor *arg0, struct ActorMotionState *arg1);
extern void func_80206764_de(void);
extern s32 func_8020655C_de(s32 arg0);
extern void func_80206258_de(struct Trigger *arg0);
extern void func_802065C0_de(void *a, struct ActorMotionState *b, s32 c);
#endif
