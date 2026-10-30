#include "COMMON/RESIDENT_EVENT_HANDLER.H"

extern char Frontend_CancelPlayerCount[];
extern char Frontend_ConfirmPlayerCount[];
extern char Frontend_CreatePlayerCountScreenEux[];
extern char Frontend_DecreasePlayerCount[];
extern char Frontend_DestroyPlayerCountScreen[];
extern char Frontend_IncreasePlayerCount[];
extern char Frontend_UpdatePlayerCountScreen[];
extern char g_Frontend_CancelPlayerCountPackedAddress24[];
extern char g_Frontend_ConfirmPlayerCountPackedAddress24[];
extern char g_Frontend_CreatePlayerCountScreenEuPackedAddress24[];
extern char g_Frontend_DecreasePlayerCountPackedAddress24[];
extern char g_Frontend_DestroyPlayerCountScreenPackedAddress24[];
extern char g_Frontend_IncreasePlayerCountPackedAddress24[];
extern char g_Frontend_UpdatePlayerCountScreenPackedAddress24[];

#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
unsigned int D_src_c64ed94a[27] = {
    0x00000E08, 0x0000001A, 0x0042DAF8, 0x00000E06, 0x0000001A, 0x0042D9F0, 0x00000E03, 0x0000001A,
    0x0042DAC8, 0x00000002, 0x0000001A, 0x0042DCC4, 0x00000001, 0x0000001A, 0x0042DC04, 0x00000008,
    0x0000001A, 0x0042DD00, 0x00000007, 0x0000001A, 0x0042DDA8, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000E07, 0x00000013,
};
#endif
#if defined(VERSION_EU)
#if defined(VERSION_EU)
struct {
    ResidentEventHandlerEntry handlers[8];
    u32 alignmentFill[3];
} D_src_c64ed94a __attribute__((aligned(4))) = {
    { { 3592, 26, (ResidentEventHandler)(void *)&g_Frontend_UpdatePlayerCountScreenPackedAddress24 }, { 3590, 26, (ResidentEventHandler)(void *)&g_Frontend_CreatePlayerCountScreenEuPackedAddress24 }, { 3587, 26, (ResidentEventHandler)(void *)&g_Frontend_DestroyPlayerCountScreenPackedAddress24 }, { 2, 26, (ResidentEventHandler)(void *)&g_Frontend_CancelPlayerCountPackedAddress24 }, { 1, 26, (ResidentEventHandler)(void *)&g_Frontend_ConfirmPlayerCountPackedAddress24 }, { 8, 26, (ResidentEventHandler)(void *)&g_Frontend_IncreasePlayerCountPackedAddress24 }, { 7, 26, (ResidentEventHandler)(void *)&g_Frontend_DecreasePlayerCountPackedAddress24 }, { 0, 0, (ResidentEventHandler)0 } },
    { 0x020712D0, 0x00000250, 0x021712D0 }
};
#endif
#endif
#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
ResidentEventHandlerEntry D_src_c64ed94a[9] = {
    { 3592, 26, (ResidentEventHandler)(void *)((char *)&Frontend_UpdatePlayerCountScreen - 0x80000000U) }, { 3590, 26, (ResidentEventHandler)(void *)((char *)&Frontend_CreatePlayerCountScreenEux - 0x80000000U) }, { 3587, 26, (ResidentEventHandler)(void *)((char *)&Frontend_DestroyPlayerCountScreen - 0x80000000U) }, { 2, 26, (ResidentEventHandler)(void *)((char *)&Frontend_CancelPlayerCount - 0x80000000U) }, { 1, 26, (ResidentEventHandler)(void *)((char *)&Frontend_ConfirmPlayerCount - 0x80000000U) }, { 8, 26, (ResidentEventHandler)(void *)((char *)&Frontend_IncreasePlayerCount - 0x80000000U) }, { 7, 26, (ResidentEventHandler)(void *)((char *)&Frontend_DecreasePlayerCount - 0x80000000U) }, { 0, 0, (ResidentEventHandler)0 },
    { 0, 0, (ResidentEventHandler)0 }
};
#endif
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
extern char g_Frontend_CreatePlayerCountScreenPackedAddress24[];
extern char g_Frontend_DestroyPlayerCountScreenPackedAddress242[];
extern char g_Frontend_UpdatePlayerCountScreenAddress[];
extern char g_Frontend_ConfirmPlayerCountPackedAddress242[];
extern char g_Frontend_CancelPlayerCountPackedAddress242[];
extern char g_Frontend_IncreasePlayerCountPackedAddress242[];
extern char g_Frontend_DecreasePlayerCountPackedAddress242[];
#if defined(VERSION_US)
ResidentEventHandlerEntry g_FrontendDispatchplayercounteventPointerWords1[8] = {
    { 3592, 26, (ResidentEventHandler)(void *)g_Frontend_UpdatePlayerCountScreenAddress }, { 3590, 26, (ResidentEventHandler)(void *)g_Frontend_CreatePlayerCountScreenPackedAddress24 }, { 3587, 26, (ResidentEventHandler)(void *)g_Frontend_DestroyPlayerCountScreenPackedAddress242 }, { 2, 26, (ResidentEventHandler)(void *)g_Frontend_CancelPlayerCountPackedAddress242 }, { 1, 26, (ResidentEventHandler)(void *)g_Frontend_ConfirmPlayerCountPackedAddress242 }, { 8, 26, (ResidentEventHandler)(void *)g_Frontend_IncreasePlayerCountPackedAddress242 }, { 7, 26, (ResidentEventHandler)(void *)g_Frontend_DecreasePlayerCountPackedAddress242 }, { 0, 0, (ResidentEventHandler)0 }
};
#endif
#if defined(VERSION_US_REV1)
ResidentEventHandlerEntry g_FrontendDispatchplayercounteventPointerWords1[8] = {
    { 3592, 26, (ResidentEventHandler)(void *)g_Frontend_UpdatePlayerCountScreenAddress }, { 3590, 26, (ResidentEventHandler)(void *)g_Frontend_CreatePlayerCountScreenPackedAddress24 }, { 3587, 26, (ResidentEventHandler)(void *)g_Frontend_DestroyPlayerCountScreenPackedAddress242 }, { 2, 26, (ResidentEventHandler)(void *)g_Frontend_CancelPlayerCountPackedAddress242 }, { 1, 26, (ResidentEventHandler)(void *)g_Frontend_ConfirmPlayerCountPackedAddress242 }, { 8, 26, (ResidentEventHandler)(void *)g_Frontend_IncreasePlayerCountPackedAddress242 }, { 7, 26, (ResidentEventHandler)(void *)g_Frontend_DecreasePlayerCountPackedAddress242 }, { 0, 0, (ResidentEventHandler)0 }
};
#endif
#endif

#if defined(VERSION_US)
char s_projectsDmPath_us[12] =
    "\\Projects\\DM";
#endif
