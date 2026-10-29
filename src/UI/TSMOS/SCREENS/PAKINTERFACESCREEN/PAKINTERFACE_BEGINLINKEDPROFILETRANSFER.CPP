#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "FRONTEND/PAKINTERFACE_BEGINLINKEDPROFILETRANSFER.H"

/* Resets the selected player menu record, updates the initiating player state and refreshes the team labels. */


extern void SmpOverlay_SetSlotValue(s32, s32, s32);
extern void PAKInterface_RefreshPlayerPanel(s32);
extern void PAKInterface_UpdatePlayerControlRows(s32);
void PAKInterface_BeginLinkedProfileTransfer(s32 player)
{
  s32 selected = g_pakProfileScreenState->links[0].player;
  PakProfilePanelState *slot;
  PakProfilePanelState *selected_slot;
  SmpOverlay_SetSlotValue(g_pakProfileScreenState->root, selected, 0);
  slot = &g_pakProfileScreenState->players[player];
  slot->state = 17;
  slot->host = 0;
  selected_slot = &g_pakProfileScreenState->players[selected];
  slot = selected_slot;
  slot->back = 2;
  slot->state = 2;
  slot->next = 13;
  slot->sub = 3;
  PAKInterface_RefreshPlayerPanel(selected);
  PAKInterface_UpdatePlayerControlRows(-1);
}
