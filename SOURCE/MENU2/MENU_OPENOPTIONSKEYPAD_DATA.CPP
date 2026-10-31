#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "TYPES.H"
#include "include_asm.h"
#include "DATA/OVLTBL/MENU_OPENOPTIONSKEYPAD_DATA.H"
#if defined(VERSION_DE)
/* 800E4400.CPP */
/* ROM-grounded data: rodata/writable/800E4400 */
struct {
    void * g_extraOptionsScreen;
} k_MenuOpenoptionskeypadZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuOpenoptionskeypadZeroWordsSizeCheck[(sizeof(k_MenuOpenoptionskeypadZeroWords) == 4) ? 1 : -1];
#endif
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
/* 800E4404.CPP */
extern char Menu_UpdateExtraOptionsMenu_Address[];
extern char Menu_OpenRuleToggleScreen_Address[];
extern char Menu_DestroyExtraOptionsMenu_Address[];
#if defined(VERSION_DE)
struct {
    ResidentEventHandlerEntry handlers[6];
    u32 alignmentFill[1];
} D_src_16391c30 __attribute__((aligned(4))) = {
    { { 3592, 28, (ResidentEventHandler)(void *)&Menu_UpdateExtraOptionsMenu_Address }, { 3590, 28, (ResidentEventHandler)(void *)&Menu_OpenRuleToggleScreen_Address }, { 3587, 28, (ResidentEventHandler)(void *)&Menu_DestroyExtraOptionsMenu_Address }, { 2, 28, (ResidentEventHandler)(void *)(Menu_UpdateExtraOptionsMenu_Address + 348) }, { 1, 28, (ResidentEventHandler)(void *)(Menu_UpdateExtraOptionsMenu_Address + 164) }, { 0, 0, (ResidentEventHandler)0 } },
    { 0x00421BAC }
};
#endif
#endif
#endif
