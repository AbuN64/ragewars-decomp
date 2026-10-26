#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "TYPES.H"

#if defined(VERSION_DE)
#define ID_SCREEN 0x398
#define ID_SCREEN_B 0x399
#define ID_ROW0 0x39F
#define ID_ROW1 0x39E
#define ID_ROW2 0x3A1
#define ID_ROW3 0x39D
#define ID_ROW4 0x39C
#define ID_ROW5 0x3A0
#define ID_WINDOW 0x39A
#define ID_LABEL 0x39B
#elif defined(VERSION_EU_X)
#define ID_SCREEN 0x3A2
#define ID_SCREEN_B 0x3A3
#define ID_ROW0 0x3AB
#define ID_ROW1 0x3A7
#define ID_ROW2 0x3AA
#define ID_ROW3 0x3A8
#define ID_ROW4 0x3A9
#define ID_ROW5 0x3A6
#define ID_WINDOW 0x3A4
#define ID_LABEL 0x3A5
#else
#define ID_SCREEN 0x39E
#define ID_SCREEN_B 0x39F
#define ID_ROW0 0x3A5
#define ID_ROW1 0x3A4
#define ID_ROW2 0x3A7
#define ID_ROW3 0x3A3
#define ID_ROW4 0x3A2
#define ID_ROW5 0x3A6
#define ID_WINDOW 0x3A0
#define ID_LABEL 0x3A1
#endif

extern void func_802A2360_de(void);
extern s32 func_80419E54_de(s32, s32);
extern s32 func_8041A280_de(s32, s32);
extern void func_8041A47C_de(s32);
extern void func_8041B110_de(s32);
extern struct ScreenState *D_800E4450;

/* Builds the screen state D_800E4450: allocates it, opens screen 0x39E, registers six resources, opens window 0x3A0 and stores the 0x3A1 label. */
s32 func_80421AE8_de(s32 root) {
    s32 screen;
    MenuWidget *window;

    /* the hub's allocation helper returns its SelectionScreenState view; this unit keeps its own screen state type */
    D_800E4450 = (struct ScreenState *) Cache_AllocateMemory(0x14);
    func_802A2360_de();
    screen = func_8041A280_de(ID_SCREEN, ID_SCREEN_B);
    D_800E4450->screen = screen;
    func_8041A47C_de(screen);
    func_8041B110_de(ID_ROW0);
    func_8041B110_de(ID_ROW1);
    func_8041B110_de(ID_ROW2);
    func_8041B110_de(ID_ROW3);
    func_8041B110_de(ID_ROW4);
    func_8041B110_de(ID_ROW5);
    window = func_8040EC30_de(root, ID_WINDOW);
    D_800E4450->window = window;
    window->alpha = 0xF;
    D_800E4450->label = func_80419E54_de(ID_LABEL, 0x6E);
    D_800E4450->state = 3;
    return 0;
}
