#include "types.h"

/* Toggles one of eight UI checkbox flags in D_801462C8, selected by (arg0[0] - 2) through the
 * jump table jtbl_800E2370 for values 2..9; any other value leaves state unchanged. Returns 0. */

#include "shared/func_80425674_de_layout.h"

s32 func_8043E830_de(s32 *arg0) {
    Shared_Game *base;

    switch (arg0[0]) {
        case 2:
            base = &D_801462C8;
            base->unknown24[9] ^= 1;
            break;
        case 3:
            base = &D_801462C8;
            base->unknown24[10] ^= 1;
            break;
        case 4:
            base = &D_801462C8;
            base->unknown24[11] ^= 1;
            break;
        case 5:
            base = &D_801462C8;
            base->unknown24[12] ^= 1;
            break;
        case 6:
            base = &D_801462C8;
            base->unknown24[13] ^= 1;
            break;
        case 7:
            base = &D_801462C8;
            base->unknown24[14] ^= 1;
            break;
        case 8:
            base = &D_801462C8;
            base->unknown24[15] ^= 1;
            break;
        case 9:
            base = &D_801462C8;
            base->unknown24[17] ^= 1;
            break;
    }
    return 0;
}
