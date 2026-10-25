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
struct Player_func_8022ACB8_de;
struct Player_func_8022ACB8_de {
    char pad0[0x18];
    struct Loadout *loadout;
    char pad1C[0x5D4 - 0x1C];
    int character;
    char pad5D8[0x1450 - 0x5D8];
    int isBot;
};

struct func_8022A94C_S1;
typedef struct func_8022A94C_S1 func_8022A94C_S1;

struct func_8022A67C_S1;
struct func_8022A67C_S1 {
    char pad0[0x20];
    SharedPlayer * unk20;
};

struct Entry190;
struct Entry190 {
    s32 value;
    u8 pad[0x18C];
};

struct Shape_typemap_165;
struct func_8022A94C_S2;
struct func_8022A94C_S2 {
    char pad0[0x2F0];
    Triple unk2F0;
    char pad2F0[0x2FC - 0x2F0 - sizeof(Triple)];
    s32 unk2FC;
    char pad2FC[0x344 - 0x2FC - sizeof(s32)];
    struct Shape_typemap_165 unk344;
    char pad344[0x354 - 0x344 - sizeof(struct Shape_typemap_165)];
    f32 unk354;
};

struct func_8022AAC4_S2;
struct func_8022AAC4_S2 {
    char pad0[0x20];
    s16 * unk20;
    char pad20[0x24 - 0x20 - sizeof(s16*)];
    s16 * unk24;
};

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

struct func_8022A738_S1;
typedef struct func_8022A738_S1 func_8022A738_S1;

struct Entry190;
typedef struct Entry190 Entry190;

struct Shape_typemap_165;
struct func_8022A94C_S1;
struct func_8022A94C_S1 {
    char pad0[0x8];
    Triple unk8;
    char pad8[0x14 - 0x8 - sizeof(Triple)];
    s32 unk14;
    char pad14[0x5C - 0x14 - sizeof(s32)];
    struct Shape_typemap_165 unk5C;
    char pad5C[0x6C - 0x5C - sizeof(struct Shape_typemap_165)];
    f32 unk6C;
    char pad6C[0x10E - 0x6C - sizeof(f32)];
    u8 unk10E;
    char pad10E[0x2E8 - 0x10E - sizeof(u8)];
    Block unk2E8;
    char pad2E8[0x86C - 0x2E8 - sizeof(Block)];
    s32 unk86C;
    char pad86C[0x11D8 - 0x86C - sizeof(s32)];
    f32 unk11D8;
};

struct ObjectLinks16E4_4;
typedef struct ObjectLinks16E4_4 ObjectLinks16E4_4;

struct SharedRecAt848;
typedef struct SharedRecAt848 SharedRecAt848;

struct SharedRecAt848;
struct SharedRecAt848 {
    char pad0[0x840];
    f32 value;
    char pad844[4];
    s32 override;
};

extern f32 func_8022AA44_de(SharedRecAt848 *arg0);

struct func_8022A274_S2;
struct func_8022A274_S2 {
    char pad0[0x5DC];
    void * unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(void*)];
    void * unk16E0;
};

struct func_8022AA8C_S2;
typedef struct func_8022AA8C_S2 func_8022AA8C_S2;

struct IntegerStateD4;
typedef struct IntegerStateD4 IntegerStateD4;

struct func_8022AA8C_S2;
struct func_8022AA8C_S2 {
    char pad0[0x20];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
};

struct func_8022AE18_S1;
struct func_8022AE18_S1 {
    char pad0[0x8];
    Triple unk8;
    char pad8[0x14 - 0x8 - sizeof(Triple)];
    int unk14;
    char pad14[0x2F0 - 0x14 - sizeof(int)];
    Triple unk2F0;
    char pad2F0[0x2FC - 0x2F0 - sizeof(Triple)];
    int unk2FC;
};

extern float D_800C2D04_de;

struct Player_func_8022ACB8_de;
typedef struct Player_func_8022ACB8_de Player_func_8022ACB8_de;

struct func_8022A82C_S3;
typedef struct func_8022A82C_S3 func_8022A82C_S3;

struct Node_Weapons_EndRound;
struct Node_Weapons_EndRound {
    u8 pad0[0x5D8];
    u8 *state;
    u8 pad5DC[0x280];
    s32 field85C;
    u8 pad860[0xE80];
    struct Node_Weapons_EndRound *next;
};

struct func_8022AA8C_S1;
struct func_8022AA8C_S1 {
    char pad0[0x594];
    s32 unk594;
};

struct func_8022AB10_S1;
struct func_8022AB10_S1 {
    char pad0[0x594];
    s32 unk594;
    char pad594[0x604 - 0x594 - sizeof(s32)];
    s8 unk604;
};

struct IntegerStateD4;
struct IntegerStateD4 {
    unsigned char padding_0[208];
    s32 unk_D0;
};

