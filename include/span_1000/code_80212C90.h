#include "acmd.h"
#include "audio_callbacks.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
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
#include "types.h"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#ifndef UNBAKE_SPAN_1000_CODE_80212C90_H
#define UNBAKE_SPAN_1000_CODE_80212C90_H
#include "common/types_8a8189af7b05.h"
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

struct func_8021321C_S3;
struct func_8021321C_S3 {
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

extern void func_80212CC4_de(void *arg0);

extern void func_802131AC_de(void *arg0);

struct func_802138F0_S2;
typedef struct func_802138F0_S2 func_802138F0_S2;

struct func_80212D94_S3;
typedef struct func_80212D94_S3 func_80212D94_S3;

struct func_80213500_S7;
typedef struct func_80213500_S7 func_80213500_S7;

extern void func_8021321C_de(void *arg0);

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

extern void func_802136EC_de(void *arg0);

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
    Vec3 position;
    u8 pad14[4];
    s32 *kind;
    Vec3 velocity;
    u8 pad28[0x10];
    s32 flags38;
    u8 pad3c[0x30];
    f32 height;
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

extern void func_80212D94_de(void *arg0);

struct func_80212D94_S3;
struct func_80212D94_S3 {
    char pad0[0x10];
    s32 unk10;
    char pad10[0x64 - 0x10 - sizeof(s32)];
    void * unk64;
};

struct func_8021321C_S3;
typedef struct func_8021321C_S3 func_8021321C_S3;

extern void func_80213810_de(void *arg0);

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

extern void func_80212C90_de(void *arg0);

extern void func_80213500_de(void *arg0);

struct func_8021321C_S5;
typedef struct func_8021321C_S5 func_8021321C_S5;

struct Source;
typedef struct Source Source;

struct func_80213CF8_S1;
struct func_80213CF8_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x18 - 0x8 - sizeof(Vec3)];
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

extern int func_80212D60_de(void * arg0);
extern int func_80212D80_eu(void * arg0);
extern void func_80212D80_eu_x(struct ActorRecAt1D8V2 *arg0);

void func_802131E0_de(Root802131E0 *arg0);

extern f32 func_8024E73C_de(u8 *arg0);

#endif
