#include "span_16E000/code_80412270.h"
#include "types.h"

/* Looks up the entry with the given identifier among the list func_80411DCC_de returns for what
   func_80299958_de returns, through func_8040EC30_de, and stores two values at offsets 0x58 and 0x5C of
   it. */


extern s32 func_80299958_de();
extern void *func_80411DCC_de(s32);
extern struct Entry_func_80412AC0_de *func_8040EC30_de(void *, u16);

void func_80412AC0_de(s32 identifier, s32 first, s32 second) {
    struct Entry_func_80412AC0_de *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), identifier);

    entry->second = second;
    entry->first = first;
}
