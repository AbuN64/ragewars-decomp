#ifndef UNBAKE_SPAN_1000_CODE_80286050_H
#define UNBAKE_SPAN_1000_CODE_80286050_H
#include "types.h"
#include "common/types_06e4f7ef1f9e.h"
#include "gfx.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "common/types_8a8189af7b05.h"
struct LevelActor;
struct SceneRecAt10C0;
typedef struct SceneRecAt10C0 SceneRecAt10C0;

extern void func_8028B4C8_de(void);

struct TableRecAt8;
typedef struct TableRecAt8 TableRecAt8;

struct Shared_World;
extern s32 func_8028B5C0_de(struct Shared_World *arg0, s32 arg1);

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

extern void func_8028B4D0_de(struct Shared_World *arg0, s32 arg1, s32 arg2);

struct func_80286254_S1;
typedef struct func_80286254_S1 func_80286254_S1;

struct ObjectLinks74;
typedef struct ObjectLinks74 ObjectLinks74;

struct BankRecAt94;
typedef struct BankRecAt94 BankRecAt94;

struct Object_func_80288EA8_de;
struct Object_func_80288EA8_de {
    char pad0[0xD8];
    u16 flags;
};

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
struct WorldRecAt1B660 {
    char pad0[0x138];
    struct ObjectRecAt18 *objects;
    s32 pad13C;
    s32 count;
    char pad144[0x1B620 - 0x144];
    ObjectRecAt18 *switches[16];
    s32 switchCount;
};

struct func_8028B370_S0;
struct func_8028B370_S0 {
    char pad0[0x6C];
    void *unk6C;
};

struct func_8028B238_S1;
typedef struct func_8028B238_S1 func_8028B238_S1;

struct Entity;
struct Entity {
    char pad0[0xF];
    unsigned char flag;
    char pad10[3];
    unsigned char index;
};

struct func_8028AFE8_S1;
struct func_8028AFE8_S1 {
    char pad0[0xA0];
    char * unkA0;
};

struct func_8028AFE8_S1;
typedef struct func_8028AFE8_S1 func_8028AFE8_S1;

struct GlobalMode;
struct GlobalMode {
    char pad[0x1295];
    u8 mode;
};

struct Object_func_80288EA8_de;
typedef struct Object_func_80288EA8_de Object_func_80288EA8_de;

struct ObjectLinks74;
struct ObjectLinks74 {
    unsigned char padding_0[112];
    void *unk_70;
};

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
#include "shared/model_instance.h"

struct Scene_func_80288EA8_de;
typedef struct Scene_func_80288EA8_de Scene_func_80288EA8_de;

struct func_8028B370_S0;
typedef struct func_8028B370_S0 func_8028B370_S0;

struct Object_func_8028B274_de;
typedef struct Object_func_8028B274_de Object_func_8028B274_de;

struct func_8028B1F8_S1;
typedef struct func_8028B1F8_S1 func_8028B1F8_S1;

typedef struct Bounds37 { f32 minX,minY,minZ,maxX,maxY,maxZ; } Bounds37;
typedef struct Item37 { u8 pad0[0xA0]; Bounds37 bounds; u8 padB8[8]; } Item37;
typedef struct Items37 { s32 stride, count; Item37 items[1]; } Items37;
typedef struct Bounds2D37 { f32 minX,minZ,maxX,maxZ; } Bounds2D37;
typedef struct Resource37 { void *data; } Resource37;
typedef struct Region37 { Resource37 *resource; Bounds2D37 *bounds; s32 flags; } Region37;
typedef struct World37 { u8 pad0[0x1504]; s32 count; Region37 regions[1]; } World37;

typedef struct DraftStreamCell { f32 minX, minZ, maxX, maxZ; s32 occupied; } DraftStreamCell;
typedef struct DraftStreamTable {
    s32 stride, count;
    union { f32 coordinates[1]; DraftStreamCell cells[1]; } data;
} DraftStreamTable;
typedef struct DraftStreamData { s32 count; } DraftStreamData;
typedef struct DraftStreamHandle { DraftStreamData *data; } DraftStreamHandle;
typedef struct DraftStreamEntry {
    DraftStreamHandle *resource; DraftStreamCell *cell; s16 x, z;
} DraftStreamEntry;
typedef struct DraftStreamViewer {
    s32 pad0; struct DraftStreamViewer *next;
    char pad8[0x120]; Vec3 position;
    char pad134[0x234]; Vec3 minimum, maximum;
} DraftStreamViewer;
typedef struct DraftStreamWorld {
    char pad0[0x30]; s32 key;
    char pad34[0xC]; s32 resourceKey;
    char pad44[0x20]; void *table, *grid;
    char pad6C[0x20]; void *specialTable;
    char pad90[0x1470]; s32 entryCount, activeCount;
    DraftStreamEntry entries[128];
    char pad1B08[0x19BA8]; DraftStreamHandle *special;
    char specialState[0x25C];
    f32 originX, originZ, cellX, cellZ;
    char pad1B920[8]; s32 specialPresent, specialEnabled;
} DraftStreamWorld;
typedef struct DraftStreamPair { f32 first, second; } DraftStreamPair;
extern DraftStreamPair D_800FF200;
extern char D_800C5220_de[];
extern void func_80296020_de(void *, s32, s32, DraftStreamData *, Vec3 *);

#endif
