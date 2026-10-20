#ifndef COMMON_OBJB_H
#define COMMON_OBJB_H
#include "TYPES.H"
#include "COMMON/LEVEL_TRACK.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PACKED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/LEVEL_INPUT.H"
struct func_8044B388_S1;
typedef struct func_8044B388_S1 func_8044B388_S1;

struct Object_func_8044D220_de;


struct func_8044CD58_S2;
typedef struct func_8044CD58_S2 func_8044CD58_S2;

struct State_func_8044D5C4_de;
struct State_func_8044D5C4_de {
    char p[0x11C0];
    s32 unk11C0;
    s32 unk11C4;
    char q[8];
    s32 unk11D0;
    s32 unk11D4;
};

struct ObjB;
typedef struct ObjB ObjB;

struct World;


struct LightSettings;
struct LightSettings {
    char pad0[0xA];
    u8 color[3];
    u8 ambient[3];
    char pad10;
    signed char dir[3];
};
struct LightSettings;
struct SceneRecAt1B2B4;
struct SceneRecAt1B2B4 {
    char pad0[0x1B2B0];
    struct LightSettings *light;
    s16 dir[3];
};

struct func_8044B27C_S1;
struct func_8044B27C_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    IntrusiveList unkC;
    IntrusiveList unk20;
    char pad34[0x38 - 0x34];
    s32 unk38;
    char pad38[0x40 - 0x38 - sizeof(s32)];
    char unk40;
    char pad40[0xF18 - 0x40 - sizeof(char)];
    s32 unkF18;
    char padF18[0xF1C - 0xF18 - sizeof(s32)];
    s32 unkF1C;
    char padF1C[0xF20 - 0xF1C - sizeof(s32)];
    s32 unkF20;
    char padF20[0xF24 - 0xF20 - sizeof(s32)];
    IntrusiveList unkF24;
    char padF24[0x1200 - 0xF24 - sizeof(IntrusiveList)];
    s32 unk1200;
};

struct func_8044CBE0_S1;
typedef struct func_8044CBE0_S1 func_8044CBE0_S1;

struct func_8044B27C_S1;
typedef struct func_8044B27C_S1 func_8044B27C_S1;

struct func_8044ADC0_S1;
struct func_8044ADC0_S1 {
    char pad0[0x24];
    u8 unk24;
    char pad24[0xA0 - 0x24 - sizeof(u8)];
    u8 unkA0;
    char padA0[0xB8 - 0xA0 - sizeof(u8)];
    u8 unkB8;
    char padB8[0xCC - 0xB8 - sizeof(u8)];
    u8 unkCC;
    char padCC[0xE0 - 0xCC - sizeof(u8)];
    u8 unkE0;
    char padE0[0x140 - 0xE0 - sizeof(u8)];
    u8 unk140;
    char pad140[0x160 - 0x140 - sizeof(u8)];
    u8 unk160;
    char pad160[0x1A0 - 0x160 - sizeof(u8)];
    u8 unk1A0;
    char pad1A0[0x1E0 - 0x1A0 - sizeof(u8)];
    u8 unk1E0;
    char pad1E0[0x554 - 0x1E0 - sizeof(u8)];
    u8 unk554;
    char pad554[0xE40 - 0x554 - sizeof(u8)];
    IntrusiveList unkE40;
    char padE40[0xE54 - 0xE40 - sizeof(IntrusiveList)];
    u8 unkE54;
    char padE54[0xE94 - 0xE54 - sizeof(u8)];
    u8 unkE94;
};

