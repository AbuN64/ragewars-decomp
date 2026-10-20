#include "TYPES.H"
#include "COMMON/TEXTURE.H"
#include "sdk/libgultra/viblack.h"

/* Spins forever unless arg0 is 5, calling osViBlack with bit 20 of a running counter each pass. */
void func_80415C1C_de(s32 arg0) {
    s32 i = 0;

    while (arg0 != 5) {
        s32 bit = i & 0x100000;

        i++;
        osViBlack(bit != 0);
    }
}
