#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028308C.h"
#include "types.h"

/** Return arg0, but treat the sentinel value 0xA as 0. */
s32 func_80283D38_de(s32 arg0) {
    if (arg0 == 0xA) {
        return 0;
    }
    return arg0;
}






extern void func_80265E10_de(void *, void *, s32, s32, Triple, struct Shape_func_802764D4_de_2);
extern void func_80279B40_de(void *, s32, s8, s32);
extern s32 func_8025DE54_de(s16, s32, s32, s32, s32, s32);











void func_80283D50_de(void *arg0) {
    struct Shape_func_802764D4_de_2 pair;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_s3;
    void *temp_s1;
    void *temp_v0_2;
    void *temp_v1;

    temp_s1 = ((func_80283D24_S1 *)(arg0))->unk118;
    if (func_80284068_de(arg0) != 0) {
        var_a0 = 0xC;
    } else {
        var_a0 = 0xA;
    }
    temp_a1 = var_a0 * 2;
    temp_v0 = ((func_802066A4_S3 *)(temp_s1))->unk18;
    temp_v1 = (char *)temp_v0 + temp_a1;
    temp_s2 = ((func_8027C324_S3 *)(temp_v1))->unk70;
    temp_a2 = ((func_8027C324_S3 *)(temp_v1))->unk8C;
    temp_v0_2 = (char *)temp_v0 + (var_a0 * 8);
    pair = *(struct Shape_func_802764D4_de_2 *)temp_v0_2;
    temp_s3 = ((func_8027C324_S3 *)((( func_802066A4_S3 *)temp_s1)->unk18 + temp_a1))->unkA8;
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1,
                     ((func_80283D24_S1 *)(arg0))->unk8.v0, pair);
    }
    if (temp_s2 != 0xFFFF) {
        func_80279B40_de(arg0, temp_s2, ((func_80283D24_S1 *)(arg0))->unk1D0, 1);
    }
    if (temp_s3 != 0xFFFF) {
        func_8025DE54_de((s16)temp_s3,
                      ((func_80283D24_S1 *)(arg0))->unk8.v1,
                      ((func_80203B60_S2 *)(arg0))->unkC,
                      ((func_80203B60_S2 *)(arg0))->unk10, 0, -1);
    }
}







extern void func_80265E10_de(void *, void *, s32, s32, Triple, struct Shape_func_802764D4_de_2);
extern void func_80279B40_de(void *, s32, s8, s32);
extern s32 func_8025DE54_de(s16, s32, s32, s32, s32, s32);











void func_80283E58_de(void *arg0) {
    struct Shape_func_802764D4_de_2 pair;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_s3;
    void *temp_s1;
    void *temp_v0_2;
    void *temp_v1;

    temp_s1 = ((func_80283D24_S1 *)(arg0))->unk118;
    if (func_80284068_de(arg0) != 0) {
        var_a0 = 0xD;
    } else {
        var_a0 = 0xB;
    }
    temp_a1 = var_a0 * 2;
    temp_v0 = ((func_802066A4_S3 *)(temp_s1))->unk18;
    temp_v1 = (char *)temp_v0 + temp_a1;
    temp_s2 = ((func_8027C324_S3 *)(temp_v1))->unk70;
    temp_a2 = ((func_8027C324_S3 *)(temp_v1))->unk8C;
    temp_v0_2 = (char *)temp_v0 + (var_a0 * 8);
    pair = *(struct Shape_func_802764D4_de_2 *)temp_v0_2;
    temp_s3 = ((func_8027C324_S3 *)((( func_802066A4_S3 *)temp_s1)->unk18 + temp_a1))->unkA8;
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1,
                     ((func_80283D24_S1 *)(arg0))->unk8.v0, pair);
    }
    if (temp_s2 != 0xFFFF) {
        func_80279B40_de(arg0, temp_s2, ((func_80283D24_S1 *)(arg0))->unk1D0, 1);
    }
    if (temp_s3 != 0xFFFF) {
        func_8025DE54_de((s16)temp_s3,
                      ((func_80283D24_S1 *)(arg0))->unk8.v1,
                      ((func_80203B60_S2 *)(arg0))->unkC,
                      ((func_80203B60_S2 *)(arg0))->unk10,
                      (s32)((char *)arg0 + 8), (s32)arg0);
    }
}






extern void func_80265E10_de(void *, void *, s32, s32, Triple, struct Shape_func_802764D4_de_2);
extern void func_80279B40_de(void *, s32, s8, s32);
extern s32 func_8025DE54_de(s16, s32, s32, s32, s32, s32);











void func_80283F60_de(void *arg0) {
    struct Shape_func_802764D4_de_2 pair;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_s3;
    void *temp_s1;
    void *temp_v0_2;
    void *temp_v1;

    temp_s1 = ((func_80283D24_S1 *)(arg0))->unk118;
    if (func_80284068_de(arg0) != 0) {
        var_a0 = 0xC;
    } else {
        var_a0 = 0xA;
    }
    temp_a1 = var_a0 * 2;
    temp_v0 = ((func_802066A4_S3 *)(temp_s1))->unk18;
    temp_v1 = (char *)temp_v0 + temp_a1;
    temp_s2 = ((func_8027C324_S3 *)(temp_v1))->unk70;
    temp_a2 = ((func_8027C324_S3 *)(temp_v1))->unk8C;
    temp_v0_2 = (char *)temp_v0 + (var_a0 * 8);
    pair = *(struct Shape_func_802764D4_de_2 *)temp_v0_2;
    temp_s3 = ((func_8027C324_S3 *)((( func_802066A4_S3 *)temp_s1)->unk18 + temp_a1))->unkA8;
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1,
                     ((func_80283D24_S1 *)(arg0))->unk8.v0, pair);
    }
    if (temp_s2 != 0xFFFF) {
        func_80279B40_de(arg0, temp_s2, ((func_80283D24_S1 *)(arg0))->unk1D0, 1);
    }
    if (temp_s3 != 0xFFFF) {
        func_8025DE54_de((s16)temp_s3,
                      ((func_80283D24_S1 *)(arg0))->unk8.v1,
                      ((func_80203B60_S2 *)(arg0))->unkC,
                      ((func_80203B60_S2 *)(arg0))->unk10, 0, -1);
    }
}

int func_80284068_de(void *arg0) {
    char pad[0x10];
    return (((func_8028403C_S1 *)(arg0))->unk5C >> 2) & 1;
}

int func_80284080_de(void) {
    char pad[0x10];
    return 0;
}
