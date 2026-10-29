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
unsigned int D_src_c64ed94a[27] = {
    0x00000E08, 0x0000001A, 0x0042E748, 0x00000E06, 0x0000001A, 0x0042E640, 0x00000E03, 0x0000001A,
    0x0042E718, 0x00000002, 0x0000001A, 0x0042E914, 0x00000001, 0x0000001A, 0x0042E854, 0x00000008,
    0x0000001A, 0x0042E950, 0x00000007, 0x0000001A, 0x0042E9F8, 0x00000000, 0x00000000, 0x00000000,
    0x020712D0, 0x00000250, 0x021712D0,
};
#endif
#if defined(VERSION_EU_X)
unsigned int D_src_c64ed94a[27] = {
    0x00000E08, 0x0000001A, 0x0042E898, 0x00000E06, 0x0000001A, 0x0042E790, 0x00000E03, 0x0000001A,
    0x0042E868, 0x00000002, 0x0000001A, 0x0042EA64, 0x00000001, 0x0000001A, 0x0042E9A4, 0x00000008,
    0x0000001A, 0x0042EAA0, 0x00000007, 0x0000001A, 0x0042EB48, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000,
};
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
unsigned int g_FrontendDispatchplayercounteventPointerWords1[24] = {
    0x00000E08, 0x0000001A, (unsigned int)g_Frontend_UpdatePlayerCountScreenAddress, 0x00000E06, 0x0000001A, (unsigned int)g_Frontend_CreatePlayerCountScreenPackedAddress24, 0x00000E03, 0x0000001A,
    (unsigned int)g_Frontend_DestroyPlayerCountScreenPackedAddress242, 0x00000002, 0x0000001A, (unsigned int)g_Frontend_CancelPlayerCountPackedAddress242, 0x00000001, 0x0000001A, (unsigned int)g_Frontend_ConfirmPlayerCountPackedAddress242, 0x00000008,
    0x0000001A, (unsigned int)g_Frontend_IncreasePlayerCountPackedAddress242, 0x00000007, 0x0000001A, (unsigned int)g_Frontend_DecreasePlayerCountPackedAddress242, 0x00000000, 0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
char s_projectsDmPath_us[12] =
    "\\Projects\\DM";
#endif
