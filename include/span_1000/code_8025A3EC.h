#ifndef UNBAKE_SPAN_1000_CODE_8025A3EC_H
#define UNBAKE_SPAN_1000_CODE_8025A3EC_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
extern f32 D_800C9068;

extern float D_800D0D10;

struct RecordCode8025A3EC;
typedef struct RecordCode8025A3EC RecordCode8025A3EC;

struct RecordCode8025A3EC;
struct RecordCode8025A3EC {
    s32 index;
    char pad04[4];
    s32 f08;
    s32 f0C;
    char pad10[4];
    s32 f14;
    char pad18[0x14];
    f32 f2C;
    char pad30[4];
    f32 f34;
    s16 f38;
    s16 f3A;
    char pad3C[4];
    s32 f40;
    char pad44[0x14];
    s32 f58;
    s32 f5C;
    char pad60[0x44];
    s32 fA4;
    char padA8[4];
    s32 fAC;
    s32 owner;
    s32 fB4;
    f32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    f32 fC8; /* per-slot volume scale, 0xC8 */
};

/* A pool header followed by its seventeen complete slot records. */
typedef struct PoolCode8025A3EC {
    s32 owner;
    RecordCode8025A3EC slots[17];
} PoolCode8025A3EC;

struct ObjRecAt4V6;
struct ObjRecAt4V6 {
    char pad0[0x4];
    RecordCode8025A3EC unk4;
};

struct RecCode8025A3EC;
struct RecCode8025A3EC {
    char pad0[0x44];
    Triple unk44;
    char pad44[0x50 - 0x44 - sizeof(Triple)];
    int unk50;
};

struct SlotRecAtB0;
typedef struct SlotRecAtB0 SlotRecAtB0;



struct SlotRecAtA8;
struct SlotRecAtA8 {
    char pad0[8];
    s32 used;
    char pad[0x9C];
    s32 value;
    char pad2[0x20];
};

struct HeaderRecAt102;
typedef struct HeaderRecAt102 HeaderRecAt102;

struct SlotRecAtA8;
typedef struct SlotRecAtA8 SlotRecAtA8;

struct HeaderRecAt102;
struct HeaderRecAt102 {
    char pad[0x102];
    s16 local;
};

struct RecordRecAt4V3;
struct RecordRecAt4V3 {
    HeaderRecAt102 *header;
    SlotRecAtA8 slots[17];
};

struct func_8025C4D4_S1;
typedef struct func_8025C4D4_S1 func_8025C4D4_S1;

struct ObjRecAt4V6;
typedef struct ObjRecAt4V6 ObjRecAt4V6;

struct OwnerCode8025A3EC8025B5F0;
typedef struct OwnerCode8025A3EC8025B5F0 OwnerCode8025A3EC8025B5F0;

struct RecCode8025A3EC;
typedef struct RecCode8025A3EC RecCode8025A3EC;

extern f32 func_8025C1CC_de(f32 arg0);

struct OwnerCode8025A3EC8025B5F0;
struct OwnerCode8025A3EC8025B5F0 {
    char pad[0x84];
    char sound[0x58];
    s16 samples[20];
    char pad2[(0x104 - 0xDC) - 40];
    s32 key;
};

struct OwnerCode8025A3EC8025B5F0;
struct SlotRecAtB0;
struct SlotRecAtB0 {
    s32 index;
    s32 state;
    s32 used;
    char pad0[4];
    s32 key;
    char pad1[0x3C];
    s32 flag;
    char pad2[0x54];
    s32 value;
    s32 active;
    struct OwnerCode8025A3EC8025B5F0 *owner;
    char pad3[0x18];
};

extern int D_800CBB00;

struct IntegerStateB4;
struct IntegerStateB4 {
    s32 unk_0;
    s32 unk_4;
    unsigned char padding_8[8];
    s32 unk_10;
    unsigned char padding_14[60];
    s32 unk_50;
    unsigned char padding_54[88];
    s32 unk_AC;
    s32 unk_B0;
};

struct SlotRecAtB8;
struct SlotRecAtB8 {
    char pad0[0xA8];
    s32 flags;
    char padaC[8];
    char *owner;
    char end[0x14];
};

struct SlotRecAtB4V1;
typedef struct SlotRecAtB4V1 SlotRecAtB4V1;

struct func_8025C458_S1;
struct func_8025C458_S1 {
    char unk0;
    char pad0[0xB0 - 0x0 - sizeof(char)];
    s32 unkB0;
    char padB0[0xC8 - 0xB0 - sizeof(s32)];
    f32 unkC8;
};

struct SlotCode8025A3EC;
struct SlotCode8025A3EC {
    int id;
    char pad4[0x9C];
    int keyA;
    char padA4[8];
    int keyB;
    char padB0[0x1C];
};

