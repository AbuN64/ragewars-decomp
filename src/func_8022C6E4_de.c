#include "common/unused.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022C894.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"

extern void func_802227F4_de(void *, void *, s32);






s32 func_8022C6E4_de(void *arg0, void *arg1) {
    s16 state = ((Actor_func_8022D290_de *)arg0)->unk_0x0650;
    s32 blocked;

    if ((state == 0x15) || (state == 0x13) || (state == 0x14)) {
        blocked = 1;
    } else {
        blocked = 0;
    }
    if (blocked == 0) {
        if ((((Actor_func_8024A7A0_de *)arg1)->motionState & 0x20000) == 0) {
            return 0;
        }
        if (((Actor_func_8022D290_de *)arg0)->unk_0x0650 == 0xD) {
            return 0;
        }
        if (((Actor_func_8022D290_de *)arg0)->unk_0x0650 == 0xE) {
            return 0;
        }
        func_802227F4_de(arg0, arg1, 0xD);
        return 1;
    }
    return 0;
}

/* Sets flag 0x100 on the second object and triggers event 0xF on the first when the first is not in states 0x13 to 0x15 or 0x26, is not flagged 0x8000, and the second object's descriptor bit 1 and flag 0x80 are set, returning whether it fired. Adapted from func_8022C6E4_de with the flag tests, the excluded state and the event number changed. */
extern void func_802227F4_de(void *, void *, s32);






s32 func_8022C760_de(void *arg0, void *arg1) {
    s16 state = ((Actor_func_8022D290_de *)arg0)->unk_0x0650;
    s32 blocked;
    s32 flags;

    if ((state == 0x15) || (state == 0x13) || (state == 0x14)) {
        blocked = 1;
    } else {
        blocked = 0;
    }
    if (blocked == 0) {
        if (((MovementDescriptor *)((Actor_func_8024A7A0_de *)arg1)->definition)->body.header.flags & 1) {
            if (((Actor_func_8022D290_de *)arg0)->unk_0x0650 == 0x26) {
                return 0;
            }
            if (((Actor_func_8022D290_de *)arg0)->unk_0x0664 & 0x8000) {
                return 0;
            }
            flags = ((Actor_func_8024A7A0_de *)arg1)->motionState;
            if (flags & 0x80) {
                goto fire;
            }
        }
        return 0;
    }
    return 0;
fire:
    ((Actor_func_8024A7A0_de *)arg1)->motionState = flags | 0x100;
    func_802227F4_de(arg0, arg1, 0xF);
    return 1;
}

extern void func_802227F4_de(void *, void *, s32);









s32 func_8022C7F8_de(void *arg0, void *arg1) {
    f32 field6E4;

    if (((Actor_func_8022D290_de *)arg0)->unk_0x07E8 == 0) {
        field6E4 = ((Actor_func_8022D290_de *)arg0)->unk_0x06E4;
        if (!(D_800C2D5C_de < field6E4)) {
            if (!(((Actor_func_8024A7A0_de *)arg1)->motionState & 0xC0000)) {
                if (((MovementDescriptor *)((Actor_func_8024A7A0_de *)arg1)->definition)->body.header.flags & 2) {
                    if ((((Actor_func_8022D290_de *)arg0)->unk_0x06B0 & 0x10) && (((Actor_func_8022D290_de *)arg0)->unk_0x11D8 <= 0.0f)) {
                        func_802227F4_de(arg0, arg1, 5);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

/** Return zero. */
int func_8022C88C_de(void) {
    return 0;
}

void func_8022C894_de(void *arg0, void *arg1) {
    ((Actor_func_8024A7A0_de *)arg1)->position1.x = 0;
    ((Actor_func_8024A7A0_de *)arg1)->position1.y = 0;
    ((Actor_func_8024A7A0_de *)arg1)->position1.z = 0;
}
