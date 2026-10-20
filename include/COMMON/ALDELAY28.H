#ifndef COMMON_ALDELAY28_H
#define COMMON_ALDELAY28_H
#include "COMMON/AUDIO_CALLBACKS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
extern float D_800C788C_de;

struct ALDelay28;
typedef struct ALDelay28 ALDelay28;

struct CallbackStateC;
struct CallbackStateC {
    unsigned char padding_0[8];
    void (*callback)(void *, s32, s32);
};


struct func_802BB32C_S2;
typedef struct func_802BB32C_S2 func_802BB32C_S2;

struct ALResampler_s28;
struct ALResampler_s28 {
    ALFilter_s14 filter;
    void *state;
    f32 ratio;
    s32 upitch;
    f32 delta;
    s32 first;
};

struct ALFilter_s14_2;
typedef struct ALFilter_s14_2 ALFilter_s14_2;

struct ALFilter_s14_2;
struct ALFilter_s14_2 {
    struct ALFilter_s14_2 *source;
    ALCmdHandler handler;
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
};

struct ALResampler_s;
struct ALResampler_s {
    ALFilter_s14_2 filter;
    void *state;
    f32 ratio;
    s32 upitch;
    f32 delta;
    s32 first;
    void *ctrlList;
    void *ctrlTail;
    s32 motion;
};


extern void *jtbl_800C7750[];

struct ALResampler_s28;
typedef struct ALResampler_s28 ALResampler_s28;

struct ALDelay28;
struct ALDelay28 {
    u32 input;
    u32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    f32 rsinc;
    f32 rsval;
    s32 rsdelta;
    f32 rsgain;
    void *lp;
    ALResampler_s28 *rs;
};


struct ALResampler_s;
typedef struct ALResampler_s ALResampler_s;

struct IntegerState34;
typedef struct IntegerState34 IntegerState34;

struct ALFx;
typedef struct ALFx ALFx;

struct func_802BB32C_S2;
struct func_802BB32C_S2 {
    char pad0[0x2];
    u16 unk2;
    char pad2[0x28 - 0x2 - sizeof(u16)];
    s32 unk28;
    char pad28[0x2F - 0x28 - sizeof(s32)];
    u8 unk2F;
};

struct func_802BB32C_S1;
struct func_802BB32C_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
};

struct func_802BB590_S1;
struct func_802BB590_S1 {
    char pad0[0x30];
    void * unk30;
    char pad30[0x34 - 0x30 - sizeof(void*)];
    s32 unk34;
};

struct func_802BB590_S1;
typedef struct func_802BB590_S1 func_802BB590_S1;

extern float D_800C7748_de;

extern float D_800C7880_de;


extern float D_800C7888_de;

extern float D_800C7884_de;

struct IntegerState34;
struct IntegerState34 {
    char pad0[0x18];
    s32 unk_18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk_1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk_20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk_24;
    char pad24[0x30 - 0x24 - sizeof(s32)];
    s32 unk_30;
};

struct func_802BB32C_S1;
typedef struct func_802BB32C_S1 func_802BB32C_S1;

struct CallbackStateC;
typedef struct CallbackStateC CallbackStateC;

struct ALFx;
struct ALFx {
    ALFilter_s14 filter;
    s16 *base;
    s16 *input;
    u32 length;
    ALDelay28 *delay;
    u8 section_count;
    void *paramHdl;
};

extern float D_800C7740_de;

typedef struct ALFilter_u1 {
    struct ALFilter_u1 *source;
    ALCmdHandler handler;
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
} ALFilter_u1;
typedef struct ALSave_u1 {
    ALFilter_u1 filter;
    s32 dramout;
    s32 first;
} ALSave_u1;
extern char D_800C8DB0_eu_x[];
extern char D_800C8DB4_eu_x[];
#endif