struct SlotCode8025A3EC;
typedef struct SlotCode8025A3EC SlotCode8025A3EC;

struct ObjRecAtCV4;
struct ObjRecAtCV4 {
    HeaderRecAt102 *owner;
    char pad4[8];
    SlotCode8025A3EC slots[16];
};

extern f32 func_8025C2EC_de(u8 arg0, u8 arg1);

extern float D_800C9044;

struct RecordRecAt4V3;
typedef struct RecordRecAt4V3 RecordRecAt4V3;

extern void func_8025C438_de(void *arg0, s32 arg1);

extern void func_8025C4B4_de(void *arg0, f32 arg1);

struct func_8025AA4C_S2;
typedef struct func_8025AA4C_S2 func_8025AA4C_S2;

struct Slots;
struct Slots {
    char pad0[0x60];
    s16 ids[16];
};

struct func_8025B718_S1;
struct func_8025B718_S1 {
    int unk0;
    char pad0[0x8 - 0x0 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x14 - 0xC - sizeof(int)];
    int unk14;
    char pad14[0x2C - 0x14 - sizeof(int)];
    float unk2C;
    char pad2C[0x34 - 0x2C - sizeof(float)];
    float unk34;
    char pad34[0x38 - 0x34 - sizeof(float)];
    short unk38;
    char pad38[0x3A - 0x38 - sizeof(short)];
    short unk3A;
    char pad3A[0x40 - 0x3A - sizeof(short)];
    int unk40;
    char pad40[0x58 - 0x40 - sizeof(int)];
    int unk58;
    char pad58[0x5C - 0x58 - sizeof(int)];
    int unk5C;
    char pad5C[0xA4 - 0x5C - sizeof(int)];
    int unkA4;
    char padA4[0xAC - 0xA4 - sizeof(int)];
    int unkAC;
    char padAC[0xB0 - 0xAC - sizeof(int)];
    int unkB0;
    char padB0[0xB4 - 0xB0 - sizeof(int)];
    int unkB4;
    char padB4[0xB8 - 0xB4 - sizeof(int)];
    float unkB8;
    char padB8[0xBC - 0xB8 - sizeof(float)];
    int unkBC;
    char padBC[0xC0 - 0xBC - sizeof(int)];
    int unkC0;
    char padC0[0xC4 - 0xC0 - sizeof(int)];
    int unkC4;
};

struct SlotRecAtB4V1;
struct SlotRecAtB4V1 {
    s32 index;
    s32 state;
    s32 used;
    char pad0[4];
    s32 key;
    char pad1[0x3C];
    s32 flag;
    char pad2[0x54];
    s32 other;
    s32 active;
    OwnerCode8025A3EC8025B5F0 *owner;
    s32 value;
    char pad3[0x14];
};

extern float D_800C3F68_de;

struct Slots;
typedef struct Slots Slots;

struct ContextCode8025A3EC;
struct ContextCode8025A3EC {
    char pad0[0x7C];
    Slots slots;
    char padFC[0x104 - 0xFC];
    s32 frame;
    char pad108[0x134 - 0x108];
    s32 track;
    char pad138[0x2B98 - 0x138];
    s32 result;
};

struct ContextCode8025A3EC;
struct View_func_8025AE1C_de;
typedef struct SoundEnvelope {
    u16 flags;
    u16 initial;
    u16 target;
    s16 frames;
    u32 reserved8;
} __attribute__((packed)) SoundEnvelope;

struct View_func_8025AE1C_de {
    s32 slot;
    s32 handle;
    s32 field8;
    s32 fieldC;
    s32 frame;
    char pad14[4];
    s32 finished;
    u8 pad1C[0xC];
    s16 priority; /* 0x28 */
    u8 pad2A[2];
    f32 time;
    char pad30[0x38 - 0x30];
    s16 field38;
    s16 field3A;
    char pad3C[0x44 - 0x3C];
    Triple position;
    Triple *tracked;
    u8 pad54[0x88 - 0x54];
    s32 sweeping; /* 0x88 */
    SoundEnvelope envelope; /* 0x8C */
    f32 value; /* 0x98 */
    f32 step; /* 0x9C */
    s32 hold;
    s32 flags;
    s32 trackId;
    s32 done;
    struct ContextCode8025A3EC *context;
    s32 fieldB4;
    char padB8[4];
    s32 followTrack;
    s32 fixed; /* 0xC0 */
};

struct func_8025C388_S1;
typedef struct func_8025C388_S1 func_8025C388_S1;

extern float D_800C3F80_de;

