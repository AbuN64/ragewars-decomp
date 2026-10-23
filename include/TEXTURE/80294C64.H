#ifndef TEXTURE_80294C64_H
#define TEXTURE_80294C64_H
#include "COMMON/RESIDENTSTATE.H"
struct ResidentSlot {
    s32 unk0;
    char pad4[0x21A0 - 0x4];
    s32 unk21A0;
};
struct ResidentEntry {
    s32 unk0;
    char pad4[0x2010 - 0x4];
    s32 unk2010;
};
struct Selection_func_802955EC_us_rev1 {
    s32 value;
    char pad4[12];
    s32 alternative; /* 0x10 */
};
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
/* Frontend action mapping selected by D_8014AED0. */
typedef struct FrontendInputSelector {
    u8 mode;
    u8 reserved1;
    u8 primaryButton;
    u8 secondaryButton;
} FrontendInputSelector;
extern void func_80294C50_de(void);
extern void func_80294C84_de(void);
#endif
