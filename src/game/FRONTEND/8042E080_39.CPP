#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_39.H"

/* Resets the selected player menu record, updates the initiating player state and refreshes the team labels. */


extern void func_8041B7B4_de(s32, s32, s32);
extern void Frontend_RefreshPlayerPanel(s32);
extern void func_80433D38_de(s32);
void func_80434D70_de(s32 player)
{
  s32 selected = D_800E54A4->links[0].player;
  State_func_80434D70_de *slot;
  State_func_80434D70_de *selected_slot;
  func_8041B7B4_de(D_800E54A4->root, selected, 0);
  slot = (State_func_80434D70_de *) (((char *) D_800E54A4) + (player * 0xB68));
  slot->state = 17;
  slot->reset = 0;
  selected_slot = (State_func_80434D70_de *) (((char *) D_800E54A4) + (selected * 0xB68));
  slot = selected_slot;
  slot->display = 2;
  slot->state = 2;
  slot->next = 13;
  slot->step = 3;
  Frontend_RefreshPlayerPanel(selected);
  func_80433D38_de(-1);
}
