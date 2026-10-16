#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/gameplay_reactions.h"
void func_80216488_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
struct CallbackState114;
void func_802171FC_de(void *arg0, struct CallbackState114 *arg1);
void func_8028CCDC_de(void *arg0, s32 arg1, s32 arg2) {
    Shared_ReactionInteraction sp18;
    s32 temp_s2;
    s32 var_s1;
    void **var_s0;
    void *temp_a0;

    var_s1 = 0;
    func_80216488_de(&sp18, 0, arg1, 0x42CCCCCC, arg2, 0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_s2 = *((s32 *) ((u8 *) (arg0) + 3924));
    if (temp_s2 > 0) {
        var_s0 = arg0 + 0xE54;
        do {
            temp_a0 = *var_s0;
            var_s0 += 1;
            var_s1 += 1;
            func_802171FC_de(temp_a0, temp_a0 + 0x170);
        } while (var_s1 < temp_s2);
    }
}
