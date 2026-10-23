#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECORDRECAT1C.H"
#include "OVLGAME/80405454.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/EXTERNS_8.H"
#include "OVLGAME/80405454_4.H"

/* Clears a record: the words at offsets 0, 4, 8, 0x18 and 0x1C, and the three-word array at 0xC
   from its last entry down. */
void func_80405CA8_de(struct RecordRecAt1C *record) {
    s32 i;
    record->a = 0;
    record->b = 0;
    record->c = 0;
    record->d = 0;
    record->e = 0;
    for (i = 2; i >= 0; i--) {
        record->values[i] = 0;
    }
}
/* Releases object resources and clears their handles. */
/* extern */
void func_80405CDC_de(struct RecordRecAt1C *arg0) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 i;
    s32 var_v1;
    temp_a1 = arg0->b;
    if (temp_a1 != 0) {
        func_80253838_de(0, temp_a1);
    }
    temp_a1_2 = arg0->c;
    if (temp_a1_2 != 0) {
        func_80253838_de(0, temp_a1_2);
    }
    temp_a1_3 = arg0->d;
    if (temp_a1_3 != 0) {
        func_80253838_de(0, temp_a1_3);
    }
    temp_a1_4 = arg0->e;
    if (temp_a1_4 != 0) {
        func_80253838_de(0, temp_a1_4);
    }
    i = 0;
    do {
        temp_a1_5 = arg0->values[i];
        if (temp_a1_5 != 0) {
            func_80253838_de(0, temp_a1_5);
        }
        i += 1;
    } while (i < 3);
    var_v1 = 2;
    arg0->a = 0;
    arg0->b = 0;
    arg0->c = 0;
    arg0->d = 0;
    arg0->e = 0;
    do {
        arg0->values[var_v1] = 0;
        var_v1 -= 1;
    } while (var_v1 >= 0);
}
