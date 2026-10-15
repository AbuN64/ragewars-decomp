#include "types.h"
/* Binary search followed by the original backward duplicate scan. */
s32 func_802A00B0_de(s32 *index, u8 *base, s32 count, void *key,
                     s32 stride, s32 (*compare)(void *, void *))
{
    s32 low = 0;
    s32 half = 0;
    s32 high = count - 1;
    s32 span = high;
    s32 result;
    u8 *entry;
    u8 *previous;
    if (index != 0) *index = 0;
    if (count != 0) {
        while (low <= high) {
            half = span >> 1;
            entry = base + (low + half) * stride;
            result = compare(key, entry);
            if (result < 0) {
                high = high - 1 - half;
            } else if (result > 0) {
                low = low + 1 + half;
            } else {
                previous = entry;
                if (previous > base) previous -= stride;
                while (previous > base) {
                    result = compare(key, previous);
                    previous -= stride;
                    if (result != 0) break;
                    half--;
                }
                if (index != 0) *index = low + half;
                return 1;
            }
            span = high - low;
        }
        if (index != 0) *index = low + half;
    }
    return 0;
}
