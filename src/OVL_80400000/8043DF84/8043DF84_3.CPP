#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8043DF84.h"
#include "TYPES.H"

/** Dispatches to func_80264770_de or func_80264788_de with a byte read from arg0->unk20->unk4, chosen by arg1. */

extern void func_80264770_de(s32 arg);
extern void func_80264788_de(s32 arg);






void func_8043DEF8_de(void *arg0, s32 arg1) {
    s32 val;
    MenuRecAt20V2 *menu = arg0;

    val = menu->widget->unk4;
    if (arg1 != 0) {
        func_80264770_de(val);
    } else {
        func_80264788_de(val);
    }
}
