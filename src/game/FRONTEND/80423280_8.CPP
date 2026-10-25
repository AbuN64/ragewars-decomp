#include "COMMON/RECRECAT4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SCREEN.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "FRONTEND/OPTIONS.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "FRONTEND/80423280_38.H"
#include "FRONTEND/80423280_39.H"
#include "FRONTEND/80423280_42.H"
#include "FRONTEND/80423280_8.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"
extern ResultsOptionsScreen *D_800E4690;
extern MenuWidget *func_8040EC30_de(void *, s32);

/* Opens the five option windows of screen D_800E4690: for each of options 0 to 4 it picks window
   0x149, 0x14C, 0x14D, 0x14E or 0x14F through jtbl_800DD9F0, opens it under the screen's parent at
   0x970, opens its 0x14B child and shows that through func_8040E8D8_de. The loop walks the table with
   its own pointer, as the cartridge's strength-reduced dispatch does. */


extern void func_8040E8D8_de(void *, s32);

#if defined(VERSION_DE)
enum { RESULTS_OPTION_329 = 327, RESULTS_OPTION_331 = 329, RESULTS_OPTION_332 = 330, RESULTS_OPTION_333 = 331, RESULTS_OPTION_334 = 332, RESULTS_OPTION_335 = 333 };
#elif defined(VERSION_EU_X)
enum { RESULTS_OPTION_329 = 333, RESULTS_OPTION_331 = 335, RESULTS_OPTION_332 = 336, RESULTS_OPTION_333 = 337, RESULTS_OPTION_334 = 338, RESULTS_OPTION_335 = 339 };
#else
enum { RESULTS_OPTION_329 = 329, RESULTS_OPTION_331 = 331, RESULTS_OPTION_332 = 332, RESULTS_OPTION_333 = 333, RESULTS_OPTION_334 = 334, RESULTS_OPTION_335 = 335 };
#endif

/* Releases the object D_800E4690 holds through func_802547E4_de, calls func_802A2360_de, clears D_800E4690, calls
   func_80245B28_de and returns zero. */



extern void func_802A2360_de();

/* On event 3 with value 0, calls MarkMenuEventHandled, sets the word at offset 0x988 of the object
   D_800E4690 points to to 8 and the byte at 0x10 of its item at 0xA50 to 0x5A, and plays sound
   0xE7C through func_8025DF34_de. Returns zero. */






extern void MarkMenuEventHandled();


/* Moves the menu cursor on event 1: when the current slot's successor in the 28-byte slot table
   (word at D_800E0658) exists and func_80265650_de reports it set in the menu's flags at 0xA74, it
   plays sound 0xE7D, shades the old window 0x46 or 0xAA by whether the old slot is set in the
   flags at 0xA79, opens the successor's window (halfword at D_800E0646_de) under arg0, refreshes
   through func_804280BC_de and, by the mode byte at 0xD of D_801462C8, through func_804281A8_de and
   func_80427B08_de unless the mode is 2 and func_804279B8_de when it is 4; returns zero. */








extern u8 D_801462C8[];

extern s32 func_80265650_de(u8 *, s32);

/* Moves the menu cursor on event 1: when the current slot's successor in the 28-byte slot table
   (word at D_800E065C) exists and func_80265650_de reports it set in the menu's flags at 0xA74, it
   plays sound 0xE7D, shades the old window 0x46 or 0xAA by whether the old slot is set in the
   flags at 0xA79, opens the successor's window (halfword at D_800E0646_de) under arg0, refreshes
   through func_804280BC_de and, by the mode byte at 0xD of D_801462C8, through func_804281A8_de and
   func_80427B08_de unless the mode is 2 and func_804279B8_de when it is 4; returns zero. Adapted from func_80428850_de with the successor word changed. */







/* Moves the menu cursor on event 1: when the current slot's successor in the 28-byte slot table
   (word at D_800E0654) exists and func_80265650_de reports it set in the menu's flags at 0xA74, it
   plays sound 0xE7D, shades the old window 0x46 or 0xAA by whether the old slot is set in the
   flags at 0xA79, opens the successor's window (halfword at D_800E0646_de) under arg0, refreshes
   through func_804280BC_de and, by the mode byte at 0xD of D_801462C8, through func_804281A8_de and
   func_80427B08_de unless the mode is 2 and func_804279B8_de when it is 4; returns zero. Adapted from func_80428850_de with the successor word changed. */







