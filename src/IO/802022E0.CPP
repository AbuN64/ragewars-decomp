#include "include_asm.h"

#ifdef NON_MATCHING
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJ.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
extern s32 D_00202270;
extern s32 D_00202284;
extern u32 D_002022A8;
extern u32 D_002022BC;

void func_802022E0_de(void) {
    u32 *var_t2_2;
    s32 *var_t0;
    s32 *var_t1;
    s32 *var_t2;
    s32 temp_t5;
    u32 *var_t0_2;
    u32 *var_t1_2;
    u32 temp_t5_2;

    var_t0 = &D_00202270;
    var_t1 = &D_00202284;
    var_t2 = (s32 *)0x80000180;
    do {
        temp_t5 = *var_t0;
        var_t0 += 1;
        *var_t1 = *var_t2;
        var_t1 += 1;
        *var_t2 = temp_t5;
        var_t2 += 1;
    } while (var_t0 != &D_00202284);
    var_t0_2 = &D_002022A8;
    var_t1_2 = &D_002022BC;
    var_t2_2 = (u32 *)0x80000000U;
    do {
        temp_t5_2 = *var_t0_2;
        var_t0_2 += 1;
        *var_t1_2 = *var_t2_2;
        var_t1_2 += 1;
        *var_t2_2++ = temp_t5_2;
    } while (var_t0_2 != &D_002022BC);
    Libgultra_TrwCacheFlush0();
    Libgultra_TrwCacheFlush1();
    D_800F3468 = -0x802;
}
#else
INCLUDE_ASM("span_1000", func_802022E0_de);
#endif
