#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8028FC98.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
extern void func_80290950_de(void *arg0, void *arg1);
extern void func_80246184_de(void *arg0);
void *func_802908C0_de(void *arg0)
{
  void *new_var;
  void *node;
  struct ListNode80290528 *next;
  if ((((ObjectLinks3C0C *)(arg0))->unk_3C00) == 0)
  {
    func_80290950_de(arg0, ((ObjectLinks3C0C *)arg0)->unk_3C08);
  }
  node = ((ObjectLinks3C0C *)(arg0))->unk_3C00;
  next = ((ObjectLinks3C0C *)(arg0))->next;
  ((ObjectLinks3C0C *)(arg0))->unk_3C00 = ((ObjectLinks1E0 *)(node))->unk_1DC;
  if (next != 0)
  {
    next->previous = node;
  }
  new_var = ((ObjectLinks3C0C *)(arg0))->next;
  ((ObjectLinks1E0 *)(node))->unk_1D8 = 0;
  ((ObjectLinks1E0 *)(node))->unk_1DC = new_var;
  ((ObjectLinks3C0C *)(arg0))->next = node;
  if ((((ObjectLinks3C0C *)(arg0))->unk_3C08) == 0)
  {
    ((ObjectLinks3C0C *)(arg0))->unk_3C08 = node;
  }
  ((ObjectLinks1E0 *)(node))->unk_1D0 |= 1;
  func_80246184_de(node);
  ((ObjectLinks1E0 *)(node))->unk_1C8 = 0;
  return node;
}
