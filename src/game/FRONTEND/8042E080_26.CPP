#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

/* Marks a player's record as ready for the next round: clears its pending counters, and on mode 1 advances its tier, gives the newly reached tier its default entry and flags the acquired handle for the notice sent to 0xE74. */

extern void *func_8041B7FC_de(s32, s32);







s32 func_8042FF40_de(s32 unusedA, s32 unusedB, s32 index, s32 mode)
{
  s32 slot = index & 0xFFFF;
  s32 offset = slot * 0xB68;
  void *handle;
  if ((D_800E54A4->players[slot].state) == 0xC)
  {
    handle = func_8041B7FC_de((s32)D_800E54A4->list, slot);
    D_800E54A4->players[slot].nameTimer = 0;
    D_800E54A4->players[slot].namePhase = 2;
    if (mode == 1)
    {
      s32 tier = (D_800E54A4->players[slot].nameCursor) + 1;
      if (tier < 7)
      {
        D_800E54A4->players[slot].nameCursor = tier;
      }
      {
        if (D_800E54A4->players[slot].name[D_800E54A4->players[slot].nameCursor].available == 0) {
          D_800E54A4->players[slot].name[D_800E54A4->players[slot].nameCursor].available = 0x41;
        }
      }
      ((struct Shape_typemap_21 *)(handle))->field_10 = 0xFF;
      Render_PlayFlatSound(0xE74);
    }
  }
 do { return 0; } while (0);
}
