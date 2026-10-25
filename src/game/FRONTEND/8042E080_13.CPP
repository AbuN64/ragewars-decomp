#include "COMMON/NAME.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/MENURECAT24.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_45.H"
#include "FRONTEND/8042E080_46.H"
#include "FRONTEND/8042E080_63.H"

/* Updates a player menu state from controller status, available saves, and the current menu phase. */


extern s32 Pak_GetStatus(s32);
extern s32 Pak_FindNoteByName(void *, s32, s32 *);
extern s32 func_80434638_de(s32, s32);
extern s32 func_80435128_de(s32);
extern s32 func_80435184_de(s32);
extern s32 func_8043590C_de(s32);
extern s32 Nav_NextRandom(void);
extern void Frontend_RefreshPlayerPanel(s32);
void func_80433610_de(s32 player)
{
  s32 random;
  s32 done = 1;
  s32 result;
  s32 status = Pak_GetStatus(player);
  short one = done;
  do
  {
    switch (status)
    {
      case -4:

      case -3:

      case -1:
        D_800E54A4->players[player].state = 3;
        break;

      case 0:
        if (D_800E54A4->phase == 6)
      {
        D_800E54A4->players[player].state = D_800E54A4->players[player].next;
      }
      else
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        if (Pak_FindNoteByName(((D_800E25A4)[g_languageIndex]), player, &result) == one)
#else
        if (Pak_FindNoteByName((D_800D36D4), player, &result) == one)
#endif
      {
        if (func_80434638_de(player, result) == one)
        {
          D_800E54A4->players[player].state = D_800E54A4->players[player].next;
          switch (D_800E54A4->phase)
          {
            case 0:
              if (func_80435128_de(player) == (-1))
            {
              D_800E54A4->players[player].state = 24;
            }
              break;

            case 7:
              if (func_80435184_de(player) == one)
            {
              D_800E54A4->players[player].state = 15;
            }
              break;

            case 2:
              if (func_80435184_de(player) == one)
            {
              D_800E54A4->players[player].state = 25;
            }
            else
              if ((D_800E54A4->players[player].host == one) && (func_80435128_de(player) == (-1)))
            {
              D_800E54A4->players[player].state = 24;
            }
              break;

            case 5:
              if (func_8043590C_de(player) == 0)
            {
              D_800E54A4->players[player].state = 21;
            }
              break;

          }

        }
      }
      else
      {
        switch (D_800E54A4->phase)
        {
          case 0:

          case 1:

          case 7:
            random = Nav_NextRandom();
            D_800E54A4->players[player].state = 15;
            D_800E54A4->players[player].profile = (random % 9999999) + 1;
            break;

          case 5:
            D_800E54A4->players[player].state = 21;
            break;

          case 4:
            D_800E54A4->players[player].state = D_800E54A4->players[player].next;
            break;

          case 2:

          case 3:
            D_800E54A4->players[player].state = 25;
            break;

        }

      }
        break;

      case -5:

      case -2:

      default:
        D_800E54A4->players[player].state = one;
        break;

    }

  }
  while (done == 0);
  Frontend_RefreshPlayerPanel(player);
}
