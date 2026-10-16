#include "span_1000/code_80243A80.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "shared/func_804235A8_eu_layout.h"
#include "TYPES.H"

extern int func_80245784_de(void);

extern void func_80245BC0_de(void);

extern void func_80253838_de(void *arg0, void *arg1);

extern f32 D_800C37D0_de;

/** Read the word at offset 0x38 from the globally selected record. */


/* Reports whether the globally selected record is active (its word at 0x38 is non-zero) and its
   value at 0x1C lies between the bounds at 0x30 and 0x34. */


void func_802456A0_de(void) {
    extern void *D_800E2830;
    if (func_80245784_de() != 0) {
        s32 temp_a1;
        Shared_MenuContext *record;

        func_80245B74_de(1);
        func_80245BC0_de();
        temp_a1 = (s32)((Shared_MenuContext *)D_800E2830)->owner;
        if (temp_a1 != 0) {
            func_80253838_de(0, temp_a1);
        }
        record = D_800E2830;
        record->owner = 0;
        record->resource = 0;
        record->active = 0;
        record->state3C = 0;
        record->unknown60 = 0;
    }
}

void func_8024570C_de(void) {
    extern func_802456FC_S1 *D_800E2830;
    if (func_80245784_de() != 0 && func_80245764_de() != 0 && D_800E2830->unk60 == 0) {
        f32 temp = D_800C37D0_de;
        D_800E2830->unk60 = 1;
        D_800E2830->unk64 = temp;
    }
}

/** Return the constant success result used by callers at VRAM 0x80245754. */
int func_80245764_de(void) {
    return 1;
}

int func_8024576C_de(void) {
    extern func_8024575C_S1 *D_800E2830;
    return D_800E2830->unkDC != -1;
}

int func_80245784_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    return record->active;
}

int func_80245798_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    float temp_f1;
    int var_a0 = 0;

    if (record->active != 0) {
        temp_f1 = record->time;
        if (record->start <= temp_f1 && temp_f1 <= record->end) {
            var_a0 = 1;
        }
    }
    return var_a0;
}

s32 func_802457E0_de(void) {
    extern func_802457D0_S1 *D_800E2830;
    if (D_800E2830->unk38 != 0) {
        if (D_800E2830->unk1C > D_800E2830->unk34) {
            return 1;
        }
        return 0;
    }
    return 1;
}
