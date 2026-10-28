#ifndef COMMON_INTEGERSTATE2C_H
#define COMMON_INTEGERSTATE2C_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
struct IntegerState2C;
struct IntegerState2C {
    char pad0[0x8];
    s32 unk_8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unk_C;
    char padC[0x24 - 0xC - sizeof(s32)];
    s32 unk_24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk_28;
};


extern float D_800C1CFC_de;

extern float D_800C1CF4_de;



extern float D_800C1CC0_de;

struct SharedRecAt0V1;
typedef struct SharedRecAt0V1 SharedRecAt0V1;



extern float D_800C1C98_de;

extern float D_800C6E20;

struct Shared_WeaponSlot;
typedef struct Shared_WeaponSlot Shared_WeaponSlot;




extern float D_800C1CAC_de;





extern float D_800C1D00_de;


extern float D_800C1D08_de;


extern float D_800C1CB0_de;

extern float D_800C1CC4_de;

extern float D_800C1CA8_de;

extern float D_800C1CB8_de;

struct ObjectLinks2EC;
struct ObjectLinks2EC {
    char pad0[0x64];
    char * unk_64;
    char pad64[0x23C - 0x64 - sizeof(char*)];
    s32 unk_23C;
    char pad23C[0x240 - 0x23C - sizeof(s32)];
    s32 unk_240;
    char pad240[0x2E4 - 0x240 - sizeof(s32)];
    s32 unk_2E4;
    char pad2E4[0x2E8 - 0x2E4 - sizeof(s32)];
    s32 unk_2E8;
};

extern float D_800C1CA0_de;


extern float D_800C1D1C_de;

extern float D_800C1D28_de;

extern float D_800C1CBC_de;



extern float D_800C1C94_de;



extern float D_800C1D2C_de;


struct Shared_Arg0;
typedef struct Shared_Arg0 Shared_Arg0;

struct Shared_Node;
struct Shared_Node {
    s32 unk0;
    char pad4[0xC];
    struct Shared_Node * unk10;
    char pad14[0x20];
    void * unk34;
};

struct Shared_Arg0;
struct Shared_Node;
struct Shared_Arg0 {
    s32 * unk0;
    char pad4[0x20];
    struct Shared_Node * unk24;
};




extern float D_800C6E04;


struct ObjectLinks2EC;
typedef struct ObjectLinks2EC ObjectLinks2EC;

extern float D_800C1D24_de;


extern float D_800C1D20_de;

extern float D_800C6E00;

extern float D_800C1C9C_de;

struct Shared_Node;
typedef struct Shared_Node Shared_Node;

struct SharedRecAt0V1;
struct SharedRecAt0V1 {
    char unk0[1];
};


extern float D_800C1CF8_de;

struct Shared_WeaponSlot;
struct func_80204620_S2;
struct Shared_WeaponSlot {
    char pad0[0x8];
    char unk8;
    char pad9[0xF];
    struct func_80204620_S2 * unk18;
    char pad1C[0xC8];
    u16 unkE4;
    char padE6[0x2];
};

struct Shared_WeaponSlot;



struct AiController;
struct AiConfig;
extern void Portal_UpdateAlternatingActionBursts(struct AiController *arg0, struct AiConfig *arg1);

extern void Portal_InitializeRandomActionSettings(void *arg0, void *arg1);


extern float D_800C1C90_de;

struct Controls;
typedef struct Controls Controls;

extern float D_800C6E28;


extern float D_800C1CA4_de;


struct IntegerState2C;
typedef struct IntegerState2C IntegerState2C;


extern float D_800C1D04_de;


extern float D_800C1CB4_de;




extern void Portal_UpdateMeterGatedActionBurst(void *arg0, void *arg1);



extern void Portal_UpdateCountedEffectAction(ObjectLinks2EC *arg0, IntegerState2C *config);

extern float D_800C6E08;


extern void Portal_UpdateRandomActionPulse(void *arg0, void *arg1);



extern void Portal_UpdateTimedActionBurst(void *arg0, void *arg1);


extern void Portal_UpdateHeldActionBurst(void *arg0, void *arg1);

extern float D_800C1D0C_de;


#include "COMMON/SHAREDCALLBACK5.H"
typedef struct AiCharacterDefinition {
    u8 pad0[0x28];
    f32 unk28; /* 0x28 */
    f32 unk2C; /* 0x2C */
    f32 unk30; /* 0x30 */
    f32 unk34; /* 0x34 */
    u8 pad38[0x14];
    u32 loadout[4]; /* 0x4C: word-sized item IDs; low half of [1] is the starting weapon ID. */
} AiCharacterDefinition;
typedef struct AiConfig {
    s32 unk0; /* 0x0 */
    s32 unk4; /* 0x4 */
    s32 unk8; /* 0x8 */
    s32 unkC; /* 0xC */
    s32 unk10; /* 0x10 */
    s32 unk14; /* 0x14 */
    s32 unk18; /* 0x18 */
    s32 unk1C; /* 0x1C */
    s32 unk20; /* 0x20 */
    s32 unk24; /* 0x24 */
    s32 unk28; /* 0x28 */
    s32 unk2C; /* 0x2C */
    s32 unk30; /* 0x30 */
    s32 unk34; /* 0x34 */
} AiConfig;
#endif
