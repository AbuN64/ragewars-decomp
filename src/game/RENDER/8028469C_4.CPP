#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "TYPES.H"
#include "stddef.h"
#include "sdk/libgultra_inferred/802AD870_2.H"
#include "sdk/libgultra/part_800C7F20/code_802B2378_2.h"

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80285160_de);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80285174_de);
#endif

void func_80253D10_de(s32, void **, void *);
void * func_80254480_de(s32, void *, s32);
void * func_80254600_de(s32, s32, s32);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
 /* extern */
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
            temp_v1 = temp_s0->unk0; /* the method: low byte of the RNC magic word */
            switch (temp_v1) {
            case 1:
                Rnc_UnpackMethod1(&temp_s0->unk12, *var_s1, temp_s0->unk8, temp_s0->unk4);
                break;
            case 2:
                Rnc_UnpackMethod2(temp_s0, *var_s1, temp_s0->unk8, temp_s0->unk4);
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

#if defined(VERSION_US)
char rodata_unresolved_80285208[8] =
    "Channels";
#endif
