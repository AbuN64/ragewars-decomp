#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_57.H"

/* Counts how many of the four 2920-byte entries D_800E54A4 points to have a word at offset 0x58 that is neither zero nor 0x11.
   Adapted from func_804355B4_de with the extra 0x11 exclusion changed. */


extern struct PlayerRecAt58 *D_800E54A4;

s32 func_80435574_de(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800E54A4[i].state != 0 && D_800E54A4[i].state != 0x11) {
            count++;
        }
    }
    return count;
}
