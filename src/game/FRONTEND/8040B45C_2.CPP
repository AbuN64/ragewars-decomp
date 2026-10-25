#include "include_asm.h"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "stddef.h"
#include "TYPES.H"
#include "FRONTEND/8040B45C_2.H"

extern s32 D_8015375C;

extern s32 D_80153784;

extern s32 D_800E28C8;

extern char D_0044EE88;

extern s32 Pak_CheckStatusPrompt(Shared_PakMenu *action, s32 channel, s32 arg2);

/* Confirms the pak menu's channel: picks the team/channel override or the record's own channel byte, marks D_80153784, and if Pak_CheckStatusPrompt accepts it opens the pak prompt keyed by the player's storage buffer (or the default buffer if there is no player), otherwise opens the prompt on the default buffer. */
extern s32 Pak_CheckStatusPrompt(Shared_PakMenu *, s32, s32);

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

/* Latches D_80153770 to one when the record's team value is not -1 and both func_802645D0_de and Pak_CheckStatusPrompt accept it, then returns D_80153770. Adapted from func_80409C0C_de with the latch D_80153784 changed to D_80153770. */





extern s32 D_80153770;

extern s32 Render_PeekPakChange(s32);

extern s32 Pak_CheckStatusPrompt(struct Shared_PakMenu *, s32, s32);

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

extern void Pak_OpenDialog(void *dst, void *text, void *arg2, void *arg3, void *arg4);
extern char D_8014561C[];
extern s32 D_80153778;
/* Starts the action's channel (D_800E28C8 in demo mode, else the record's inner value) through Pak_CheckStatusPrompt; on success loads the record's actor resource into D_8014561C and latches D_80153784, otherwise loads the shared fallback text with the actor as extra argument. Returns 1. */
s32 Frontend_OpenPakChannel(s32 unused0, Shared_PakMenu *menu) {
    s32 channel;

    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = menu->owner->unk4;
    }
    if (Pak_CheckStatusPrompt(menu, channel, 1) != 0) {
        D_80153784 = 1;
        Pak_OpenDialog(D_8014561C, menu->unk24, menu->player, menu->owner, 0);
        return 1;
    }
    Pak_OpenDialog(D_8014561C, &D_0044EE88, menu->player, menu->owner, menu->unk24);
    return 1;
}

s32 func_8040B58C_de(void *arg0, Shared_PakMenu *menu) {
    void *buffer;
    ObjRecAt5DC *player;
    s32 channel;
    if (D_8015375C != 0) {
        channel = D_800E28C8;
    } else {
        channel = menu->owner->unk4;
    }
    D_80153784 = 1;
    if (Pak_CheckStatusPrompt(menu, channel, 1) != 0) {
        player = menu->player;
        if (player != NULL) {
            buffer = player->unk5DC + 0x554;
        } else {
            buffer = D_8014561C;
        }
        Pak_OpenDialog(buffer, menu->unk24, menu->player, menu->owner, 0);
        return 1;
    }
    Pak_OpenDialog(D_8014561C, menu->unk24, menu->player, menu->owner, 0);
    return 1;
}

s32 func_8040B648_de(s32 unused0, ActionRecAt24 *arg1) {
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
            var_a0 = D_8014561C;
        }
        Pak_OpenDialog(var_a0, (void *)arg1->unk24, (void *)arg1->unk1C, (void *)arg1->unk20, 0);
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
            if (Render_PeekPakChange(func_80409BDC_de(record)) != 0) {
                if (Pak_CheckStatusPrompt(record, func_80409BDC_de(record), 0) != 0) {
                    D_80153770 = 1;
                }
            }
        }
    }
    return D_80153770;
}

void func_8040B7E0_de(void) {
    D_80153778 = 0;
    D_80153770 = 0;
}

void func_8040B7F8_de(void) {
    D_80153778 = 1;
    D_80153770 = 0;
}

void func_8040B814_de(void) {
    D_80153778 = 2;
    D_80153770 = 0;
}

void func_8040B830_de(void) {
    D_80153778 = 3;
    D_80153770 = 0;
}

void func_8040B84C_de(void) {
    D_80153778 = 4;
    D_80153770 = 0;
}

s32 func_8040B868_de(struct FieldRecAt14 *field) {
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

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DBC9C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E882C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800ED66C[1] = {
    0x00000000,
};
#endif
