#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/OBJECTSTATE10_5.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B8370_4.h"
#include "sdk/libultra/audio/synthesizer.h"












void alSynStartVoice(void *synth, void *voice, s32 waveTable) {
    s32 new_var;
    void *Shared_func_802B3540_de_v0;
    void *voiceFilter;
    SharedRecV3 fn;

    if ((((ObjectState1C *)(voice))->unk_8.v0) != 0) {
        Shared_func_802B3540_de_v0 = Audio_AllocParam();
        if (Shared_func_802B3540_de_v0 != 0) {
            new_var = (((struct Shape_typemap_71 *)(synth))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectState1C *) voice)->unk_8.v1)->state);
            ((ObjectState10_5 *)(Shared_func_802B3540_de_v0))->unk_8 = 0xE;
            ((ObjectState10_5 *)(Shared_func_802B3540_de_v0))->unk_C = waveTable;
            ((ObjectState10_5 *)(Shared_func_802B3540_de_v0))->unk_0 = 0;
            ((ObjectState10_5 *)(Shared_func_802B3540_de_v0))->unk_4 = new_var;
            ((ObjectState10_5 *)(Shared_func_802B3540_de_v0))->unk_A = ((ObjectState1C *)(voice))->unk_1A;
            voiceFilter = ((struct Draw *) ((ObjectState1C *) voice)->unk_8.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, 3, Shared_func_802B3540_de_v0);
        }
    }
}
