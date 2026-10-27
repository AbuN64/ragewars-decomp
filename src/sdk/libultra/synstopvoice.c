#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"
#include "TYPES.H"
#include "sdk/libultra/audio/synthesizer.h"











void alSynStopVoice(struct Shape_typemap_71 *synth, void *voice)
{
  int new_var;
  void *Shared_func_802B36F0_de_v0;
  void *voiceFilter;
  SharedRecV12 fn;
  if ((((ObjectStateC_2 *)(voice))->unk_8.v0) != 0)
  {
    Shared_func_802B36F0_de_v0 = Audio_AllocParam();
    if (Shared_func_802B36F0_de_v0 != 0)
    {
      new_var = (synth->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) voice)->unk_8.v1)->state);
      ((ObjectStateC_3 *)(Shared_func_802B36F0_de_v0))->unk_8 = 0xF;
      ((ObjectStateC_3 *)(Shared_func_802B36F0_de_v0))->unk_0 = 0;
      ((ObjectStateC_3 *)(Shared_func_802B36F0_de_v0))->unk_4 = new_var;
      voiceFilter = ((struct Draw *) ((ObjectStateC_2 *) voice)->unk_8.v1)->model;
      fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
      fn(voiceFilter, 3, Shared_func_802B36F0_de_v0);
    }
  }
}
