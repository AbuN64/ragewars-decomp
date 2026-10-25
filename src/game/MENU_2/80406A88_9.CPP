#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern char *D_auto_800DDB08[];
extern void MarkMenuEventHandled(void *);
extern void *func_8040EC30_de(void *, s32);
extern void func_8025DF34_de(s32);
typedef struct { u8 pad0[0x38]; char *text; } LangItemEu;
/* Language selector, previous entry: on the confirm press (arg3 == 1) steps the language byte down (0 wraps to 2), shows the
   new language's label in item 0x5E and plays sound 0xE81. */
s32 func_80423D30_eu_x(void *window, s32 b, s32 c, s32 press) {
    MarkMenuEventHandled(window);
    if (press == 1) {
        D_801462C8.language = D_801462C8.language == 0 ? 2 : D_801462C8.language - 1;
        ((LangItemEu *)func_8040EC30_de(window, 0x5E))->text = D_auto_800DDB08[D_80152789];
        func_8025DF34_de(0xE81);
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80423D30_eu_x);
#endif
#endif

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Language selector, next entry: as func_80423D30_eu_x but steps the language byte up (2 wraps to 0). */
s32 func_80423DB0_eu_x(void *window, s32 b, s32 c, s32 press) {
    MarkMenuEventHandled(window);
    if (press == 1) {
        D_801462C8.language = D_801462C8.language == 2 ? 0 : D_801462C8.language + 1;
        ((LangItemEu *)func_8040EC30_de(window, 0x5E))->text = D_auto_800DDB08[D_80152789];
        func_8025DF34_de(0xE81);
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80423DB0_eu_x);
#endif
#endif