/* Moves the menu cursor on event 1: when the current slot's successor in the 28-byte slot table
   (word at D_800E0650) exists and func_80265650_de reports it set in the menu's flags at 0xA74, it
   plays sound 0xE7D, shades the old window 0x46 or 0xAA by whether the old slot is set in the
   flags at 0xA79, opens the successor's window (halfword at D_800E0646_de) under arg0, refreshes
   through func_804280BC_de and, by the mode byte at 0xD of D_801462C8, through func_804281A8_de and
   func_80427B08_de unless the mode is 2 and func_804279B8_de when it is 4; returns zero. Adapted from func_80428850_de with the successor word changed. */








/* Calls MarkMenuEventHandled and Frontend_HideTrialCatalogueWidgets, passes the two words after the identifier in the
   28-byte entry D_800E4690's selection at 0xA44 picks from D_800E4694 to func_8042E9A0_de, then
   calls func_8042E988_de with 0x19. Returns zero. */






extern struct EntryRecAt8V3 D_800E4694[];
/* The window table stores word-valued resource identifiers: the key is the word cast to 16 bits. The halfword at
   word+2 (the table symbol D_800E0646_de) is only its low half on big-endian MIPS. */
#define entryWindowKey(index) ((u16)D_800E4694[index].id)

extern void func_8042E9A0_de(s32, s32);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4D84, an actor kind at D_800E4D88 and a handler at D_800E4D8C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80429058)(void *, s32, s32, s32, s32);

extern Handler80429058 D_800E4D8C;

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4E20, an actor kind at D_800E4E24 and a handler at D_800E4E28: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler804290E8)(void *, s32, s32, s32, s32);

extern Handler804290E8 D_800E4E28;

void func_80428700_de(void) {
    s32 id = 0;
    s32 option;

    for (option = 0; option < 5; option++) {
        switch (option) {
        case 0:
            id = RESULTS_OPTION_329;
            break;
        case 1:
            id = RESULTS_OPTION_332;
            break;
        case 2:
            id = RESULTS_OPTION_333;
            break;
        case 3:
            id = RESULTS_OPTION_334;
            break;
        case 4:
            id = RESULTS_OPTION_335;
            break;
        }
        func_8040E8D8_de(func_8040EC30_de(func_8040EC30_de(D_800E4690->parent, id), RESULTS_OPTION_331), 1);
    }
}

s32 func_804287B8_de(void) {
    func_802547E4_de(D_800E4690);
    func_802A2360_de();
    D_800E4690 = 0;
    func_80245B28_de();
    return 0;
}

s32 func_804287F8_de(void *first, void *second, u32 event, s32 value) {
    ResultsOptionsScreen *state;

    if ((event >> 16) == 3 && value == 0) {
        MarkMenuEventHandled();
        state = D_800E4690;
        state->state = 8;
        state->item->alpha = 0x5A;
        func_8025DF34_de(0xE7C);
    }
    return 0;
}

