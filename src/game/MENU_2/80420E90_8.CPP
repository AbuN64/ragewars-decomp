#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "TYPES.H"

#if (defined(VERSION_EU) || defined(VERSION_EU_X)) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_80400000", func_80420E20_de);
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
/* Fuzzy draft in EU and EU-X: their body differs. */
/* Opens the options screen: allocates its 0x3C-byte state into D_800E4400 for window arg0, builds
   its title, heading and the four toggle buttons 0x3B4, 0x3B1, 0x3AD and 0x3AF set from bits of
   D_801462C8, creates the item list and refreshes the limit markers through func_80421234_de. */

extern struct OptionsOpenScreen *D_800E4400;
extern s32 D_801462C8;

/* The hub spells the allocator, the window item lookup and the list builder; these helpers stay. */
extern void *func_8041A280_de(s32, s32);
extern void func_8041B110_de(s32);
extern void *func_8041ABC0_de(s32, s32);
extern void Menu_AppendListText(void *, void *);
extern void Menu_SelectListEntry(void *, s32);
extern void func_80421234_de(void);

#if defined(VERSION_DE)
#define ID(n) ((n) - 6)
#define COLOR 0x86
#else
#define ID(n) (n)
#define COLOR 0x88
#endif
s32 func_80420E20_de(void *window) {
    struct OptionsOpenScreen *screen;
    void *button;

    screen = (struct OptionsOpenScreen *) Scene_AllocateMemory(0x3C);
    D_800E4400 = screen;
    screen->window = window;
    screen->full = 0;
    /* the hub's item type carries no color; this unit's options view names the byte at +0x1A */
    ((OptionsOpenItem *) func_8040EC30_de(window, ID(0x3A8)))->color = COLOR;
    D_800E4400->title = func_8041A280_de(ID(0x3A8), ID(0x3A9));
    func_8041B110_de(ID(0x3B6));

    button = func_8041ABC0_de(ID(0x3B4), ID(0x3B5));
    D_800E4400->buttons[0] = button;
    Menu_AppendListText(button, D_800D3470_de[0]);
    Menu_AppendListText(D_800E4400->buttons[0], D_800D3474[0]);
    if (D_801462C8 & 0x8000000) {
        Menu_SelectListEntry(D_800E4400->buttons[0], 1);
    } else {
        Menu_SelectListEntry(D_800E4400->buttons[0], 0);
    }

    button = func_8041ABC0_de(ID(0x3B1), ID(0x3B2));
    D_800E4400->buttons[1] = button;
    Menu_AppendListText(button, D_800D3470_de[0]);
    Menu_AppendListText(D_800E4400->buttons[1], D_800D3474[0]);
    if (D_801462C8 & 0x10000000) {
        Menu_SelectListEntry(D_800E4400->buttons[1], 1);
    } else {
        Menu_SelectListEntry(D_800E4400->buttons[1], 0);
    }

    button = func_8041ABC0_de(ID(0x3AD), ID(0x3AE));
    D_800E4400->buttons[2] = button;
    Menu_AppendListText(button, D_800D3470_de[0]);
    Menu_AppendListText(D_800E4400->buttons[2], D_800D3474[0]);
    if (D_801462C8 & 0x8) {
        Menu_SelectListEntry(D_800E4400->buttons[2], 1);
    } else {
        Menu_SelectListEntry(D_800E4400->buttons[2], 0);
    }

    button = func_8041ABC0_de(ID(0x3AF), ID(0x3B0));
    D_800E4400->buttons[3] = button;
    Menu_AppendListText(button, D_800D3470_de[0]);
    Menu_AppendListText(D_800E4400->buttons[3], D_800D3474[0]);
    if (D_801462C8 & 0x20000000) {
        Menu_SelectListEntry(D_800E4400->buttons[3], 1);
    } else {
        Menu_SelectListEntry(D_800E4400->buttons[3], 0);
    }

    func_8041B110_de(ID(0x3AC));
    D_800E4400->cursor = (OptionsOpenItem *) func_8040EC30_de(window, ID(0x3B7));
    D_800E4400->unk_28 = 0;
    D_800E4400->unk_2C = 0;
    D_800E4400->unk_34 = 1;
    /* the hub publishes the list builder as returning the word naming the list; the member stores it */
    D_800E4400->list = (void *) func_80419E54_de(ID(0x3AA), 0x6E);
    func_80421234_de();
    return 0;
}
#endif
