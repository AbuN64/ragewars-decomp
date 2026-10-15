#ifndef UNBAKE_SPAN_1000_CODE_802646F4_H
#define UNBAKE_SPAN_1000_CODE_802646F4_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct ActorRecAt5E0;
struct ActorRecAt5E0 {
    char pad0[8];
    Triple position;
    s32 id;
    char pad18[0x6C - 0x18];
    f32 field6C;
    char pad70[0x5E0 - 0x70];
    Block70 block;
    char pad650[0x16E8 - 0x650];
};

struct ActorList;
struct ActorRecAt5E0;
struct ActorList {
    s32 pad0;
    struct ActorRecAt5E0 *actors;
    s32 count;
};

struct Snapshot;
struct Snapshot {
    s32 pad0;
    s32 mode;
    char pad8[0x8];
    Block70 blocks[8];
    Triple positions[8];
    f32 values[8];
    s32 handles[8];
};

struct SampledCurve;
struct SampledCurve {
    int type;
    unsigned char samples[0x10];
    float length;
};

struct SampledCurve;
/* Type 1 curves choose a new random value each period. */
typedef struct RandomCurve {
    s32 type;
    f32 period;
    u8 minimum;
    u8 maximum;
} RandomCurve;

struct PlayerRecAt8;
struct PlayerRecAt8 {
    struct SampledCurve *curve;
    float time;
    float value;
};

extern void func_80264B7C_de();

struct func_80264A40_S1;
typedef struct func_80264A40_S1 func_80264A40_S1;

struct PlayerRecAt8;
typedef struct PlayerRecAt8 PlayerRecAt8;

struct Snapshot;
typedef struct Snapshot Snapshot;

struct Snapshot;

extern void func_80264CE0_de();

struct Snapshot;

extern s32 func_802646D4_de(s32 arg0);

struct func_80264E10_S1;
typedef struct func_80264E10_S1 func_80264E10_S1;

extern void func_80264B8C_de();

struct func_80264E10_S2;
struct func_80264E10_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    u8 unk8;
    char pad8[0x9 - 0x8 - sizeof(u8)];
    u8 unk9;
    char pad9[0x14 - 0x9 - sizeof(u8)];
    f32 unk14;
};

extern void func_80264CB8_de();

struct ActorRecAt5E0;
typedef struct ActorRecAt5E0 ActorRecAt5E0;

extern void func_802649FC_de();

extern void func_8026479C_de();

struct func_80264E10_S2;
typedef struct func_80264E10_S2 func_80264E10_S2;

extern void func_80264A20_de(void);

struct ActorList;
typedef struct ActorList ActorList;

extern void func_8026480C_de();

extern void func_80264B44_de();

struct func_80264A40_S1;
struct func_80264A40_S1 {
    char pad0[0x5EC];
    s32 unk5EC;
    char pad5EC[0x650 - 0x5EC - sizeof(s32)];
    u16 unk650;
};

extern void func_8026495C_de();

struct func_80264E10_S1;
struct func_80264E10_S1 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
};

extern s32 func_80264DF0_de(void *arg0);

struct SampledCurve;
typedef struct SampledCurve SampledCurve;

extern void func_80264A0C_de();

#endif
