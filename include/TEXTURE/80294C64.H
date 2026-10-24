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
/* Frontend action mapping selected by D_8014AED0. */
typedef struct FrontendInputSelector {
    u8 mode;
    u8 reserved1;
    u8 primaryButton;
    u8 secondaryButton;
} FrontendInputSelector;
struct Node80253610;
/* The us-rev1 resident texture menu state (D_8014AEB0, 0x21BC bytes): func_802954E0_us_rev1 clears it,
   func_80294CA0_us_rev1 loads the selected entry and func_80294F1C_us_rev1 steps the selection. */
struct MenuGlobalRecAt21B8 {
    u8 alternateTitle; /* +0x0 */
    u8 state; /* +0x1 */
    u8 unused0[2];
    s32 field4;
    s32 active; /* +0x8: item count, the selection modulus */
    s32 selectionIndex; /* +0xC */
    s32 selectionValue; /* +0x10 */
    s32 titleWasShown; /* +0x14: set when the selection changed */
    s32 overridesOff; /* +0x18: no texture or palette override while set */
    struct Node80253610 *resource; /* +0x1C: the loaded entry */
    FrontendInputSelector *selector; /* +0x20 */
    s32 *textureOverride; /* +0x24 */
    s32 *paletteOverride; /* +0x28 */
    s32 textureData[0x2000 / 4]; /* +0x2C */
    s32 paletteData[0x100 / 4]; /* +0x202C */
    s32 *entryTable; /* +0x212C */
    s32 *textureTable; /* +0x2130 */
    s32 *paletteTable; /* +0x2134 */
    char displayData[0x80]; /* +0x2138 */
    s32 frameCount; /* +0x21B8 */
};
extern struct MenuGlobalRecAt21B8 D_8014AEB0;
struct SelectionRecAt8 {
    s32 index; /* +0x0: == D_8014AEBC */
    s32 value; /* +0x4 */
    s32 changed; /* +0x8: == D_8014AEC4 */
};
extern void func_80294C50_de(void);
extern void func_80294C84_de(void);
#endif
