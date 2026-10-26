#include "include_asm.h"

#include "IO/EXTERNS.H"
#include "TYPES.H"

extern volatile s32 D_800F1C80_de;

void Libsn_SpinDelay(s32 iterationCount) {
    for (D_800F1C80_de = 0; D_800F1C80_de < iterationCount; D_800F1C80_de++) {
    }
}
