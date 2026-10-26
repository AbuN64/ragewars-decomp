#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "COMMON/S1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "UTIL/8025DBA0.H"
#include "sdk/libgultra_inferred/802B3B80_7.H"
#include "stddef.h"
#include "RENDER_4/8028FD2C_6.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8025DB80_C9D0C[1] = {
    0x3DCCCCCD,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025DB80_C9D0C_us_rev1.c */
const unsigned int D_blob_c2e990d7fbcab1f9b43c[1] = {
    0x3DCCCCCD,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_8025DC34_C9D10[1] = {
    0x46FFFE00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025DC34_C9D10_us_rev1.c */
const unsigned int D_blob_818b493a54f22a804367[1] = {
    0x46FFFE00,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_8025DC88_C9D14[2] = {
    0x3C23D70A, 0x3C23D70A,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025DC88_C9D14_us_rev1.c */
const unsigned int D_blob_713397d39e7015fa86e1[2] = {
    0x3C23D70A, 0x3C23D70A,
};
#endif

extern f32 D_800C4030_de;
extern s32 func_802654E8_de(s32, s32, s32);
extern f32 func_802B2350(s32);
extern f32 func_802AD520_eu(s32);
extern f32 D_800C401C_de;

void *func_8025DB80_de(Track *state, s32 index) {
    s32 selection;

    void *result;
    Resource *command;
    f32 duration;
    selection = func_802654E8_de(state->unk0->unk2B60, state->unk0->unk2B64, index);
    if (selection != -1) {
        selection *= 2;
        result = Render_GetPackSection(state->unk0->unk2B50, selection | 1);
        command = Render_GetPackSection(state->unk0->unk2B50, selection);
        state->unk24 = command->unk0;
        #if defined(VERSION_EU)
        duration = func_802AD520_eu(command->unk4);
#else
        duration = func_802B2350(command->unk4);
#endif
        state->unk30 = duration;
        if (duration <= 0.0f) state->unk30 = D_800C401C_de;
        return result;
    }
    return NULL;
}

extern void func_802AE5B8_de(s32 arg0, s32 arg1);


void func_8025DC34_de(void *arg0, f32 arg1) {
    Track *track = arg0;
    f32 f20 = arg1;
    f32 f0 = f20 * D_800C4020_de;
    func_802AFF60_de(track->unk14, (s16)(s32) f0);
    track->unk2C = f20;
}

void func_8025DC88_de(void *arg0) {
    ObjectState40 *o = arg0;
    f32 var_f20;
    ContextRecAt2BC0 *context;

    if (o->unk_38 != 0) {
        f32 prod = o->context->green;
        prod = prod * D_800C4024_de;
        var_f20 = (f32) (o->unk_24);
        var_f20 = var_f20 * prod;
        var_f20 = var_f20 * o->unk_3C;
        goto do_update;
    }
    context = o->context;
    var_f20 = (f32) (o->unk_24) * (context->green * D_800C4028_de);
    if (context->field2BB8 != 0) {
        var_f20 = var_f20 * (0.699999988079071f);
    }
    if (var_f20 != o->unk_2C) {
do_update:
        func_802AFF60_de(o->unk_14, (s16) (s32) (var_f20 * D_800C4030_de));
        o->unk_2C = var_f20;
    }
}

void func_8025DD60_de(Track *track) {
    s32 i;
    f32 scaled;

    i = 0;
    func_802AE5B8_de(track->unk10, track->unkC);
    func_802AFF30_de(track->unk14, track->unk10);
    func_802AFEB0_de(track->unk14,
                  track->unk8->field_4);
    do {
        func_802AFEE0_de(track->unk14, i & 0xFF, 0);
        i++;
    } while (i < 0x14);

    scaled = (f32)track->unk24 *
             (track->unk0->unk2BA4 * (&D_800C4030_de)[1]);
    func_802AFF60_de(track->unk14, (s16)(s32)(scaled * D_800C4038_de));
    track->unk2C = scaled;
}

/* ROM-grounded data: rodata/unresolved/800C9120 */
const unsigned int D_blob_97655e5ead2f6b44a8c7[1] = {
    0x46FFFE00,
};

#if !(defined(VERSION_US_REV1))
const unsigned int D_8025DD60_C9D24[2] = {
    0x3C23D70A, 0x46FFFE00,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C432C[1] = {
    0x68696373,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C403C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025DD60_C9D24_us_rev1.c */
const unsigned int D_blob_4d5302c2d0e80d970cfa[2] = {
    0x3C23D70A, 0x46FFFE00,
};
#endif
