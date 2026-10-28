#ifndef GAME_SOUNDINFO_H
#define GAME_SOUNDINFO_H
#include "COMMON/STREAM.H"
#include "TYPES.H"

extern int func_8025E59C_de(void *soundDescriptor);

struct Output8025EF54 {
    f32 value;
    s32 pad04;
    s32 pad08;
    s32 pad0C;
};
struct Segment8025FFD0 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    u32 unkC;
    u8 pad10[0x24 - 0x10];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
};
struct Decode8025EF54 {
    s32 bits;
    f32 base;
    f32 range;
    s32 unused;
    u32 stream;
    s32 first_bits;
    s32 second_bits;
};
struct Poly {
    float a;
    float b;
    float c;
    float d;
    u32 duration;
};
struct Curve {
    s32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u32 unk20;
    s32 unk24;
    s32 unk28;
};
typedef struct AnimTrack {
    /* 0x00 */ char pad0[0x18];
    /* 0x18 */ f32 length;
    /* 0x1C */ f32 rate;
} AnimTrack;
typedef struct AnimRef {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u16 id;
    /* 0x06 */ u16 frame;
    /* 0x08 */ u16 count;
    /* 0x0A */ u8 flags[2];
    /* 0x0C */ u32 span;
    /* 0x10 */ void **data;
} AnimRef;
typedef struct AnimKeyEntry {
    s16 position, rotation;
} AnimKeyEntry;
typedef struct AnimKeyTable {
    s32 reserved0, reserved4;
    AnimKeyEntry entries[1];
} AnimKeyTable;

typedef struct KeyIndex {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ s16 position;
    /* 0x0A */ s16 rotation;
} KeyIndex;
typedef struct PoseTable {
    s32 stride;
    char pad4[4];
    s16 pad8[2];
    s16 value[4];
} PoseTable;
#endif
