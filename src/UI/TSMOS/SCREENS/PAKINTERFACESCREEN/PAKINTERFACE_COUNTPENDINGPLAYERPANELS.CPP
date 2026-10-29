#include "COMMON/ITEMRECAT20V1.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/PAKINTERFACE_COUNTPENDINGPLAYERPANELS.H"

/* Counts how many of the four 2920-byte entries g_pakProfileScreenState points to have a word at offset 0x58 that is not zero, 0xE or 0x11.
   Adapted from PAKInterface_CountActivePlayerPanels with the extra 0xE and 0x11 exclusions changed. */



s32 PAKInterface_CountPendingPlayerPanels(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (g_pakProfileScreenState->players[i].state != 0 && g_pakProfileScreenState->players[i].state != 0xE && g_pakProfileScreenState->players[i].state != 0x11) {
            count++;
        }
    }
    return count;
}
