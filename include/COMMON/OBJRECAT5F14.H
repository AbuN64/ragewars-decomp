#ifndef COMMON_OBJRECAT5F14_H
#define COMMON_OBJRECAT5F14_H
struct SceneEffectPool;
#ifndef SPAN_1000_CODE_802624A0_H
#define SPAN_1000_CODE_802624A0_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"



struct func_802626BC_S1;
struct func_802626BC_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x8 - 0x4 - sizeof(u16)];
    u16 unk8;
    char pad8[0xC - 0x8 - sizeof(u16)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    func_802626BC_S1_U10 unk10;
};

struct ObjRecAt5F14;
typedef struct ObjRecAt5F14 ObjRecAt5F14;


struct EffectDesc;
typedef struct EffectDesc EffectDesc;


struct EffectDesc;
struct EffectDesc {
    u8 id;
    char pad1[7];
    CVector3 position;
    s32 owner;
    s32 count;
    CVector3 direction;
    char pad28[0x28];
    CVector3 color;
    char pad5C[0x10];
    f32 scale;
    char pad70[0x74];
    u16 variant;
};

extern SceneEffect *func_80262A9C_de(struct SceneEffectPool *scene, EffectDesc *desc);

extern void *func_80262FF8_de(s32 arg0, s32 *arg1);

struct Record_func_802627A0_de;
struct Record_func_802627A0_de {
    char pad0[0x1C];
    u16 count;
    u16 angle;
};

struct ObjRecAt10V1;
typedef struct ObjRecAt10V1 ObjRecAt10V1;

struct ResourceEntry;
typedef struct ResourceEntry ResourceEntry;

struct Effect_func_80262E88_de;
typedef struct Effect_func_80262E88_de Effect_func_80262E88_de;

struct ObjRecAt10V1;
struct ObjRecAt10V1 {
    int unk0;
    short unk4;
    char pad4[0x6 - 0x4 - sizeof(short)];
    short unk6;
    char pad6[0x8 - 0x6 - sizeof(short)];
    short unk8;
    char pad8[0xA - 0x8 - sizeof(short)];
    unsigned char unkA;
    char padA[0xB - 0xA - sizeof(unsigned char)];
    unsigned char unkB;
    char padB[0x10 - 0xB - sizeof(unsigned char)];
    int unk10;
};

struct Six;
struct Six {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

struct ObjectLinks5F28;
struct ObjectLinks5F28 {
    unsigned char padding_0[24320];
    void *unk_5F00;
    unsigned char padding_5F04[32];
    s32 unk_5F24;
};

union func_80262EA8_S1_U5F14;
typedef union func_80262EA8_S1_U5F14 func_80262EA8_S1_U5F14;

struct Effect_func_80262E88_de;
struct Effect_func_80262E88_de {
    char pad0[0xE8];
    f32 min[3];
    f32 max[3];
    char pad100[0];
    s32 flags;
    char pad104[0x70];
    s32 busy;
    char pad178[0x2EC - 0x178];
    struct Effect_func_80262E88_de *next;
    s32 *ref;
};

struct Effect_func_80262E88_de;
union func_80262EA8_S1_U5F14;
union func_80262EA8_S1_U5F14 {
    struct Effect_func_80262E88_de * v0;
    char v1;
};

struct func_80262EA8_S1;
struct func_80262EA8_S1 {
    char pad0[0x5F00];
    IntrusiveList unk5F00;
    char pad5F00[0x5F14 - 0x5F00 - sizeof(IntrusiveList)];
    IntrusiveList unk5F14;
};

struct ObjectLinks5F28;
typedef struct ObjectLinks5F28 ObjectLinks5F28;

struct Record_func_802627A0_de;
typedef struct Record_func_802627A0_de Record_func_802627A0_de;

struct func_802626BC_S1;
typedef struct func_802626BC_S1 func_802626BC_S1;

extern void func_802624A8_de(void *arg0);




struct BitReader;
typedef struct BitReader BitReader;

extern float D_800C4258_de;

union func_80262ABC_S1_U5F00;
typedef union func_80262ABC_S1_U5F00 func_80262ABC_S1_U5F00;

union func_80262ABC_S1_U5F00;
union func_80262ABC_S1_U5F00 {
    struct SceneEffect * v0;
    char v1;
};

struct ObjRecAt5F14;
struct ObjRecAt5F14 {
    SceneEffect effects[0x20];
    IntrusiveList unk5F00;
    char pad5F00[0x5F14 - 0x5F00 - sizeof(IntrusiveList)];
    IntrusiveList unk5F14;
};

struct BitReader;
struct BitReader {
    u8 *data;
    s32 bitPos;
};

/* The 0x25C-byte region-grid state (func_80296020_de fills it): the bit reader on the stream, the grid's origin,
 * the last cell lookup, and one signed code (or stream offset) per cell of the 17x17 grid. */
struct ResourceBitGrid;
typedef struct ResourceBitGrid ResourceBitGrid;
struct ResourceBitGrid {
    BitReader reader;
    s32 originX;
    s32 originY;
    s32 cellState;
    s32 cellValue;
    s16 cells[17 * 17];
};

struct func_80262EA8_S1;
typedef struct func_80262EA8_S1 func_80262EA8_S1;

struct ResourceEntry;
struct ResourceEntry {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

struct Six;
typedef struct Six Six;

/* The list func_80262C88_de appends its record to. */


/* Shared object layout established by effect-pool consumers. */
struct SceneEffectPool {
    SceneEffect DynAnims[0x20]; /* 0x0000 */
    IntrusiveList FreeList; /* 0x5F00 */
    IntrusiveList UsedList; /* 0x5F14 */
};

/* Eight-byte easing parameters returned for a motion animation segment. */
typedef struct AnimationBlendEntry {
    u16 frames;
    u8 reserved2[3];
    u8 start;
    u8 reserved6;
    u8 end;
} AnimationBlendEntry;

#endif
#endif
