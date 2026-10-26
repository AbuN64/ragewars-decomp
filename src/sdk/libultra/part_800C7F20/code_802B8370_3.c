#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/OBJECTSTATE10_5.H"
#include "TYPES.H"

extern void *Audio_AllocParam(void);
extern s32 func_802B3CD0_de(void *arg0, s32 arg3);











void func_802B3480_de(void *synth, void *voice, s16 arg2, s32 rampTime) {
    s32 new_var;
    void *Shared_func_802B3480_de_v0;
    void *voiceFilter;
    SharedRecV10 fn;

    if ((((ObjectStateC_2 *)(voice))->unk_8.v0) != 0) {
        Shared_func_802B3480_de_v0 = Audio_AllocParam();
        if (Shared_func_802B3480_de_v0 != 0) {
            new_var = (((struct Shape_typemap_71 *)(synth))->field_1C) + (((struct IntegerStateDC_2 *) ((ObjectStateC_2 *) voice)->unk_8.v1)->state);
            ((ObjectState14_2 *)(Shared_func_802B3480_de_v0))->unk_8 = 0xB;
            ((ObjectState14_2 *)(Shared_func_802B3480_de_v0))->unk_C = (s32) arg2;
            ((ObjectState14_2 *)(Shared_func_802B3480_de_v0))->unk_4 = new_var;
            ((ObjectState14_2 *)(Shared_func_802B3480_de_v0))->unk_10 = func_802B3CD0_de(synth, rampTime);
            ((ObjectState14_2 *)(Shared_func_802B3480_de_v0))->unk_0 = 0;
            voiceFilter = ((struct Draw *) ((ObjectStateC_2 *) voice)->unk_8.v1)->model;
            fn = ((CallbackStateC_4 *)(voiceFilter))->callback;
            fn(voiceFilter, 3, Shared_func_802B3480_de_v0);
        }
    }
}

#if defined(VERSION_US)
char rodata_unresolved_802B3468[8] =
    "e_t\022CROM";
#endif
