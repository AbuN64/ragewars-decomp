#include "span_1000/code_80243A80.h"
#include "common/types_8fd754e1e915.h"
#include "shared/func_804235A8_eu_layout.h"
#include "span_1000/code_80245980.h"
#include "TYPES.H"

extern int func_80245784_de(void);

extern u32 func_80245850_de(void);

extern f32 D_800D2988;

/** Read the word at offset 0x38 from the globally selected record. */


void func_80245C38_de(void) {
    extern Record108 *D_800E2830;
    f32 value;
    f32 limit;
    Record108 *record;

    if (func_80245784_de() != 0) {
        if (func_80245850_de() != 0) {
            D_800E2830->previous = D_800E2830->value;
            return;
        }
        record = D_800E2830;
        record->previous = *(volatile f32 *)&record->value;
        record->value += D_800D2988 * D_800C37E0_de;
        if (record->threshold <= record->value) {
            func_80244E58_de();
        }
        value = D_800E2830->value;
        limit = D_800E2830->limit;
        if (limit <= value) {
            if (D_800E2830->mode == 1) {
                D_800E2830->value = value - limit;
                return;
            }
            D_800E2830->value = limit;
            if (D_800E2830->active != 0) {
                D_800E2830->done = 1;
                D_800E2830->active = 0;
            }
        }
    }
}

int func_80245D14_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    return record->active;
}
