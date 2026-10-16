#include "span_16E000/code_80423280.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_80429C10.h"
#include "TYPES.H"
#include "common/unused.h"
#include "shared/func_80421E70_eu_closed.h"
#include "span_16E000/code_80420E90.h"

/* Looks up entry arg1 of the table chosen by arg0 and returns field 0xC of the first of the forty records at D_800E4F64 whose first word equals it, or zero. */




extern RecordRecAtCV2 D_800E4F64[];

extern s32 D_800E51E4[];

extern s32 D_800E51F8[];

extern s32 D_800E5214[];

extern s32 D_800E5240[];

/* Sets the byte at offset 0x10 of the two objects at offsets 0x454 and 0x450 of the structure D_800E4F60
   points to to 0xFF, shows both through func_8040E8D8_de and clears the word at 0x46C. */







/* Calls func_80265688_de on D_80154018 for each index from 0 to 0x27 with zero. */

extern void func_80265688_de(void *, s32, s32);

/* Releases the object D_800E4F60 holds through func_802547E4_de, calls func_802A2360_de and
   func_80422020_de, clears D_800E4F60 and returns zero. */


extern void func_802547E4_de(void *);

extern void func_802A2360_de();

#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_80422020_de();
#else
#endif


/* When the global session is mode 3 with no pending state and the caller's high word and empty flag agree, resets the mode, restarts five subsystems and queues one status message. */







extern s32 D_80154020;


extern void func_8042A7B4_de(s32 a0);

extern void func_8025DF34_de(s32 a0);

/* Moves the selection of the screen D_800E4F60 back on event 1: calls func_8029973C_de and steps the
   selection at 0x438 back while it is above 0; in category 0 the second page (11 and up) instead
   steps forward while below the count func_8042B154_de gives for list 0. When it moved it plays sound
   0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464, dims the item at 0x43C to alpha
   0x41 and refreshes through func_8042A990_de, and when the selection is then 0 it shows the items at
   0x440 and 0x448, moves the marker at 0x448 to x 0x7C plus 34 per category, hides the item at
   0x444 and shows model 0xEA6 plus the category in the view at 0x308. Returns zero. Adapted from
   func_8042B644_de with the step direction, page handling and final item updates changed. */







extern void func_8029973C_de();

extern void func_8025DF34_de(s32);


extern s32 func_8042B154_de(void *);

extern void func_80439C80_de(void *, s32);

/* Moves the selection of the screen D_800E4F60 on event 1: calls func_8029973C_de and steps the
   selection at 0x438 forward while it stays below the count func_8042B154_de gives for the category's
   list; in category 0 the first page (below 11) steps forward unless it would reach the count of
   list 0 or 11, and the second page steps back unless it would reach 10. When it moved it plays
   sound 0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464, dims the item at 0x43C to
   alpha 0x41, refreshes through func_8042A990_de, hides the items at 0x440 and 0x448 and shows the
   one at 0x444. Returns zero. */







/* Moves the screen D_800E4F60 to its previous category on event 1: calls func_8029973C_de and steps
   the category at 0x434 back unless it is 0; in category 0 a selection at 0x438 from 5 to 10 is
   mirrored to 21 minus it when that stays below the count func_8042B154_de gives for list 0. When
   anything changed it plays sound 0xE7D, calls func_8042B2E4_de, clears the words at 0x45C and 0x464,
   dims the item at 0x43C to alpha 0x41, clamps the selection below the count for the category's
   list, refreshes through func_8042A990_de and, when the selection is 0, shows model 0xEA6 plus the
   category in the view at 0x308 and moves the marker item at 0x448 to x 0x7C plus 34 per category.
   Returns zero. Adapted from func_8042B904_de with the step direction and the mirror test changed. */







/* Moves the screen D_800E4F60 to its next category on event 1: calls func_8029973C_de and, unless the
   category at 0x434 is already 3, advances it (from category 0 only while the selection at 0x438
   is below 11, otherwise mirroring the selection to 21 minus it), then plays sound 0xE7D, calls
   func_8042B2E4_de, clears the words at 0x45C and 0x464, dims the item at 0x43C to alpha 0x41, clamps
   the selection below the count func_8042B154_de gives for the category's list, refreshes through
   func_8042A990_de and, when the selection is 0, shows model 0xEA6 plus the category in the view at
   0x308 and moves the marker item at 0x448 to x 0x7C plus 34 per category. Returns zero. */







/* Calls func_8029973C_de; when the mode word at offset 0x3DC of the object D_800E4F60 points to is 3,
   sets it to 5 and the word at 0x3E0 to 4. Returns zero. */




/* Calls func_8042AAD0_de when the word at offset 0x3DC of the object D_800E4F60 points to is 3, and
   returns zero. */




/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5284, an actor kind at D_800E5288 and a handler at D_800E528C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8042BCB0)(void *, s32, s32, s32, s32);



extern Handler8042BCB0 D_800E528C;

