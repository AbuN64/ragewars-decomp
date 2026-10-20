#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8043601C_de(void) {
    return 0;
}
