#include "span_16E000/code_80423280.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_804290E8.h"
#include "TYPES.H"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "shared/func_80421E70_eu_closed.h"
#include "span_16E000/code_804366C4.h"

/* Refreshes the option block D_801462C8 from the menu D_800E4EF0 points to: the bytes at 0x24 to
   0x27 from the values func_802A1B18_de reports for its items at 0x28, 0x24, 0x2C and 0x30, and the
   byte at 0x28 from the selection func_8041AD04_de reports for its item at 0x1C. */







/* Synchronizes screen D_800E4EF0's option widgets and player-count widget with the stored option
 * block D_801462C8 and the live player count: pushes the four stored option bytes back into their
 * checkbox widgets, sets the player-count widget to the lesser of the screen's cap and the live
 * player count (or the screen's default when that count is zero), and sets the selection and
 * cursor widgets from the stored selection byte and the current cursor value. */







extern void func_802A1B24_de(void *arg0, s32 arg1);

extern void func_8041AD10_de(void *arg0, s32 arg1);


/* Refreshes the entry list of screen D_800E4EF0: reads the selection of its cursor at 0x20 through
   func_8041AD04_de and the entry count of its list at 0x34 through func_802A1B18_de. With no entries it
   clears the list through func_8041EA70_de; otherwise, when the count differs from what
   func_8041EB50_de shows or force is 1, it clears the list and rebuilds it for the count and
   selection through func_8041E81C_de. */




extern void func_8041EA70_de(void);


/* Releases the object D_800E4EF0 holds through func_802547E4_de, clears D_800E4EF0 and returns zero. */


extern void func_802547E4_de(void *);



/* Handles the menu message func_80299A08_de reports after func_8029973C_de unless func_8043C308_de reports
   screen D_800E4EF0 busy: 0x36B closes the menu through func_804294C4_de, sends code -1 to
   func_8042E988_de and calls func_802998A8_de; 0x369 does the same with page reset func_80429654_de(0)
   and code 0x17 when func_802A1B18_de reports the screen's list at 0x34 non-empty; 0x36A always does
   it with func_8041E5F8_de and code 0x19, then calls func_802A2394_de. Returns zero. */




extern void func_802998A8_de(void);

extern void func_8041E5F8_de(void);


/* Calls func_8029973C_de and, unless func_8043C308_de reports one for the object D_800E4EF0 holds, calls
   func_804294C4_de, func_8042E988_de with -1 and func_802998A8_de. Returns zero. */


extern void func_8029973C_de();


/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4EF4, an actor kind at D_800E4EF8 and a handler at D_800E4EFC: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80429B74)(void *, s32, s32, s32, s32);



extern Handler80429B74 D_800E4EFC;

void func_804294C4_de(void) {
    extern s32 func_8041AD04_de(void *);
    extern s32 func_802A1B18_de(void *);
    extern struct Options D_801462C8;
    extern func_804296A4_S1 *D_800E4EF0;
    struct Options *options;
    s32 value;

    value = func_802A1B18_de(D_800E4EF0->unk28);
    options = &D_801462C8;
    options->values[0] = value;
    options->values[1] = func_802A1B18_de(D_800E4EF0->unk24);
    options->values[2] = func_802A1B18_de(D_800E4EF0->unk2C);
    options->values[3] = func_802A1B18_de(D_800E4EF0->unk30);
    options->values[4] = func_8041AD04_de(D_800E4EF0->unk1C);
}

void func_80429560_de(void) {
    extern struct Options_func_80429560_de D_801462C8;
    extern struct Screen_func_80429560_de *D_800E4EF0;
    struct Options_func_80429560_de *opts;
    s32 count;
    s32 cap;

    opts = &D_801462C8;
    func_802A1B24_de(D_800E4EF0->widget24, opts->val1);
    func_802A1B24_de(D_800E4EF0->widget28, opts->val0);
    func_802A1B24_de(D_800E4EF0->widget2C, opts->val2);
    func_802A1B24_de(D_800E4EF0->widget30, opts->val3);
    count = func_8041EB50_de();
    cap = D_800E4EF0->countCap;
    if (cap < count) {
        count = cap;
    }
    if (count == 0) {
        count = D_800E4EF0->countDefault;
    }
    func_802A1B24_de(D_800E4EF0->widget34, count);
    func_8041AD10_de(D_800E4EF0->selectWidget, opts->val4);
    func_8041AD10_de(D_800E4EF0->cursorWidget, func_8041E720_de());
}