s32 func_8042B1B8_de(s32 arg0, s32 arg1) {
    s32 result = 0;
    s32 *table;
    s32 key;
    s32 found;
    s32 i;

    if (arg1 == 0) {
        arg1 = 1;
    }
    switch (arg0) {
    case 0:
        table = D_800E51E4;
        break;
    case 1:
        table = D_800E51F8;
        break;
    case 3:
        table = D_800E5214;
        break;
    case 2:
        table = D_800E5240;
        break;
    default:
        return 0;
    }
    key = table[arg1];
    found = 0;
    i = 0;
    do {
        if (key == D_800E4F64[i].key) {
            found = 1;
            result = D_800E4F64[i].value;
        }
        i++;
    } while ((i < 0x28) && (found == 0));
    return result;
}

/* Maps a selection index to its display code: 0 gives 2, 1 gives 3, 2 gives 1 and anything else 0. */
int func_8042B294_de(int index) {
    int r;

    switch (index) {
    default:
        r = 0;
        break;
    case 2:
        return 1;
    case 1:
        return 3;
    case 0:
        r = 2;
    }
    return r;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8042B2DC_de(void) {
    return 0;
}

void func_8042B2E4_de(void) {
    extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);
    extern func_8042B4C4_S1 *D_800E4F60;
    (D_800E4F60->unk454)->value = 0xFF;
    (D_800E4F60->unk450)->value = 0xFF;
    func_8040E8D8_de(D_800E4F60->unk450, 1);
    func_8040E8D8_de(D_800E4F60->unk454, 1);
    D_800E4F60->unk46C = 0;
}

void func_8042B350_de(void) {
    s32 i;

    for (i = 0; i < 0x28; i++) {
        func_80265688_de(D_80154018, i, 0);
    }
}

