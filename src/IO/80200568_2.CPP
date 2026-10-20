#include "include_asm.h"

#ifdef NON_MATCHING
#include "IO/EXTERNS.H"
#include "TYPES.H"

extern s32 D_800F1C80_de;

void func_802005DC_de(s32 arg0) {
    for (D_800F1C80_de = 0; D_800F1C80_de < arg0; D_800F1C80_de++) {
    }
}
#else
INCLUDE_ASM("span_1000", func_802005DC_de);
#endif
