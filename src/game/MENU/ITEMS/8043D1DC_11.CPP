#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "TYPES.H"

extern s32 D_801462C8;
extern s32 D_801462CC;

/* Updates the option item's flag bit and selects its associated text pointer. */
s32 Items_UpdateOptionBit0Item(TextBoundsText *arg0) {
    if (D_801462CC & 1) {
        arg0->flags |= 0x01000000;
    } else {
        arg0->flags &= 0xFEFFFFFF;
    }
    if (D_801462C8 & 1) {
        arg0->text = &D_800D3B0C;
    } else {
        arg0->text = &D_800D3B10;
    }
    return 0;
}

extern s32 D_801462C8;

/* Toggles bit 1 of the settings flag word D_801462C8 and returns 0. */
s32 Items_ToggleOptionBit1(void) {
    D_801462C8 ^= 2;
    return 0;
}

#if !(defined(VERSION_US_REV1))
s32 Items_UpdateOptionBit1Item(TextBoundsText *item) {
    extern s32 D_801462C8, D_801462CC;
    extern s32 D_800D3B14, D_800D3B18;
    if (D_801462CC & 2) item->flags |= 0x01000000; else item->flags &= 0xFEFFFFFF;
    if (D_801462C8 & 2) item->text = &D_800D3B14; else item->text = &D_800D3B18;
    return 0;
}
#endif
