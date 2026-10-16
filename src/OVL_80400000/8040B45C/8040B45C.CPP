#include "span_16E000/code_8040B45C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "stddef.h"
#include "TYPES.H"

extern s32 D_8015375C;

extern s32 D_80153784;

extern s32 D_800E28C8;

extern char D_0044EE88;

extern s32 func_80406178_de(Shared_PakMenu *action, s32 channel, s32 arg2);

/* Confirms the pak menu's channel: picks the team/channel override or the record's own channel byte, marks D_80153784, and if func_80406178_de accepts it opens the pak prompt keyed by the player's storage buffer (or the default buffer if there is no player), otherwise opens the prompt on the default buffer. */
extern s32 func_80406178_de(Shared_PakMenu *, s32, s32);

/* Starts the configured action using the actor resource or the shared fallback. */


 /* extern */
extern s32 D_800E28C0;

extern s32 D_8014ADA0;

extern s32 D_8014D480;

/* Points a field's text at D_800D7990 when the option D_80153760 is set and at D_800D7994 otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_80153760;

extern char D_800D7990[];

extern char D_800D7994[];

/* Latches D_80153770 to one when the record's team value is not -1 and both func_802645D0_de and func_80406178_de accept it, then returns D_80153770. Adapted from func_80409C0C_de with the latch D_80153784 changed to D_80153770. */





extern s32 D_80153770;

extern s32 func_802645D0_de(s32);

extern s32 func_80406178_de(struct Shared_PakMenu *, s32, s32);

static inline s32 func_80409BDC_de(struct Shared_PakMenu *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->owner->unk4;
}

/* Stores 0 in D_80153778 and 0 in D_80153770. */


/* Stores 1 in D_80153778 and 0 in D_80153770. */


/* Stores 2 in D_80153778 and 0 in D_80153770. */


/* Stores 3 in D_80153778 and 0 in D_80153770. */


/* Stores 4 in D_80153778 and 0 in D_80153770. */


/* Points a field's text at the label for the state word D_80153778: one of four strings through the
   jump table jtbl_800E1008 for states 0 to 4, and D_800D7998 for any other state. Returns zero. */




extern char D_800D7998[];

extern char D_800D3980[];

extern char D_800D3994[];

extern char D_800D39A8[];

extern char D_800D39BC[];

/* Starts the action's channel (D_800E28C8 in demo mode, else the record's inner value) through func_80406178_de; on success loads the record's actor resource into D_8014561C and latches D_80153784, otherwise loads the shared fallback text with the actor as extra argument. Returns 1. */
s32 func_8040B4E0_de(s32 arg0, Shared_PakMenu *arg1) {
    extern void func_80442574_de(void *dst, void *text, void *arg2, void *arg3, void *arg4);
    extern char D_8014561C;
    s32 channel;

    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = arg1->owner->unk4;
    }
    if (func_80406178_de(arg1, channel, 1) == 0) {
        func_80442574_de(&D_8014561C, &D_0044EE88, arg1->player, arg1->owner, arg1->unk24);
    } else {
        D_80153784 = 1;
        func_80442574_de(&D_8014561C, arg1->unk24, arg1->player, arg1->owner, 0);
    }
    return 1;
    /* FAKEMATCH: preserve the return-value load before the epilogue register restores. */
    do {
    } while (0);
}

s32 func_8040B58C_de(void *arg0, Shared_PakMenu *arg1) {
    extern void func_80442574_de(void *, void *, ObjRecAt5DC *, void *, s32);
    extern char D_8014561C[];
    void *buffer;
    ObjRecAt5DC *player;
    s32 channel;
    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = arg1->owner->unk4;
    }
    D_80153784 = 1;
    if (func_80406178_de(arg1, channel, 1) != 0) {
        player = arg1->player;
        if (player != NULL) {
            buffer = player->unk5DC + 0x554;
        } else {
            buffer = D_8014561C;
        }
        func_80442574_de(buffer, arg1->unk24, arg1->player, arg1->owner, 0);
        return 1;
    }
    func_80442574_de(D_8014561C, arg1->unk24, arg1->player, arg1->owner, 0);
    return 1;
}

s32 func_8040B648_de(s32 arg0, ActionRecAt24 *arg1) {
    void func_80442574_de(void *, s32, void *, s32, s32);
    extern char D_8014561C;
    void *var_a0;
    ObjRecAt5DC *temp_v0;
    D_800E28C0 = 1;
    D_8014D480 = 0;
    if (D_8015375C != 0) {
        D_8014ADA0 = 1;
    } else {
        temp_v0 = arg1->unk1C;
        if (temp_v0 != NULL) {
            var_a0 = temp_v0->unk5DC + 0x554;
        } else {
            var_a0 = &D_8014561C;
        }
        func_80442574_de(var_a0, arg1->unk24, arg1->unk1C, arg1->unk20, 0);
    }
    return 1;
}

s32 func_8040B6CC_de(struct FieldRecAt14 *field) {
    if (D_80153760 != 0) {
        field->text = D_800D7990;
    } else {
        field->text = D_800D7994;
    }
    return 0;
}

s32 func_8040B700_de(struct Shared_PakMenu *record) {
    if (D_80153770 == 0) {
        if (func_80409BDC_de(record) != -1) {
            if (func_802645D0_de(func_80409BDC_de(record)) != 0) {
                if (func_80406178_de(record, func_80409BDC_de(record), 0) != 0) {
                    D_80153770 = 1;
                }
            }
        }
    }
    return D_80153770;
}

void func_8040B7E0_de(void) {
    extern s32 D_80153778;
    D_80153778 = 0;
    D_80153770 = 0;
}

void func_8040B7F8_de(void) {
    extern s32 D_80153778;
    D_80153778 = 1;
    D_80153770 = 0;
}

void func_8040B814_de(void) {
    extern s32 D_80153778;
    D_80153778 = 2;
    D_80153770 = 0;
}

void func_8040B830_de(void) {
    extern s32 D_80153778;
    D_80153778 = 3;
    D_80153770 = 0;
}

void func_8040B84C_de(void) {
    extern s32 D_80153778;
    D_80153778 = 4;
    D_80153770 = 0;
}

s32 func_8040B868_de(struct FieldRecAt14 *field) {
    extern u32 D_80153778;
    u32 state = D_80153778;

    if (state >= 5) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto state_1;
        case 2: goto state_2;
        case 3: goto state_3;
        case 4: goto state_4;
        }
state_other:
    field->text = D_800D7998;
    goto done;
state_1:
    field->text = D_800D3980;
    goto done;
state_2:
    field->text = D_800D3994;
    goto done;
state_3:
    field->text = D_800D39A8;
    goto done;
state_4:
    field->text = D_800D39BC;
done:
    return 0;
}
