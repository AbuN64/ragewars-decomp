#include "MENU/PLAYERSETTINGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/8043DF84.H"
#include "COMMON/SHARED_DEBUGFIELD.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "MENU/MISC/8043DF84_5.H"

extern s8 Pak_AdjustValue(Outer8043E458 *arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern void func_804427C4_de(void *arg0, void *arg1, void *arg2);

/* Points arg0's unk14 field at D_800D7688 or D_800D768C when the mode byte at 0x7B of the owner's record is 0 or 1, and returns 0. */









extern char D_800D7688;

extern char D_800D768C;

/* Forwards arg0->unk20->unk4 to func_80264770_de and clears D_800E28C0. */



extern s32 D_800E28C0;

extern void func_80264770_de(s32 kind);

/* Returns whether any of the words at offsets 0x28, 0x1C and 0x20 of D_801468A0 is set. */



/* Restarts a round for the player passed in arg1: clears the world timer flag D_800E28C0 via
   func_804097E8_de, cancels the active countdown sound through func_8025E214_de, then reallocates a
   fresh scoreboard entry via Pak_OpenDialog using arg1's fields at 0x1C and 0x20, and always
   reports success. */

extern s32 D_8014561C;

extern s32 D_0044E468;

void func_804097E8_de(void);

void *Pak_OpenDialog(void *owner, void *list, s32 b, s32 c, s32 d);

/** Runs a target's animation/state transition through Pak_AdjustValue and stores the new state. */
s32 func_8043E3CC_de(void *arg0, Outer8043E458 *arg1) {
    Target8043E458 *temp_s0;

    temp_s0 = arg1->unk1C->unk5D8;
    temp_s0->unk7B = Pak_AdjustValue(arg1, temp_s0->unk7B, 1, 0, 1, 1);
    return 0;
}

/** Forwards arg1 through and arg2 as the first parameter, adding the D_452834 record. */
s32 func_8043E418_de(void *arg0, void *arg1, void *arg2) {
    func_804427C4_de(arg2, arg1, &D_004518A4);
    return 1;
}

s32 func_8043E444_de(Shared_DebugWidget *widget, Shared_MenuHandle *handle) {
    widget->field = D_800E1CC0[handle->selection->index];
    return 0;
}

/* Forwards arg1 through and arg2 as the first parameter, adding the D_4505C0 record. */
s32 func_8043E468_de(void *arg0, void *arg1, void *arg2) {
    func_804427C4_de(arg2, arg1, &D_0044F994_de);
    return 1;
}

s32 func_8043E494_de(ObjRecAt14V1 *arg0, Menu_func_8043E494_de *menu) {
    switch (menu->owner->record->mode) {
    case 0:
        arg0->unk14 = &D_800D7688;
        break;
    case 1:
        arg0->unk14 = &D_800D768C;
        break;
    }
    return 0;
}

/** Forwards the pointed-to inner byte field on to func_80264770_de. */
void func_8043E4E0_de(Outer8043E56C *arg0) {
    func_80264770_de(arg0->unk20->unk4);
}

void func_8043E504_de(struct Shared_PakMenu *arg0) {
    func_80264770_de(arg0->owner->unk4);
    D_800E28C0 = 0;
}

s32 func_8043E530_de(void) {
    CGameStatus *state = &D_801462C8.counters;

    return state->round != 0 || state->elapsed != 0 || state->state != 0;
}

s32 func_8043E568_de(void *arg0, Arg1Struct *arg1) {
    s32 val1C;

    val1C = arg1->unk1C;
    func_804097E8_de();
    ((s32 (*)(s32))func_8025E214_de)(-1);
    Pak_OpenDialog(&D_8014561C, &D_0044E468, val1C, arg1->unk20, 0);
    return 1;
}

/** Return 0. */
s32 func_8043E5C8_de(void) {
    return 0;
}
