#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"

#if (!(defined(VERSION_US) || defined(VERSION_US_REV1))) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_80400000", Menu_CreateUnlockGatedListScreen);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1) || defined(NON_MATCHING)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */
typedef struct Shared_MenuWidgetState { s32 list; s32 resourceWidget; void *item; s32 unkC; s32 unk10; s32 unk14; } Shared_MenuWidgetState;
extern Shared_MenuWidgetState *D_800E5780;
extern char D_80102B7E[];

extern s32 SmpFade_CreateFadeWidget(s32, s32);
extern s32 Defs_TestBit(char *, s32);
extern void Frontend_SetWidgetFlag100(MenuWidget *record, int enable);
extern s32 SmpFlicker_CreateFlickerWidget(s32, s32);

s32 Menu_CreateUnlockGatedListScreen(void *window) {
    void *obj;

    D_800E5780 = (Shared_MenuWidgetState *)Cache_AllocateMemory(0x18);
    D_800E5780->list = SmpFade_CreateFadeWidget(0x136, 0x137);
    D_800E5780->unk14 = 0;

    if (Defs_TestBit(D_80102B7E, 0) == 0) {
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(window, 0x13A), 1);
    }

    D_800E5780->resourceWidget = SmpFlicker_CreateFlickerWidget(0x139, 0x6E);

    obj = Frontend_FindWidgetByResourceId(window, 0x138);
    D_800E5780->item = obj;
    ((ListScreenItem *)obj)->alpha = 0xF;

    D_800E5780->unkC = 3;
    D_800E5780->unk10 = -1;
    return 0;
}
#endif
