#ifndef COMMON_OBJECTLINKS1458_H
#define COMMON_OBJECTLINKS1458_H
#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
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
#include "COMMON/MEASUREDRECAT62EV1.H"
#include "COMMON/OBJECTLINKS14.H"
struct func_8020F93C_S1;
typedef struct func_8020F93C_S1 func_8020F93C_S1;

struct func_8020F444_S3;
typedef struct func_8020F444_S3 func_8020F444_S3;



extern float D_800C1EE4_de;

struct ObjectLinks1458;
struct ObjectLinks1458 {
    char pad0[0x1454];
    char * unk_1454;
};

struct func_8020F444_S2;
typedef struct func_8020F444_S2 func_8020F444_S2;

struct ObjectLinks1458;
typedef struct ObjectLinks1458 ObjectLinks1458;


struct func_8020F150_S1;
struct func_8020F150_S1 {
    char pad0[0x24];
    struct Node8020BC50 * unk24;
};

struct Actor1DC;
typedef struct Actor1DC Actor1DC;

struct func_8020F93C_S1;
struct func_8020F93C_S1 {
    char pad0[0x38];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x6C - 0x3C - sizeof(s32)];
    s32 unk6C;
};

struct RecCode8020EAE0;
struct RecCode8020EAE0 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x14 - 0xC - sizeof(s32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
    char pad18[0x28 - 0x18 - sizeof(s32)];
    s32 unk28;
    char pad28[0x1BC - 0x28 - sizeof(s32)];
    s32 unk1BC;
    char pad1BC[0x1C0 - 0x1BC - sizeof(s32)];
    s32 unk1C0;
    char pad1C0[0x2F4 - 0x1C0 - sizeof(s32)];
    s32 unk2F4;
    char pad2F4[0x2F8 - 0x2F4 - sizeof(s32)];
    s32 unk2F8;
    char pad2F8[0x2FC - 0x2F8 - sizeof(s32)];
    s32 unk2FC;
};

struct func_8020EE50_S1;
typedef struct func_8020EE50_S1 func_8020EE50_S1;

struct ObjectLinks40;
typedef struct ObjectLinks40 ObjectLinks40;

struct func_8020EEA4_S2;
struct func_8020EEA4_S2 {
    char pad0[0xC];
    u16 unkC;
    char padC[0xE - 0xC - sizeof(u16)];
    u16 unkE;
};

struct func_8020F444_S3;
struct func_8020F444_S3 {
    char pad0[0x1A4];
    s8 unk1A4;
};

struct ObjRecAt28C;

struct Actor1DC;
struct Actor1DC {
    char pad0[0x1D8];
    char **info;
};

struct RecCode8020EAE0;
typedef struct RecCode8020EAE0 RecCode8020EAE0;




struct Func8020ED50Arg;
struct Func8020ED50Arg {
    char pad0[4];
    s32 field4;
    char pad8[4];
    s32 fieldC;
    s32 field10;
    s32 links[4]; /* 0x14 */
    char pad24[4];
    s32 committed; /* 0x28 */
    char pad2C[0x1BC - 0x2C];
    s32 linkState;
    s32 selection;
    char pad1C4[0x2F4 - 0x1C4];
    s32 releaseFlags[3];
};


struct func_8020EE50_S1;
struct func_8020EE50_S1 {
    char pad0[0x10];
    void * unk10;
    char pad10[0x18 - 0x10 - sizeof(void*)];
    f32 unk18;
    char pad18[0x38 - 0x18 - sizeof(f32)];
    s32 unk38;
};

struct Func8020ED50Arg;
typedef struct Func8020ED50Arg Func8020ED50Arg;



struct func_8020F2A8_S1;
struct func_8020F2A8_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x14 - 0xC - sizeof(s32)];
    char unk14;
    char pad14[0x68 - 0x14 - sizeof(char)];
    s32 unk68;
    char pad68[0xBC - 0x68 - sizeof(s32)];
    s32 unkBC;
};

struct func_8020F150_S1;
typedef struct func_8020F150_S1 func_8020F150_S1;

struct func_8020F984_S2;
struct func_8020F984_S2 {
    char pad0[0x38];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    void * unk3C;
    char pad3C[0x6C - 0x3C - sizeof(void*)];
    s32 unk6C;
    char pad6C[0x94 - 0x6C - sizeof(s32)];
    s32 unk94;
};

struct ObjRecAt28C;
typedef struct ObjRecAt28C ObjRecAt28C;

extern float D_800C1EE0_de;



struct func_8020F984_S2;
typedef struct func_8020F984_S2 func_8020F984_S2;

struct func_8020EEA4_S3;
struct func_8020EEA4_S3 {
    char pad0[0x10];
    void * unk10;
    char pad10[0x18 - 0x10 - sizeof(void*)];
    f32 unk18;
};

struct func_8020EEA4_S2;
typedef struct func_8020EEA4_S2 func_8020EEA4_S2;

struct func_8020F2A8_S1;
typedef struct func_8020F2A8_S1 func_8020F2A8_S1;

extern float D_800C1EDC_de;

struct ObjectLinks40;
struct ObjectLinks40 {
    unsigned char padding_0[60];
    Actor1DC *unk_3C;
};

struct func_8020F444_S2;
struct func_8020F444_S2 {
    char pad0[0x10];
    void * unk10;
    char pad10[0x34 - 0x10 - sizeof(void*)];
    void * unk34;
};

struct func_8020EEA4_S3;
typedef struct func_8020EEA4_S3 func_8020EEA4_S3;

extern int func_8020EF60_us(void * arg0);

extern s32 func_80232ABC_de(void *arg0);
#endif
