#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802536F4.h"
#include "types.h"

extern char D_801051A0;

extern void func_80254DD0_de(void *arg0, struct IntrusiveList *arg1);
extern void func_80255B2C_de(void *arg0, s32 arg1);
extern void func_80254AD0_de(s32, s32);




void func_80254990_de(void *unused, struct IntrusiveList *arg1) {
    s32 temp_v0;

    arg1->nextOffset = arg1->nextOffset & ~2;
    if (arg1->prevOffset != 0) {
    loop_1:
        do {
            temp_v0 = arg1->prevOffset - 1;
            arg1->prevOffset = temp_v0;
            if (temp_v0 != 0) {
                goto loop_1;
            }
            arg1->nextOffset = arg1->nextOffset & ~0x100;
        } while (arg1->prevOffset != 0);
    }
    if (!(arg1->nextOffset & 0x702)) {
        func_80254DD0_de(0, arg1);
        func_80255B2C_de(&D_801051A0, *(s32 *) arg1);
        func_80254AD0_de(0, arg1);
    }
}
