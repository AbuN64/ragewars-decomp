#include "COMMON/RESERVED_SHARED_DECLARATIONS.H"
#include "TYPES.H"

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Frontend_ReturnPauseEventZero(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Frontend_ReturnPauseEventZeroAlt(void) {
    return 0;
}
