#include "span_16E000/code_80444EC0.h"
#include "types.h"

/* Passes what func_8025CC6C_de returns to func_8025CB0C_de, then calls func_8025E384_de and func_8025E3CC_de,
   and returns one. */
extern s32 func_8025CC6C_de();
extern void func_8025CB0C_de(s32);
extern void func_8025E384_de();
extern void func_8025E3CC_de();

s32 func_80444E7C_de(void) {
    func_8025CB0C_de(func_8025CC6C_de());
    func_8025E384_de();
    func_8025E3CC_de();
    return 1;
}

/* Returns one. Nothing in the cartridge image calls it or stores its address as a word. */
s32 func_80444EB4_de(void) {
    return 1;
}
