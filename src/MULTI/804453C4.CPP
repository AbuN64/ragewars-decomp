#include "include_asm.h"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "MULTI/804453C4.H"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
/* Steps a menu spinner for the entry func_8022A5A0_de finds in D_80145040: advances its repeat timer by D_800D2988, wrapping at D_800E2810, and while the menu is active (state 1) decrements its value above zero when func_80264388_de reports the decrease input, or else increments it below its maximum when func_802643A0_de reports the increase input, restarting the timer on a change. Returns zero. */




extern char D_80145040[];
extern Spinner D_800E63C0[];

extern s32 func_8022A5A0_de(char *, s32);



s32 func_80445964_de(void *unused, MenuRecAt20V1 *menu) {
    s32 i;
    f32 t;

    i = func_8022A5A0_de(D_80145040, menu->id);
    t = D_800E63C0[i].timer + D_800D2988;
    D_800E63C0[i].timer = t;
    if (t >= (15.0f)) {
        D_800E63C0[i].timer = t - (15.0f);
    }
    if (menu->state == 1) {
        if (((s32 (*)(s32))func_80264388_de)(menu->input) != 0 && D_800E63C0[i].value > 0) {
            D_800E63C0[i].value--;
            D_800E63C0[i].timer = 0.0f;
        } else if (((s32 (*)(s32))func_802643A0_de)(menu->input) != 0) {
            if (D_800E63C0[i].value < D_800E63C0[i].max) {
                D_800E63C0[i].value++;
                D_800E63C0[i].timer = 0.0f;
            }
        }
    }
    return 0;
}
#endif

#if defined(VERSION_US_REV1)
INCLUDE_RODATA("data_800C", rodata_func_80445964_de_800E2810);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_ASM("ovl_80400000", func_80446330_us_rev1);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_ASM("ovl_80400000", func_80445964_de);
#endif
