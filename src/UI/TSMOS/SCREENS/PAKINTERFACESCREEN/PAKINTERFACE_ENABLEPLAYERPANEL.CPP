#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "FRONTEND/PAKINTERFACE_ENABLEPLAYERPANEL.H"

/* Marks entry i of the 150-byte records g_playerSettingsRecords and sets the words at offsets 0x6C and 0x58
   of entry i of the 2920-byte records g_pakProfileScreenState points to to 2. */



void PAKInterface_EnablePlayerPanel(s32 index) {
    PakProfilePanelState *entry;

    g_gameSettings.playerSettings[index].enabled = 1;
    entry = &g_pakProfileScreenState->players[index];
    entry->back = 2;
    entry->state = 2;
}
