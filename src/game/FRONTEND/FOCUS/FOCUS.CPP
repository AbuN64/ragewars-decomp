#include "include_asm.h"
#include "SCENE/802508E0_13.H"
#include "COMMON/PLAYERPROFILES.H"



#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LABEL.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
extern void func_8025476C_de(unsigned int value);
extern int func_8025477C_de(void);
extern PlayerRecord D_800FEB4A[];
extern s32 Defs_TestBit(void *bits, s32 bit);

static __inline__ MenuFrontendRefreshUnlockedFocusLabel *screen32(void) {
    void *block = D_800E3590;
    return block;
}

static __inline__ void *record32(void) { return &D_800E3590->record; }


#if defined(VERSION_DE)
enum { PROFILE_RESOURCE_498 = 494, PROFILE_RESOURCE_499 = 495, PROFILE_RESOURCE_500 = 496, PROFILE_RESOURCE_502 = 498, PROFILE_RESOURCE_505 = 501, PROFILE_RESOURCE_506 = 502, PROFILE_RESOURCE_509 = 505 };
#elif defined(VERSION_EU_X)
enum { PROFILE_RESOURCE_498 = 502, PROFILE_RESOURCE_499 = 503, PROFILE_RESOURCE_500 = 504, PROFILE_RESOURCE_502 = 507, PROFILE_RESOURCE_505 = 509, PROFILE_RESOURCE_506 = 511, PROFILE_RESOURCE_509 = 513 };
#else
enum { PROFILE_RESOURCE_498 = 498, PROFILE_RESOURCE_499 = 499, PROFILE_RESOURCE_500 = 500, PROFILE_RESOURCE_502 = 502, PROFILE_RESOURCE_505 = 505, PROFILE_RESOURCE_506 = 506, PROFILE_RESOURCE_509 = 509 };
#endif

/* The hub spells D_800E3590 as the menu block; this unit keeps its ProfileStatisticsScreen view
   because it reads the 0x32-byte text buffers from 0x110 up, which the hub only pads over. */

extern char g_longAndIntFormats[];

extern char D_800DD50C[];

/* EC30 hands back the hub Item view; this unit reads/writes the Label view (text pointer at 0x38)
   through the store-side cast. */
extern void XStdio_FormatBuffer(char *, char *, s32);

extern char *Achieve_UpdateRankText(s32);

extern s32 Achieve_CountEarnedAchievements(s32);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/MENU_MATCH_GLOBALS.H"
#endif

/* The hub spells D_800E3590 as the padded menu block; its focus slot at +0x0EC is a word there,
   while this unit's view types it as a node pointer, so each member use casts to the view. */
extern TextEntry D_800DF544[];

extern char D_800DD4C8[];

extern signed char D_80102B0D[];


void Frontend_UpdateFocusCaption(void) {
    s32 index;
    s32 count;
    s32 text;
    if (screen32()->focus == 0) {
        Frontend_SetPreviewModel(record32(), 0);
        return;
    }
    for (index = 0; index < 50; index++) {
        if (D_800DF544[index].id == screen32()->focus->unkC) {
            if (Defs_TestBit(&D_800FEB4A[screen32()->player], index) == 1) {
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
                Frontend_SetPreviewModel(record32(), text);
                Frontend_SetPreviewRenderFlags(record32(), count);
                if (func_8025477C_de() == 0) func_8025476C_de(1);
            } else {
                Frontend_SetPreviewModel(record32(), 0);
            }
            return;
        }
    }
}

/* Fills the player record screen for the selected record D_80102B00[index]: shows the record's
   name in item 0x1F3 and its rank text from Achieve_UpdateRankText in item 0x1F2, and formats into the
   screen's text buffers the record's counters at 0x70, 0x6C and 0x74, the value Achieve_CountEarnedAchievements
   reports and the byte at 0x17 for items 0x1FD, 0x1F4, 0x1F6, 0x1F9 and 0x1FA, making each item
   visible through func_8040E8D8_de. */
