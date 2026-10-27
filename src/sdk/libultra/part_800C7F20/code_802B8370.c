#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"
#include "sdk/libultra/audio/synthesizer.h"












void func_802B32A0_de(void *synth, void *voice, s8 effectMix) {
    s32 new_var;
    s32 mixMagnitude;
    void *Shared_func_802B32A0_de_v0;
    void *voiceFilter;
    SharedRecV4 fn;

    if ((((ObjectStateC_2 *)(voice))->unk_8.v0) != 0) {
        Shared_func_802B32A0_de_v0 = Audio_AllocParam();
        if (Shared_func_802B32A0_de_v0 != 0) {
            new_var = (((struct Shape_typemap_71 *)(synth))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) voice)->unk_8.v1)->state);
            ((ObjectState10_3 *)(Shared_func_802B32A0_de_v0))->unk_8 = 0x10;
            ((ObjectState10_3 *)(Shared_func_802B32A0_de_v0))->unk_4 = new_var;
            if (effectMix < 0) {
                mixMagnitude = -effectMix;
            } else {
                mixMagnitude = (u8) effectMix;
            }
            ((ObjectState10_3 *)(Shared_func_802B32A0_de_v0))->unk_C = mixMagnitude;
            ((ObjectState10_3 *)(Shared_func_802B32A0_de_v0))->unk_0 = 0;
            voiceFilter = ((struct Draw *) ((ObjectStateC_2 *) voice)->unk_8.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, 3, Shared_func_802B32A0_de_v0);
        }
    }
}












void func_802B3350_de(void *synth, void *voice, u8 pan) {
    s32 new_var;
    void *Shared_func_802B3350_de_v0;
    void *voiceFilter;
    SharedRecV5 fn;

    if ((((ObjectStateC_2 *)(voice))->unk_8.v0) != 0) {
        Shared_func_802B3350_de_v0 = Audio_AllocParam();
        if (Shared_func_802B3350_de_v0 != 0) {
            new_var = (((struct Shape_typemap_71 *)(synth))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) voice)->unk_8.v1)->state);
            ((ObjectState10_3 *)(Shared_func_802B3350_de_v0))->unk_8 = 0xC;
            ((ObjectState10_3 *)(Shared_func_802B3350_de_v0))->unk_C = pan;
            ((ObjectState10_3 *)(Shared_func_802B3350_de_v0))->unk_0 = 0;
            ((ObjectState10_3 *)(Shared_func_802B3350_de_v0))->unk_4 = new_var;
            voiceFilter = ((struct Draw *) ((ObjectStateC_2 *) voice)->unk_8.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, 3, Shared_func_802B3350_de_v0);
        }
    }
}












void func_802B33E0_de(void *synth, void *voice, f32 pitchRatio) {
    s32 new_var;
    void *Shared_func_802B33E0_de_v0;
    void *voiceFilter;
    SharedRecV7 fn;

    if ((((ObjectStateC_2 *)(voice))->unk_8.v0) != 0) {
        Shared_func_802B33E0_de_v0 = Audio_AllocParam();
        if (Shared_func_802B33E0_de_v0 != 0) {
            new_var = (((struct Shape_typemap_71 *)(synth))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) voice)->unk_8.v1)->state);
            ((ObjectState10_4 *)(Shared_func_802B33E0_de_v0))->unk_8 = 7;
            ((ObjectState10_4 *)(Shared_func_802B33E0_de_v0))->unk_C = pitchRatio;
            ((ObjectState10_4 *)(Shared_func_802B33E0_de_v0))->unk_0 = 0;
            ((ObjectState10_4 *)(Shared_func_802B33E0_de_v0))->unk_4 = new_var;
            voiceFilter = ((struct Draw *) ((ObjectStateC_2 *) voice)->unk_8.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, 3, Shared_func_802B33E0_de_v0);
        }
    }
}
