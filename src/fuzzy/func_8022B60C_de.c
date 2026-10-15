#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/gameplay_reactions.h"
#include "types.h"
void func_80216488_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_80219A40_de(struct Shared_ReactionActor *arg0, void *arg1, struct Shared_ReactionInteraction *arg2);
void func_8022B60C_de(Shared_ReactionActor *arg0, f32 arg1, s32 arg2) {
    Shared_ReactionInteraction sp18;
    f32 temp_fv0;
    f32 var_fv0f;

    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0 = *((f32 *) ((u8 *) (arg0) + 4800)) + arg1;
    var_fv0f = *D_800C9190_de;
    if (!(var_fv0f <= temp_fv0)) {
        var_fv0f = temp_fv0;
    }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((f32 *) ((u8 *) (arg0) + 4800)) = var_fv0f;
    if (*D_800C9190_de <= var_fv0f) {
        func_80216488_de(&sp18, arg2, 0x40000, 0x41CCCCCC, 0x80, 0);
        /* FAKEMATCH: Native reaction buffer is at byte offset 0x170 in the actor. */
        func_80219A40_de(arg0, (void *)((u8 *)arg0 + 0x170), &sp18);
    }
}
