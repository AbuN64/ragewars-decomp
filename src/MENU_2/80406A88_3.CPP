#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct EuxDrawScreen { void *window; s32 unk4; void *roots[3]; s32 unk14; s32 unk18; s32 count; } EuxDrawScreen;
typedef struct { u8 pad0[0x10]; u8 alpha; } EuxDrawItem;
extern EuxDrawScreen *D_800E39C0;
extern void *func_8025305C_de(s32);
extern s32 func_8041B610_de(void *, s32);
extern void func_8041B6E8_de(void *, s32, s32);
extern void *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(void *, s32);
extern s32 func_802999A0_de(s32);
extern s32 func_8041EB50_de(void);
extern void func_8041E408_de(s32);
extern void func_802A2360_de(void);
/* Builds the pak-draw selection screen: allocates its 0x20-byte state, creates the four rows, hides the pointer item
   when the pad answer is 0x16, collects the three root items and hides their cursors, then shows the cursor of the
   current root. Returns 0. */
s32 func_8041E3A0_eu_x(void *window) {
    EuxDrawScreen *screen;
    EuxDrawItem *item;
    s32 i;

    screen = func_8025305C_de(0x20);
    D_800E39C0 = screen;
    screen->window = window;
    D_800E39C0->unk4 = func_8041B610_de(window, 4);
    func_8041B6E8_de(window, 0, 0x38D);
    func_8041B6E8_de(window, 1, 0x38D);
    func_8041B6E8_de(window, 2, 0x38D);
    func_8041B6E8_de(window, 3, 0x38D);
    item = func_8040EC30_de(window, 0x38F);
    item->alpha = 0x8C;
    if (func_802999A0_de(0) == 0x16) {
        func_8040E8D8_de(item, 0);
    }
    D_800E39C0->unk14 = 0;
    D_800E39C0->unk18 = 0;
    D_800E39C0->roots[0] = func_8040EC30_de(window, 0x390);
    D_800E39C0->roots[1] = func_8040EC30_de(window, 0x399);
    D_800E39C0->roots[2] = func_8040EC30_de(window, 0x39A);
    D_800E39C0->count = func_8041EB50_de();
    for (i = 0; i < 3; i++) {
        func_8041E408_de(i);
        func_8040E8D8_de(func_8040EC30_de(D_800E39C0->roots[i], 0x396), 0);
    }
    func_802A2360_de();
    func_8040E8D8_de(func_8040EC30_de(D_800E39C0->roots[D_800E39C0->unk14], 0x396), 1);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8041E3A0_eu_x);
#endif
#endif
