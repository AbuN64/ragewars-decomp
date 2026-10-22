#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "COMMON/NODERECAT2A8.H"
#include "FRONTEND/8040B45C_22.H"

#if !(defined(VERSION_US))
/* Sets bit 23 of the flag word at offset 8 of a record unless func_80265350_de reports 0x400000 for
   it, in which case the bit is cleared; then stores what func_8040C3BC_de returns at offset 0x14.
   Returns zero. */


extern s32 func_80265350_de(struct RecordRecAt14 *);
extern s32 func_8040C3BC_de();

s32 func_80445590_de(struct RecordRecAt14 *record) {
    if (func_80265350_de(record) != 0x400000) {
        record->flags |= 0x800000;
    } else {
        record->flags &= ~0x800000;
    }
    record->value = func_8040C3BC_de();
    return 0;
}

/* Calls func_8040C2F8_de and returns zero. */

s32 func_804455EC_de(void) {
    func_8040C2F8_de();
    return 0;
}
#endif
