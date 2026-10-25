#include "COMMON/ITEMRECAT20V1.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_43.H"

/* Pulses entry i of the 2920-byte records D_800E54A4 points to: takes the sine of i plus the
   entry's phase word at 0x2C + 4i scaled by D_800E1EF8, maps it through the next two constants,
   and stores the unsigned result as the alpha byte at 0x10 of items 0x2C2 and 0x2C3 of the
   entry's window. */

extern struct Resource_func_80419E54_de *func_8040EC30_de(void *, s32);
void func_80434FC4_de(s32 index) {
    float f;
    u32 alpha;
    struct Entry_func_80434FC4_de *entry;
    f = Math_Cosf((float)index + (float)D_800E54A4->selected[index] * D_800E1EF8)
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
    entry = (struct Entry_func_80434FC4_de *)((char *)D_800E54A4 + index * 0xB68);
#if defined(VERSION_DE)
    func_8040EC30_de(entry->window, 0x2E4)->value = alpha;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8040EC30_de(entry->window, 0x2C2)->value = alpha;
#elif defined(VERSION_EU_X)
    func_8040EC30_de(entry->window, 0x2D5)->value = alpha;
#endif
    entry = (struct Entry_func_80434FC4_de *)((char *)D_800E54A4 + index * 0xB68);
#if defined(VERSION_DE)
    func_8040EC30_de(entry->window, 0x2E5)->value = alpha;
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8040EC30_de(entry->window, 0x2C3)->value = alpha;
#elif defined(VERSION_EU_X)
    func_8040EC30_de(entry->window, 0x2D4)->value = alpha;
#endif
}
