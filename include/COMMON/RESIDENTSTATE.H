#ifndef COMMON_RESIDENTSTATE_H
#define COMMON_RESIDENTSTATE_H
#include "TYPES.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ResidentState;
struct ResidentState {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct ResidentSlot;

struct ResidentEntry;



struct func_80295B00_S1;
typedef struct func_80295B00_S1 func_80295B00_S1;




typedef struct ResidentState ResidentState;
typedef struct ResidentSlot ResidentSlot;
typedef struct ResidentEntry ResidentEntry;

struct func_802953FC_S1;
struct func_802953FC_S1 {
    char pad0[0x2];
    u8 unk2;
    char pad2[0x3 - 0x2 - sizeof(u8)];
    u8 unk3;
};

struct func_80295B00_S1;
struct func_80295B00_S1 {
    char pad0[0x2];
    unsigned char unk2;
};

struct Selection_func_802955EC_us_rev1;


struct func_802953FC_S1;
typedef struct func_802953FC_S1 func_802953FC_S1;

extern void func_80294F1C_us_rev1();

struct RecCode80294C64;
struct RecCode80294C64 {
    char unk0;
    char pad0[0x1 - 0x0 - sizeof(char)];
    char unk1;
    char pad1[0x4 - 0x1 - sizeof(char)];
    int unk4;
    char pad4[0x8 - 0x4 - sizeof(int)];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x10 - 0xC - sizeof(int)];
    int unk10;
    char pad10[0x14 - 0x10 - sizeof(int)];
    int unk14;
    char pad14[0x1C - 0x14 - sizeof(int)];
    int unk1C;
    char pad1C[0x20 - 0x1C - sizeof(int)];
    int unk20;
    char pad20[0x24 - 0x20 - sizeof(int)];
    int unk24;
    char pad24[0x28 - 0x24 - sizeof(int)];
    int unk28;
    char pad28[0x212C - 0x28 - sizeof(int)];
    int unk212C;
    char pad212C[0x2130 - 0x212C - sizeof(int)];
    int unk2130;
    char pad2130[0x2134 - 0x2130 - sizeof(int)];
    int unk2134;
    char pad2134[0x21B8 - 0x2134 - sizeof(int)];
    int unk21B8;
};

extern ResidentState D_8014AEB8;

struct func_80295B18_S1;
struct func_80295B18_S1 {
    char pad0[0x3];
    char unk3;
};


struct Selection_func_802955EC_us_rev1;
typedef struct Selection_func_802955EC_us_rev1 Selection_func_802955EC_us_rev1;


struct AnimationInfo;
typedef struct AnimationInfo AnimationInfo;


struct func_80295B18_S1;
typedef struct func_80295B18_S1 func_80295B18_S1;


struct AnimationInfo;


struct RecCode80294C64;
typedef struct RecCode80294C64 RecCode80294C64;

struct ResourceData80295B84;
extern void func_80294C8C_de(s32 index, struct ResourceData80295B84 *resource);

extern s32 D_auto_800D2AE8;

extern s32 D_auto_800D2AE4;

extern s32 D_auto_800D2AF4;

extern s32 D_auto_800D2AF8;

extern void func_80294CA0_us_rev1(void);
extern u8 D_800CA60C[0x14];
extern u8 D_auto_800CA620[0x14];
extern f32 D_auto_800CA634;
extern s32 D_auto_800D2AFC;


/* Texture animation metadata returned to material and texture consumers. */
struct Shared_AnimFrame;
typedef struct Shared_AnimInfo {
    s32 count;
    s32 unk4;
    struct Shared_AnimFrame *frame;
} Shared_AnimInfo;


extern void func_802955EC_us_rev1(s32 resource, s32 **data);
extern void func_802956AC_us_rev1(s32 resource, s32 **data);
extern s32 D_8014D070;
extern s32 D_8014D074;
extern s32 D_8014D078;
extern s32 D_8014D07C;
#endif
