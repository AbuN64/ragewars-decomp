#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A6AC0.h"
#include "types.h"

extern f32 D_800D2988;
extern void func_802796F4_de(void *arg0, void *arg1);





void func_802A5EE0_de(void *arg0)
{
  void *node;
  char *new_var;
  void *next;
  f32 value;
  s32 count;
  node = ((ObjectLinks7598 *)(arg0))->unk_7594;
  if (node != 0)
  {
    do
    {
      value = (((ObjectLinks14_2 *)(node))->unk_8 = (((ObjectLinks14_2 *)(node))->unk_8) - D_800D2988);
      next = ((ObjectLinks14_2 *)(node))->next;
      if (value <= 0.0f)
      {
        value += ((ObjectLinks14_2 *)(node))->unk_C;
        ((ObjectLinks14_2 *)(node))->unk_8 = value;
        if (value < 0.0f)
        {
          ((ObjectLinks14_2 *)(node))->unk_8 = 0.0f;
        }
        (((struct CallbackState1C *) ((char *) node))->callback)(node);
        count = (((struct func_8022BC04_S3 *) (new_var = (char *) node))->unk10) - 1;
        ((ObjectLinks14_2 *)(node))->unk_10 = count;
        if (count <= 0)
        {
          func_802796F4_de(&((ObjectLinks7598 *)(arg0))->unk_7588, node);
        }
      }
      node = next;
    }
    while (node != 0);
  }
}
