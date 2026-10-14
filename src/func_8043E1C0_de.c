#include "span_16E000/code_8043DF84.h"
#include "types.h"

extern TutorialProgress D_801468A0;




/** True if any of three flags inside the D_801468A0 record are set. */
s32 func_8043E1C0_de(void) {
    TutorialProgress *base = &D_801468A0;
    s32 result;

    result = 0;
    if ((base->unk28 != 0) || (base->unk1C != 0) || (base->unk20 != 0)) {
        result = 1;
    }
    return result;
}
