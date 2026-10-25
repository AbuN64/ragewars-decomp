#ifndef COMMON_ENTRYRECATE_H
#define COMMON_ENTRYRECATE_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"

struct EntryRecAtE;
typedef struct EntryRecAtE EntryRecAtE;


struct Other;
struct Other {
    char pad0[0x5E4];
    s32 enabled;
    char pad5E8[0x1224 - 0x5E8];
    s32 lockOn[2];
    char pad122C[0x16E0 - 0x122C];
    struct Other *next;
};





struct Shared_ActorView;



struct Actor_func_802AB400_de;
struct Actor_func_802AB400_de {
    u8 type;
    u8 pad1[7];
    CVector3 position; /* 0x08: provider func_8025DE54_de takes CVector3 */
    u8 pad14[0xE4 - 0x14];
    u16 team;
    char padE6[0x100 - 0xE6];
    s32 flags;
    u8 pad104[0x174 - 0x104];
    s32 active; /* 0x174 */
    u8 pad178[0x5D8 - 0x178];
    ObjRecAt8F *model;
    void *owner; /* 0x5DC */
    u8 pad5E0[4];
    s32 count;
    u16 fraction; /* 0x5E8 */
    s16 lives; /* 0x5EA */
    u8 pad5EC[8];
    s16 levels[7];
    char pad602[0x602 - 0x602];
    Shared_Slot slots[22];
};



struct Other;
typedef struct Other Other;

















struct EntryRecAtE;
struct EntryRecAtE {
    void *resource;
    s16 id;
    s16 sound;
    s16 callback;
    s16 reservedA;
    s16 index;
    s16 argument;
};




struct Actor_func_802AB400_de;
typedef struct Actor_func_802AB400_de Actor_func_802AB400_de;







extern float D_800C62E0;

/* The five 0x14-byte ammunition definitions searched at D_800D3230. */
typedef struct AmmoPickupDefinition {
    u8 reserved0[4];
    s16 kind;
    u8 reserved6[6];
    s16 slot;
    u8 reservedE[6];
} AmmoPickupDefinition;



/* Three-channel pickups extend the common two-argument effect record. */
typedef struct MultiChannelItemEffect {
    EntryRecAtE effect;
    s16 third;
} MultiChannelItemEffect;

extern f32 D_800C6260;
extern f32 D_800CB3F8;
extern f32 D_800C6270_de;
extern f32 D_800C6274_de;
extern f32 D_800C627C_de;
extern f32 D_800CB414;
extern f32 D_800C6288_de;
extern f32 D_800C628C_de;
extern f32 D_800C6290_de;
extern f32 D_800C6294_de;
extern f32 D_800C6298;
extern f32 D_800C629C;
extern f32 D_800C62A4;
extern f32 D_800C62AC;
#endif
