#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028469C.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

void *func_802846C8_de(void *arg0, s32 arg1, void *arg2) {
    void *record;

    record = *(void **)(&((func_8028469C_S1 *)(arg0))->unkFC28 +
                        (((func_8028469C_S3 *)(((func_8028469C_S2 *)(arg2))->unk38))->unk8 * 20));
    if (arg2 != 0) {
        if (record != 0) {
            do {
                if (((func_8028469C_S4 *)(record))->unk124 == arg1) {
                    if (((func_8028469C_S4 *)(record))->unk118 == arg2) {
                        return record;
                    }
                }
                record = ((func_8028469C_S4 *)(record))->unk1EC;
            } while (record != 0);
        }
    } else if (record != 0) {
        do {
            if (((func_8028469C_S4 *)(record))->unk124 == arg1) {
                return record;
            }
            record = ((func_8028469C_S4 *)(record))->unk1EC;
        } while (record != 0);
    }
    return 0;
}

extern void func_80255D70_de(void *, s32, s32);
extern s32 func_80255CB8_de(void *, s32);

void func_80284758_de(void *arg0, void *arg1)
{
    void *current;
    s32 key;

    current = ((func_8028472C_S1 *)(arg0))->unkFC14.head;
    if (current != 0) {
        key = ((func_8028472C_S2 *)(arg1))->unk118.v0;
loop:
        if (((func_8028472C_S3 *)(current))->unk118 != key) {
            current = ((func_8028472C_S3 *)(current))->unk1F4;
            if (current != 0) {
                goto loop;
            }
        }
    }

    if (current != 0) {
        func_80255D70_de(&((func_8028472C_S1 *)(arg0))->unkFC14, current, arg1);
    } else if (*((func_8028472C_S2 *)(arg1))->unk118.v1 & 0x2000) {
        func_80255CB8_de(&((func_8028472C_S1 *)(arg0))->unkFC14, arg1);
    } else {
        func_80255D14_de(&((func_8028472C_S1 *)(arg0))->unkFC14, arg1);
    }

    ((func_8028472C_S2 *)(arg1))->unk5C |= 0x01000000;
}

extern s32 func_802744D4_de(void);

s32 func_8028480C_de(s32 arg0) {
    if (arg0 != 0) {
        return func_802744D4_de() % (arg0 + 1);
    }
    return 0;
}


void func_80284870_de(f32 arg0) {
    if (arg0 != 0.0f) {
        ((s32 (*)())func_80274564_de)();
    }
}

/** Return offset 0x180 only when the nested state word is zero. */
float func_8028489C_de(void *arg0) {
    void *inner = ((func_80284870_S1 *)(arg0))->unk118;
    if (((func_80204468_S3 *)(inner))->unk14 != 0) {
        return 0.0f;
    }
    return ((func_80284870_S1 *)(arg0))->unk180;
}

f32 func_802848BC_de(void *arg0) {
    f32 var_f0;
    var_f0 = 0.0f;
    if ((((struct func_80204468_S3 *) ((s8 *) ((struct ObjectLinks188 *) ((s8 *) arg0))->unk_118))->unk14) == 0) {
        var_f0 = (((struct ObjectLinks188 *) ((s8 *) arg0))->unk_184);
    }
    return var_f0;
}

s32 func_802848DC_de(void *arg0) {
    u16 temp_v1;
    s32 val;

    temp_v1 = ((func_8022BC04_S2 *)(arg0))->unk4;
    val = temp_v1;
    if (val == 0x56) {
        goto ret1;
    }
    if (val >= 0x57) {
        goto ge_e;
    }
    if (val == 2) {
        goto ret1;
    }
    goto ret0;
ge_e:
    if (val == 0x111) {
        goto ret1;
    }
    if (val != 0x126) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

s32 func_80284928_de(void *arg0) {
    u16 temp_v1;
    s32 val;

    temp_v1 = ((func_8022BC04_S2 *)(arg0))->unk4;
    val = temp_v1;
    if (val == 0x11) {
        goto ret1;
    }
    if (val >= 0x12) {
        goto ge_12;
    }
    if (val < 5) {
        goto ret0;
    }
    if (val < 8) {
        goto ret1;
    }
    if (val == 9) {
        goto ret1;
    }
    goto ret0;
ge_12:
    if (val == 0x1A) {
        goto ret1;
    }
    if (val >= 0x1B) {
        goto ge_1b;
    }
    if (val == 0x13) {
        goto ret1;
    }
    goto ret0;
ge_1b:
    if (val == 0x101) {
        goto ret1;
    }
    if (val != 0x110) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

s32 func_802849AC_de(void *arg0) {
    u16 temp_v1;
    s32 val;

    temp_v1 = ((func_8022BC04_S2 *)(arg0))->unk4;
    val = temp_v1;
    if (val == 0xD) {
        goto ret1;
    }
    if (val >= 0xE) {
        goto ge_e;
    }
    if (val == 8) {
        goto ret1;
    }
    goto ret0;
ge_e:
    if (val != 0x12) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}
