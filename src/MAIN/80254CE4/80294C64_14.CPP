#include "span_1000/code_80294C64.h"
#include "TYPES.H"

extern char *func_8028FDB4_de(s32 *, s32);




void func_80295F78_de(s32 **arg0, Shared_AnimInfo *arg1) {
    s32 *temp_s0;
    s32 *tmp;

    temp_s0 = *arg0;
    if (*temp_s0 != 0) {
        arg1->frame = func_8028FDB4_de(temp_s0, 0);
        tmp = func_8028FDB4_de(temp_s0, 1);
        arg1->count = *tmp;
        tmp = func_8028FDB4_de(temp_s0, 2);
        arg1->unk4 = *tmp;
        return;
    }
    arg1->frame = 0;
    arg1->count = 0;
    arg1->unk4 = 0;
}
