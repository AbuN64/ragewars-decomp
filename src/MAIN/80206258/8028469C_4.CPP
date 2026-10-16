#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028469C.h"
#include "TYPES.H"
#include "stddef.h"
void func_80253D10_de(s32, void **, void *);
void * func_80254480_de(s32, void *, s32);
void * func_80254600_de(s32, s32, s32);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
 /* extern */
#if defined(VERSION_DE)
#elif defined(VERSION_EU)
s32 func_802ADBE0_eu();
#elif defined(VERSION_EU_X)
s32 func_802ADC20_eu_x();
#elif defined(VERSION_US)
s32 func_802AD870_us();
#elif defined(VERSION_US_REV1)
s32 func_802B2A10_us_rev1();
#endif
/* extern */
/* Unpack or copy a resource into an allocated buffer and install it. */
s32 func_80285180_de(void **arg0, s32 arg1) {
    s32 var_s0;
    u8 temp_v1;
    void **var_s1;
    ObjRecAt4V2 *temp_a2;
    ObjRecAt12 *temp_s0;
    ObjRecAt4V2 *temp_v0;
    temp_a2 = *arg0;
    temp_s0 = temp_a2->unk0;
    if ((temp_s0->unk0 & ~0xFF) == 0x524E4300) {
        if (arg1 != 0) {
            var_s1 = func_80254600_de(0, (s32) arg0, temp_s0->unk4);
        } else {
            var_s1 = func_80254480_de(0, arg0, temp_s0->unk4);
        }
        if (var_s1 != NULL) {
            temp_v1 = (((Access_u8_3 *)(temp_s0))->field);
            switch (temp_v1) {
            case 1:
                func_802AD4C0_de(&temp_s0->unk12, *var_s1, temp_s0->unk8, temp_s0->unk4);
                break;
            case 2:
#if defined(VERSION_DE)
                func_802AD940_de(temp_s0, *var_s1, temp_s0->unk8, temp_s0->unk4);
#elif defined(VERSION_EU)
                func_802ADBE0_eu(temp_s0, *var_s1, temp_s0->unk8, temp_s0->unk4);
#elif defined(VERSION_EU_X)
                func_802ADC20_eu_x(temp_s0, *var_s1, temp_s0->unk8, temp_s0->unk4);
#elif defined(VERSION_US)
                func_802AD870_us(temp_s0, *var_s1, temp_s0->unk8, temp_s0->unk4);
#elif defined(VERSION_US_REV1)
                func_802B2A10_us_rev1(temp_s0, *var_s1, temp_s0->unk8, temp_s0->unk4);
#endif
                break;
            default:
                break;
            }
            var_s0 = 1;
        } else {
            var_s0 = 0;
        }
    } else if (arg1 == 0) {
        var_s1 = func_80254480_de(0, arg0, temp_a2->unk4);
        if (var_s1 != NULL) {
            temp_v0 = *arg0;
            var_s0 = 1;
            func_802BD3A0_de(*var_s1, temp_v0->unk0, temp_v0->unk4);
        } else {
            var_s0 = 0;
        }
    } else {
        var_s0 = 1;
        goto done;
    }
    func_80253D10_de(0, arg0, var_s1);
done:
    return var_s0;
}
