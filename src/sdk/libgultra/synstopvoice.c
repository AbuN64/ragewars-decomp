#include "sdk/libgultra.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B369C.h"
#include "TYPES.H"


extern void *__allocParam(void);










void alSynStopVoice(struct Shape_typemap_71 *arg0, void *arg1)
{
  int new_var;
  void *Shared_func_802B36F0_de_v0;
  void *temp_a0;
  SharedRecV12 fn;
  if ((((ObjectStateC_2 *)(arg1))->unk_8.v0) != 0)
  {
    Shared_func_802B36F0_de_v0 = __allocParam();
    if (Shared_func_802B36F0_de_v0 != 0)
    {
      new_var = (arg0->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->state);
      ((ObjectStateC_3 *)(Shared_func_802B36F0_de_v0))->unk_8 = 0xF;
      ((ObjectStateC_3 *)(Shared_func_802B36F0_de_v0))->unk_0 = 0;
      ((ObjectStateC_3 *)(Shared_func_802B36F0_de_v0))->unk_4 = new_var;
      temp_a0 = ((struct Draw *) ((ObjectStateC_2 *) arg1)->unk_8.v1)->model;
      fn = ((CallbackStateC_4 *)(temp_a0))->callback;
      fn(temp_a0, 3, Shared_func_802B36F0_de_v0);
    }
  }
}
