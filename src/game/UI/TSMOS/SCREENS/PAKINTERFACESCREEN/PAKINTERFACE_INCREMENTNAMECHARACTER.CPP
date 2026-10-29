#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"

extern void *SmpOverlay_GetSlotValue(s32, s32);

/* Advances the selected name character, wrapping past Z to a space. */
void PAKInterface_IncrementNameCharacter(s32 player) {
    u8 value;

    g_pakProfileScreenState->selected[player] = 0;
    SmpOverlay_GetSlotValue(g_pakProfileScreenState->root, player);
    if (g_pakProfileScreenState->players[player].name[g_pakProfileScreenState->players[player].nameCursor].available == 0) {
        g_pakProfileScreenState->players[player].name[g_pakProfileScreenState->players[player].nameCursor].available = 0x41;
    }
    value = g_pakProfileScreenState->players[player].name[g_pakProfileScreenState->players[player].nameCursor].available;
    value++;
    if (value >= 0x5B) {
        value = 0x20;
    }
    g_pakProfileScreenState->players[player].name[g_pakProfileScreenState->players[player].nameCursor].available = value;
}
