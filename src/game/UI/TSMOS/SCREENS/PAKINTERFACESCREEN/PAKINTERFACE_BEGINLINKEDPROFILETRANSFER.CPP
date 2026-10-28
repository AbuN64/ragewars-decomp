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
  s32 selected = D_800E54A4->links[0].player;
  StatePAKInterfaceBeginLinkedProfileTransfer *slot;
  StatePAKInterfaceBeginLinkedProfileTransfer *selected_slot;
  SmpOverlay_SetSlotValue(D_800E54A4->root, selected, 0);
  slot = (StatePAKInterfaceBeginLinkedProfileTransfer *) (((char *) D_800E54A4) + (player * 0xB68));
  slot->state = 17;
  slot->reset = 0;
  selected_slot = (StatePAKInterfaceBeginLinkedProfileTransfer *) (((char *) D_800E54A4) + (selected * 0xB68));
  slot = selected_slot;
  slot->display = 2;
  slot->state = 2;
  slot->next = 13;
  slot->step = 3;
  PAKInterface_RefreshPlayerPanel(selected);
  PAKInterface_UpdatePlayerControlRows(-1);
}