struct ObjectLinks16E4_4;
struct ObjectLinks16E4_4 {
    char pad0[0x698];
    char * unk_698;
    char pad698[0x16E0 - 0x698 - sizeof(char*)];
    char * unk_16E0;
};

struct func_8022A8B8_S2;
struct func_8022A8B8_S2 {
    char pad0[0x670];
    f32 unk670;
    char pad670[0x16E0 - 0x670 - sizeof(f32)];
    char * unk16E0;
};

extern int func_8022AE28_de(void *arg0, void *arg1);

struct Context;
extern void *func_8022A634_de(struct Context *arg0, u32 arg1);

extern void func_8022A95C_de(void *arg0);

struct func_8022A4F4_S2;
struct func_8022A4F4_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x5E4 - 0x10 - sizeof(f32)];
    s32 unk5E4;
    char pad5E4[0x16E0 - 0x5E4 - sizeof(s32)];
    void * unk16E0;
};

struct func_8022AB8C_S1;
typedef struct func_8022AB8C_S1 func_8022AB8C_S1;

struct ObjRecAtB4;
typedef struct ObjRecAtB4 ObjRecAtB4;

extern float D_800C2CE8_de;

struct func_8022AB8C_S1;
struct func_8022AB8C_S1 {
    char pad0[0x594];
    s32 unk594;
    char pad594[0x62E - 0x594 - sizeof(s32)];
    s16 unk62E;
};

struct IntegerState6C;
struct IntegerState6C {
    char pad0[0x54];
    int unk_54;
    char pad54[0x68 - 0x54 - sizeof(int)];
    int unk_68;
};

struct func_8022A5B0_S2;
struct func_8022A5B0_S2 {
    char pad0[0x698];
    s32 unk698;
    char pad698[0x16E0 - 0x698 - sizeof(s32)];
    char * unk16E0;
};

extern void func_8022A940_de(Shared_Effect *arg0);

struct ObjectLinks16E4_3;
typedef struct ObjectLinks16E4_3 ObjectLinks16E4_3;

extern void func_8022A8C8_de(char *object, f32 arg1);

extern void func_8022A928_de(ObjRecAtB4 *arg0, int arg1);

struct ObjectLinks16E4_3;
struct ObjectLinks16E4_3 {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x16E0 - 0x5D8 - sizeof(char*)];
    void * unk_16E0;
};

struct func_8022A8E0_S2;
struct func_8022A8E0_S2 {
    char pad0[0x5FE];
    s16 unk5FE;
    char pad5FE[0x1450 - 0x5FE - sizeof(s16)];
    s32 unk1450;
    char pad1450[0x16E0 - 0x1450 - sizeof(s32)];
    char * unk16E0;
};

struct func_8022A82C_S3;
struct func_8022A82C_S3 {
    char pad0[0x8F];
    unsigned char unk8F;
    char pad8F[0x90 - 0x8F - sizeof(unsigned char)];
    unsigned char unk90;
};

extern float D_800C2D08_de;

struct func_8022A5B0_S2;
typedef struct func_8022A5B0_S2 func_8022A5B0_S2;

struct func_8022AB10_S1;
typedef struct func_8022AB10_S1 func_8022AB10_S1;

struct Node_Weapons_EndRound;
typedef struct Node_Weapons_EndRound Node_Weapons_EndRound;

struct GlobalState;
typedef struct GlobalState GlobalState;

struct MatchState;

struct func_8022AAC4_S2;
typedef struct func_8022AAC4_S2 func_8022AAC4_S2;

struct MatchState;

struct func_8022A470_S2;
typedef struct func_8022A470_S2 func_8022A470_S2;

struct func_8022A8E0_S2;
typedef struct func_8022A8E0_S2 func_8022A8E0_S2;

struct ObjRecAtB4;
struct ObjRecAtB4 {
    char pad0[0x4];
    int unk4;
    char pad4[0xB4 - 0x4 - sizeof(int)];
    int unkB4;
};

struct ActorCode80225D10;
struct ActorCode80225D10 {
    char pad[0x5F4];
    s16 table[1];
};

struct func_8022A4F4_S2;
typedef struct func_8022A4F4_S2 func_8022A4F4_S2;

struct func_8022AA8C_S1;
typedef struct func_8022AA8C_S1 func_8022AA8C_S1;

struct func_8022A67C_S1;
typedef struct func_8022A67C_S1 func_8022A67C_S1;

struct IntegerState6C;
typedef struct IntegerState6C IntegerState6C;

struct ActorCode80225D10;
typedef struct ActorCode80225D10 ActorCode80225D10;

struct func_8022AE18_S1;
typedef struct func_8022AE18_S1 func_8022AE18_S1;

struct ObjectLinks1454_3;
typedef struct ObjectLinks1454_3 ObjectLinks1454_3;

struct func_8022A94C_S2;
typedef struct func_8022A94C_S2 func_8022A94C_S2;

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
struct func_8022A738_S1;
struct func_8022A738_S1 {
    char pad0[0x20];
    struct Node_Weapons_EndRound * unk20;
};

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
