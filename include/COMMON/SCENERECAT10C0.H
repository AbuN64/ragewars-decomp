#ifndef COMMON_SCENERECAT10C0_H
#define COMMON_SCENERECAT10C0_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/GFX.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHAREDPLAYER.H"
struct LevelActor;
struct SceneRecAt10C0;
typedef struct SceneRecAt10C0 SceneRecAt10C0;


struct TableRecAt8;
typedef struct TableRecAt8 TableRecAt8;

struct Shared_World;

struct Entity;
typedef struct Entity Entity;

struct Scene_func_80288EA8_de;
struct Scene_func_80288EA8_de {
    char pad0[0x88];
    void *model;
    char pad8C[0xF8 - 0x8C];
    s32 loaded;
    char padFC[0x120 - 0xFC];
    Gfx *lists[2];
};


struct func_80286254_S1;
typedef struct func_80286254_S1 func_80286254_S1;

struct ObjectLinks74;
typedef struct ObjectLinks74 ObjectLinks74;

struct BankRecAt94;
typedef struct BankRecAt94 BankRecAt94;

struct Object_func_80288EA8_de;

struct DescriptorRecAt20;
typedef struct DescriptorRecAt20 DescriptorRecAt20;

struct TableRecAt8;
struct TableRecAt8 {
    s32 unused;
    s32 count;
    u16 entries[1];
};

struct func_8028B4AC_S1;
typedef struct func_8028B4AC_S1 func_8028B4AC_S1;

struct DescriptorRecAt20;
struct DescriptorRecAt20 {
    s32 type;
    s32 flags;
    char pad8[4];
    s16 model;
    char padE[0x20 - 0xE];
    s32 kind;
};

struct DescriptorRecAt20;
struct ObjectRecAt18;
struct ObjectRecAt18 {
    char pad0[0x18];
    struct DescriptorRecAt20 *descriptor;
    char pad1C[0x2E8 - 0x1C];
};

struct ObjectRecAt18;
typedef struct ObjectRecAt18 ObjectRecAt18;

struct ObjectRecAt18;
struct WorldRecAt1B660;

struct func_8028B370_S0;
struct func_8028B370_S0 {
    char pad0[0x6C];
    void *unk6C;
};

struct func_8028B238_S1;
typedef struct func_8028B238_S1 func_8028B238_S1;

struct Entity;

struct func_8028AFE8_S1;
struct func_8028AFE8_S1 {
    char pad0[0xA0];
    char * unkA0;
};

struct func_8028AFE8_S1;
typedef struct func_8028AFE8_S1 func_8028AFE8_S1;

struct GlobalMode;

struct Object_func_80288EA8_de;
typedef struct Object_func_80288EA8_de Object_func_80288EA8_de;

struct ObjectLinks74;

struct func_8028B1F8_S2;
typedef struct func_8028B1F8_S2 func_8028B1F8_S2;

struct SceneRecAt10C0;
struct SceneRecAt10C0 {
    char pad0[0xC50];
    struct LevelActor *objects[128];
    s32 count;
    char padE54[0x10BC - 0xE54];
    s32 lateCount;
    struct LevelActor *late[64];
};

struct BankRecAt94;
struct TableRecAt8;
struct BankRecAt94 {
    char pad0[0x24];
    s32 field24;
    char pad28[0x2C];
    s32 field54;
    char pad58[0x3C];
    struct TableRecAt8 *table;
};

struct func_8028B1F8_S2;
struct func_8028B1F8_S2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    u16 unk8;
};

struct WorldRecAt1B660;
typedef struct WorldRecAt1B660 WorldRecAt1B660;

struct func_8028B4AC_S1;
struct func_8028B4AC_S1 {
    char pad0[0x84];
    void * unk84;
    char pad84[0x1B40C - 0x84 - sizeof(void*)];
    s32 unk1B40C;
};

struct func_8028B238_S1;
struct func_8028B238_S1 {
    char pad0[0x94];
    char * unk94;
};

struct func_80286254_S1;
struct func_80286254_S1 {
    char pad0[0xC50];
    s32 unkC50;
    char padC54[0xE50-0xC54];
    s32 unkE50;
};

struct GlobalMode;
typedef struct GlobalMode GlobalMode;

struct func_8028B1F8_S1;
struct func_8028B1F8_S1 {
    char pad0[0x94];
    void * unk94;
};

struct Object_func_8028B274_de;
#include "COMMON/MODEL_INSTANCE.H"

struct Scene_func_80288EA8_de;
typedef struct Scene_func_80288EA8_de Scene_func_80288EA8_de;

struct func_8028B370_S0;
typedef struct func_8028B370_S0 func_8028B370_S0;

struct Object_func_8028B274_de;
typedef struct Object_func_8028B274_de Object_func_8028B274_de;

struct func_8028B1F8_S1;
typedef struct func_8028B1F8_S1 func_8028B1F8_S1;

typedef struct Bounds2D37 { f32 minX,minZ,maxX,maxZ; } Bounds2D37;

typedef struct DraftStreamCell { f32 minX, minZ, maxX, maxZ; s32 occupied; } DraftStreamCell;
typedef struct DraftStreamData { s32 count; } DraftStreamData;
typedef struct DraftStreamHandle { DraftStreamData *data; } DraftStreamHandle;
typedef struct DraftStreamEntry {
    DraftStreamHandle *resource; DraftStreamCell *cell; s16 x, z;
} DraftStreamEntry;
typedef struct DraftStreamViewer {
    s32 pad0; struct DraftStreamViewer *next;
    char pad8[0x120]; CVector3 position;
    char pad134[0x234]; CVector3 minimum, maximum;
} DraftStreamViewer;
typedef struct DraftStreamPair { f32 first, second; } DraftStreamPair;
extern DraftStreamPair D_800FF200;
extern char D_800C5220_de[];
struct ResourceBitGrid;
extern void System_DecodeRegionGrid(struct ResourceBitGrid *, s32, s32, DraftStreamData *, CVector3 *);
#endif
