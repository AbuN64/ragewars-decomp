#include "include_asm.h"
#include "COMMON/OBJRECAT26DD8.H"
#include "RENDER/802944E8_5.H"

/** Perform the no-op callback at VRAM 0x80294ABC. */
void func_80294AA8_de(void) {
}

#if defined(VERSION_US)
extern s32 D_800E28D8;
extern char D_auto_800D3460[], D_800D4530[];
extern f32 rodata_func_8029499C_us_800C5410;
extern s32 D_80142CA8;
extern void *D_auto_rodata_unresolved_800CD698[];
extern void osViSetMode(void *);
extern void osViSetYScale(f32);
extern void func_802BA700_de(s32);
extern void func_802456A0_de(void);
extern void func_8025E214_de(s32);
extern void func_80264854_de(s32);
#define SCR_W(state, off) (*(s32 *)((char *)(state) + (off)))
/* Per-frame screen step: when the flag at 0x26DD0 is set it switches the video mode (label chosen by D_800E28D8, Y scale from a constant, mode 2); in state 2 of D_80142CA8 with that flag clear it latches 0x26DBC into 0x26DB8, clears 0x26DB0, runs the reset calls and dispatches the 12-byte table row D_auto_rodata_unresolved_800CD698 for that value. */
void func_802949A0_us(char *state) {
    void (*handler)(char *);
    s32 mode;
    if (SCR_W(state, 0x26DD0) != 0) {
        char *label = D_auto_800D3460;
        if (D_800E28D8 == 0) {
            label = D_800D4530;
        }
        osViSetMode(label);
        osViSetYScale(rodata_func_8029499C_us_800C5410);
        func_802BA700_de(2);
    }
    if (D_80142CA8 == 2 && SCR_W(state, 0x26DD0) == 0) {
        mode = SCR_W(state, 0x26DBC);
        SCR_W(state, 0x26DB0) = 0;
        SCR_W(state, 0x26DB8) = mode;
        func_802456A0_de();
        func_8025E214_de(-1);
        func_80264854_de(0);
        handler = (void (*)(char *))D_auto_rodata_unresolved_800CD698[SCR_W(state, 0x26DB8) * 3];
        if (handler != 0) {
            handler(state);
        }
    }
}
#endif