struct SlotRecAtB4V2;
struct SlotRecAtB4V2 {
    s32 index;
    s32 state;
    s32 used;
    s32 fieldC;
    s32 key;
    char pad14[0x24];
    s16 priority;
    s16 channel;
    char pad3C[0x14];
    s32 flag;
    char pad2[0x50];
    s32 mask;
    s32 value;
    s32 active;
    OwnerCode8025A3EC8025B5F0 *owner;
    s32 fieldB4;
    char padB8[0x14];
};

extern float D_800C3F88_de;

struct func_8025C458_S1;
typedef struct func_8025C458_S1 func_8025C458_S1;

struct SlotRecAtB4V2;
typedef struct SlotRecAtB4V2 SlotRecAtB4V2;

struct RecordRecAt4V4;
struct RecordRecAt4V4 {
    HeaderRecAt102 *header;
    SlotRecAtB4V2 slots[17];
};

extern s16 func_8025C25C_de(s16 arg0, s16 arg1);

struct SlotRecAtB8;
typedef struct SlotRecAtB8 SlotRecAtB8;

extern void func_8025B8BC_de(SlotRecAtB8 *base, s16 index);

struct func_8025BB9C_S1;
typedef struct func_8025BB9C_S1 func_8025BB9C_S1;

extern void func_8025BD00_de(void **arg0);

extern s32 func_8025B854_de(s32 arg0, s16 arg1);



extern void func_8025BB3C_de(s32 a);

struct RecordRecAt4V5;
typedef struct RecordRecAt4V5 RecordRecAt4V5;

struct func_8025BB9C_S1;
struct func_8025BB9C_S1 {
    char pad0[0xA8];
    int unkA8;
};

struct HeaderRecAt102;
struct RecordRecAt4V6;
struct RecordRecAt4V6 {
    struct HeaderRecAt102 *header;
    SlotRecAtB0 slots[17];
};

struct RecordRecAt4V5;
struct RecordRecAt4V5 {
    HeaderRecAt102 *header;
    SlotRecAtB4V1 slots[17];
};

extern float D_800C3F50_de;

struct func_8025AA4C_S1;
typedef struct func_8025AA4C_S1 func_8025AA4C_S1;

struct func_8025AA4C_S2;
struct func_8025AA4C_S2 {
    char pad0[0x128];
    f32 unk128;
    char pad128[0x12C - 0x128 - sizeof(f32)];
    f32 unk12C;
    char pad12C[0x130 - 0x12C - sizeof(f32)];
    f32 unk130;
};

struct RecordRecAt4V4;
typedef struct RecordRecAt4V4 RecordRecAt4V4;

extern float D_800CB8E8;

struct func_8025AA4C_S1;
struct func_8025AA4C_S1 {
    char pad0[0x2B98];
    char * unk2B98;
};

struct Emitter;
struct Emitter {
    char pad0[0x34];
    f32 level;
    char pad38[0xC];
    f32 x;
    f32 y;
    f32 z;
    char pad50[8];
    f32 distance;
    f32 lastDistance;
    char pad60[0x48];
    s32 id;
    char padAC[4];
    void *scene;
    char padB4[0xC];
    s32 reset;
};

extern float D_800C3F84_de;

struct func_8025B718_S1;
typedef struct func_8025B718_S1 func_8025B718_S1;

struct RecordRecAt4V6;
typedef struct RecordRecAt4V6 RecordRecAt4V6;

struct func_8025C4D4_S1;
struct func_8025C4D4_S1 {
    char unk0;
    char pad0[0x34 - 0x0 - sizeof(char)];
    f32 unk34;
    char pad34[0xB0 - 0x34 - sizeof(f32)];
    s32 unkB0;
    char padB0[0xB8 - 0xB0 - sizeof(s32)];
    f32 unkB8;
};

struct IntegerStateB4;
typedef struct IntegerStateB4 IntegerStateB4;

struct ContextCode8025A3EC;
typedef struct ContextCode8025A3EC ContextCode8025A3EC;

struct View_func_8025AE1C_de;
typedef struct View_func_8025AE1C_de View_func_8025AE1C_de;

extern float D_800C9048;

struct Emitter;
typedef struct Emitter Emitter;

struct func_8025C388_S1;
struct func_8025C388_S1 {
    char pad0[0x34];
    Vec3 unk34;
    char pad34[0x44 - 0x34 - sizeof(Vec3)];
    s8 unk44;
};

struct ObjRecAtCV4;
typedef struct ObjRecAtCV4 ObjRecAtCV4;

/* Position and attenuation curve of a spatial sound source. */
typedef struct SoundSpatialSource {
    u8 reserved0[0x34];
    Vec3 position;
    u8 reserved40[4];
    s8 curve;
} SoundSpatialSource;

#endif
