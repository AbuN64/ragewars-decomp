#include "span_16E000/code_8041BEA8.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_80286080_de_closed.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "shared/func_804220A8_de_closed.h"
#include "shared/func_80438614_de_closed.h"
#include "TYPES.H"

extern PlayerRecord D_800FEB4A[];

static __inline__ Menu_func_8041D960_de *screen32(void) {
    void *block = D_800E3590;
    return block;
}

static __inline__ void *record32(void) { return &D_800E3590->record; }

/* Fills the player record screen for the selected record D_80102B00[index]: shows the record's
   name in item 0x1F3 and its rank text from func_80424DE8_de in item 0x1F2, and formats into the
   screen's text buffers the record's counters at 0x70, 0x6C and 0x74, the value func_80426004_de
   reports and the byte at 0x17 for items 0x1FD, 0x1F4, 0x1F6, 0x1F9 and 0x1FA, making each item
   visible through func_8040E8D8_de. */

#if defined(VERSION_DE)
enum { PROFILE_RESOURCE_498 = 494, PROFILE_RESOURCE_499 = 495, PROFILE_RESOURCE_500 = 496, PROFILE_RESOURCE_502 = 498, PROFILE_RESOURCE_505 = 501, PROFILE_RESOURCE_506 = 502, PROFILE_RESOURCE_509 = 505 };
#elif defined(VERSION_EU_X)
enum { PROFILE_RESOURCE_498 = 502, PROFILE_RESOURCE_499 = 503, PROFILE_RESOURCE_500 = 504, PROFILE_RESOURCE_502 = 507, PROFILE_RESOURCE_505 = 509, PROFILE_RESOURCE_506 = 511, PROFILE_RESOURCE_509 = 513 };
#else
enum { PROFILE_RESOURCE_498 = 498, PROFILE_RESOURCE_499 = 499, PROFILE_RESOURCE_500 = 500, PROFILE_RESOURCE_502 = 502, PROFILE_RESOURCE_505 = 505, PROFILE_RESOURCE_506 = 506, PROFILE_RESOURCE_509 = 509 };
#endif

/* The hub spells D_800E3590 as the menu block; this unit keeps its ProfileStatisticsScreen view
   because it reads the 0x32-byte text buffers from 0x110 up, which the hub only pads over. */
extern Profile D_80102B00[];

extern char D_800DD508_de[];

extern char D_800DD50C[];

/* EC30 hands back the hub Item view; this unit reads/writes the Label view (text pointer at 0x38)
   through the store-side cast. */
extern void func_802A0C08_de(char *, char *, s32);

extern char *func_80424DE8_de(s32);

extern s32 func_80426004_de(s32);

/* Sets the label text for the focused node: the text of its entry in the 50-entry id table when the
   current player's unlock bit for that entry is set, otherwise the default text; the European
   cartridges hold each entry's text per language and pick the current language's. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
#include "shared/menu_match_globals.h"
#endif

/* The hub spells D_800E3590 as the padded menu block; its focus slot at +0x0EC is a word there,
   while this unit's view types it as a node pointer, so each member use casts to the view. */
extern TextEntry D_800DF544[];

extern char D_800DD4C8[];

/* Advances a cursor over four 400-byte entries, wrapping to 0, until it reaches one whose flag byte in
   D_80102B0D is not negative; after six steps without one it sets the cursor to -1. */
extern signed char D_80102B0D[];

/* Releases the object D_800E3590 holds through func_802547E4_de, clears D_800E3590 and returns zero.
 * The hub names D_800E3590 as the menu block it points at; the release helper takes a plain pointer
 * and the clear stores a null word. */
extern void func_802547E4_de(void *);

struct ObjectB8;

