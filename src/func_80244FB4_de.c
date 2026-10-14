#include "span_1000/code_80243A80.h"
#include "span_16E000/code_80400000.h"
#include "types.h"




extern s32 func_80245784_de(void);
extern u32 func_80245850_de(void);


extern Record_func_80244FB4_de *D_800E2830;
extern f32 D_800D2988;


s32 func_80244FB4_de(void) {
    s32 none;
    f32 value;
    f32 limit;
    Record_func_80244FB4_de *record;

    none = -1;
    if (D_800E2830->resource == none) {
        return 0;
    }
    func_804009F4_de(D_800E2830->resource);
    D_800E2830->resource = none;
    if (func_80245784_de() != 0) {
        if (func_80245850_de() != 0) {
            D_800E2830->previous = D_800E2830->value;
        } else {
            record = D_800E2830;
            record->previous = *(volatile f32 *)&record->value;
            record->value += D_800D2988 * D_800C37B0_de;
            if (record->threshold <= record->value) {
                func_80244E58_de();
            }
            value = D_800E2830->value;
            limit = D_800E2830->limit;
            if (limit <= value) {
                if (D_800E2830->mode == 1) {
                    D_800E2830->value = value - limit;
                } else {
                    D_800E2830->value = limit;
                    if (D_800E2830->active != 0) {
                        D_800E2830->done = 1;
                        D_800E2830->active = 0;
                    }
                }
            }
        }
    }
    func_80403458_de();
    return 1;
}