struct State_func_8044A170_de;
struct State_func_8044A170_de {
    char pad0[12];
    f32 unkC;
    f32 unk10;
    char pad14[104];
    s32 unk7C;
    char pad80[116];
    f32 unkF4;
    f32 unkF8;
    s32 unkFC;
    s32 unk100;
    s32 unk104;
    s32 unk108;
    s32 unk10C;
    f32 unk110;
    f32 unk114;
    s32 unk118;
    char pad11C[4];
    s32 unk120;
    s16 unk124;
    s16 unk126;
    char pad128[24];
    f32 unk140;
    char pad144[8];
    f32 unk14C;
    char pad150[332];
    f32 unk29C;
    f32 unk2A0;
    f32 unk2A4;
    f32 unk2A8;
    char pad2AC[4];
    s16 unk2B0;
    s16 unk2B2;
    s16 unk2B4;
    s16 unk2B6;
    s16 unk2B8;
    s16 unk2BA;
    s16 unk2BC;
    s16 unk2BE;
    char pad2C0[600];
    s32 unk518;
    f32 unk51C;
    u8 unk520;
    u8 unk521;
    u8 unk522;
    u8 unk523;
    u8 unk524;
    u8 unk525;
    u8 unk526;
    u8 unk527;
    f32 unk528;
    f32 unk52C;
    f32 unk530;
    f32 unk534;
    char pad538[4];
    s32 unk53C;
    s32 unk540;
    s32 unk544;
    u8 unk548;
};

struct Bucket;
typedef struct Bucket Bucket;

struct SceneRecAt1B2B4;
typedef struct SceneRecAt1B2B4 SceneRecAt1B2B4;

struct Level_func_8044CD8C_de;
struct Level_func_8044CD8C_de {
    char pad0[0x30];
    s32 key;
    char pad34[0x64 - 0x34];
    s32 file;
    void *grid;
};

struct PoolRecord;
typedef struct PoolRecord PoolRecord;

typedef IntrusiveList ListRec;

struct Bucket;
struct Bucket {
    struct Bucket *prev;
    struct Bucket *next;
    struct Record14 *object;
    f32 remaining;
};

struct Floats;
typedef struct Floats Floats;

struct State_func_8044D528_de;
typedef struct State_func_8044D528_de State_func_8044D528_de;

struct Node_func_8044D220_de;
struct Node_func_8044D220_de {
    s32 index;
    s32 link[2];
};

struct ObjA;
typedef struct ObjA ObjA;

struct func_8044AD14_S1;
typedef struct func_8044AD14_S1 func_8044AD14_S1;

struct Face;
struct Face {
    char pad0[0xE];
    u8 flags;
    u8 hidden;
    char pad10[3];
    u8 group;
};

struct Face;
typedef struct Face Face;

struct func_8044CD58_S2;
struct func_8044CD58_S2 {
    char pad0[0x8];
    Face unk8;
};

union func_8044CBE0_S1_U1B500;
union func_8044CBE0_S1_U1B500 {
    void * v0;
    s8 v1;
};

union func_8044CBE0_S1_U1B500;
typedef union func_8044CBE0_S1_U1B500 func_8044CBE0_S1_U1B500;

struct func_8044CBE0_S1;
struct func_8044CBE0_S1 {
    char pad0[0xB8];
    void * unkB8;
    void * unkBC;
    void * unkC0;
    void * unkC4;
    void * unkC8;
    void * unkCC;
    void * unkD0;
    void * unkD4;
    char padD4[0x10];
    void * unkE8;
    void * unkEC;
    void * unkF0;
    void * unkF4;
    char padF4[0x4];
    void * unkFC;
    void * unk100;
    char pad100[0x1B3FC];
    IntrusiveList unk1B500;
};

struct State_func_8044D0F0_de;
struct State_func_8044D0F0_de {
    char pad[0x3C];
    int resource;
    char pad40[8];
    int bank;
    char pad4c[0x1B3C0];
    int selection;
    char pad1b410[12];
    int changed;
};

struct World;


struct Node_func_8044D220_de;
typedef struct Node_func_8044D220_de Node_func_8044D220_de;

struct State_func_8044D0F0_de;
typedef struct State_func_8044D0F0_de State_func_8044D0F0_de;

struct State_func_8044A170_de;
typedef struct State_func_8044A170_de State_func_8044A170_de;

struct func_8044ADC0_S2;
struct func_8044ADC0_S2 {
    char pad0[0x10];
    State_func_8044A170_de unk10;
};

