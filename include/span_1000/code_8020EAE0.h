#include "acmd.h"
#include "audio_callbacks.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "decomp/argb_color.h"
#include "gfx.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028CCB8.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_8028FC98.h"
#include "span_1000/code_802944E8.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B8DD0.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BBC68.h"
#include "span_1000/code_802BE0D0.h"
#include "span_166000/code_80426310.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "span_16E000/code_8041BEA8.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_804251F4.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_8043962C.h"
#include "span_16E000/code_8043E9A8.h"
#include "span_16E000/code_8044ACCC.h"
#include "TYPES.H"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#ifndef UNBAKE_SPAN_1000_CODE_8020EAE0_H
#define UNBAKE_SPAN_1000_CODE_8020EAE0_H
#include "common/draft_fields_func_8020F5A4_de.h"
#include "span_1000/code_8020AF9C.h"
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
struct ObjRecAt28C {
    char pad[0x38];
    s32 count;
    int keys[10];
    char pad64[0x6C - 0x64];
    int flags[10];
    s32 distances[10];
    char padBC[0x28C - 0xBC];
    int current;
};

struct Actor1DC;
struct Actor1DC {
    char pad0[0x1D8];
    char **info;
};

struct RecCode8020EAE0;
typedef struct RecCode8020EAE0 RecCode8020EAE0;

extern s32 func_8020F55C_de(s32 arg0);

extern s32 func_8020F614_de(void);


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

extern s32 func_8020F57C_de(s32 arg0);

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
extern int func_8020EF80_eu(void * arg0);
s32 func_8020EF80_eu_x(PickupGoalObj8020EF60 *arg0);

extern s32 func_80232ABC_de(void *arg0);

#endif
