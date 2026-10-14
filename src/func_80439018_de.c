#include "span_16E000/code_804379C8.h"
#include "types.h"

/* Runs the sound options screen D_800E58A0 each frame: when its menu reports 4 it calls
   func_8029973C_de and leaves through func_80298368_de with the stored target or func_802998A8_de when
   that is -1; otherwise it copies the effects slider into option byte D_801462E1, playing sound
   0x460 when it changed, and the music slider into D_801462E0, stopping the music through
   func_8025E2D4_de(0) below 5 or starting track 0x34 when func_8025E2C4_de reports none playing.
   Returns zero. */



extern struct State_func_80439018_de *D_800E58A0;
extern u8 D_801462E1;
extern s32 func_8041A470_de(void *);
extern s32 func_8041A6E0_de(void *);
extern void func_8029973C_de();
extern void func_80298368_de(s32);
extern void func_802998A8_de();
extern void func_8025DF34_de(s32);
extern s32 func_8025E2C4_de(s32);


s32 func_80439018_de(void) {
    u8 *options;
    s32 value;
    s32 track;

    switch (func_8041A470_de(D_800E58A0->menu)) {
    case 3:
        break;
    case 4:
        func_8029973C_de();
        if (D_800E58A0->target != -1) {
            func_80298368_de(D_800E58A0->target);
            return 0;
        }
        func_802998A8_de();
        return 0;
    }
    value = func_8041A6E0_de(D_800E58A0->effects);
    options = &D_801462E1;
    if (value != options[0]) {
        options[0] = value;
        func_8025DF34_de(0x460);
    }
    value = func_8041A6E0_de(D_800E58A0->music);
    if (value != options[-1]) {
        options[-1] = value;
        track = 0;
        if ((u8)value >= 5) {
            if (func_8025E2C4_de(0) != 0) {
                return 0;
            }
            track = 0x34;
        }
        func_8025E2D4_de(track);
    }
    return 0;
}
