#ifndef COMMON_REC_H
#define COMMON_REC_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
struct RecCode80206258;
struct RecCode80206258 {
    char pad0[0x124];
    char unk124;
    char pad124[0x128 - 0x124 - sizeof(char)];
    s32 unk128;
};

struct RecCode80206258802063EC;
struct RecCode80206258802063EC {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x6C - 0x1C - sizeof(Triple)];
    f32 unk6C;
};

struct func_80206930_S2;
typedef struct func_80206930_S2 func_80206930_S2;

struct func_8020655C_S1;
typedef struct func_8020655C_S1 func_8020655C_S1;

struct func_802066A4_S1;
struct func_802066A4_S1 {
    char pad0[0x124];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    f32 unk128;
    char pad128[0x12C - 0x128 - sizeof(f32)];
    f32 unk12C;
};

union func_802070D0_S3_U8;
union func_802070D0_S3_U8 {
    u8 v0;
    f32 v1;
};

struct Dest;

struct Trigger;

struct RiderCode80206258;

struct func_802065C0_S1;
struct func_802065C0_S1 {
    char pad0[0x35];
    s8 unk35;
    char pad35[0xCB - 0x35 - sizeof(s8)];
    s8 unkCB;
    char padCB[0x124 - 0xCB - sizeof(s8)];
    s32 unk124;
};


struct func_802065C0_S1;
typedef struct func_802065C0_S1 func_802065C0_S1;

struct Rec;
typedef struct Rec Rec;

struct func_80206604_S1;
struct func_80206604_S1 {
    char pad0[0x2C];
    s32 * unk2C;
    char pad2C[0x108 - 0x2C - sizeof(s32*)];
    s32 * unk108;
    char pad108[0x10C - 0x108 - sizeof(s32*)];
    s32 * unk10C;
};

struct func_802070D0_S3;
typedef struct func_802070D0_S3 func_802070D0_S3;

struct func_802062E0_S3;
struct func_802062E0_S3 {
    char pad0[0x1A0];
    s32 unk1A0;
};

extern float D_800C1AE0_de;

struct func_802077F4_S3;
typedef struct func_802077F4_S3 func_802077F4_S3;

struct ActorMotionState;
struct LevelActor;

struct func_802070D0_S1;

struct RecCode80206258802064A0;
struct RecCode80206258802064A0 {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    CQuatern unk5C;
};

struct Rec;

struct func_80207910_S1;
struct func_80207910_S1 {
    char pad0[0x134];
    f32 unk134;
    char pad134[0x138 - 0x134 - sizeof(f32)];
    f32 unk138;
};



struct func_80206930_S2;
struct func_80206930_S2 {
    char pad0[0xE];
    unsigned char unkE;
    char padE[0x10 - 0xE - sizeof(unsigned char)];
    unsigned char unk10;
};

struct Settings;
typedef struct Settings Settings;

union func_802070D0_S3_U8;
typedef union func_802070D0_S3_U8 func_802070D0_S3_U8;

struct func_802070D0_S3;

struct func_80206604_S1;
typedef struct func_80206604_S1 func_80206604_S1;

struct func_8020655C_S1;
struct func_8020655C_S1 {
    char pad0[0x18];
    s32 * unk18;
    char pad18[0x2EC - 0x18 - sizeof(s32*)];
    void * unk2EC;
};


struct RecCode80206258;
typedef struct RecCode80206258 RecCode80206258;

struct Actor_func_80206DD4_de;
typedef struct Actor_func_80206DD4_de Actor_func_80206DD4_de;

struct RecCode80206258802064A0;
typedef struct RecCode80206258802064A0 RecCode80206258802064A0;

struct func_80206604_G1;
typedef struct func_80206604_G1 func_80206604_G1;

struct func_802066A4_S1;
typedef struct func_802066A4_S1 func_802066A4_S1;

struct func_802062E0_S3;
typedef struct func_802062E0_S3 func_802062E0_S3;

struct func_8020694C_S1;
typedef struct func_8020694C_S1 func_8020694C_S1;

struct func_80207890_S1;
struct func_80207890_S1 {
    char pad0[0x37];
    s8 unk37;
    char pad37[0x94 - 0x37 - sizeof(s8)];
    s8 unk94;
    char pad94[0x96 - 0x94 - sizeof(s8)];
    u16 unk96;
    char pad96[0x98 - 0x96 - sizeof(u16)];
    u16 unk98;
};

struct func_80207910_S2;
typedef struct func_80207910_S2 func_80207910_S2;

union WaypointFlags;
union WaypointFlags {
    u16 half;
    s32 word;
};

struct func_80206758_S1;
typedef struct func_80206758_S1 func_80206758_S1;

struct func_802070D0_S2;
typedef struct func_802070D0_S2 func_802070D0_S2;

union WaypointFlags;
typedef union WaypointFlags WaypointFlags;


struct Actor_func_80206DD4_de;


struct func_802070D0_S2;

struct func_80207910_S2;
struct func_80207910_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x50 - 0x10 - sizeof(f32)];
    f32 unk50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
    char pad58[0x6C - 0x58 - sizeof(f32)];
    f32 unk6C;
    char pad6C[0x74 - 0x6C - sizeof(f32)];
    char unk74;
};


struct RiderCode80206258;
typedef struct RiderCode80206258 RiderCode80206258;

