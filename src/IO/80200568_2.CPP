#include "include_asm.h"

#include "IO/EXTERNS.H"
#include "TYPES.H"

extern volatile s32 D_800F1C80_de;

void func_802005DC_de(s32 arg0) {
    for (D_800F1C80_de = 0; D_800F1C80_de < arg0; D_800F1C80_de++) {
    }
}
