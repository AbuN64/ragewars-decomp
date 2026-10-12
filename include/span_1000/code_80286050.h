#ifndef UNBAKE_SPAN_1000_CODE_80286050_H
#define UNBAKE_SPAN_1000_CODE_80286050_H
#include "../types.h"
#include "common/types_06e4f7ef1f9e.h"
#include "gfx.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"
struct Scene_func_8028B028_de;
/* unbake published declaration: published_071d490f65b9ae384b2faaa5 */
typedef struct Scene_func_8028B028_de Scene_func_8028B028_de;

/* unbake published declaration: published_100abd53300e47a1931e0900 */
extern void func_8028B4C8_de(void);

struct Table_func_8028B274_de;
/* unbake published declaration: published_15df223cbdbf18c3650f5592 */
typedef struct Table_func_8028B274_de Table_func_8028B274_de;

/* unbake published declaration: published_2244acb7b26cfb9e525bc3f0 */
extern s32 func_8028B5C0_de(void *arg0, s32 arg1);

struct Entity;
/* unbake published declaration: published_2d471bd0dd800849d27d684c */
typedef struct Entity Entity;

struct Scene_func_80288EA8_de;
/* unbake published declaration: published_363e185a83d059a120b6903c */
struct Scene_func_80288EA8_de {
    char pad0[0x88];
    void *model;
    char pad8C[0xF8 - 0x8C];
    s32 loaded;
    char padFC[0x120 - 0xFC];
    Gfx *lists[2];
};

/* unbake published declaration: published_372f1c1f7ee26425990a9401 */
extern void func_8028B4D0_de(void *arg0, s32 arg1, s32 arg2);

struct func_80286254_S1;
/* unbake published declaration: published_40ac898289da89966db96c64 */
typedef struct func_80286254_S1 func_80286254_S1;

struct ObjectLinks74;
/* unbake published declaration: published_47017dde4166ac2169c35c11 */
typedef struct ObjectLinks74 ObjectLinks74;

struct Bank_func_8028B274_de;
/* unbake published declaration: published_4714b36fe8381a9bf4cb01ce */
typedef struct Bank_func_8028B274_de Bank_func_8028B274_de;

struct Object_func_80288EA8_de;
/* unbake published declaration: published_47df3d2cbdca7caec8f2eb54 */
struct Object_func_80288EA8_de {
    char pad0[0xD8];
    u16 flags;
};

struct Descriptor_func_80286950_de;
/* unbake published declaration: published_49908c9747c3af99f5b66707 */
typedef struct Descriptor_func_80286950_de Descriptor_func_80286950_de;

struct Table_func_8028B274_de;
/* unbake published declaration: published_4dce20a0f1c200acb2a5188b */
struct Table_func_8028B274_de {
    s32 unused;
    s32 count;
    u16 entries[1];
};

struct func_8028B4AC_S1;
/* unbake published declaration: published_4f758425d92d5d7c6ffdd7f6 */
typedef struct func_8028B4AC_S1 func_8028B4AC_S1;

struct Descriptor_func_80286950_de;
/* unbake published declaration: published_ef636bef5ced22952a95ca49 */
struct Descriptor_func_80286950_de {
    s32 type;
    s32 flags;
    char pad8[4];
    s16 model;
    char padE[0x20 - 0xE];
    s32 kind;
};

struct Descriptor_func_80286950_de;
struct Object_func_80286950_de;
/* unbake published declaration: published_cfc5cd4cb8b41e41502f0bba */
struct Object_func_80286950_de {
    char pad0[0x18];
    struct Descriptor_func_80286950_de *descriptor;
    char pad1C[0x2E8 - 0x1C];
};

struct Object_func_80286950_de;
/* unbake published declaration: published_d72f86cd35a6c35e404f3b3a */
typedef struct Object_func_80286950_de Object_func_80286950_de;

struct Object_func_80286950_de;
struct World_func_80286950_de;
/* unbake published declaration: published_5b2e40a87211ed3cbfba2ae8 */
struct World_func_80286950_de {
    char pad0[0x138];
    struct Object_func_80286950_de *objects;
    s32 pad13C;
    s32 count;
    char pad144[0x1B620 - 0x144];
    Object_func_80286950_de *switches[16];
    s32 switchCount;
};

struct func_8028B370_S0;
/* unbake published declaration: published_61b1fb3b80b1b19161337505 */
struct func_8028B370_S0 {
    char pad0[0x6C];
    void *unk6C;
};

struct func_8028B238_S1;
/* unbake published declaration: published_6d239fa1bf21cdfbb97023b9 */
typedef struct func_8028B238_S1 func_8028B238_S1;

