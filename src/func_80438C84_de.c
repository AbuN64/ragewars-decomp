#include "span_16E000/code_804379C8.h"
#include "types.h"
/* Runs the screen D_800E5830 each frame until stage 1 of D_800E28E0: on its first frame it marks
   the word at 0x90, passes 0x272 to func_802991D4_de, or 0x273 when func_8040EBD0_de
   reports zero for item 0x273 of the window argument, also 0x272 when D_80146948 is clear, and calls func_802A2360_de; then, once the
   reply pair ending at D_80154024 is marked, it clears the mark and either hides the item at 0x24,
   clears the word at 0x1C0, calls func_8029973C_de and leaves through func_80298368_de with the reply,
   or for a reply of -1 shows the item again and sets 0x1C0 to one. Returns zero. Written from the
   assembly; the conditional tests the zero case first. */
extern s32 D_800E28E0;
extern struct State_func_80438C84_de *D_800E5830;
extern s32 D_80146948;
extern s32 D_80154024;
extern void *func_8040EC30_de(void *, s32);
extern s32 func_8040EBD0_de(void *);
extern void func_802991D4_de(s32);
extern void func_802A2360_de();
extern void func_8040E8D8_de(void *, s32);
extern void func_8029973C_de();
extern void func_80298368_de(s32);
s32 func_80438C84_de(void *window) {
    s32 *pair;
    s32 marked;
    if (D_800E28E0 > 0) {
        return 0;
    }
    if (D_800E5830->started == 0) {
        D_800E5830->started = 1;
#if defined(VERSION_DE)
        func_802991D4_de(func_8040EBD0_de(func_8040EC30_de(window, 0x26F)) == 0 ? 0x26F : 0x26E);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        func_802991D4_de(func_8040EBD0_de(func_8040EC30_de(window, 0x273)) == 0 ? 0x273 : 0x272);
#elif defined(VERSION_EU_X)
        func_802991D4_de(func_8040EBD0_de(func_8040EC30_de(window, 0x278)) == 0 ? 0x278 : 0x277);
#endif
        if (D_80146948 == 0) {
#if defined(VERSION_DE)
            func_802991D4_de(0x26E);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            func_802991D4_de(0x272);
#elif defined(VERSION_EU_X)
            func_802991D4_de(0x277);
#endif
        }
        func_802A2360_de();
    }
    pair = &D_80154024;
    marked = pair[0];
    if (marked == 1) {
        pair[0] = 0;
        if (pair[-1] != -1) {
            func_8040E8D8_de(D_800E5830->item, 0);
            D_800E5830->busy = 0;
            func_8029973C_de();
            func_80298368_de(pair[-1]);
            return 0;
        }
        func_8040E8D8_de(D_800E5830->item, 1);
        D_800E5830->busy = marked;
    }
    return 0;
}
