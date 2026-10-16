#ifndef UNBAKE_SPAN_1000_CODE_8025E568_H
#define UNBAKE_SPAN_1000_CODE_8025E568_H
#include "TYPES.H"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
struct func_802604BC_S1;
typedef struct func_802604BC_S1 func_802604BC_S1;

struct Output8025EF54;
typedef struct Output8025EF54 Output8025EF54;

struct Output8025EF54;
struct Output8025EF54 {
    f32 value;
    s32 pad04;
    s32 pad08;
    s32 pad0C;
};

extern void func_8025EF34_de(u32 *stream, Output8025EF54 *out, s32 count);

extern unsigned int func_80260684_de(unsigned int value);

extern int func_8025E59C_de(void *arg0);

struct Stream;
typedef struct Stream Stream;

struct Segment8025FFD0;
typedef struct Segment8025FFD0 Segment8025FFD0;

struct func_802604CC_S1;
struct func_802604CC_S1 {
    char * unk0;
    char pad0[0x4 - 0x0 - sizeof(char*)];
    Rec_func_8024C92C_de * unk4;
    char pad4[0x8 - 0x4 - sizeof(Rec_func_8024C92C_de*)];
    void * unk8;
    char pad8[0x18 - 0x8 - sizeof(void*)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
};

extern f32 func_8025F434_de(f32 amount, f32 period);

extern float D_800C9208;

extern float D_800C4168_de;

extern float D_800C91F8;

extern float func_80260634_de(float value, int bits);

extern void func_80260724_de(u32 arg0, u32 arg1, u32 arg2);

struct Segment8025FFD0;
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

struct Stream;
struct Stream {
    s32 unk0;
    char pad4[8];
    s32 unkC;
    float coeff[4];
    u32 unk20;
    u32 unk24;
    s32 unk28;
};

struct Decode8025EF54;
struct Decode8025EF54 {
    s32 bits;
    f32 base;
    f32 range;
    s32 unused;
    u32 stream;
    s32 first_bits;
    s32 second_bits;
};

struct Curve;
typedef struct Curve Curve;

extern unsigned int func_802606A4_de(unsigned int arg0);

extern double D_800C40F8_de;

extern float D_800C9200;

extern double D_800C4100_de;

extern Func802608ECResult func_802608CC_de(f32 arg0, f32 arg1, f32 arg2);

struct func_802604CC_S1;
typedef struct func_802604CC_S1 func_802604CC_S1;

struct Decode8025EF54;
typedef struct Decode8025EF54 Decode8025EF54;

struct Poly;
struct Poly {
    float a;
    float b;
    float c;
    float d;
    u32 duration;
};

struct Poly;
typedef struct Poly Poly;

struct Curve;
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

struct func_802604BC_S1;
struct func_802604BC_S1 {
    char pad0[0x10];
    void **unk10;
};

extern void func_80260828_de(u32 *arg0, u32 arg1, u32 arg2);

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
typedef struct KeyIndex {
    /* 0x00 */ char pad0[0xA];
    /* 0x0A */ s16 key;
    /* 0x0C */ char padC[2];
} KeyIndex;
typedef struct PoseTable {
    s32 stride;
    char pad4[4];
    s16 pad8[2];
    s16 value[4];
} PoseTable;

#endif
