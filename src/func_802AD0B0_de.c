#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AB3FC.h"
#include "types.h"
#include "shared/gameplay_transition.h"

extern char D_800D34C0;




void *func_802AD0B0_de(s32 arg0) {
    char *v1;
    s32 i;
    Shared__struct_D_800D34C0_0x18 *record;

    v1 = &D_800D34C0;
    i = 0xF;
    do {
        record = (Shared__struct_D_800D34C0_0x18 *)v1;
        i -= 1;
        if (record->id != arg0) {
            v1 += 0x18;
        } else {
            return v1;
        }
    } while (i != -1);
    return 0;
}
