#include "span_16E000/code_80412270.h"
#include "types.h"

/* Looks up the entry with the given identifier among the list func_80411DCC_de returns for what func_80299958_de returns, through func_8040EC30_de, and stores two words into the eight-byte cell at the given row and column of its cell table at 0x44, whose row width is the byte at 0x4B.
   Adapted from func_80412A58_de with the three byte stores replaced by the two cell-word stores changed. */





extern s32 func_80299958_de();
extern void *func_80411DCC_de(s32);
extern Entry_func_80412898_de *func_8040EC30_de(void *, unsigned short);

void func_80412898_de(s32 identifier, s32 row, s32 column, s32 first, s32 second) {
    Entry_func_80412898_de *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), identifier);

    entry->cells[row * entry->width + column].field_0 = first;
    entry->cells[row * entry->width + column].field_4 = second;
}