void func_8041D4E0_de(void) {
    extern s32 func_80265650_de(void *, s32);
    s32 index;
    s32 count;
    s32 text;
    if (screen32()->focus == 0) {
        func_80439C80_de(record32(), 0);
        return;
    }
    for (index = 0; index < 50; index++) {
        if (D_800DF544[index].id == screen32()->focus->unkC) {
            if (func_80265650_de(&D_800FEB4A[screen32()->player], index) == 1) {
                text = 0;
                count = 0;
                switch (index) {
                case 36: text = 3701; break;
                case 37: text = 3702; break;
                case 38: text = 3703; break;
                case 39: text = 3704; break;
                case 40: text = 3705; break;
                case 41: text = 3706; break;
                case 42: text = 3707; break;
                case 43: text = 3708; break;
                case 44: text = 3709; break;
                case 45: text = 3710; break;
                case 46: text = 3711; break;
                case 47: text = 3712; break;
                case 48: text = 3713; break;
                case 49: text = 3714; break;
                default: text = 0xE74; count = index; break;
                }
                func_80439C80_de(record32(), text);
                func_80439CD4_de(record32(), count);
                if (func_8025477C_de() == 0) func_8025476C_de(1);
            } else {
                func_80439C80_de(record32(), 0);
            }
            return;
        }
    }
}

void func_8041D6A8_de(void) {
    func_8041F2A0_Item *item;
    s32 score;

    item = func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_499);
    func_8040E8D8_de(item, 1);
    ((Label *) item)->text = D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].name;
    item = func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_498);
    func_8040E8D8_de(item, 1);
    ((Label *) item)->text = func_80424DE8_de(((ProfileStatisticsScreen *) D_800E3590)->index);
    item = func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_509);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->kills, D_800DD508_de, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.kills);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->kills;
    item = func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_500);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->wins, D_800DD508_de, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.wins);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->wins;
    item = func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_502);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->deaths, D_800DD508_de, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.deaths);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->deaths;
    score = func_80426004_de(((ProfileStatisticsScreen *) D_800E3590)->index);
    item = func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_505);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->score, D_800DD50C, score);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->score;
    item = func_8040EC30_de(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_506);
    func_8040E8D8_de(item, 1);
    func_802A0C08_de(((ProfileStatisticsScreen *) D_800E3590)->count, D_800DD50C, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].count);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->count;
}

void func_8041D960_de(void) {
    extern s32 func_80265650_de(PlayerRecord *bits, s32 bit);
    s32 i;
    if (((Menu_func_8041D960_de *) D_800E3590)->focus == 0) {
        ((Menu_func_8041D960_de *) D_800E3590)->label->text = D_800DD4C8 + 4;
        return;
    }
    for (i = 0; i < 50; i++) {
        if (D_800DF544[i].id == ((Menu_func_8041D960_de *) D_800E3590)->focus->unkC) {
            if (func_80265650_de(&D_800FEB4A[((Menu_func_8041D960_de *) D_800E3590)->player], i) == 1) {
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
                ((Menu_func_8041D960_de *) D_800E3590)->label->text = D_800DF544[i].text[0];
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
                ((Menu_func_8041D960_de *) D_800E3590)->label->text = D_800DF544[i].text[D_80145088.settings.language];
#endif
            } else {
                ((Menu_func_8041D960_de *) D_800E3590)->label->text = D_800DD4C8 + 4;
            }
            return;
        }
    }
}

void func_8041DA5C_de(s32 style) {
    extern s32 func_80265650_de(PlayerRecord *bits, s32 bit);
    s32 i;
    func_8041F2A0_Item *node;

    for (i = 0; i < 50; i++) {
        node = func_8040EC30_de(D_800E3590->root, (u16) D_800DF544[i].id);
        if (func_80265650_de(&D_800FEB4A[((MenuRecAt10C *) D_800E3590)->player], i) == 1) {
            func_8040E8D8_de(node, 1);
            ((NodeRecAt10 *) node)->style = style;
        } else {
            func_8040E8D8_de(node, 0);
        }
    }
}

void func_8041DB30_de(int *cursor) {
    int steps;

    steps = 0;
    do {
        (*cursor)++;
        if (*cursor >= 4) {
            *cursor = 0;
        }
        steps++;
        if (steps >= 6) {
            *cursor = -1;
            return;
        }
    } while (D_80102B0D[*cursor * 400] < 0);
}

s32 func_8041DB9C_de(void) {
    func_802547E4_de(D_800E3590);
    D_800E3590 = 0;
    return 0;
}
