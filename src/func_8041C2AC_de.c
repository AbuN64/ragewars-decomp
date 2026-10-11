#include "span_16E000/code_8041BEA8.h"
#include "types.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
/* Builds screen state D_800E3518 under a parent window: allocates its 0x2C bytes, keeps the parent,
   opens windows 0x3C3 (shown), 0x3C9, 0x3C4 and 0x3C5 (hidden) at 0x4 to 0x10, clears the words at
   0x14 and 0x18, resets through func_8040C428_de(0) and func_802A2394_de, sets D_800E28C8 to -1 and
   D_80146D70 to 0, releases the resources of D_8011FAC0 and of its block at 0x3C8, clears the
   word at 0x1C and returns zero. */
extern struct Screen_func_8041C2AC_de *D_800E3518;
extern s32 D_800E28C8;
extern s32 D_80146D70;
extern char D_8011FAC0[];
extern void func_8040C428_de(s32);
extern void func_802A2394_de(void);
extern void func_80293334_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
s32 func_8041C2AC_de(void *parent) {
    void *window;
    char *resources;
    D_800E3518 = func_8025305C_de(0x2C);
    D_800E3518->parent = parent;
#if defined(VERSION_DE)
    window = func_8040EC30_de(parent, 0x3BE);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = func_8040EC30_de(parent, 0x3C3);
#elif defined(VERSION_EU_X)
    window = func_8040EC30_de(parent, 0x3CC);
#endif
    D_800E3518->windows[0] = window;
    func_8040E8D8_de(window, 1);
#if defined(VERSION_DE)
    window = func_8040EC30_de(parent, 0x3C3);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = func_8040EC30_de(parent, 0x3C9);
#elif defined(VERSION_EU_X)
    window = func_8040EC30_de(parent, 0x3CD);
#endif
    D_800E3518->windows[1] = window;
    func_8040E8D8_de(window, 0);
#if defined(VERSION_DE)
    window = func_8040EC30_de(parent, 0x3BD);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = func_8040EC30_de(parent, 0x3C4);
#elif defined(VERSION_EU_X)
    window = func_8040EC30_de(parent, 0x3C6);
#endif
    D_800E3518->windows[2] = window;
    func_8040E8D8_de(window, 0);
#if defined(VERSION_DE)
    window = func_8040EC30_de(parent, 0x3BF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    window = func_8040EC30_de(parent, 0x3C5);
#elif defined(VERSION_EU_X)
    window = func_8040EC30_de(parent, 0x3C8);
#endif
    D_800E3518->windows[3] = window;
    func_8040E8D8_de(window, 0);
    D_800E3518->selection = 0;
    D_800E3518->scroll = 0;
    func_8040C428_de(0);
    func_802A2394_de();
    D_800E28C8 = -1;
    D_80146D70 = 0;
    resources = D_8011FAC0;
    func_80293334_de(resources, 0, 0);
    func_80286AA8_de(resources + 0x3C8, 0, 0);
    D_800E3518->state = 0;
    return 0;
}
