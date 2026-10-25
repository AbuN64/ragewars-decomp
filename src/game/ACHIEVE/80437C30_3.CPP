#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/WORLD.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "TYPES.H"
#include "ACHIEVE/80437C30.H"
#include "ACHIEVE/80437C30_3.H"
#include "SCENE/802508E0_13.H"

/* Resets three words of the object D_800E5830 points to: the words at 0x9C and 0xB0 to -1 and
   the word at 0x188 to zero. */




/* Releases the object D_800E5830 holds through Scene_FreeMemory, clears D_800E5830 and returns zero. */



/* Handles event 1 on the screen D_800E5830: unless func_8043C308_de reports its menu in state 1 it
   calls func_80438828_de; otherwise it advances the menu with Frontend_DrawMenuImage and func_8043C2A4_de and,
   once func_8043C308_de reports 2, acts on the choice at 0x1C: choice 0 calls MarkMenuEventHandled, clears
   D_80146918 and D_801468F4 and leaves through func_80298368_de for screen 0xA unless D_80146948 is 1
   and D_8015402C is at least 35, in which case it leaves for screen 7 when option D_801462D5 is 1
   and screen 3 otherwise; choice 1 calls func_8040C428_de(0), shows the window argument, stops the
   objects at D_80145088 and 0x48 before it, releases D_8011FE88 through func_80286AA8_de and sets the
   word at 0x17F0 of D_80145088 to 8. Returns zero. Adapted from func_8042D4FC_de with the option cases written in the order that reproduces the
   cartridge's decision tree. */










extern struct SelectionMessageScreen *D_800E5830;

extern void Frontend_DrawMenuImage(struct MenuRules *);

extern void func_8043C2A4_de(struct MenuRules *);



extern void Frontend_SetWidgetFlag08(void *, s32);

extern void Items_ResetActorPools(void *, s32);

extern void func_804499B0_de(void *, s32, s32);

extern void func_80286AA8_de(void *, s32, s32);

extern void MarkMenuEventHandled();

extern void func_80298368_de(s32);

/* Runs the screen D_800E5830 each frame until stage 1 of D_800E28E0: on its first frame it marks
   the word at 0x90, passes 0x272 to func_802991D4_de, or 0x273 when func_8040EBD0_de
   reports zero for item 0x273 of the window argument, also 0x272 when D_80146948 is clear, and calls func_802A2360_de; then, once the
   reply pair ending at D_80154024 is marked, it clears the mark and either hides the item at 0x24,
   clears the word at 0x1C0, calls MarkMenuEventHandled and leaves through func_80298368_de with the reply,
   or for a reply of -1 shows the item again and sets 0x1C0 to one. Returns zero. Written from the
   assembly; the conditional tests the zero case first. */


extern void *func_8040EC30_de(void *, s32);

extern s32 Frontend_ListHasFlag100(void *);

extern void func_802991D4_de(s32);

extern void func_802A2360_de();

void func_80438A88_de(void) {
    struct SelectionMessageScreen *state = D_800E5830;

    state->first = -1;
    state->second = -1;
    state->third = 0;
}

