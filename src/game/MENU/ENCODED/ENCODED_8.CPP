#include "COMMON/CHEATCODE.H"
#include "TYPES.H"
#include "MENU/80408AC4_40.H"

/* Resets D_80154030 to -1. */

extern s32 D_80154030;

void Encoded_ResetTextEntryResult(void) {
    D_80154030 = -1;
}
