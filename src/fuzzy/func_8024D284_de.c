#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_C76B0/data.h"
#include "types.h"
f32 func_8024E3C4_de(Actor_u1 *arg0);
extern f32 D_800C3C34_de;
extern f32 D_800C8D28;

f32 func_8024D284_de(void *arg0) {
    f32 var_fv0;
    u32 temp_v1;
    void *temp_a0;

    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    if ((*((u8 *) ((u8 *) (arg0) + 0)) == 1) && (*((s32 *) ((u8 *) (arg0) + 372)) <= 0)) {
        return func_8024E3C4_de(arg0);
    }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v1 = *((u32 *) ((u8 *) (*((void **) ((u8 *) (arg0) + 24))) + 0));
    switch (temp_v1) { /* Cases verified against the corpus switch. */
        case 11:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            if ((*((u8 *) ((u8 *) (arg0) + 0)) == 1) && (*((s32 *) ((u8 *) (arg0) + 256)) & 0x300000)) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                return *((f32 *) ((u8 *) (*((void **) ((u8 *) (arg0) + 472))) + 1780));
            }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            return *((f32 *) ((u8 *) (*((void **) ((u8 *) (arg0) + 24))) + 244));
        case 1:
        case 4:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            return *((f32 *) ((u8 *) (*((void **) ((u8 *) (arg0) + 24))) + 48));
        case 8:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_a0 = *((void **) ((u8 *) (arg0) + 24));
            var_fv0 = D_800C3C34_de;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            if (!(*((s32 *) ((u8 *) (temp_a0) + 20)) & 1)) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                return *((f32 *) ((u8 *) (temp_a0) + 28));
            }
            /* Duplicate return node #16. Try simplifying control flow for better match */
            return var_fv0;
        case 7:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            return *((f32 *) ((u8 *) (*((void **) ((u8 *) (arg0) + 24))) + 32));
        case 6:
            return D_800C8D28;
        case 0:
        case 5:
        case 10:
        case 12:
        case 13:
        case 14:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            return *((f32 *) ((u8 *) (*((void **) ((u8 *) (arg0) + 24))) + 28));
    default:
    case 2:
    case 3:
    case 9:
        var_fv0 = 0.0f;
        return var_fv0;
    }
}
