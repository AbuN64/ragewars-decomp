#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "COMMON/NODERECAT2A8.H"
#include "FRONTEND/8040B45C_22.H"

#if !(defined(VERSION_US))
/* Sets bit 23 of the flag word at offset 8 of a record unless Defs_GetMemorySize reports 0x400000 for
   it, in which case the bit is cleared; then stores what func_8040C3BC_de returns at offset 0x14.
   Returns zero. */


extern s32 Defs_GetMemorySize(struct RecordRecAt14 *);
extern s32 Frontend_GetScreenModePalette();

s32 Pak_UpdateScreenModeAvailability(struct RecordRecAt14 *record) {
    if (Defs_GetMemorySize(record) != 0x400000) {
        record->flags |= 0x800000;
    } else {
        record->flags &= ~0x800000;
    }
    record->value = Frontend_GetScreenModePalette();
    return 0;
}

/* Calls func_8040C2F8_de and returns zero. */

s32 Pak_StartScreenModeFade(void) {
    Frontend_StartScreenModeFade();
    return 0;
}
#endif
