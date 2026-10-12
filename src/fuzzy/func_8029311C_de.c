#include "common/types_1dc8418c21db.h"
#include "gfx.h"
#include "resident_event_handler.h"
#include "shared/gbi.h"
#include "span_1000/code_8022F3E8.h"
#include "span_1000/code_80291054.h"
#include "types.h"
void func_8029311C_de(void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Gfx *temp_a1;
    Gfx *temp_a3;
    Gfx *temp_t0;
    Gfx *temp_v0;
    s32 var_a2;
    s32 var_a3;
    s32 var_t1;
    s32 var_v1;

    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    if (*((u8 *) ((u8 *) (arg1) + 3)) != 0) {
        temp_a1 = D_80110634;
        temp_v0 = D_80110634 + 1;
        D_80110634 = temp_v0;
        gDPPipeSync(temp_a1);
        
        D_80110634 = temp_v0 + 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        gDPSetCycleType(temp_v0, G_CYC_1CYCLE);
        func_8026925C_de(0x13);
        func_80268CE0_de(0x19U);
        var_t1 = arg4;
        temp_a3 = D_80110634;
        temp_t0 = D_80110634 + 1;
        D_80110634 = temp_t0;
        D_80110634 = temp_t0 + 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        gDPSetPrimColor(temp_a3, 0xFF, 0xFF, ((u8 *)arg1)[0], ((u8 *)arg1)[1], ((u8 *)arg1)[2], ((u8 *)arg1)[3]);
        if (var_t1 < 0) {
            var_t1 = 0;
        }
        var_v1 = arg5;
        if (var_v1 < 0) {
            var_v1 = 0;
        }
        var_a2 = arg2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_t0->words.w0 = (u32) (((var_t1 & 0x3FF) << 0xE) | (((var_v1 & 0x3FF) * 4) | 0xF6000000));
        if (var_a2 < 0) {
            var_a2 = 0;
        }
        var_a3 = arg3;
        if (var_a3 < 0) {
            var_a3 = 0;
        }
        temp_t0->words.w1 = ((var_a2 & 0x3FF) << 0xE) | ((var_a3 & 0x3FF) * 4);
    }
}
