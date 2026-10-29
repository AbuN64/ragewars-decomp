#include "../../../sdk/include/libgultra_inferred/IDENTIFIER.H"
#include "include_asm.h"
#include "../../../sdk/include/PERIPHERAL_PORT_BYTE_VIEWS.H"
#include "TYPES.H"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
void Menu_EmptyResourceRangeHookEuX(void) { }
#endif

#if defined(VERSION_US)
/** Perform no operation. */
void Menu_EmptyResourceRangeHookUs(void) {
}
#endif

#if !(defined(VERSION_DE))
s32 Menu_ClassifyResourceRange(s32 resourceId) {
    if ((resourceId == 0x7CF) || (resourceId == 0xBB7) || (resourceId == 0xF9F) ||
        (resourceId == 0x1387) || (resourceId == 0x176F) || (resourceId == 0x1B57) ||
        (resourceId == 0x63)) {
        return 0;
    }
    if ((u32)(resourceId - 0x3E8) < 0x3E8) {
        return 1;
    }
    if ((u32)(resourceId - 0x7D0) < 0x3E8) {
        return 2;
    }
    if ((u32)(resourceId - 0xBB8) < 0x3E8) {
        return 3;
    }
    if ((u32)(resourceId - 0xFA0) < 0x3E8) {
        return 4;
    }
    if ((u32)(resourceId - 0x1388) < 0x3E8) {
        return 5;
    }
    if ((u32)(resourceId - 0x1770) < 0x3E8) {
        return 6;
    }
    return -1;
}
#endif

#if defined(VERSION_US)
char s_IdentifierMRegionSText[8] =
    "MRegionS";
#endif
