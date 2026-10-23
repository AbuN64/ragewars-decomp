#include "include_asm.h"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SCREEN.H"
#include "COMMON/WORLD.H"
#include "FRONTEND/8043A0B0_10.H"
#include "FRONTEND/8043A0B0_11.H"
#include "FRONTEND/CODE_8043AED0.H"
#include "FRONTEND/8040B45C_32.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"
extern FourPlayerResultsScreen *D_800E59E0;

/* Clears the 22 owned bytes at 0x4C of each of the 4 player records (150 bytes apart) in
   D_80146398; for each active player (byte 0x78 == 1) it looks up the player's model kind (byte
   0x80) through func_8028CFA0_de and marks each of its 8 slot ids at least 0x4C3 as owned (byte 0x4C
   plus the id less 0x4C3), then refreshes the player's loadout columns through func_8043B6E8_de. */




extern u8 D_80146398[];

extern struct Model *func_8028CFA0_de(Shared_World *, s32, s32);

/* Counts how many of the four 0x4D0-byte entries D_800E59E0 points to have the word at offset
   0x4B0 equal to one. */




/* Moves the cursor of player p's 0x4D0-byte entry of D_800E59E0 to column c: unless c is 5 it
   hides the item whose id D_800E5A06[p * 19 + c] names in the screen window, shows the item
   D_800E5A1A[p * 19 + c] names with alpha 0x96, stores c as the entry's selection and redraws that
   column through Frontend_ShowEquipChoice with the entry's value for it. */











extern struct StateFlags D_800E5A06[];

extern struct Resource_func_80419E54_de *func_8040EC30_de(void *, s32);

extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);


/* Releases the object D_800E59E0 holds through func_802547E4_de, clears D_800E59E0, calls
   func_802A2360_de and func_802A23C4_de with 2, and returns zero. */



extern void func_802A2360_de();

/* Handles an input event for the 0x4D0-byte entry of D_800E59E0 the low half of the third argument
   selects: when that entry is active, the high half is 3 and the fourth argument is zero, it calls
   func_8029973C_de, resets the entry through func_8043B6E8_de, redraws its six columns and then its
   selected column through Frontend_ShowEquipChoice, and plays sound 0xE7C; it always returns zero. Written
   from the assembly; the entries are an array member of the screen so each column offset is
   summed before the base is added. */







extern void func_8029973C_de();


/* Calls func_8029973C_de and, when the fourth argument is one and the 0x4D0-byte entry of D_800E59E0 the third argument selects has a nonzero word at 0x4D4 (four bytes past the entry) with its word at 0x4B0 equal to one, plays sound 0xE7B through func_8025DF34_de and calls func_8043ACF0_de with the entry index and 1, returning zero. */





/* Calls func_8029973C_de and, when the fourth argument is one and the 0x4D0-byte entry of D_800E59E0 the third argument selects has a nonzero word at 0x4D4 (four bytes past the entry) with its word at 0x4B0 equal to one, plays sound 0xE7B through func_8025DF34_de and calls func_8043ACF0_de with the entry index and -1, returning zero. Adapted from func_8043BCC0_de with the second func_8043ACF0_de argument changed from 1 to -1. */





/* Calls func_8029973C_de and, when the fourth argument is one and the 0x4D0-byte entry of D_800E59E0 the third argument selects is in mode two (the word at 0x4D4, four bytes past the entry) with its word at 0x4B0 equal to one, plays sound 0xE7B through func_8025DF34_de and calls func_8043AE5C_de with the entry index and -1, returning zero. */





/* Calls func_8029973C_de and, when the fourth argument is one and the 0x4D0-byte entry of D_800E59E0 the third argument selects is in mode two (the word at 0x4D4, four bytes past the entry) with its word at 0x4B0 equal to one, plays sound 0xE7B through func_8025DF34_de and calls func_8043AE5C_de with the entry index and 1, returning zero. Adapted from func_8043BDF0_de with the second func_8043AE5C_de argument changed from -1 to 1. */





/* Cancels a player's selection or schedules the menu transition according to the current selection state. */




extern void func_8041B7B4_de(void *, int, int);

extern void func_8041CE10_de(void *, int);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5C04, an actor kind at D_800E5C08 and a handler at D_800E5C0C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8043C1D0)(void *, s32, s32, s32, s32);

extern Handler8043C1D0 D_800E5C0C;

void func_8043B96C_de(void) {
    u8 *record;
    struct Model *model;
    s32 id;
    s32 i;
    s32 player;
    u8 *entry;

    for (player = 0; player < 4; player++) {
        record = &D_80146398[player * 150];
        i = 0x15;
        entry = record + 0x15;
        do {
            entry[0x4C] = 0;
            i -= 1;
            entry -= 1;
        } while (i >= 0);
        if (record[0x78] == 1) {
            model = func_8028CFA0_de(&D_8011FE88, 0xB, (s8) record[0x80]);
            for (i = 0; i < 8; i++) {
                id = model->slots[i];
                if (id >= 0x4C3) {
                    (record + (id - 0x4C3))[0x4C] = 1;
                }
            }
            func_8043B6E8_de(player);
        }
    }
}

s32 func_8043BA24_de(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800E59E0->panels[i].state == 1) {
            count++;
        }
    }
    return count;
}

