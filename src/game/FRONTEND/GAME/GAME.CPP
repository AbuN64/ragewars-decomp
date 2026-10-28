#include "include_asm.h"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
extern char *D_auto_800DDB08[];
extern void MarkMenuEventHandled(void *);
extern void *Node_FindWidgetByResourceId(void *, s32);
extern s32 SoundElement_PlayFlatSound(s32);
typedef struct { u8 pad0[0x38]; char *text; } LangItemEu;
/* Language selector, previous entry: on the confirm press (arg3 == 1) steps the language byte down (0 wraps to 2), shows the
   new language's label in item 0x5E and plays sound 0xE81. */
s32 Frontend_SelectPreviousLanguage(void *window, s32 b, s32 c, s32 press) {
    MarkMenuEventHandled(window);
    if (press == 1) {
        D_801462C8.language = D_801462C8.language == 0 ? 2 : D_801462C8.language - 1;
        ((LangItemEu *)Node_FindWidgetByResourceId(window, 0x5E))->text = D_auto_800DDB08[g_languageIndex];
        SoundElement_PlayFlatSound(0xE81);
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Frontend_SelectPreviousLanguage);
#endif
#endif

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Language selector, next entry: as Frontend_SelectPreviousLanguage but steps the language byte up (2 wraps to 0). */
s32 Frontend_SelectNextLanguage(void *window, s32 b, s32 c, s32 press) {
    MarkMenuEventHandled(window);
    if (press == 1) {
        D_801462C8.language = D_801462C8.language == 2 ? 0 : D_801462C8.language + 1;
        ((LangItemEu *)Node_FindWidgetByResourceId(window, 0x5E))->text = D_auto_800DDB08[g_languageIndex];
        SoundElement_PlayFlatSound(0xE81);
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Frontend_SelectNextLanguage);
#endif
#endif