struct func_8044DE04_S1;
struct func_8044DE04_S1 {
    char pad0[0x1B410];
    s32 unk1B410;
    char pad1B410[0x1B414 - 0x1B410 - sizeof(s32)];
    s32 unk1B414;
    char pad1B414[0x1B418 - 0x1B414 - sizeof(s32)];
    s32 unk1B418;
    char pad1B418[0x1B41C - 0x1B418 - sizeof(s32)];
    s32 unk1B41C;
    char pad1B41C[0x1B434 - 0x1B41C - sizeof(s32)];
    s32 unk1B434;
    char pad1B434[0x1B438 - 0x1B434 - sizeof(s32)];
    s32 unk1B438;
    char pad1B438[0x1B43C - 0x1B438 - sizeof(s32)];
    s32 unk1B43C;
    char pad1B43C[0x1B440 - 0x1B43C - sizeof(s32)];
    s32 unk1B440;
};

struct PoolRecord;
/* One of a pool's eight 0x18-byte records, threaded through its lists by prev (+0) and next (+4). */
struct PoolRecord {
    void *prev;
    void *next;
    s32 unk8;
    f32 unkC;
    char q[6];
    s16 unk16;
};

struct CGameDynamicLight_t;
/* A list of the pool's eight records and a second, empty list. */
struct CGameDynamicLight_t {
    IntrusiveList empty;
    IntrusiveList records;
    struct PoolRecord entries[8];
};

extern float D_800CA1F0;

struct ObjA;
struct ObjA {
    s8 pad0;
    s8 type;
    char pad2[0x20 - 2];
    void **block;
    char pad24[0xE8 - 0x24];
};

struct Level_func_8044CD8C_de;
typedef struct Level_func_8044CD8C_de Level_func_8044CD8C_de;


struct func_8044AD14_S1;
struct func_8044AD14_S1 {
    char pad0[0x3];
    u8 unk3;
    char pad3[0x18 - 0x3 - sizeof(u8)];
    void * unk18;
    char pad18[0x5D8 - 0x18 - sizeof(void*)];
    void * unk5D8;
    char pad5D8[0x5E0 - 0x5D8 - sizeof(void*)];
    s32 unk5E0;
    char pad5E0[0x86C - 0x5E0 - sizeof(s32)];
    s32 unk86C;
};

struct Face;
struct WorldRecAt1B40C;
struct WorldRecAt1B40C {
    char pad0[0x80];
    void *tree;
    char pad84[0x11C0 - 0x84];
    s32 nfaces;
    s32 nedges;
    void *verts;
    void *edgeData;
    struct Face *faces;
    struct Face *edges;
    IntrusiveList listA;
    IntrusiveList listB;
    Bucket buckets[0x30];
    char pad1500[0x1B40C - 0x1500];
    s32 group;
};

struct func_8044DC48_S1;
struct func_8044DC48_S1 {
    char pad0[0x1B444];
    s32 unk1B444;
    char pad1B444[0x1B448 - 0x1B444 - sizeof(s32)];
    s32 unk1B448;
    char pad1B448[0x1B44C - 0x1B448 - sizeof(s32)];
    s32 unk1B44C;
};

struct func_8044ADC0_S1;
typedef struct func_8044ADC0_S1 func_8044ADC0_S1;

struct Object_func_8044D220_de;


extern short D_8010F320;

struct State_func_8044D528_de;
struct State_func_8044D528_de {
    char pad[0x1B2B0];
    Resource_func_80419E54_de *input;
    char pad1b2b4[0x15C];
    int mode;
    int active;
    char pad1b418[0x20];
    int selection;
};

struct func_8044D9DC_S1;
typedef struct func_8044D9DC_S1 func_8044D9DC_S1;

struct func_8044DE04_S1;
typedef struct func_8044DE04_S1 func_8044DE04_S1;

struct ObjRecAt8C8;
struct EntryCode8044ACCC {
    char pad0[0x228];
};

struct ObjRecAt8C8 {
    struct EntryCode8044ACCC entries[4];
    IntrusiveList free;
    IntrusiveList active;
    s16 unk8C8;
};

struct func_8044B388_S1;
struct func_8044B388_S1 {
    char pad0[0xC];
    char unkC;
    char padC[0x20 - 0xC - sizeof(char)];
    IntrusiveList unk20;
};

struct func_8044ADC0_S2;
typedef struct func_8044ADC0_S2 func_8044ADC0_S2;

