#include "include_asm.h"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/NAME.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8042E080_12.H"
#include "RENDER_2/8025DE50_5.H"

/* Animates the two menu panels through open, close and countdown states and updates the active team menu. */

extern void func_80298368_de(s32);
extern void MarkMenuEventHandled(void);
extern void func_802A2360_de(void);
extern void func_80419F24_de(void *);
extern void func_80419F58_de(void *, s32);

extern s32 func_80419F38_de(void *);
s32 func_8042F91C_de(s32 unused0, s32 unused1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_v0;
    MenuWidget *temp_a0;
    MenuWidget *temp_a0_2;
    MenuWidget *temp_a1;
    MenuWidget *temp_a1_2;

    if (D_800E28E0 < 2) {
        temp_v0 = D_800E54A4->ready;
        switch (temp_v0) {
        case 1:
            temp_a1 = D_800E54A4->top;
            temp_a1->x = (u16) (temp_a1->x + (u16) D_800E54A4->topStep);
            temp_a1_2 = D_800E54A4->bottom;
            temp_a1_2->x = (u16) (temp_a1_2->x - (u16) D_800E54A4->bottomStep);
            temp_v0_2 = D_800E54A4->timer - 1;
            D_800E54A4->timer = temp_v0_2;
            if (temp_v0_2 <= 0) {
                func_8025DF34_de(0xE79);
                /* unk28 is the panel's item handle, kept untyped in the animation state */
                func_8040E8D8_de((func_8041F2A0_Item *) D_800E54A4->title, 1);
                func_80419F58_de(D_800E54A4->music, 4);
                D_800E54A4->ready = 4;
                D_800E54A4->timer = 4;
            }
            break;
        case 2:
            temp_a0 = D_800E54A4->top;
            temp_a0->x = (u16) (temp_a0->x - (u16) D_800E54A4->topStep);
            temp_a0_2 = D_800E54A4->bottom;
            temp_a0_2->x = (u16) (temp_a0_2->x + (u16) D_800E54A4->bottomStep);
            temp_v0_3 = D_800E54A4->timer - 1;
            D_800E54A4->timer = temp_v0_3;
            if (temp_v0_3 <= 0) {
                D_800E54A4->ready = 3;
                MarkMenuEventHandled();
                func_80298368_de(D_800E54A4->focus);
                return 0;
            }
            break;
        case 3:
            func_802A2360_de();
            break;
        case 4:
            D_800E54A4->timer = RW_CLAMP(D_800E54A4->timer - 1, 0, D_800E54A4->timer);
            if ((D_800E54A4->timer <= 0) && (func_80419F38_de(D_800E54A4->music) != 0)) {
                func_80419F24_de(D_800E54A4->music);
                D_800E54A4->ready = 3;
            }
            break;
        case 5:
            func_8025DF34_de(0xE78);
            D_800E54A4->ready = 2;
            D_800E54A4->timer = 4;
            func_8040E8D8_de((func_8041F2A0_Item *) D_800E54A4->title, 0);
            break;
        }
        if (D_800E54A4->ready == 3) func_80433398_de(arg2);
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC85C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E93EC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EE22C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DDBAC[1] = {
    0x00000000,
};
#endif
