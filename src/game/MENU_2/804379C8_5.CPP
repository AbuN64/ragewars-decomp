#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENULISTSCREEN.H"
#include "MENU_2/804379C8_5.H"

#if defined(VERSION_DE) || defined(VERSION_EU_X)
extern s32 func_8041A280_de(s32, s32);
extern s32 func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(s32, s32);
extern void func_8041B110_de(s32);
extern s32 func_80419E54_de(s32, s32);

s32 func_80438F0C_de(void) {
    s32 cue;
    void *memory;
    memory = Cache_AllocateMemory(0x1C);
    D_800E58A0 = memory;
#if defined(VERSION_DE)
    D_800E58A0->handle = func_8041A280_de(0x6A, 0x6B);
    cue = func_8041A580_de(0x6D, 0x6E, 0xFF);
#elif defined(VERSION_EU_X)
    D_800E58A0->handle = func_8041A280_de(0x70, 0x71);
    cue = func_8041A580_de(0x73, 0x74, 0xFF);
#else
    D_800E58A0->handle = func_8041A280_de(0x6C, 0x6D);
    cue = func_8041A580_de(0x6F, 0x70, 0xFF);
#endif
    D_800E58A0->cue0 = cue;
    func_8041A6EC_de(cue, D_801462C8.volume[0]);
#if defined(VERSION_DE)
    cue = func_8041A580_de(0x6F, 0x70, 0xFF);
#elif defined(VERSION_EU_X)
    cue = func_8041A580_de(0x75, 0x76, 0xFF);
#else
    cue = func_8041A580_de(0x71, 0x72, 0xFF);
#endif
    D_800E58A0->cue1 = cue;
    func_8041A6EC_de(cue, D_801462C8.volume[1]);
#if defined(VERSION_DE)
    func_8041B110_de(0x71);
    cue = func_80419E54_de(0x6C, 0x6E);
#elif defined(VERSION_EU_X)
    func_8041B110_de(0x77);
    cue = func_80419E54_de(0x72, 0x6E);
#else
    func_8041B110_de(0x73);
    cue = func_80419E54_de(0x6E, 0x6E);
#endif
    D_800E58A0->state = 3;
    D_800E58A0->ambient = cue;
    D_800E58A0->unk14 = -1;
    return 0;
}
#endif

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "TYPES.H"






extern s32 func_8041A280_de(s32 a0, s32 a1);
extern s32 func_8041A580_de(s32 a0, s32 a1, s32 a2);
extern void func_8041A6EC_de(s32 cue, s32 volume);
extern s32 func_80419E54_de(s32 a0, s32 a1);

/* Allocates the HUD-cue object D_800E58A0, opens its handle for 0x6C/0x6D, starts its two timed cues at the volumes in D_801462E0 and its ambient loop, then arms state 3; returns 0. */
s32 func_80438F0C_de(void) {
    s32 cue;

    /* the hub's allocation helper returns its SelectionScreenState view; this unit keeps its own HudCue view */
    D_800E58A0 = (struct HudCue *) Cache_AllocateMemory(0x1C);
    D_800E58A0->handle = func_8041A280_de(0x6C, 0x6D);
    cue = func_8041A580_de(0x6F, 0x70, 0xFF);
    D_800E58A0->cue0 = cue;
    func_8041A6EC_de(cue, D_801462C8.volume[0]);
    cue = func_8041A580_de(0x71, 0x72, 0xFF);
    D_800E58A0->cue1 = cue;
    func_8041A6EC_de(cue, D_801462C8.volume[1]);
    func_8041B110_de(0x73);
    cue = func_80419E54_de(0x6E, 0x6E);
    D_800E58A0->state = 3;
    D_800E58A0->ambient = cue;
    D_800E58A0->unk14 = -1;
    return 0;
}
#endif
