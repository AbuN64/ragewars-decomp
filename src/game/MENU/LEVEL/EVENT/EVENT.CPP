#include "include_asm.h"


#if defined(VERSION_US_REV1)
/* Maps an id from 1 to 33 to the address of its data block, returning 0 for any other id. */
#include "TYPES.H"
#include "MENU/EVENT.H"


void *Level_GetScreenEventTable(s32 id) {
    switch (id) {
    case 1:
        return g_packedCodeAddress24_00435F70;
    case 31:
        return g_packedCodeAddress24_0043630C;
    case 32:
        return g_packedCodeAddress24_00436634;
    case 7:
        return g_packedCodeAddress24_00420E00;
    case 8:
        return g_packedCodeAddress24_0043C1D0;
    case 10:
        return g_packedCodeAddress24_00429058;
    case 15:
        return g_packedCodeAddress24_004290E8;
    case 3:
        return g_packedCodeAddress24_00424528;
    case 4:
        return g_packedCodeAddress24_0042359C;
    case 6:
        return g_packedCodeAddress24_00439390;
    case 5:
        return g_packedCodeAddress24_00436FE4;
    case 11:
        return g_packedCodeAddress24_00423930;
    case 12:
        return g_packedCodeAddress24_00437454;
    case 13:
        return g_packedCodeAddress24_0043962C;
    case 16:
        return g_packedCodeAddress24_0041DF24;
    case 17:
        return g_packedCodeAddress24_0042DB38;
    case 18:
        return g_packedCodeAddress24_0043905C;
    case 9:
        return g_packedCodeAddress24_00437868;
    case 30:
        return g_packedCodeAddress24_00437B98;
    case 20:
        return g_packedCodeAddress24_0042BCB0;
    case 21:
        return g_packedCodeAddress24_00429B74;
    case 23:
        return g_packedCodeAddress24_0041F118;
    case 14:
        return g_packedCodeAddress24_0042931C;
    case 19:
        return g_packedCodeAddress24_00435C54;
    case 22:
        return g_packedCodeAddress24_00423B88;
    case 24:
        return g_packedCodeAddress24_00439938;
    case 25:
        return g_packedCodeAddress24_0042247C;
    case 27:
        return g_packedCodeAddress24_00421E00;
    case 26:
        return g_packedCodeAddress24_0042DFF0;
    case 29:
        return g_packedCodeAddress24_0041C5EC;
    case 28:
        return g_packedCodeAddress24_00421A88;
    case 33:
        return g_packedCodeAddress24_0043A014;
    default:
        return 0;
    }
}
#endif
#if VERSION_DE
INCLUDE_ASM("ovl_80400000", Level_GetScreenEventTable);
#endif
#if VERSION_US
INCLUDE_DATA("ovl_80400000", D_auto_func_8043C730_us_rev1_padding_1A072C);
#endif
#if VERSION_EU_X
INCLUDE_DATA("ovl_80400000", D_auto_func_8043C730_us_rev1_padding_12D55C);
#endif
#if VERSION_EU
INCLUDE_DATA("ovl_80400000", D_auto_func_8043C730_us_rev1_padding_1B342C);
#endif
#if VERSION_DE
INCLUDE_DATA("ovl_80400000", D_auto_func_8043C730_us_rev1_padding_1A254C);
#endif
#if VERSION_EU
INCLUDE_ASM("ovl_80400000", Level_GetScreenEventTable);
#endif
#if VERSION_EU_X
INCLUDE_ASM("ovl_80400000", Level_GetScreenEventTable);
#endif
#if VERSION_US
INCLUDE_ASM("ovl_80400000", Level_GetScreenEventTable);
#endif
