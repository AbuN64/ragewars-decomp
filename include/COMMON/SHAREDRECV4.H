#ifndef COMMON_SHAREDRECV4_H
#define COMMON_SHAREDRECV4_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
typedef void ( *SharedRecV4)(void *, signed int, void *);

struct Node_func_802B3130_de;
typedef struct Node_func_802B3130_de Node_func_802B3130_de;

struct ObjectLinks10_2;
typedef struct ObjectLinks10_2 ObjectLinks10_2;

struct ALParam_s_func_802B3000_de;
typedef struct ALParam_s_func_802B3000_de ALParam_s_func_802B3000_de;

struct ObjectState10_3;
typedef struct ObjectState10_3 ObjectState10_3;

struct ObjectLinks10_2;
struct ObjectLinks10_2 {
    char pad0[0x4];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    void * unk_C;
};


struct ObjectState10_4;
typedef struct ObjectState10_4 ObjectState10_4;

typedef void ( *SharedRecV7)(void *, signed int, void *);

struct PVoice_s_func_802B3000_de;
typedef struct PVoice_s_func_802B3000_de PVoice_s_func_802B3000_de;

struct ALParam_s_func_802B3000_de;
struct ALParam_s_func_802B3000_de {
    struct ALParam_s_func_802B3000_de *next;
    s32 delta;
    s16 type;
    union {
        f32 f;
        s32 i;
    } data;
    union {
        f32 f;
        s32 i;
    } moredata;
};

typedef void ( *SharedRecV5)(void *, signed int, void *);

struct ObjRecAt40V2;
struct ObjRecAt40V2 {
    u8 padding000[0x14];
    ALEventQueue events; /* 0x14 */
    u8 padding028[0x14];
    s32 field3C;
    s32 field40;
};


struct ObjectState10_3;
struct ObjectState10_3 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    s32 unk_C;
};

struct Limit;
struct Node_func_802B3130_de;
struct Node_func_802B3130_de {
    struct Node_func_802B3130_de *next;
    char pad4[4];
    struct Limit *limit;
    char padC[0xCC];
    s32 flags;
};

typedef void ( *SharedRecV8)(void *, signed int, void *);

struct ObjectState10_4;
struct ObjectState10_4 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
    char pad8[0xC - 0x8 - sizeof(s16)];
    f32 unk_C;
};

struct ObjRecAt40V2;
typedef struct ObjRecAt40V2 ObjRecAt40V2;

#endif
