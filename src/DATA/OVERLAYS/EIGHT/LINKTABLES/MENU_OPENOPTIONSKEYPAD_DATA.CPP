#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "TYPES.H"

extern char g_Menu_ConfirmExtraOptionsPackedAddress24[];
extern char g_Menu_DestroyExtraOptionsMenuPackedAddress24[];
extern char g_Menu_HandleExtraOptionsChoicePackedAddress24[];
extern char g_Menu_OpenRuleToggleScreenPackedAddress24[];
extern char g_Menu_UpdateExtraOptionsMenuPackedAddress24[];

#include "include_asm.h"
#include "DATA/OVLTBL/MENU_OPENOPTIONSKEYPAD_DATA.H"

/* 800E4400.CPP */
/* ROM-grounded data: rodata/writable/800E4400 */
#if defined(VERSION_DE)
struct {
    void * g_extraOptionsScreen;
} k_MenuOpenoptionskeypadZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuOpenoptionskeypadZeroWordsSizeCheck[(sizeof(k_MenuOpenoptionskeypadZeroWords) == 4) ? 1 : -1];
#endif
#if defined(VERSION_EU)
struct {
    void * g_extraOptionsScreen;
} k_MenuOpenoptionskeypadZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuOpenoptionskeypadZeroWordsSizeCheck[(sizeof(k_MenuOpenoptionskeypadZeroWords) == 4) ? 1 : -1];
#endif
#if defined(VERSION_EU_X)
struct {
    void * g_extraOptionsScreen;
} k_MenuOpenoptionskeypadZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuOpenoptionskeypadZeroWordsSizeCheck[(sizeof(k_MenuOpenoptionskeypadZeroWords) == 4) ? 1 : -1];
#endif
#if defined(VERSION_US)
struct {
    void * g_extraOptionsScreen;
} k_MenuOpenoptionskeypadZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuOpenoptionskeypadZeroWordsSizeCheck[(sizeof(k_MenuOpenoptionskeypadZeroWords) == 4) ? 1 : -1];
#endif
#if defined(VERSION_US_REV1)
struct {
    void * g_extraOptionsScreen;
} k_MenuOpenoptionskeypadZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuOpenoptionskeypadZeroWordsSizeCheck[(sizeof(k_MenuOpenoptionskeypadZeroWords) == 4) ? 1 : -1];
#endif

/* 800E4404.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char Menu_UpdateExtraOptionsMenu_Address[];
extern char Menu_OpenRuleToggleScreen_Address[];
extern char Menu_DestroyExtraOptionsMenu_Address[];
extern char g_Menu_DispatchExtraOptionsEventAddress[];
#if defined(VERSION_DE)
struct {
    ResidentEventHandlerEntry handlers[6];
    u32 alignmentFill[1];
} D_src_16391c30 __attribute__((aligned(4))) = {
    { { 3592, 28, (ResidentEventHandler)(void *)Menu_UpdateExtraOptionsMenu_Address }, { 3590, 28, (ResidentEventHandler)(void *)Menu_OpenRuleToggleScreen_Address }, { 3587, 28, (ResidentEventHandler)(void *)Menu_DestroyExtraOptionsMenu_Address }, { 2, 28, (ResidentEventHandler)(void *)(Menu_UpdateExtraOptionsMenu_Address + 348) }, { 1, 28, (ResidentEventHandler)(void *)(Menu_UpdateExtraOptionsMenu_Address + 164) }, { 0, 0, (ResidentEventHandler)0 } },
    { 0x00421BAC }
};
#endif
#endif
#if defined(VERSION_EU)
#if defined(VERSION_EU)
struct {
    ResidentEventHandlerEntry handlers[6];
    u32 alignmentFill[1];
} D_src_16391c30 __attribute__((aligned(4))) = {
    { { 3592, 28, (ResidentEventHandler)(void *)&g_Menu_UpdateExtraOptionsMenuPackedAddress24 }, { 3590, 28, (ResidentEventHandler)(void *)&g_Menu_OpenRuleToggleScreenPackedAddress24 }, { 3587, 28, (ResidentEventHandler)(void *)&g_Menu_DestroyExtraOptionsMenuPackedAddress24 }, { 2, 28, (ResidentEventHandler)(void *)&g_Menu_ConfirmExtraOptionsPackedAddress24 }, { 1, 28, (ResidentEventHandler)(void *)&g_Menu_HandleExtraOptionsChoicePackedAddress24 }, { 0, 0, (ResidentEventHandler)0 } },
    { 0x8C850320 }
};
#endif
#endif
#if defined(VERSION_EU_X)
extern char g_Selection_DispatchCharacterSelectionEventAddress[];
#if defined(VERSION_EU_X)
struct {
    ResidentEventHandlerEntry handlers[6];
    u32 alignmentFill[1];
} D_src_16391c30 __attribute__((aligned(4))) = {
    { { 3592, 28, (ResidentEventHandler)(void *)(g_Selection_DispatchCharacterSelectionEventAddress + 2956) }, { 3590, 28, (ResidentEventHandler)(void *)(g_Selection_DispatchCharacterSelectionEventAddress + 144) }, { 3587, 28, (ResidentEventHandler)(void *)(g_Selection_DispatchCharacterSelectionEventAddress + 2908) }, { 2, 28, (ResidentEventHandler)(void *)(g_Selection_DispatchCharacterSelectionEventAddress + 3264) }, { 1, 28, (ResidentEventHandler)(void *)(g_Selection_DispatchCharacterSelectionEventAddress + 3120) }, { 0, 0, (ResidentEventHandler)0 } },
    { 0x00000000 }
};
#endif
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
#if defined(VERSION_US)
ResidentEventHandlerEntry g_MenuOpenoptionskeypadEncodedWords[6] = {
    { 3592, 28, (ResidentEventHandler)(void *)g_menu_UpdateExtraOptionsMenuEntry }, { 3590, 28, (ResidentEventHandler)(void *)g_menu_OpenRuleToggleScreenEntry }, { 3587, 28, (ResidentEventHandler)(void *)g_menu_DestroyExtraOptionsMenuEntry }, { 2, 28, (ResidentEventHandler)(void *)g_menu_ConfirmExtraOptionsEntry }, { 1, 28, (ResidentEventHandler)(void *)g_menu_HandleExtraOptionsChoiceEntry }, { 0, 0, (ResidentEventHandler)0 }
};
#endif
#if defined(VERSION_US_REV1)
ResidentEventHandlerEntry g_MenuOpenoptionskeypadEncodedWords[6] = {
    { 3592, 28, (ResidentEventHandler)(void *)g_menu_UpdateExtraOptionsMenuEntry }, { 3590, 28, (ResidentEventHandler)(void *)g_menu_OpenRuleToggleScreenEntry }, { 3587, 28, (ResidentEventHandler)(void *)g_menu_DestroyExtraOptionsMenuEntry }, { 2, 28, (ResidentEventHandler)(void *)g_menu_ConfirmExtraOptionsEntry }, { 1, 28, (ResidentEventHandler)(void *)g_menu_HandleExtraOptionsChoiceEntry }, { 0, 0, (ResidentEventHandler)0 }
};
#endif
#endif

#if defined(VERSION_US)
#if defined(VERSION_US)
struct {
    u8 alignmentFill[4];
} g_MenuOpenoptionskeypadTrailingWord __attribute__((aligned(4))) = {
    { 0x75, 0x04, 0x2E, 0x65 }
};
#endif
#endif
