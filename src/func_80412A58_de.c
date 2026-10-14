#include "span_16E000/code_80412270.h"
#include "types.h"

/* Looks up the entry with the given identifier among the list func_80411DCC_de returns for what
   func_80299958_de returns, through func_8040EC30_de, and stores three bytes at offsets 0x55, 0x57 and 0x53. */
extern s32 func_80299958_de();
extern void *func_80411DCC_de(s32);
extern u8 *func_8040EC30_de(void *, unsigned short);

void func_80412A58_de(s32 identifier, s32 first, s32 second, s32 third) {
    u8 *entry = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), identifier);

    entry[0x55] = second;
    entry[0x57] = third;
    entry[0x53] = first;
}
