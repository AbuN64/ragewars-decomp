#include "shared/world.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern s32 func_80265550_de(s32, s32, u16, s32 *, s32 *);




s32 func_8028C1D4_de(char *arg0, u16 *arg1, s32 *arg2, s32 *arg3) {
    s32 sp18;
    s32 sp1C;
    s32 temp_v0_2;
    s32 field_cc;
    s32 field_c4;

    temp_v0_2 = func_80265550_de(field_cc, field_c4, *arg1,
        (field_cc = (s32)((Shared_World *)arg0)->alternateRecordIndex,
         field_c4 = ((Shared_World *)arg0)->alternateRecordCount, &sp18), &sp1C);
    if (temp_v0_2 != 0) {
        *arg2 = (s32)((Shared_World *)arg0)->alternateRecordArray + (sp18 * 0x14);
        temp_v0_2 = (sp1C - sp18) + 1;
        *arg3 = temp_v0_2;
    } else {
        *arg2 = 0;
        *arg3 = 0;
    }
    return temp_v0_2;
}
