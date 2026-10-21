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

struct Session;
struct Session {
    char pad0[0x98];
    s32 running;
    s32 mode;
};

extern float D_800C1CFC_de;

extern float D_800C1CF4_de;

struct RecCode8020800080209E80;
typedef struct RecCode8020800080209E80 RecCode8020800080209E80;

struct func_8020A95C_S2;
struct func_8020A95C_S2 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x18 - 0xC - sizeof(s32)];
    s32 unk18;
};

extern float D_800C1CC0_de;

struct SharedRecAt0V1;
typedef struct SharedRecAt0V1 SharedRecAt0V1;

struct func_80209B64_S3;
struct func_80209B64_S3 {
    char pad0[0x28];
    f32 unk28;
};

struct func_8020A028_S2;
typedef struct func_8020A028_S2 func_8020A028_S2;

extern float D_800C1C98_de;

extern float D_800C6E20;

struct Shared_WeaponSlot;
typedef struct Shared_WeaponSlot Shared_WeaponSlot;

struct RecCode8020800080209E80;
struct RecCode8020800080209E80 {
    char pad0[0x594];
    s32 unk594;
    char pad594[0x62E - 0x594 - sizeof(s32)];
    s16 unk62E;
    char pad62E[0x6AC - 0x62E - sizeof(s16)];
    u32 unk6AC;
    char pad6AC[0x6B0 - 0x6AC - sizeof(u32)];
    u32 unk6B0;
    char pad6B0[0x11D8 - 0x6B0 - sizeof(u32)];
    f32 unk11D8;
};

struct func_8020A95C_S1;
typedef struct func_8020A95C_S1 func_8020A95C_S1;

struct func_80209E80_S2;
typedef struct func_80209E80_S2 func_80209E80_S2;

extern float D_800C1CAC_de;

struct func_80209E80_S2;
struct func_80209E80_S2 {
    char pad0[0x240];
    s32 unk240;
};

struct func_80209C5C_S3;
typedef struct func_80209C5C_S3 func_80209C5C_S3;

struct func_80209B64_S1;
struct func_80209B64_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x5D8 - 0x18 - sizeof(void*)];
    void * unk5D8;
};

struct RecCode802080008020A458;
typedef struct RecCode802080008020A458 RecCode802080008020A458;

extern float D_800C1D00_de;

struct func_80209BE0_S3;
struct func_80209BE0_S3 {
    char pad0[0x34];
    f32 unk34;
};

extern float D_800C1D08_de;

struct func_8020A884_S2;
struct func_8020A884_S2 {
    char pad0[0x10];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
};

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

struct Shared_WeaponWorld;
typedef struct Shared_WeaponWorld Shared_WeaponWorld;

extern float D_800C1D1C_de;

extern float D_800C1D28_de;

extern float D_800C1CBC_de;

struct func_8020A458_S2;
struct func_8020A458_S2 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
    char pad28[0x2C - 0x28 - sizeof(s32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s32 unk30;
    char pad30[0x34 - 0x30 - sizeof(s32)];
    s32 unk34;
};

struct RecCode802080008020A028;
struct RecCode802080008020A028 {
    s32 unk0;
    char pad0[0x64 - 0x0 - sizeof(s32)];
    void * unk64;
    char pad64[0x23C - 0x64 - sizeof(void*)];
    s32 unk23C;
    char pad23C[0x240 - 0x23C - sizeof(s32)];
    s32 unk240;
    char pad240[0x2E4 - 0x240 - sizeof(s32)];
    s32 unk2E4;
    char pad2E4[0x2E8 - 0x2E4 - sizeof(s32)];
    s32 unk2E8;
    char pad2E8[0x2EC - 0x2E8 - sizeof(s32)];
    s32 unk2EC;
};

extern float D_800C1C94_de;

struct func_80209B64_S5;
struct func_80209B64_S5 {
    char pad0[0x93];
    s8 unk93;
};

struct RecCode802080008020A884;
struct RecCode802080008020A884 {
    char pad0[0x23C];
    s32 unk23C;
    char pad23C[0x240 - 0x23C - sizeof(s32)];
    s32 unk240;
    char pad240[0x2EC - 0x240 - sizeof(s32)];
    s32 unk2EC;
};

extern float D_800C1D2C_de;

struct RecCode8020800080209DAC;
struct RecCode8020800080209DAC {
    char pad0[0x93];
    func_80209DAC_S2_U93 unk93;
};

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


struct func_80209B64_S3;
typedef struct func_80209B64_S3 func_80209B64_S3;

struct func_8020A028_S2;
struct func_8020A028_S2 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x14 - 0x10 - sizeof(s32)];
    s32 unk14;
    char pad14[0x1C - 0x14 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
};

