#include "include_asm.h"

#include "TYPES.H"

s32 func_802A00B0_de(s32 *index, u8 *base, s32 count, void *key,
                     s32 stride, s32 (*compare)(void *, void *)) {
    s32 low = 0;
    s32 half = 0;
    s32 high = count - 1;
    s32 result;
    u8 *entry;
    if (index != 0) {
        *index = 0;
    }
    if (count != 0) {
        while (low <= high) {
            half = (high - low) >> 1;
            entry = base + (low + half) * stride;
            result = compare(key, entry);
            if (result < 0) {
                goto less;
            }
            if (result != 0) {
                goto more;
            }

            while ((entry -= stride) > base && compare(key, entry) == 0) {
                half--;
            }
            if (index != 0) {
                *index = low + half;
            }
            return 1;
more:
            low += half + 1;
            continue;
less:
            high -= half + 1;
        }
        if (index != 0) {
            *index = low + half;
        }
    }
    return 0;
}
