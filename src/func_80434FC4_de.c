#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80434F4C.h"
#include "types.h"
/* Pulses entry i of the 2920-byte records D_800E54A4 points to: takes the sine of i plus the
   entry's phase word at 0x2C + 4i scaled by D_800E1EF8, maps it through the next two constants,
   and stores the unsigned result as the alpha byte at 0x10 of items 0x2C2 and 0x2C3 of the
   entry's window. */
extern struct Entry_func_80434FC4_de *D_800E54A4;

extern struct Resource_func_80419E54_de *func_8040EC30_de(void *, s32);
void func_80434FC4_de(s32 index) {
    float f;
    u32 alpha;
    struct Entry_func_80434FC4_de *entry;
    f = func_802B6560_de((float)index + (float)D_800E54A4->phases[index] * D_800E1EF8)
        * (*(&D_800E1EF8 + 1)) + D_800DDED0;
    if (f >= (*(&D_800DDED0 + 1))) {
        goto large;
    }
    alpha = (s32)f;
    goto converted;
large:
    alpha = (s32)(f - (*(&D_800DDED0 + 1)));
    alpha |= 0x80000000;
converted:
    entry = &D_800E54A4[index];
#if defined(VERSION_DE)
    func_8040EC30_de(entry->window, 0x2E4)->value = alpha;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8040EC30_de(entry->window, 0x2C2)->value = alpha;
#elif defined(VERSION_EU_X)
    func_8040EC30_de(entry->window, 0x2D5)->value = alpha;
#endif
    entry = &D_800E54A4[index];
#if defined(VERSION_DE)
    func_8040EC30_de(entry->window, 0x2E5)->value = alpha;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8040EC30_de(entry->window, 0x2C3)->value = alpha;
#elif defined(VERSION_EU_X)
    func_8040EC30_de(entry->window, 0x2D4)->value = alpha;
#endif
}