void func_8043BA5C_de(s32 player, s32 column) {
    struct Resource_func_80419E54_de *item;

    if (column != 5) {
        item = func_8040EC30_de(D_800E59E0->window, D_800E5A06[player * 19 + column].value);
        func_8040E8D8_de(item, 1);
    }
    item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][column].value);
    func_8040E928_de(item, 1);
    item->value = 0x96;
    D_800E59E0->panels[player].selection = column;
    Frontend_ShowEquipChoice(player, column, D_800E59E0->panels[player].values[column]);
}

s32 func_8043BB70_de(void) {
    func_802547E4_de(D_800E59E0);
    D_800E59E0 = 0;
    func_802A2360_de();
    func_802A23C4_de(2);
    return 0;
}

s32 func_8043BBB0_de(void *first, void *second, u32 event, s32 held) {
    s32 index;
    s32 i;

    index = event & 0xFFFF;
    if (D_800E59E0->panels[index].state != 1) {
        return 0;
    }
    if ((event >> 16) != 3) {
        return 0;
    }
    if (held != 0) {
        return 0;
    }
    func_8029973C_de();
    func_8043B6E8_de(index);
    for (i = 0; i < 6; i++) {
        Frontend_ShowEquipChoice(index, i, D_800E59E0->panels[index].values[i]);
    }
    Frontend_ShowEquipChoice(index, D_800E59E0->panels[index].selection,
                  D_800E59E0->panels[index].values[D_800E59E0->panels[index].selection]);
    func_8025DF34_de(0xE7C);
    return 0;
}

s32 func_8043BCC0_de(void *first, void *second, s32 slot, s32 active) {
    u16 index;

    func_8029973C_de();
    if (active == 1) {
        index = slot;
        if (D_800E59E0->panels[index].mode != 0 && D_800E59E0->panels[index].state == active) {
            func_8025DF34_de(0xE7B);
            func_8043ACF0_de(index, 1);
            return 0;
        }
    }
    return 0;
}

s32 func_8043BD58_de(void *first, void *second, s32 slot, s32 active) {
    u16 index;

    func_8029973C_de();
    if (active == 1) {
        index = slot;
        if (D_800E59E0->panels[index].mode != 0 && D_800E59E0->panels[index].state == active) {
            func_8025DF34_de(0xE7B);
            func_8043ACF0_de(index, -1);
            return 0;
        }
    }
    return 0;
}

s32 func_8043BDF0_de(void *first, void *second, s32 slot, s32 active) {
    u16 index;

    func_8029973C_de();
    if (active == 1) {
        index = slot;
        if (D_800E59E0->panels[index].mode == 2 && D_800E59E0->panels[index].state == active) {
            func_8025DF34_de(0xE7B);
            func_8043AE5C_de(index, -1);
            return 0;
        }
    }
    return 0;
}

s32 func_8043BE8C_de(void *first, void *second, s32 slot, s32 active) {
    u16 index;

    func_8029973C_de();
    if (active == 1) {
        index = slot;
        if (D_800E59E0->panels[index].mode == 2 && D_800E59E0->panels[index].state == active) {
            func_8025DF34_de(0xE7B);
            func_8043AE5C_de(index, 1);
            return 0;
        }
    }
    return 0;
}

int func_8043BF28_de(int a,int b,unsigned int player) {
 func_8029973C_de();player &= 0xFFFF;
 switch(D_800E59E0->panels[player].state) {
 case 1:D_800E59E0->state=5;D_800E59E0->timer=4;D_800E59E0->next=7;break;
 case 2:D_800E59E0->panels[player].state=0;func_8041B7B4_de(D_800E59E0->menu,player,0);func_8041CE10_de(D_800E59E0->panels[player].pad0,1);func_8043B0CC_de(player);break;
 }
 return 0;
}

s32 func_8043BFF0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8043C1D0 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E5C0C != 0) {
        wildcard = 0x7530;
        entry = &D_800E5C0C;
        index = 0;
        do {
            if (D_800E5C04[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5C08[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}

#ifdef NON_MATCHING
/* 96/100 words; remaining: three-case switch tree on D_800E28D8 lays out its branches differently */
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "GFX/TEXT/802A8A94_5.H"
extern float D_800E2064;
extern float D_80141008[];
void func_8043C080_de(u8 *arg0) {
    s32 arg14;
    float b, a;
    float *screen;
    Gfx *cmd;
    Gfx *next;
    if (*(s32 *)(arg0 + 0x18) == 1) {
        arg14 = *(s32 *)(arg0 + 0x14);
        screen = D_80141008;
        func_802A84F8_de();
        func_8026925C_de(0x15);
        a = D_800DE030_de;
        b = a;
        switch (D_800E28D8) {
        case 1:
            a = D_800E2064;
            b = D_800DE038;
            break;
        case 2:
            a = D_800DE03C_de;
            b = D_800DE040;
            break;
        case 0:
            break;
        }
        gDPSetEnvColor(D_80110634++, arg0[7], arg0[0xB], arg0[0xF], 0xFF);
        gDPSetPrimColor(D_80110634++, 0, 0, 0xE0, 0, 0, 0xFF);
        func_802AAC28_de(*(s32 *)arg0, arg14, (s16)(s32)screen[0xA9], (s16)(s32)screen[0xAA],
                         a * (&D_800DE040)[1], b * D_800DE048_de, 1);
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8043C080_de);
#endif