struct Entity;
/* unbake published declaration: published_71ea1dc9be2ea29831f30722 */
struct Entity {
    char pad0[0xF];
    unsigned char flag;
    char pad10[3];
    unsigned char index;
};

struct func_8028AFE8_S1;
/* unbake published declaration: published_758f540c897aa294d4b368c2 */
struct func_8028AFE8_S1 {
    char pad0[0xA0];
    char * unkA0;
};

struct func_8028AFE8_S1;
/* unbake published declaration: published_87dd929e7fb972539243d19d */
typedef struct func_8028AFE8_S1 func_8028AFE8_S1;

struct GlobalMode;
/* unbake published declaration: published_8d8ce57edb052dd9d04d05ef */
struct GlobalMode {
    char pad[0x1295];
    u8 mode;
};

struct Object_func_80288EA8_de;
/* unbake published declaration: published_9e7ecee1fb34943b76781870 */
typedef struct Object_func_80288EA8_de Object_func_80288EA8_de;

struct ObjectLinks74;
/* unbake published declaration: published_9e7ed80e66ded070473254a0 */
struct ObjectLinks74 {
    unsigned char padding_0[112];
    void *unk_70;
};

struct func_8028B1F8_S2;
/* unbake published declaration: published_a3f15e02e2fb5e0d187653d2 */
typedef struct func_8028B1F8_S2 func_8028B1F8_S2;

struct Scene_func_8028B028_de;
/* unbake published declaration: published_a9ddbdd0b7db476e4b468c9c */
struct Scene_func_8028B028_de {
    char pad0[0xC50];
    func_80203C40_S1 *objects[128];
    s32 count;
    char padE54[0x10BC - 0xE54];
    s32 lateCount;
    func_80203C40_S1 *late[64];
};

struct Bank_func_8028B274_de;
struct Table_func_8028B274_de;
/* unbake published declaration: published_c0759c74cf5c6549946ce55b */
struct Bank_func_8028B274_de {
    char pad0[0x24];
    s32 field24;
    char pad28[0x2C];
    s32 field54;
    char pad58[0x3C];
    struct Table_func_8028B274_de *table;
};

struct func_8028B1F8_S2;
/* unbake published declaration: published_cb1494536f657fa1c26fc0b0 */
struct func_8028B1F8_S2 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    u16 unk8;
};

struct World_func_80286950_de;
/* unbake published declaration: published_cdc99f07d437794256a099bc */
typedef struct World_func_80286950_de World_func_80286950_de;

struct func_8028B4AC_S1;
/* unbake published declaration: published_d501f98364e89900262d5f7f */
struct func_8028B4AC_S1 {
    char pad0[0x84];
    void * unk84;
    char pad84[0x1B40C - 0x84 - sizeof(void*)];
    s32 unk1B40C;
};

struct func_8028B238_S1;
/* unbake published declaration: published_d57d11fa5aa2f8c10557bb51 */
struct func_8028B238_S1 {
    char pad0[0x94];
    char * unk94;
};

struct func_80286254_S1;
/* unbake published declaration: published_d7f11232ed866cb938331f87 */
struct func_80286254_S1 {
    char pad0[0xC50];
    s32 unkC50;
    char padC54[0xE50-0xC54];
    s32 unkE50;
};

struct GlobalMode;
/* unbake published declaration: published_db3412520d582581e44937c8 */
typedef struct GlobalMode GlobalMode;

struct func_8028B1F8_S1;
/* unbake published declaration: published_e0f139ef17fea94f04c7773c */
struct func_8028B1F8_S1 {
    char pad0[0x94];
    void * unk94;
};

struct Object_func_8028B274_de;
/* unbake published declaration: published_e8ced3816c9dd76557dd5d3c */
struct Object_func_8028B274_de {
    char pad0[4];
    s16 index;
    char pad6[0xDE];
    u16 id;
};

struct Scene_func_80288EA8_de;
/* unbake published declaration: published_eaecdbd96c809d67a6da5edc */
typedef struct Scene_func_80288EA8_de Scene_func_80288EA8_de;

struct func_8028B370_S0;
/* unbake published declaration: published_ec6479e202c558a8df6cb698 */
typedef struct func_8028B370_S0 func_8028B370_S0;

struct Object_func_8028B274_de;
/* unbake published declaration: published_f50c983dcd4b7d2744a1c8b4 */
typedef struct Object_func_8028B274_de Object_func_8028B274_de;

struct func_8028B1F8_S1;
/* unbake published declaration: published_f9405dec979e127e750a3f53 */
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
