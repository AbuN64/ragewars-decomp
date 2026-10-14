#include "span_16E000/code_8043962C.h"
#include "types.h"

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80439750_de(void) {
    return 0;
}
