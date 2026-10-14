#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"

/* Latches D_80153770 to one when the record's team value is not -1 and both func_802645D0_de and func_80406178_de accept it, then returns D_80153770. Adapted from func_80409C0C_de with the latch D_80153784 changed to D_80153770. */





extern s32 D_80153770;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 func_802645D0_de(s32);
extern s32 func_80406178_de(struct Record_func_80409BDC_de *, s32, s32);

static inline s32 func_80409BDC_de(struct Record_func_80409BDC_de *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->inner->unk4;
}

s32 func_8040B700_de(struct Record_func_80409BDC_de *record) {
    if (D_80153770 == 0) {
        if (func_80409BDC_de(record) != -1) {
            if (func_802645D0_de(func_80409BDC_de(record)) != 0) {
                if (func_80406178_de(record, func_80409BDC_de(record), 0) != 0) {
                    D_80153770 = 1;
                }
            }
        }
    }
    return D_80153770;
}
