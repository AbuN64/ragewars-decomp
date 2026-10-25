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




struct Node_func_8023CC08_de;
typedef struct Node_func_8023CC08_de Node_func_8023CC08_de;


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


struct Block10;


struct Node_func_8023CC08_de;
struct Node_func_8023CC08_de {
    struct Node_func_8023CC08_de *next;
    u16 start;
    u16 size;
    char pad8[8];
    u8 *data;
};



#endif