s32 func_8042B394_de(void) {
    extern void *D_800E4F60;
    func_802547E4_de(D_800E4F60);
    func_802A2360_de();
#if defined(VERSION_DE)
    func_80422020_de();
#else
    
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_80422020_de
#else
func_8042201C_de
#endif
();
#endif
    D_800E4F60 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_8042B3D4_de(void) {
    return 0;
}

s32 func_8042B3DC_de(s32 a0, s32 a1, s32 a2, s32 a3)
{
    extern void func_8040E8D8_de(s32 a0, s32 a1);
    extern G *D_800E4F60;
    s32 v = D_800E4F60->unk3DC;

    if (v != 3) {
        return 0;
    }
    if (D_80154020 != -1) {
        return 0;
    }
    if ((u32)a2 >> 16 != v) {
        return 0;
    }
    if (a3 != 0) {
        return 0;
    }

    func_8029973C_de();
    D_800E4F60->unk3DC = 8;
    func_8042A7B4_de(0x41);

    func_8040E8D8_de(D_800E4F60->unk440, 0);
    func_8040E8D8_de(D_800E4F60->unk444, 0);
    func_8040E8D8_de(D_800E4F60->unk448, 0);
    func_8040E8D8_de(D_800E4F60->unk3EC, 0);
    func_8040E8D8_de(D_800E4F60->unk3F0, 0);

    D_800E4F60->unk44C->value = 0x5A;
    func_8025DF34_de(0xE7C);

    return 0;
}

s32 func_8042B4D4_de(void *arg0, void *arg1, void *arg2, s32 event) {
    extern void func_8040E8D8_de(struct MenuMarker *, s32);
    extern struct Screen_func_8042B4D4_de *D_800E4F60;
    struct Screen_func_8042B4D4_de *screen;
    s32 changed;
    s32 next;

    func_8029973C_de();
    if (event != 1) {
        return 0;
    }
    screen = D_800E4F60;
    changed = 0;
    if (screen->category != 0) {
        if (screen->selection > 0) {
            changed = 1;
            screen->selection = screen->selection - 1;
        }
    } else if (screen->selection >= 11) {
        next = func_8042B154_de(func_8042B294_de(0));
        screen = D_800E4F60;
        if (screen->selection + 1 < next) {
            changed = 1;
            screen->selection = screen->selection + 1;
        }
    } else if (screen->selection > 0) {
        screen->selection = screen->selection - 1;
        changed = 1;
    }
    if (changed != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    func_8042B2E4_de();
    D_800E4F60->word45C = 0;
    D_800E4F60->word464 = 0;
    D_800E4F60->item->alpha = 0x41;
    func_8042A990_de();
    if (D_800E4F60->selection != 0) {
        return 0;
    }
    func_8040E8D8_de(D_800E4F60->left, 1);
    func_8040E8D8_de(D_800E4F60->marker, 1);
    D_800E4F60->marker->x = D_800E4F60->category * 34 + 0x7C;
    func_8040E8D8_de(D_800E4F60->right, 0);
    func_80439C80_de(D_800E4F60->view, D_800E4F60->category + 0xEA6);
    return 0;
}

s32 func_8042B644_de(void *arg0, void *arg1, void *arg2, s32 event) {
    extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);
    extern struct Screen_func_8042B644_de *D_800E4F60;
    struct Screen_func_8042B644_de *screen;
    s32 changed;
    s32 count;
    s32 next;
    s32 limit;

    func_8029973C_de();
    if (event != 1) {
        return 0;
    }
    changed = 0;
    count = func_8042B154_de(func_8042B294_de(D_800E4F60->category));
    screen = D_800E4F60;
    if (screen->category != 0) {
        next = screen->selection + 1;
        if (next < count) {
            changed = 1;
            screen->selection = next;
        }
    } else {
        if (screen->selection >= 11) {
            next = screen->selection - 1;
            limit = 10;
        } else {
            limit = func_8042B154_de(func_8042B294_de(0));
            screen = D_800E4F60;
            next = screen->selection + 1;
            if (next == limit) {
                goto moved;
            }
            limit = 11;
        }
        if (next != limit) {
            changed = 1;
            screen->selection = next;
        }
    }
moved:
    if (changed != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    func_8042B2E4_de();
    D_800E4F60->word45C = 0;
    D_800E4F60->word464 = 0;
    D_800E4F60->item->value = 0x41;
    func_8042A990_de();
    func_8040E8D8_de(D_800E4F60->left, 0);
    func_8040E8D8_de(D_800E4F60->right, 1);
    func_8040E8D8_de(D_800E4F60->marker, 0);
    return 0;
}

s32 func_8042B78C_de(void *arg0, void *arg1, void *arg2, s32 event) {
    extern void func_8040E8D8_de(struct MenuMarker *, s32);
    extern struct Screen_func_8042B78C_de *D_800E4F60;
    struct Screen_func_8042B78C_de *screen;
    s32 changed;
    s32 count;
    s32 mirror;

    func_8029973C_de();
    if (event != 1) {
        return 0;
    }
    screen = D_800E4F60;
    changed = 0;
    if (screen->category != 0) {
        changed = 1;
        screen->category = screen->category - 1;
    } else if ((u32)(screen->selection - 5) < 6) {
        mirror = 21 - screen->selection;
        if (mirror < func_8042B154_de(func_8042B294_de(0))) {
            changed = 1;
            D_800E4F60->selection = mirror;
        }
    }
    if (changed != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    func_8042B2E4_de();
    D_800E4F60->word45C = 0;
    D_800E4F60->word464 = 0;
    D_800E4F60->item->alpha = 0x41;
    count = func_8042B154_de(func_8042B294_de(D_800E4F60->category));
    if (D_800E4F60->selection >= count) {
        D_800E4F60->selection = count - 1;
    }
    func_8042A990_de();
    if (D_800E4F60->selection == 0) {
        func_80439C80_de(D_800E4F60->view, D_800E4F60->category + 0xEA6);
        func_8040E8D8_de(D_800E4F60->marker, 1);
        D_800E4F60->marker->x = D_800E4F60->category * 34 + 0x7C;
    }
    return 0;
}

s32 func_8042B904_de(void *arg0, void *arg1, void *arg2, s32 event) {
    extern void func_8040E8D8_de(struct MenuMarker *, s32);
    extern struct Screen_func_8042B78C_de *D_800E4F60;
    struct Screen_func_8042B78C_de *screen;
    s32 changed;
    s32 count;

    func_8029973C_de();
    if (event != 1) {
        return 0;
    }
    screen = D_800E4F60;
    changed = 0;
    if (screen->category != 3) {
        changed = screen->category == 0;
        if (changed) {
            changed = 1;
            if (screen->selection >= 11) {
                screen->selection = 21 - screen->selection;
            } else {
                screen->category = changed;
            }
        } else {
            changed = 1;
            screen->category = screen->category + changed;
        }
    }
    if (changed != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    func_8042B2E4_de();
    D_800E4F60->word45C = 0;
    D_800E4F60->word464 = 0;
    D_800E4F60->item->alpha = 0x41;
    count = func_8042B154_de(func_8042B294_de(D_800E4F60->category));
    if (D_800E4F60->selection >= count) {
        D_800E4F60->selection = count - 1;
    }
    func_8042A990_de();
    if (D_800E4F60->selection == 0) {
        func_80439C80_de(D_800E4F60->view, D_800E4F60->category + 0xEA6);
        func_8040E8D8_de(D_800E4F60->marker, 1);
        D_800E4F60->marker->x = D_800E4F60->category * 34 + 0x7C;
    }
    return 0;
}

s32 func_8042BA54_de(void) {
    extern struct State_func_8042BA54_de *D_800E4F60;
    struct State_func_8042BA54_de *state;

    func_8029973C_de();
    state = D_800E4F60;
    if (state->mode == 3) {
        state->mode = 5;
        state->next = 4;
        return 0;
    }
    return 0;
}

s32 func_8042BA98_de(void) {
    extern struct State_func_8042BA98_de *D_800E4F60;
    if (D_800E4F60->mode == 3) {
        func_8042AAD0_de();
        return 0;
    }
    return 0;
}

s32 func_8042BAD0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8042BCB0 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E528C != 0) {
        wildcard = 0x7530;
        entry = &D_800E528C;
        index = 0;
        do {
            if (D_800E5284[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5288[index].value;
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
