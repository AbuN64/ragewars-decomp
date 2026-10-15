#include "span_1000/code_80231F5C.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80208000.h"
#include "types.h"
#include "common/unused.h"


void func_80232744_de(void *arg0, s32 arg1, s32 arg2) {
    AiTarget *target = arg0;
    func_8021A9A4_de(target->player, arg2);
}

/** Return the value pointed to by the indexed pointer table entry. */
int func_80232764_de(int arg0) {
    return *D_800CB358_de[arg0];
}

s32 func_80232780_de(s32 arg0) {
    if (arg0 < 7) {
        if (arg0 >= 3) {
            return 1;
        }
    }
    return 0;
}

/** Return whether the encoded type belongs to this caller's accepted set. */
s32 func_802327A0_de(s32 arg0) {
    {
        arg0 -= 2;
        if ((unsigned int)arg0 >= 14) {
            goto case_default;
        }
        switch (arg0) {
        case 0: goto case_2;
        case 1: goto case_default;
        case 2: goto case_default;
        case 3: goto case_default;
        case 4: goto case_default;
        case 5: goto case_2;
        case 6: goto case_2;
        case 7: goto case_2;
        case 8: goto case_default;
        case 9: goto case_default;
        case 10: goto case_default;
        case 11: goto case_2;
        case 12: goto case_2;
        case 13: goto case_2;
        }
    }
case_2:
case_7:
case_8:
case_9:
case_13:
case_14:
case_15:
    return 1;
case_default:
    return 0;
}

s32 func_802327D4_de(s32 arg0) {
    if (arg0 < 0xD) {
        if (arg0 >= 0xA) {
            return 1;
        }
    }
    return 0;
}
