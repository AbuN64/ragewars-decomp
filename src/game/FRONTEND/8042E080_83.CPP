#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"

/* Event callback for screen D_800E5554: on event 1 while func_8043C308_de reports the screen in state 1 it advances the screen through Frontend_DrawMenuImage and func_8043C2A4_de, and when that leaves it in state 2 it calls func_8040C428_de(0) and MarkMenuEventHandled, clears the pause word D_80146894 (0x180C past the match objects at D_80145088), stops those objects and the ones 0x48 bytes before them, releases resource 0x24 of D_8011FE88, restarts func_8025476C_de when func_8025477C_de reports it idle, stores 8 at 0x17F0 past the match objects, passes the screen's word at 0x1C to func_80298368_de and calls func_8025E384_de, returning zero. Adapted from func_804362A8_de with the screen D_800E5558 changed to D_800E5554, a func_8040C428_de(0) call added, and the trailing func_8042DEA0_de call replaced by the store of 8 and the func_80298368_de call before func_8025E384_de. */

extern MenuRules *D_800E5554;


extern s32 func_8043C308_de(void *);
extern void Frontend_DrawMenuImage(void *);
extern void func_8043C2A4_de(void *);
extern void Frontend_RequestScreenMode(s32);
extern void MarkMenuEventHandled(void);
extern void Items_ResetActorPools(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(s32);
extern void func_80298368_de(void *);
extern void func_8025E384_de(void);

s32 func_80435F14_de(s32 unused0, s32 unused1, s32 event) {
    s32 *pause;
    if (event == 1) {
        if (func_8043C308_de(D_800E5554) != 1) {
            return 0;
        }
        Frontend_DrawMenuImage(D_800E5554);
        func_8043C2A4_de(D_800E5554);
        if (func_8043C308_de(D_800E5554) != 2) {
            return 0;
        }
        Frontend_RequestScreenMode(0);
        MarkMenuEventHandled();
        pause = &D_80145088.status[7];
        *pause = 0;
        Items_ResetActorPools((char *)pause - 0x180C, 0);
        func_804499B0_de((char *)pause - 0x1854, 0, 0);
        func_80286AA8_de(&D_8011FE88, 0x24, 0);
        if (func_8025477C_de() == 0) {
            func_8025476C_de(1);
        }
        pause[-7] = 8;
        func_80298368_de((void *)D_800E5554->locked);
        func_8025E384_de();
    }
    return 0;
}
