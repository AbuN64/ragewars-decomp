#ifndef UNBAKE_SPAN_1000_CODE_8020D370_H
#define UNBAKE_SPAN_1000_CODE_8020D370_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct ActorRec;
typedef struct ActorRec ActorRec;

extern float D_800C1DB8_de;

struct Obj_func_8020D9C0_de;
struct Obj_func_8020D9C0_de {
    char pad0[0x38];
    s32 count;
    char pad3C[0x138-0x3C];
    Vec3 points[10];
    Vec3 result;
    char pad1BC[0x1C4-0x1BC];
    s32 infoIndex;
};

extern float D_800C1E40_de;

struct Stage;
struct Stage {
    s32 to;
    s32 from;
    f32 distance;
};

struct Stage;
typedef struct Stage Stage;

struct Selection_func_8020D4AC_de;
struct Selection_func_8020D4AC_de {
    char pad0[0xC];
    s32 node;
    char pad10[0x28];
    s32 objectCount;
    Player *objects[33];
    Stage stages[10];
    Vec3 dirs[10];
    char pad1B0[0xC];
    s32 stageCount;
    s32 id;
};

struct RecCode802080008020DC10;
typedef struct RecCode802080008020DC10 RecCode802080008020DC10;

/* The trajectory mode belongs to the full instance, beyond its 20-byte header. */
typedef struct BallisticInstance {
    InstanceHdr header;
    u8 pad014[0x62E - 0x14];
    s16 trajectoryMode;
} BallisticInstance;

struct ActorRec;
struct ActorRec {
    BallisticInstance *instance;
    u8 pad004[0x248 - 4];
    f32 field248;
    f32 field24C;
    f32 field250;
    f32 field254;
    union {
        struct { f32 field258; f32 field25C; f32 field260; };
        Vec3 destination;
    };
    f32 field264;
    s32 field268;
    s32 field26C;
    s32 field270;
    s32 field274;
    f32 field278;
    f32 field27C;
    f32 field280;
    s32 field284;
};

struct RecCode802080008020DC10;
struct RecCode802080008020DC10 {
    char pad0[0x64];
    s32 unk64;
    char pad64[0x21C - 0x64 - sizeof(s32)];
    s32 unk21C;
};

struct Selection_func_8020D4AC_de;
typedef struct Selection_func_8020D4AC_de Selection_func_8020D4AC_de;

extern float D_800C1E48_de;

struct WeightSource;
struct WeightSource {
    char pad[0x2C];
    f32 first;
    f32 second;
    f32 third;
};

struct func_8020DCA0_S1;
typedef struct func_8020DCA0_S1 func_8020DCA0_S1;

extern float D_800C1E58_de;

extern float D_800C1E44_de;

struct Obj_func_8020DB14_de;
struct Obj_func_8020DB14_de {
    char pad0[0x14];
    int nodes[4];
    char pad24[0x1BC - 0x24];
    int hits;
    int node;
    char pad1C4[4];
    int pending;
};

struct func_8020DCA0_S1;
struct func_8020DCA0_S1 {
    void * unk0;
    char pad0[0x230 - 0x0 - sizeof(void*)];
    s32 unk230;
};

struct Obj_func_8020DB14_de;
typedef struct Obj_func_8020DB14_de Obj_func_8020DB14_de;

struct Obj_func_8020D9C0_de;
typedef struct Obj_func_8020D9C0_de Obj_func_8020D9C0_de;

extern float D_800C1E50_de;

struct WeightSource;
typedef struct WeightSource WeightSource;

extern s32 func_8020EAB4_de(void);

/* Resource sections returned by func_8028FDB4_de, selectors 1 and 2. */
#include "shared/func_8027AD4C_de_closed.h"
#include "resident_event_handler.h"
typedef struct BallisticResourceKeys {
    s32 tag;
    s32 count;
    u32 keys[1];
} BallisticResourceKeys;
typedef struct BallisticResourceRecords {
    s32 tag;
    s32 count;
    BallisticParamsHolder records[1];
} BallisticResourceRecords;

extern s32 *D_8013D534;

#endif
