#include "MENU_2/STATE.H"
#include "TYPES.H"

#if defined(VERSION_DE)
/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8042342C_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80423434_de(void) {
    return 0;
}
#endif
