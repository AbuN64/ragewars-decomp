#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "MENU_2/8041F1FC_6.H"
#include "RENDER_2/8025DE50_5.H"

/* Handles a packed message whose high half is type 3 with no extra argument: when the entry named by
   its low half in the 0x4C8-byte table D_800E42D0 is active and has a target, runs func_804201A4_de on it
   and plays sound 0xE7C; always returns 0. */




extern void func_804201A4_de(int, EntryRecAt14V1 *);


/* Advances a player panel from its ready state and starts its selection. */




extern u8 D_801462D5;

void func_8029973C_de(void);

                           /* extern */
void func_8041B7B4_de(s32, s32, s32, State_func_80420C10_de *);

         /* extern */
void func_8041CE10_de(void *, s32);

                    /* extern */
void func_80420438_de(s32);

/* Applies the chosen character when the active player panel is ready. */

void func_8029973C_de();

                                  /* extern */
s32 func_8040EBD0_de(s32);

                             /* extern */
s32 func_8041B7FC_de(s32, s32);

                        /* extern */
s32 func_8041B810_de(s32, s32);

                        /* extern */
void func_80420618_de(s32, s32);

                          /* extern */


#if defined(VERSION_DE)
enum { SPECIAL_CHAR = 127 };
#elif defined(VERSION_EU_X)
enum { SPECIAL_CHAR = 133 };
#else
enum { SPECIAL_CHAR = 129 };
#endif

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4364, an actor kind at D_800E4368 and a handler at D_800E436C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */



extern s32 D_800E4364;

extern s32 D_800E4368;

extern Handler802A2B50 D_800E436C;

int func_80420B78_de(int unused0, int unused1, unsigned int message, int extra) {
    int index = message & 0xFFFF;
    EntryRecAt14V1 *e;

    if ((message >> 16) == 3 && extra == 0) {
        e = &((EntryRecAt14V1 *)D_800E42D0)[index];
        if (e->active == 1 && e->target != -1) {
            func_804201A4_de(index, e);
            func_8025DF34_de(0xE7C);
        }
    }
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80420BF0_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80420BF8_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80420C00_de(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80420C08_de(void) {
    return 0;
}

                            


/* extern */

s32 func_80420C10_de(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_s1;
    State_func_80420C10_de *temp_a3;

    func_8029973C_de();
    temp_s0 = arg2 & 0xFFFF;
    temp_s1 = temp_s0 * 0x4C8;
    temp_a3 = (State_func_80420C10_de *)&((PanelRecord *)D_800E42D0)[temp_s0];
    temp_a0 = temp_a3->unk14;
    switch (temp_a0) {
    case 1:
        if (D_801462D5 != 1) {
            D_800E42D0->phase = 5;
            D_800E42D0->timer = 4;
            D_800E42D0->result = 3;
        }
        break;
    case 3:
        temp_a3->unk14 = 1;
        func_8041B7B4_de(D_800E42D0->unk4, temp_s0, 0, temp_a3);
        func_8041CE10_de(&((PanelRecord *)(temp_s1 + (s32)D_800E42D0))->target, 1);
        func_80420438_de(temp_s0);
        break;
    }
    return 0;
}

s32 func_80420CDC_de(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 choice;
    s32 var_a1;
    CharacterSelectionRoot *characterSelectionRoot;

    temp_s0 = arg2 & 0xFFFF;
    choice = func_8041B810_de(D_800E42D0->unk4, temp_s0);
    func_8029973C_de();
    characterSelectionRoot = (CharacterSelectionRoot *)((char *)D_800E42D0 + (temp_s0 * 0x4C8));
    if (characterSelectionRoot->phase == 1) {
        if (choice == SPECIAL_CHAR) func_80420618_de(temp_s0,characterSelectionRoot->choice);
        else if (func_8040EBD0_de(func_8041B7FC_de(D_800E42D0->unk4,temp_s0)) == 0) func_80420618_de(temp_s0,choice);
    }
    return 0;
}

s32 func_80420D90_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    char *entry;
    s32 offset;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E436C != 0) {
        wildcard = 0x7530;
        entry = (char *)&D_800E436C;
        offset = 0;
        do {
            if (((struct Shape_typemap_3 *) (((char *) (&D_800E4364)) + offset))->field_0 == arg1) {
                actor_kind = ((struct ObjRecAtCV1 *) ((char *) arg0))->unkC;
                table_kind = ((struct Shape_typemap_3 *) (((char *) (&D_800E4368)) + offset))->field_0;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*(Handler802A2B50 *)entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 0xC;
            offset += 0xC;
        } while (*(Handler802A2B50 *)entry != 0);
    }
    return 0;
}
