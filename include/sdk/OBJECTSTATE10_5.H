#ifndef SDK_OBJECTSTATE10_5_H
#define SDK_OBJECTSTATE10_5_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ObjectState10_5;
typedef struct ObjectState10_5 ObjectState10_5;

struct ObjectState14_2;
typedef struct ObjectState14_2 ObjectState14_2;

struct func_802B8540_S1;
struct func_802B8540_S1 {
    char pad0[0x16];
    unsigned short unk16;
};

typedef void ( *SharedRecV3)(void *, signed int, void *);

struct ObjectState1C;
typedef struct ObjectState1C ObjectState1C;

struct ALStartParamAlt;
struct Node_func_80239AF4_de;
struct ALStartParamAlt {
    struct Node_func_80239AF4_de *next;
    s32 delta;
    s16 type;
    s16 unity;
    f32 pitch;
    s16 volume;
    u8 pan;
    u8 fxMix;
    s32 samples;
    void *wave;
};

struct ALStartParamAlt;
typedef struct ALStartParamAlt ALStartParamAlt;

struct ObjectState1C;
struct ObjectState1C {
    char pad0[0x8];
    ObjectLinks4_3 unk_8;
    char pad8[0x1A - 0x8 - sizeof(ObjectLinks4_3)];
    u16 unk_1A;
};

extern void alSynStartVoice(void *arg0, void *arg1, s32 arg2);

struct func_802B8540_S1;
typedef struct func_802B8540_S1 func_802B8540_S1;

struct ObjectState10_5;
struct ObjectState10_5 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xA - 0x8 - sizeof(s16)];
    u16 unk_A;
    char padA[0xC - 0xA - sizeof(u16)];
    s32 unk_C;
};

typedef void ( *SharedRecV10)(void *, signed int, void *);

struct ObjectState14_2;
struct ObjectState14_2 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s32 unk_C;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk_10;
};
#endif
