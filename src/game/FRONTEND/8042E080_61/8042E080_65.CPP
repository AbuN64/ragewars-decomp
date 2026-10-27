#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Frontend_ReturnProfileEventZero(void) {
    return 0;
}
