#include "types.h"
/* Updates the selected equipment icon, description and label for an active player's menu row; the category-1 arm is duplicated behind a short-circuit test of the player and choice arguments as a block-ordering lever that keeps behaviour identical and reproduces the cartridge's branch polarity in the three-case switch. */
typedef struct Node
{
  int pad0;
  struct Node *next;
  char pad8[6];
  unsigned short type;
  char pad10[0x1C];
  int item;
} Node;
typedef struct 
{
  char pad0[8];
  Node *child;
  char padc[0x2C];
  int label;
} Widget;
typedef struct 
{
  char preview[0x4A8];
  int mode;
  int selection;
  int picks[6];
  Widget *widget;
  int state;
} Player;
typedef struct 
{
  void *screen;
  void *menu;
  Player players[4];
  char pad1348[0x28];
  char descriptions[4][0xC0];
} State;
typedef struct 
{
  int item;
  int resource;
  int kind;
  int *label;
} Entry;
extern State *D_800E59E0;
extern Entry D_800E5BC4[];
extern Entry D_800E5B44[];
extern Entry D_800E5B14[];
extern unsigned short D_800E5A1A[][38];
extern void func_8040E8D8_de(void *, int);
extern void func_80439C80_de(void *, int);
extern Widget *func_8040EC30_de(void *, int);
void func_8043B49C_de(int player, int category, int choice)
{
  Entry *table;
  int found;
  Node *node;
  if (D_800E59E0->players[player].state != 0)
  {
    func_8040E8D8_de(D_800E59E0->players[player].widget, 1);
    if (D_800E59E0->players[player].state == 1)
    {
      switch (category)
      {
        case 0:
          table = D_800E5BC4;
          goto render;

        case 1:
          if (player || choice)
        {
          table = D_800E5B44;
          goto render;
        }
        else
        {
          table = D_800E5B44;
          goto render;
        }

        case 2:
          table = D_800E5B14;
          goto render;

      }

    }
    else
    {
      switch (category)
      {
        case 0:

        case 1:
          table = D_800E5BC4;
          goto render;

        case 2:

        case 3:
          table = D_800E5B44;
          goto render;

        case 4:
          table = D_800E5B14;
          goto render;

        case 5:

        default:
          goto hide;

      }

    }
    hide:
    func_80439C80_de(D_800E59E0->descriptions[player], 0);

    func_8040E8D8_de(D_800E59E0->players[player].widget, 0);
    return;
    render:
    if (table)
    {
      node = func_8040EC30_de(D_800E59E0->screen, D_800E5A1A[player][category * 2])->child;
      found = 0;
      do
      {
        if (node->type == 3)
        {
          node->item = table[choice].item;
          found = 1;
        }
        else
        {
          node = node->next;
        }
      }
      while (!found);
      func_80439C80_de(D_800E59E0->descriptions[player], table[choice].resource);
      D_800E59E0->players[player].widget->label = *table[choice].label;
    }

  }
}
