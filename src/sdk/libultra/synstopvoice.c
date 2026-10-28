#include "COMMON/ALPARAM_S.H"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"
#include "TYPES.H"
#include "sdk/libultra/audio/synthesizer.h"











void alSynStopVoice(struct AudioSynthParamSamplesView *synth, void *voice)
{
  int new_var;
  void *Shared_func_802B36F0_de_v0;
  void *voiceFilter;
  SharedRecV12 fn;
  if ((((AudioVoicePhysicalLinkView *)(voice))->pvoice.v0) != 0)
  {
    Shared_func_802B36F0_de_v0 = Audio_AllocParam();
    if (Shared_func_802B36F0_de_v0 != 0)
    {
      new_var = (synth->paramSamples) + (((struct AudioPhysicalVoiceOffsetView *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->offset);
      ((AudioStopVoiceUpdate *)(Shared_func_802B36F0_de_v0))->type = AL_FILTER_STOP_VOICE;
      ((AudioStopVoiceUpdate *)(Shared_func_802B36F0_de_v0))->next = 0;
      ((AudioStopVoiceUpdate *)(Shared_func_802B36F0_de_v0))->delta = new_var;
      voiceFilter = ((struct Draw *) ((AudioVoicePhysicalLinkView *) voice)->pvoice.v1)->model;
      fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
      fn(voiceFilter, AL_FILTER_ADD_UPDATE, Shared_func_802B36F0_de_v0);
    }
  }
}