void Frontend_RefreshProfileStatistics(void) {
    func_8041F2A0_Item *item;
    s32 score;

    item = Frontend_FindWidgetByResourceId(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_499);
    Frontend_SetWidgetFlag08(item, 1);
    ((Label *) item)->text = D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].name;
    item = Frontend_FindWidgetByResourceId(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_498);
    Frontend_SetWidgetFlag08(item, 1);
    ((Label *) item)->text = Achieve_UpdateRankText(((ProfileStatisticsScreen *) D_800E3590)->index);
    item = Frontend_FindWidgetByResourceId(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_509);
    Frontend_SetWidgetFlag08(item, 1);
    XStdio_FormatBuffer(((ProfileStatisticsScreen *) D_800E3590)->kills, g_longAndIntFormats, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.kills);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->kills;
    item = Frontend_FindWidgetByResourceId(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_500);
    Frontend_SetWidgetFlag08(item, 1);
    XStdio_FormatBuffer(((ProfileStatisticsScreen *) D_800E3590)->wins, g_longAndIntFormats, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.wins);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->wins;
    item = Frontend_FindWidgetByResourceId(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_502);
    Frontend_SetWidgetFlag08(item, 1);
    XStdio_FormatBuffer(((ProfileStatisticsScreen *) D_800E3590)->deaths, g_longAndIntFormats, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].statistics.deaths);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->deaths;
    score = Achieve_CountEarnedAchievements(((ProfileStatisticsScreen *) D_800E3590)->index);
    item = Frontend_FindWidgetByResourceId(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_505);
    Frontend_SetWidgetFlag08(item, 1);
    XStdio_FormatBuffer(((ProfileStatisticsScreen *) D_800E3590)->score, D_800DD50C, score);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->score;
    item = Frontend_FindWidgetByResourceId(((ProfileStatisticsScreen *) D_800E3590)->handle, PROFILE_RESOURCE_506);
    Frontend_SetWidgetFlag08(item, 1);
    XStdio_FormatBuffer(((ProfileStatisticsScreen *) D_800E3590)->count, D_800DD50C, D_80102B00[((ProfileStatisticsScreen *) D_800E3590)->index].count);
    ((Label *) item)->text = ((ProfileStatisticsScreen *) D_800E3590)->count;
}

/* Sets the label text for the focused node: the text of its entry in the 50-entry id table when the
   current player's unlock bit for that entry is set, otherwise the default text; the European
   cartridges hold each entry's text per language and pick the current language's. */
void Frontend_RefreshUnlockedFocusLabel(void) {
    s32 i;
    if (((MenuFrontendRefreshUnlockedFocusLabel *) D_800E3590)->focus == 0) {
        ((MenuFrontendRefreshUnlockedFocusLabel *) D_800E3590)->label->text = D_800DD4C8 + 4;
        return;
    }
    for (i = 0; i < 50; i++) {
        if (D_800DF544[i].id == ((MenuFrontendRefreshUnlockedFocusLabel *) D_800E3590)->focus->unkC) {
            if (Defs_TestBit(&D_800FEB4A[((MenuFrontendRefreshUnlockedFocusLabel *) D_800E3590)->player], i) == 1) {
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
                ((MenuFrontendRefreshUnlockedFocusLabel *) D_800E3590)->label->text = D_800DF544[i].text[0];
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
                ((MenuFrontendRefreshUnlockedFocusLabel *) D_800E3590)->label->text = D_800DF544[i].text[D_80145088.settings.language];
#endif
            } else {
                ((MenuFrontendRefreshUnlockedFocusLabel *) D_800E3590)->label->text = D_800DD4C8 + 4;
            }
            return;
        }
    }
}

void Frontend_ShowUnlockedEntries(s32 style) {
    MenuWidget *node;
    s32 i;
    for (i = 0; i < 50; i++) {
        node = Frontend_FindWidgetByResourceId(D_800E3590->root, (u16)D_800DF544[i].id);
        if (Defs_TestBit(&D_800FEB4A[D_800E3590->unk268], i) == 1) {
            Frontend_SetWidgetFlag08(node, 1);
            node->alpha = style;
        } else {
            Frontend_SetWidgetFlag08(node, 0);
        }
    }
}

/* Advances a cursor over four 400-byte entries, wrapping to 0, until it reaches one whose flag byte in
   D_80102B0D is not negative; after six steps without one it sets the cursor to -1. */
void Frontend_AdvanceActiveSlot(int *cursor) {
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


/* Releases the object D_800E3590 holds through Cache_FreeMemory, clears D_800E3590 and returns zero.
 * The hub names D_800E3590 as the menu block it points at; the release helper takes a plain pointer
 * and the clear stores a null word. */
s32 Frontend_FreeMenuBlock(void) {
    Cache_FreeMemory(D_800E3590);
    D_800E3590 = 0;
    return 0;
}