s32 func_80428850_de(void *parent, s32 unused1, s32 unused2, s32 event) {
    s32 next;
    s32 set;
    u8 *options;

    MarkMenuEventHandled();
    if (event != 1) {
        return 0;
    }
    next = D_800E0658[D_800E4690->selection * 7];
    if (next == -1) {
        return 0;
    }
    set = func_80265650_de(D_800E4690->owned, next);
    if (set != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    if (func_80265650_de(D_800E4690->pending, D_800E4690->selection) == set) {
        D_800E4690->window->alpha = 0x46;
    } else {
        D_800E4690->window->alpha = 0xAA;
    }
    D_800E4690->selection = next;
    D_800E4690->window = func_8040EC30_de(parent, entryWindowKey(next));
    func_804280BC_de();
    options = D_801462C8;
    if (options[0xD] != 2) {
        func_804281A8_de();
        D_800E4690->frames = 0;
        func_80427B08_de();
    }
    if (options[0xD] == 4) {
        func_804279B8_de();
    }
    return 0;
}

s32 func_804289B4_de(void *parent, s32 unused1, s32 unused2, s32 event) {
    s32 next;
    s32 set;
    u8 *options;

    MarkMenuEventHandled();
    if (event != 1) {
        return 0;
    }
    next = D_800E065C[D_800E4690->selection * 7];
    if (next == -1) {
        return 0;
    }
    set = func_80265650_de(D_800E4690->owned, next);
    if (set != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    if (func_80265650_de(D_800E4690->pending, D_800E4690->selection) == set) {
        D_800E4690->window->alpha = 0x46;
    } else {
        D_800E4690->window->alpha = 0xAA;
    }
    D_800E4690->selection = next;
    D_800E4690->window = func_8040EC30_de(parent, entryWindowKey(next));
    func_804280BC_de();
    options = D_801462C8;
    if (options[0xD] != 2) {
        func_804281A8_de();
        D_800E4690->frames = 0;
        func_80427B08_de();
    }
    if (options[0xD] == 4) {
        func_804279B8_de();
    }
    return 0;
}

s32 func_80428B18_de(void *parent, s32 unused1, s32 unused2, s32 event) {
    s32 next;
    s32 set;
    u8 *options;

    MarkMenuEventHandled();
    if (event != 1) {
        return 0;
    }
    next = D_800E0654[D_800E4690->selection * 7];
    if (next == -1) {
        return 0;
    }
    set = func_80265650_de(D_800E4690->owned, next);
    if (set != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    if (func_80265650_de(D_800E4690->pending, D_800E4690->selection) == set) {
        D_800E4690->window->alpha = 0x46;
    } else {
        D_800E4690->window->alpha = 0xAA;
    }
    D_800E4690->selection = next;
    D_800E4690->window = func_8040EC30_de(parent, entryWindowKey(next));
    func_804280BC_de();
    options = D_801462C8;
    if (options[0xD] != 2) {
        func_804281A8_de();
        D_800E4690->frames = 0;
        func_80427B08_de();
    }
    if (options[0xD] == 4) {
        func_804279B8_de();
    }
    return 0;
}

s32 func_80428C7C_de(void *parent, s32 unused1, s32 unused2, s32 event) {
    s32 next;
    s32 set;
    u8 *options;

    MarkMenuEventHandled();
    if (event != 1) {
        return 0;
    }
    next = D_800E0650[D_800E4690->selection * 7];
    if (next == -1) {
        return 0;
    }
    set = func_80265650_de(D_800E4690->owned, next);
    if (set != 1) {
        return 0;
    }
    func_8025DF34_de(0xE7D);
    if (func_80265650_de(D_800E4690->pending, D_800E4690->selection) == set) {
        D_800E4690->window->alpha = 0x46;
    } else {
        D_800E4690->window->alpha = 0xAA;
    }
    D_800E4690->selection = next;
    D_800E4690->window = func_8040EC30_de(parent, entryWindowKey(next));
    func_804280BC_de();
    options = D_801462C8;
    if (options[0xD] != 2) {
        func_804281A8_de();
        D_800E4690->frames = 0;
        func_80427B08_de();
    }
    if (options[0xD] == 4) {
        func_804279B8_de();
    }
    return 0;
}

s32 func_80428DE0_de(void) {
    MarkMenuEventHandled();
    Frontend_HideTrialCatalogueWidgets();
    func_8042E988_de(0xE);
    return 0;
}

s32 func_80428E10_de(void) {
    s32 selection;

    MarkMenuEventHandled();
    Frontend_HideTrialCatalogueWidgets();
    selection = D_800E4690->selection;
    func_8042E9A0_de(D_800E4694[selection].first, D_800E4694[selection].second);
    func_8042E988_de(0x19);
    return 0;
}

s32 func_80428E78_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80429058 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E4D8C != 0) {
        wildcard = 0x7530;
        entry = &D_800E4D8C;
        index = 0;
        do {
            if (D_800E4D84[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4D88[index].value;
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

s32 func_80428F08_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler804290E8 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E4E28 != 0) {
        wildcard = 0x7530;
        entry = &D_800E4E28;
        index = 0;
        do {
            if (D_800E4E20[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4E24[index].value;
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
