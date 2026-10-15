#include "span_16E000/code_804379C8.h"
#include "shared/func_80421E70_eu_closed.h"
#include "types.h"
#include "span_1000/code_80297CD0.h"

/* Releases the object D_800E58A0 holds through func_802547E4_de, clears D_800E58A0 and returns zero. */


extern void func_802547E4_de(void *);

/* Runs the sound options screen D_800E58A0 each frame: when its menu reports 4 it calls
   func_8029973C_de and leaves through func_80298368_de with the stored target or func_802998A8_de when
   that is -1; otherwise it copies the effects slider into option byte D_801462E1, playing sound
   0x460 when it changed, and the music slider into D_801462E0, stopping the music through
   func_8025E2D4_de(0) below 5 or starting track 0x34 when func_8025E2C4_de reports none playing.
   Returns zero. */





extern u8 D_801462E1;

extern s32 func_8041A470_de(void *);

extern s32 func_8041A6E0_de(void *);

extern void func_8029973C_de();

extern void func_80298368_de(s32);


extern void func_8025DF34_de(s32);

extern s32 func_8025E2C4_de(s32);

/* Calls func_8029973C_de; when func_80299A08_de reports 0x73, sets the word at offset 0x14 of the object
   D_800E58A0 points to to -1 and calls func_8041A430_de on its first word with 2. Returns zero. */


s32 func_80438FE0_de(void) {
    extern void *D_800E58A0;
    func_802547E4_de(D_800E58A0);
    D_800E58A0 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80439010_de(void) {
    return 0;
}

s32 func_80439018_de(void) {
    extern struct SoundOptionsScreen *D_800E58A0;
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

s32 func_80439128_de(void) {
    extern struct State_func_80439128_de *D_800E58A0;
    struct State_func_80439128_de *state;
    func_8029973C_de();
#if defined(VERSION_DE)
    if (func_80299A08_de() == 0x71) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (func_80299A08_de() == 0x73) {
#elif defined(VERSION_EU_X)
    if (func_80299A08_de() == 0x77) {
#endif
        state = D_800E58A0;
        state->value = -1;
        func_8041A430_de((s32)state->first, 2);
    }
    return 0;
}
