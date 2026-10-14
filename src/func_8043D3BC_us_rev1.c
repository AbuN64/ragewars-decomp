#include "types.h"

extern u32 D_80154034;

/* Returns the score threshold for the current level index, 1000 for level 0 or out of range. */
s32 func_8043D3BC_us_rev1(void) {
    switch (D_80154034) {
    case 0:
    default:
        return 1000;
    case 1:
        return 2000;
    case 2:
        return 3000;
    case 3:
        return 4000;
    case 4:
        return 5000;
    case 5:
        return 6000;
    case 6:
        return 7401;
    case 7:
        return 7501;
    case 8:
        return 7601;
    case 9:
        return 7602;
    case 10:
        return 8000;
    }
}
