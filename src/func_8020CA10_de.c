#include "shared/navigation_graph.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020AF9C.h"
#include "types.h"




extern f32 D_800C1D90_de;

extern struct {s32 *unk0;} D_8013B364;
extern s32 func_802744D4_de(void);





void func_8020CA10_de(void *arg0, s32 arg1)
{
  NavigationPoint *entry;
  NavigationSearchNode *node = arg0;
  u16 flags;
  char *new_var;
  s32 *base;
  node->value = D_800C1D8C_de;
  node->key = arg1;
  node->state = -1;
  node->flags = 0;
  node->next = 0;
  base = D_8013B364.unk0;
  new_var = (char *)base + ((arg1 * (*base)) + 8);
  entry = (NavigationPoint *)new_var;
  flags = entry->flags;
  if (flags & 2)
  {
    node->wait = D_800C1D90_de;
  }
  node->object = 0;
  node->ticks = 0;
  node->delay = 0;
  node->platform = 0;
  node->endpoint.x = 0;
  node->endpoint.y = 0;
  node->endpoint.z = 0;
  flags = entry->flags;
  if (flags & 0x40)
  {
    node->ticks = (func_802744D4_de() % 5) + 5;
  }
  flags = entry->flags;
  if (flags & 0x80)
  {
    node->delay = (func_802744D4_de() % 5) + 5;
  }
}
