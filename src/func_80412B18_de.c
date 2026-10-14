#include "span_16E000/code_80412270.h"
#include "types.h"

/* Looks up the entry with the given identifier among the list func_80411DCC_de returns for what
   func_80299958_de returns, through func_8040EC30_de, and reports its bytes at offsets 0x4C and 0x4D. */


extern s32 func_80299958_de();
extern void *func_80411DCC_de(s32);
extern struct Entry_func_80412B18_de *func_8040EC30_de(void *, unsigned short);

void func_80412B18_de(s32 identifier, s32 *first, s32 *second) {
    struct Entry_func_80412B18_de *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), identifier);

    *first = entry->first;
    *second = entry->second;
}
