#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"

/** Always returns 0. */
s32 func_8043E5D0_de(void) {
    return 0;
}

/* Returns 1 if any of D_801468A0's unk1C, unk20 or unk28 fields is nonzero, otherwise 0. */



extern State_func_8043E254_de D_801468A0;

s32 func_8043E5D8_de(void) {
    State_func_8043E254_de *s = &D_801468A0;
    s32 result;

    result = 0;
    if ((s->unk28 != 0) || (s->unk1C != 0) || (s->unk20 != 0)) {
        result = 1;
    }
    return result;
}

/* Clears arg1->unk1C's unk858 flag and its unk5D8's unk80, then forwards to func_80442574_de. */

extern void func_80442574_de(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4);
extern s32 D_0044FB2C;







s32 func_8043E610_de(void *arg0, Handle8043E788 *arg1) {
    Obj1C *temp_a2;

    temp_a2 = arg1->unk1C;
    temp_a2->unk858 = 0;
    temp_a2->unk5D8->unk80 = 0;
    func_80442574_de(temp_a2->unk5DC + 0x554, &D_0044FB2C, temp_a2, temp_a2->unk698, temp_a2->unk5D4);
    return 1;
}

/* Sets arg1->unk1C's unk858 flag and clears its unk5D8's unk80, then forwards to func_80442574_de. */

extern void func_80442574_de(s32 arg0, void *arg1, void *arg2, s32 arg3, s32 arg4);
extern s32 D_0044FB2C;







s32 func_8043E658_de(void *arg0, Handle8043E788 *arg1) {
    Obj1C *temp_a2;

    temp_a2 = arg1->unk1C;
    temp_a2->unk858 = 1;
    temp_a2->unk5D8->unk80 = 0;
    func_80442574_de(temp_a2->unk5DC + 0x554, &D_0044FB2C, temp_a2, temp_a2->unk698, temp_a2->unk5D4);
    return 1;
}

/* Steps the selection D_800E1DF8_de through func_804423BC_de (a second step when func_802643A0_de or
   func_8026437C_de reports the object's controller busy), then sets D_80142228 to the chosen entry of the
   float table D_00450854 plus the offset in D_800E2358, clamped between D_800DE330_de and (2.0f). */





extern s32 D_800E1DF8_de;
extern Extra D_800E2358;


extern f32 D_00450854[];

extern s32 func_804423BC_de(struct Shape_typemap_114 *, s32, s32, s32, s32, s32);

extern s32 func_8026437C_de(s32);

s32 func_8043E6A4_de(void *arg0, struct Shape_typemap_114 *obj)
{
    f32 scale;

    D_800E1DF8_de = func_804423BC_de(obj, D_800E1DF8_de, 1, 0, 15, 0);
    if (((s32 (*)(s32))func_802643A0_de)(obj->field_20) != 0 || func_8026437C_de(obj->field_20) != 0) {
        func_804423BC_de(obj, D_800E1DF8_de, 1, 0, 15, 0);
    }
    scale = D_00450854[D_800E1DF8_de] + D_800E2358.scale;
    if (!(scale < D_800DE330_de)) {
        if (!(scale > (2.0f))) {
            if (scale < D_800DE330_de) {
                scale = D_800DE330_de;
            }
        } else {
            scale = (2.0f);
        }
    } else {
        scale = D_800DE330_de;
    }
    D_80142228 = scale;
    return 0;
}