s32 func_80438AA4_de(void) {
    Scene_FreeMemory(D_800E5830);
    D_800E5830 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80438AD4_de(void) {
    return 0;
}

extern s32 D_801468F4; /* MIXED func_80438ADC_de */
extern s32 D_80146918; /* MIXED func_80438ADC_de */
extern s32 D_80146948; /* MIXED func_80438ADC_de */
s32 func_80438ADC_de(void *window, void *unused1, s32 event) {
    s32 state;
    char *object;
    s32 next;

    if (event != 1) {
        return 0;
    }
    state = func_8043C308_de((Shared_OptionsScreen *)&D_800E5830->rules);
    if (state == event) {
        Frontend_DrawMenuImage(&D_800E5830->rules);
        func_8043C2A4_de(&D_800E5830->rules);
        if (func_8043C308_de((Shared_OptionsScreen *)&D_800E5830->rules) != 2) {
            return 0;
        }
        if (D_800E5830->rules.locked != 0) {
            if (D_800E5830->rules.locked != state) {
                return 0;
            }
            Frontend_RequestScreenMode(0);
            Frontend_SetWidgetFlag08(window, 1);
            object = &D_80145088;
            Items_ResetActorPools(object, 0);
            func_804499B0_de(object - 0x48, 0, 0);
            func_80286AA8_de(&D_8011FE88, 0, 0);
            ((MatchMenuObjects *)(object))->transition = 8;
        } else {
            MarkMenuEventHandled();
            D_80146918 = 0;
            D_801468F4 = 0;
            if (D_80146948 == state && D_8015402C >= 35) {
                switch (D_801462C8.controllerMode) {
                case 4:
                    next = 3;
                    break;
                default:
                    next = 3;
                    break;
                case 1:
                    next = 7;
                    break;
                case 3:
                    next = 3;
                    break;
                }
            } else {
                next = 0xA;
            }
            func_80298368_de(next);
            return 0;
        }
    } else {
        func_80438828_de();
    }
    return 0;
}

s32 func_80438C84_de(void *window) {
    s32 *pair;
    s32 marked;
    if (D_800E28E0 > 0) {
        return 0;
    }
    if (D_800E5830->started == 0) {
        D_800E5830->started = 1;
#if defined(VERSION_DE)
        func_802991D4_de(Frontend_ListHasFlag100(func_8040EC30_de(window, 0x26F)) == 0 ? 0x26F : 0x26E);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        func_802991D4_de(Frontend_ListHasFlag100(func_8040EC30_de(window, 0x273)) == 0 ? 0x273 : 0x272);
#elif defined(VERSION_EU_X)
        func_802991D4_de(Frontend_ListHasFlag100(func_8040EC30_de(window, 0x278)) == 0 ? 0x278 : 0x277);
#endif
        if (D_801462C8.counters.humanWon == 0) {
#if defined(VERSION_DE)
            func_802991D4_de(0x26E);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
            func_802991D4_de(0x272);
#elif defined(VERSION_EU_X)
            func_802991D4_de(0x277);
#endif
        }
        func_802A2360_de();
    }
    pair = &D_80154020.ready;
    marked = pair[0];
    if (marked == 1) {
        pair[0] = 0;
        if (pair[-1] != -1) {
            Frontend_SetWidgetFlag08(D_800E5830->item, 0);
            D_800E5830->busy = 0;
            MarkMenuEventHandled();
            func_80298368_de(pair[-1]);
            return 0;
        }
        Frontend_SetWidgetFlag08(D_800E5830->item, 1);
        D_800E5830->busy = marked;
    }
    return 0;
}

#if defined(VERSION_DE)
enum { MSG_BACK = 0x26F, MSG_HIDE = 0x26E, MSG_LEAVE = 0x273 };
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
enum { MSG_BACK = 0x273, MSG_HIDE = 0x272, MSG_LEAVE = 0x277 };
#else
enum { MSG_BACK = 0x278, MSG_HIDE = 0x277, MSG_LEAVE = 0x27C };
#endif
extern void func_80434FB4_de(s32);
extern void func_8042E988_de(s32);
extern s32 func_80299A08_de(void);
extern void func_8043C278_de(void *);

s32 func_80438D94_de(void) {
    MarkMenuEventHandled();
    if (func_8043C308_de((Shared_OptionsScreen *)&D_800E5830->rules) != 1) {
        D_80145088.status[7] = 0;
        switch (func_80299A08_de()) {
        case MSG_HIDE:
            func_8043C278_de(D_800E5830);
            D_800E5830->rules.locked = 0;
            break;
        case MSG_BACK:
            func_80434FB4_de(5);
            func_80298368_de(0x13);
            return 0;
        case MSG_LEAVE:
            func_8042E988_de(0x21);
            break;
        default:
            return 0;
        }
        return 0;
    }
    return 0;
}