void func_80429654_de(s32 force) {
    extern s32 func_8041AD04_de(s32);
    extern s32 func_802A1B18_de(s32);
    extern struct Screen_func_80429654_de *D_800E4EF0;
    s32 selection;
    s32 count;

    selection = func_8041AD04_de(D_800E4EF0->cursor);
    count = func_802A1B18_de(D_800E4EF0->list);
    if (count <= 0) {
        func_8041EA70_de();
        return;
    }
    if (count != func_8041EB50_de() || force == 1) {
        func_8041EA70_de();
        func_8041E81C_de(count, selection);
    }
}

s32 func_804296F4_de(void) {
    extern void *D_800E4EF0;
    func_802547E4_de(D_800E4EF0);
    D_800E4EF0 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80429724_de(void) {
    return 0;
}

s32 func_8042972C_de(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    extern struct Screen_func_8042972C_de *D_800E4EF0;
    u32 kind;
    void *widget;
    s32 value;

    kind = arg2 >> 0x10;
    if ((kind == 3) && (arg3 == 2)) {
        func_8029973C_de();
        switch (func_80299A08_de()) {
#if defined(VERSION_DE)
        case 0x35F:
#elif defined(VERSION_EU_X)
        case 0x367:
#else
        case 0x363:
#endif
            widget = D_800E4EF0->widget24;
            value = 0;
            func_802A1B24_de(widget, value);
            break;
#if defined(VERSION_DE)
        case 0x35D:
#elif defined(VERSION_EU_X)
        case 0x365:
#else
        case 0x361:
#endif
            widget = D_800E4EF0->widget28;
            value = 0;
            func_802A1B24_de(widget, value);
            break;
#if defined(VERSION_DE)
        case 0x35B:
#elif defined(VERSION_EU_X)
        case 0x363:
#else
        case 0x35F:
#endif
            widget = D_800E4EF0->widget2C;
            value = 0;
            func_802A1B24_de(widget, value);
            break;
#if defined(VERSION_DE)
        case 0x361:
#elif defined(VERSION_EU_X)
        case 0x369:
#else
        case 0x365:
#endif
            widget = D_800E4EF0->widget30;
            value = 0;
            func_802A1B24_de(widget, value);
            break;
#if defined(VERSION_DE)
        case 0x368:
#elif defined(VERSION_EU_X)
        case 0x370:
#else
        case 0x36C:
#endif
            widget = D_800E4EF0->widget34;
            value = D_800E4EF0->countDefault;
            func_802A1B24_de(widget, value);
            break;
        }
    }
    return 0;
}

s32 func_804297F8_de(void) {
    extern s32 func_8043C308_de(struct func_8020F2A8_S3 *);
    extern s32 func_802A1B18_de(s32);
    extern struct func_8020F2A8_S3 *D_800E4EF0;
    func_8029973C_de();
    if (func_8043C308_de(D_800E4EF0) == 1) {
        return 0;
    }
    switch (func_80299A08_de()) {
#if defined(VERSION_DE)
    case 0x367:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x36B:
#elif defined(VERSION_EU_X)
    case 0x36F:
#endif
        func_804294C4_de();
        func_8042E988_de(-1);
        func_802998A8_de();
        break;
#if defined(VERSION_DE)
    case 0x365:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x369:
#elif defined(VERSION_EU_X)
    case 0x36D:
#endif
        if (func_802A1B18_de(D_800E4EF0->unk34) > 0) {
            func_804294C4_de();
            func_80429654_de(0);
            func_8042E988_de(0x17);
            func_802998A8_de();
        }
        break;
#if defined(VERSION_DE)
    case 0x366:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x36A:
#elif defined(VERSION_EU_X)
    case 0x36E:
#endif
        func_804294C4_de();
        func_80429654_de(0);
        func_8041E5F8_de();
        func_8042E988_de(0x19);
        func_802998A8_de();
        func_802A2394_de();
        break;
    }
    return 0;
}

s32 func_804298F8_de(void) {
    extern s32 func_8043C308_de(void *);
    extern void *D_800E4EF0;
    func_8029973C_de();
    if (func_8043C308_de(D_800E4EF0) == 1) {
        return 0;
    }
    func_804294C4_de();
    func_8042E988_de(-1);
    func_802998A8_de();
    return 0;
}

s32 func_8042994C_de(void *first, void *second, void *third, s32 fourth) {
    if (fourth == 0) {
        func_80429654_de(1);
        return 0;
    }
    return 0;
}

s32 func_80429970_de(void *first, void *second, void *third, s32 fourth) {
    if (fourth == 0) {
        func_80429654_de(1);
        return 0;
    }
    return 0;
}

s32 func_80429994_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80429B74 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E4EFC != 0) {
        wildcard = 0x7530;
        entry = &D_800E4EFC;
        index = 0;
        do {
            if (D_800E4EF4[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4EF8[index].value;
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
