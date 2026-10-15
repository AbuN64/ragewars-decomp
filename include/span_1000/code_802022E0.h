#ifndef UNBAKE_SPAN_1000_CODE_802022E0_H
#define UNBAKE_SPAN_1000_CODE_802022E0_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
struct Obj;
typedef struct Obj Obj;

struct func_80203908_S3;
struct func_80203908_S3 {
    char pad0[0x37];
    s8 unk37;
    char pad37[0x64 - 0x37 - sizeof(s8)];
    f32 unk64;
    char pad64[0x124 - 0x64 - sizeof(f32)];
    func_80203908_S3_U124 unk124;
    char pad124[0x128 - 0x124 - sizeof(func_80203908_S3_U124)];
    s32 unk128;
};

struct RecordRecAt13C;
struct RecordRecAt13C {
    char pad0[0x2C];
    void *table;
    char pad30[7];
    s8 state; /* 0x37 */
    char pad38[0x64 - 0x38];
    f32 threshold; /* 0x64 */
    char pad68[0x108 - 0x68];
    void *first;
    s32 pad10C;
    void *second;
    char pad114[0x11C - 0x114];
    void *third;
    void *fourth;
    f32 speed;
    s32 pad128;
    s32 rate;
    s32 a;
    f32 range;
    s32 b;
    s32 c;
};

extern float D_800C6B2C;

extern float D_800C1A04_de;

struct SegmentRecAt71;
typedef struct SegmentRecAt71 SegmentRecAt71;




extern float D_800C1A00_de;

struct func_80203DF0_S4;
typedef struct func_80203DF0_S4 func_80203DF0_S4;

struct Result;
typedef struct Result Result;

struct func_80203DF0_S4;
struct func_80203DF0_S4 {
    char pad0[0x6C];
    f32 unk6C;
    char pad6C[0x20C - 0x6C - sizeof(f32)];
    f32 unk20C;
};

struct func_80203908_S3;
typedef struct func_80203908_S3 func_80203908_S3;




extern float D_800C19FC_de;

struct Actor;
typedef struct Actor Actor;

struct Hook;
struct Obj;
struct Obj {
    char pad0[0x30];
    struct Hook *hook;
    char pad34[0x12C - 0x34];
    int count;
    char pad130[0x13C - 0x130];
    float timer;
};

struct RiderRecAt130V1;
typedef struct RiderRecAt130V1 RiderRecAt130V1;

struct Actor;
struct Actor {
    char pad[0x1D8];
    struct Actor *linked;
    char pad1DC[0x5D8 - 0x1DC];
    Record *info;
    char pad5DC[0x5E4 - 0x5DC];
    int active;
};

extern void func_80203DF0_de(void *arg0, ObjRecAt8V1 *event);

struct Segment;
struct Segment {
    char pad0[0x5C];
    f32 rise;
    f32 radius;
    f32 angle;
    f32 length;
};

struct Result;
struct Result {
    char pad0[4];
    SharedPlayer *target;
    char pad8[0x38];
    f32 distance;
};

struct SegmentRecAt71;
struct SegmentRecAt71 {
    char pad0[0x3C];
    s32 yawEvent; /* 0x3C: rotation event selector */
    s32 orientationMode;
    f32 rate;
    f32 limit;
    f32 distanceLimit;
    s32 pad50;
    f32 range;
    f32 tolerance;
    char pad5C[0x70-0x5C];
    u8 activeMode;
    u8 inactiveMode;
};

struct NavigationTrack {
    u8 prefix[4];
    u32 flags; /* 0x4 */
    u8 pad8[0xC];
    SegmentRecAt71 segment;
};

extern int func_80203A94_de(void *arg0);

extern float D_800C1A48_de;

extern f32 D_80115DEC;

struct ObjRecAt294;
struct ObjRecAt294 {
    char pad0[0x18];
    char * unk18;
    char pad18[0x6C - 0x18 - sizeof(char*)];
    f32 heading; /* 0x6C */
    char pad70[0x20C - 0x70];
    f32 targetHeading; /* 0x20C */
    char pad210[0x294 - 0x210];
    f32 unk294;
};

extern float D_800C1A0C;

struct Segment;
typedef struct Segment Segment;

struct OwnerRecAtE4;
struct RecordRecAt13C;
extern void func_8020388C_de(struct OwnerRecAtE4 *owner, struct RecordRecAt13C *record);

struct ObjRecAt294;
typedef struct ObjRecAt294 ObjRecAt294;

struct Rider;
typedef struct Rider Rider;

extern void func_802022E0_de();
extern void func_8020238C_de(void);
extern void func_802023A8_de(void);
extern int func_802023C4_de();
extern void func_802023D0_de(int arg0);

void func_80216D3C_de(Input80216D3C *arg0, void *arg1, Output80216D3C *arg2, s32 arg3, s32 arg4);
void func_80216808_de(void *arg0, s32 arg1, f32 arg2, f32 arg3);
typedef union NavActor { SharedPlayer player; Input80216D3C input; Actor_func_80214624_de actor; struct Owner owner; } NavActor;
typedef struct NavVec { Vec3 v; f32 fourth; } NavVec;


/* Shared object layout established by rotation consumers. */
struct RotationObject {
    u8 padding000[0x130];
    f32 angleX; /* 0x130 */
    f32 angleY; /* 0x134 */
    f32 angleZ; /* 0x138 */
};


/* Shared object layout established by weapon-events consumers. */
struct WeaponEventSource {
    u8 padding000[0xCB];
    char eventEnabled; /* 0xCB */
};

#endif
