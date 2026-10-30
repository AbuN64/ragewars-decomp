#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "TYPES.H"

extern char g_Frontend_AcknowledgePage67EventPackedAddress24[];
extern char g_Frontend_ActivatePauseMenuActionPackedAddress24[];
extern char g_Frontend_ClearPage67ModeFlagPackedAddress24[];
extern char g_Frontend_ConsumeConfirmationEventPackedAddress24[];
extern char g_Frontend_ConsumePauseMenuEventPackedAddress24[];
extern char g_Frontend_CreatePauseConfirmationPackedAddress24[];
extern char g_Frontend_CreatePauseMenuPackedAddress24[];
extern char g_Frontend_CreateTimedMenuPackedAddress24[];
extern char g_Frontend_DestroyPauseMenuPackedAddress24[];
extern char g_Frontend_FreePage67ScreenPackedAddress24[];
extern char g_Frontend_HandlePage67ChoicePackedAddress24[];
extern char g_Frontend_IgnorePage67EventPackedAddress24[];
extern char g_Frontend_ResumeMatchOnInputPackedAddress24[];
extern char g_Frontend_ReturnConfirmationEventZeroPackedAddress24[];
extern char g_Frontend_ReturnPauseEventZeroAltPackedAddress24[];
extern char g_Frontend_ReturnPauseEventZeroPackedAddress24[];
extern char g_Frontend_SetPauseMenuInputModePackedAddress24[];
extern char g_Frontend_UpdatePage67ExitPackedAddress24[];
extern char g_Timed_DestroyPauseConfirmationPackedAddress24[];
extern char g_Timed_FinishPauseConfirmationTransitionPackedAddress24[];
extern char g_Timed_SetConfirmationInputModePackedAddress24[];
extern char g_Timed_UpdateTimedScreenPackedAddress24[];

#include "include_asm.h"

/* 800E5550.CPP */
/* ROM-grounded data: rodata/writable/800E5550 */
#if defined(VERSION_DE)
struct {
    void * g_pauseMenuState;
    void * g_pauseTimedMenu;
    s32 g_residentChoiceScreen;
} g_FrontendDestroypausemenuWords1 __attribute__((aligned(4))) = {
    0,
    0,
    0
};
typedef char g_FrontendDestroypausemenuWords1SizeCheck[(sizeof(g_FrontendDestroypausemenuWords1) == 12) ? 1 : -1];
#endif
#if defined(VERSION_EU)
struct {
    void * g_pauseMenuState;
    void * g_pauseTimedMenu;
    s32 g_residentChoiceScreen;
} g_FrontendDestroypausemenuWords1 __attribute__((aligned(4))) = {
    0,
    0,
    0
};
typedef char g_FrontendDestroypausemenuWords1SizeCheck[(sizeof(g_FrontendDestroypausemenuWords1) == 12) ? 1 : -1];
#endif
#if defined(VERSION_EU_X)
struct {
    void * g_pauseMenuState;
    void * g_pauseTimedMenu;
    s32 g_residentChoiceScreen;
} g_FrontendDestroypausemenuWords1 __attribute__((aligned(4))) = {
    0,
    0,
    0
};
typedef char g_FrontendDestroypausemenuWords1SizeCheck[(sizeof(g_FrontendDestroypausemenuWords1) == 12) ? 1 : -1];
#endif
#if defined(VERSION_US)
struct {
    void * g_pauseMenuState;
    void * g_pauseTimedMenu;
    s32 g_residentChoiceScreen;
} g_FrontendDestroypausemenuWords1 __attribute__((aligned(4))) = {
    0,
    0,
    0
};
typedef char g_FrontendDestroypausemenuWords1SizeCheck[(sizeof(g_FrontendDestroypausemenuWords1) == 12) ? 1 : -1];
#endif
#if defined(VERSION_US_REV1)
struct {
    void * g_pauseMenuState;
    void * g_pauseTimedMenu;
    s32 g_residentChoiceScreen;
} g_FrontendDestroypausemenuWords1 __attribute__((aligned(4))) = {
    0,
    0,
    0
};
typedef char g_FrontendDestroypausemenuWords1SizeCheck[(sizeof(g_FrontendDestroypausemenuWords1) == 12) ? 1 : -1];
#endif