extern float D_800C6E04;

struct func_8020A6D8_S1;
typedef struct func_8020A6D8_S1 func_8020A6D8_S1;

struct ObjectLinks2EC;
typedef struct ObjectLinks2EC ObjectLinks2EC;

extern float D_800C1D24_de;

struct func_80209DAC_S3;
struct func_80209DAC_S3 {
    char pad0[0x244];
    f32 unk244;
};

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
struct Shared_WeaponWorld;
struct Shared_WeaponWorld {
    char pad0[0x138];
    struct Shared_WeaponSlot * unk138;
    char pad13C[0x4];
    s32 unk140;
};


struct func_8020A6D8_S1;
struct func_8020A6D8_S1 {
    char pad0[0x64];
    void * unk64;
    char pad64[0x23C - 0x64 - sizeof(void*)];
    s32 unk23C;
    char pad23C[0x2E4 - 0x23C - sizeof(s32)];
    s32 unk2E4;
    char pad2E4[0x2E8 - 0x2E4 - sizeof(s32)];
    s32 unk2E8;
};

struct AiController;
struct AiConfig;
extern void func_8020A028_de(struct AiController *arg0, struct AiConfig *arg1);

extern void func_8020A95C_de(void *arg0, void *arg1);

struct RecCode8020800080209DAC;
typedef struct RecCode8020800080209DAC RecCode8020800080209DAC;

extern float D_800C1C90_de;

struct Controls;
typedef struct Controls Controls;

extern float D_800C6E28;

struct func_8020A95C_S2;
typedef struct func_8020A95C_S2 func_8020A95C_S2;

extern float D_800C1CA4_de;

struct func_80209C5C_S3;
struct func_80209C5C_S3 {
    char pad0[0x30];
    f32 unk30;
};

struct IntegerState2C;
typedef struct IntegerState2C IntegerState2C;

struct RecCode802080008020A458;
struct RecCode802080008020A458 {
    char pad0[0x64];
    void * unk64;
    char pad64[0x23C - 0x64 - sizeof(void*)];
    s32 unk23C;
    char pad23C[0x240 - 0x23C - sizeof(s32)];
    s32 unk240;
    char pad240[0x2E4 - 0x240 - sizeof(s32)];
    s32 unk2E4;
    char pad2E4[0x2E8 - 0x2E4 - sizeof(s32)];
    s32 unk2E8;
    char pad2E8[0x2EC - 0x2E8 - sizeof(s32)];
    s32 unk2EC;
};

extern float D_800C1D04_de;

struct RecCode802080008020A884;
typedef struct RecCode802080008020A884 RecCode802080008020A884;

extern float D_800C1CB4_de;

struct RecCode802080008020A028;
typedef struct RecCode802080008020A028 RecCode802080008020A028;

struct func_80209B64_S5;
typedef struct func_80209B64_S5 func_80209B64_S5;

struct func_8020A95C_S1;
struct func_8020A95C_S1 {
    char pad0[0x240];
    s32 unk240;
    char pad240[0x2E4 - 0x240 - sizeof(s32)];
    s32 unk2E4;
    char pad2E4[0x2E8 - 0x2E4 - sizeof(s32)];
    s32 unk2E8;
};

extern void func_8020A458_de(void *arg0, void *arg1);

struct Session;
typedef struct Session Session;

struct func_80209BE0_S3;
typedef struct func_80209BE0_S3 func_80209BE0_S3;

extern void func_8020A2D4_de(ObjectLinks2EC *arg0, IntegerState2C *config);

extern float D_800C6E08;

struct func_8020A884_S2;
typedef struct func_8020A884_S2 func_8020A884_S2;

extern void func_8020A884_de(void *arg0, void *arg1);

struct func_80209B64_S1;
typedef struct func_80209B64_S1 func_80209B64_S1;

struct func_80209DAC_S3;
typedef struct func_80209DAC_S3 func_80209DAC_S3;

extern void func_8020A6D8_de(void *arg0, void *arg1);

struct func_8020A458_S2;
typedef struct func_8020A458_S2 func_8020A458_S2;

extern void func_8020A7B0_de(void *arg0, void *arg1);

extern float D_800C1D0C_de;


#include "COMMON/SHAREDCALLBACK5.H"
typedef struct AiCharacterDefinition {
    u8 pad0[0x28];
    f32 unk28; /* 0x28 */
    f32 unk2C; /* 0x2C */
    f32 unk30; /* 0x30 */
    f32 unk34; /* 0x34 */
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
