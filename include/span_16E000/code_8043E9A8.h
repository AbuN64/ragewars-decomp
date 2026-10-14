#ifndef UNBAKE_SPAN_16E000_CODE_8043E9A8_H
#define UNBAKE_SPAN_16E000_CODE_8043E9A8_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
extern s32 func_8043EA4C_de(void *arg0, Outer8043E56C *arg1);

extern signed char D_801422C1;

struct PlayerRecAt64E;
struct PlayerRecAt64E {
    char pad[0x644];
    u8 flags[9];
    u8 count64D;
    u8 count64E;
};

struct Holder_func_8043F048_de;
struct PlayerRecAt64E;
struct Holder_func_8043F048_de {
    char pad[0x1C];
    struct PlayerRecAt64E *player;
    char pad20[0x30 - 0x20];
    f32 fade;
    f32 alpha;
};

struct Flagged;
struct Flagged {
    u8 pad0[0x58];
    u32 unk58;
};
struct Flagged;
struct Obj8043ECE8;
struct Obj8043ECE8 {
    s16 unk0;
    u8 pad2[10];
    struct Flagged *unkC;
};

extern s32 func_8043ED48_de(void);

struct ItemDef;
struct ItemDef {
    char pad[0x20];
    s16 type;
    s16 index;
};

struct ItemDef;
struct ItemRecAt18V2;
struct ItemRecAt18V2 {
    char pad[0x14];
    s32 resource;
    struct ItemDef *def;
};

extern s32 func_8043EA00_de(void *arg0, Arg1Struct *arg1);

struct Obj8043EB20;
typedef struct Obj8043EB20 Obj8043EB20;

struct ObjRecAt20V2;
extern void func_8043EA98_de(void *arg0, struct ObjRecAt20V2 *menu);

struct Globals_func_8043EA98_de;
struct Player_func_8041EAC4_de;
struct Globals_func_8043EA98_de {
    char pad0[0x1D];
    u8 flag1D;
    u8 flag1E;
    char pad1F[0xD0 - 0x1F];
    struct Player_func_8041EAC4_de status[8];
};

struct Inner8043E56C;
typedef struct Inner8043E56C Inner8043E56C;

struct Obj8043EB20;
struct Obj8043EB20 {
    u8 pad0[0x1C];
    s32 unk1C;
    Inner8043E56C *unk20;
};

struct Obj8043ECE8;
typedef struct Obj8043ECE8 Obj8043ECE8;

extern void func_8043F040_de(void);

struct Player_func_8043EBE4_de;
struct Player_func_8043EBE4_de {
    u8 flag;
    u8 data[149];
};

struct Options_func_8043EBE4_de;
struct Player_func_8043EBE4_de;
struct Options_func_8043EBE4_de {
    char pad0[0x1D];
    u8 first;
    u8 second;
    char pad1F[0x2D - 0x1F];
    u8 toggles[7]; /* 0x2D..0x33: menu checkbox flags */
    char pad34;
    u8 extraToggle; /* 0x35 */
    char pad36[0x148 - 0x36];
    struct Player_func_8043EBE4_de players[8];
};

struct Shared_PakMenu;
extern void func_8043E948_de(struct Shared_PakMenu *arg0);

extern s32 func_8043E9A8_de(void *arg0, Obj8043EB20 *arg1);

extern s32 func_8043EDDC_de(void);

extern s32 func_8043ED50_de(void);

extern void func_8043E97C_de(void *arg0);
extern f32 D_800E23A0[2];
extern f32 D_800E23A8;

extern char D_800DE380[];
extern char D_800DE388_de[];
extern char D_800DE390_de[];
extern char D_8014DE10[];
extern char D_8014DDD0[];

#endif