/* 800E555C.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int D_src_2527d91d[77] = {
    0x00000E07, 0x00000001, 0x00435C40, 0x00000E08, 0x00000001, 0x00435C68, 0x00000E0A, 0x00000001,
    0x00435C60, 0x00000E06, 0x00000001, 0x00435B34, 0x00000E03, 0x00000001, 0x00435C00, 0x00000001,
    0x00000001, 0x00435CD8, 0x00000002, 0x00000001, 0x00435CB8, 0x0000000A, 0x00000001, 0x00435C70,
    0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x0000001F, 0x00435EF4, 0x00000E08, 0x0000001F,
    0x0043601C, 0x00000E0A, 0x0000001F, 0x00435F14, 0x00000E06, 0x0000001F, 0x00435E20, 0x00000E03,
    0x0000001F, 0x00435EBC, 0x00000001, 0x0000001F, 0x00436044, 0x00000002, 0x0000001F, 0x00436024,
    0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x00000020, 0x00436288, 0x00000E08, 0x00000020,
    0x00436394, 0x00000E0A, 0x00000020, 0x004362A8, 0x00000E06, 0x00000020, 0x004361BC, 0x00000E03,
    0x00000020, 0x00436250, 0x00000001, 0x00000020, 0x004363BC, 0x00000002, 0x00000020, 0x0043639C,
    0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x00000005,
};
#endif
#if defined(VERSION_EU)
#if defined(VERSION_EU)
struct {
    ResidentEventHandlerEntry handlers[25];
    u32 alignmentFill[2];
} D_src_2527d91d __attribute__((aligned(4))) = {
    { { 3591, 1, (ResidentEventHandler)(void *)&g_Frontend_SetPauseMenuInputModePackedAddress24 }, { 3592, 1, (ResidentEventHandler)(void *)&g_Frontend_ReturnPauseEventZeroAltPackedAddress24 }, { 3594, 1, (ResidentEventHandler)(void *)&g_Frontend_ReturnPauseEventZeroPackedAddress24 }, { 3590, 1, (ResidentEventHandler)(void *)&g_Frontend_CreatePauseMenuPackedAddress24 }, { 3587, 1, (ResidentEventHandler)(void *)&g_Frontend_DestroyPauseMenuPackedAddress24 }, { 1, 1, (ResidentEventHandler)(void *)&g_Frontend_ActivatePauseMenuActionPackedAddress24 }, { 2, 1, (ResidentEventHandler)(void *)&g_Frontend_ConsumePauseMenuEventPackedAddress24 }, { 10, 1, (ResidentEventHandler)(void *)&g_Frontend_ResumeMatchOnInputPackedAddress24 }, { 0, 0, (ResidentEventHandler)0 }, { 3591, 31, (ResidentEventHandler)(void *)&g_Timed_SetConfirmationInputModePackedAddress24 }, { 3592, 31, (ResidentEventHandler)(void *)&g_Frontend_ReturnConfirmationEventZeroPackedAddress24 }, { 3594, 31, (ResidentEventHandler)(void *)&g_Timed_FinishPauseConfirmationTransitionPackedAddress24 }, { 3590, 31, (ResidentEventHandler)(void *)&g_Frontend_CreatePauseConfirmationPackedAddress24 }, { 3587, 31, (ResidentEventHandler)(void *)&g_Timed_DestroyPauseConfirmationPackedAddress24 }, { 1, 31, (ResidentEventHandler)(void *)&g_Timed_UpdateTimedScreenPackedAddress24 }, { 2, 31, (ResidentEventHandler)(void *)&g_Frontend_ConsumeConfirmationEventPackedAddress24 }, { 0, 0, (ResidentEventHandler)0 }, { 3591, 32, (ResidentEventHandler)(void *)&g_Frontend_ClearPage67ModeFlagPackedAddress24 }, { 3592, 32, (ResidentEventHandler)(void *)&g_Frontend_IgnorePage67EventPackedAddress24 }, { 3594, 32, (ResidentEventHandler)(void *)&g_Frontend_UpdatePage67ExitPackedAddress24 }, { 3590, 32, (ResidentEventHandler)(void *)&g_Frontend_CreateTimedMenuPackedAddress24 }, { 3587, 32, (ResidentEventHandler)(void *)&g_Frontend_FreePage67ScreenPackedAddress24 }, { 1, 32, (ResidentEventHandler)(void *)&g_Frontend_HandlePage67ChoicePackedAddress24 }, { 2, 32, (ResidentEventHandler)(void *)&g_Frontend_AcknowledgePage67EventPackedAddress24 }, { 0, 0, (ResidentEventHandler)0 } },
    { 0x00000000, 0x00800000 }
};
#endif
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_2527d91d[77] = {
    0x00000E07, 0x00000001, 0x00436AB0, 0x00000E08, 0x00000001, 0x00436AD8, 0x00000E0A, 0x00000001,
    0x00436AD0, 0x00000E06, 0x00000001, 0x004369A4, 0x00000E03, 0x00000001, 0x00436A70, 0x00000001,
    0x00000001, 0x00436B48, 0x00000002, 0x00000001, 0x00436B28, 0x0000000A, 0x00000001, 0x00436AE0,
    0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x0000001F, 0x00436D5C, 0x00000E08, 0x0000001F,
    0x00436E84, 0x00000E0A, 0x0000001F, 0x00436D7C, 0x00000E06, 0x0000001F, 0x00436C88, 0x00000E03,
    0x0000001F, 0x00436D24, 0x00000001, 0x0000001F, 0x00436EAC, 0x00000002, 0x0000001F, 0x00436E8C,
    0x00000000, 0x00000000, 0x00000000, 0x00000E07, 0x00000020, 0x004370F0, 0x00000E08, 0x00000020,
    0x004371FC, 0x00000E0A, 0x00000020, 0x00437110, 0x00000E06, 0x00000020, 0x00437024, 0x00000E03,
    0x00000020, 0x004370B8, 0x00000001, 0x00000020, 0x00437224, 0x00000002, 0x00000020, 0x00437204,
    0x00000000, 0x00000000, 0x00000000, 0x8FA70028, 0x24020033,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
extern char g_Frontend_CreatePauseMenuPackedAddress242[];
extern char g_Frontend_DestroyPauseMenuPackedAddress242[];
extern char g_Frontend_SetPauseMenuInputModePackedAddress242[];
extern char g_Frontend_ReturnPauseEventZeroPackedAddress242[];
extern char g_Frontend_ReturnPauseEventZeroAltPackedAddress242[];
extern char g_Frontend_ResumeMatchOnInputPackedAddress242[];
extern char g_Frontend_ConsumePauseMenuEventPackedAddress242[];
extern char g_Frontend_ActivatePauseMenuActionPackedAddress242[];
#if defined(VERSION_US)
ResidentEventHandlerEntry g_FrontendDestroypausemenuPointerWords1[9] = {
    { 3591, 1, (ResidentEventHandler)(void *)g_Frontend_SetPauseMenuInputModePackedAddress242 }, { 3592, 1, (ResidentEventHandler)(void *)g_Frontend_ReturnPauseEventZeroAltPackedAddress242 }, { 3594, 1, (ResidentEventHandler)(void *)g_Frontend_ReturnPauseEventZeroPackedAddress242 }, { 3590, 1, (ResidentEventHandler)(void *)g_Frontend_CreatePauseMenuPackedAddress242 }, { 3587, 1, (ResidentEventHandler)(void *)g_Frontend_DestroyPauseMenuPackedAddress242 }, { 1, 1, (ResidentEventHandler)(void *)g_Frontend_ActivatePauseMenuActionPackedAddress242 }, { 2, 1, (ResidentEventHandler)(void *)g_Frontend_ConsumePauseMenuEventPackedAddress242 }, { 10, 1, (ResidentEventHandler)(void *)g_Frontend_ResumeMatchOnInputPackedAddress242 },
    { 0, 0, (ResidentEventHandler)0 }
};
#endif
#if defined(VERSION_US_REV1)
ResidentEventHandlerEntry g_FrontendDestroypausemenuPointerWords1[9] = {
    { 3591, 1, (ResidentEventHandler)(void *)g_Frontend_SetPauseMenuInputModePackedAddress242 }, { 3592, 1, (ResidentEventHandler)(void *)g_Frontend_ReturnPauseEventZeroAltPackedAddress242 }, { 3594, 1, (ResidentEventHandler)(void *)g_Frontend_ReturnPauseEventZeroPackedAddress242 }, { 3590, 1, (ResidentEventHandler)(void *)g_Frontend_CreatePauseMenuPackedAddress242 }, { 3587, 1, (ResidentEventHandler)(void *)g_Frontend_DestroyPauseMenuPackedAddress242 }, { 1, 1, (ResidentEventHandler)(void *)g_Frontend_ActivatePauseMenuActionPackedAddress242 }, { 2, 1, (ResidentEventHandler)(void *)g_Frontend_ConsumePauseMenuEventPackedAddress242 }, { 10, 1, (ResidentEventHandler)(void *)g_Frontend_ResumeMatchOnInputPackedAddress242 },
    { 0, 0, (ResidentEventHandler)0 }
};
#endif
#endif

#if defined(VERSION_US)
unsigned int g_pauseMenuEventHandlerRecords[50] = {
    0x00000E07, 0x0000001F, 0x004360D4, 0x00000E08, 0x0000001F, 0x004361FC, 0x00000E0A, 0x0000001F,
    0x004360F4, 0x00000E06, 0x0000001F, 0x00436000, 0x00000E03, 0x0000001F, 0x0043609C, 0x00000001,
    0x0000001F, 0x00436224, 0x00000002, 0x0000001F, 0x00436204, 0x00000000, 0x00000000, 0x00000000,
    0x00000E07, 0x00000020, 0x00436468, 0x00000E08, 0x00000020, 0x00436574, 0x00000E0A, 0x00000020,
    0x00436488, 0x00000E06, 0x00000020, 0x0043639C, 0x00000E03, 0x00000020, 0x00436430, 0x00000001,
    0x00000020, 0x0043659C, 0x00000002, 0x00000020, 0x0043657C, 0x00000000, 0x00000000, 0x00000000,
    0x2E481CF4, 0x0020433A,
};
#endif
