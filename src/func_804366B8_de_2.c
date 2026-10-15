#include "span_16E000/code_804366C4.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_80421E70_eu_closed.h"
#include "types.h"
#include "common/unused.h"
#include "shared/func_804235A8_eu_closed.h"
#include "span_1000/code_80297CD0.h"

/* Stores arg0 into its own D_80146417 entry and pushes the five settings of slot arg0 of the D_80102C89 table into the objects D_800E5694 holds through func_8041AD10_de and func_8041A6EC_de. Adapted from func_804366B8_de with D_800E5690 changed to D_800E5694 and the object fields moved down by eight bytes. */


extern struct State_func_804368F8_de *D_800E5694;


extern u8 D_800FEC8A[];

extern u8 D_800FEC8B[];

extern u8 D_800FEC8C[];

extern u8 D_800FEC8D[];


extern void func_8041AD10_de(void *, s32);

extern void func_8041A6EC_de(void *, s32);

extern u8 D_80146398[];

extern s32 func_8041AD04_de(void *);

extern s32 func_8041A6E0_de(void *);

/* Releases the object D_800E5690 holds through func_802547E4_de, clears D_800E5690 and returns zero. */


extern void func_802547E4_de(void *);

/* Acts on the mode of the menu held first in the block D_800E5690 points to: in mode 4 it calls
   func_8029973C_de and then either func_80298368_de with the block's word at 0x20, when that is not -1,
   or func_802998A8_de. Returns zero. */




extern s32 func_8041A470_de(void *);

extern void func_8029973C_de();



/* Calls func_8029973C_de; when func_80299A08_de reports 0x60, passes the word at offset 0x28 of the object
   D_800E5690 points to to func_804367A8_de, then sets its word at 0x20 to -1 and calls func_8041A430_de
   on its first word with 2. Returns zero. */



void func_804368F8_de(s32 arg0) {
    u8 *slot = &D_80146417[arg0 * 0x96];

    *slot = arg0;
    func_8041AD10_de(D_800E5694->a, D_80102C89[arg0 * 0x190]);
    func_8041AD10_de(D_800E5694->b, D_800FEC8A[arg0 * 0x190]);
    func_8041A6EC_de(D_800E5694->c, D_800FEC8B[arg0 * 0x190]);
    func_8041A6EC_de(D_800E5694->d, D_800FEC8C[arg0 * 0x190]);
    func_8041AD10_de(D_800E5694->e, D_800FEC8D[arg0 * 0x190]);
}

void func_804369E8_de(s32 arg0) {
    u8 *config;

    config = D_80146398 + arg0 * 0x96;
    D_80102C89[arg0 * 0x190] = func_8041AD04_de(D_800E5694->a);
    do {
        D_800FEC8A[arg0 * 0x190] = func_8041AD04_de(D_800E5694->b);
        D_800FEC8B[arg0 * 0x190] = func_8041A6E0_de(D_800E5694->c);
        D_800FEC8C[arg0 * 0x190] = func_8041A6E0_de(D_800E5694->d);
        D_800FEC8D[arg0 * 0x190] = func_8041AD04_de(D_800E5694->e);
    } while (0);
    config[0x7B] = D_80102C89[arg0 * 0x190];
    config[0x7D] = D_800FEC8A[arg0 * 0x190];
    config[0x79] = D_800FEC8B[arg0 * 0x190];
    config[0x7A] = D_800FEC8C[arg0 * 0x190];
    config[0x82] = D_800FEC8D[arg0 * 0x190];
}

s32 func_80436B38_de(void) {
    extern void *D_800E5690;
    func_802547E4_de(D_800E5690);
    D_800E5690 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80436B68_de(void) {
    return 0;
}

s32 func_80436B70_de(void) {
    extern struct State_func_804232AC_de *D_800E5690;
    switch (func_8041A470_de(D_800E5690->menu)) {
    case 3:
        break;
    case 4:
        func_8029973C_de();
        if (D_800E5690->value != -1) {
            func_80298368_de(D_800E5690->value);
        } else {
            func_802998A8_de();
        }
        break;
    }
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80436BEC_de(void) {
    return 0;
}

s32 func_80436BF4_de(void) {
    extern struct State_func_80436BF4_de *D_800E5690;
    struct State_func_80436BF4_de *state;
    func_8029973C_de();
#if defined(VERSION_DE)
    if (func_80299A08_de() == 0x5E) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (func_80299A08_de() == 0x60) {
#elif defined(VERSION_EU_X)
    if (func_80299A08_de() == 0x64) {
#endif
        func_804367A8_de(D_800E5690->item);
        state = D_800E5690;
        state->value = -1;
        func_8041A430_de((s32)state->first, 2);
    }
    return 0;
}
