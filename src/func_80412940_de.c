#include "span_16E000/code_80412270.h"
#include "types.h"

/* Reads the two words of a selected grid cell into caller outputs, after looking up its entry by identifier. Adapted from matched setter func_80412898_de. */





extern s32 func_80299958_de();
extern void *func_80411DCC_de(s32);
extern Entry_func_80412898_de *func_8040EC30_de(void *, unsigned short);

void func_80412940_de(s32 identifier, s32 row, s32 column, s32 *first, s32 *second) {
    Entry_func_80412898_de *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), identifier);

    *first = entry->cells[row * entry->width + column].field_0;
    *second = entry->cells[row * entry->width + column].field_4;
}
