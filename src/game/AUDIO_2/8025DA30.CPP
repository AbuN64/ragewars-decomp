#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/STATERECAT34.H"
#include "AUDIO_2/8025DA30.H"
#include "TYPES.H"
#include "sdk/OS/8025DA30.H"

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "COMMON/S1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "UTIL/8025DBA0.H"
#include "sdk/libgultra_inferred/802B3B80_7.H"
#include "stddef.h"
#include "stddef.h"
#include "RENDER_4/8028FD2C_6.H"
extern s32 func_802654E8_de(s32, s32, s32);
extern f32 func_802B2350(s32);
extern f32 func_802AD520_eu(s32);
extern f32 D_800C4008_de;

s32 func_8025DA10_de(Track *state, s32 index) {
    s32 selection;

    void *result;
    void *selected;
    Resource *command;
    f32 duration;
    selection = func_802654E8_de(state->unk0->unk2B60, state->unk0->unk2B64, index);
    if (selection != -1) {
        selection *= 2;
        selected = func_8028FDB4_de(state->unk0->unk2B50, selection | 1);
        command = func_8028FDB4_de(state->unk0->unk2B50, selection);
        state->unk24 = command->unk0;
        #if defined(VERSION_EU)
        duration = func_802AD520_eu(command->unk4);
#else
        duration = func_802B2350(command->unk4);
#endif
        state->unk30 = duration;
        if (duration <= 0.0f) state->unk30 = D_800C4008_de;
        result = selected;
    } else {
        result = NULL;
    }
    state->unkC = result;
    return result != NULL;
}

/* Sets the sound fade state and derives its step from the clamped duration. */

void func_8025DACC_de(StateRecAt34 *arg0) {
    f32 var_f2;

    var_f2 = arg0->unk30;
    arg0->unk1C = 2;
    arg0->unk18 = 0x20;
    arg0->unk20 = (s32) (arg0->unk2C * 32767.0f);
    if (!(var_f2 >= 0.1f)) {
        var_f2 = 0.1f;
    }
    arg0->unk30 = var_f2;
    arg0->unk28 = 0;
    arg0->unk34 = (f32) ((f32) arg0->unk20 / (var_f2 * 60.0f));
}

void func_8025DB34_de(Track *track) {
    track->unk38 = 1;
    track->unk40 = 0;
}

/** Clear offset 0x38 and initialize offset 0x40 from D_800C9108. */
void func_8025DB44_de(Track *track) {
    track->unk40 = D_800C9108;
    track->unk38 = 0;
}

s32 func_802AFF90_de(s32);
void func_8025DB58_de(s32 a) {
    (((struct IntegerState2C_2 *) ((s8 *) a))->unk_28) = -1;
    func_802AFF90_de((((struct IntegerState2C_2 *) ((s8 *) a))->unk_14));
}
