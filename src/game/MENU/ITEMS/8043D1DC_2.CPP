#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#ifdef NON_MATCHING
/* Maps the state number D_80154034 (0 to 10) to a fixed value through a jump table; anything else gives 1000. 32/32 words; remaining: the jump table sits in the separate rodata file. */
extern u32 D_80154034;
s32 func_8043D1DC_de(void) {
    switch (D_80154034) {
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
    case 0:
    default:
        return 1000;
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8043D1DC_de);
#endif
#endif
