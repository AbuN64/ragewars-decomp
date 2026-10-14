#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802393F4.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern void func_80239CE0_de(void *arg0);
extern void func_80255ED8_de(void *, s32);







void *func_80239C3C_de(void *arg0, s32 arg1) {
    struct ScreenMessageOwner *owner = arg0;
    struct ScreenMessagePool *pool = (struct ScreenMessagePool *)arg1;
    void *temp_s0;

    temp_s0 = owner->activeMessages.head;
    if (temp_s0 != 0) {
        func_80239CE0_de(temp_s0);
        func_80255ED8_de(&owner->activeMessages, (s32)temp_s0);
        func_80255D14_de(&pool->freeMessages, temp_s0);
    }
    return temp_s0;
}
