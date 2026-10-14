#include "span_1000/code_80243A80.h"
#include "types.h"




extern func_802457D0_S1 *D_800E2830;

s32 func_802457E0_de(void) {
    if (D_800E2830->unk38 != 0) {
        if (D_800E2830->unk1C > D_800E2830->unk34) {
            return 1;
        }
        return 0;
    }
    return 1;
}
