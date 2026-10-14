#include "span_16E000/code_8042F988.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_16E000/code_80405DC0.h"
#include "span_16E000/code_8042F988.h"
#include "types.h"

/* Updates a player menu state from controller status, available saves, and the current menu phase. */

extern PakMenuController *D_800E54A4;

extern s32 func_80404F04_de(s32);
extern s32 func_80404BE8_de(void *, s32, s32 *);
extern s32 func_80434638_de(s32, s32);
extern s32 func_80435128_de(s32);
extern s32 func_80435184_de(s32);
extern s32 func_8043590C_de(s32);
extern s32 func_802744D4_de(void);
extern void func_804322AC_de(s32);
void func_80433610_de(s32 player)
{
  s32 random;
  s32 done = 1;
  s32 result;
  s32 status = func_80404F04_de(player);
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
        if (func_80404BE8_de(((D_800E25A4)[D_80152789]), player, &result) == one)
#else
        if (func_80404BE8_de((D_800D36D4), player, &result) == one)
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
            random = func_802744D4_de();
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
  func_804322AC_de(player);
}
