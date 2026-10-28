#ifndef COMMON_LOADOUT_H
#define COMMON_LOADOUT_H
#include "TYPES.H"
#include "COMMON/ACTIVE.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Loadout;
struct Loadout {
    char pad0[0x108];
    int capacity[1];
};
struct Loadout;
struct PlayerWeaponsGetAmmoCapacity;
struct PlayerWeaponsGetAmmoCapacity {
    char pad0[0x18];
    struct Loadout *loadout;
    char pad1C[0x5D4 - 0x1C];
    int character;
    char pad5D8[0x1450 - 0x5D8];
    int isBot;
};



struct Entry190;
struct Entry190 {
    s32 value;
    u8 pad[0x18C];
};

struct Shape_typemap_165;


struct ObjRecAt16E0V3;
struct ObjRecAt16E0V3 {
    char pad0[0xE4];
    u16 unkE4;
    char padE4[0x5DC - 0xE4 - sizeof(u16)];
    void * unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(void*)];
    void * unk16E0;
};

struct ObjectLinks1454_3;
struct ObjectLinks1454_3 {
    char pad0[0x18];
    void * unk_18;
    char pad18[0x5D4 - 0x18 - sizeof(void*)];
    s32 unk_5D4;
    char pad5D4[0x5D8 - 0x5D4 - sizeof(s32)];
    char * unk_5D8;
    char pad5D8[0x1450 - 0x5D8 - sizeof(char*)];
    s32 unk_1450;
};


struct Entry190;
typedef struct Entry190 Entry190;

struct Shape_typemap_165;


struct SharedRecAt848;
typedef struct SharedRecAt848 SharedRecAt848;

struct SharedRecAt848;
struct SharedRecAt848 {
    char pad0[0x840];
    f32 value;
    char pad844[4];
    s32 override;
};

extern f32 func_8022AA44_de(SharedRecAt848 *rampState);

struct func_8022A274_S2;
struct func_8022A274_S2 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(void*)];
    void * unk16E0;
};


struct IntegerStateD4;
typedef struct IntegerStateD4 IntegerStateD4;



extern float D_800C2D04_de;

struct PlayerWeaponsGetAmmoCapacity;
typedef struct PlayerWeaponsGetAmmoCapacity PlayerWeaponsGetAmmoCapacity;


struct Node_Weapons_EndRound;
struct Node_Weapons_EndRound {
    u8 pad0[0x5D8];
    u8 *state;
    u8 pad5DC[0x280];
    s32 field85C;
    u8 pad860[0xE80];
    struct Node_Weapons_EndRound *next;
};



struct IntegerStateD4;
struct IntegerStateD4 {
    unsigned char padding_0[208];
    s32 unk_D0;
};


struct func_8022A8B8_S2;
struct func_8022A8B8_S2 {
    char pad0[0x670];
    f32 unk670;
    char pad670[0x16E0 - 0x670 - sizeof(f32)];
    char * unk16E0;
};

extern int func_8022AE28_de(void *player, void *newPosition);

struct Context;
extern void *func_8022A634_de(struct Context *context, u32 viewPlayerIndex);

extern void func_8022A95C_de(void *player);



struct ObjRecAtB4;
typedef struct ObjRecAtB4 ObjRecAtB4;

extern float D_800C2CE8_de;




extern void func_8022A940_de(Shared_Effect *effect);


extern void func_8022A8C8_de(char *object, f32 arg1);

extern void func_8022A928_de(ObjRecAtB4 *record, int newValue);




extern float D_800C2D08_de;



struct Node_Weapons_EndRound;
typedef struct Node_Weapons_EndRound Node_Weapons_EndRound;

struct GlobalState;
typedef struct GlobalState GlobalState;




struct func_8022A470_S2;
typedef struct func_8022A470_S2 func_8022A470_S2;


struct ObjRecAtB4;
struct ObjRecAtB4 {
    char pad0[0x4];
    int unk4;
    char pad4[0xB4 - 0x4 - sizeof(int)];
    int unkB4;
};








struct ObjectLinks1454_3;
typedef struct ObjectLinks1454_3 ObjectLinks1454_3;


struct func_8022A274_S2;
typedef struct func_8022A274_S2 func_8022A274_S2;

struct ObjRecAt16E0V3;
typedef struct ObjRecAt16E0V3 ObjRecAt16E0V3;

struct GlobalState;
struct GlobalState {
    u8 pad0[0x1C];
    s32 field1C;
    s32 field20;
    s32 field24;
    s32 field28;
    u8 pad2C[0x28];
    s32 restricted; /* 0x54 */
    u8 pad58[0x10];
    s32 restrictionActive; /* 0x68 */
};

struct Node_Weapons_EndRound;

struct func_8022A8B8_S2;
typedef struct func_8022A8B8_S2 func_8022A8B8_S2;

struct func_8022A470_S2;
struct func_8022A470_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x16E0 - 0x10 - sizeof(f32)];
    void * unk16E0;
};

extern float D_800C2D00_de;
#endif
