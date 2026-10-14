#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041BEA8.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_80286080_de_closed.h"
#include "shared/func_804220A8_de_closed.h"
#include "shared/func_80438614_de_closed.h"
struct ObjectB8;
extern s32 func_80265650_de(void *, s32);
extern PlayerRecord D_800FEB4A[];
static __inline__ Menu_func_8041D960_de *screen32(void) {
    void *block = D_800E3590;
    return block;
}
static __inline__ void *record32(void) { return &D_800E3590->record; }
void func_8041D4E0_de(void) {
    s32 index;
    s32 count;
    s32 text;
    if (screen32()->focus == 0) {
        func_80439C80_de(record32(), 0);
        return;
    }
    for (index = 0; index < 50; index++) {
        if (D_800DF544[index].id == screen32()->focus->unkC) {
            if (func_80265650_de(&D_800FEB4A[screen32()->player], index) == 1) {
                text = 0;
                count = 0;
                switch (index) {
                case 36: text = 3701; break;
                case 37: text = 3702; break;
                case 38: text = 3703; break;
                case 39: text = 3704; break;
                case 40: text = 3705; break;
                case 41: text = 3706; break;
                case 42: text = 3707; break;
                case 43: text = 3708; break;
                case 44: text = 3709; break;
                case 45: text = 3710; break;
                case 46: text = 3711; break;
                case 47: text = 3712; break;
                case 48: text = 3713; break;
                case 49: text = 3714; break;
                default: text = 0xE74; count = index; break;
                }
                func_80439C80_de(record32(), text);
                func_80439CD4_de(record32(), count);
                if (func_8025477C_de() == 0) func_8025476C_de(1);
            } else {
                func_80439C80_de(record32(), 0);
            }
            return;
        }
    }
}