struct func_802077F4_S3;
struct func_802077F4_S3 {
    char pad0[0x2C];
    void * unk2C;
    char pad2C[0x64 - 0x2C - sizeof(void*)];
    f32 unk64;
    char pad64[0x108 - 0x64 - sizeof(f32)];
    void * unk108;
    char pad108[0x11C - 0x108 - sizeof(void*)];
    void * unk11C;
    char pad11C[0x124 - 0x11C - sizeof(void*)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
    char pad128[0x12C - 0x128 - sizeof(s32)];
    s32 unk12C;
    char pad12C[0x130 - 0x12C - sizeof(s32)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
    char pad134[0x138 - 0x134 - sizeof(s32)];
    s32 unk138;
    char pad138[0x13C - 0x138 - sizeof(s32)];
    f32 unk13C;
    char pad13C[0x140 - 0x13C - sizeof(f32)];
    s32 unk140;
    char pad140[0x144 - 0x140 - sizeof(s32)];
    s32 unk144;
    char pad144[0x148 - 0x144 - sizeof(s32)];
    s32 unk148;
    char pad148[0x14C - 0x148 - sizeof(s32)];
    s32 unk14C;
    char pad14C[0x168 - 0x14C - sizeof(s32)];
    s32 unk168;
    char pad168[0x16C - 0x168 - sizeof(s32)];
    s32 unk16C;
};

struct func_80207890_S1;
typedef struct func_80207890_S1 func_80207890_S1;


struct SegmentRecAt5C;
struct SegmentRecAt5C {
    char pad0[4];
    u16 moving;
    char pad6[0x1E];
    u32 flags;
    u8 bobMode;
    u8 linear;
    u8 yawMode;
    char pad2B;
    f32 rise;
    f32 radius;
    f32 angle;
    char pad38[4];
    f32 yaw;
    char pad40[4];
    f32 bob;
    char pad48[0xC];
    f32 triggerDelay;
    f32 displacement;
    f32 duration;
};


struct func_80206758_S1;
struct func_80206758_S1 {
    char pad0[0x124];
    int unk124;
};

struct SegmentRecAt5C;
typedef struct SegmentRecAt5C SegmentRecAt5C;

struct RecCode80206258802063EC;
typedef struct RecCode80206258802063EC RecCode80206258802063EC;

struct func_80207910_S1;
typedef struct func_80207910_S1 func_80207910_S1;


struct func_802070D0_S1;
typedef struct func_802070D0_S1 func_802070D0_S1;

struct func_8020694C_S1;
struct func_8020694C_S1 {
    char pad0[0xB4];
    int unkB4;
    char padB4[0x140 - 0xB4 - sizeof(int)];
    Slot unk140;
};

struct func_80206604_G1;


struct InputRecAt37;

typedef struct ActorMotionDefinition {
    s32 flags; /* 0x0 */
    u16 radial; /* 0x4 */
    u8 pad6[2];
    u8 pad8[4];
    s32 eventMask; /* 0xC */
    s32 secondaryEventMask; /* 0x10 */
    u8 pad14[2];
    s16 soundEnabled; /* 0x16 */
    s16 soundIndex; /* 0x18 */
    u8 pad1A[0xA];
    s32 transitionFlags; /* 0x24 */
    u8 pad28[0x4];
    f32 height; /* 0x2C */
    f32 radius; /* 0x30 */
    f32 heading; /* 0x34 */
    f32 transitionTime; /* 0x38 */
    u8 pad3C[0x4];
    f32 speed; /* 0x40 */
    u8 pad44[0x4];
    f32 progressScale; /* 0x48 */
    f32 openThreshold; /* 0x4C */
    f32 closeThreshold; /* 0x50 */
    u8 pad54[0x18];
    f32 eventThreshold; /* 0x6C */
} ActorMotionDefinition;
typedef struct ActorMotionResource {
    s32 kind; /* 0x0 */
    u8 pad4[0x10];
    ActorMotionDefinition motion; /* 0x14 */
} ActorMotionResource;
typedef struct ActorMotionHooks { void *reserved[2]; void (*onStep)(void *, void *); u8 padC[0x10]; s32 flags; } ActorMotionHooks;
typedef struct ActorMotionState {
    s32 flags; /* 0x0 */
    u8 pad4[0x28];
    void * table; /* 0x2C */
    ActorMotionHooks * hooks; /* 0x30 */
    s8 mode; /* 0x34 */
    s8 action; /* 0x35 */
    u8 pad36;
    s8 state; /* 0x37 */
    u8 pad38[0x8];
    f32 timer; /* 0x40 */
    u8 pad44[0x4];
    CVector3 position; /* 0x48 */
    u8 pad54[0xC];
    f32 height; /* 0x60 */
    f32 speed; /* 0x64 */
    struct Player *target; /* 0x68 */
    u8 pad6C[0x28];
    s8 routeMode; /* 0x94 */
    u8 route; /* 0x95 */
    u16 start; /* 0x96 */
    u16 destination; /* 0x98 */
    u8 pad9A[0x6];
    CVector3 base; /* 0xA0 */
    u8 padAC[0x1F];
    s8 actionPending; /* 0xCB */
    u8 padCC[0x3C];
    void * update; /* 0x108 */
    void * secondaryUpdate; /* 0x10C */
    void * event; /* 0x110 */
    u8 pad114[8];
    void * transform; /* 0x11C */
    u8 pad120[0x4];
    s32 unk124; /* 0x124 */
    s32 unk128; /* 0x128 */
    s32 unk12C; /* 0x12C */
    s32 unk130; /* 0x130 */
    f32 yaw; /* 0x134 */
    f32 pitch; /* 0x138 */
    f32 progress; /* 0x13C */
    s32 unk140; /* 0x140 */
    s32 unk144; /* 0x144 */
    s32 unk148; /* 0x148 */
    s32 unk14C; /* 0x14C */
    u8 pad150[0x18];
    s32 unk168; /* 0x168 */
    s32 unk16C; /* 0x16C */
} ActorMotionState;
#endif
