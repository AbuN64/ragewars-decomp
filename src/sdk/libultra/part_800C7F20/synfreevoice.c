#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"

extern void *Audio_AllocParam(void);
extern void _freePVoice(s32 arg0, void *arg1);











void alSynFreeVoice(void *synth, void *voice) {
    void *Shared_func_802B3200_de_v0;
    void *voiceFilter;
    SharedRecV8 fn;
    s32 new_var;

    if ((((ObjectStateC_2 *)(voice))->unk_8.v0) != 0) {
        if ((((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) voice)->unk_8.v1)->state) != 0) {
            Shared_func_802B3200_de_v0 = Audio_AllocParam();
            if (Shared_func_802B3200_de_v0 != 0) {
                new_var = (((struct Shape_typemap_71 *)(synth))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) voice)->unk_8.v1)->state);
                ((ObjectLinks10_2 *)(Shared_func_802B3200_de_v0))->unk_8 = 0;
                ((ObjectLinks10_2 *)(Shared_func_802B3200_de_v0))->unk_4 = new_var;
                ((ObjectLinks10_2 *)(Shared_func_802B3200_de_v0))->unk_C = ((ObjectStateC_2 *)(voice))->unk_8.v0;
                voiceFilter = ((struct Draw *) ((ObjectStateC_2 *) voice)->unk_8.v1)->model;
                fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
                fn(voiceFilter, 3, Shared_func_802B3200_de_v0);
                ((ObjectStateC_2 *)(voice))->unk_8.v0 = 0;
            }
        } else {
            _freePVoice((s32) synth, ((ObjectStateC_2 *)(voice))->unk_8.v0);
            ((ObjectStateC_2 *)(voice))->unk_8.v0 = 0;
        }
    }
}
