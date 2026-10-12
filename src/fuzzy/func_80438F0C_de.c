#include "span_16E000/code_804366C4.h"
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "common/unused.h"
#include "types.h"



extern struct HudCue *D_800E58A0;



extern struct HudCue *func_8025305C_de(s32 size);
extern s32 func_8041A280_de(s32 a0, s32 a1);
extern s32 func_8041A580_de(s32 a0, s32 a1, s32 a2);
extern void func_8041A6EC_de(s32 cue, s32 volume);
extern void func_8041B110_de(s32 id);
extern s32 func_80419E54_de(s32 a0, s32 a1);

/* Allocates the HUD-cue object D_800E58A0, opens its handle for 0x6C/0x6D, starts its two timed cues at the volumes in D_801462E0 and its ambient loop, then arms state 3; returns 0. */
s32 func_80438F0C_de(void) {
    s32 cue;

    D_800E58A0 = func_8025305C_de(0x1C);
    D_800E58A0->handle = func_8041A280_de(0x6C, 0x6D);
    cue = func_8041A580_de(0x6F, 0x70, 0xFF);
    D_800E58A0->cue0 = cue;
    func_8041A6EC_de(cue, D_801462E0[0]);
    cue = func_8041A580_de(0x71, 0x72, 0xFF);
    D_800E58A0->cue1 = cue;
    func_8041A6EC_de(cue, D_801462E0[1]);
    func_8041B110_de(0x73);
    cue = func_80419E54_de(0x6E, 0x6E);
    D_800E58A0->state = 3;
    D_800E58A0->ambient = cue;
    D_800E58A0->unk14 = -1;
    return 0;
}
