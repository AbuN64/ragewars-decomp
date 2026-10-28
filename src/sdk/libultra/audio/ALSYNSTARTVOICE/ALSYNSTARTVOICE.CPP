#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/OBJECTSTATE10_5.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/ALSYNSTARTVOICE.H"
#include "sdk/libultra/audio/synthesizer.h"

/* code_802B8370_4.c */
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

/* 8025DE50_11.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802B35D4_de_padding_B41D4[12] = { 0xF7, 0xB4, 0x00, 0x38, 0x44, 0x87, 0xA0, 0x00, 0xAF, 0xB1, 0x00, 0x14 };
#endif

/* 8025DE50_19.CPP */
/* 8025DE50_19.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_802B3874_eu_padding_B4474[12] = { 0xAF, 0xB4, 0x00, 0x20, 0x24, 0x14, 0x00, 0x01, 0xAF, 0xB1, 0x00, 0x14 };
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
unsigned char D_auto_func_802B86A4_us_rev1_padding_B92A4[8] = { 0x03, 0xE0, 0x00, 0x08, 0x27, 0xBD, 0x00, 0x18 };
#endif

/* 8025DE50_9.CPP */
#if defined(VERSION_US)
unsigned char s_aternText[12] = { 0x61, 0x74, 0x65, 0x72, 0x6E, 0x5F, 0x74, 0x09, 0x6D, 0x5F, 0x71, 0x47 };
#endif
