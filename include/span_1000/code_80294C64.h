#ifndef UNBAKE_SPAN_1000_CODE_80294C64_H
#define UNBAKE_SPAN_1000_CODE_80294C64_H
#include "types.h"
#include "resident_event_handler.h"
#include "common/types_1dc8418c21db.h"
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

extern void func_80295970_us_rev1(void);

extern void func_802955AC_us_rev1(void);

struct func_80295B00_S1;
typedef struct func_80295B00_S1 func_80295B00_S1;

extern int func_802955C8_us_rev1();

extern void func_802958D8_us_rev1(void);

extern void func_802954E0_us_rev1();

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

extern void func_80295924_us_rev1(void);

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

extern int func_80295B00_us_rev1(void);

struct Selection_func_802955EC_us_rev1;
typedef struct Selection_func_802955EC_us_rev1 Selection_func_802955EC_us_rev1;

extern int func_80295B18_us_rev1(void);

struct AnimationInfo;
typedef struct AnimationInfo AnimationInfo;

extern void func_80295E78_de(int *value, int first, int second);

struct func_80295B18_S1;
typedef struct func_80295B18_S1 func_80295B18_S1;

extern void func_80294C50_de(void);

struct AnimationInfo;
struct AnimationInfo {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    void * unk8;
};

extern void func_80295890_us_rev1();

struct RecCode80294C64;
typedef struct RecCode80294C64 RecCode80294C64;

extern void func_80294C84_de(void);
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

#endif
