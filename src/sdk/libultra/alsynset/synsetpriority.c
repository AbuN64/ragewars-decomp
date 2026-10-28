#include "include_asm.h"
#include "sdk/libgultra.h"
#include "sdk/OBJECTSTATE10_5.H"

/** Store the supplied halfword at offset 0x16. */
void alSynSetPriority(void *unused, void *object, unsigned short value) {
    func_802B8540_S1 *record = object;
    record->unk16 = value;
}

#if defined(VERSION_US)
char rodata_unresolved_802B33A8[8] =
    "\020m_nCurr";
#endif
