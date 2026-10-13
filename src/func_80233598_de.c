#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8023330C.h"
#include "types.h"
#include "shared/level_actor.h"

extern s32 func_802301F4_de(void);







void func_80233598_de(void *arg0, void *arg1) {
    void *temp_s1;

    temp_s1 = ((Actor_func_8024A7A0_de *)arg0)->controller;
    if (((WeaponFireState *)arg1)->triggerMode != 0) {
        ((WeaponFireState *)arg1)->mode = 2;
        if (func_802301F4_de() != 0) {
            ((WeaponFireState *)arg1)->mode = 1;
            func_8022B00C_de(temp_s1);
        }
    }
}
