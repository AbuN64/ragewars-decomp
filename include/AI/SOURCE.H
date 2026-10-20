#ifndef AI_SOURCE_H
#define AI_SOURCE_H
#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARGB_COLOR.H"
#include "COMMON/GFX.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/MANAGER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/MTX.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/RESULTS.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/ALDELAY28.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/CTX.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/LABEL.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/S1_5.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/SHAREDPLAYER.H"
extern float D_800C2100_de;

extern double D_800C2108_de;

extern double D_800C2110_de;

struct func_80213500_S7;
struct func_80213500_S7 {
    char pad0[0x38];
    s32 unk38;
    char pad38[0x650 - 0x38 - sizeof(s32)];
    s16 unk650;
    char pad650[0x6B0 - 0x650 - sizeof(s16)];
    s32 unk6B0;
};

extern float D_800C20F0_de;

struct RecCode80212C90;
struct RecCode80212C90 {
    char pad0[0x38];
    u32 unk38;
    char pad38[0x5D8 - 0x38 - sizeof(u32)];
    void * unk5D8;
    char pad5D8[0x650 - 0x5D8 - sizeof(void*)];
    s16 unk650;
    char pad650[0x6B0 - 0x650 - sizeof(s16)];
    u32 unk6B0;
};

struct func_802136EC_S3;
struct func_802136EC_S3 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x220 - 0xC - sizeof(s32)];
    s32 unk220;
    char pad220[0x22C - 0x220 - sizeof(s32)];
    s32 unk22C;
    char pad22C[0x320 - 0x22C - sizeof(s32)];
    s32 unk320;
};

extern float D_800C2124_de;

struct func_80213340_S2;
struct func_80213340_S2 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x22C - 0xC - sizeof(s32)];
    s32 unk22C;
};

struct func_80213340_S2;
typedef struct func_80213340_S2 func_80213340_S2;

struct AiTarget;


struct func_802138F0_S2;
typedef struct func_802138F0_S2 func_802138F0_S2;

struct func_80212D94_S3;
typedef struct func_80212D94_S3 func_80212D94_S3;

struct func_80213500_S7;
typedef struct func_80213500_S7 func_80213500_S7;


union func_802138F0_S2_U18;
typedef union func_802138F0_S2_U18 func_802138F0_S2_U18;

struct func_802138F0_S1;
typedef struct func_802138F0_S1 func_802138F0_S1;

struct func_802138F0_S1;
struct func_802138F0_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s8 unk10;
    char pad10[0xCC - 0x10 - sizeof(s8)];
    s8 unkCC;
    char padCC[0x100 - 0xCC - sizeof(s8)];
    u8 unk100;
    char pad100[0x102 - 0x100 - sizeof(u8)];
    s16 unk102;
};


union func_802138F0_S2_U18;
union func_802138F0_S2_U18 {
    s32 v0;
    s16 v1;
};

struct func_802138F0_S2;
struct func_802138F0_S2 {
    char pad0[0xE];
    s8 unkE;
    char padE[0x10 - 0xE - sizeof(s8)];
    s8 unk10;
    char pad10[0x12 - 0x10 - sizeof(s8)];
    s8 unk12;
    char pad12[0x18 - 0x12 - sizeof(s8)];
    func_802138F0_S2_U18 unk18;
    char pad18[0x40 - 0x18 - sizeof(func_802138F0_S2_U18)];
    u8 unk40;
    char pad40[0x41 - 0x40 - sizeof(u8)];
    u8 unk41;
};

struct Source;
struct Source {
    u8 pad0[8];
    CVector3 position;
    void *surface; /* +0x14: func_80213AAC_us_rev1 ground query */
    s32 *kind;
    CVector3 velocity;
    u8 pad28[0x10];
    s32 flags38;
    u8 pad3c[0x30];
    f32 height;
    u8 reserved070[0x90];
    u32 flags; /* +0x100; probe 20261019T012702233005Z */
};

struct func_80213500_S3;
typedef struct func_80213500_S3 func_80213500_S3;

struct func_80213CF8_S1;
typedef struct func_80213CF8_S1 func_80213CF8_S1;

extern int D_8013B368;

extern float D_800C2120_de;

struct IntegerState23C;
struct IntegerState23C {
    unsigned char padding_0[104];
    s32 unk_68;
    unsigned char padding_6C[436];
    s32 unk_220;
    unsigned char padding_224[20];
    s32 unk_238;
};

extern float D_800C2118_de;


struct func_80212D94_S3;
struct func_80212D94_S3 {
    char pad0[0x10];
    s32 unk10;
    char pad10[0x64 - 0x10 - sizeof(s32)];
    void * unk64;
};

struct RecCode80212C90;
typedef struct RecCode80212C90 RecCode80212C90;


struct IntegerState23C;
typedef struct IntegerState23C IntegerState23C;

struct func_80213500_S3;
struct func_80213500_S3 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x22C - 0xC - sizeof(s32)];
    s32 unk22C;
    char pad22C[0x314 - 0x22C - sizeof(s32)];
    s32 unk314;
    char pad314[0x320 - 0x314 - sizeof(s32)];
    s32 unk320;
};



struct func_8021321C_S5;
typedef struct func_8021321C_S5 func_8021321C_S5;

struct Source;
typedef struct Source Source;

struct func_80213CF8_S1;
struct func_80213CF8_S1 {
    char pad0[0x8];
    CVector3 unk8;
    char pad8[0x18 - 0x8 - sizeof(CVector3)];
    s32 * unk18;
};

struct func_8021321C_S5;
struct func_8021321C_S5 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x320 - 0xC - sizeof(s32)];
    s32 unk320;
};

struct func_802136EC_S3;
typedef struct func_802136EC_S3 func_802136EC_S3;



extern f32 func_8024E73C_de(u8 *arg0);
#endif
