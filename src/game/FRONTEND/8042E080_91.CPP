#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Frontend_IgnorePage67Event(void) {
    return 0;
}
