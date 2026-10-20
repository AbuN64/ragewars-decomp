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
struct ResidentSlot {
    s32 unk0;
    char pad4[0x21A0 - 0x4];
    s32 unk21A0;
};

struct ResidentEntry;
struct ResidentEntry {
    s32 unk0;
    char pad4[0x2010 - 0x4];
    s32 unk2010;
};



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
struct Selection_func_802955EC_us_rev1 {
    s32 value;
    char pad4[12];
    s32 alternative; /* 0x10 */
};


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
struct AnimationInfo {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    void * unk8;
};


struct RecCode80294C64;
typedef struct RecCode80294C64 RecCode80294C64;

struct ResourceData80295B84;
extern void func_80294C8C_de(s32 index, struct ResourceData80295B84 *resource);

extern s32 D_auto_800D2AE8;

extern s32 D_auto_800D2AE4;

extern s32 D_auto_800D2AF4;

extern s32 D_auto_800D2AF8;

struct MenuGlobalRecAt21B8 {
    u8 alternateTitle; /* +0x0 */
    u8 state; /* +0x1 */
    u8 unused0[2];
    s32 field4;
    s32 active; /* +0x8 */
    s32 selectionIndex; /* +0xC: == D_8014AEBC */
    s32 selectionValue; /* +0x10: == D_8014AEC0 */
    s32 titleWasShown; /* +0x14: == D_8014AEC4 */
    u8 unused18[4];
    s32 field1C, field20, field24, field28;
    u8 unused2C[0x212C - 0x2C];
    s32 field212C, field2130, field2134;
    u8 displayData; /* +0x2138 */
    u8 unused2[127]; /* +0x2139 */
    s32 frameCount; /* +0x21B8: == D_8014D068 */
};
struct SelectionRecAt8 {
    s32 index; /* +0x0: == D_8014AEBC */
    s32 value; /* +0x4 */
    s32 changed; /* +0x8: == D_8014AEC4 */
};
extern void func_80294CA0_us_rev1(void);
extern u8 D_800CA60C[0x14];
extern u8 D_auto_800CA620[0x14];
extern f32 D_auto_800CA634;
extern s32 D_auto_800D2AFC;

/* Frontend action mapping selected by D_8014AED0. */
typedef struct FrontendInputSelector {
    u8 mode;
    u8 reserved1;
    u8 primaryButton;
    u8 secondaryButton;
} FrontendInputSelector;

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
