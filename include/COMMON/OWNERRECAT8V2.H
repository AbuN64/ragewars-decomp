#ifndef COMMON_OWNERRECAT8V2_H
#define COMMON_OWNERRECAT8V2_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"

struct Block_func_8023C85C_de;
typedef struct Block_func_8023C85C_de Block_func_8023C85C_de;

struct OwnerRecAt8V2;

struct OwnerRecAt8V2;
typedef struct OwnerRecAt8V2 OwnerRecAt8V2;

extern void func_8023CCD4_de(OwnerRecAt8V2 *arg0);

struct Channels;
typedef struct Channels Channels;



struct Shape_typemap_110;


struct func_8023D148_S1;
typedef struct func_8023D148_S1 func_8023D148_S1;

struct func_8023C77C_S1;
typedef struct func_8023C77C_S1 func_8023C77C_S1;

struct Node_func_8023CC08_de;
typedef struct Node_func_8023CC08_de Node_func_8023CC08_de;

struct func_8023D148_S2;
struct func_8023D148_S2 {
    char pad0[0x48];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x54 - 0x4C - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
    char pad58[0x60 - 0x58 - sizeof(f32)];
    f32 unk60;
    char pad60[0x64 - 0x60 - sizeof(f32)];
    f32 unk64;
};

struct Block10;
typedef struct Block10 Block10;

union ObjectState1000;
union ObjectState1000 {
    u8 marks[4096];
    struct { u8 padding[0x3CF]; u8 indices[96]; } first;
    struct { u8 padding[0x3D0]; u8 indices[96]; } second;
};

struct ResourcePageMapping;
struct ResourcePageMapping {
    struct ResourcePageMapping *next;
    struct ResourcePageMapping *prev;
    u16 id;
    union { u16 padA; struct { u8 index; u8 slot; }; };
    s32 fieldC;
};

extern float D_800C3630_de;

struct Region;
struct Region {
    struct Region *next;
    u16 start;
    u16 pages;
    u8 (*source)[4096];
    s32 padC;
    u8 *map;
    s32 pad14;
};

struct Region;
struct RegionDesc;

struct RegionDesc;
typedef struct RegionDesc RegionDesc;

extern void func_8023CDD4_de(RegionDesc *desc);


struct Slot_func_8023B9C0_eu;
typedef struct Slot_func_8023B9C0_eu Slot_func_8023B9C0_eu;

struct ResourcePageMapping;
typedef struct ResourcePageMapping ResourcePageMapping;

struct Block_func_8023C85C_de;

struct Channels;
struct Channels {
    char pad0[0x1C];
};

struct Slot_func_8023B9C0_eu;
struct Slot_func_8023B9C0_eu {
    union {
        struct { s32 a; s32 b; char pad8[2]; u8 index; char padB[5]; };
        ResourcePageMapping chain;
    };
};

/* The first 0x20 bytes of the resource pager state: request statistics, copied out whole by func_8023C8D4_de. */
struct PagerCounters {
    s32 requests;
    s32 misses;
    u32 lastAddress;
    char padC[0x20 - 0xC];
};
struct PagerState;


union ObjectState1000;
typedef union ObjectState1000 ObjectState1000;

/* D_800FFB50: the page mappings of the resource pager */
typedef struct ResourcePageMapping Slot_func_8023CCD4_de;

struct Node_func_8023CBC0_de;
typedef struct Node_func_8023CBC0_de Node_func_8023CBC0_de;

struct Node_func_8023CBC0_de;
struct Node_func_8023CBC0_de {
    struct Node_func_8023CBC0_de *next;
    u16 f4;
    u16 f6;
};

struct Region;
typedef struct Region Region;

struct PagerState;
typedef struct PagerState PagerState;

struct func_8023D148_S2;
typedef struct func_8023D148_S2 func_8023D148_S2;

struct Block10;

struct func_8023D148_S1;
struct func_8023D148_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x40 - 0x4 - sizeof(s32)];
    s32 * unk40;
    char pad40[0x44 - 0x40 - sizeof(s32*)];
    func_80234DD0_S1_U260 unk44;
    char pad44[0x50 - 0x44 - sizeof(func_80234DD0_S1_U260)];
    func_80234DD0_S1_U260 unk50;
    char pad50[0x5C - 0x50 - sizeof(func_80234DD0_S1_U260)];
    func_80234DD0_S1_U260 unk5C;
    char pad5C[0x68 - 0x5C - sizeof(func_80234DD0_S1_U260)];
    CVector3 unk68;
    char pad68[0x80 - 0x68 - sizeof(CVector3)];
    f32 unk80;
    char pad80[0x84 - 0x80 - sizeof(f32)];
    f32 unk84;
    char pad84[0x88 - 0x84 - sizeof(f32)];
    f32 unk88;
    char pad88[0x8C - 0x88 - sizeof(f32)];
    f32 unk8C;
    char pad8C[0x90 - 0x8C - sizeof(f32)];
    f32 unk90;
    char pad90[0x94 - 0x90 - sizeof(f32)];
    f32 unk94;
    char pad94[0x98 - 0x94 - sizeof(f32)];
    f32 unk98;
    char pad98[0x9C - 0x98 - sizeof(f32)];
    f32 unk9C;
    char pad9C[0xA0 - 0x9C - sizeof(f32)];
    f32 unkA0;
    char padA0[0xA4 - 0xA0 - sizeof(f32)];
    f32 unkA4;
    char padA4[0xA8 - 0xA4 - sizeof(f32)];
    f32 unkA8;
    char padA8[0xB0 - 0xA8 - sizeof(f32)];
    s32 unkB0;
};

struct Node_func_8023CC08_de;
struct Node_func_8023CC08_de {
    struct Node_func_8023CC08_de *next;
    u16 start;
    u16 size;
    char pad8[8];
    u8 *data;
};


struct func_8023C77C_S1;
struct func_8023C77C_S1 {
    char pad0[0xC];
    void ** unkC;
};

extern void func_8023CFD8_eu(void * arg0);
#endif