struct State_func_8044D5C4_de;
typedef struct State_func_8044D5C4_de State_func_8044D5C4_de;

struct ObjRecAt8C8;
typedef struct ObjRecAt8C8 ObjRecAt8C8;


struct Floats;
struct Floats {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

struct func_8044DC48_S1;
typedef struct func_8044DC48_S1 func_8044DC48_S1;

struct func_8044D9DC_S1;
struct func_8044D9DC_S1 {
    char pad0[0x8];
    func_8022BC04_S3 unk8;
};

struct Object_func_8044A07C_de;
struct Object_func_8044A07C_de {
    char pad[0x11BC];
    s32 first;
    s32 second;
};
typedef struct Object_func_8044A07C_de ResourceHandleOwner;

struct WorldRecAt1B40C;
typedef struct WorldRecAt1B40C WorldRecAt1B40C;

struct ObjB;
struct ObjB {
    s8 pad0;
    s8 type;
    char pad2[0x60 - 2];
    void **block;
    char pad64[0x1C8 - 0x64];
};

struct Shared_World;
extern void func_8044CFF8_de(struct Shared_World *world, s32 level);
extern void **func_802540F4_de(s32,void **,s32,void *,s32);
extern s32 D_0044D804;
extern s32 D_0044D934;
extern char D_800C4F50_de;
extern char D_800C4F60_de;
extern char D_800C4F70_de;
extern char D_800C4F84_de;
extern char D_800C4F94_de;
extern char D_800C4FA4_de;
extern char D_800C4FB4_de;
extern char D_800C4FC8_de;
extern char D_800C4FD8_de;
extern char D_800C4FEC_de;
extern char D_800C4FFC_de;
extern char D_800C5008_de;
extern char D_800C5010_de;
extern char D_800C5018_de;
extern char D_800C5028_de;
extern char D_800C5038_de;
extern char D_800C504C_de;
extern char D_800C505C_de;
extern char D_800C5070_de;
extern char D_800C5098_de;

typedef struct Shape33 { u32 words[7]; } Shape33;
typedef void (*ResourceCallback33)(s32, s32);
extern void func_8026D7F4_de(s32, s32);
extern u8 D_800C4EE0_de[];
extern u8 D_800C4F04_de[];
extern u8 D_800C4F2C_de[];

typedef struct CollisionBuildVertex {
    f32 x;
    f32 y;
    f32 z;
    f32 ceiling;
} CollisionBuildVertex;
typedef union CollisionBuildTriangle { struct {
    u16 kind;
    u16 flags;
    CollisionBuildVertex *v[3];
    union CollisionBuildTriangle *adj[3];
    s32 mask;
} fields; CGameRegion canonical; s32 words[8]; } CollisionBuildTriangle;
typedef struct CollisionBuildHeader {
    s32 count;
    s32 offsets[5];
} CollisionBuildHeader;
typedef Packed CollisionBuildFace;
typedef struct CollisionBuildList {
    s32 kind;
    s32 count;
    CollisionBuildFace items[0];
} CollisionBuildList;
typedef union CollisionBuildMeshHandle {
    struct Shape_typemap_165 canonical;
    struct { void *data; s32 size,refs,flags; } payload;
} CollisionBuildMeshHandle;
typedef struct CollisionBuildVertexList { s32 kind,count; CollisionBuildVertex items[0]; } CollisionBuildVertexList;
typedef struct CollisionBuildTriangleList { s32 kind,count; CollisionBuildTriangle items[0]; } CollisionBuildTriangleList;
typedef struct CollisionBuildWorld {
    char pad0[0x84];
    int *tree;
    char pad88[0x1B2FC - 0x88];
    f32 minY;
    char pad1B300[0x1B40C - 0x1B300];
    s32 group;
} CollisionBuildWorld;
extern void func_8028FF0C_de(void *src, void *dst, s32 arg2);

extern void *memcpy(void *, const void *, unsigned int);
extern s32 D_80141060;
extern void func_80449970_us_rev1(SharedPlayer *player, InputRecAt27 *rec, s32 mode, s32 index);
#endif
