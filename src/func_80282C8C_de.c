#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027A0F4.h"
#include "types.h"

/* Returns whether any of the 22 records in D_800D052C holds, in either of its two three-entry lists, an entry of kind 1 whose id matches the given object's id. */







extern Record_func_80282C8C_de *D_800D052C[];

s32 func_80282C8C_de(func_8022BC04_S2 *obj) {
    s32 i;
    s32 j;
    Entry_func_80282C8C_de *entry;

    for (i = 0; i < 22; i++) {
        for (j = 0; j < 3; j++) {
            entry = D_800D052C[i]->first[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 1) {
                return 1;
            }
            entry = D_800D052C[i]->second[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 1) {
                return 1;
            }
        }
    }
    return 0;
}

/* Accepts special id 0x427 or an id found in either record list with entry kind zero. */







extern Record_func_80282C8C_de *D_800D052C[];

s32 func_80282D38_de(func_8022BC04_S2 *obj) {
    s32 i;
    s32 j;
    Entry_func_80282C8C_de *entry;

    if (obj->unk4 == 0x427) return 1;
    for (i = 0; i < 22; i++) {
        for (j = 0; j < 3; j++) {
            entry = D_800D052C[i]->first[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 0) {
                return 1;
            }
            entry = D_800D052C[i]->second[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 0) {
                return 1;
            }
        }
    }
    return 0;
}

/* Returns whether any of the 22 records in D_800D052C holds, in either of its two three-entry lists, an entry of kind 2 whose id matches the given object's id. Adapted from func_80282C8C_de with the entry kind changed from 1 to 2. */







extern Record_func_80282C8C_de *D_800D052C[];

s32 func_80282DEC_de(func_8022BC04_S2 *obj) {
    s32 i;
    s32 j;
    Entry_func_80282C8C_de *entry;

    for (i = 0; i < 22; i++) {
        for (j = 0; j < 3; j++) {
            entry = D_800D052C[i]->first[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 2) {
                return 1;
            }
            entry = D_800D052C[i]->second[j];
            if (entry != 0 && entry->id == obj->unk4 && entry->kind == 2) {
                return 1;
            }
        }
    }
    return 0;
}


extern char D_8011D8D0;
extern f32 D_800C4E58_de[];



extern void *func_802A001C_de(void *, s32, u32);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);
extern void func_8022B550_de(void *, f32, f32, void *, s32);
extern void func_8028CE94_de(void *, void *, s32, Triple, f32, f32);

extern void func_80265E10_de(void *, void *, s32, s32, Triple, struct Shape_func_802764D4_de_2);
extern void func_80279B40_de(void *, s32, s8, s32);
extern void func_80284570_de(void *, void *);















void func_80282E98_de(void *arg0, void *arg1) {
    Triple scratch;
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

    func_802A001C_de(&scratch, 0, 0xC);
    if (((func_80282E6C_S1 *)(arg0))->unk4 == 0x40F) {
        func_8025DE54_de(0xCDA, ((func_80282E6C_S2 *)(arg1))->unk8,
                      (s32)&((func_80282E6C_S2 *)arg1)->unk8, -1);
        func_8022B550_de(arg1, 30.0f, 3.0f,
                     ((func_80282E6C_S1 *)(arg0))->unk12C, 0);
        func_8028CE94_de(&D_8011FE88,
                      &((func_80282E6C_S3 *)(((func_80282E6C_S2 *)(arg1))->unk698))->unk140,
                      0x14, scratch, D_800C4E58_de[1], D_800C4E60_de);
        ((func_80282E6C_S2 *)(arg1))->unk11EC = (&D_800C4E60_de)[1];
    }

    temp_s1 = ((func_80282E6C_S1 *)(arg0))->unk118;
    if (func_80284068_de(arg0) != 0) {
        var_a0 = 0xC;
    } else {
        var_a0 = 0xA;
    }
    temp_a1 = var_a0 * 2;
    temp_v0 = ((func_802066A4_S3 *)(temp_s1))->unk18;
    temp_v1 = (char *)temp_v0 + temp_a1;
    temp_s2 = ((func_80282E6C_S5 *)(temp_v1))->unk70;
    temp_a2 = ((func_80282E6C_S5 *)(temp_v1))->unk8C;
    temp_v0_2 = (char *)temp_v0 + (var_a0 * 8);
    pair = *(struct Shape_func_802764D4_de_2 *)temp_v0_2;
    temp_s3 = ((func_80282E6C_Table *)(((func_802066A4_S3 *)temp_s1)->unk18 + temp_a1))->unkA8;
    if (temp_a2 != 0xFFFF) {
        func_80265E10_de(arg0, arg0, temp_a2, -1,
                     ((func_80282E6C_S1 *)(arg0))->unk8.v0, pair);
    }
    if (temp_s2 != 0xFFFF) {
        func_80279B40_de(arg0, temp_s2, ((func_80282E6C_S1 *)(arg0))->unk1D0, 1);
    }
    if (temp_s3 != 0xFFFF) {
        func_8025DE54_de((s16)temp_s3, ((func_80282E6C_S1 *)(arg0))->unk8.v1, 0, -1);
    }
    func_80284570_de(&D_8011D8D0, arg0);
    func_80284434_de(arg0);
}

extern u8 D_801462E3;




void func_80283064_de(void *arg0, s32 *arg1) {
    s32 result;

    result = 0;
    if ((*(((func_80283038_S1 *)((arg0)))->unk118)) & 0x02000000) {
        if ((((func_80283038_S1 *)((arg0)))->unk5C) & 2) {
            result = 2;
        } else if (D_801462E3 == 2) {
            result = 1;
        }
    }
    *arg1 |= result << 0x1E;
}
