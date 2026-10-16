#ifndef UNBAKE_SPAN_1000_CODE_802AB3FC_H
#define UNBAKE_SPAN_1000_CODE_802AB3FC_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
struct LocalizedEffectContext;
typedef struct LocalizedEffectContext LocalizedEffectContext;

struct EntryRecAtE;
typedef struct EntryRecAtE EntryRecAtE;

extern void func_802AB1B0_de(u16 *grid, f32 x0, f32 y, f32 sx, f32 sy);

struct Other;
struct Other {
    char pad0[0x5E4];
    s32 enabled;
    char pad5E8[0x1224 - 0x5E8];
    s32 lockOn[2];
    char pad122C[0x16E0 - 0x122C];
    struct Other *next;
};

struct func_802ADB08_S2;
struct func_802ADB08_S2 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5DC - 0x10 - sizeof(s32)];
    void * unk5DC;
};

struct func_802ADA44_S1;
struct func_802ADA44_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x19C - 0x14 - sizeof(s32)];
    u16 unk19C;
    char pad19C[0x1D0 - 0x19C - sizeof(u16)];
    s32 unk1D0;
};



extern s32 func_802AD1B4_de(void *arg0);



struct Actor_func_802AB400_de;
struct Actor_func_802AB400_de {
    u8 type;
    u8 pad1[7];
    Vec3 position; /* 0x08: provider func_8025DE54_de takes Vec3 */
    u8 pad14[0xE4 - 0x14];
    u16 team;
    char padE6[0x100 - 0xE6];
    s32 flags;
    u8 pad104[0x174 - 0x104];
    s32 active; /* 0x174 */
    u8 pad178[0x5D8 - 0x178];
    ObjRecAt8F *model;
    void *owner; /* 0x5DC */
    u8 pad5E0[4];
    s32 count;
    u16 fraction; /* 0x5E8 */
    s16 lives; /* 0x5EA */
    u8 pad5EC[8];
    s16 levels[7];
    char pad602[0x602 - 0x602];
    Shared_Slot slots[22];
};

struct func_802ADBF4_S1;
struct func_802ADBF4_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x174 - 0x10 - sizeof(s32)];
    s32 unk174;
    char pad174[0x5DC - 0x174 - sizeof(s32)];
    void * unk5DC;
    char pad5DC[0x5E4 - 0x5DC - sizeof(void*)];
    s32 unk5E4;
};

struct func_802ADBF4_S2;
struct func_802ADBF4_S2 {
    char pad0[0x6];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s32 unkC;
};

struct Other;
typedef struct Other Other;

struct LocalizedEffectContext;
struct LocalizedEffectContext {
    u8 reserved[0x17C1];
    u8 language;
};

union func_802ADD18_S1_U5E8;
union func_802ADD18_S1_U5E8 {
    u16 v0;
    s16 v1;
};

extern void func_802AB35C_de(int unused, unsigned char *pairs, int count, unsigned char *table);

struct func_802AE1A4_S1;
struct func_802AE1A4_S1 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x16D4 - 0x5DC - sizeof(void*)];
    s32 unk16D4;
};

struct func_802ADD18_S1;
typedef struct func_802ADD18_S1 func_802ADD18_S1;

struct func_802ADBF4_S2;
typedef struct func_802ADBF4_S2 func_802ADBF4_S2;

struct func_802ADFA0_S1;
struct func_802ADFA0_S1 {
    char pad0[0x6];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s16 unkC;
    char padC[0xE - 0xC - sizeof(s16)];
    s16 unkE;
    char padE[0x10 - 0xE - sizeof(s16)];
    s16 unk10;
};

union func_802ADD18_S1_U5E8;
typedef union func_802ADD18_S1_U5E8 func_802ADD18_S1_U5E8;

struct func_802ADD18_S1;
struct func_802ADD18_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5DC - 0x10 - sizeof(s32)];
    void * unk5DC;
    char pad5DC[0x5E8 - 0x5DC - sizeof(void*)];
    func_802ADD18_S1_U5E8 unk5E8;
    char pad5E8[0x5EA - 0x5E8 - sizeof(func_802ADD18_S1_U5E8)];
    func_8022FD9C_S2_U770 unk5EA;
};

struct func_802ADFA0_S1;
typedef struct func_802ADFA0_S1 func_802ADFA0_S1;

struct func_802AE1A4_S2;
typedef struct func_802AE1A4_S2 func_802AE1A4_S2;



extern void func_802AB3A8_de(void);

struct func_802ADBF4_S1;
typedef struct func_802ADBF4_S1 func_802ADBF4_S1;

extern void func_802AB0B0_de(u16 *grid, s16 x0, s32 y);

struct EntryRecAtE;
struct EntryRecAtE {
    void *resource;
    s16 id;
    s16 sound;
    s16 callback;
    s16 reservedA;
    s16 index;
    s16 argument;
};

struct func_802ADD18_S2;
typedef struct func_802ADD18_S2 func_802ADD18_S2;

struct func_802ADA44_S1;
typedef struct func_802ADA44_S1 func_802ADA44_S1;

struct func_802ADB08_S1;
struct func_802ADB08_S1 {
    char pad0[0x6];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s16 unkC;
    char padC[0xE - 0xC - sizeof(s16)];
    s16 unkE;
};

struct Actor_func_802AB400_de;
typedef struct Actor_func_802AB400_de Actor_func_802AB400_de;

struct func_802ADD18_S2;
struct func_802ADD18_S2 {
    char pad0[0x6];
    s16 unk6;
    char pad6[0x8 - 0x6 - sizeof(s16)];
    s16 unk8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    u16 unkC;
};

struct func_802ADB08_S2;
typedef struct func_802ADB08_S2 func_802ADB08_S2;

struct func_802ADB08_S1;
typedef struct func_802ADB08_S1 func_802ADB08_S1;

struct func_802AE1A4_S1;
typedef struct func_802AE1A4_S1 func_802AE1A4_S1;

struct func_802AE1A4_S2;
struct func_802AE1A4_S2 {
    char pad0[0x124];
    s16 unk124;
};

extern void func_802AADCC_de(u16 *grid, s16 x0, s32 y);

extern float D_800C62E0;

/* The five 0x14-byte ammunition definitions searched at D_800D3230. */
typedef struct AmmoPickupDefinition {
    u8 reserved0[4];
    s16 kind;
    u8 reserved6[6];
    s16 slot;
    u8 reservedE[6];
} AmmoPickupDefinition;


/* Timed pickup family: common effect payload followed by a word amount. */
typedef struct TimedItemEffect {
    void *resource;
    s16 id;
    s16 sound;
    s16 callback;
    s16 reservedA;
    s32 amount;
} TimedItemEffect;

/* Three-channel pickups extend the common two-argument effect record. */
typedef struct MultiChannelItemEffect {
    EntryRecAtE effect;
    s16 third;
} MultiChannelItemEffect;

extern f32 D_800C6260;
extern f32 D_800CB3F8;
extern f32 D_800C6270_de;
extern f32 D_800C6274_de;
extern f32 D_800C627C_de;
extern f32 D_800CB414;
extern f32 D_800C6288_de;
extern f32 D_800C628C_de;
extern f32 D_800C6290_de;
extern f32 D_800C6294_de;
extern f32 D_800C6298;
extern f32 D_800C629C;
extern f32 D_800C62A4;
extern f32 D_800C62AC;

#endif
